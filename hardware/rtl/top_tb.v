/* verilator lint_off UNUSEDSIGNAL */
module top_tb;

    // inputs
    reg clk, reset;
    reg task_valid;
    reg [7:0]  task_id;
    reg [31:0] task_cycles;

    // outputs
    wire task_accepted;
    wire queue_full;
    wire [3:0] queue_count;
    wire mem_done;
    wire uart_tx_pin;

    // mem control inputs (tied to defaults)
    reg        mem_start     = 0;
    reg [0:0]  mem_chain_row = 0;
    reg [0:0]  mem_chain_col = 0;
    reg [9:0]  mem_src_addr  = 0;
    reg [9:0]  mem_dst_addr  = 512;
    reg [31:0] mem_num_rows  = 32'd4;

    // SRAM interface
    wire [9:0] sram_rd_addr;
    wire [9:0] sram_wr_addr;
    wire       sram_wr_en;
    wire [7:0] sram_wr_data;
    reg  [7:0] sram_rd_data;

    // simple SRAM model
    reg [7:0] sram [0:1023];

    // serve reads combinationally
    always @(*) sram_rd_data = sram[sram_rd_addr];

    // serve writes on clock edge
    always @(posedge clk)
        if (sram_wr_en)
            sram[sram_wr_addr] <= sram_wr_data;

    // instantiate top
    top #(
        .G(2), .C(2), .N(4),
        .QDEPTH(8), .SRAM_DEPTH(1024)
    ) dut (
        .clk          (clk),
        .reset        (reset),
        .task_valid   (task_valid),
        .task_id      (task_id),
        .task_cycles  (task_cycles),
        .task_accepted(task_accepted),
        .queue_full   (queue_full),
        .queue_count  (queue_count),
        .sram_rd_addr (sram_rd_addr),
        .sram_wr_addr (sram_wr_addr),
        .sram_wr_en   (sram_wr_en),
        .sram_wr_data (sram_wr_data),
        .sram_rd_data (sram_rd_data),
        .mem_start    (mem_start),
        .mem_chain_row(mem_chain_row),
        .mem_chain_col(mem_chain_col),
        .mem_src_addr (mem_src_addr),
        .mem_dst_addr (mem_dst_addr),
        .mem_num_rows (mem_num_rows),
        .mem_done     (mem_done),
        .uart_tx_pin  (uart_tx_pin)
    );

    // clock -- blocking assignment is intentional for clock gen
    /* verilator lint_off BLKSEQ */
    always #5 clk = ~clk;
    /* verilator lint_on BLKSEQ */

    // task helper
    task push_task(input [7:0] id, input [31:0] cycles);
        task_valid  = 1;
        task_id     = id;
        task_cycles = cycles;
        @(posedge clk);
        #1;
        task_valid = 0;
    endtask

    integer i;

    initial begin
        $dumpfile("top_tb.vcd");
        $dumpvars(0, top_tb);

        // init
        clk         = 0;
        reset       = 1;
        task_valid  = 0;
        task_id     = 0;
        task_cycles = 0;

        // fill SRAM with test data
        for (i = 0; i < 1024; i = i + 1)
            sram[i] = i[7:0];

        // hold reset
        repeat(4) @(posedge clk);
        reset = 0;
        repeat(2) @(posedge clk);

        // push 3 tasks
        push_task(8'd1, 32'd20);
        repeat(2) @(posedge clk);

        push_task(8'd2, 32'd15);
        repeat(2) @(posedge clk);

        push_task(8'd3, 32'd10);
        repeat(2) @(posedge clk);

        // push 4th when queue has space
        push_task(8'd4, 32'd25);

        // wait for all tasks to complete
        repeat(200) @(posedge clk);

        $finish;
    end

    // monitor -- use negedge to avoid reset/sync conflict
    always @(negedge clk) begin
        if (!reset)
            $display("time=%0t | accepted=%0b | queue=%0d | full=%0b",
                      $time, task_accepted, queue_count, queue_full);
    end

endmodule
