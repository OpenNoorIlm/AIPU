# OpenNoorIlm Teacher AIPU — Complete Project Reference

## Who & What

**Owner:** OpenNoorIlmAI | GitHub: OpenNoorIlm
**Machine user:** bismillah
**Machine:** Lenovo IdeaPad 1 15ALC7, Ubuntu 24.04, AMD Radeon iGPU
**Project root:** /home/bismillah/teacher-aipu/
**Arduino sketches:** /home/bismillah/Arduino/

This project is a fully custom AI Processing Unit (AIPU) — a systolic array accelerator —
designed from scratch in SystemVerilog, simulated with Verilator, synthesized with Yosys/Synlig,
placed & routed with nextpnr, and deployed to a Sipeed Tang Primer 20K FPGA via FT232H JTAG.

The architecture is parameterized: G (grid size), C (chains per cell), N (array size).
Changing three numbers rescales the entire design from 0.005 TOPS (FPGA prototype) to
4,194 TOPS (TSMC 6nm production chip that would beat the NVIDIA H100).

The project is Islamic in spirit — named "Noor ul Ilm" (light of knowledge). The owner
builds iteratively and hands-on.

**Big picture roadmap:**
```
Teacher AIPU on Tang Primer 20K FPGA (NOW — proving architecture)
    ↓
Prototype AIPU on larger FPGA (G=2,C=2,N=8 → 0.1 TOPS)
    ↓
First Silicon via efabless MPW shuttle (G=4,C=4,N=16, TSMC 28nm → 4 TOPS, ~$10K)
    ↓
Production v1 (G=8,C=4,N=32, TSMC 12nm → 100 TOPS, ~$500K)
    ↓
Production v2 (G=16,C=8,N=32, TSMC 6nm → 4,194 TOPS, ~$5-10M — beats H100 at 3,958 TOPS)
```

---

## Hardware — Every Component, Every Wire

### 1. Sipeed Tang Primer 20K FPGA Board

**Critical facts:**
- This is the BARE BOARD with NO DOCK. This distinction matters enormously.
- Form factor: DDR3 SODIMM. It plugs into a SODIMM slot on the dock, but we have no dock.
- The bare board exposes ZERO standard 2.54mm GPIO headers. The ONLY accessible pins are:
  (a) The SH1.0 8-pin JST connector, and (b) the SODIMM edge connector (unusable without dock).
- FPGA chip: Gowin GW2A-18C (Engineering Sample / ES grade — important for toolchain)
- JTAG IDCODE: 0x0000081B — this is what openFPGALoader reports as 0x81B
- Crystal oscillator: 27 MHz, connected to FPGA pin H11
- H11 is in IO bank 0, which runs at 1.8V VCCIO. This means the clk port MUST be
  declared LVCMOS18 in the CST, not LVCMOS33. Using LVCMOS33 on H11 can cause the
  FPGA to malfunction silently (clock not registered properly).
- No user LEDs on the bare board. No way to visually confirm FPGA is running.
- Tang Primer 20K is NOT the same as Tang Nano 20K. They are different boards.
- SRAM is volatile: bitstream is lost on every power cycle. Must reflash after every power cut.
- The Tang board is powered ENTIRELY from the FT232H 5V pin. It has no independent USB power.

**SH1.0 8-Pin Connector — Exact Pinout:**
The connector is a JST SH 1.0mm pitch 8-pin. We use a proper SH1.0 crimped cable
(crimped SH1.0 pins on the Tang side, female 2.54mm dupont on the other end).
Pin numbering — 1 is at the bottom (near board edge), 8 is at the top:
```
Pin 1 — GND
Pin 2 — TX   → FPGA ball M11, this is UART transmit OUT from FPGA to world
Pin 3 — RX   → FPGA ball for UART receive INTO FPGA (not currently used)
Pin 4 — TDI  → JTAG data in
Pin 5 — TCK  → JTAG clock
Pin 6 — TDO  → JTAG data out
Pin 7 — TMS  → JTAG mode select
Pin 8 — 5V0  → 5V power input to Tang board
```
Important: Pin 2 (TX/M11) is the FPGA's UART TX output. It idles HIGH (~3.3V) when idle.
FPGA pin M11 is in an IO bank that supports LVCMOS33 (3.3V logic output).

