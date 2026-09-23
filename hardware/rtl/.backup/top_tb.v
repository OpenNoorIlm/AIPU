/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off WIDTHTRUNC */
/* verilator lint_off TIMESCALEMOD */
`timescale 1ns/1ps
module top_tb;
    reg clk = 0;
    always #18 clk = ~clk;  // 27 MHz

    reg  [1:0]  precision   = 2'b00;
    reg         task_valid  = 0;
    reg  [7:0]  task_id     = 1;
    reg  [31:0] task_cycles = 300;
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
    initial begin : mem_init
        integer i; for (i=0;i<1024;i=i+1) mem_arr[i] = 8'h00;
    end
    always @(posedge clk) if (sram_wr_en) mem_arr[sram_wr_addr] <= sram_wr_data;
    always @(posedge clk) sram_rd_data <= mem_arr[sram_rd_addr];

    top #(.G(1),.C(1),.N(4),.QDEPTH(8),.SRAM_DEPTH(1024),
          .CLK_FREQ(27_000_000),.BAUD_RATE(115_200)) dut (
        .clk(clk), .reset(1'b0),
        .precision(precision),
        .task_valid(task_valid), .task_id(task_id),
        .task_cycles(task_cycles), .task_accepted(task_accepted),
        .queue_full(queue_full), .queue_count(queue_count),
        .mem_start(mem_start), .mem_chain_row(mem_chain_row),
        .mem_chain_col(mem_chain_col), .mem_src_addr(mem_src_addr),
        .mem_dst_addr(mem_dst_addr), .mem_num_rows(mem_num_rows),
        .mem_done(mem_done),
        .sram_rd_addr(sram_rd_addr), .sram_wr_addr(sram_wr_addr),
        .sram_wr_en(sram_wr_en), .sram_wr_data(sram_wr_data),
        .sram_rd_data(sram_rd_data), .uart_tx_pin(uart_tx_pin)
    );

    // fire: enqueue task then run memory_ctrl
    task fire;
        integer t;
        begin
            // wait for queue space
            t = 0;
            while (queue_full && t < 1000) begin @(posedge clk); t=t+1; end
            @(posedge clk); task_valid <= 1;
            @(posedge clk); task_valid <= 0;
            // wait for task_accepted
            t = 0;
            while (!task_accepted && t < 100) begin @(posedge clk); t=t+1; end
            repeat(10) @(posedge clk);
            // trigger mem_ctrl
            @(posedge clk); mem_start <= 1;
            @(posedge clk); mem_start <= 0;
            // wait for mem_done posedge
            t = 0;
            while (!mem_done && t < 5000) begin @(posedge clk); t=t+1; end
            repeat(10) @(posedge clk);
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

    integer pass, fail, ii;
    reg [31:0] raw;
    real got;

    initial begin
        pass = 0; fail = 0;
        repeat(30) @(posedge clk);

        // ─── T1: INT8 identity A×B=I ──────────────────────────────────────
        // col-major A at [0..15], row-major B at [16..31]
        // identity: A[col][row] = 1 if col==row else 0
        for (ii=0; ii<4; ii=ii+1) begin
            mem_arr[0+ii*4+0] = (ii==0) ? 8'h01 : 8'h00;
            mem_arr[0+ii*4+1] = (ii==1) ? 8'h01 : 8'h00;
            mem_arr[0+ii*4+2] = (ii==2) ? 8'h01 : 8'h00;
            mem_arr[0+ii*4+3] = (ii==3) ? 8'h01 : 8'h00;
            mem_arr[16+ii*4+0] = (ii==0) ? 8'h01 : 8'h00;
            mem_arr[16+ii*4+1] = (ii==1) ? 8'h01 : 8'h00;
            mem_arr[16+ii*4+2] = (ii==2) ? 8'h01 : 8'h00;
            mem_arr[16+ii*4+3] = (ii==3) ? 8'h01 : 8'h00;
        end
        precision = 2'b00; fire;
        raw = {mem_arr[512],mem_arr[513],mem_arr[514],mem_arr[515]};
        if ($signed(raw) === 32'sd1) begin
            $display("PASS T1: INT8 I[0][0]=%0d", $signed(raw)); pass=pass+1;
        end else begin
            $display("FAIL T1: INT8 I[0][0]=%0d (exp 1)", $signed(raw)); fail=fail+1;
        end

        // ─── T2: FP8 1.0 × 1.0 = 1.0 ─────────────────────────────────────
        // FP8 1.0 = 8'h38  (e=7, m=0)
        for (ii=0; ii<4; ii=ii+1) begin
            mem_arr[0+ii*4+0] = (ii==0) ? 8'h38 : 8'h00;
            mem_arr[0+ii*4+1] = (ii==1) ? 8'h38 : 8'h00;
            mem_arr[0+ii*4+2] = (ii==2) ? 8'h38 : 8'h00;
            mem_arr[0+ii*4+3] = (ii==3) ? 8'h38 : 8'h00;
            mem_arr[16+ii*4+0] = (ii==0) ? 8'h38 : 8'h00;
            mem_arr[16+ii*4+1] = (ii==1) ? 8'h38 : 8'h00;
            mem_arr[16+ii*4+2] = (ii==2) ? 8'h38 : 8'h00;
            mem_arr[16+ii*4+3] = (ii==3) ? 8'h38 : 8'h00;
        end
        precision = 2'b01; fire;
        raw = {mem_arr[512],mem_arr[513],mem_arr[514],mem_arr[515]};
        got = fp32_to_real(raw);
        if (got > 0.99 && got < 1.01) begin
            $display("PASS T2: FP8 1.0x1.0=%f", got); pass=pass+1;
        end else begin
            $display("FAIL T2: FP8 1.0x1.0=%f (bits=%h, exp 1.0)", got, raw); fail=fail+1;
        end

        // ─── T3: FP8 2.0 × 3.0 = 6.0 ─────────────────────────────────────
        // 2.0=8'h40, 3.0=8'h44
        for (ii=0; ii<4; ii=ii+1) begin
            mem_arr[0+ii*4+0] = (ii==0) ? 8'h40 : 8'h00;
            mem_arr[0+ii*4+1] = (ii==1) ? 8'h40 : 8'h00;
            mem_arr[0+ii*4+2] = (ii==2) ? 8'h40 : 8'h00;
            mem_arr[0+ii*4+3] = (ii==3) ? 8'h40 : 8'h00;
            mem_arr[16+ii*4+0] = (ii==0) ? 8'h44 : 8'h00;
            mem_arr[16+ii*4+1] = (ii==1) ? 8'h44 : 8'h00;
            mem_arr[16+ii*4+2] = (ii==2) ? 8'h44 : 8'h00;
            mem_arr[16+ii*4+3] = (ii==3) ? 8'h44 : 8'h00;
        end
        precision = 2'b01; fire;
        raw = {mem_arr[512],mem_arr[513],mem_arr[514],mem_arr[515]};
        got = fp32_to_real(raw);
        if (got > 5.99 && got < 6.01) begin
            $display("PASS T3: FP8 2.0x3.0=%f", got); pass=pass+1;
        end else begin
            $display("FAIL T3: FP8 2.0x3.0=%f (bits=%h)", got, raw); fail=fail+1;
        end

        // ─── T4: FP8 -1.0 × 2.0 = -2.0 ──────────────────────────────────
        // -1.0=8'hB8, 2.0=8'h40
        for (ii=0; ii<4; ii=ii+1) begin
            mem_arr[0+ii*4+0] = (ii==0) ? 8'hB8 : 8'h00;
            mem_arr[0+ii*4+1] = (ii==1) ? 8'hB8 : 8'h00;
            mem_arr[0+ii*4+2] = (ii==2) ? 8'hB8 : 8'h00;
            mem_arr[0+ii*4+3] = (ii==3) ? 8'hB8 : 8'h00;
            mem_arr[16+ii*4+0] = (ii==0) ? 8'h40 : 8'h00;
            mem_arr[16+ii*4+1] = (ii==1) ? 8'h40 : 8'h00;
            mem_arr[16+ii*4+2] = (ii==2) ? 8'h40 : 8'h00;
            mem_arr[16+ii*4+3] = (ii==3) ? 8'h40 : 8'h00;
        end
        precision = 2'b01; fire;
        raw = {mem_arr[512],mem_arr[513],mem_arr[514],mem_arr[515]};
        got = fp32_to_real(raw);
        if (got > -2.01 && got < -1.99) begin
            $display("PASS T4: FP8 -1.0x2.0=%f", got); pass=pass+1;
        end else begin
            $display("FAIL T4: FP8 -1.0x2.0=%f (bits=%h)", got, raw); fail=fail+1;
        end

        $display("Results: %0d/%0d passed", pass, pass+fail);
        if (fail==0) $display("ALL PASS"); else $display("FAILURES: %0d", fail);
        $finish;
    end

    initial #50_000_000 begin $display("TIMEOUT"); $finish; end
endmodule
