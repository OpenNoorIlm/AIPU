# Continue Here — Current State After UART Breakthrough

**READ about.md FIRST** for full hardware/wiring/toolchain context.

---

## 🎉 UART IS WORKING — As Of This Session

"AIPU OK\r\n" confirmed received on PC. 351 messages in 5 seconds.
Byte counts: {65:'A', 73:'I', 80:'P', 85:'U', 32:' ', 79:'O', 75:'K', 13:'\r', 10:'\n'}

### Final Working Configuration
```
Tang SH1.0 Pin 2 (M11 TX)  →  ESP32 GPIO25
ESP32 sketch: uart_relay.ino with Serial2.begin(115200, SERIAL_8N1, 25, -1)
ESP32 binary: /tmp/relay_build25/uart_relay.ino.merged.bin
FPGA bitstream: ~/teacher-aipu/uart/uart_top.fs  (sends "AIPU OK\r\n" every 1s)
```

### What Was Wrong (Root Cause)
GPIO13 = MTCK (ESP32 JTAG clock pin) — interfered with Serial2 decode.
GPIO16/17 = strapping/SPI flash pins — caused boot corruption.
GPIO25 = clean, no special functions, Serial2 works perfectly.

Also: listen window timing was off — the 2s relay delay + 1s FPGA boot delay
meant data arrived at the end of short listen windows. Use 12s+ windows.

---

## Current State

```
✅ Verilator simulation — zero errors
✅ Synlig synthesis — top_fpga.json
✅ nextpnr P&R — PASS at 27MHz, max 167MHz
✅ gowin_pack — top_fpga.fs (4.5MB)
✅ FT232H JTAG — detects Tang every time (idcode 0x81b)
✅ openFPGALoader flash — works perfectly
✅ ESP32 uart_relay on GPIO25 — confirmed working
✅ uart_top.fs → "AIPU OK\r\n" received on PC — BREAKTHROUGH!
⬜ top_fpga.fs (full AIPU) — not yet tested, next step
```

---

## Next Steps (In Order)

### 1. Flash full AIPU and verify output
```bash
openFPGALoader -c ft232 -b tangprimer20k ~/teacher-aipu/rtl/top_fpga.fs
python3 -c "
import serial, time
ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)
ser.reset_input_buffer()
t = time.time()
while time.time() - t < 12:
    d = ser.read(64)
    if d: print(f't={time.time()-t:.1f}s: {repr(d)}')
ser.close()
"
```
Expected: result packets from result_sender.v over UART.

### 2. Scale up — increase G, C, N in top.v, resynthesize
### 3. Add signed INT8 — modify mac.v with $signed()
### 4. Add FP8 — write fp8_mul.v
### 5. Add BF16 — write bf16_mul.v (~500 lines)
### 6. Mixed precision — 2-bit precision selector in MAC
### 7. Port to larger FPGA
### 8. efabless MPW shuttle — first silicon

---

## Working Commands Quick Reference

### Flash uart test (confirmed working):
```bash
openFPGALoader -c ft232 -b tangprimer20k ~/teacher-aipu/uart/uart_top.fs
```

### Flash full AIPU:
```bash
openFPGALoader -c ft232 -b tangprimer20k ~/teacher-aipu/rtl/top_fpga.fs
```

### Listen for FPGA output:
```bash
python3 -c "
import serial, time
ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)
ser.reset_input_buffer()
t = time.time()
while time.time() - t < 12:
    d = ser.read(64)
    if d: print(f't={time.time()-t:.1f}s: {repr(d)}')
ser.close()
"
```

### Verify ESP32 relay running:
```bash
python3 -c "
import serial, time
ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=5)
ser.dtr = False; time.sleep(0.1); ser.dtr = True
time.sleep(4)
print(repr(ser.read(300)))
ser.close()
"
# Expected: ends with b'[relay] ready GPIO25\r\n'
```

### Ports:
```
/dev/ttyUSB0 = ESP32 (relay, read FPGA output here)
/dev/ttyUSB1 = FT232H (JTAG)
/dev/ttyACM0 = OWNER'S PHONE — NEVER TOUCH
```
