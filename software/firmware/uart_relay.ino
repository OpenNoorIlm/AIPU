// uart_relay on GPIO25 — no JTAG, no strapping, no SPI flash conflicts
void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("[relay] booting...");
  delay(2000);
  Serial2.begin(115200, SERIAL_8N1, 25, -1);
  Serial.println("[relay] ready GPIO25");
}

void loop() {
  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }
}
