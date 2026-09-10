/* verilator lint_off UNUSEDSIGNAL */
module top_fpga(
    input  clk,        // H11 -- 27MHz oscillator
    input  reset,      // C14 -- button
    output uart_tx_pin // T13 -- to ESP32 RX
);
    reg        task_valid   = 0;
    reg [7:0]  task_id      = 8'd1;
    reg [31:0] task_cycles  = 32'd50;
    reg        mem_start    = 0;
    reg [0:0]  mem_chain_row = 0;
    reg [0:0]  mem_chain_col = 0;
    reg [9:0]  mem_src_addr  = 0;
    reg [9:0]  mem_dst_addr  = 512;
    reg [31:0] mem_num_rows  = 32'd4;

    reg [7:0] sram [0:1023];
    reg [9:0] sram_rd_addr;
    wire [9:0] sram_wr_addr;
    wire       sram_wr_en;
    wire [7:0] sram_wr_data;
    wire [7:0] sram_rd_data;

    reg [10:0] k;
    initial begin
        for (k = 0; k < 1024; k = k + 1)
            sram[k] = k[7:0];
    end

    assign sram_rd_data = sram[sram_rd_addr];

    always @(posedge clk) begin
        if (sram_wr_en)
            sram[sram_wr_addr] <= sram_wr_data;
    end

    // 2-second boot delay so ESP32 Serial2 is ready before UART output
    reg [25:0] startup_cnt = 0;
    localparam BOOT_DELAY  = 26'd54_000_000; // 2s at 27MHz

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            startup_cnt <= 0;
            task_valid  <= 0;
            mem_start   <= 0;
        end else begin
            if (startup_cnt < BOOT_DELAY)
                startup_cnt <= startup_cnt + 1;

            if (startup_cnt == BOOT_DELAY)       task_valid <= 1;
            if (startup_cnt == BOOT_DELAY + 1)   task_valid <= 0;
            if (startup_cnt == BOOT_DELAY + 10)  mem_start  <= 1;
            if (startup_cnt == BOOT_DELAY + 11)  mem_start  <= 0;
        end
    end

    wire task_accepted;
    wire queue_full;
    wire [3:0] queue_count;
    wire mem_done;

    top #(
        .G(1), .C(1), .N(4),
        .QDEPTH(8),
        .SRAM_DEPTH(1024),
        .CLK_FREQ(27_000_000),
        .BAUD_RATE(115_200)
    ) aipu (
        .clk(clk),
        .reset(reset),
        .task_valid(task_valid),
        .task_id(task_id),
        .task_cycles(task_cycles),
        .task_accepted(task_accepted),
        .queue_full(queue_full),
        .queue_count(queue_count),
        .mem_start(mem_start),
        .mem_chain_row(mem_chain_row),
        .mem_chain_col(mem_chain_col),
        .mem_src_addr(mem_src_addr),
        .mem_dst_addr(mem_dst_addr),
        .mem_num_rows(mem_num_rows),
        .mem_done(mem_done),
        .sram_rd_addr(sram_rd_addr),
        .sram_wr_addr(sram_wr_addr),
        .sram_wr_en(sram_wr_en),
        .sram_wr_data(sram_wr_data),
        .sram_rd_data(sram_rd_data),
        .uart_tx_pin(uart_tx_pin)
    );
endmodule
