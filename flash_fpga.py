#!/usr/bin/env python3
"""
flash_fpga.py — Flash Tang Primer 20K via ESP32 JTAG bitbang
Supports: --flash (default), --idcode, --watch (auto-reflash on .fs change)
WiFi monitor: just open http://<esp32-ip>/ in any browser — no Python needed.

GW2A-18C: IR length = 8 bits
ESP32 pins: TCK=14, TDI=13, TDO=4, TMS=15, Tang TX→GPIO17
"""

import serial, time, sys, os, argparse

SERIAL_PORT = "/dev/ttyUSB0"
BAUD        = 115200
BITSTREAM   = "top_fpga.fs"
BULK_SIZE   = 255

IDCODE_MASK     = 0xFFFFFFFF
IDCODE_EXPECTED = 0x0000081B

IR_IDCODE        = 0x06
IR_CFG_ENABLE    = 0x15
IR_ERASE_SRAM    = 0x05
IR_INIT_ADDR     = 0x12
IR_PROG_SRAM     = 0x17
IR_PROG_INACTIVE = 0x3A

ser = None

# ── Serial ────────────────────────────────────────────────────────────────────

def open_serial():
    global ser
    ser = serial.Serial(SERIAL_PORT, BAUD, timeout=2)
    time.sleep(0.3)
    ser.reset_input_buffer()
    ser.reset_output_buffer()
    print(f"Serial ready ({SERIAL_PORT})")

# ── Low-level JTAG ────────────────────────────────────────────────────────────

def _c(tck, tms, tdi):
    return bytes([ord('0') + ((tck & 1) << 2) | ((tms & 1) << 1) | (tdi & 1)])

def clock(tms, tdi):
    ser.write(_c(0, tms, tdi))
    ser.write(_c(1, tms, tdi))

def clock_r(tms, tdi) -> int:
    ser.write(_c(0, tms, tdi))
    ser.write(_c(1, tms, tdi))
    ser.write(b'R')
    ser.flush()
    deadline = time.time() + 0.5
    while time.time() < deadline:
        b = ser.read(1)
        if b in (b'0', b'1'):
            return b[0] - ord('0')
    return 0

def tap_reset():
    for _ in range(6):
        clock(1, 0)
    ser.flush()
    time.sleep(0.05)

def tap_idle():
    clock(0, 0)
    ser.flush()

def shift_ir(ir, nbits=8):
    clock(1, 0); clock(1, 0)   # → Select-DR, Select-IR
    clock(0, 0); clock(0, 0)   # → Capture-IR, Shift-IR
    for i in range(nbits):
        clock(1 if i == nbits - 1 else 0, (ir >> i) & 1)
    clock(1, 0); clock(0, 0)   # → Update-IR, Idle
    ser.flush()

def read_dr(nbits) -> int:
    clock(1, 0); clock(0, 0); clock(0, 0)   # → Shift-DR
    val = 0
    for i in range(nbits):
        val |= clock_r(1 if i == nbits - 1 else 0, 0) << i
    clock(1, 0); clock(0, 0)   # → Update-DR, Idle
    ser.flush()
    return val

def write_dr(data, nbits):
    clock(1, 0); clock(0, 0); clock(0, 0)
    for i in range(nbits):
        clock(1 if i == nbits - 1 else 0, (data >> i) & 1)
    clock(1, 0); clock(0, 0)
    ser.flush()

# ── Bulk bitstream ────────────────────────────────────────────────────────────

def bulk_stream(data: bytes):
    total, offset = len(data), 0
    t0 = time.time()
    while offset < total:
        chunk = data[offset:offset + BULK_SIZE]
        n = len(chunk)
        ser.write(b'W' + bytes([n]) + chunk)
        ser.flush()
        ack = ser.read(1)
        if ack != b'K':
            print(f"\n[WARN] offset={offset} no ACK, got {ack!r}")
        offset += n
        elapsed = time.time() - t0
        rate = offset / elapsed / 1024 if elapsed > 0 else 0
        print(f"\r  {offset}/{total}  ({offset * 100 // total}%)  {rate:.1f} KB/s", end='', flush=True)
    print()

