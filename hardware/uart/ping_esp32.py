#!/usr/bin/env python3
"""Send a reset pulse + newline to ESP32, read banner response."""
import serial, time

ser = serial.Serial("/dev/ttyUSB0", 115200, timeout=2)
# toggle DTR to reset ESP32
ser.dtr = False; time.sleep(0.1); ser.dtr = True; time.sleep(2)
ser.reset_input_buffer()
# send newline (triggers handleCommand with empty string)
ser.write(b"\n")
time.sleep(0.5)
out = ser.read(512)
print("ESP32 response:", repr(out))
ser.close()
