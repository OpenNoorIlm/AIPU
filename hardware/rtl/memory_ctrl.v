/* verilator lint_off UNUSEDPARAM */
/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off WIDTHTRUNC */
module memory_ctrl #(
    parameter N          = 4,
    parameter G          = 2,
    parameter C          = 2,
    parameter SRAM_DEPTH = 1024,
    parameter SRAM_WIDTH = 8
)(
    input clk,
    input reset,
    output reg [$clog2(SRAM_DEPTH)-1:0] sram_rd_addr,
    output reg [$clog2(SRAM_DEPTH)-1:0] sram_wr_addr,
    output reg        sram_wr_en,
    output reg [7:0]  sram_wr_data,
    input      [7:0]  sram_rd_data,
    output reg [7:0] a_in[0:G-1][0:N-1],
    output reg [7:0] b_in[0:G-1][0:N-1],
    output reg [7:0] next_a_in[0:G-1][0:C-1][0:N-1],
    output reg [7:0] next_b_in[0:G-1][0:C-1][0:N-1],
    input [31:0] out[0:G-1][0:G-1][0:C-1][0:N-1][0:N-1],

    // dispatcher interface
    input             start,
    input  [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] chain_row,
    input  [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] chain_col,
    input  [$clog2(SRAM_DEPTH)-1:0] src_addr,
    input  [$clog2(SRAM_DEPTH)-1:0] dst_addr,
    input  [31:0]     num_rows,
    output reg        done
);

    localparam IDLE    = 2'd0;
    localparam LOAD    = 2'd1;
    localparam COMPUTE = 2'd2;
    localparam STORE   = 2'd3;

    reg [1:0]  state;
    reg [$clog2(N)-1:0]           row_counter;   // max N-1
    reg [$clog2(C*N*N+1)-1:0]     col_counter;   // max C*N*N-1
    reg [$clog2(C*32+1)-1:0]      tile_counter;  // max C*num_rows-1 (num_rows<=32)
    reg [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] sel_row;
    reg [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] sel_col;

    always @(posedge clk) begin
        if (reset) begin
            state        <= IDLE;
            done         <= 0;
            sram_wr_en   <= 0;
            sram_rd_addr <= 0;
            sram_wr_addr <= 0;
            row_counter  <= 0;
            col_counter  <= 0;
            tile_counter <= 0;
            sel_row      <= 0;
            sel_col      <= 0;
        end else begin
            case (state)

                IDLE: begin
                    done <= 0;
                    if (start) begin
                        sel_row      <= chain_row;
                        sel_col      <= chain_col;
                        sram_rd_addr <= src_addr;
                        sram_wr_addr <= dst_addr;
                        row_counter  <= 0;
                        col_counter  <= 0;
                        tile_counter <= 0;
                        state        <= LOAD;
                    end
                end

                LOAD: begin
                    a_in[sel_row][row_counter[($clog2(N)-1):0]] <= sram_rd_data;
                    b_in[sel_col][row_counter[($clog2(N)-1):0]] <= sram_rd_data;

                    if (tile_counter < C) begin
                        next_a_in[sel_row][tile_counter][row_counter[($clog2(N)-1):0]] <= sram_rd_data;
                        next_b_in[sel_col][tile_counter][row_counter[($clog2(N)-1):0]] <= sram_rd_data;
                    end

                    sram_rd_addr <= sram_rd_addr + 1;
                    row_counter  <= row_counter + 1;

                    if (row_counter >= N - 1) begin
                        row_counter  <= 0;
                        tile_counter <= tile_counter + 1;
                        if (tile_counter >= C * num_rows - 1)
                            state <= COMPUTE;
                    end
                end

                COMPUTE: begin
                    state <= STORE;
                end

                STORE: begin
                    sram_wr_data <= out[sel_row][sel_col]
                                       [col_counter / (N*N)]
                                       [(col_counter % (N*N)) / N]
                                       [col_counter % N][7:0];
                    sram_wr_en   <= 1;
                    sram_wr_addr <= sram_wr_addr + 1;
                    col_counter  <= col_counter + 1;

                    if (col_counter >= C*N*N - 1) begin
                        sram_wr_en  <= 0;
                        col_counter <= 0;
                        done        <= 1;
                        state       <= IDLE;
                    end
                end

            endcase
        end
    end
endmodule
