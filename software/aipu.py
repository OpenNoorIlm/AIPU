#!/usr/bin/env python3
"""
aipu.py — Python driver for the Teacher AIPU on Tang Primer 20K
=================================================================

Protocol (UART 115200 8N1, /dev/ttyUSB0):

  WRITE:    0xBB [addr_hi] [addr_lo] [len] [byte_0 ... byte_len-1]
              Writes LEN bytes into FPGA SRAM starting at ADDR.
              Only send when AIPU is not busy (i.e. not right after compute()).

  COMPUTE:  0xAA [src_hi] [src_lo] [dst_hi] [dst_lo] [0x02] [0x00] [0x55]
              Triggers computation: SRAM[src..src+N-1] = A vector,
              SRAM[src+N..src+2N-1] = B vector, result → SRAM[dst..dst+N*N*4-1].

  RESPONSE: "RES:XX XX ... XX\r\n" — N*N INT32 values as space-sep hex bytes (big-endian).

Quick start:
  import aipu, time
  chip = aipu.AIPU('/dev/ttyUSB0')
  chip.flash_fpga()  # optional — flashes top_fpga.fs via openFPGALoader
  chip.wait_boot()   # waits for "AIPU OK" banner
  result = chip.matmul([0,1,2,3], [4,5,6,7])
  print(result)      # [[0,0,0,0],[4,5,6,7],[8,10,12,14],[12,15,18,21]]
"""

import serial
import struct
import time
import subprocess
import os

# SRAM layout for G=1, C=1, N=4 (current top_fpga.v config)
# Full matmul layout (memory_ctrl v2 — column-major A, row-major B):
#   SRAM[src .. src+N*N-1]       = A stored column-major (col k = src + k*N)
#   SRAM[src+N*N .. src+2*N*N-1] = B stored row-major  (row k = src + N*N + k*N)
#   SRAM[dst .. dst+N*N*4-1]     = result C (N*N INT32, big-endian, row-major)
DEFAULT_SRC  = 0      # A starts at SRAM[0], B at SRAM[16], for N=4
DEFAULT_DST  = 512    # 4×4 INT32 results land at SRAM[512..575]
N            = 4      # systolic array dimension

FPGA_FS   = os.path.expanduser('~/teacher-aipu/hardware/rtl/top_fpga.fs')
FLASH_CMD = ['openFPGALoader', '-c', 'ft232', '-b', 'tangprimer20k', FPGA_FS]


