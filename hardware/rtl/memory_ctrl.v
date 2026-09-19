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
    //           a_in/b_in are all zero at this point
    // LOAD_A  - read N bytes from SRAM into a_buf (N cycles)
    // LOAD_B  - read N bytes from SRAM into b_buf (N cycles)
    // PRESENT - assert all a_in and b_in simultaneously for exactly 1 cycle
    //           each MAC[i][j] computes a_buf[i]*b_buf[j] in this 1 cycle
    // DRAIN   - hold a_in=0, b_in=0 for N cycles so pipeline latency settles
    //           (MAC out register has 1-cycle latency from the multiply)
    // STORE   - write N*N INT32 results to SRAM
    localparam IDLE    = 3'd0;
    localparam CLEAR   = 3'd1;
    localparam LOAD_A  = 3'd2;
    localparam LOAD_B  = 3'd3;
    localparam PRESENT = 3'd4;
    localparam DRAIN   = 3'd5;
    localparam PRESENT_CYCLES = 2*N - 1; // hold inputs for full systolic propagation
    localparam STORE   = 3'd6;

    reg [2:0]  state;
    reg [$clog2(N+1)-1:0]          row_counter;
    reg [$clog2(N*N)-1:0]          mac_idx;
    reg [1:0]                       byte_sel;
    reg [$clog2(N*N*4+1)-1:0]      col_counter;
    reg [$clog2(N+2)-1:0]          drain_cnt;
    reg [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] sel_row;
    reg [($clog2(G) > 0 ? $clog2(G) : 1)-1:0] sel_col;
    reg [$clog2(SRAM_DEPTH)-1:0]   dst_latch;

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
            // zero a_in and b_in
            a_in[0][0] <= 0; a_in[0][1] <= 0; a_in[0][2] <= 0; a_in[0][3] <= 0;
            b_in[0][0] <= 0; b_in[0][1] <= 0; b_in[0][2] <= 0; b_in[0][3] <= 0;
        end else begin
            case (state)

                IDLE: begin
                    done       <= 0;
                    mac_reset  <= 0;
                    sram_wr_en <= 0;
                    // Keep a_in/b_in at zero while idle
                    a_in[0][0] <= 0; a_in[0][1] <= 0; a_in[0][2] <= 0; a_in[0][3] <= 0;
                    b_in[0][0] <= 0; b_in[0][1] <= 0; b_in[0][2] <= 0; b_in[0][3] <= 0;
                    if (start) begin
                        sel_row      <= chain_row;
                        sel_col      <= chain_col;
                        dst_latch    <= dst_addr;
                        sram_wr_addr <= dst_addr;
                        sram_rd_addr <= src_addr;
                        row_counter  <= 0;
                        col_counter  <= 0;
                        drain_cnt    <= 0;
                        mac_idx      <= 0;
                        byte_sel     <= 0;
                        state        <= CLEAR;
                    end
                end

                // Pulse mac_reset=1 for 1 cycle — zeros all MAC accumulators
                // a_in/b_in are already 0 (from IDLE), so no spurious accumulation
                CLEAR: begin
                    mac_reset    <= 1;
                    row_counter  <= 0;
                    // Issue first SRAM read: sram[src_addr] appears on rd_data next cycle
                    sram_rd_addr <= src_addr;
                    state        <= LOAD_A;
                end

                // Read N bytes into a_buf (N cycles)
                // Each cycle: rd_data = sram[src_addr + row_counter]
                LOAD_A: begin
                    mac_reset <= 0;
                    a_buf[row_counter[$clog2(N)-1:0]] <= sram_rd_data;
                    sram_rd_addr <= sram_rd_addr + 1;
                    row_counter  <= row_counter + 1;
                    if (row_counter >= N - 1) begin
                        row_counter <= 0;
                        // sram_rd_addr now = src_addr+N, pointing at B
                        state <= LOAD_B;
                    end
                end

                // Read N bytes into b_buf (N cycles)
                LOAD_B: begin
                    b_buf[row_counter[$clog2(N)-1:0]] <= sram_rd_data;
                    sram_rd_addr <= sram_rd_addr + 1;
                    row_counter  <= row_counter + 1;
                    if (row_counter >= N - 1) begin
                        row_counter <= 0;
                        state <= PRESENT;
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
                    if (drain_cnt >= N) begin
                        col_counter  <= 0;
                        mac_idx      <= 0;
                        byte_sel     <= 0;
                        sram_wr_addr <= dst_latch;
                        state        <= STORE;
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