---

### 2. FT232H Breakout Board (JTAG Programmer + Tang Power Supply)

**What it is:** A single-channel USB↔UART/MPSSE chip from FTDI. In MPSSE mode it
does hardware JTAG at up to 30 MHz. This replaced the earlier ESP32 bitbang JTAG
approach which was too slow (estimated 2.5 hours for 4.5MB bitstream at 115200 baud).

**USB identification:**
- VID:PID = 0403:6014
- Kernel driver: ftdi_sio (creates /dev/ttyUSB1 in UART mode)
- openFPGALoader uses libftdi directly and bypasses /dev/ttyUSB1 entirely

**Critical behavior:**
- openFPGALoader claims the USB device exclusively via libftdi. While it runs,
  the ftdi_sio kernel driver cannot use /dev/ttyUSB1.
- After openFPGALoader exits, ftdi_sio reclaims the device and /dev/ttyUSB1 reappears.
- Sometimes the FT232H disappears completely (neither libftdi nor ftdi_sio can see it).
  Fix: physically unplug and replug the FT232H USB cable. Always fix this way.
- The "FAIL" message at the end of every openFPGALoader flash is a FALSE ALARM.
  It is the Gowin SRAM readback verify step failing (Gowin SRAM is not readable after
  IR_PROG_INACTIVE is sent). The flash itself succeeds. The FPGA runs the new bitstream.
- udev rule required for non-root access:
  `/etc/udev/rules.d/99-ft232h.rules`:
  `SUBSYSTEM=="usb", ATTR{idVendor}=="0403", ATTR{idProduct}=="6014", MODE="666", GROUP="plugdev"`

**Physical wiring — FT232H to Tang SH1.0 connector:**
```
FT232H pin  →  Tang SH1.0 pin  →  Signal
D0          →  Pin 5           →  TCK (JTAG clock)
D1          →  Pin 4           →  TDI (JTAG data in to FPGA)
D2          →  Pin 6           →  TDO (JTAG data out from FPGA)
D3          →  Pin 7           →  TMS (JTAG mode select)
5V          →  Pin 8           →  5V0 (powers the entire Tang board)
GND         →  Pin 1           →  GND
```
Note: FT232H D0=TCK, D1=TDI, D2=TDO, D3=TMS — standard MPSSE JTAG pinout.
The Tang TX wire (Pin 2) is NOT connected to FT232H at all — it goes to ESP32.

**Commands:**
```bash
# Detect Tang (confirms FT232H + Tang alive):
openFPGALoader -c ft232 --detect
# Expected output: idcode 0x81b, manufacturer Gowin, family GW2A, model GW2A(R)-18(C)

# Flash a bitstream:
openFPGALoader -c ft232 -b tangprimer20k <file.fs>
# "FAIL" at end = normal, ignore it

# If FT232H not found ("unable to open ftdi device"):
# Unplug FT232H USB cable, wait 2 seconds, replug, try again.
```

---

### 3. ESP32 DevKit (UART Monitor / Serial Relay)

**What it does:** Receives UART bytes from Tang TX pin on GPIO16, forwards them
to the PC over USB serial (/dev/ttyUSB0). Acts as a bridge so we can see FPGA output.

**USB identification:**
- VID:PID = 10c4:ea60 (Silicon Labs CP2102)
- Always appears as /dev/ttyUSB0

**CRITICAL WARNING: /dev/ttyACM0 is the owner's Android phone. NEVER open, write,
or touch /dev/ttyACM0 under any circumstances. It is NOT an ESP32 or FPGA.**

**Physical wiring — Tang to ESP32:**
```
Tang SH1.0 Pin 2 (TX / FPGA M11)  →  ESP32 GPIO25
```
That is the only wire between Tang and ESP32. No power wire — they are powered independently.

