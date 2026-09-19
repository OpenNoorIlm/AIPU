# Security Policy

## Scope

This project is an open-source AI Processing Unit (AIPU) implemented on an
FPGA (Gowin GW2A, Tang Primer 20K) with an ESP32 UART bridge. Security
concerns fall into three categories:

1. **Firmware / RTL vulnerabilities** — bugs in the Verilog/SystemVerilog
   that could cause unintended hardware behaviour.
2. **UART protocol vulnerabilities** — the ESP32 relay exposes a serial
   interface; malformed input must not hang or corrupt the FPGA state machine.
3. **Host toolchain vulnerabilities** — issues in synlig, nextpnr, or
   gowin_pack that could compromise the build machine.

## Supported Versions

| Component | Status |
|---|---|
| `hardware/rtl/*.v` | ✅ Actively maintained |
| `hardware/uart/uart_top.v` | ⚠️ Test only — not for production |
| ESP32 `uart_relay_bidir.ino` | ✅ Actively maintained |
| Toolchain (synlig / nextpnr) | ℹ️ Report upstream |

## Known Hardware Attack Surface

### UART RX (T13 pin, ESP32 GPIO26 → FPGA)
The FPGA's `uart_rx.v` receives bytes at 115200 8N1. Currently a single
`0xAB` byte triggers re-computation using whatever data is already in SRAM.
There is **no authentication**. Anyone with physical or serial access can:
- Trigger arbitrary re-computation
- (Future) overwrite SRAM weights via UART load protocol

**Mitigation planned:** command packet with magic header + length + checksum
before any SRAM write is accepted.

### SRAM contents
The Tang Primer 20K FPGA uses SRAM-based configuration — the bitstream and
all SRAM data are lost on power-off. There is no persistent secret storage.
This is a feature, not a bug: the device cannot leak weights across power cycles.

### ESP32 serial bridge
The ESP32 relay forwards all bytes bidirectionally between USB serial and
the FPGA UART. It performs no filtering. A host with access to `/dev/ttyUSB0`
has full read/write access to the FPGA communication channel.

**Mitigation:** restrict OS-level access to the tty device to trusted users
(`sudo usermod -aG dialout <user>`; do not expose the serial port over network).

### Voltage safety
- Do not connect 5 V signals to any FPGA IO pin — maximum is 3.3 V.
- Bank 0 (H11 clock pin) is a 1.8 V bank — CST must specify `LVCMOS18`.
- Violating IO voltage will permanently damage the GW2A device.

## Reporting a Vulnerability

To report a security issue:

1. **Do not open a public GitHub issue** for vulnerabilities that could
   enable hardware damage or data leakage.
2. Open a **private issue** (if the host platform supports it) or email
   the maintainer directly with subject line `[SECURITY] teacher-aipu`.
3. Include:
   - A clear description of the vulnerability
   - Steps to reproduce
   - Potential impact
   - Suggested fix if known
4. You will receive a response within 7 days.
5. If confirmed, a fix will be committed and you will be credited in the
   changelog unless you prefer anonymity.

## What We Will Never Do

- Store cryptographic keys or user credentials in SRAM or bitstream.
- Expose the FPGA UART bridge over a network interface without explicit
  authentication and encryption.
- Accept pull requests that remove input validation from the UART RX
  state machine once it is implemented.

## Responsible Disclosure

We follow a **90-day disclosure policy**: if a reported vulnerability is
not fixed within 90 days of being confirmed, the reporter is free to
disclose it publicly. We will always credit researchers who report issues
responsibly.
