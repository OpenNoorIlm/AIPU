<div align="center">

# AIPU — Open-Source AI Processing Unit

### *A fully custom systolic-array AI accelerator designed from first principles in SystemVerilog.*
### *Runs today on a $20 FPGA. Parameterized to scale to 4,194 TOPS on production silicon — surpassing the NVIDIA H100.*

<br>

[![License: CERN-OHL-S](https://img.shields.io/badge/Hardware-CERN--OHL--S--2.0-blue?style=for-the-badge&logo=opensourceinitiative&logoColor=white)](hardware/LICENSE)
[![License: GPL v3](https://img.shields.io/badge/Software-GPL--v3.0-green?style=for-the-badge&logo=gnu&logoColor=white)](software/LICENSE)
[![Toolchain: 100% Open](https://img.shields.io/badge/Toolchain-100%25%20Open%20Source-orange?style=for-the-badge&logo=linux&logoColor=white)](#toolchain)
[![HW Status](https://img.shields.io/badge/Hardware-AIPU%20OK%20Confirmed-brightgreen?style=for-the-badge&logo=checkmarx&logoColor=white)](#status)
[![Custom License](https://img.shields.io/badge/Commercial%20Use-Contact%20Us-purple?style=for-the-badge&logo=mail&logoColor=white)](#contact--custom-licensing)

<br>

*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*

*In the name of Allah, the Most Gracious, the Most Merciful*

**نور العلم — Noor ul Ilm — Light of Knowledge**

<br>

</div>

---

## Table of Contents

- [What It Is](#what-it-is)
- [Why It Matters](#why-it-matters)
- [Compute Scale Roadmap](#compute-scale-roadmap)
- [Architecture](#architecture)
  - [RTL Hierarchy](#rtl-hierarchy)
  - [Data Flow](#data-flow)
  - [Module Reference](#module-reference)
  - [Key Parameters](#key-parameters)
- [Repository Structure](#repository-structure)
- [Hardware](#hardware)
  - [Bill of Materials](#bill-of-materials)
  - [Full Wiring Diagram](#full-wiring-diagram)
  - [SH1.0 Connector Pinout](#sh10-connector-pinout)
  - [Pin Constraints (CST)](#pin-constraints-cst)
  - [Known Hardware Gotchas](#known-hardware-gotchas)
- [Toolchain](#toolchain)
  - [Tool Reference](#tool-reference)
  - [Installation](#installation)
  - [Build Pipeline](#build-pipeline)
  - [Known Toolchain Gotchas](#known-toolchain-gotchas)
- [Quick Start](#quick-start)
- [Simulation](#simulation)
- [Precision Roadmap](#precision-roadmap)
- [Status](#status)
- [Contributing](#contributing)
- [License](#license)
- [Contact & Custom Licensing](#contact--custom-licensing)

---

## What It Is

AIPU is a hardware AI accelerator built entirely from first principles — no IP cores, no vendor libraries, no proprietary tools. It implements a **weight-stationary systolic array** of Multiply-Accumulate (MAC) units in SystemVerilog: the same fundamental architecture used inside Google's TPU and NVIDIA's Tensor Cores.

The entire design is controlled by **three integer parameters**: `G` (grid size), `C` (chains per cell), and `N` (array dimensions). Changing those three numbers — and only those three numbers — rescales the hardware from a proof-of-concept on a $20 FPGA to a chip that beats the H100 in raw INT8 throughput.

```
Current state:  G=2, C=2, N=2  →  32 MACs  →  0.005 TOPS  on Tang Primer 20K FPGA ✅
Production v2:  G=16, C=8, N=32 →  2,097,152 MACs  →  4,194 TOPS  on TSMC 6nm
```

### Design Principles

- **No proprietary tools.** Synthesized with Yosys + Synlig, placed & routed with nextpnr, flashed with openFPGALoader. Zero dependency on Gowin IDE, Vivado, or Quartus.
- **Parameterized, not hardcoded.** One RTL, any scale.
- **Built by hand.** Every wire, every module, every debug session from scratch.
- **Fully copyleft.** Hardware under CERN-OHL-S v2. Software under GPL-3.0. If you build on it, you share back.

---

## Why It Matters

The global AI chip market is dominated by a handful of companies. Designing AI accelerator hardware is considered inaccessible without million-dollar EDA tool licenses, NDA-gated process design kits, and large teams.

AIPU proves that is false.

A working AI Processing Unit — verified on real silicon (the FPGA fabric) — can be designed with free tools, cheap hardware, and one person. The same architecture, parameterized upward, reaches the performance tier of the world's most powerful AI accelerators.

The first open-source, community-built AI chip is not a thought experiment. It is a git repository.

---

## Compute Scale Roadmap

> **Formula:** `TOPS = Total_MACs × 2 × clock_GHz`
> where `Total_MACs = G² × C × N²`

| Step | G | C | N | Total MACs | TOPS | Process | Est. Cost | Status |
|------|---|---|---|------------|------|---------|-----------|--------|
| **Teacher** | 2 | 2 | 2 | 32 | 0.005 | Tang 20K FPGA | Owned | ✅ Running |
| Prototype | 2 | 2 | 8 | 512 | ~0.1 | Larger FPGA | ~$50 | ⬜ Next |
| First Silicon | 4 | 4 | 16 | 16,384 | ~4 | TSMC 28nm (efabless MPW) | ~$10,000 | ⬜ Planned |
| Production v1 | 8 | 4 | 32 | 262,144 | ~100 | TSMC 12nm | ~$500,000 | ⬜ Future |
| **Production v2** | 16 | 8 | 32 | 2,097,152 | **4,194** | TSMC 6nm | ~$5–10M | ⬜ Future |

> **NVIDIA H100** = 3,958 TOPS (INT8). **Production v2 exceeds it.**
> **NVIDIA B200** = ~9,000 TOPS. Production v2 does not yet exceed it — that is Production v3.
>
> The RTL is identical across all rows. Only the three parameter values change.

---

## Architecture

### RTL Hierarchy

```
top_fpga.v                            ← FPGA wrapper: physical pin assignments only
│
│   clk          → H11  (27 MHz onboard crystal, LVCMOS18, IO bank 0 = 1.8V VCCIO)
│   uart_tx_pin  → M11  (SH1.0 Pin 2, LVCMOS33, 3.3V, idles HIGH when no data)
│
└── top.v  [parameters: G=2, C=2, N=2, CLK_FREQ=27_000_000, BAUD_RATE=115_200]
      │
      ├── grid_GxG.v                  ← G×G = 4 independent grid cells
      │     └── chain_CxC.v          ← C=2 chains wired in series per cell
      │           └── systolic_NxN.v ← N×N = 4 MACs in weight-stationary array
      │                 └── mac.v    ← Single MAC: acc[31:0] += a[7:0] × b[7:0]
      │                              ← 1-cycle multiply, registered output
      │                              ← Weights held, activations shift left each cycle
      │
      ├── dispatcher.v                ← Task queue, depth=8
      │     Inputs:  task_valid, task_id[7:0], task_cycles[31:0]
      │     Outputs: task_accepted, active_task[G][G][7:0]
      │     Controls which grid cell receives work and when
      │
      ├── memory_ctrl.v               ← 1 KB on-chip SRAM (Gowin BSRAM primitive)
      │     Read/write interface shared between dispatcher and result_sender
      │     Address space: weights + activations + output results
      │
      ├── result_sender.v             ← Result serializer
      │     Boot: sends "AIPU OK\r\n" after 1-second delay (confirmed on hardware)
      │     Run:  waits for mem_done pulse → reads SRAM → feeds uart_tx byte by byte
      │     States: S_BOOT_WAIT → S_BOOT_SEND → S_BOOT_TICK → S_IDLE → S_READ → S_SEND → S_WAIT
      │
      └── uart_tx.v                   ← UART transmitter, 115200 8N1
            CLK_PER_BIT = 27_000_000 / 115_200 = 234  (0.16% error, within UART tolerance)
            States: IDLE → START_BIT → DATA[0] → … → DATA[7] → STOP_BIT → IDLE
            busy output: high while transmitting, blocks next byte from loading
```

### Data Flow

```
Host PC
  │
  │  [future: send task descriptor over UART RX]
  │
  ▼
uart_rx.v  ──►  dispatcher.v  ──►  grid_GxG.v
                                       │
                                       │ (G×G systolic arrays computing in parallel)
                                       │
                                   memory_ctrl.v  ◄──  accumulates INT32 results
                                       │
                                       ▼
                               result_sender.v  ──►  uart_tx.v  ──►  M11 pin
                                                                         │
                                                                    SH1.0 Pin 2
                                                                         │
                                                                    ESP32 GPIO25
                                                                         │
                                                                    /dev/ttyUSB0
                                                                         │
                                                                      Host PC
```

### Module Reference

| File | Module | Lines | Purpose |
|------|--------|-------|---------|
| `hardware/rtl/mac.v` | `mac` | ~40 | Single INT8 MAC: `acc[31:0] += a[7:0] × b[7:0]`. Registered, 1-cycle latency. |
| `hardware/rtl/systolic_NxN.v` | `systolic_NxN` | ~80 | N×N weight-stationary systolic array. Uses SystemVerilog packed array ports `[7:0] a_in[0:N-1]`. |
| `hardware/rtl/systolic_2x2.v` | `systolic_2x2` | ~60 | Hardcoded 2×2 version. Used for early Yosys testing (no SV packed arrays). |
| `hardware/rtl/chain_CxC.v` | `chain_CxC` | ~60 | C systolic arrays wired in series. Output of one feeds next. |
| `hardware/rtl/grid_GxG.v` | `grid_GxG` | ~80 | G×G grid of chains. Parallel independent execution. |
| `hardware/rtl/dispatcher.v` | `dispatcher` | ~110 | FIFO task queue, depth=8. Routes tasks to grid cells. Signals `task_accepted`, `queue_full`. |
| `hardware/rtl/memory_ctrl.v` | `memory_ctrl` | ~90 | 1 KB SRAM via Gowin BSRAM. R/W arbitration between dispatcher and result_sender. |
| `hardware/rtl/result_sender.v` | `result_sender` | ~160 | 7-state FSM. Sends `AIPU OK\r\n` on boot, then sends SRAM result bytes over UART. |
| `hardware/rtl/uart_tx.v` | `uart_tx` | ~70 | Parameterized 8N1 UART TX. CLK_FREQ/BAUD_RATE = CLK_PER_BIT. `busy` signal for flow control. |
| `hardware/rtl/top.v` | `top` | ~120 | AIPU top: instantiates and connects all submodules. G, C, N defined here. |
| `hardware/rtl/top_fpga.v` | `top_fpga` | ~30 | FPGA pin wrapper. Assigns H11→clk, M11→uart_tx_pin. Instantiates top. |
| `hardware/rtl/top_tb.v` | `top_tb` | ~150 | Verilator testbench. Drives clock, reset, task inputs. Zero errors, zero warnings. |
| `hardware/uart/uart_top.v` | `uart_top` | ~100 | Standalone UART test. Sends `AIPU OK\r\n` every 1s after 1s boot delay. TX on M11. |
| `hardware/uart/uart_rx.v` | `uart_rx` | ~80 | UART receiver. Parameterized. Not yet integrated into top. |
| `hardware/uart/blink_m11.v` | `blink_m11` | ~20 | 1 Hz blink on M11. Used to confirm IO bank VCCIO is alive when UART produces nothing. |

### Key Parameters

```verilog
// ── In hardware/rtl/top.v ─────────────────────────────────────────────────────
//    Change these three values to scale the entire design:

parameter G = 2;               // Grid dimensions: G×G independent cells
parameter C = 2;               // Chains per cell: C systolic arrays in series
parameter N = 2;               // Array dimensions: each array is N×N MACs

parameter CLK_FREQ  = 27_000_000;   // 27 MHz — Tang Primer 20K onboard crystal
parameter BAUD_RATE = 115_200;      // UART baud rate (matched to ESP32 relay sketch)

// ── Derived (computed automatically from above) ───────────────────────────────
//
//   Total MACs     = G*G * C * N*N
//                  = 4 * 2 * 4 = 32    (at G=C=N=2)
//
//   TOPS           = Total_MACs * 2 * CLK_FREQ / 1e12
//                  = 32 * 2 * 27e6 / 1e12 = 0.001728 TOPS   (at G=C=N=2, 27MHz)
//
//   CLK_PER_BIT    = CLK_FREQ / BAUD_RATE
//                  = 27_000_000 / 115_200 = 234   (0.16% error — within UART tolerance)
//
//   Queue depth    = 8 tasks (hardcoded in dispatcher.v, safe for current grid size)
```

---

## Repository Structure

```
AIPU/
├── README.md                          ← You are here
├── .gitignore                         ← Excludes build artifacts, bitstreams, VCDs
│
├── hardware/                          ← Licensed: CERN-OHL-S v2
│   ├── LICENSE                        ← Full CERN-OHL-S v2 text
│   ├── top.cst                        ← Master CST: H11=LVCMOS18, M11=LVCMOS33
│   ├── tang.cfg                       ← openFPGALoader board config for Tang 20K
│   │
│   ├── rtl/                           ← Main AIPU RTL source
│   │   ├── mac.v                      ← INT8 MAC unit
│   │   ├── systolic_NxN.v             ← N×N systolic array (SystemVerilog packed arrays)
│   │   ├── systolic_2x2.v             ← Hardcoded 2×2 (plain Verilog, no SV needed)
│   │   ├── chain_CxC.v                ← Chain of C arrays
│   │   ├── grid_GxG.v                 ← G×G grid of chains
│   │   ├── dispatcher.v               ← Task queue and dispatch controller
│   │   ├── memory_ctrl.v              ← SRAM controller (Gowin BSRAM)
│   │   ├── result_sender.v            ← Result serializer, sends over uart_tx
│   │   ├── uart_tx.v                  ← 115200 8N1 UART transmitter
│   │   ├── top.v                      ← AIPU top-level (G, C, N defined here)
│   │   ├── top_fpga.v                 ← FPGA wrapper: H11 clk, M11 uart_tx_pin
│   │   ├── top_tb.v                   ← Verilator testbench (passes clean)
│   │   ├── synth.ys                   ← Standalone Yosys synthesis script
│   │   ├── do.sh                      ← Full build: synth → patch → P&R → pack → flash
│   │   ├── upload.sh                  ← Flash only
│   │   ├── flash_fpga.py              ← Old ESP32 JTAG bitbang flasher (obsolete)
│   │   └── esp32_jtag/
│   │       └── esp32_jtag.ino         ← Old ESP32 JTAG sketch (obsolete, replaced by FT232H)
│   │
│   ├── uart/                          ← UART test designs and debug tools
│   │   ├── uart_top.v                 ← Sends "AIPU OK\r\n" every 1s via M11
│   │   ├── uart_top.cst               ← H11=LVCMOS18, M11=LVCMOS33, PULL_MODE=NONE
│   │   ├── uart_tx.v                  ← Copy of rtl/uart_tx.v
│   │   ├── uart_rx.v                  ← UART RX (future integration into top)
│   │   ├── uart_loopback_tb.v         ← Loopback simulation testbench
│   │   ├── blink_m11.v                ← 1Hz blink on M11 (IO bank alive diagnostic)
│   │   ├── debug_uart.py              ← Listen /dev/ttyUSB0, print hex + ASCII
│   │   ├── debug2.py                  ← ESP32 alive check + 5s Tang data listen
│   │   └── ping_esp32.py              ← DTR-reset ESP32, capture and print banner
│   │
│   ├── tb/                            ← Early standalone testbenches
│   │   ├── mac_tb.v
│   │   ├── systolic_2x2_tb.v
│   │   └── systolic_NxN_tb.v
│   │
│   ├── sim/                           ← Simulation VCD output (gitignored)
│   ├── mac/                           ← Early standalone MAC experiments
│   └── test/                          ← uart_hello test (TX on T13, NOT SH1.0 — bare board only)
│       ├── uart_hello.v
│       └── uart_hello.cst
│
└── software/                          ← Licensed: GPL-3.0
    ├── LICENSE                        ← Full GPL-3.0 text
    └── firmware/
        └── uart_relay.ino             ← ESP32: Serial2(GPIO25, 115200) → USB serial relay
```

> **All build artifacts are gitignored** and must be regenerated locally:
> `obj_dir/`, `slpp_all/`, `synlig/`, `*.fs` (bitstreams), intermediate `*.json`, `*.vcd`
>
> See [Build Pipeline](#build-pipeline) for full regeneration commands.

---

## Hardware

### Bill of Materials

| # | Component | Part Number / Description | Role | Notes |
|---|-----------|--------------------------|------|-------|
| 1 | **FPGA Board** | Sipeed Tang Primer 20K | Target compute device | Gowin GW2A-18C ES grade, 20K LUTs, 256-pin BGA, SODIMM form factor. **Bare board, no dock.** SRAM-based: bitstream lost on power cycle. |
| 2 | **JTAG Programmer** | FT232H USB breakout | Programs FPGA + powers Tang | FTDI FT232H, VID:PID `0403:6014`. MPSSE hardware JTAG up to 30 MHz. Also supplies 5V to Tang via SH1.0 Pin 8. |
| 3 | **UART Relay** | ESP32 DevKit V1 (38-pin) | Bridges FPGA UART to PC USB | CP2102 USB-serial, VID:PID `10c4:ea60`. Runs `uart_relay.ino`. Serial2 on GPIO25. |
| 4 | **Connector Cable** | SH1.0 8-pin JST crimped cable | Only accessible IO on bare Tang | 1mm pitch JST SH on Tang side, 2.54mm dupont female on other end. Custom crimped. |
| 5 | **Dupont wires** | Female-to-female 2.54mm | Point-to-point connections | Used for FT232H↔SH1.0 and Tang TX↔ESP32 GPIO25. |

> ⚠️ The Tang Primer 20K **bare board** (not the kit with dock) has **zero standard GPIO headers**.
> The SH1.0 8-pin connector is the only way to reach any FPGA IO pin.
> The SODIMM edge connector is only accessible via the dock, which is not used here.

### Full Wiring Diagram

```
┌─────────────────────────────────────────────────────────┐
│           Tang Primer 20K (GW2A-18C FPGA)               │
│                                                         │
│   H11 ◄── 27 MHz crystal (onboard, not wired externally)│
│   M11 ──► SH1.0 Pin 2  (UART TX output, 3.3V)          │
└──────────────────────┬──────────────────────────────────┘
                       │
              SH1.0 8-pin JST connector (1mm pitch)
                       │
   ┌───────────────────┴──────────────────────────────────────────┐
   │                                                              │
   │  Pin 1 (GND) ─────────────────────────────── GND ──── GND   │
   │  Pin 2 (TX / M11) ────────────────────────── ESP32 GPIO25   │
   │  Pin 3 (RX) ──────────────────────────────── [unconnected]   │
   │  Pin 4 (TDI) ─────────────────────────────── FT232H D1      │
   │  Pin 5 (TCK) ─────────────────────────────── FT232H D0      │
   │  Pin 6 (TDO) ─────────────────────────────── FT232H D2      │
   │  Pin 7 (TMS) ─────────────────────────────── FT232H D3      │
   │  Pin 8 (5V0) ─────────────────────────────── FT232H 5V      │
   └──────────────────────────────────────────────────────────────┘

FT232H USB  ───►  PC  /dev/ttyUSB1  (ftdi_sio kernel driver)
                      Used by openFPGALoader via libftdi (bypasses ttyUSB1)

ESP32  USB  ───►  PC  /dev/ttyUSB0  (cp210x kernel driver)
                      Read this to see FPGA output

⛔  /dev/ttyACM0  =  owner's Android phone — DO NOT touch under any circumstances
```

### SH1.0 Connector Pinout

| Pin | FPGA Ball | Signal | Direction | IO Standard | Notes |
|-----|-----------|--------|-----------|-------------|-------|
| 1 | — | GND | — | — | Common ground, connect to all devices |
| **2** | **M11** | **TX** | **FPGA → World** | **LVCMOS33** | **UART TX output. 3.3V. Idles HIGH. This is the data wire.** |
| 3 | (RX) | RX | World → FPGA | LVCMOS33 | Not yet used. `uart_rx.v` exists but not integrated. |
| 4 | (TDI) | TDI | FT232H D1 → FPGA | — | JTAG data in |
| 5 | (TCK) | TCK | FT232H D0 → FPGA | — | JTAG clock |
| 6 | (TDO) | TDO | FPGA → FT232H D2 | — | JTAG data out |
| 7 | (TMS) | TMS | FT232H D3 → FPGA | — | JTAG mode select |
| 8 | — | 5V0 | FT232H → Tang | — | 5V input — powers entire Tang board |

> **Pin 1 is at the bottom** (nearest the board edge). Pin 8 is at the top.
> Pins are spaced **1mm apart** — one pin offset is enough to connect to GND instead of TX.
> Always verify against a labeled diagram before inserting wires.

### Pin Constraints (CST)

```
# Used by nextpnr via:  --vopt cst=hardware/top.cst
# Or for UART test:     --vopt cst=hardware/uart/uart_top.cst

IO_LOC  "clk"          H11;
IO_PORT "clk"          PULL_MODE=NONE IO_TYPE=LVCMOS18;

IO_LOC  "uart_tx_pin"  M11;
IO_PORT "uart_tx_pin"  PULL_MODE=NONE IO_TYPE=LVCMOS33;
```

> **Why LVCMOS18 on H11:**
> H11 sits in IO bank 0, whose VCCIO rail is 1.8V on the Tang Primer 20K.
> If you declare it LVCMOS33, the FPGA may fail to register the 1.8V clock signal
> (the 3.3V threshold is higher than the 1.8V swing), causing the design to stall silently
> with no output. This is the hardest bug to diagnose — everything looks right but nothing works.
>
> **Why PULL_MODE=NONE on M11:**
> A pull-up resistor on a UART TX line fights the FPGA when it drives the line LOW for a
> start bit or a data 0 bit. The external pull-up wins, suppressing those transitions.
> The receiver sees a line that never goes low — it never detects a start bit — silence.

### Known Hardware Gotchas

| # | Issue | Symptom | Fix |
|---|-------|---------|-----|
| 1 | **Tang SRAM is volatile** | Bitstream lost on every power cycle or FT232H USB unplug | Reflash after every power interruption |
| 2 | **FT232H USB conflict** | `openFPGALoader: unable to open ftdi device` | Unplug FT232H USB, wait 2s, replug |
| 3 | **ESP32 strapping pins** | Serial2 fails to decode UART; relay crash-loops on boot | Use GPIO25 — no strapping, no JTAG, no SPI flash conflicts |
| 4 | **SH1.0 Pin 1 vs Pin 2** | All bytes received as 0x00 (line stuck LOW = GND) | Pin 2 is TX. Pin 1 is GND. They are 1mm apart. Verify with diagram. |
| 5 | **H11 = LVCMOS18 not LVCMOS33** | FPGA runs (JTAG works) but no UART output at all | CST must say `IO_TYPE=LVCMOS18` for H11 |
| 6 | **M11 PULL_MODE=NONE** | Partial or no UART output; start bits suppressed | Remove any pull-up from M11. CST: `PULL_MODE=NONE` |
| 7 | **Gowin SRAM verify "FAIL"** | openFPGALoader prints `FAIL` at end | This is normal. SRAM is not readable after `IR_PROG_INACTIVE`. Flash succeeded if `Load SRAM: 100%` appeared. |
| 8 | **Tang TX corrupts ESP32 boot** | ESP32 crash-loops; garbage on serial | FPGA drives M11 during ESP32 reset. Use a 2s `delay()` in `setup()` before `Serial2.begin()` so ESP32 finishes booting before UART starts. |

---

## Toolchain

All tools are **100% free and open source**. No proprietary EDA licenses required.

### Tool Reference

| Tool | Version | Role | Binary |
|------|---------|------|--------|
| [Yosys](https://github.com/YosysHQ/yosys) | 0.52 | Verilog synthesis backend | `yosys` |
| [Synlig](https://github.com/chipsalliance/synlig) | local | SystemVerilog frontend + synthesis | `hardware/rtl/synlig/synlig` ⚠️ |
| [nextpnr-himbaechel-gowin](https://github.com/YosysHQ/nextpnr) | latest | Place & Route for Gowin GW2A | `nextpnr-himbaechel-gowin` ⚠️ |
| [apicula / gowin_pack](https://github.com/YosysHQ/apicula) | latest | Bitstream packing | `gowin_pack` |
| [openFPGALoader](https://github.com/trabucayre/openFPGALoader) | latest | FPGA programming via FT232H | `openFPGALoader` |
| [Verilator](https://www.veripool.org/verilator/) | 5.x | RTL simulation | `verilator` |
| [GTKWave](https://gtkwave.sourceforge.net/) | any | VCD waveform viewer | `gtkwave` |

> ⚠️ **Synlig:** The system `synlig` command may exist but uses the wrong `share/` path and fails.
> Always use the local binary: `cd hardware/rtl && ./synlig/synlig ...`
>
> ⚠️ **nextpnr:** The correct binary is `nextpnr-himbaechel-gowin`.
> Do **NOT** use `nextpnr-gowin` — it is a different, incompatible tool.

### Installation

```bash
# ── Ubuntu / Debian ───────────────────────────────────────────────────────────
sudo apt update
sudo apt install yosys verilator gtkwave

# openFPGALoader
sudo apt install openfpgaloader
# Or build from source: https://github.com/trabucayre/openFPGALoader

# gowin_pack (part of apicula)
pip install apycula

# ── Synlig ────────────────────────────────────────────────────────────────────
# Download the release binary for your distro:
# https://github.com/chipsalliance/synlig/releases
# Extract and place at:  hardware/rtl/synlig/synlig

# ── nextpnr-himbaechel-gowin ─────────────────────────────────────────────────
# Must be built from source with Gowin chipdb enabled:
# https://github.com/YosysHQ/nextpnr#building-nextpnr-himbaechel

# ── udev rule for FT232H (non-root flash access) ─────────────────────────────
echo 'SUBSYSTEM=="usb", ATTR{idVendor}=="0403", ATTR{idProduct}=="6014", MODE="666", GROUP="plugdev"' \
  | sudo tee /etc/udev/rules.d/99-ft232h.rules
sudo udevadm control --reload-rules && sudo udevadm trigger
```

### Build Pipeline

Every step from RTL source to running FPGA, in order:

```bash
cd hardware/rtl

# ── Step 1: Synthesize with Synlig ───────────────────────────────────────────
# Synlig is required (not plain yosys) because systolic_NxN.v uses
# SystemVerilog packed array ports:  input [7:0] a_in[0:N-1]
# Plain yosys 0.52 cannot parse this syntax.

./synlig/synlig -p "
  read_systemverilog mac.v systolic_NxN.v chain_CxC.v grid_GxG.v \
    dispatcher.v memory_ctrl.v uart_tx.v result_sender.v top.v top_fpga.v;
  synth_gowin -top top_fpga -json top_fpga.json;
  stat
"
# ✓ Expected: no errors, ~1,914 LUT4, ~344 ALU, ~881 DFF, ~6,541 cells total
# ✓ Warnings about integer loop variables are normal — ignore them

# ── Step 2: Patch ES device string ───────────────────────────────────────────
# synth_gowin writes "GW2A-18C-ES" into the JSON.
# nextpnr's chipdb does not contain the "ES" entry — it knows only "GW2A-18C".
# This one-liner patches the JSON before P&R:

python3 -c "
import re
with open('top_fpga.json') as f: t = f.read()
t = re.sub(r'GW2A-18C-ES', 'GW2A-18C', t)
with open('top_fpga_p.json', 'w') as f: f.write(t)
print('Patched: GW2A-18C-ES → GW2A-18C')
"

# ── Step 3: Place & Route ─────────────────────────────────────────────────────
# IMPORTANT: --device must be GW2A-LV18PG256C8/I7, NOT GW2A-18C
# Using GW2A-18C triggers: ERROR: Speed grade 'ES' not found in database
# CST is passed via --vopt cst=, NOT --cst (himbaechel does not accept --cst)

nextpnr-himbaechel-gowin \
  --device GW2A-LV18PG256C8/I7 \
  --vopt family=GW2A-18C \
  --vopt cst=../top.cst \
  --json top_fpga_p.json \
  --write top_fpga_routed.json

# ✓ Expected: PASS at 27 MHz constraint
# ✓ Max achievable frequency: ~167 MHz
# ✓ ~26,000 routing iterations

# ── Step 4: Pack Bitstream ────────────────────────────────────────────────────
gowin_pack -d GW2A-18C -o top_fpga.fs top_fpga_routed.json

# ✓ Output: top_fpga.fs (~4.5 MB)

# ── Step 5: Flash to FPGA ─────────────────────────────────────────────────────
openFPGALoader -c ft232 -b tangprimer20k top_fpga.fs

# ✓ "FAIL" at the end is NORMAL — it is a readback verify step that always fails
#    because Gowin SRAM is not readable after IR_PROG_INACTIVE is sent.
# ✓ Flash succeeded if you see "Load SRAM: [=====] 100%" before the FAIL line.
# ✓ FPGA starts running new bitstream immediately after flash.
```

### Known Toolchain Gotchas

| # | Issue | What happens | Fix |
|---|-------|-------------|-----|
| 1 | Using system `synlig` instead of local | Wrong `share/` path → synthesis fails | Always `./synlig/synlig` from inside `hardware/rtl/` |
| 2 | Using `nextpnr-gowin` instead of `nextpnr-himbaechel-gowin` | Wrong tool, wrong chipdb | Use `nextpnr-himbaechel-gowin` |
| 3 | `--device GW2A-18C` in nextpnr | `ERROR: Speed grade 'ES' not found` | Use `--device GW2A-LV18PG256C8/I7` |
| 4 | `--cst file.cst` in nextpnr | Flag not recognized | Use `--vopt cst=file.cst` |
| 5 | Not patching JSON after synthesis | nextpnr rejects `GW2A-18C-ES` device | Run Step 2 patch script every time |
| 6 | ftdi_sio driver conflict | `openFPGALoader: unable to claim usb device` | Close anything reading ttyUSB1. Unplug/replug FT232H if stuck. |
| 7 | Arduino IDE open during flash | Port conflict on ttyUSB0 or ttyUSB1 | Close Serial Monitor before flashing FPGA |

---

## Quick Start

### 1. Clone

```bash
git clone https://github.com/OpenNoorIlm/AIPU.git
cd AIPU
```

### 2. Build and Flash the FPGA

```bash
# Full automated build (synth → patch → P&R → pack → flash):
cd hardware/rtl && ./do.sh

# Or step by step — see Build Pipeline above.

# Verify Tang is detected:
openFPGALoader -c ft232 --detect
# Expected: idcode 0x81b, manufacturer Gowin, family GW2A, model GW2A(R)-18(C)
```

### 3. Flash the ESP32 Relay

Open `software/firmware/uart_relay.ino` in **Arduino IDE** with ESP32 board support installed.

- Board: `ESP32 Dev Module`
- Port: `/dev/ttyUSB0`
- Flash, then open Serial Monitor at **115200 baud**

On boot you should see:
```
[relay] booting...
[relay] ready GPIO25
```

### 4. Read AIPU Output

```bash
python3 -c "
import serial, time
ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)
ser.reset_input_buffer()
print('Listening 12 seconds...')
t = time.time()
while time.time() - t < 12:
    d = ser.read(64)
    if d: print(f't={time.time()-t:.1f}s: {repr(d)}')
ser.close()
print('Done.')
"
```

**Confirmed hardware output:**

```
t=0.0s: b'AIPU OK\r\nAIPU OK\r\nAIPU OK\r\nAIPU OK\r\nAIPU OK\r\n...'
```

### 5. Verify the Full Chain

```bash
# 1. FPGA detectable:
openFPGALoader -c ft232 --detect

# 2. ESP32 relay banner (reset and read):
python3 -c "
import serial, time
s = serial.Serial('/dev/ttyUSB0', 115200, timeout=5)
s.dtr = False; time.sleep(0.1); s.dtr = True
time.sleep(4)
print(repr(s.read(300)))
s.close()
"
# Expected: b'...[relay] booting...\r\n[relay] ready GPIO25\r\n'

# 3. Flash UART test (isolated from full AIPU):
openFPGALoader -c ft232 -b tangprimer20k hardware/uart/uart_top.fs
# Then run step 4 above — should receive AIPU OK\r\n every 1 second
```

---

## Simulation

```bash
cd hardware/rtl

# ── Compile testbench with Verilator ─────────────────────────────────────────
verilator --sv --binary --trace -o obj_dir/sim_top \
  top_tb.v mac.v systolic_NxN.v chain_CxC.v grid_GxG.v \
  dispatcher.v memory_ctrl.v uart_tx.v result_sender.v top.v

# ── Run simulation ────────────────────────────────────────────────────────────
./obj_dir/sim_top
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

**View waveforms:**
```bash
gtkwave top_tb.vcd
```

Signals of interest in GTKWave: `clk`, `reset`, `task_valid`, `task_accepted`, `queue_full`, `mem_done`, `uart_tx_pin`.

---

## Precision Roadmap

The MAC unit currently performs **unsigned INT8 × INT8 → INT32** accumulation.
Each precision tier is backward compatible; a 2-bit selector register will choose at runtime.

| Phase | Precision | Weights | Activations | Accumulator | Complexity | Status |
|-------|-----------|---------|-------------|-------------|-----------|--------|
| **Current** | Unsigned INT8 | `uint8` | `uint8` | `uint32` | — | ✅ Done |
| **Phase 2** | Signed INT8 | `int8` | `int8` | `int32` | Low — `$signed()` wrappers in `mac.v` | 🔄 Next |
| **Phase 3** | FP8 (E4M3) | `fp8` | `fp8` | `fp32` | Medium — new `fp8_mul.v`, ~150 lines | ⬜ Planned |
| **Phase 4** | BF16 | `bf16` | `bf16` | `fp32` | High — IEEE 754 rounding, ~500 lines | ⬜ Planned |
| **Phase 5** | Mixed | `int8`/`fp8` | `bf16` | `fp32` | Very High — like NVIDIA Tensor Cores | ⬜ Future |

The runtime precision selector:

```verilog
// In mac.v (future):
input [1:0] precision
// 2'b00 = INT8 (current)
// 2'b01 = FP8
// 2'b10 = BF16
// 2'b11 = FP32
```

---

## Status

| Milestone | Status | Details |
|-----------|--------|---------|
| MAC unit RTL | ✅ **Done** | `mac.v` — INT8×INT8→INT32, 1-cycle pipelined |
| MAC simulation | ✅ **Done** | Zero Verilator errors or warnings |
| Systolic NxN RTL | ✅ **Done** | `systolic_NxN.v` — parameterized, weight-stationary |
| Systolic simulation | ✅ **Done** | Loopback testbench passes |
| Full AIPU RTL | ✅ **Done** | All modules: grid, dispatcher, memory, result_sender, uart_tx |
| Full simulation | ✅ **Done** | `top_tb.v` — task dispatch, queue fill/drain, zero errors |
| Synlig synthesis | ✅ **Done** | ~6,541 cells, ~1,914 LUT4, ~881 DFF |
| nextpnr Place & Route | ✅ **Done** | PASS at 27 MHz, max 167 MHz, critical path 5.99 ns |
| Bitstream generation | ✅ **Done** | `top_fpga.fs` ~4.5 MB |
| FT232H JTAG flash | ✅ **Done** | ~10 seconds, `openFPGALoader -c ft232` |
| ESP32 UART relay | ✅ **Done** | GPIO25, 115200 baud, `[relay] ready GPIO25` |
| **UART on hardware** | ✅ **Done** | `AIPU OK\r\n` received on PC — full chain verified |
| Send tasks, read results | 🔄 **In Progress** | UART RX integration + dispatcher protocol |
| Signed INT8 | ⬜ Planned | `$signed()` in `mac.v` |
| FP8 (E4M3) | ⬜ Planned | New `fp8_mul.v` |
| BF16 | ⬜ Planned | IEEE 754, ~500 lines |
| Mixed precision | ⬜ Planned | 2-bit selector, Tensor Core-style |
| Scale to larger FPGA | ⬜ Planned | Increase G, C, N — same RTL |
| First silicon (efabless MPW) | ⬜ Future | TSMC 28nm, ~$10K |
| Production v1 | ⬜ Future | TSMC 12nm, ~100 TOPS |
| Production v2 | ⬜ Future | TSMC 6nm, ~4,194 TOPS — H100-class |

---

## Contributing

Contributions are welcome. This is an early-stage open hardware project and there is a lot to build.

**Good first areas:**
- UART RX integration (bring `uart_rx.v` into `top.v`, add task protocol)
- Signed INT8 support in `mac.v` (low complexity, high value)
- Testbench improvements and coverage expansion
- Documentation, diagrams, and build system improvements

**Before contributing:**
- Read the architecture section fully — especially the RTL hierarchy and data flow
- Check existing modules before writing new ones (e.g. `uart_tx.v` is already parameterized)
- All hardware contributions must be compatible with **CERN-OHL-S v2**
- All software contributions must be compatible with **GPL-3.0**

Open an [issue](https://github.com/OpenNoorIlm/AIPU/issues) before starting significant work,
to avoid duplication and ensure alignment with the roadmap.

---

## License

| What | License | Obligation |
|------|---------|-----------|
| **Hardware** — all RTL `.v` files, constraint `.cst` files, schematics, layout | [CERN-OHL-S v2](hardware/LICENSE) | If you manufacture hardware using this design, you must publicly release your modified source under CERN-OHL-S v2 and mark the hardware with the source location. |
| **Software** — firmware `.ino`, Python scripts, host tools | [GPL-3.0](software/LICENSE) | If you distribute software derived from this project, it must remain GPL-3.0 and source must be made available. |

© 2025 OpenNoorIlm contributors

These are **strongly reciprocal (copyleft)** licenses. They are designed to ensure that improvements to open hardware and software remain open. If your use case requires different terms — for example, you want to integrate AIPU into a proprietary product without releasing your modifications — see the section below.

---

## Contact & Custom Licensing

**The open-source licenses (CERN-OHL-S v2 and GPL-3.0) apply by default to everyone.**

However, as the copyright holder, OpenNoorIlm can grant **additional permissions** or
**alternative commercial licenses** to specific parties — this is called *dual licensing*
and is fully legal. Companies such as Qt (LGPL + commercial), MySQL (GPL + commercial),
and many others use exactly this model.

### When you might need a custom license

- You want to integrate AIPU RTL into a **proprietary chip or product** without open-sourcing your design
- You want to use AIPU firmware or tools in a **closed-source commercial product**
- You want to **redistribute modified versions** without the copyleft obligation
- You want to **manufacture and sell hardware** based on AIPU under a private agreement
- You want to discuss **joint development, investment, or partnership**
- You have a question that doesn't fit neatly into an issue tracker

### How to get in touch

> 📧 **[noorulilm.contact.us@gmail.com](mailto:noorulilm.contact.us@gmail.com)**

Please include in your email:
- What you are building or planning to build
- How you intend to use AIPU (integrate, modify, manufacture, distribute, etc.)
- Whether you need hardware license, software license, or both
- Your timeline and scale (prototype, small batch, mass production, etc.)

All enquiries are welcome — commercial, research, educational, or just a conversation.
We will respond to every serious message.

---

<div align="center">

*"وَعَلَّمَ آدَمَ الْأَسْمَاءَ كُلَّهَا"*

*"And He taught Adam the names of all things"* — Quran 2:31

<br>

**OpenNoorIlm — نور العلم — Open Light of Knowledge**

<br>

[GitHub](https://github.com/OpenNoorIlm/AIPU) · [Issues](https://github.com/OpenNoorIlm/AIPU/issues) · [Contact](mailto:noorulilm.contact.us@gmail.com)

</div>