GPIO25 was chosen after GPIO16, GPIO17, and GPIO13 caused boot corruption issues (strapping pin
interference during ESP32 reset). GPIO13 has no special strapping or SPI flash functions.
Signal confirmed physically arriving at GPIO13 via digitalRead test (saw toggling 0x00/0x80).

**ESP32 UART2 configuration in sketch:**
```cpp
Serial2.begin(115200, SERIAL_8N1, 25, -1);  // RX=GPIO13, TX=none (-1)
```
ESP32 GPIO matrix allows routing UART2 RX to any pin including GPIO13.

**ESP32 DevKit GPIO13 physical location:**
On the standard 38-pin ESP32 DevKit, GPIO13 is on the left side row.
Always verify against a labeled pinout diagram — easy to miscount.

**Current sketch on ESP32:** uart_relay.ino
Location: /home/bismillah/Arduino/uart_relay/uart_relay.ino
Baud: 115200. Pins: GPIO16 RX. No TX. Forwards every byte from Serial2 to Serial (USB).
When it boots correctly, it prints: `[relay] ready — forwarding GPIO16 → USB`
You can verify the sketch is running by resetting ESP32 via DTR toggle and reading the banner.

---

### Complete Wiring Summary (All 3 Devices)

```
PC USB-A ──────────────────────────────── FT232H USB-B (0403:6014 = /dev/ttyUSB1)
                                               │
                          FT232H D0 (TCK) ─── Tang SH1.0 Pin 5
                          FT232H D1 (TDI) ─── Tang SH1.0 Pin 4
                          FT232H D2 (TDO) ─── Tang SH1.0 Pin 6
                          FT232H D3 (TMS) ─── Tang SH1.0 Pin 7
                          FT232H 5V ───────── Tang SH1.0 Pin 8 (powers Tang)
                          FT232H GND ──────── Tang SH1.0 Pin 1

PC USB-A ──────────────────────────────── ESP32 USB (10c4:ea60 = /dev/ttyUSB0)
                                               │
                          Tang SH1.0 Pin 2 ── ESP32 GPIO13

PC USB-A (DO NOT USE) ─────────────────── /dev/ttyACM0 (owner's phone — leave alone)
```

---

### Wiring Mistakes History — Read Before Touching Any Wire

These mistakes were made and debugged across many hours. Do not repeat them:

1. **GPIO27 instead of GPIO16** — The wire was physically one pin off from GPIO16 on the
   ESP32 header. This caused zero signal on GPIO16 even though the wire looked connected.
   Always count pins carefully from a labeled reference, not by feel.

2. **GPIO26 instead of GPIO16** — TANG_RX was defined as 26 in aipu_combined.ino.
   Serial2.begin() with GPIO26 appeared to initialize but never decoded UART correctly.
   gpio16_test showed zero transitions on GPIO26 even when FPGA was transmitting.
   GPIO16 is the correct default hardware UART2 RX pin on ESP32.

3. **T13 pin — not accessible on bare board** — uart_hello.v (the test bitstream in
   teacher-aipu/test/) outputs UART on FPGA pin T13, not M11. T13 is exposed only
   on the SODIMM edge connector or via the dock. On the bare board T13 is floating.
   The file uart_top.fs uses M11 (SH1.0 Pin 2) which IS accessible. Always use M11.

4. **SoftwareSerial at 115200** — Tried EspSoftwareSerial library on ESP32 at 115200 baud.
   It does NOT work. It outputs raw sampled bit values as bytes (0x80, 0xC0 repeating pattern)
   instead of decoded UART characters. SoftwareSerial on ESP32 tops out around 19200 baud
   reliably. Do not use it. Hardware Serial2 on GPIO16 is the correct approach.

5. **PULL_MODE=UP on UART TX** — An earlier version of uart_top.cst had PULL_MODE=UP
   on M11. A pull-up resistor on a UART TX pin fights the FPGA when it tries to pull
   the line low for start bits. This would prevent proper UART transmission. Always use
   PULL_MODE=NONE on TX pins.

