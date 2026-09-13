# Contributing to AIPU

*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*

First of all — thank you for being here. This is an early-stage open hardware project
built by hand, from first principles, with the goal of producing the world's first
fully open-source, community-built AI accelerator chip. Every contribution matters,
whether it is a single-line bug fix, a new module, a testbench, a wiring diagram,
or just a question that forces us to write better documentation.

This document explains everything you need to know to contribute effectively —
technically, legally, and in terms of community culture.

---

## Table of Contents

- [Philosophy](#philosophy)
- [Code of Conduct](#code-of-conduct)
- [What We Need Most](#what-we-need-most)
- [Legal — Read This First](#legal--read-this-first)
  - [Licensing of Contributions](#licensing-of-contributions)
  - [Developer Certificate of Origin (DCO)](#developer-certificate-of-origin-dco)
  - [Copyright Assignment](#copyright-assignment)
  - [What You Can Use AIPU For](#what-you-can-use-aipu-for)
  - [Patent Grant](#patent-grant)
- [Before You Start](#before-you-start)
- [How to Contribute](#how-to-contribute)
  - [Reporting Bugs](#reporting-bugs)
  - [Requesting Features](#requesting-features)
  - [Submitting Code or Hardware](#submitting-code-or-hardware)
  - [Improving Documentation](#improving-documentation)
- [Development Environment](#development-environment)
- [Project Structure](#project-structure)
- [RTL Coding Standards](#rtl-coding-standards)
  - [Naming Conventions](#naming-conventions)
  - [Module Template](#module-template)
  - [Synthesis Rules](#synthesis-rules)
  - [Simulation Requirements](#simulation-requirements)
- [Firmware and Software Standards](#firmware-and-software-standards)
- [Git Workflow](#git-workflow)
  - [Branch Naming](#branch-naming)
  - [Commit Messages](#commit-messages)
  - [Pull Request Process](#pull-request-process)
  - [Review Criteria](#review-criteria)
- [Good First Issues](#good-first-issues)
- [Architecture Decisions — Do Not Change Without Discussion](#architecture-decisions--do-not-change-without-discussion)
- [Versioning](#versioning)
- [Contact](#contact)

---

## Philosophy

AIPU exists to prove that cutting-edge AI hardware does not have to be locked behind
proprietary tools, NDA-gated PDKs, and corporate secrecy. Every design decision is
made in the open. Every mistake is documented. Every debug session is a lesson.

When you contribute to AIPU, you are contributing to that proof. Your work may eventually
run in silicon. Please take it seriously.

**Core values:**

1. **Correctness before performance.** A wrong result at 167 MHz is worse than a correct
   result at 27 MHz. Simulation must pass before any hardware change is considered.

2. **Simplicity before cleverness.** This is not a place for unreadable Verilog tricks.
   A new contributor should be able to read any module and understand it within 10 minutes.

3. **Document everything.** Every module must have a header comment explaining what it does,
   what its parameters mean, and what its ports do. Every non-obvious line needs an inline
   comment. If you had to think for more than 5 minutes about something, document it so
   the next person does not have to.

4. **All tools must be free and open source.** No Vivado. No Quartus. No Gowin IDE.
   No EDA tool that requires a license or an NDA. Every build step must be reproducible
   on a fresh Ubuntu install with only `apt`, `pip`, and a handful of open-source tools.

5. **The architecture is parameterized by design.** Do not hardcode values that should
   be parameters. Do not break parameterization when adding new features. The same RTL
   must work at `G=C=N=2` (32 MACs, FPGA) and at `G=16, C=8, N=32` (2M MACs, silicon).

---

## Code of Conduct

This project follows a simple rule: **treat every contributor with the respect you would
want in a professional setting.** That means:

- Assume good faith. Someone asking a basic question is learning, not wasting your time.
- Critique the work, not the person.
- If you disagree with a design decision, say why — with technical reasoning, not frustration.
- No harassment, discrimination, or personal attacks of any kind.
- Contributions are judged on correctness, clarity, and alignment with the project — not
  on who wrote them.

Violations can result in removal from the project. Decisions on this rest with the
project maintainer (OpenNoorIlm).

---

## What We Need Most

The following are the highest-priority contributions as of the current state of the project.
They are listed roughly in order of importance:

### Immediate (unblocks the next milestone)

| Area | What | Skill needed |
|------|------|-------------|
| **UART RX integration** | Bring `hardware/uart/uart_rx.v` into `hardware/rtl/top.v`. Add a simple task protocol: host sends a packet over serial, FPGA parses it, dispatches to grid. | SystemVerilog, UART protocol |
| **Dispatcher protocol** | Define and implement the wire format for task descriptors sent over UART RX. What bytes mean what. Document it. | Protocol design, Verilog |
| **Result format** | `result_sender.v` currently sends raw SRAM bytes. Define a meaningful output packet format (task ID, result bytes, checksum). | Verilog, protocol design |

### Near-term (precision roadmap)

| Area | What | Skill needed |
|------|------|-------------|
| **Signed INT8** | Add `$signed()` wrappers to `mac.v`. Update testbench to test negative values. | Verilog, fixed-point arithmetic |
| **FP8 (E4M3)** | Write `fp8_mul.v` — FP8 multiplier, ~150 lines. Add to MAC as precision mode 2'b01. | Verilog, floating-point arithmetic |
| **BF16** | Write `bf16_mul.v` with IEEE 754 rounding. ~500 lines. | Verilog, floating-point, IEEE 754 |

### Always welcome

| Area | What |
|------|------|
| **Testbench coverage** | More corner cases in `top_tb.v`. Test queue overflow, back-to-back tasks, reset behaviour. |
| **Simulation scripts** | Automate the Verilator compile + run + check output in a single script. |
| **Documentation** | Diagrams, timing diagrams, block diagrams, waveform annotations. |
| **Build system** | Improve `do.sh` — add error checking, timestamps, optional `--flash` flag. |
| **CI** | GitHub Actions workflow to run Verilator simulation on every push and PR. |
| **Larger FPGA port** | Port `top.v` with `G=2, C=2, N=8` (512 MACs) to a larger FPGA. Document the process. |

---

## Legal — Read This First

This section covers the legal terms under which you contribute to AIPU.
**It is important. Please read it fully before submitting anything.**

### Licensing of Contributions

All contributions to this repository are subject to the same licenses as the repository itself:

- **Hardware contributions** (RTL `.v` files, constraint `.cst` files, schematics, layout) →
  Licensed under **CERN Open Hardware Licence Version 2 — Strongly Reciprocal (CERN-OHL-S v2)**
  See `hardware/LICENSE` for the full text.

- **Software contributions** (firmware `.ino`, Python scripts, host tools, CI scripts) →
  Licensed under **GNU General Public License Version 3 (GPL-3.0)**
  See `software/LICENSE` for the full text.

- **Documentation** (Markdown files, diagrams, comments) →
  Licensed under **Creative Commons Attribution-ShareAlike 4.0 (CC BY-SA 4.0)**
  This includes `README.md`, `CONTRIBUTING.md`, and any `.md` files you add.

By submitting a pull request, you agree that your contribution is made available under
these licenses and that you have the legal right to make it so (i.e., it is your own
original work, or you have permission from the original author).

**Do not submit code, schematics, or any other material that is:**
- Copied from a proprietary or closed-source project
- Subject to an NDA
- Derived from IP cores that are not openly licensed
- Licensed in a way incompatible with CERN-OHL-S v2 or GPL-3.0

If you are unsure about the licensing status of something you want to contribute,
open an issue and ask before submitting. It is always better to ask first.

### Developer Certificate of Origin (DCO)

AIPU uses the **Developer Certificate of Origin (DCO) v1.1** as the mechanism for
contributors to certify that they have the right to submit their contributions.

This means **every commit** you submit must include a `Signed-off-by` line:

```
Signed-off-by: Your Name <your.email@example.com>
```

You add this by using `git commit -s` (the `-s` flag), or by manually adding the line
to the end of your commit message.

By adding this line, you certify the following (paraphrased from the
[full DCO text](https://developercertificate.org/)):

> I wrote this code myself, or I have the right to submit it under the open-source
> license used by this project. I understand that this contribution and my name and
> email will be permanently associated with it in the version history.

The full DCO text is at [developercertificate.org](https://developercertificate.org/). In short: you certify you wrote it yourself or have the right to submit it under this project's licenses, and you understand the contribution and your sign-off are permanently public in the git history.

### Copyright Assignment

AIPU does **not** require copyright assignment. You retain copyright over your own
contributions. You are simply licensing them to the project and its users under
CERN-OHL-S v2 (hardware) or GPL-3.0 (software) as described above.

Your name will appear in the git history permanently and is part of the project record.

### What You Can Use AIPU For

Under the open-source licenses:

**You CAN:**
- Use, study, and modify the RTL and firmware for any purpose, including commercial
- Build hardware based on this design and sell it, **provided you release your modified
  sources under CERN-OHL-S v2** and mark the hardware with the source location
- Use the software in your own projects, **provided your project is also GPL-3.0**
- Fork this repository and make your own version (as long as you comply with the license)
- Reference this project in academic work, citing the repository

**You CANNOT (under the open licenses):**
- Integrate the RTL into a proprietary chip design without releasing your sources
- Use the firmware in a closed-source product without releasing your source code
- Remove the copyright notices or license headers from any file
- Claim that your proprietary product is "based on AIPU" without complying with the license

**If you need to do any of the "CANNOT" things:**
Contact us at [noorulilm.contact.us@gmail.com](mailto:noorulilm.contact.us@gmail.com)
to discuss a commercial/custom license. See the [Contact](#contact) section.

### Patent Grant

By contributing hardware designs or algorithms to AIPU, you grant a royalty-free,
non-exclusive, worldwide patent license to any patents you hold that are necessarily
infringed by your contribution, for the purpose of implementing, using, and distributing
the contribution as part of AIPU under its open-source licenses.

This is consistent with what CERN-OHL-S v2 requires and what the GPL-3.0 includes
by reference. If you are unsure whether your contribution involves patented technology
you hold, please raise this before submitting.

---

## Before You Start

Before writing a single line of code or RTL, please do the following:

1. **Read the README.md fully.** Especially the Architecture, Hardware, and Toolchain sections.
   Many questions are answered there.

2. **Read the relevant source files.** If you want to change `mac.v`, read it first.
   If you want to add something to `top.v`, understand what is already there.

3. **Get the toolchain working** on your machine. Run the full build pipeline.
   Flash the FPGA. Receive `AIPU OK` on your terminal. Verify simulation passes.
   If you cannot build and flash, you cannot meaningfully test your contribution.

4. **Open an issue first** (for anything non-trivial). Describe what you want to do
   and why. Wait for a response before spending significant time. This avoids:
   - Duplicate work (someone else is already doing it)
   - Wasted effort (the approach doesn't fit the architecture)
   - Merge conflicts (you changed something that was being changed elsewhere)

5. **Check open issues and pull requests.** Maybe what you want already exists, or
   is already in progress.

---

## How to Contribute

### Reporting Bugs

Open a [GitHub Issue](https://github.com/OpenNoorIlm/AIPU/issues) with:

- **Title:** Short, specific. E.g. `uart_tx.v: busy stays high after STOP bit at 9600 baud`
  not `UART broken`.

- **Category (label):** Use `bug`, `hardware`, `simulation`, `toolchain`, or `documentation`
  as appropriate.

- **Environment:**
  ```
  OS: Ubuntu 24.04
  Yosys version: 0.52
  Synlig version: (from ./synlig/synlig --version)
  nextpnr version: (from nextpnr-himbaechel-gowin --version)
  FPGA board: Tang Primer 20K bare board
  ```

- **Steps to reproduce:** Exact commands, in order. If it's a simulation bug, include
  the exact `verilator` command. If it's a hardware bug, include the flash command
  and the listen command.

- **Expected behaviour:** What should have happened.

- **Actual behaviour:** What actually happened. Include full terminal output — do not
  paraphrase. Paste the raw output.

- **What you already tried:** This saves everyone time.

### Requesting Features

Open an issue with the label `enhancement`. Include:

- What you want to add and why
- How it fits the architecture (specifically: does it break parameterization?)
- Whether you intend to implement it yourself or are asking someone else to
- Any references (papers, prior art, other open-source implementations) that are relevant

### Submitting Code or Hardware

The full process is described in [Git Workflow](#git-workflow) below. Summary:

1. Fork the repository
2. Create a branch: `git checkout -b feature/signed-int8-mac`
3. Make your changes following the standards in this document
4. Ensure simulation passes: `verilator --sv --binary --trace ... && ./obj_dir/sim_top`
5. Ensure synthesis succeeds: `./synlig/synlig -p "... synth_gowin ..."`
6. Commit with DCO sign-off: `git commit -s -m "mac.v: add signed INT8 support"`
7. Push and open a pull request against `main`

### Improving Documentation

Documentation contributions are just as valuable as RTL contributions. They follow the
same process (fork → branch → PR) but do not require synthesis or simulation to pass.

Good documentation contributions:
- Fix factual errors (wrong pin numbers, wrong baud rate, etc.)
- Add missing context that would have helped you when you started
- Add timing diagrams, waveform screenshots, or architecture diagrams
- Translate documentation (open an issue first to coordinate)
- Improve the clarity of any existing explanation

---

## Development Environment

### Required Tools

```bash
# Ubuntu / Debian — install all required tools:
sudo apt update
sudo apt install yosys verilator gtkwave git python3 python3-pip openfpgaloader

# Python dependencies (for debug scripts and flash tools):
pip install pyserial apycula

# Synlig (SystemVerilog frontend) — download binary release:
# https://github.com/chipsalliance/synlig/releases
# Extract to hardware/rtl/synlig/ so that hardware/rtl/synlig/synlig exists

# nextpnr-himbaechel-gowin — build from source:
# https://github.com/YosysHQ/nextpnr#building-nextpnr-himbaechel
# Ensure chipdb for Gowin GW2A is included in the build

# Arduino IDE (for ESP32 firmware):
# https://www.arduino.cc/en/software
# Board support: ESP32 by Espressif (install via Board Manager)
```

### udev rules (Linux — required for non-root FPGA access)

```bash
# FT232H (JTAG programmer):
echo 'SUBSYSTEM=="usb", ATTR{idVendor}=="0403", ATTR{idProduct}=="6014", MODE="666", GROUP="plugdev"' \
  | sudo tee /etc/udev/rules.d/99-ft232h.rules

# ESP32 CP2102 (UART relay):
echo 'SUBSYSTEM=="usb", ATTR{idVendor}=="10c4", ATTR{idProduct}=="ea60", MODE="666", GROUP="plugdev"' \
  | sudo tee /etc/udev/rules.d/99-cp2102.rules

sudo udevadm control --reload-rules && sudo udevadm trigger
sudo usermod -aG plugdev $USER   # log out and back in after this
```

### Verify your environment

```bash
# Check all tools are available and working:
yosys --version           # should print Yosys 0.52 or newer
verilator --version       # should print Verilator 5.x
nextpnr-himbaechel-gowin --version
gowin_pack --help | head -3
openFPGALoader --version

# Check hardware is detected:
openFPGALoader -c ft232 --detect
# Expected: idcode 0x81b, manufacturer Gowin, family GW2A, model GW2A(R)-18(C)

# Run simulation:
cd hardware/rtl
verilator --sv --binary --trace -o obj_dir/sim_top \
  top_tb.v mac.v systolic_NxN.v chain_CxC.v grid_GxG.v \
  dispatcher.v memory_ctrl.v uart_tx.v result_sender.v top.v
./obj_dir/sim_top
# Expected: no errors, no warnings, task accepted messages printed
```

---

## Project Structure

```
hardware/rtl/     ← All main AIPU RTL lives here. This is where most work happens.
hardware/uart/    ← Standalone UART test designs. Used for isolated UART debugging.
hardware/tb/      ← Early standalone testbenches. top_tb.v is in rtl/, not here.
software/firmware/ ← ESP32 firmware only. Any host-side tools go here too.
```

**Key rule:** Do not put synthesis artifacts, bitstreams, or simulation outputs into git.
The `.gitignore` excludes them. If you find yourself trying to `git add` a `.fs`, `.json`
(synthesis output), or `.vcd` file — stop. These are generated files and must not be tracked.

---

## RTL Coding Standards

All SystemVerilog/Verilog in `hardware/` must follow these standards.
Pull requests that do not follow them will not be merged until they do.

### Naming Conventions

| Thing | Convention | Example |
|-------|-----------|---------|
| Module name | `snake_case`, matches filename | `mac`, `uart_tx`, `systolic_NxN` |
| Parameters | `UPPER_SNAKE_CASE` | `CLK_FREQ`, `BAUD_RATE`, `N` |
| Ports | `snake_case` | `clk`, `reset`, `uart_tx_pin`, `task_valid` |
| Internal registers | `snake_case`, descriptive | `bit_cnt`, `clk_per_bit`, `state` |
| State machine states | `S_` prefix + `UPPER_SNAKE_CASE` | `S_IDLE`, `S_START_BIT`, `S_DATA` |
| Active-low signals | `_n` suffix | `reset_n` (but prefer active-high reset) |
| Clock | Always named `clk` | `input clk` |
| Reset | Always named `reset` | `input reset` (synchronous, active-high preferred) |
| Localparams | `UPPER_SNAKE_CASE` | `localparam CLK_PER_BIT = CLK_FREQ / BAUD_RATE` |
| Generate variable | `gi`, `gj`, `gk` | `for (gi = 0; gi < G; gi++)` |

### Module Template

Every new module must follow this template:

```verilog
// ============================================================================
// Module: <module_name>
// File:   hardware/rtl/<filename>.v
//
// Description:
//   <One paragraph. What does this module do? What problem does it solve?>
//   <What are the key signals to watch? What are the timing assumptions?>
//
// Parameters:
//   <PARAM_NAME>  — <what it controls, units, valid range>
//
// Ports:
//   clk           — system clock
//   reset         — synchronous active-high reset
//   <port_name>   — <direction, width, what it represents>
//
// Notes:
//   <Any non-obvious design decisions. Why was it done this way?>
//   <Known limitations. What this module does NOT handle.>
//
// Copyright (C) 2025 OpenNoorIlm contributors
// SPDX-License-Identifier: CERN-OHL-S-2.0   (for hardware/rtl/)
//              or GPL-3.0-or-later            (for software/)
// ============================================================================

module <module_name> #(
    parameter DATA_WIDTH = 8,        // <what this controls>
    parameter CLK_FREQ   = 27_000_000
) (
    input  wire                  clk,
    input  wire                  reset,
    input  wire [DATA_WIDTH-1:0] data_in,
    output reg  [DATA_WIDTH-1:0] data_out
);

    // ── Local parameters ─────────────────────────────────────────────────────
    localparam SOME_DERIVED = CLK_FREQ / 1000;  // <what this means>

    // ── Internal signals ──────────────────────────────────────────────────────
    reg [7:0] state;
    reg [7:0] counter;

    // ── State machine ─────────────────────────────────────────────────────────
    localparam S_IDLE = 2'd0;
    localparam S_WORK = 2'd1;
    localparam S_DONE = 2'd2;

    always @(posedge clk) begin
        if (reset) begin
            state    <= S_IDLE;
            counter  <= 0;
            data_out <= 0;
        end else begin
            case (state)
                S_IDLE: begin
                    // ...
                end
                S_WORK: begin
                    // ...
                end
                default: state <= S_IDLE;  // always have a default
            endcase
        end
    end

endmodule
```

### Synthesis Rules

These rules exist because violations have caused real bugs in this project:

1. **No latches.** Every `always` block must have a complete `if/else` or `case/default`
   so that every register has a defined value on every path. Latches are inferred when
   you forget an `else` or a `default`. They synthesize unpredictably on Gowin.

2. **All `case` statements must have `default`.** Even if you believe all cases are covered.
   The synthesizer will thank you and the linter will not complain.

3. **Reset every register.** Every `reg` must be assigned in the `if (reset)` block.
   Uninitialized registers in simulation start at `X` (unknown) and can mask bugs.

4. **Do not use `#delay` in synthesizable code.** `#10` and similar delays are for
   testbenches only. They are ignored by synthesis and produce misleading simulation.

5. **No `initial` blocks in synthesizable modules.** Gowin FPGA does not support
   `initial` blocks for register initialization in all contexts. Use reset logic instead.
   Exception: `initial` is fine in testbenches.

6. **Parameterize, do not hardcode.** If a value might ever need to change for a different
   scale or clock frequency, make it a parameter or derive it with `localparam`.
   Examples: `CLK_PER_BIT = CLK_FREQ / BAUD_RATE`, `BOOT_DELAY = CLK_FREQ` (1 second at any clock).

7. **Do not use `$signed()` without thought.** INT8 sign extension into a wider accumulator
   requires explicit handling. The current codebase uses unsigned arithmetic. If you are
   adding signed support, document exactly how sign extension works in your module header.

8. **Packed array port syntax must be SystemVerilog.**
   `input [7:0] a_in[0:N-1]` is SystemVerilog, not Verilog-2001. This requires Synlig.
   If you write a module with packed array ports, note it in the header comment.

9. **IO standard in CST must match IO bank voltage.**
   `H11` (clock, IO bank 0) → `LVCMOS18`. `M11` (TX, IO bank ?) → `LVCMOS33`.
   Always verify a new pin's IO bank before assigning an IO standard.

### Simulation Requirements

Every new module must come with a testbench or updates to `top_tb.v`.

Requirements for testbenches:
- Must simulate with `verilator --sv --binary --trace` with **zero errors** and **zero warnings**
- Must test the happy path (normal operation)
- Must test reset behaviour (assert reset, verify all outputs go to defined state)
- Must test at least one edge case (queue full, byte boundary, zero input, etc.)
- Must print a clear `PASS` or `FAIL` message at the end of simulation
- Must write a VCD file for waveform inspection (`$dumpfile` / `$dumpvars`)

Example testbench structure:

```verilog
// top of testbench:
integer errors = 0;

// at end of testbench:
initial begin
    #(SIM_DURATION);
    if (errors == 0)
        $display("PASS — all checks passed");
    else
        $display("FAIL — %0d errors", errors);
    $finish;
end

// in checks:
if (actual !== expected) begin
    $display("ERROR at t=%0t: expected %0h got %0h", $time, expected, actual);
    errors = errors + 1;
end
```

---

## Firmware and Software Standards

Applies to `software/` and any Python/shell scripts in `hardware/`.

### Arduino / C++ (ESP32 firmware)

- All sketches must include a header comment: author, date, purpose, pin assignments
- Pin numbers must be named constants, not bare numbers: `const int TANG_RX_PIN = 25;`
- `Serial.begin(115200)` must be called before any other Serial usage
- Every sketch must print a human-readable boot banner over Serial when setup completes
- Do not use `delay()` for anything longer than 100ms in the main loop
- Do not use blocking waits in `loop()` — use non-blocking state machines
- The ESP32 sketch must never interfere with FPGA flashing (do not tie up shared GPIO)

### Python

- Python 3.10+ only
- Use `argparse` for any script that takes command-line arguments
- Use `pyserial` for serial port access — do not shell out to `cat /dev/ttyUSB0`
- Every script must handle `KeyboardInterrupt` gracefully (close serial port before exiting)
- Include a `if __name__ == "__main__":` guard

### Shell Scripts

- Start every script with `#!/bin/bash` and `set -euo pipefail`
- Every script must print usage if called with `--help` or wrong arguments
- Every build step must check its output exists before proceeding to the next step
- Print clear status messages: `echo "[1/5] Synthesizing..."`, `echo "[1/5] DONE"`

---

## Git Workflow

### Branch Naming

```
feature/<short-description>     ← new functionality
fix/<short-description>         ← bug fix
docs/<short-description>        ← documentation only
refactor/<short-description>    ← code restructure, no functional change
test/<short-description>        ← testbench additions or fixes
hw/<short-description>          ← hardware-specific (CST, top_fpga.v, wiring)
```

Examples:
```
feature/signed-int8-mac
feature/uart-rx-integration
fix/result-sender-busy-signal
docs/sh10-wiring-diagram
test/dispatcher-queue-overflow
hw/nextpnr-cst-m11-pull-none
```

### Commit Messages

Follow the [Conventional Commits](https://www.conventionalcommits.org/) format:

```
<type>(<scope>): <short summary in imperative mood>

<body — what changed and why, not what the diff shows>

<footer — DCO sign-off and any issue references>
Signed-off-by: Your Name <your.email@example.com>
Fixes #42
```

**Types:**
- `feat` — new feature or module
- `fix` — bug fix
- `docs` — documentation only
- `refactor` — restructure without changing behaviour
- `test` — testbench additions or changes
- `build` — build system, scripts, toolchain
- `hw` — hardware-only (CST, pinout, board-level changes)
- `chore` — maintenance (cleanup, rename, reorg)

**Scopes** (optional but helpful): `mac`, `uart-tx`, `uart-rx`, `dispatcher`,
`result-sender`, `top-fpga`, `esp32`, `toolchain`, `docs`, `ci`

**Examples:**

```
feat(mac): add signed INT8 support via $signed() wrappers

Previously, the MAC unit performed unsigned INT8 × INT8 multiplication.
This adds signed support using $signed() on both inputs and extends the
accumulator sign correctly into the full 32-bit result.

Testbench updated: negative × negative, negative × positive, and
overflow cases all pass. Zero errors in Verilator.

Signed-off-by: Your Name <you@example.com>
```

```
fix(uart-tx): prevent busy from staying high after STOP bit

The state machine transitioned from S_STOP to S_IDLE but did not
de-assert busy in the same clock cycle. This caused the downstream
result_sender to skip sending the first byte of every packet.

Simulation testbench added to verify busy goes low on the cycle
after STOP bit completes.

Signed-off-by: Your Name <you@example.com>
Fixes #17
```

```
docs(sh10-pinout): correct Pin 3 description — RX not TX

Pin 3 was incorrectly described as TX in the README table.
It is the FPGA RX input (currently unconnected).

Signed-off-by: Your Name <you@example.com>
```

### Pull Request Process

1. **Open an issue first** for anything that takes more than ~30 minutes to implement.
   PRs without a linked issue may be asked to pause while the approach is discussed.

2. **One concern per PR.** Do not mix a feature with a refactor with a docs update in the
   same PR. Small, focused PRs get reviewed faster and are easier to merge or revert.

3. **Fill out the PR template** (when it exists). Until then, include in the description:
   - What this PR does and why
   - What was tested (simulation? hardware? both?)
   - Any known limitations or follow-up work needed
   - Link to the issue it addresses (`Fixes #N`)

4. **Simulation must pass.** Include the full terminal output of your Verilator run
   in the PR description or as a comment. Zero errors, zero warnings.

5. **Synthesis must succeed** for any RTL change. Include the `stat` output from Synlig
   showing the cell count. If resource usage increased significantly, explain why.

6. **Do not force-push to `main`.** Force-push is only allowed on your own feature branch
   to clean up commits before the PR is merged.

7. **Respond to review comments promptly.** If a review asks for changes, address them
   or explain why you disagree. Do not let PRs go stale.

### Review Criteria

A PR will be reviewed against these criteria before merging:

| Check | What the reviewer looks for |
|-------|---------------------------|
| **Correctness** | Does it do what it says? Does simulation pass? |
| **Parameterization** | Does it work at G=C=N=2 AND G=16,C=8,N=32? Are magic numbers eliminated? |
| **Style** | Naming conventions, header comment, module template followed? |
| **Synthesis** | Does `./synlig/synlig` complete without errors? What is the cell count? |
| **Reset** | Is every register reset in the `if (reset)` block? |
| **Latches** | Are there any inferred latches? (check Synlig warnings) |
| **Testbench** | Is there a testbench? Does it print PASS? Does it test edge cases? |
| **DCO** | Is every commit signed off with `Signed-off-by:`? |
| **License header** | Does every new file have the SPDX license identifier comment? |
| **Documentation** | Is every non-obvious decision explained in a comment? |

---

## Good First Issues

If you are new to the project and looking for a place to start, these are good options:

### Very Easy (documentation / tooling)

- Add `--help` output to `hardware/uart/debug_uart.py`
- Add PASS/FAIL print to `hardware/tb/mac_tb.v` testbench
- Fix any typo or unclear sentence in `README.md`
- Add a `Makefile` target that runs the full Verilator simulation in one command

### Easy (RTL / firmware)

- Add a `$dumpvars` block to `hardware/rtl/top_tb.v` to enable full VCD tracing
- Add an `errors` counter and PASS/FAIL message to `hardware/rtl/top_tb.v`
- Add `set -euo pipefail` and error checking to `hardware/rtl/do.sh`
- Add a boot banner print to `hardware/uart/debug_uart.py`

### Medium (RTL)

- Signed INT8 support in `mac.v` — update `top_tb.v` to test negative values
- Integrate `uart_rx.v` into `top.v` — connect it to the clock, add the port to `top_fpga.v`
- Define a simple task wire protocol (open issue to discuss format first)

### Harder (RTL / architecture)

- FP8 multiplier `fp8_mul.v` (E4M3 format) — simulation testbench required
- GitHub Actions CI that runs Verilator simulation on every push
- Port to a larger FPGA with G=2, C=2, N=8

Open an [issue](https://github.com/OpenNoorIlm/AIPU/issues) before starting any
medium or harder task, so we can confirm the approach and avoid conflicts.

---

## Architecture Decisions — Do Not Change Without Discussion

The following are **locked design decisions**. Do not submit a PR that changes these
without opening an issue first and getting explicit sign-off from the project maintainer.
Changes here affect the entire architecture and must be considered carefully.

| Decision | Why it is locked |
|----------|-----------------|
| **Systolic array, weight-stationary dataflow** | Core architectural choice. Changing this changes everything. Discuss on an issue before any alternative is proposed. |
| **Three parameters: G, C, N** | Changing the parameterization model breaks backward compatibility and all documented scale targets. |
| **CLK_FREQ = 27_000_000 for Tang** | Matches the onboard Tang crystal. Never hardcode a different value without a new parameter. |
| **BAUD_RATE = 115_200** | Matched to the ESP32 relay sketch. Both sides must match. Change requires coordinated update. |
| **H11 = LVCMOS18** | IO bank 0 is 1.8V VCCIO. This is a board-level hardware fact, not a preference. |
| **M11 = LVCMOS33, PULL_MODE=NONE** | Required for correct UART TX behaviour. See README Hardware Gotchas #5 and #6. |
| **All tools must be open source** | No exceptions. If a proposed change requires a proprietary tool to reproduce, it will not be merged. |
| **No IP cores** | No Gowin IP, no third-party encrypted cores, no vendor-specific primitives except where absolutely required (e.g. Gowin BSRAM) and fully documented. |

---

## Versioning

AIPU follows [Semantic Versioning](https://semver.org/) for hardware and software releases:

```
v<MAJOR>.<MINOR>.<PATCH>

MAJOR — breaking change to the task protocol, wire format, or parameter interface
MINOR — new feature (new precision tier, new module, extended protocol)
PATCH — bug fix, documentation update, tooling improvement
```

The current version is **v0.1.0** (pre-release: architecture proven on hardware,
task dispatch not yet implemented).

Version tags are applied to `main` by the project maintainer after review.
Do not create version tags on feature branches.

---

## Contact

For contribution questions, architecture discussions, and general project talk:
→ [GitHub Issues](https://github.com/OpenNoorIlm/AIPU/issues)

For commercial licensing, partnership, investment, or anything that should not be public:
→ [noorulilm.contact.us@gmail.com](mailto:noorulilm.contact.us@gmail.com)

> **Custom license applications — how they are handled:**
> By emailing us to apply for a custom or commercial license, you agree that your email
> may be opened as a GitHub issue for discussion among contributors if there are active
> contributors on the project at the time of your enquiry. If there are no active
> contributors at the time, your email will be handled privately and will not be opened
> as a public issue. We will always inform you of how your enquiry is being handled.
>
> **Why we do this:** AIPU is built by contributors who give their time, skill, and effort
> freely under copyleft licenses. When someone seeks to use that work under a custom or
> commercial license — outside the terms those contributors agreed to — it is only right
> that the people whose work is involved have a voice in that decision. Opening the
> enquiry as a GitHub issue gives active contributors full visibility and the opportunity
> to participate in the discussion. We do this out of respect for every contributor's
> contribution.

For security vulnerabilities (do not post publicly):
→ [noorulilm.contact.us@gmail.com](mailto:noorulilm.contact.us@gmail.com)
  Subject line: `[SECURITY] <brief description>`

---

<div align="center">

*"وَفَوْقَ كُلِّ ذِي عِلْمٍ عَلِيمٌ"*

*"And above every possessor of knowledge is one more knowing"* — Quran 12:76

**OpenNoorIlm — نور العلم — Open Light of Knowledge**

[GitHub](https://github.com/OpenNoorIlm/AIPU) ·
[Issues](https://github.com/OpenNoorIlm/AIPU/issues) ·
[Contact](mailto:noorulilm.contact.us@gmail.com)

</div>
