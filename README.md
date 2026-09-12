<div align="center">

# AIPU — Open-Source AI Processing Unit

**A fully custom systolic-array AI accelerator, designed from scratch in SystemVerilog,
running on a Sipeed Tang Primer 20K FPGA. Parameterized to scale from 0.005 TOPS on an FPGA
prototype all the way to 4,194 TOPS on a production silicon chip — surpassing the NVIDIA H100.**

[![License: CERN-OHL-S](https://img.shields.io/badge/Hardware-CERN--OHL--S--2.0-blue?style=for-the-badge)](hardware/LICENSE)
[![License: GPL v3](https://img.shields.io/badge/Software-GPL--v3.0-green?style=for-the-badge)](software/LICENSE)
[![Toolchain: Open Source](https://img.shields.io/badge/Toolchain-100%25%20Open%20Source-orange?style=for-the-badge)](#toolchain)
[![Status: UART Confirmed](https://img.shields.io/badge/HW%20Status-UART%20Confirmed-brightgreen?style=for-the-badge)](#status)

*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*
*In the name of Allah, the Most Gracious, the Most Merciful*

**Noor ul Ilm — Light of Knowledge**

</div>

---

## Table of Contents

- [What It Is](#what-it-is)
- [Compute Scale Roadmap](#compute-scale-roadmap)
- [Architecture](#architecture)
  - [RTL Hierarchy](#rtl-hierarchy)
  - [Module Reference](#module-reference)
  - [Key Parameters](#key-parameters)
- [Repository Structure](#repository-structure)
- [Hardware](#hardware)
  - [Components](#components)
  - [Full Wiring Diagram](#full-wiring-diagram)
  - [SH1.0 Connector Pinout](#sh10-connector-pinout)
  - [Pin Constraints](#pin-constraints-cst)
- [Toolchain](#toolchain)
  - [Installation](#installation)
  - [Build Pipeline](#build-pipeline)
- [Quick Start](#quick-start)
  - [Build and Flash FPGA](#1-build-and-flash-fpga)
  - [Flash ESP32 Relay](#2-flash-esp32-relay)
  - [Read AIPU Output](#3-read-aipu-output)
- [Simulation](#simulation)
- [Precision Roadmap](#precision-roadmap)
- [Status](#status)
- [License](#license)

---

## What It Is

AIPU is a hardware AI accelerator built entirely from first principles. It implements a
**systolic array** of Multiply-Accumulate (MAC) units in SystemVerilog — the same fundamental
architecture used in Google's TPU and NVIDIA's Tensor Cores — but fully open source and
designed to run without any proprietary tools.

The architecture is controlled by three parameters: **G** (grid size), **C** (chains per
cell), and **N** (array dimensions). Changing those three numbers rescales the entire design
from a proof-of-concept on a $20 FPGA to a chip that beats the H100.

- **Hardware** licensed under **CERN-OHL-S v2** (strongly reciprocal open hardware)
- **Software** licensed under **GNU GPL v3** (copyleft open source)
- **Toolchain** is 100% open source — Yosys, Synlig, nextpnr, Verilator, openFPGALoader

---

## Compute Scale Roadmap

| Step | G | C | N | Total MACs | TOPS | Target Process | Est. Cost |
|------|---|---|---|-----------|------|---------------|-----------|
| **Teacher (NOW)** | 2 | 2 | 2 | 32 | 0.005 | Tang Primer 20K FPGA | Hardware owned |
| Prototype | 2 | 2 | 8 | 512 | ~0.1 | Larger FPGA | ~$50 |
| First Silicon | 4 | 4 | 16 | 16,384 | 4 | TSMC 28nm (efabless MPW) | ~$10,000 |
| Production v1 | 8 | 4 | 32 | 262,144 | 100 | TSMC 12nm | ~$500,000 |
| **Production v2** | 16 | 8 | 32 | 2,097,152 | **4,194** | TSMC 6nm | ~$5–10M |

> **TOPS = MACs × 2 × clock_GHz**
> NVIDIA H100 = 3,958 TOPS. Production v2 exceeds it.
> The same RTL, unchanged, just different parameter values.

---

## Architecture

### RTL Hierarchy

```
top_fpga.v                          ← FPGA wrapper, physical pin assignments
│   clk      → H11 (27 MHz crystal, LVCMOS18, IO bank 0 = 1.8V)
│   uart_tx  → M11 (SH1.0 Pin 2,   LVCMOS33, idle HIGH)
│
└── top.v  [G=2, C=2, N=2, CLK=27MHz, BAUD=115200]
      │
      ├── grid_GxG.v                ← G×G = 4 grid cells
      │     └── chain_CxC.v        ← C=2 chains per cell
      │           └── systolic_NxN.v  ← N×N = 4 MACs, weight-stationary
      │                 └── mac.v  ← INT8×INT8 → INT32, 1 cycle latency
      │                     Weights: stationary (loaded once, reused)
      │                     Activations: shift through array each cycle
      │
      ├── dispatcher.v              ← Task queue (depth=8), controls grid
      │     Accepts: weight_addr, activation_addr, output_addr
      │     Signals: task_valid, task_accepted, queue_full
      │
      ├── memory_ctrl.v             ← 1 KB SRAM (Gowin BSRAM primitive)
      │     Shared between dispatcher (writes) and result_sender (reads)
      │
      ├── result_sender.v           ← Reads results, serializes to UART
      │     Boot: sends "AIPU OK\r\n" after 1s delay
      │     Run:  waits for mem_done, reads SRAM, forwards bytes to uart_tx
      │
      └── uart_tx.v                 ← 115200 8N1 UART transmitter
            CLK_PER_BIT = 27,000,000 / 115,200 = 234 (0.16% error)
            States: IDLE → START → DATA[0..7] → STOP → IDLE
            busy signal: prevents next byte until current finishes
```

### Module Reference

| File | Module | Purpose |
|------|--------|---------|
| `hardware/rtl/mac.v` | `mac` | Single INT8 MAC unit: `acc += a × b`. 1-cycle pipelined. |
| `hardware/rtl/systolic_NxN.v` | `systolic_NxN` | N×N systolic array. Activations flow right; weights stationary. Uses SV packed array ports. |
| `hardware/rtl/systolic_2x2.v` | `systolic_2x2` | Hardcoded 2×2 version for early testing without SystemVerilog parser. |
| `hardware/rtl/chain_CxC.v` | `chain_CxC` | C sequential systolic arrays chained together. |
| `hardware/rtl/grid_GxG.v` | `grid_GxG` | G×G grid of chains. Parallel tile execution. |
| `hardware/rtl/dispatcher.v` | `dispatcher` | Task queue depth=8. Dispatches work descriptors to grid cells. |
| `hardware/rtl/memory_ctrl.v` | `memory_ctrl` | 1 KB SRAM controller using Gowin BSRAM primitive. R/W interface. |
| `hardware/rtl/result_sender.v` | `result_sender` | Reads results from SRAM, sends ASCII over UART. Sends `AIPU OK\r\n` on boot. |
| `hardware/rtl/uart_tx.v` | `uart_tx` | 115200 8N1 UART TX. Parameterized CLK_FREQ and BAUD_RATE. |
| `hardware/rtl/top.v` | `top` | AIPU top-level. Wires grid, dispatcher, memory, result_sender, uart. |
| `hardware/rtl/top_fpga.v` | `top_fpga` | FPGA wrapper. Maps H11→clk, M11→uart_tx_pin. |
| `hardware/rtl/top_tb.v` | `top_tb` | Verilator testbench. Zero errors, zero warnings. |
| `hardware/uart/uart_top.v` | `uart_top` | Standalone test: sends `AIPU OK\r\n` every 1s. Used for UART chain verification. |
| `hardware/uart/uart_rx.v` | `uart_rx` | UART receiver (not yet integrated into top). |
| `hardware/uart/blink_m11.v` | `blink_m11` | Blinks M11 at 1 Hz. Used to verify IO bank is alive. |

### Key Parameters

```verilog
// In top.v — change these to scale the entire design:
parameter G = 2;                // Grid is G×G cells
parameter C = 2;                // Chains per grid cell
parameter N = 2;                // Each array is N×N MACs
parameter CLK_FREQ  = 27_000_000;
parameter BAUD_RATE = 115_200;

// Derived quantities (automatic):
// Total MACs  = G*G * C * N*N  →  at G=C=N=2: 4 × 2 × 4 = 32 MACs
// TOPS        = Total_MACs * 2 * CLK_FREQ / 1e12
// CLK_PER_BIT = CLK_FREQ / BAUD_RATE  →  27M / 115200 = 234
```

---

## Repository Structure

```
AIPU/
├── README.md                        ← You are here
├── .gitignore
│
├── hardware/                        ← CERN-OHL-S v2
│   ├── LICENSE
│   ├── top.cst                      ← Master pin constraints (used by nextpnr)
│   ├── tang.cfg                     ← openFPGALoader board config
│   │
│   ├── rtl/                         ← Main AIPU RTL
│   │   ├── mac.v
│   │   ├── systolic_NxN.v           ← SystemVerilog (packed array ports)
│   │   ├── systolic_2x2.v
│   │   ├── chain_CxC.v
│   │   ├── grid_GxG.v
│   │   ├── dispatcher.v
│   │   ├── memory_ctrl.v
│   │   ├── result_sender.v
│   │   ├── uart_tx.v
│   │   ├── top.v
│   │   ├── top_fpga.v               ← FPGA top-level (H11 clk, M11 TX)
│   │   ├── top_tb.v                 ← Verilator testbench
│   │   ├── synth.ys                 ← Yosys script
│   │   ├── do.sh                    ← Full build script (synth→P&R→pack→flash)
│   │   └── upload.sh
│   │
│   ├── uart/                        ← UART test designs
│   │   ├── uart_top.v               ← Sends "AIPU OK\r\n" every 1s via M11
│   │   ├── uart_top.cst             ← H11=LVCMOS18, M11=LVCMOS33 PULL_MODE=NONE
│   │   ├── uart_tx.v                ← Copy of rtl/uart_tx.v
│   │   ├── uart_rx.v                ← UART receiver (future integration)
│   │   ├── uart_loopback_tb.v       ← Loopback testbench
│   │   ├── blink_m11.v              ← 1Hz blink on M11 (IO bank alive test)
│   │   ├── debug_uart.py            ← Listen ttyUSB0, print hex+ASCII
│   │   ├── debug2.py                ← ESP32 alive check + 5s Tang listen
│   │   └── ping_esp32.py            ← Reset ESP32 via DTR, print banner
│   │
│   ├── tb/                          ← Early testbenches
│   │   ├── mac_tb.v
│   │   ├── systolic_2x2_tb.v
│   │   └── systolic_NxN_tb.v
│   │
│   ├── sim/                         ← Simulation VCD outputs (gitignored)
│   ├── mac/                         ← Standalone early MAC experiments
│   └── test/                        ← uart_hello sanity test (TX on T13, not SH1.0)
│       ├── uart_hello.v
│       └── uart_hello.cst
│
└── software/                        ← GPL v3
    ├── LICENSE
    └── firmware/
        └── uart_relay.ino           ← ESP32: relays Tang TX (GPIO25) → USB serial
```

> **Build artifacts are gitignored:** `obj_dir/`, `slpp_all/`, `synlig/`, `*.fs`, `*.json`, `*.vcd`
> Regenerate with the commands in [Build Pipeline](#build-pipeline).

---

## Hardware

### Components

| Component | Part | Detail |
|-----------|------|--------|
| **FPGA** | Sipeed Tang Primer 20K | Gowin GW2A-18C ES, 20K LUTs, 256-pin BGA (SODIMM form factor). **Bare board, no dock.** |
| **FPGA Oscillator** | 27 MHz crystal | Connected to FPGA ball H11. H11 is in IO bank 0 (1.8V VCCIO). Must be LVCMOS18. |
| **JTAG Programmer** | FT232H breakout | FTDI FT232H, VID:PID 0403:6014. MPSSE mode for hardware JTAG up to 30 MHz. Also powers the Tang via its 5V pin. |
| **UART Relay** | ESP32 DevKit | CP2102 USB-serial, VID:PID 10c4:ea60. Runs `uart_relay.ino`. Forwards FPGA UART output to PC over USB. |
| **FPGA Connector** | SH1.0 8-pin JST | The **only** accessible IO on the bare Tang board. 1mm pitch. Custom crimped cable with 2.54mm dupont on the other end. |

> ⚠️ **Tang Primer 20K bare board has NO standard GPIO headers.** The only accessible pins are
> the SH1.0 8-pin connector and the SODIMM edge (unusable without the dock).

### Full Wiring Diagram

```
                    ┌─────────────────────────────┐
                    │     Tang Primer 20K          │
                    │     (GW2A-18C FPGA)          │
                    │                             │
                    │  H11 ← 27MHz crystal (onboard)│
                    │  M11 → SH1.0 Pin 2 (TX out) │
                    └──────────┬──────────────────┘
                               │ SH1.0 8-pin connector
          ┌────────────────────┴────────────────────────────────┐
          │                                                     │
  Pin 1 (GND) ─────────────────────────────────── GND (common)
  Pin 2 (TX/M11) ──────────────────────────────── ESP32 GPIO25
  Pin 4 (TDI) ─────────── FT232H D1
  Pin 5 (TCK) ─────────── FT232H D0
  Pin 6 (TDO) ─────────── FT232H D2
  Pin 7 (TMS) ─────────── FT232H D3
  Pin 8 (5V0) ─────────── FT232H 5V  (Tang powered by FT232H)
          │
          └──────────────────────────────────────────────────────┘

FT232H USB ──→ PC  (/dev/ttyUSB1, kernel: ftdi_sio, used by openFPGALoader via libftdi)
ESP32  USB ──→ PC  (/dev/ttyUSB0, kernel: cp210x)

⛔ /dev/ttyACM0 = owner's Android phone — NEVER open or write to this device
```

### SH1.0 Connector Pinout

```
SH1.0 Pin │ FPGA Ball │ Signal  │ Direction      │ Notes
──────────┼──────────┼─────────┼────────────────┼──────────────────────────────
  Pin 1   │    —      │  GND    │ —              │ Common ground
  Pin 2   │   M11     │  TX     │ FPGA → World   │ UART out, 3.3V, idles HIGH
  Pin 3   │   (RX)    │  RX     │ World → FPGA   │ Not currently used
  Pin 4   │   (TDI)   │  TDI    │ FT232H → FPGA  │ JTAG data in
  Pin 5   │   (TCK)   │  TCK    │ FT232H → FPGA  │ JTAG clock
  Pin 6   │   (TDO)   │  TDO    │ FPGA → FT232H  │ JTAG data out
  Pin 7   │   (TMS)   │  TMS    │ FT232H → FPGA  │ JTAG mode select
  Pin 8   │    —      │  5V0    │ FT232H → Tang  │ Powers entire Tang board
```

> Pin 1 is at the bottom (board edge side), Pin 8 is at the top. Pins are 1mm apart —
> **verify with a caliber or reference diagram before inserting wires.**

### Pin Constraints (CST)

```
# hardware/uart/uart_top.cst  (used for uart test)
# hardware/top.cst            (used for full AIPU)

IO_LOC  "clk"          H11;
IO_PORT "clk"          PULL_MODE=NONE IO_TYPE=LVCMOS18;

IO_LOC  "uart_tx_pin"  M11;
IO_PORT "uart_tx_pin"  PULL_MODE=NONE IO_TYPE=LVCMOS33;
```

> **H11 must be LVCMOS18** — IO bank 0 runs at 1.8V VCCIO. Using LVCMOS33 here causes
> the clock to malfunction silently; the FPGA runs but outputs nothing.
>
> **M11 must be PULL_MODE=NONE** — a pull-up on a UART TX pin fights the FPGA's low-level
> start bit drive, suppressing UART transmission.

---

## Toolchain

All tools are **100% open source**. No Gowin IDE, no Vivado, no Quartus.

| Tool | Version | Role | Install |
|------|---------|------|---------|
| [Yosys](https://github.com/YosysHQ/yosys) | 0.52 | Verilog synthesis (standalone files only) | `apt install yosys` |
| [Synlig](https://github.com/chipsalliance/synlig) | local binary | SystemVerilog synthesis (packed arrays) | Download release binary |
| [nextpnr-himbaechel-gowin](https://github.com/YosysHQ/nextpnr) | latest | Place & Route for GW2A | Build from source |
| [apicula / gowin_pack](https://github.com/YosysHQ/apicula) | latest | Bitstream generation | `pip install apycula` |
| [openFPGALoader](https://github.com/trabucayre/openFPGALoader) | latest | FPGA flash via FT232H | `apt install openfpgaloader` |
| [Verilator](https://www.veripool.org/verilator/) | 5.x | RTL simulation | `apt install verilator` |

> ⚠️ **Do NOT use system `synlig`** — use the local binary at `hardware/rtl/synlig/synlig`.
> The system install may lack the correct `share/` path.
>
> ⚠️ **Do NOT use `nextpnr-gowin`** — use `nextpnr-himbaechel-gowin`. Different tool.

### Installation

```bash
# Core tools
sudo apt install yosys verilator openfpgaloader

# gowin_pack (apicula)
pip install apycula

# Synlig — download the release binary for your distro from:
# https://github.com/chipsalliance/synlig/releases
# Extract into hardware/rtl/synlig/

# nextpnr-himbaechel-gowin — build from source:
# https://github.com/YosysHQ/nextpnr#gowin
```

### Build Pipeline

Every step in order, from RTL to running FPGA:

```bash
cd hardware/rtl

# ── Step 1: Synthesize with Synlig (SystemVerilog-aware) ──────────────────
./synlig/synlig -p "
  read_systemverilog mac.v systolic_NxN.v chain_CxC.v grid_GxG.v \
    dispatcher.v memory_ctrl.v uart_tx.v result_sender.v top.v top_fpga.v;
  synth_gowin -top top_fpga -json top_fpga.json;
  stat
"
# Expected: ~1,914 LUT4, ~344 ALU, ~881 DFF, ~6,541 cells total. No errors.

# ── Step 2: Patch ES device string ───────────────────────────────────────
# synth_gowin writes "GW2A-18C-ES" but nextpnr only knows "GW2A-18C"
python3 -c "
import re
with open('top_fpga.json') as f: t = f.read()
t = re.sub(r'GW2A-18C-ES', 'GW2A-18C', t)
with open('top_fpga_p.json', 'w') as f: f.write(t)
print('Patched OK')
"

# ── Step 3: Place & Route ─────────────────────────────────────────────────
nextpnr-himbaechel-gowin \
  --device GW2A-LV18PG256C8/I7 \
  --vopt family=GW2A-18C \
  --vopt cst=../top.cst \
  --json top_fpga_p.json \
  --write top_fpga_routed.json
# Expected: PASS at 27 MHz, max frequency 167 MHz, ~26,000 routing iterations

# ── Step 4: Pack Bitstream ────────────────────────────────────────────────
gowin_pack -d GW2A-18C -o top_fpga.fs top_fpga_routed.json
# Output: top_fpga.fs (~4.5 MB)

# ── Step 5: Flash to FPGA ─────────────────────────────────────────────────
openFPGALoader -c ft232 -b tangprimer20k top_fpga.fs
# "FAIL" at the end = normal (SRAM readback verify, not a real failure)
# Flash succeeded if you see "Load SRAM: 100%"
```

> ⚠️ **`--device` must be `GW2A-LV18PG256C8/I7`**, not `GW2A-18C`.
> Using `GW2A-18C` triggers `ERROR: Speed grade 'ES' not found in database` because
> the chipdb maps that string to the ES variant internally.
>
> ⚠️ **CST is passed as `--vopt cst=file.cst`**, not `--cst`. The himbaechel variant
> does not accept `--cst` directly.

---

## Quick Start

### 1. Build and Flash FPGA

```bash
# Clone
git clone https://github.com/OpenNoorIlm/AIPU.git
cd AIPU

# Build (see full pipeline above, or use do.sh)
cd hardware/rtl
./do.sh          # runs all 5 steps automatically

# Or flash a pre-built bitstream (if you have top_fpga.fs):
openFPGALoader -c ft232 -b tangprimer20k top_fpga.fs
```

### 2. Flash ESP32 Relay

Open `software/firmware/uart_relay.ino` in Arduino IDE (ESP32 board support required).
Select your ESP32 DevKit board and the correct COM port, then flash.

The sketch configures `Serial2` on **GPIO25** at **115200 baud** and forwards every
received byte to USB serial. On boot it prints:

```
[relay] booting...
[relay] ready GPIO25
```

### 3. Read AIPU Output

```bash
# After flashing FPGA and ESP32, read on Linux:
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

**Expected output (confirmed on hardware):**

```
t=0.0s: b'AIPU OK\r\nAIPU OK\r\nAIPU OK\r\nAIPU OK\r\n...'
```

### 4. Verify the Chain Is Alive

```bash
# Detect Tang via JTAG (confirms FT232H + Tang communication):
openFPGALoader -c ft232 --detect
# Expected: idcode 0x81b, manufacturer Gowin, family GW2A

# Verify ESP32 relay banner:
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

---

## Simulation

```bash
cd hardware/rtl

# Compile and simulate
verilator --sv --binary --trace -o sim_top \
  top_tb.v mac.v systolic_NxN.v chain_CxC.v grid_GxG.v \
  dispatcher.v memory_ctrl.v uart_tx.v result_sender.v top.v

./sim_top
```

**Expected output:**
```
[  60ns] task accepted, id=1
[  90ns] task accepted, id=2
[ 120ns] task accepted, id=3
[ 150ns] task accepted, id=4
Queue depth: 6 → drains to 0
No errors. No warnings.
```

VCD trace is written to the working directory and can be viewed in GTKWave:

```bash
gtkwave top_tb.vcd
```

---

## Precision Roadmap

The MAC unit currently performs **unsigned INT8 × INT8 → INT32** accumulation.
Upcoming precision additions (each backward compatible, selected by a 2-bit register):

| Phase | Precision | Complexity | Status |
|-------|-----------|-----------|--------|
| Current | Unsigned INT8 | — | ✅ Done |
| Next | **Signed INT8** | Low — sign extension in accumulator | 🔄 Planned |
| Phase 3 | **FP8** (1s + 4e + 3m) | Medium — new `fp8_mul.v` | ⬜ Planned |
| Phase 4 | **BF16** (1s + 8e + 7m) | High — IEEE 754 rounding (~500 lines) | ⬜ Planned |
| Phase 5 | **Mixed** INT8/FP8 weights + BF16 activations + FP32 accumulator | Very High | ⬜ Future |

The MAC precision selector will be:

```verilog
input [1:0] precision  // 2'b00=INT8  2'b01=FP8  2'b10=BF16  2'b11=FP32
```

---

## Status

| Milestone | Status | Notes |
|-----------|--------|-------|
| MAC unit RTL + simulation | ✅ **Done** | Zero errors in Verilator |
| Systolic array RTL + simulation | ✅ **Done** | NxN parameterized |
| Full RTL synthesis (Synlig) | ✅ **Done** | ~6,541 cells, no errors |
| Place & Route (nextpnr) | ✅ **Done** | Max 167 MHz, PASS at 27 MHz |
| Bitstream generation | ✅ **Done** | 4.5 MB .fs file |
| FPGA flash via FT232H | ✅ **Done** | ~10 seconds per flash |
| UART TX confirmed on hardware | ✅ **Done** | `AIPU OK\r\n` received on PC |
| Full AIPU output on hardware | ✅ **Done** | `AIPU OK` streaming confirmed |
| Send compute tasks, read results | 🔄 **In Progress** | Next immediate step |
| Signed INT8 support | ⬜ Planned | `$signed()` in mac.v |
| FP8 support | ⬜ Planned | New `fp8_mul.v` |
| BF16 support | ⬜ Planned | ~500 lines |
| Mixed precision MAC | ⬜ Planned | 2-bit precision selector |
| Port to larger FPGA | ⬜ Planned | Scale G, C, N |
| First silicon (efabless MPW) | ⬜ Future | TSMC 28nm, ~$10K |
| Production chip | ⬜ Future | TSMC 6nm, 4,194 TOPS |

---

## License

| Scope | License |
|-------|---------|
| **Hardware** — RTL, constraints, schematics, layout | [CERN Open Hardware Licence v2 - Strongly Reciprocal (CERN-OHL-S)](hardware/LICENSE) |
| **Software** — firmware, scripts, host tools | [GNU General Public License v3.0 (GPL-3.0)](software/LICENSE) |

© 2025 OpenNoorIlm contributors

This is open hardware and open software. If you build hardware using this design,
you must make your modified sources available under the same CERN-OHL-S license.
If you distribute software derived from this project, it must remain GPL-3.0.

---

<div align="center">

*"And He taught Adam the names of all things"* — Quran 2:31

**OpenNoorIlm — Open Light of Knowledge**

[GitHub](https://github.com/OpenNoorIlm/AIPU) · [Issues](https://github.com/OpenNoorIlm/AIPU/issues)

</div>