6. **LVCMOS33 on H11 (clock pin)** — H11 is in IO bank 0 which runs at 1.8V VCCIO.
   Earlier CST files used LVCMOS33 for the clk port on H11. This is wrong and can cause
   the FPGA to not clock properly. Always use LVCMOS18 for H11. Fixed in current CST.

7. **FT232H + ftdi_sio conflict** — The kernel ftdi_sio driver and libftdi (used by
   openFPGALoader) cannot share the FT232H simultaneously. If openFPGALoader times out
   or is killed mid-flash, the device can get stuck. Solution: always unplug/replug.

---

## Software — Toolchain (Every Tool, Every Command)

### Yosys (Plain Verilog Synthesis)
Version: 0.52 (git sha1 fee39a3284)
Binary: /usr/bin/yosys
LIMITATION: Yosys 0.52 CANNOT parse SystemVerilog packed array port declarations.
systolic_NxN.v line 6 has `input [7:0] a_in[0:N-1]` — this causes:
`systolic_NxN.v:6: ERROR: syntax error, unexpected '[', expecting ',' or '=' or ')'`
Do NOT use plain yosys for the main AIPU. Use Synlig instead.
Yosys CAN be used for simple standalone files like uart_top.v (no packed arrays).

### Synlig (SystemVerilog-Aware Synthesis)
Location: /home/bismillah/teacher-aipu/rtl/synlig/synlig (local binary, not in PATH)
What it is: Yosys with Surelog as the SystemVerilog frontend. Handles packed arrays.
The system `synlig` command exists but uses a different plugin path and may fail.
ALWAYS use the local binary: `./synlig/synlig` from inside the rtl/ directory.

Full synthesis command for AIPU:
```bash
cd ~/teacher-aipu/rtl
./synlig/synlig -p "read_systemverilog mac.v systolic_NxN.v chain_CxC.v grid_GxG.v \
  dispatcher.v memory_ctrl.v uart_tx.v result_sender.v top.v top_fpga.v; \
  synth_gowin -top top_fpga -json top_fpga.json; stat"
```
Expected output includes: no fatal errors, no syntax errors. Warnings about integer loop
variables and non-standard constructs are normal and can be ignored.
Last successful stat: ~1,914 LUT4, ~344 ALU, ~881 DFF, total ~6,541 cells.

### ES Speed Grade Patch (Required After Every Synth)
Problem: synth_gowin embeds "GW2A-18C-ES" as the device string in the output JSON.
nextpnr-himbaechel-gowin does NOT have "ES" in its chipdb and refuses to run.
Fix — patch the JSON before P&R:
```bash
python3 -c "
import re
with open('top_fpga.json') as f: txt = f.read()
txt = re.sub(r'GW2A-18C-ES', 'GW2A-18C', txt)
with open('top_fpga_p.json', 'w') as f: f.write(txt)
"
```
This replaces "GW2A-18C-ES" with "GW2A-18C" everywhere in the JSON.
The output file (top_fpga_p.json) is what goes into nextpnr.

### nextpnr-himbaechel-gowin (Place & Route)
Binary: /usr/bin/nextpnr-himbaechel-gowin
NOT /usr/bin/nextpnr-gowin (different tool, wrong for this board)

CRITICAL: The --device string must be `GW2A-LV18PG256C8/I7`
Using `GW2A-18C` triggers: `ERROR: Speed grade 'ES' not found in database`
even after patching the JSON, because the device string itself encodes the grade.
`GW2A-LV18PG256C8/I7` means: GW2A family, LV (low voltage), 18C (18K LUT), PG256 (256-pin),
C8/I7 (commercial temp grade 8, industrial grade 7). This avoids the ES lookup.

CST syntax for nextpnr: pass via --vopt, not --cst:
```bash
nextpnr-himbaechel-gowin \
  --device GW2A-LV18PG256C8/I7 \
  --vopt family=GW2A-18C \
  --vopt cst=top.cst \
  --json top_fpga_p.json \
  --write top_fpga_routed.json
```
Timing result from last successful run:
  Max frequency: 167.06 MHz (PASS at 27 MHz)
  Critical path: 5.99 ns (SRAM read path — routing wire between distant LUTs)
  26,026 routing iterations

