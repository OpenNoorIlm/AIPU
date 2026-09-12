#!/usr/bin/env python3
"""
debug_uart.py — passive listener on ESP32 serial, prints raw hex + ASCII.
Run: sudo python3 debug_uart.py
"""
import serial, time, sys

PORT = "/dev/ttyUSB0"
BAUD = 115200
TIMEOUT = 10  # seconds to listen

print(f"Opening {PORT} at {BAUD} baud...")
ser = serial.Serial(PORT, BAUD, timeout=1)
ser.reset_input_buffer()
print(f"Listening for {TIMEOUT}s — all bytes shown as hex + ASCII\n")

deadline = time.time() + TIMEOUT
total = 0
while time.time() < deadline:
    chunk = ser.read(64)
    if chunk:
        total += len(chunk)
        hex_str = " ".join(f"{b:02X}" for b in chunk)
        asc_str = "".join(chr(b) if 32 <= b < 127 else "." for b in chunk)
        print(f"[{hex_str}]  {asc_str!r}")

ser.close()
print(f"\nDone. {total} bytes received in {TIMEOUT}s.")
if total == 0:
    print("ZERO bytes — ESP32 not forwarding anything from Tang.")
    print("Check: Tang TX wire → ESP32 GPIO26")