# ── IDCODE ────────────────────────────────────────────────────────────────────

def check_idcode():
    tap_reset()
    tap_idle()
    idcode = read_dr(32)
    print(f"IDCODE: 0x{idcode:08X}")
    masked = idcode & IDCODE_MASK
    if masked == IDCODE_EXPECTED:
        print("✅ GW2A-18C detected")
        return True
    elif idcode in (0x00000000, 0xFFFFFFFF):
        print("❌ No response — check wiring:")
        print("   TCK→GPIO14  TDI→GPIO13  TDO→GPIO4  TMS→GPIO15  GND→GND  3.3V→3.3V")
        return False
    elif (idcode & 0x0FFF) == 0x01B:
        print("⚠️  Gowin chip (manufacturer match) — continuing")
        return True
    else:
        print("⚠️  Unknown IDCODE — attempting flash anyway")
        return True

# ── Flash ─────────────────────────────────────────────────────────────────────

def flash(path):
    if not os.path.exists(path):
        print(f"ERROR: {path} not found — run from ~/teacher-aipu/rtl/")
        sys.exit(1)

    data = open(path, 'rb').read()
    print(f"Bitstream: {len(data):,} bytes  ({path})")

    tap_reset(); tap_idle()

    print("Enabling config...")
    shift_ir(IR_CFG_ENABLE)
    write_dr(0x00, 8)

    print("Erasing SRAM...")
    shift_ir(IR_ERASE_SRAM)
    write_dr(0x00010000, 32)
    time.sleep(0.1)

    print("Init address...")
    shift_ir(IR_INIT_ADDR)
    write_dr(0x00, 8)

    print("Programming SRAM...")
    shift_ir(IR_PROG_SRAM)

    clock(1, 0); clock(0, 0); clock(0, 0)  # → Shift-DR
    ser.flush()

    bulk_stream(data)

    clock(1, 0); clock(1, 0); clock(0, 0)  # → Exit1-DR, Update-DR, Idle
    ser.flush()

    print("Deactivating config...")
    shift_ir(IR_PROG_INACTIVE)
    write_dr(0x00, 8)
    time.sleep(0.01)

    print("✅ Flash complete — AIPU running!")

# ── Auto-reflash loop ─────────────────────────────────────────────────────────

def watch_and_reflash(path: str):
    """Watch bitstream file for changes and re-flash automatically."""
    mtime = os.path.getmtime(path)
    print(f"Watching {path} for changes (Ctrl+C to stop)...")
    while True:
        time.sleep(1)
        try:
            new_mtime = os.path.getmtime(path)
        except FileNotFoundError:
            continue
        if new_mtime != mtime:
            mtime = new_mtime
            print(f"\n[watch] {path} changed — reflashing...")
            time.sleep(0.2)   # let file finish writing
            ser.reset_input_buffer()
            ser.reset_output_buffer()
            if check_idcode():
                flash(path)

# ── Main ──────────────────────────────────────────────────────────────────────

def main():
    global SERIAL_PORT, BAUD, BITSTREAM
    parser = argparse.ArgumentParser(description="Flash Tang Primer 20K via ESP32 JTAG")
    parser.add_argument("--port",    default=SERIAL_PORT, help="Serial port (default /dev/ttyUSB0)")
    parser.add_argument("--baud",    default=BAUD, type=int)
    parser.add_argument("--fs",      default=BITSTREAM, help="Bitstream .fs file")
    parser.add_argument("--idcode",  action="store_true", help="Read IDCODE only")
    parser.add_argument("--watch",   action="store_true", help="Auto-reflash on .fs change")
    args = parser.parse_args()

    SERIAL_PORT = args.port
    BAUD        = args.baud
    BITSTREAM   = args.fs

    open_serial()

    if args.idcode:
        check_idcode()
        return

    if not check_idcode():
        sys.exit(1)

    flash(args.fs)

    if args.watch:
        watch_and_reflash(args.fs)

if __name__ == "__main__":
    main()