### gowin_pack (Bitstream Generation)
```bash
gowin_pack -d GW2A-18C -o top_fpga.fs top_fpga_routed.json
```
Output: top_fpga.fs, approximately 4.5 MB
This is the final bitstream file that gets flashed to the FPGA.

### Verilator (RTL Simulation)
All RTL files simulate cleanly with zero errors and zero warnings.
The only warning ever seen: reset used both async (in RTL) and checked synchronously (in TB).
Fixed by adding `/* verilator lint_off ... */` in top_tb.v.

Simulation command:
```bash
cd ~/teacher-aipu/rtl
verilator --sv --binary --trace -o sim_top \
  top_tb.v mac.v systolic_NxN.v chain_CxC.v grid_GxG.v \
  dispatcher.v memory_ctrl.v uart_tx.v result_sender.v top.v
./sim_top
```
Expected output: tasks accepted at t=60,90,120,150; queue fills to 6, drains to 0; no errors.

### openFPGALoader (Flash Tool)
Uses libftdi to talk to FT232H directly. Completely bypasses /dev/ttyUSB1.
```bash
openFPGALoader -c ft232 -b tangprimer20k top_fpga.fs
```
The `-c ft232` flag selects FT232H in MPSSE mode.
The `-b tangprimer20k` flag tells it the board type (sets JTAG sequence).
Exit code 0 = success even when "FAIL" is printed. The FAIL is readback verify only.

---

## RTL Architecture — Every File Explained

### File Tree
```
teacher-aipu/
├── rtl/                    ← Main AIPU RTL and synthesis artifacts
│   ├── mac.v               ← Single MAC unit
│   ├── systolic_NxN.v      ← N×N systolic array of MACs (uses SV packed arrays)
│   ├── systolic_2x2.v      ← Hardcoded 2×2 version (for early testing)
│   ├── chain_CxC.v         ← C chains of N×N arrays
│   ├── grid_GxG.v          ← G×G grid of chains
│   ├── dispatcher.v        ← Task queue, depth=8, dispatches work to grid
│   ├── memory_ctrl.v       ← 1KB SRAM interface for weights/activations
│   ├── result_sender.v     ← Reads results from grid, serializes over UART
│   ├── uart_tx.v           ← 115200 baud UART transmitter (used everywhere)
│   ├── top.v               ← AIPU top: wires everything together
│   ├── top_fpga.v          ← FPGA wrapper: assigns physical pins H11, M11
│   ├── top.cst             ← Pin constraints: H11=clk(LVCMOS18), M11=TX(LVCMOS33)
│   ├── top_tb.v            ← Testbench (passes clean in Verilator)
│   ├── top_fpga.json       ← Synlig synthesis output (pre-patch)
│   ├── top_fpga_routed.json ← nextpnr P&R output
│   ├── top_fpga.fs         ← Final bitstream (4.5MB, flash this)
│   ├── synlig/             ← Local Synlig binary and share/ files
│   ├── flash_fpga.py       ← Old Python JTAG bitbang flash script (replaced by FT232H)
│   └── esp32_jtag/         ← Old ESP32 JTAG sketch (replaced by FT232H)
│
├── uart/                   ← Standalone UART test designs
│   ├── uart_top.v          ← Sends "AIPU OK\r\n" every 1s after 1s boot delay, TX on M11
│   ├── uart_tx.v           ← Same uart_tx.v as in rtl/ (copy)
│   ├── uart_top.cst        ← H11=LVCMOS18, M11=LVCMOS33 PULL_MODE=NONE (CORRECT)
│   ├── uart_top.fs         ← Bitstream for uart_top (115200 baud, M11) — USE THIS FOR UART TEST
│   ├── uart_9600.fs        ← 9600 baud version (only for SoftwareSerial debugging, irrelevant)
│   ├── uart_t13.fs         ← TX on T13 (NOT accessible on bare board — DISCARD/IGNORE)
│   ├── uart_top_nodelay.v  ← No boot delay version (written but P&R failed — see continue.md)
│   ├── uart_rx.v           ← UART receiver (not yet integrated)
│   ├── debug_uart.py       ← Listen on ttyUSB0, print hex+ASCII of all received bytes
│   ├── debug2.py           ← ESP32 alive check + 5s Tang data listen combined
│   └── ping_esp32.py       ← Reset ESP32 via DTR, read and print banner
│
├── test/                   ← First uart test (uses T13, not SH1.0 TX)
│   ├── uart_hello.v        ← Self-contained UART, no submodule, TX on T13
│   ├── uart_hello.cst      ← H11=LVCMOS18, T13=LVCMOS33 (T13 not accessible bare board)
│   └── uart_hello.fs       ← Built bitstream (TX on T13 = useless without dock)
│
├── tb/                     ← Early testbenches
├── sim/                    ← Simulation VCD output files
├── mac/                    ← Early standalone MAC tests
└── about.md / continue.md  ← YOU ARE HERE
```

