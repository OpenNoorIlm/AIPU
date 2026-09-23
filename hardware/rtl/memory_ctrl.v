/* verilator lint_off UNUSEDPARAM */
/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off WIDTHTRUNC */
/* verilator lint_off CASEINCOMPLETE */
module memory_ctrl #(
    parameter N          = 4,
    parameter G          = 2,
    parameter C          = 2,
    parameter SRAM_DEPTH = 1024
)(
    input        clk,
    input        reset,
    input  [1:0] precision,
    output reg [$clog2(SRAM_DEPTH)-1:0] sram_rd_addr,
    output reg [$clog2(SRAM_DEPTH)-1:0] sram_wr_addr,
    output reg        sram_wr_en,
    output wire [7:0] sram_wr_data,
    input      [7:0]  sram_rd_data,
    output reg [7:0] a_in[0:G-1][0:N-1],
    output reg [7:0] b_in[0:G-1][0:N-1],
    output reg [7:0] next_a_in[0:G-1][0:C-1][0:N-1],
    output reg [7:0] next_b_in[0:G-1][0:C-1][0:N-1],
    input [31:0] out[0:G-1][0:G-1][0:C-1][0:N-1][0:N-1],
    output reg mac_reset,
    input             start,
    input  [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] chain_row,
    input  [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] chain_col,
    input  [$clog2(SRAM_DEPTH)-1:0] src_addr,
    input  [$clog2(SRAM_DEPTH)-1:0] dst_addr,
    input  [31:0]     num_rows,
    output reg        done
);
    // BF16 uses 2 bytes per operand; INT8/FP8 use 1 byte.
    // bytes_per_elem = (precision==BF16) ? 2 : 1
    wire bf16_mode = (precision == 2'b10);
    wire [9:0] bpe = bf16_mode ? 10'd2 : 10'd1;  // bytes per element

    localparam IDLE    = 3'd0;
    localparam CLEAR   = 3'd1;
    localparam LOAD_A  = 3'd2;
    localparam LOAD_B  = 3'd3;
    localparam PRESENT = 3'd4;
    localparam DRAIN   = 3'd5;
    localparam STORE   = 3'd6;
    localparam WAIT_RD = 3'd7;  // 1-cycle bubble after setting sram_rd_addr

    reg [2:0]  state;
    reg [$clog2(N+1)-1:0]     row_counter;
    reg [$clog2(N*N)-1:0]     mac_idx;
    reg [1:0]                  byte_sel;
    reg [$clog2(N*N*4+1)-1:0] col_counter;
    reg [$clog2(2*N+1)-1:0]   drain_cnt;
    reg [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] sel_row, sel_col;
    reg [$clog2(SRAM_DEPTH)-1:0] dst_latch, src_latch;
    reg [$clog2(N+1)-1:0] k_iter;

    // BF16 needs 2-byte load: high byte first, then low byte
    reg load_hi;      // 1 = waiting for high byte, 0 = waiting for low byte
    reg wait_rd_next; // 0 = go to LOAD_A after WAIT_RD, 1 = go to LOAD_B

    reg [7:0] a_buf [0:N-1];
    reg [7:0] b_buf [0:N-1];
    reg [7:0]  hi_byte;  // temp for BF16 high byte

    wire [31:0] cur_out = out[sel_row][sel_col][0]
                             [mac_idx[$clog2(N*N)-1:$clog2(N)]]
                             [mac_idx[$clog2(N)-1:0]];
    assign sram_wr_data = (byte_sel == 2'd0) ? cur_out[31:24] :
                          (byte_sel == 2'd1) ? cur_out[23:16] :
                          (byte_sel == 2'd2) ? cur_out[15:8]  :
                                               cur_out[7:0];

    always @(posedge clk) begin
        if (reset) begin
            state <= IDLE; done <= 0; mac_reset <= 0; sram_wr_en <= 0;
            sram_rd_addr <= 0; sram_wr_addr <= 0;
            row_counter <= 0; col_counter <= 0; drain_cnt <= 0;
            mac_idx <= 0; byte_sel <= 0; sel_row <= 0; sel_col <= 0;
            dst_latch <= 0; src_latch <= 0; k_iter <= 0; load_hi <= 1;
            wait_rd_next <= 0;
            begin : reset_zero
                integer ri, ni;
                for (ri=0; ri<G; ri=ri+1)
                    for (ni=0; ni<N; ni=ni+1) begin
                        a_in[ri][ni] <= 0; b_in[ri][ni] <= 0;
                    end
            end
        end else begin
            case (state)

                IDLE: begin
                    done <= 0; mac_reset <= 0; sram_wr_en <= 0;
                    begin : idle_zero
                        integer ri, ni;
                        for (ri=0; ri<G; ri=ri+1)
                            for (ni=0; ni<N; ni=ni+1) begin
                                a_in[ri][ni] <= 0; b_in[ri][ni] <= 0;
                            end
                    end
                    if (start) begin
                        sel_row <= chain_row; sel_col <= chain_col;
                        dst_latch <= dst_addr; src_latch <= src_addr;
                        sram_wr_addr <= dst_addr;
                        sram_rd_addr <= src_addr;
                        row_counter <= 0; col_counter <= 0; drain_cnt <= 0;
                        mac_idx <= 0; byte_sel <= 0; k_iter <= 0; load_hi <= 1;
                        state <= CLEAR;
                    end
                end

                CLEAR: begin
                    mac_reset <= 1;
                    row_counter <= 0; load_hi <= 1;
                    sram_rd_addr <= src_latch + k_iter * N * bpe;
                    wait_rd_next <= 0;  // after wait, go to LOAD_A
                    state <= WAIT_RD;
                end

                WAIT_RD: begin
                    mac_reset <= 0;
                    state <= wait_rd_next ? LOAD_B : LOAD_A;
                end

                LOAD_A: begin
                    mac_reset <= 0;
                    if (bf16_mode) begin
                        // BF16: 2 SRAM reads per element.
                        // load_hi=1: current sram_rd_data is hi byte. Save it, inc addr, load_hi=0.
                        // load_hi=0: current sram_rd_data is lo byte. Save {hi,lo}. If more elements,
                        //            inc addr and row_counter, load_hi=1. Else switch to LOAD_B.
                        if (load_hi) begin
                            hi_byte      <= sram_rd_data;
                            sram_rd_addr <= sram_rd_addr + 1;
                            load_hi      <= 0;
                        end else begin
                            a_buf[row_counter[$clog2(N)-1:0]] <= sram_rd_data;
                            if (row_counter < N-1) begin
                                sram_rd_addr <= sram_rd_addr + 1;
                                row_counter  <= row_counter + 1;
                                load_hi      <= 1;
                            end else begin
                                row_counter  <= 0;
                                load_hi      <= 1;
                                sram_rd_addr <= src_latch + N*N*bpe + k_iter*N*bpe;
                                wait_rd_next <= 1;  // after wait, go to LOAD_B
                                state        <= WAIT_RD;
                            end
                        end
                    end else begin
                        a_buf[row_counter[$clog2(N)-1:0]] <= {8'h00, sram_rd_data};
                        if (row_counter < N-1) begin
                            sram_rd_addr <= sram_rd_addr + 1;
                            row_counter  <= row_counter + 1;
                        end else begin
                            row_counter  <= 0;
                            sram_rd_addr <= src_latch + N*N*bpe + k_iter*N*bpe;
                            wait_rd_next <= 1;
                            state        <= WAIT_RD;
                        end
                    end
                end

                LOAD_B: begin
                    if (bf16_mode) begin
                        if (load_hi) begin
                            hi_byte      <= sram_rd_data;
                            sram_rd_addr <= sram_rd_addr + 1;
                            load_hi      <= 0;
                        end else begin
                            b_buf[row_counter[$clog2(N)-1:0]] <= sram_rd_data;
                            if (row_counter < N-1) begin
                                sram_rd_addr <= sram_rd_addr + 1;
                                row_counter  <= row_counter + 1;
                                load_hi      <= 1;
                            end else begin
                                row_counter <= 0;
                                load_hi     <= 1;
                                drain_cnt   <= 0;
                                state       <= PRESENT;
                            end
                        end
                    end else begin
                        b_buf[row_counter[$clog2(N)-1:0]] <= {8'h00, sram_rd_data};
                        if (row_counter < N-1) begin
                            sram_rd_addr <= sram_rd_addr + 1;
                            row_counter  <= row_counter + 1;
                        end else begin
                            row_counter <= 0; drain_cnt <= 0;
                            state <= PRESENT;
                        end
                    end
                end

                PRESENT: begin
                    begin : present_loop
                        integer pi;
                        for (pi = 0; pi < N; pi = pi + 1) begin
                            a_in[sel_row][pi] <= (drain_cnt == pi[$clog2(N)-1:0]) ? a_buf[pi] : 8'd0;
                            b_in[sel_col][pi] <= (drain_cnt == pi[$clog2(N)-1:0]) ? b_buf[pi] : 8'd0;
                        end
                    end
                    drain_cnt <= drain_cnt + 1;
                    if (drain_cnt >= N) begin
                        drain_cnt <= 0; state <= DRAIN;
                    end
                end

                DRAIN: begin
                    drain_cnt <= drain_cnt + 1;
                    if (drain_cnt >= 2*N - 1) begin
                        drain_cnt <= 0;
                        if (k_iter < N-1) begin
                            k_iter <= k_iter + 1; row_counter <= 0; load_hi <= 1;
                            sram_rd_addr <= src_latch + (k_iter+1)*N*bpe;
                            wait_rd_next <= 0;
                            state <= WAIT_RD;
                        end else begin
                            col_counter <= 0; mac_idx <= 0; byte_sel <= 0;
                            sram_wr_addr <= dst_latch; sram_wr_en <= 1;
                            state <= STORE;
                        end
                    end
                end

                STORE: begin
                    sram_wr_en <= 1;
                    col_counter <= col_counter + 1;
                    sram_wr_addr <= sram_wr_addr + 1;
                    if (byte_sel == 2'd3) begin byte_sel <= 0; mac_idx <= mac_idx + 1; end
                    else byte_sel <= byte_sel + 1;
                    if (col_counter >= N*N*4 - 1) begin
                        sram_wr_en <= 0; col_counter <= 0; done <= 1; state <= IDLE;
                    end
                end

            endcase
        end
    end
endmodule
