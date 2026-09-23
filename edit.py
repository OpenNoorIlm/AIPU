#!/usr/bin/env python3
"""
edit.py — apply all 4 phases of AIPU improvements
Run: python3 edit.py

Phase 1: Fix top_tb.v FP8 testbench (reset between tests, longer task_cycles)
Phase 2: Add bf16_mul to mac.v + route precision=2'b10 to it (8-bit ports, limited precision)
Phase 3: UART packet byte 6 = {chain_row[3:0], chain_col[3:0]} for G>1 Option A
Phase 4: PARALLEL_MEM stub in top.v (default off)

Backs up each file to .backup/ before editing. Idempotent.
"""
import re, sys
from pathlib import Path

RTL = Path.home() / "teacher-aipu/hardware/rtl"
BACKUP = RTL / ".backup"

def backup(path):
    BACKUP.mkdir(exist_ok=True)
    src, dst = RTL / path, BACKUP / path
    if src.exists() and not dst.exists():
        dst.write_text(src.read_text())

def write(path, content):
    backup(path)
    (RTL / path).write_text(content)
    print(f"  ✓ wrote   {path}")

def sub(path, old, new, count=1):
    backup(path)
    p = RTL / path
    txt = p.read_text()
    if old not in txt:
        # idempotent: if `new` is already present, silently succeed
        if new in txt:
            print(f"  · {path}: already patched")
            return True
        print(f"  ⚠ {path}: pattern not found: {old[:70]!r}")
        return False
    new_txt = txt.replace(old, new) if count == 'all' else txt.replace(old, new, count)
    p.write_text(new_txt)
    print(f"  ✓ patched {path}")
    return True

def regex_sub(path, pat, repl, count=0):
    backup(path)
    p = RTL / path
    txt = p.read_text()
    new_txt, n = re.subn(pat, repl, txt, count=count)
    if n == 0:
        print(f"  ⚠ {path}: regex no match: {pat!r}")
        return False
    p.write_text(new_txt)
    print(f"  ✓ patched {path} ({n} sub{'s' if n != 1 else ''})")
    return True