### RTL Hierarchy (How Data Flows)
```
top_fpga.v  [pins: clk=H11 27MHz, uart_tx_pin=M11]
  └── top.v  [parameters: G=2, C=2, N=2, CLK_FREQ=27M, BAUD=115200]
        │
        ├── grid_GxG.v  [G×G = 2×2 = 4 grid cells total]
        │     └── chain_CxC.v  [C=2 chains per grid cell]
        │           └── systolic_NxN.v  [N×N = 2×2 = 4 MACs per array]
        │                 └── mac.v  [1 MAC: a(8b) × b(8b) → acc(32b), pipelined]
        │                     Each MAC: INT8 × INT8 → INT32 accumulator
        │                     Inputs pass through (systolic: shift left each cycle)
        │                     Weights stay (loaded once, reused)
        │
        ├── dispatcher.v  [task queue depth=8]
        │     Accepts task descriptors: weight_addr, activation_addr, output_addr
        │     Controls which grid cell gets work next
        │     queue_full signal prevents overflow
        │     task_accepted signal confirms receipt
        │
        ├── memory_ctrl.v  [1KB SRAM via Gowin BSRAM primitive]
        │     Stores weights and activations
        │     Read/write interface shared between dispatcher and result_sender
        │
        ├── result_sender.v  [reads results from grid, sends over UART]
        │     Waits for grid cell done signal
        │     Reads 32-bit results, converts to ASCII hex
        │     Feeds bytes to uart_tx one at a time
        │
        └── uart_tx.v  [115200 baud, 8N1, active-low start bit]
              CLK_FREQ/BAUD_RATE = 27,000,000/115,200 = 234 clocks per bit
              State machine: IDLE → START → DATA[0..7] → STOP → IDLE
              busy signal prevents next byte until current one finishes
```

### Key Parameters (change these to scale the design)
```verilog
// In top.v / top_fpga.v:
parameter G = 2;              // Grid is G×G cells
parameter C = 2;              // C chains per cell
parameter N = 2;              // Each chain is N×N systolic array
parameter CLK_FREQ  = 27_000_000;
parameter BAUD_RATE = 115_200;

// Total MACs = G×G × C × N×N = 4 × 2 × 4 = 32 MACs at G=C=N=2
// TOPS = MACs × 2 × clock_freq / 1e12
```

### CST File — Pin Constraints (top.cst, MUST BE EXACT)
```
IO_LOC "clk"          H11;
IO_PORT "clk"         PULL_MODE=NONE IO_TYPE=LVCMOS18;
IO_LOC "uart_tx_pin"  M11;
IO_PORT "uart_tx_pin" PULL_MODE=NONE IO_TYPE=LVCMOS33;
```
H11 = 27MHz crystal, bank 0 = 1.8V → LVCMOS18 is mandatory.
M11 = SH1.0 Pin 2 TX output, bank supports 3.3V → LVCMOS33, PULL_MODE=NONE mandatory.

