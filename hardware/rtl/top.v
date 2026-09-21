/* verilator lint_off UNUSEDSIGNAL */
module top #(
    parameter G          = 2,
    parameter C          = 2,
    parameter N          = 4,
    parameter QDEPTH     = 8,
    parameter SRAM_DEPTH = 1024,
    parameter CLK_FREQ   = 27_000_000,
    parameter BAUD_RATE  = 115_200
)(
    input clk,
    input reset,
    input  [1:0] precision,
    input         task_valid,
    input  [7:0]  task_id,
    input  [31:0] task_cycles,
    output        task_accepted,
    output        queue_full,
    output [$clog2(QDEPTH):0] queue_count,
    input                                          mem_start,
    input  [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] mem_chain_row,
    input  [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] mem_chain_col,
    input  [$clog2(SRAM_DEPTH)-1:0]               mem_src_addr,
    input  [$clog2(SRAM_DEPTH)-1:0]               mem_dst_addr,
    input  [31:0]                                  mem_num_rows,
    output                                         mem_done,
    output [$clog2(SRAM_DEPTH)-1:0] sram_rd_addr,
    output [$clog2(SRAM_DEPTH)-1:0] sram_wr_addr,
    output        sram_wr_en,
    output [7:0]  sram_wr_data,
    input  [7:0]  sram_rd_data,
    output uart_tx_pin
);
    wire enable[0:G-1][0:G-1];
    wire done  [0:G-1][0:G-1];
    wire [7:0] active_task[0:G-1][0:G-1];
    wire [7:0] a_in[0:G-1][0:N-1];
    wire [7:0] b_in[0:G-1][0:N-1];
    wire [7:0] next_a_in[0:G-1][0:C-1][0:N-1];
    wire [7:0] next_b_in[0:G-1][0:C-1][0:N-1];
    wire [31:0] grid_out[0:G-1][0:G-1][0:C-1][0:N-1][0:N-1];
    wire [7:0] a_out[0:G-1][0:N-1];
    wire [$clog2(SRAM_DEPTH)-1:0] mem_sram_rd_addr;
    wire [$clog2(SRAM_DEPTH)-1:0] rs_sram_rd_addr;
    wire mac_reset_w;

    reg rs_owns_sram = 0;
    always @(posedge clk)
        if (mem_start)     rs_owns_sram <= 0;
        else if (mem_done) rs_owns_sram <= 1;
    assign sram_rd_addr = rs_owns_sram ? rs_sram_rd_addr : mem_sram_rd_addr;

    dispatcher #(.G(G), .QDEPTH(QDEPTH)) disp(
        .clk(clk), .reset(reset),
        .task_valid(task_valid), .task_id(task_id),
        .task_cycles(task_cycles), .task_accepted(task_accepted),
        .queue_full(queue_full), .queue_count(queue_count),
        .enable(enable), .active_task(active_task), .done(done)
    );

    grid_GxG #(.G(G), .C(C), .N(N)) grid(
        .clk(clk), .reset(reset),
        .precision(precision),
        .in_out_reset(mac_reset_w ? 8'hFF : 8'h00),
        .a_in(a_in), .b_in(b_in),
        .next_a_in(next_a_in),
        .next_b_in(next_b_in),
        .enable(enable), .out(grid_out),
        .a_out(a_out), .done(done)
    );

    memory_ctrl #(.G(G), .C(C), .N(N), .SRAM_DEPTH(SRAM_DEPTH)) mem(
        .clk(clk), .reset(reset),
        .sram_rd_addr(mem_sram_rd_addr),
        .sram_wr_addr(sram_wr_addr),
        .sram_wr_en(sram_wr_en),
        .sram_wr_data(sram_wr_data),
        .sram_rd_data(sram_rd_data),
        .a_in(a_in), .b_in(b_in),
        .next_a_in(next_a_in),
        .next_b_in(next_b_in),
        .out(grid_out),
        .mac_reset(mac_reset_w),
        .start(mem_start),
        .chain_row(mem_chain_row),
        .chain_col(mem_chain_col),
        .src_addr(mem_src_addr),
        .dst_addr(mem_dst_addr),
        .num_rows(mem_num_rows),
        .done(mem_done)
    );

    result_sender #(
        .G(G), .C(C), .N(N),
        .CLK_FREQ(CLK_FREQ),
        .BAUD_RATE(BAUD_RATE),
        .SRAM_DEPTH(SRAM_DEPTH)
    ) rs(
        .clk(clk), .reset(reset),
        .mem_done(mem_done),
        .mem_dst_addr(mem_dst_addr),
        .sram_rd_data(sram_rd_data),
        .sram_rd_addr(rs_sram_rd_addr),
        .uart_tx_pin(uart_tx_pin)
    );
endmodule