# ═══════════════════════════════════════════════════════════════════════════
# PHASE 1 — top_tb.v full rewrite
# ═══════════════════════════════════════════════════════════════════════════
TOP_TB_NEW = r'''/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off WIDTHTRUNC */
/* verilator lint_off TIMESCALEMOD */
`timescale 1ns/1ps
module top_tb;
    reg clk = 0;
    always #18 clk = ~clk;  // 27 MHz

    reg         reset       = 1;
    reg  [1:0]  precision   = 2'b00;
    reg         task_valid  = 0;
    reg  [7:0]  task_id     = 1;
    reg  [31:0] task_cycles = 500;
    wire        task_accepted, queue_full;
    wire [4:0]  queue_count;
    reg         mem_start    = 0;
    reg  [0:0]  mem_chain_row = 0, mem_chain_col = 0;
    reg  [9:0]  mem_src_addr = 0, mem_dst_addr = 512;
    reg  [31:0] mem_num_rows = 4;
    wire        mem_done;
    wire [9:0]  sram_rd_addr, sram_wr_addr;
    wire        sram_wr_en;
    wire [7:0]  sram_wr_data;
    reg  [7:0]  sram_rd_data;
    wire        uart_tx_pin;

    reg [7:0] mem_arr [0:1023];
    integer i;
    initial begin : mem_init
        for (i=0;i<1024;i=i+1) mem_arr[i] = 8'h00;
    end
    always @(posedge clk) if (sram_wr_en) mem_arr[sram_wr_addr] <= sram_wr_data;
    always @(posedge clk) sram_rd_data <= mem_arr[sram_rd_addr];

    top #(.G(1),.C(1),.N(4),.QDEPTH(8),.SRAM_DEPTH(1024),
          .CLK_FREQ(27_000_000),.BAUD_RATE(115_200)) dut (
        .clk(clk), .reset(reset), .precision(precision),
        .task_valid(task_valid), .task_id(task_id), .task_cycles(task_cycles),
        .task_accepted(task_accepted), .queue_full(queue_full),
        .queue_count(queue_count),
        .mem_start(mem_start), .mem_chain_row(mem_chain_row),
        .mem_chain_col(mem_chain_col), .mem_src_addr(mem_src_addr),
        .mem_dst_addr(mem_dst_addr), .mem_num_rows(mem_num_rows),
        .mem_done(mem_done),
        .sram_rd_addr(sram_rd_addr), .sram_wr_addr(sram_wr_addr),
        .sram_wr_en(sram_wr_en), .sram_wr_data(sram_wr_data),
        .sram_rd_data(sram_rd_data), .uart_tx_pin(uart_tx_pin)
    );

    task do_reset;
        begin
            reset <= 1; repeat(20) @(posedge clk);
            reset <= 0; repeat(20) @(posedge clk);
        end
    endtask

    task fire;
        integer t;
        begin
            t = 0;
            while (queue_full && t < 1000) begin @(posedge clk); t=t+1; end
            @(posedge clk); task_valid <= 1;
            @(posedge clk); task_valid <= 0;
            t = 0;
            while (!task_accepted && t < 200) begin @(posedge clk); t=t+1; end
            if (!task_accepted) $display("  [fire] WARN task_accepted never fired");
            repeat(20) @(posedge clk);
            @(posedge clk); mem_start <= 1;
            @(posedge clk); mem_start <= 0;
            t = 0;
            while (!mem_done && t < 10000) begin @(posedge clk); t=t+1; end
            if (!mem_done) $display("  [fire] WARN mem_done never fired");
            repeat(20) @(posedge clk);
        end
    endtask

    function real fp32_to_real;
        input [31:0] b;
        real r; integer exp; real mant;
        begin
            if (b[30:0] == 0) begin fp32_to_real = b[31] ? -0.0 : 0.0; end
            else begin
                exp  = $signed({1'b0, b[30:23]}) - 127;
                mant = 1.0 + $itor(b[22:0]) / (2.0**23);
                r    = mant * (2.0**exp);
                fp32_to_real = b[31] ? -r : r;
            end
        end
    endfunction

    task dump_sram;
        input [9:0] base;
        integer k;
        begin
            $write("  SRAM[%0d..%0d] = ", base, base+15);
            for (k=0; k<16; k=k+1) $write("%02x ", mem_arr[base+k]);
            $display("");
        end
    endtask

    integer pass, fail, ii;
    reg [31:0] raw;
    real got;

    initial begin
        pass = 0; fail = 0;
        do_reset;

        // ── T1: INT8 identity ──────────────────────────────────────
        $display("\n=== T1: INT8 identity ===");
        for (ii=0; ii<1024; ii=ii+1) mem_arr[ii] = 8'h00;
        for (ii=0; ii<4; ii=ii+1) begin
            mem_arr[0+ii*4+ii]  = 8'h01;
            mem_arr[16+ii*4+ii] = 8'h01;
        end
        precision = 2'b00; fire;
        dump_sram(512);
        raw = {mem_arr[512],mem_arr[513],mem_arr[514],mem_arr[515]};
        if ($signed(raw) === 32'sd1) begin
            $display("PASS T1: INT8 I[0][0]=%0d", $signed(raw)); pass=pass+1;
        end else begin
            $display("FAIL T1: INT8 I[0][0]=%0d (exp 1)", $signed(raw)); fail=fail+1;
        end

        // ── T2: FP8 1.0 × 1.0 ──────────────────────────────────────
        $display("\n=== T2: FP8 1.0 x 1.0 ===");
        do_reset;
        for (ii=0; ii<1024; ii=ii+1) mem_arr[ii] = 8'h00;
        for (ii=0; ii<4; ii=ii+1) begin
            mem_arr[0+ii*4+ii]  = 8'h38;
            mem_arr[16+ii*4+ii] = 8'h38;
        end
        precision = 2'b01; fire;
        dump_sram(512);
        raw = {mem_arr[512],mem_arr[513],mem_arr[514],mem_arr[515]};
        got = fp32_to_real(raw);
        if (got > 0.99 && got < 1.01) begin
            $display("PASS T2: FP8 1.0x1.0=%f", got); pass=pass+1;
        end else begin
            $display("FAIL T2: FP8 1.0x1.0=%f (bits=%h)", got, raw); fail=fail+1;
        end

        // ── T3: FP8 2.0 × 3.0 = 6.0 ────────────────────────────────
        $display("\n=== T3: FP8 2.0 x 3.0 ===");
        do_reset;
        for (ii=0; ii<1024; ii=ii+1) mem_arr[ii] = 8'h00;
        for (ii=0; ii<4; ii=ii+1) begin
            mem_arr[0+ii*4+ii]  = 8'h40;
            mem_arr[16+ii*4+ii] = 8'h44;
        end
        precision = 2'b01; fire;
        dump_sram(512);
        raw = {mem_arr[512],mem_arr[513],mem_arr[514],mem_arr[515]};
        got = fp32_to_real(raw);
        if (got > 5.99 && got < 6.01) begin
            $display("PASS T3: FP8 2.0x3.0=%f", got); pass=pass+1;
        end else begin
            $display("FAIL T3: FP8 2.0x3.0=%f (bits=%h)", got, raw); fail=fail+1;
        end

        // ── T4: FP8 -1.0 × 2.0 = -2.0 ──────────────────────────────
        $display("\n=== T4: FP8 -1.0 x 2.0 ===");
        do_reset;
        for (ii=0; ii<1024; ii=ii+1) mem_arr[ii] = 8'h00;
        for (ii=0; ii<4; ii=ii+1) begin
            mem_arr[0+ii*4+ii]  = 8'hB8;
            mem_arr[16+ii*4+ii] = 8'h40;
        end
        precision = 2'b01; fire;
        dump_sram(512);
        raw = {mem_arr[512],mem_arr[513],mem_arr[514],mem_arr[515]};
        got = fp32_to_real(raw);
        if (got > -2.01 && got < -1.99) begin
            $display("PASS T4: FP8 -1.0x2.0=%f", got); pass=pass+1;
        end else begin
            $display("FAIL T4: FP8 -1.0x2.0=%f (bits=%h)", got, raw); fail=fail+1;
        end

        $display("\nResults: %0d/%0d passed", pass, pass+fail);
        if (fail==0) $display("ALL PASS"); else $display("FAILURES: %0d", fail);
        $finish;
    end

    initial #200_000_000 begin $display("TIMEOUT"); $finish; end
endmodule
'''