---

## Arduino Sketches — Every File

All sketches are in /home/bismillah/Arduino/<sketch_name>/<sketch_name>.ino

### uart_relay.ino (CURRENT ACTIVE SKETCH)
Purpose: Simplest possible relay. Reads Tang TX via Serial2 on GPIO13 at 115200,
forwards every byte to Serial (USB). Nothing else. No JTAG. No WiFi. No command parser.
```cpp
// uart_relay on GPIO13 — safe pin, no strapping or SPI flash conflicts
void setup() {
  Serial.begin(115200);
  pinMode(13, INPUT_PULLUP);
  delay(100);
  Serial2.begin(115200, SERIAL_8N1, 25, -1);
  Serial.println("[relay] ready GPIO13");
}
void loop() {
  while (Serial2.available()) Serial.write(Serial2.read());
}
```
When running correctly, resetting ESP32 (via DTR toggle) produces this banner:
`[relay] ready GPIO13`

### aipu_combined.ino (OLD — replaced by FT232H for JTAG)
The "kitchen sink" sketch from before FT232H arrived:
- JTAG bitbang: handled 'R','B','Q','0'-'7','W' single-char commands from flash_fpga.py
- WiFi setup portal: first boot creates "AIPU-Setup-OpenNoorIlmTechnology" hotspot,
  connects to home WiFi, saves credentials to flash via Preferences.h
- Web server: served live Tang UART output at http://<esp32-ip>/ with 2s auto-refresh
- Ring buffer: 8KB buffer so no output is missed even if FPGA boots before page opens
- TANG_RX was GPIO26 in this sketch (wrong — caused decode failure)
- TANG_RX was later changed to GPIO16 but Serial2 still failed there for unknown reason
This sketch is now OBSOLETE. FT232H does JTAG, uart_relay.ino does UART monitoring.
Kept for reference in case WiFi streaming is ever wanted again.

### gpio16_test.ino (DEBUG TOOL)
Reads GPIO16 as raw digitalRead() 1000 times/second, prints transitions count every 1s.
Used historically to confirm whether signal reached GPIO16. No longer used — wire is now on GPIO13.
A similar inline digitalRead test on GPIO13 confirmed FPGA signal IS arriving:
saw \x00\x80 alternating pattern (raw bit samples of the 115200 baud UART signal).
This proved M11 is transmitting and the wire is making contact.

### gpio26_test.ino (DEBUG TOOL — GPIO26 no longer used)
Same as gpio16_test but for GPIO26. Used during early wiring debugging.
When wire was on GPIO26 and FPGA running uart_top.fs:
showed `0x0c` and `0x0e` bytes alternating — raw USB serial of '0'/'1' ASCII chars
printed at high rate by digitalRead loop. This CONFIRMED signal was reaching GPIO26 at that point.
But then wire was moved to GPIO27 by mistake. By the time it was corrected to GPIO16,
gpio16_test showed zero — suggesting signal not reaching GPIO16 or uart_top not transmitting.

### soft_relay.ino (BROKEN — do not use)
Used EspSoftwareSerial library. Set to GPIO26 RX, 115200 baud.
Output was 0x80/0xC0/0x00 repeating pattern — raw bit samples, not decoded UART.
SoftwareSerial on ESP32 cannot reliably decode 115200 baud. Do not use.

### tdo_scan.ino (written inline during debug, not saved to file)
Scanned all ESP32 GPIOs for TDO response from Tang JTAG.
Confirmed TDO was on GPIO4 (matched our wiring). Helped confirm JTAG was connected correctly
before FT232H arrived.

### flash_fpga.py (OLD Python JTAG bitbang — rtl/flash_fpga.py)
Used before FT232H arrived. Sent JTAG commands to ESP32 via serial.
ESP32 would bitbang TCK/TDI/TDO/TMS. Speed: ~7.9 KB/s (4.5MB = ~10 minutes per flash).
Supported --idcode, --verify, --watch (auto-reflash on .fs change), --fs flags.
Now OBSOLETE. openFPGALoader with FT232H flashes in seconds. Keep for reference only.

