// uart_relay.ino — bidirectional UART bridge
// ESP32 GPIO25 = Serial2 RX (Tang M11 TX → ESP32)
// ESP32 GPIO26 = Serial2 TX (ESP32 → Tang T13 RX)
// PC sends bytes via USB Serial → relayed to FPGA over GPIO26
// FPGA sends bytes via GPIO25 → relayed to PC over USB Serial

void setup() {
    Serial.begin(115200);
    delay(500);
    Serial.println("[relay] booting...");
    delay(2000);  // wait for FPGA to settle before opening Serial2
    Serial2.begin(115200, SERIAL_8N1, 25, 26);  // RX=GPIO25, TX=GPIO26
    Serial.println("[relay] ready GPIO25(RX) GPIO26(TX)");
}

void loop() {
    // FPGA → PC
    while (Serial2.available()) Serial.write(Serial2.read());
    // PC → FPGA
    while (Serial.available())  Serial2.write(Serial.read());
}