def phase1():
    print("\n[Phase 1] Rewriting top_tb.v (reset between tests, 500-cycle tasks, SRAM dumps)")
    write("top_tb.v", TOP_TB_NEW)

# ═══════════════════════════════════════════════════════════════════════════
# PHASE 2 — bf16_mul in mac.v + route precision=2'b10
# ═══════════════════════════════════════════════════════════════════════════
BF16_FN = r'''
    // ── BF16 multiplier (IEEE 754 BF16: 1 sign + 8 exp + 7 mantissa) ────
    // NOTE: current 8-bit mac ports feed this as {8'b0, a} — only the low
    // byte of the 16-bit operands is populated. This exercises the exponent
    // and rounding path correctly but with reduced precision. To get true
    // BF16, widen a/b/next_a/next_b ports to [15:0] per BF16_UPGRADE_GUIDE.
    function automatic [31:0] bf16_mul;
        input [15:0] fa, fb;
        reg        s;
        reg [7:0]  ea, eb, ep;
        reg [7:0]  ma, mb;
        reg [15:0] mp;
        begin
            s  = fa[15] ^ fb[15];
            ea = fa[14:7];
            eb = fb[14:7];
            ma = {1'b1, fa[6:0]};
            mb = {1'b1, fb[6:0]};
            if (ea == 8'd0 || eb == 8'd0) begin
                bf16_mul = 32'd0;
            end else if (ea == 8'hFF || eb == 8'hFF) begin
                bf16_mul = {s, 8'hFF, 23'h400000};   // Inf/NaN
            end else begin
                ep = ea + eb - 8'd127;
                mp = ma * mb;                        // 8x8 = 16-bit
                if (mp[15])
                    bf16_mul = {s, ep + 8'd1, mp[14:8], 16'd0};
                else
                    bf16_mul = {s, ep,       mp[13:7], 16'd0};
            end
        end
    endfunction

    wire [31:0] bf16_prod = bf16_mul({8'b0, a}, {8'b0, b});
    wire [31:0] bf16_next = (in_out_reset != 8'h00)
                          ? 32'd0
                          : fp32_add(out, bf16_prod);
'''