class AIPU:
    def __init__(self, port='/dev/ttyUSB0', baud=115200, timeout=2.0):
        """Open serial connection to the ESP32 relay."""
        self.port    = port
        self.baud    = baud
        self.timeout = timeout
        self.ser     = serial.Serial(port, baud, timeout=0.1)
        # Do NOT sleep or flush here — the FPGA "AIPU OK" banner arrives ~1s
        # after flash and may already be in the kernel buffer. Flushing here
        # would destroy it. Call flush_input() only when the banner is not needed.

    def flush_input(self) -> None:
        """Drain all pending bytes from the serial buffer.

        Call this before sending new commands when you know the FPGA boot
        banner has already passed and you don't need it.
        ESP32 dump-mode produces garbage for ~2-3s after USB connect — this
        waits that window out before flushing.
        """
        time.sleep(3)
        self.ser.reset_input_buffer()

    # ------------------------------------------------------------------
    # Low-level SRAM access
    # ------------------------------------------------------------------

    def write_sram(self, addr: int, data: bytes) -> None:
        """Write arbitrary bytes into FPGA SRAM.

        Only call this when the AIPU is idle (not computing).
        Max 255 bytes per call; call multiple times for larger writes.
        """
        assert 0 <= addr <= 1023, f"addr {addr} out of 1KB SRAM range"
        assert 1 <= len(data) <= 255, f"data length {len(data)} must be 1..255"
        pkt = bytes([0xBB, (addr >> 8) & 0x03, addr & 0xFF, len(data)]) + data
        self.ser.write(pkt)
        # At 115200 baud: each byte takes ~87µs. Give the FPGA time to ingest them.
        # UART RX processes 1 byte per ~8.7µs at 115200, so 259 bytes ≈ 2.3ms.
        time.sleep(0.01 + len(data) * 0.00009)

    def read_sram_result(self, dst: int = DEFAULT_DST, n_ints: int = N*N,
                         timeout: float = 3.0) -> list:
        """Read N*N INT32 results from the RES: UART response.

        Returns a flat list of N*N int32 values, row-major.
        Raises TimeoutError if no valid RES: line arrives within `timeout` seconds.
        """
        buf = b''
        t   = time.time()
        while time.time() - t < timeout:
            chunk = self.ser.read(128)
            if chunk:
                buf += chunk
            if b'RES:' in buf and b'\r' in buf.split(b'RES:')[1]:
                hex_part = buf.split(b'RES:')[1].split(b'\r')[0].decode().strip()
                raw = bytes.fromhex(hex_part.replace(' ', ''))
                return [struct.unpack('>i', raw[i:i+4])[0]
                        for i in range(0, len(raw), 4)]
        raise TimeoutError(f"No RES: line within {timeout}s — is FPGA running top_fpga.fs?")

    # ------------------------------------------------------------------
    # Compute trigger
    # ------------------------------------------------------------------

    def compute(self, src: int = DEFAULT_SRC, dst: int = DEFAULT_DST) -> None:
        """Send a compute packet to the FPGA.

        The FPGA will:
          1. Clear accumulators
          2. Load A from SRAM[src..src+N-1]
          3. Load B from SRAM[src+N..src+2N-1]
          4. Present data to the N×N systolic array
          5. Drain the pipeline
          6. Store N*N INT32 results to SRAM[dst..dst+N*N*4-1]
          7. Send "RES: ..." over UART
        """
        pkt = bytes([
            0xAA,
            (src >> 8) & 0x03, src & 0xFF,
            (dst >> 8) & 0x03, dst & 0xFF,
            0x02, 0x00,        # reserved (ignored by FPGA)
            0x55               # end marker
        ])
        self.ser.write(pkt)

    # ------------------------------------------------------------------
    # High-level operations
    # ------------------------------------------------------------------

    def matmul(self, A: list, B: list,
               src: int = DEFAULT_SRC,
               dst: int = DEFAULT_DST) -> list:
        """Compute outer product A⊗B on the FPGA systolic array.

        MAC arithmetic is SIGNED INT8 × INT8 → INT32 accumulator.
        This matches PyTorch quantized inference convention.

        A: list of N values, each -128..127 (signed) or 0..255 (raw byte)
        B: list of N values, same range
        Returns: flat list of N*N int32 values, row-major.
          result[i*N+j] = A[i] * B[j]  (signed multiplication)

        Examples:
          chip.matmul([1,2,3,4], [10,20,30,40])
          → [10,20,30,40, 20,40,60,80, 30,60,90,120, 40,80,120,160]

          chip.matmul([-1,-1,-1,-1], [-1,-1,-1,-1])   # or [255,255,255,255]
          → [1,1,1,1, ...]   (signed: -1 × -1 = 1)

          chip.matmul([-2,-2,-2,-2], [3,3,3,3])       # or [254,254,254,254]
          → [-6,-6,-6,-6, ...]  (signed: -2 × 3 = -6)

        For Conv1d / nn.Linear:
          weights go into A (one output channel per future matmul row),
          activations go into B (one input position per future matmul row).
          Bias added in Python: [r + bias for r in result]
        """
        A = list(A)[:N]
        B = list(B)[:N]
        # Accept either signed (-128..127) or raw byte (0..255).
        # Signed values are converted to two's-complement bytes automatically.
        def to_byte(v):
            if v < 0:
                return v & 0xFF   # e.g. -1 → 255, -128 → 128
            assert v <= 255, f"value {v} out of range -128..255"
            return v
        A = [to_byte(v) for v in A]
        B = [to_byte(v) for v in B]

        # Clear input buffer before starting so we don't mix up responses
        self.ser.reset_input_buffer()

        # memory_ctrl now does N outer products (k=0..N-1):
        #   col k of A at SRAM[src + k*N], row k of B at SRAM[src+N*N + k*N]
        # For a 1D outer product we want only k=0 to contribute.
        # Explicitly zero-write cols 1..N-1 of A and rows 1..N-1 of B so the
        # k=1..N-1 iterations multiply by zero and don't corrupt the result.
        zeros = bytes(N * (N - 1))  # (N-1)*N zero bytes covers cols/rows 1..N-1
        self.write_sram(src,             bytes(A) + zeros)   # col0=A, cols1-3=0
        self.write_sram(src + N*N,       bytes(B) + zeros)   # row0=B, rows1-3=0

        # Trigger computation
        self.compute(src=src, dst=dst)

        # Read and return the result
        return self.read_sram_result(dst=dst)

    def matmul_matrix(self, A: list, B: list,
                       src: int = DEFAULT_SRC,
                       dst: int = DEFAULT_DST) -> list:
        """Compute full N×N matrix multiply C = A @ B on the FPGA.

        Uses the updated memory_ctrl which accumulates N outer products:
          C[i][j] = sum(A[i][k] * B[k][j] for k in range(N))

        SRAM layout written by this function:
          SRAM[src + k*N .. src + k*N + N-1]       = column k of A (for k=0..N-1)
          SRAM[src + N*N + k*N .. + k*N + N-1]     = row k of B    (for k=0..N-1)

        A: N×N matrix as flat list (row-major), e.g. [[a00,a01],[a10,a11]] flattened
           or list of N lists of N ints.
        B: N×N matrix as flat list (row-major), same shape.
        Returns: flat list of N*N int32, row-major — C[i*N+j] = A[i]·B[:,j]

        Example (N=4):
          A = [[1,0,0,0],
               [0,2,0,0],
               [0,0,3,0],
               [0,0,0,4]]  (diagonal)
          B = [[1,1,1,1],
               [1,1,1,1],
               [1,1,1,1],
               [1,1,1,1]]  (all ones)
          C = A @ B → each row i is scaled by A[i][i]:
            [[1,1,1,1],[2,2,2,2],[3,3,3,3],[4,4,4,4]]
        """
        # Normalize: accept list of lists or flat list
        if isinstance(A[0], (list, tuple)):
            A = [v for row in A for v in row]
        if isinstance(B[0], (list, tuple)):
            B = [v for row in B for v in row]
        assert len(A) == N*N, f"A must have {N*N} elements, got {len(A)}"
        assert len(B) == N*N, f"B must have {N*N} elements, got {len(B)}"

        def to_byte(v):
            if v < 0: return v & 0xFF
            assert v <= 255, f"value {v} out of range -128..255"
            return v

        A = [to_byte(v) for v in A]
        B = [to_byte(v) for v in B]

        # Pack A column-major: col k = [A[0][k], A[1][k], A[2][k], A[3][k]]
        #   A[row*N + col] → col k bytes: A[0*N+k], A[1*N+k], A[2*N+k], A[3*N+k]
        a_col_major = []
        for k in range(N):
            for i in range(N):
                a_col_major.append(A[i*N + k])

        # Pack B row-major: row k = [B[k][0], B[k][1], B[k][2], B[k][3]]
        #   B[row*N + col] → row k bytes: B[k*N+0], B[k*N+1], B[k*N+2], B[k*N+3]
        b_row_major = []
        for k in range(N):
            for j in range(N):
                b_row_major.append(B[k*N + j])

        self.ser.reset_input_buffer()

        # Write A (column-major) starting at src
        self.write_sram(src,       bytes(a_col_major))
        # Write B (row-major) starting at src + N*N
        self.write_sram(src + N*N, bytes(b_row_major))

        # Trigger
        self.compute(src=src, dst=dst)

        return self.read_sram_result(dst=dst)

    # ------------------------------------------------------------------
    # Boot / flash helpers
    # ------------------------------------------------------------------

    def wait_boot(self, timeout: float = 8.0) -> None:
        """Wait for the 'AIPU OK' boot banner from result_sender.

        Call this right after flash_fpga() or after a power cycle.
        The banner arrives ~1s after FPGA configuration, but the ESP32 dump-mode
        also produces garbage bytes for ~2-3s after the port is first opened.
        We read everything and just look for the 'AIPU OK' substring anywhere.
        """
        buf = b''
        t   = time.time()
        while time.time() - t < timeout:
            chunk = self.ser.read(128)
            if chunk:
                buf += chunk
                # Print raw to help diagnose if something is wrong
                if b'AIPU OK' in buf:
                    print("Boot banner received.")
                    self.ser.reset_input_buffer()
                    return
        # If we get here, print what we did receive to help diagnose
        printable = ''.join(c if 32 <= ord(c) < 127 else '.' for c in buf.decode('latin-1'))
        raise TimeoutError(
            f"AIPU OK banner not received within {timeout}s.\n"
            f"Received {len(buf)} bytes: {printable[:120]!r}\n"
            f"Check: is top_fpga.fs flashed? Is GPIO25 wire connected?"
        )

    def flash_fpga(self, fs_path: str = FPGA_FS) -> None:
        """Flash top_fpga.fs to the Tang Primer 20K via openFPGALoader + FT232H.

        Requires FT232H connected and openFPGALoader in PATH.
        After flashing, call wait_boot() before issuing any commands.
        """
        cmd = ['openFPGALoader', '-c', 'ft232', '-b', 'tangprimer20k', fs_path]
        print(f"Flashing {fs_path} ...")
        result = subprocess.run(cmd, capture_output=True, text=True)
        if 'Load SRAM: ' in result.stderr and '100%' in result.stderr:
            print("Flash OK (ignore any FAIL at end — that is normal for Gowin SRAM verify).")
        else:
            print("STDOUT:", result.stdout)
            print("STDERR:", result.stderr)
            raise RuntimeError("openFPGALoader did not complete successfully")
        # Drain leftover bytes from the FPGA booting
        time.sleep(1)
        self.ser.reset_input_buffer()

    def close(self) -> None:
        self.ser.close()

    def __enter__(self):
        return self

    def __exit__(self, *_):
        self.close()