---

## Known Toolchain Quirks and Gotchas

1. **Synlig vs system synlig:** The LOCAL binary at rtl/synlig/synlig is the one that works.
   The system `synlig` command may exist but lacks the correct share/ path and fails.
   Always: `cd ~/teacher-aipu/rtl && ./synlig/synlig ...`

2. **nextpnr binary name:** It is `nextpnr-himbaechel-gowin`, NOT `nextpnr-gowin`.
   There is also `/usr/bin/nextpnr-gowin` but it is the wrong one for this board.

3. **nextpnr --cst flag:** The himbaechel version does NOT accept `--cst`.
   CST is passed as: `--vopt cst=filename.cst`

4. **Device string for nextpnr:** Must use `GW2A-LV18PG256C8/I7`, not `GW2A-18C`.
   `GW2A-18C` triggers ES speed grade error because chipdb maps it to the ES variant.

5. **ftdi_sio vs libftdi conflict:** openFPGALoader needs the FT232H unclaimed by kernel.
   If /dev/ttyUSB1 exists and is open, openFPGALoader fails with "unable to claim usb device".
   Solution: ensure nothing is reading /dev/ttyUSB1, or unplug/replug FT232H.

6. **Gowin SRAM verify always fails:** After IR_PROG_INACTIVE the config SRAM is not readable.
   Any verify step after deactivation returns all zeros. This is expected, not a bug.
   The flash succeeded if openFPGALoader printed "Load SRAM: 100%" without an error before FAIL.

7. **Tang loses bitstream when unpowered:** FPGA SRAM is volatile. Every power cycle
   (including FT232H USB cable unplug) wipes the bitstream. Always reflash after any power loss.

8. **Arduino IDE and ttyUSB0 conflict:** When Arduino IDE flashes the ESP32 via ttyUSB0,
   any Python script reading ttyUSB0 must be closed first. They share the same port.
   Also: flashing ESP32 can sometimes cause FT232H to drop off USB (they share the USB hub).
   If FT232H disappears after an ESP32 flash, unplug and replug the FT232H.

---

## AIPU Future Roadmap (Detailed)

### Compute Scale
```
Step          G   C   N    MACs        TOPS   Process      Estimated Cost
Teacher       2   2   2    32          0.005  Tang 20K     Hardware owned
Prototype     2   2   8    512         ~0.1   Larger FPGA  ~$50 FPGA
First Si      4   4   16   16,384      4      TSMC 28nm    ~$10K MPW shuttle
Prod v1       8   4   32   262,144     100    TSMC 12nm    ~$500K
Prod v2       16  8   32   2,097,152   4,194  TSMC 6nm     ~$5-10M
```
TOPS = MACs × 2 × clock_GHz. H100 = 3,958 TOPS. Production v2 beats H100.
B200 = 9,000 TOPS. Production v2 does not beat B200.

### Precision Roadmap (after FPGA architecture validated)
Current: INT8 × INT8 → INT32 (unsigned, 8-bit weights and activations)
Next steps:
1. Signed INT8 (-128 to 127) — low complexity, just sign extension in accumulator
2. FP8 (1 sign + 4 exp + 3 mantissa) — medium complexity, new fp8_mul.v module
3. BF16 (1 sign + 8 exp + 7 mantissa) — high complexity, IEEE 754 rounding, ~500 lines
4. Mixed precision: INT8/FP8 weights + BF16 activations + FP32 accumulator (like Tensor Cores)

The MAC unit will get a precision selector register:
```verilog
input [1:0] precision  // 00=INT8, 01=FP8, 10=BF16, 11=FP32
```

### Silicon Path
- efabless.com MPW shuttle: ~$10,000 for a multi-project wafer slot, TSMC 28nm
  Good for first silicon verification of the architecture
- Production: requires foundry direct relationship and significant funding