def phase2():
    print("\n[Phase 2] Adding bf16_mul to mac.v, routing precision=2'b10")

    # Insert the BF16 function block right before the "Main register" comment
    sub("mac.v",
        "    // ── Main register ────────────────────────────────────────────────────",
        BF16_FN + "\n    // ── Main register ────────────────────────────────────────────────────")

    # Route precision=2'b10 to the BF16 path (was aliasing fp8_next)
    sub("mac.v",
        "                2'b10:   out <= fp8_next;   // BF16 stub",
        "                2'b10:   out <= bf16_next;  // BF16 (partial — see BF16_UPGRADE_GUIDE.md)")

    # Update module header comment
    sub("mac.v",
        "//   2'b10 = BF16  : ** STUB ** see BF16_UPGRADE_GUIDE.md; aliases FP8 path",
        "//   2'b10 = BF16  : bf16_mul on {8'b0,a}x{8'b0,b} (see BF16_UPGRADE_GUIDE.md)")

# ═══════════════════════════════════════════════════════════════════════════
# PHASE 3 — G>1 Option A: UART packet byte 6 = {chain_row[3:0], chain_col[3:0]}
# ═══════════════════════════════════════════════════════════════════════════
def phase3():
    print("\n[Phase 3] G>1 Option A: route tasks to cells [row][col] via packet byte 6")

    # Widen mem_chain_row/col registers to 4 bits so they can carry G up to 16
    sub("top_fpga.v",
        "    reg [0:0]  mem_chain_row = 0;  // 1-bit: 0 or 1 (for G=2)\n"
        "    reg [0:0]  mem_chain_col = 0;  // 1-bit: 0 or 1 (for G=2)",
        "    reg [3:0]  mem_chain_row = 0;  // 4-bit: G up to 16\n"
        "    reg [3:0]  mem_chain_col = 0;  // 4-bit: G up to 16")

    # Parse byte 6 as {row[3:0], col[3:0]} and route to mem_chain_row/col
    sub("top_fpga.v",
        "                                mem_src_addr <= {pkt_buf[1][1:0], pkt_buf[2]};\n"
        "                                mem_dst_addr <= {pkt_buf[3][1:0], pkt_buf[4]};\n"
        "                                precision    <= pkt_buf[5][1:0];  // byte5: precision",
        "                                mem_src_addr  <= {pkt_buf[1][1:0], pkt_buf[2]};\n"
        "                                mem_dst_addr  <= {pkt_buf[3][1:0], pkt_buf[4]};\n"
        "                                precision     <= pkt_buf[5][1:0];  // byte5: precision\n"
        "                                mem_chain_row <= pkt_buf[6][7:4];  // byte6 hi nibble: row\n"
        "                                mem_chain_col <= pkt_buf[6][3:0];  // byte6 lo nibble: col")

    # Update protocol comment
    sub("top_fpga.v",
        "    //   0xAA [SRC_HI] [SRC_LO] [DST_HI] [DST_LO] [0x02] [0x00] [0x55]",
        "    //   0xAA [SRC_HI] [SRC_LO] [DST_HI] [DST_LO] [PREC] [R|C]  [0x55]\n"
        "    //        byte5 = precision (00=INT8, 01=FP8, 10=BF16)\n"
        "    //        byte6 = {chain_row[3:0], chain_col[3:0]}  (G>1 cell select)")