# ------------------------------------------------------------------
# Demo / self-test
# ------------------------------------------------------------------

if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser(description='AIPU Python driver demo')
    parser.add_argument('--port',  default='/dev/ttyUSB0')
    parser.add_argument('--flash', action='store_true',
                        help='Flash top_fpga.fs before running')
    parser.add_argument('--boot',  action='store_true',
                        help='Wait for AIPU OK banner before sending commands')
    args = parser.parse_args()

    print(f"Opening {args.port} ...")
    with AIPU(args.port) as chip:
        if args.flash:
            chip.flash_fpga()

        if args.boot:
            # Banner arrives ~1s after flash. Read immediately — don't flush first.
            print("Waiting for AIPU OK banner (up to 8s) ...")
            chip.wait_boot()
        else:
            # No banner expected — drain garbage then send a fresh trigger
            print("Draining serial buffer (3s) ...")
            chip.flush_input()

        print("\n--- Test 1: A=[0,1,2,3], B=[4,5,6,7] (explicit write) ---")
        res1 = chip.matmul([0, 1, 2, 3], [4, 5, 6, 7])
        print("Result  :", res1)
        expected1 = [0,0,0,0, 4,5,6,7, 8,10,12,14, 12,15,18,21]
        print("Expected:", expected1)
        print("Match:", res1 == expected1)

        print("\n--- Test 2: write custom A=[10,20,30,40], B=[1,2,3,4] ---")
        res2 = chip.matmul([10, 20, 30, 40], [1, 2, 3, 4])
        print("Result  :", res2)
        expected2 = [a*b for a in [10,20,30,40] for b in [1,2,3,4]]
        print("Expected:", expected2)
        print("Match:", res2 == expected2)

        print("\n--- Test 3: all zeros ---")
        res3 = chip.matmul([0, 0, 0, 0], [0, 0, 0, 0])
        print("Result  :", res3)
        print("Match:", res3 == [0]*16)

        print("\n--- Test 4: signed INT8 arithmetic — 0xFF = -1, so (-1)×(-1) = 1 ---")
        # IMPORTANT: the MAC unit does SIGNED INT8 multiplication.
        # Byte 0xFF = 255 unsigned, but = -1 as signed INT8.
        # This matches PyTorch quantized inference (INT8 weights: -128..127).
        # To compute 255×255 = 65025 you would need unsigned MACs (not implemented).
        # To use negative weights/activations: pass two's-complement bytes directly.
        #   e.g. -1  → 0xFF = 255,  -128 → 0x80 = 128,  127 → 0x7F = 127
        res4 = chip.matmul([255, 255, 255, 255], [255, 255, 255, 255])  # -1 × -1 = 1
        print("Result  :", res4)
        print("Expected: [1]*16  (signed: -1 × -1 = 1)")
        print("Match:", res4 == [1]*16)

        print("\n--- Test 4b: signed negative × positive = negative ---")
        # -2 × 3 = -6  →  0xFE = 254 as byte = -2 signed INT8
        res4b = chip.matmul([254, 254, 254, 254], [3, 3, 3, 3])
        print("Result  :", res4b)
        print("Expected: [-6]*16  (signed: -2 × 3 = -6)")
        print("Match:", res4b == [-6]*16)

        print("\n--- Test 4c: max positive (127) × max positive (127) = 16129 ---")
        res4c = chip.matmul([127, 127, 127, 127], [127, 127, 127, 127])
        print("Result  :", res4c)
        print("Expected: [16129]*16")
        print("Match:", res4c == [16129]*16)

        print("\n--- Test 5: Conv1d neuron — w·x+bias ---")
        # out(Ni, Cout_j) = bias + Σ weight(Cout_j,k) * input(Ni,k)
        # With N=4: weight row 0 = [1,2,3,4], input row 0 = [10,20,30,40]
        # dot product = 1*10 + 2*20 + 3*30 + 4*40 = 10+40+90+160 = 300
        # result[0] (row0 · col0 of outer product) will give weight[0]*input[0] = 10
        # Full matmul needed for true dot product — this tests outer product for now
        W = [1, 2, 3, 4]   # weight row
        X = [10, 20, 30, 40]  # input row
        res5 = chip.matmul(W, X)
        print("W:", W, "  X:", X)
        print("Outer product (W[i]*X[j]):", res5)
        # Manual dot product from diagonal: sum(W[k]*X[k])
        dot = sum(W[k]*X[k] for k in range(4))
        print(f"True dot product W·X = {dot} (need full matmul for this — milestone #1)")

        print("\n--- Test 6: Full N×N matrix multiply C = A @ B ---")
        # A = identity-like (diagonal [1,2,3,4]), B = all-ones
        # C[i][j] = sum(A[i][k]*B[k][j]) = A[i][i]*1 (only diagonal of A is non-zero)
        # → row i of C = [A[i][i]] * N
        A_mat = [
            1, 0, 0, 0,
            0, 2, 0, 0,
            0, 0, 3, 0,
            0, 0, 0, 4,
        ]
        B_mat = [1]*16  # all ones
        res6 = chip.matmul_matrix(A_mat, B_mat)
        expected6 = [1,1,1,1, 2,2,2,2, 3,3,3,3, 4,4,4,4]
        print("Result  :", res6)
        print("Expected:", expected6)
        print("Match:", res6 == expected6)

        print("\n--- Test 7: General matrix multiply ---")
        # A = [[1,2],[3,4],[5,6],[7,8]] padded to 4×4, B = [[1,0],[0,1],[0,0],[0,0]]
        A_mat2 = [
            1, 2, 0, 0,
            3, 4, 0, 0,
            5, 6, 0, 0,
            7, 8, 0, 0,
        ]
        B_mat2 = [
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 0, 0,
            0, 0, 0, 0,
        ]
        # C = A @ B → C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + 0 + 0
        # C[0] = [1*1+2*0, 1*0+2*1, 0, 0] = [1, 2, 0, 0]
        # C[1] = [3, 4, 0, 0], C[2] = [5, 6, 0, 0], C[3] = [7, 8, 0, 0]
        res7 = chip.matmul_matrix(A_mat2, B_mat2)
        expected7 = [
            1, 2, 0, 0,
            3, 4, 0, 0,
            5, 6, 0, 0,
            7, 8, 0, 0,
        ]
        print("Result  :", res7)
        print("Expected:", expected7)
        print("Match:", res7 == expected7)

    print("\nAll tests done.")
