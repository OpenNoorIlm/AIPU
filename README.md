# AIPU — Open Source AI Processing Unit

An open-source systolic-array AI accelerator built from scratch in Verilog, running on a Tang Primer 20K FPGA.

[![License: CERN-OHL-S](https://img.shields.io/badge/Hardware-CERN--OHL--S--2.0-blue)](hardware/LICENSE)
[![License: GPL v3](https://img.shields.io/badge/Software-GPL--v3-green)](software/LICENSE)

---

## What It Is

AIPU is a hardware AI accelerator implementing a systolic array of MAC (Multiply-Accumulate) units. It performs matrix multiplication — the core operation behind neural network inference — entirely in hardware on an FPGA.

The design is fully open source under copyleft licenses: hardware under CERN-OHL-S v2, software under GPL-3.0.

---

## Architecture

```
┌─────────────────────────────────────────────┐
│                  top_fpga.v                 │
│                                             │
│  ┌──────────┐   ┌──────────┐               │
│  │dispatcher│──▶│ grid_GxG │ (GxG MACs)    │
│  └──────────┘   └────┬─────┘               │
│                      │                     │
│  ┌──────────┐   ┌────▼─────┐               │
│  │  uart_tx │◀──│result_   │               │
│  └────┬─────┘   │sender    │               │
│       │         └──────────┘               │
└───────┼─────────────────────────────────────┘
        │ M11 (TX)
        ▼
    ESP32 GPIO25 → USB → PC
```

**Key modules:**
- `mac.v` — Single INT8 multiply-accumulate unit
- `systolic_NxN.v` — NxN systolic array of MACs with weight-stationary dataflow
- `grid_GxG.v` — Grid of systolic arrays (G×G tiles)
- `chain_CxC.v` — Chain of C systolic arrays
- `dispatcher.v` — Task queue and control
- `memory_ctrl.v` — SRAM read/write controller
- `result_sender.v` — Reads results, serializes over UART
- `uart_tx.v` — 115200 baud UART transmitter
- `top_fpga.v` — Top-level with clock and IO constraints

---

## Hardware

| Component | Part | Notes |
|-----------|------|-------|
| FPGA | Tang Primer 20K (Gowin GW2A-18C) | 20K LUTs, 27MHz oscillator on H11 |
| USB-JTAG | FT232H breakout | Programs FPGA via openFPGALoader |
| Microcontroller | ESP32 DevKit | UART relay: FPGA → PC via USB |
| Connector | SH1.0 6-pin | Tang UART out on Pin 2 (FPGA ball M11) |

**Wiring:**
```
Tang SH1.0 Pin 1  →  GND
Tang SH1.0 Pin 2  →  ESP32 GPIO25   (FPGA TX → ESP32 RX)
ESP32 USB         →  PC /dev/ttyUSB0
FT232H USB        →  PC /dev/ttyUSB1 (JTAG)
```

---

## Toolchain

All open source, no proprietary tools required.

| Tool | Purpose |
|------|---------|
| [Yosys](https://github.com/YosysHQ/yosys) | Synthesis |
| [Synlig](https://github.com/chipsalliance/synlig) | SystemVerilog frontend |
| [nextpnr-himbaechel](https://github.com/YosysHQ/nextpnr) | Place & Route (Gowin) |
| [apicula/gowin_pack](https://github.com/YosysHQ/apicula) | Bitstream packing |
| [openFPGALoader](https://github.com/trabucayre/openFPGALoader) | FPGA flashing |
| [Verilator](https://www.veripool.org/verilator/) | RTL simulation |

---

## Quick Start

### Build and Flash

```bash
cd hardware/rtl

# Synthesize
yosys -p "read_verilog *.v; synth_gowin -top top_fpga -json top_fpga.json"

# Patch device string
python3 -c "
import re
with open('top_fpga.json') as f: t=f.read()
t=re.sub(r'GW2A-18C-ES','GW2A-18C',t)
with open('top_fpga_p.json','w') as f: f.write(t)
"

# Place & Route
nextpnr-himbaechel-gowin \
  --device GW2A-LV18PG256C8/I7 \
  --vopt family=GW2A-18C \
  --vopt cst=../uart/uart_top.cst \
  --json top_fpga_p.json \
  --write top_fpga_routed.json

# Pack bitstream
gowin_pack -d GW2A-18C -o top_fpga.fs top_fpga_routed.json

# Flash
openFPGALoader -c ft232 -b tangprimer20k top_fpga.fs
```

### Flash ESP32 Relay

Open `software/firmware/uart_relay.ino` in Arduino IDE with ESP32 board support installed. Flash to your ESP32 DevKit.

### Read AIPU Output

```bash
python3 -c "
import serial, time
ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)
ser.reset_input_buffer()
t = time.time()
while time.time() - t < 12:
    d = ser.read(64)
    if d: print(repr(d))
ser.close()
"
```

Expected output: `AIPU OK` on boot, then computation results.

---

## Status

| Milestone | Status |
|-----------|--------|
| MAC unit simulation | ✅ Done |
| Systolic array simulation | ✅ Done |
| Full RTL synthesis (Yosys+Synlig) | ✅ Done |
| Place & Route on GW2A-18C | ✅ Done — 167MHz max |
| FPGA flashing via FT232H | ✅ Done |
| UART TX confirmed on hardware | ✅ Done — "AIPU OK" received |
| Send tasks, read results | 🔄 In progress |
| Signed INT8 support | ⬜ Planned |
| FP8 support | ⬜ Planned |
| BF16 support | ⬜ Planned |
| Silicon tape-out (efabless MPW) | ⬜ Future |

---

## License

- **Hardware** (RTL, constraints, schematics): [CERN Open Hardware Licence v2 - Strongly Reciprocal](hardware/LICENSE)
- **Software** (firmware, scripts, tools): [GNU General Public License v3.0](software/LICENSE)

© 2024 OpenNoorIlm contributors