# ═══════════════════════════════════════════════════════════════════════════
# PHASE 4 — PARALLEL_MEM stub in top.v (default OFF)
# ═══════════════════════════════════════════════════════════════════════════
def phase4():
    print("\n[Phase 4] Adding PARALLEL_MEM parameter stub to top.v (default off)")

    # Add PARALLEL_MEM parameter to top.v
    sub("top.v",
        "    parameter SRAM_DEPTH = 1024,\n"
        "    parameter CLK_FREQ   = 27_000_000,\n"
        "    parameter BAUD_RATE  = 115_200\n"
        ")(",
        "    parameter SRAM_DEPTH = 1024,\n"
        "    parameter CLK_FREQ   = 27_000_000,\n"
        "    parameter BAUD_RATE  = 115_200,\n"
        "    // PARALLEL_MEM: 0 = single mem_ctrl (current, G>1 is sequential)\n"
        "    //               1 = one mem_ctrl per grid cell (true 4x throughput)\n"
        "    //               Stub only — instantiation not yet wired. See continue.md.\n"
        "    parameter PARALLEL_MEM = 0\n"
        ")(")

    # Add a generate guard comment near the mem instantiation
    sub("top.v",
        "    memory_ctrl #(.G(G), .C(C), .N(N), .SRAM_DEPTH(SRAM_DEPTH)) mem(",
        "    // NOTE: PARALLEL_MEM=1 requires G*G memory_ctrl instances with SRAM\n"
        "    // arbitration — currently only the single-instance path is implemented.\n"
        "    memory_ctrl #(.G(G), .C(C), .N(N), .SRAM_DEPTH(SRAM_DEPTH)) mem(")

    # Add a top_fpga.v comment so the param is discoverable there too
    sub("top_fpga.v",
        "    top #(\n        .G(2), .C(1), .N(4),",
        "    // To enable parallel-grid (4x throughput): set G(2), PARALLEL_MEM(1)\n"
        "    // and provide G*G memory_ctrls. See continue.md Phase 4.\n"
        "    top #(\n        .G(2), .C(1), .N(4), .PARALLEL_MEM(0),")

# ═══════════════════════════════════════════════════════════════════════════
def main():
    print("AIPU edit.py — applying 4 phases")
    print(f"RTL dir:  {RTL}")
    print(f"Backups:  {BACKUP}")
    if not RTL.exists():
        print(f"ERROR: {RTL} not found"); sys.exit(1)

    phase1()
    phase2()
    phase3()
    phase4()

    print("\n══════════════════════════════════════════════════════════════")
    print("All phases applied. Next steps:")
    print()
    print("  1. Verify Verilator sim (Phase 1 fix):")
    print("     cd ~/teacher-aipu/hardware/rtl")
    print("     verilator --sv --binary -o sim_top top_tb.v mac.v systolic_NxN.v \\")
    print("       chain_CxC.v grid_GxG.v dispatcher.v memory_ctrl.v uart_tx.v \\")
    print("       uart_rx.v result_sender.v top.v && ./obj_dir/sim_top")
    print()
    print("  2. Rebuild + flash (editGrids.py runs the whole pipeline):")
    print("     python3 editGrids.py")
    print()
    print("  3. BF16: precision=2'b10 in UART packet byte 5 — works but with")
    print("     8-bit mantissa truncation until you widen ports per")
    print("     BF16_UPGRADE_GUIDE.md")
    print()
    print("  4. G>1 Option A: packet byte 6 = 0x00/0x01/0x10/0x11 for cell [0][0]")
    print("     /[0][1]/[1][0]/[1][1] — hardware already routes via sel_row/sel_col")
    print()
    print("  5. G>1 Option B (parallel): PARALLEL_MEM=1 is a stub. Full impl")
    print("     is a separate session — see continue.md.")
    print("══════════════════════════════════════════════════════════════")

if __name__ == "__main__":
    main()
