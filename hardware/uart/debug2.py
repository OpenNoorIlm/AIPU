#!/usr/bin/env python3
"""
Two tests:
1. ESP32 loopback — send BAUD:115200\n, expect it echoed back
2. Listen 5s for Tang data on GPIO26
"""
import serial, time

PORT = "/dev/ttyUSB0"
ser = serial.Serial(PORT, 115200, timeout=2)
time.sleep(0.5)
ser.reset_input_buffer()

# Test 1: send a command, ESP32 should respond
print("=== Test 1: ESP32 alive? ===")
ser.write(b"BAUD:115200\n")
time.sleep(0.5)
resp = ser.read(256)
print("Response:", repr(resp))
if b"115200" in resp or b"ESP32" in resp or b"baud" in resp.lower():
    print("ESP32 is alive and responding")
else:
    print("ESP32 NOT responding — sketch may not be running or wrong port")

# Test 2: passive listen for Tang data
print("\n=== Test 2: Tang TX data (5s) ===")
ser.reset_input_buffer()
deadline = time.time() + 5
count = 0
while time.time() < deadline:
    d = ser.read(64)
    if d:
        count += len(d)
        print(f"  hex: {d.hex()}  ascii: {repr(d)}")
print(f"Total: {count} bytes")
if count == 0:
    print("Nothing received — Tang TX not reaching GPIO26")

ser.close()
