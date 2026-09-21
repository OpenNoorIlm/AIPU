/* verilator lint_off UNUSEDPARAM */
/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off WIDTHTRUNC */
/* verilator lint_off CASEINCOMPLETE */
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
    // IDLE    - wait for start
    // CLEAR   - pulse mac_reset=1 for 1 cycle (zeros all accumulators)
    // LOAD_A  - read N bytes (column k of A) from SRAM into a_buf (N cycles)
    //           A is stored column-major: col k starts at src_addr + k*N
    // LOAD_B  - read N bytes (row k of B) from SRAM into b_buf (N cycles)
    //           B is stored row-major: row k starts at src_addr + N*N + k*N
    // PRESENT - skewed input feeding: cycle i presents a_buf[i], b_buf[i]
    //           exits after N+1 cycles so last input is safely registered
    // DRAIN   - zero inputs, wait N+1 cycles for pipeline latency
    //           then: if k_iter < N-1 → increment k, go back to LOAD_A (no reset)
    //                 if k_iter == N-1 → STORE (N outer products accumulated)
    // STORE   - write N*N INT32 results big-endian to SRAM[dst_addr]
    localparam IDLE    = 3'd0;
    localparam CLEAR   = 3'd1;
    localparam LOAD_A  = 3'd2;
    localparam LOAD_B  = 3'd3;
    localparam PRESENT = 3'd4;
    localparam DRAIN   = 3'd5;
    localparam STORE   = 3'd6;

    reg [2:0]  state;
    reg [$clog2(N+1)-1:0]          row_counter;
    reg [$clog2(N*N)-1:0]          mac_idx;
    reg [1:0]                       byte_sel;
    reg [$clog2(N*N*4+1)-1:0]      col_counter;
    reg [$clog2(2*N+1)-1:0]         drain_cnt;
    reg [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] sel_row;
    reg [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] sel_col;
    reg [$clog2(SRAM_DEPTH)-1:0]   dst_latch;
    reg [$clog2(SRAM_DEPTH)-1:0]   src_latch;   // latched src_addr for k-loop use
    reg [$clog2(N+1)-1:0]          k_iter;       // outer product iteration 0..N-1

    // Pre-load buffers — hold full vectors before presenting to array
    reg [7:0] a_buf [0:N-1];
    reg [7:0] b_buf [0:N-1];

    wire [31:0] cur_out = out[sel_row][sel_col][0]
                             [mac_idx[$clog2(N*N)-1:$clog2(N)]]
                             [mac_idx[$clog2(N)-1:0]];
    assign sram_wr_data = (byte_sel == 2'd0) ? cur_out[31:24] :
                          (byte_sel == 2'd1) ? cur_out[23:16] :
                          (byte_sel == 2'd2) ? cur_out[15:8]  :
                                               cur_out[7:0];

    always @(posedge clk) begin
        if (reset) begin
            state        <= IDLE;
            done         <= 0;
            mac_reset    <= 0;
            sram_wr_en   <= 0;
            sram_rd_addr <= 0;
            sram_wr_addr <= 0;
            row_counter  <= 0;
            col_counter  <= 0;
            drain_cnt    <= 0;
            mac_idx      <= 0;
            byte_sel     <= 0;
            sel_row      <= 0;
            sel_col      <= 0;
            dst_latch    <= 0;
            src_latch    <= 0;
            k_iter       <= 0;
            // zero all a_in and b_in across all G rows/cols
            begin : reset_zero
                integer ri, ni;
                for (ri = 0; ri < G; ri = ri + 1)
                    for (ni = 0; ni < N; ni = ni + 1) begin
                        a_in[ri][ni] <= 0;
                        b_in[ri][ni] <= 0;
                    end
            end
        end else begin
            case (state)

                IDLE: begin
                    done       <= 0;
                    mac_reset  <= 0;
                    sram_wr_en <= 0;
                    // Keep all a_in/b_in at zero while idle
                    begin : idle_zero
                        integer ri, ni;
                        for (ri = 0; ri < G; ri = ri + 1)
                            for (ni = 0; ni < N; ni = ni + 1) begin
                                a_in[ri][ni] <= 0;
                                b_in[ri][ni] <= 0;
                            end
                    end
                    if (start) begin
                        sel_row      <= chain_row;
                        sel_col      <= chain_col;
                        dst_latch    <= dst_addr;
                        src_latch    <= src_addr;
                        sram_wr_addr <= dst_addr;
                        sram_rd_addr <= src_addr;  // col 0 of A = src_addr + 0*N
                        row_counter  <= 0;
                        col_counter  <= 0;
                        drain_cnt    <= 0;
                        mac_idx      <= 0;
                        byte_sel     <= 0;
                        k_iter       <= 0;
                        state        <= CLEAR;
                    end
                end

                // Pulse mac_reset=1 for 1 cycle — zeros all MAC accumulators.
                // Also prime the SRAM address for col 0 of A.
                // SRAM has 1-cycle read latency: address set this cycle →
                // data valid NEXT cycle. So we set sram_rd_addr here and spend
                // one extra "addr settle" cycle in LOAD_A before reading.
                CLEAR: begin
                    mac_reset    <= 1;
                    row_counter  <= 0;
                    // Set address for col k_iter of A: src_latch + k_iter*N
                    // (k_iter=0 on first call, or already set when looping back)
                    sram_rd_addr <= src_latch + k_iter * N;
                    state        <= LOAD_A;
                end

                // Read N bytes = column k_iter of A into a_buf.
                // Cycle 0: sram_rd_data is valid (address was set in CLEAR or DRAIN).
                //          Store byte 0, advance address to byte 1.
                // Cycle 1: sram_rd_data = byte 1 → store, advance address.
                // ...
                // Cycle N-1: store last byte, then set address for row k_iter of B.
                LOAD_A: begin
                    mac_reset <= 0;
                    // Store the byte that came back from the address we set last cycle
                    a_buf[row_counter[$clog2(N)-1:0]] <= sram_rd_data;
                    if (row_counter < N - 1) begin
                        sram_rd_addr <= sram_rd_addr + 1;
                        row_counter  <= row_counter + 1;
                    end else begin
                        row_counter  <= 0;
                        // Set address for row k_iter of B; data valid next cycle
                        sram_rd_addr <= src_latch + N*N + k_iter*N;
                        state        <= LOAD_B;
                    end
                end

                // Read N bytes = row k_iter of B into b_buf.
                // Same 1-cycle-latency convention as LOAD_A.
                LOAD_B: begin
                    b_buf[row_counter[$clog2(N)-1:0]] <= sram_rd_data;
                    if (row_counter < N - 1) begin
                        sram_rd_addr <= sram_rd_addr + 1;
                        row_counter  <= row_counter + 1;
                    end else begin
                        row_counter <= 0;
                        drain_cnt   <= 0;
                        state       <= PRESENT;
                    end
                end

                // PRESENT: skewed input feeding.
                // Cycle 0: a_in[0]=a_buf[0], b_in[0]=b_buf[0], rest=0
                // Cycle 1: a_in[1]=a_buf[1], b_in[1]=b_buf[1], rest=0
                // ...
                // Cycle N-1: a_in[N-1]=a_buf[N-1], b_in[N-1]=b_buf[N-1]
                // This way MAC[i][j] sees a_buf[i] (entered at cycle i,
                // shifts right j columns, arrives at cycle i+j) and b_buf[j]
                // (entered at cycle j, shifts down i rows, arrives at cycle i+j).
                // Each MAC accumulates exactly once.
                PRESENT: begin
                    // Skewed input: only one a/b pair is non-zero per cycle.
                    // drain_cnt==0: present a[0],b[0]; drain_cnt==1: a[1],b[1]; etc.
                    // Exit after drain_cnt==N (one cycle AFTER the last input),
                    // so index N-1 is NOT overridden by the zero-clear on exit.
                    a_in[sel_row][0] <= (drain_cnt == 0) ? a_buf[0] : 8'd0;
                    a_in[sel_row][1] <= (drain_cnt == 1) ? a_buf[1] : 8'd0;
                    a_in[sel_row][2] <= (drain_cnt == 2) ? a_buf[2] : 8'd0;
                    a_in[sel_row][3] <= (drain_cnt == 3) ? a_buf[3] : 8'd0;
                    b_in[sel_col][0] <= (drain_cnt == 0) ? b_buf[0] : 8'd0;
                    b_in[sel_col][1] <= (drain_cnt == 1) ? b_buf[1] : 8'd0;
                    b_in[sel_col][2] <= (drain_cnt == 2) ? b_buf[2] : 8'd0;
                    b_in[sel_col][3] <= (drain_cnt == 3) ? b_buf[3] : 8'd0;
                    drain_cnt <= drain_cnt + 1;
                    // Exit one cycle AFTER last input (drain_cnt==N, not N-1)
                    // so the last a/b values are registered before state changes
                    if (drain_cnt >= N) begin
                        drain_cnt <= 0;
                        state     <= DRAIN;
                    end
                end

                // Exact pipeline latency from last skewed input to valid out[i][j]:
                // - a_in[i] presented at PRESENT cycle i, reaches MAC[i][j] after j more clocks
                // - b_in[j] presented at PRESENT cycle j, reaches MAC[i][j] after i more clocks
                // - Deepest path: MAC[N-1][N-1], last input at cycle N-1, both arrive at
                //   cycle (N-1)+(N-1) = 2N-2 from PRESENT start = N-1 cycles into DRAIN
                // - mac.out register: +1 cycle
                // - systolic out[i][j] <= mac_out register: +1 cycle
                // Total DRAIN cycles needed = (2N-2) - (N-1) + 2 = N+1
                // drain_cnt goes 0,1,...,N so exit when drain_cnt >= N
                DRAIN: begin
                    drain_cnt <= drain_cnt + 1;
                    if (drain_cnt >= 2*N - 1) begin
                        drain_cnt <= 0;
                        if (k_iter < N - 1) begin
                            // More outer products to accumulate — no mac_reset
                            k_iter       <= k_iter + 1;
                            row_counter  <= 0;
                            // Prime SRAM address for col (k_iter+1) of A.
                            // k_iter still holds OLD value here (non-blocking),
                            // so (k_iter+1)*N is correct for the next iteration.
                            sram_rd_addr <= src_latch + (k_iter + 1) * N;
                            state        <= LOAD_A;
                        end else begin
                            // All N outer products accumulated — write results
                            col_counter  <= 0;
                            mac_idx      <= 0;
                            byte_sel     <= 0;
                            sram_wr_addr <= dst_latch;
                            sram_wr_en   <= 1;
                            state        <= STORE;
                        end
                    end
                end

                // Write N*N INT32 results big-endian
                STORE: begin
                    sram_wr_en   <= 1;
                    col_counter  <= col_counter + 1;
                    sram_wr_addr <= sram_wr_addr + 1;
                    if (byte_sel == 2'd3) begin
                        byte_sel <= 0;
                        mac_idx  <= mac_idx + 1;
                    end else begin
                        byte_sel <= byte_sel + 1;
                    end
                    if (col_counter >= N*N*4 - 1) begin
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
