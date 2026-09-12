#define TCK 14
#define TDO 4
#define TDI 13
#define TMS 15
#define TANG_TX 17

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, TANG_TX, -1);
  pinMode(TCK, OUTPUT);
  pinMode(TDI, OUTPUT);
  pinMode(TMS, OUTPUT);
  pinMode(TDO, INPUT);
  digitalWrite(TCK, LOW);
  digitalWrite(TDI, LOW);
  digitalWrite(TMS, LOW);
}

void loop() {
  // Forward Tang UART to PC
  if (Serial2.available()) {
    Serial.write(Serial2.read());
  }

  if (!Serial.available()) return;

  char c = Serial.read();

  if (c == 'R') {
    // Read TDO
    Serial.write('0' + digitalRead(TDO));
    Serial.flush();
  } else if (c == 'B' || c == 'b' || c == 'Q' || c == 'q') {
    return;
  } else if (c >= '0' && c <= '7') {
    int v = c - '0';
    digitalWrite(TMS, (v >> 1) & 1);
    digitalWrite(TDI, (v >> 0) & 1);
    digitalWrite(TCK, LOW);
    if ((v >> 2) & 1) digitalWrite(TCK, HIGH);
  } else if (c == 'W') {
    // Bulk write: next byte = count, then count data bytes
    while (!Serial.available());
    int count = Serial.read();
    for (int i = 0; i < count; i++) {
      while (!Serial.available());
      byte data = Serial.read();
      for (int b = 0; b < 8; b++) {
        digitalWrite(TDI, (data >> b) & 1);
        digitalWrite(TCK, LOW);
        digitalWrite(TCK, HIGH);
      }
    }
    Serial.write('K');
    Serial.flush();  // Critical - flush ACK immediately
  }
}
