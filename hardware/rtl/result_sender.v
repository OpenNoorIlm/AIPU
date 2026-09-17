// ============================================================================
// Module: result_sender
// Sends boot message "AIPU OK\r\n" then on each mem_done:
//   outputs "RES:XX XX XX ... XX\r\n" (hex encoded, space separated)
//   where XX = low 8 bits of each MAC accumulator stored in SRAM
// SPDX-License-Identifier: CERN-OHL-S-2.0
// ============================================================================
module result_sender #(
    parameter N          = 4,
    parameter G          = 2,
    parameter C          = 2,
    parameter CLK_FREQ   = 27_000_000,
    parameter BAUD_RATE  = 115_200,
    parameter SRAM_DEPTH = 1024
)(
    input clk,
    input reset,
    input mem_done,
    input [$clog2(SRAM_DEPTH)-1:0] mem_dst_addr,
    input [7:0] sram_rd_data,
    output reg [$clog2(SRAM_DEPTH)-1:0] sram_rd_addr,
    output uart_tx_pin
);

    // ── UART TX ───────────────────────────────────────────────────────────────
    reg [7:0] tx_data;
    reg       tx_valid;
    wire      tx_busy;

    uart_tx #(
        .CLK_FREQ(CLK_FREQ),
        .BAUD_RATE(BAUD_RATE)
    ) uart(
        .clk(clk), .reset(reset),
        .data(tx_data), .valid(tx_valid),
        .tx(uart_tx_pin), .busy(tx_busy)
    );

    // ── Boot message: "AIPU OK\r\n" ──────────────────────────────────────────
    localparam BOOT_MSG_LEN = 9;
    reg [7:0] boot_msg [0:BOOT_MSG_LEN-1];
    initial begin
        boot_msg[0] = 8'h41; // 'A'
        boot_msg[1] = 8'h49; // 'I'
        boot_msg[2] = 8'h50; // 'P'
        boot_msg[3] = 8'h55; // 'U'
        boot_msg[4] = 8'h20; // ' '
        boot_msg[5] = 8'h4F; // 'O'
        boot_msg[6] = 8'h4B; // 'K'
        boot_msg[7] = 8'h0D; // '\r'
        boot_msg[8] = 8'h0A; // '\n'
    end

    // ── Header: "RES:" ───────────────────────────────────────────────────────
    localparam HDR_LEN = 4;
    reg [7:0] hdr_msg [0:HDR_LEN-1];
    initial begin
        hdr_msg[0] = 8'h52; // 'R'
        hdr_msg[1] = 8'h45; // 'E'
        hdr_msg[2] = 8'h53; // 'S'
        hdr_msg[3] = 8'h3A; // ':'
    end

    // ── Hex nibble lookup ────────────────────────────────────────────────────
    function [7:0] hex_char;
        input [3:0] nibble;
        begin
            if (nibble < 10) hex_char = 8'h30 + nibble; // '0'-'9'
            else             hex_char = 8'h41 + (nibble - 4'd10); // 'A'-'F'
        end
    endfunction

    // ── 1-second boot delay ──────────────────────────────────────────────────
    localparam BOOT_DELAY = CLK_FREQ;
    reg [25:0] boot_cnt  = 0;
    reg        boot_done = 0;
    always @(posedge clk) begin
        if (reset) begin
            boot_cnt  <= 0;
            boot_done <= 0;
        end else if (!boot_done) begin
            if (boot_cnt == BOOT_DELAY - 1)
                boot_done <= 1;
            else
                boot_cnt <= boot_cnt + 1;
        end
    end

    // ── State machine ─────────────────────────────────────────────────────────
    localparam S_BOOT_WAIT  = 4'd0;  // waiting for boot delay
    localparam S_BOOT_SEND  = 4'd1;  // sending boot message chars
    localparam S_BOOT_WAIT2 = 4'd2;  // wait for uart busy
    localparam S_IDLE       = 4'd3;  // waiting for mem_done
    localparam S_HDR_SEND   = 4'd4;  // sending "RES:" header
    localparam S_HDR_WAIT   = 4'd5;  // wait for header char
    localparam S_READ       = 4'd6;  // issue SRAM read
    localparam S_HI_SEND    = 4'd7;  // send high hex nibble
    localparam S_HI_WAIT    = 4'd8;  // wait for high nibble tx
    localparam S_LO_SEND    = 4'd9;  // send low hex nibble
    localparam S_LO_WAIT    = 4'd10; // wait for low nibble tx
    localparam S_SP_SEND    = 4'd11; // send space (or \r\n at end)
    localparam S_SP_WAIT    = 4'd12; // wait for space tx
    localparam S_EOL_R      = 4'd13; // send '\r'
    localparam S_EOL_N      = 4'd14; // send '\n'

    // Number of result bytes = C * N * N * 4 (4 bytes per INT32 accumulator)
    localparam RESULT_BYTES = C * N * N * 4;

    reg [3:0]  state;
    reg [3:0]  boot_idx;
    reg [3:0]  hdr_idx;
    reg [7:0]  byte_val;      // captured SRAM byte
    reg [7:0]  byte_count;    // which result byte we're on
    reg        mem_done_latch; // sticky: set on mem_done, cleared when S_IDLE sees it

    always @(posedge clk) begin
        if (reset) begin
            state          <= S_BOOT_WAIT;
            boot_idx       <= 0;
            hdr_idx        <= 0;
            byte_count     <= 0;
            sram_rd_addr   <= 0;
            tx_valid       <= 0;
            tx_data        <= 0;
            byte_val       <= 0;
            mem_done_latch <= 0;
        end else begin
            // Capture mem_done whenever it fires — even if we're mid-transmission
            if (mem_done) mem_done_latch <= 1;
            tx_valid <= 0; // default

            case (state)

                // ── Boot sequence ─────────────────────────────────────────────
                S_BOOT_WAIT: begin
                    if (boot_done) state <= S_BOOT_SEND;
                end

                S_BOOT_SEND: begin
                    if (!tx_busy) begin
                        tx_data  <= boot_msg[boot_idx];
                        tx_valid <= 1;
                        state    <= S_BOOT_WAIT2;
                    end
                end

                S_BOOT_WAIT2: begin
                    if (tx_busy) begin  // wait for uart to accept byte
                        if (boot_idx < BOOT_MSG_LEN - 1) begin
                            boot_idx <= boot_idx + 1;
                            state    <= S_BOOT_SEND;
                        end else begin
                            state <= S_IDLE;
                        end
                    end
                end

                // ── Idle — wait for computation result ────────────────────────
                S_IDLE: begin
                    byte_count   <= 0;
                    hdr_idx      <= 0;
                    sram_rd_addr <= mem_dst_addr; // read from where memory_ctrl wrote results
                    if (mem_done || mem_done_latch) begin
                        mem_done_latch <= 0;
                        state <= S_HDR_SEND;
                    end
                end

                // ── Send "RES:" header ────────────────────────────────────────
                S_HDR_SEND: begin
                    if (!tx_busy) begin
                        tx_data  <= hdr_msg[hdr_idx];
                        tx_valid <= 1;
                        state    <= S_HDR_WAIT;
                    end
                end

                S_HDR_WAIT: begin
                    if (tx_busy) begin
                        if (hdr_idx < HDR_LEN - 1) begin
                            hdr_idx <= hdr_idx + 1;
                            state   <= S_HDR_SEND;
                        end else begin
                            state <= S_READ;
                        end
                    end
                end

                // ── Read one SRAM byte ────────────────────────────────────────
                S_READ: begin
                    // one cycle read latency — capture next cycle
                    state <= S_HI_SEND;
                end

                // ── Send high nibble as hex char ──────────────────────────────
                S_HI_SEND: begin
                    byte_val <= sram_rd_data; // capture byte
                    if (!tx_busy) begin
                        tx_data  <= hex_char(sram_rd_data[7:4]);
                        tx_valid <= 1;
                        state    <= S_HI_WAIT;
                    end
                end

                S_HI_WAIT: begin
                    if (tx_busy) state <= S_LO_SEND;
                end

                // ── Send low nibble as hex char ───────────────────────────────
                S_LO_SEND: begin
                    if (!tx_busy) begin
                        tx_data  <= hex_char(byte_val[3:0]);
                        tx_valid <= 1;
                        state    <= S_LO_WAIT;
                    end
                end

                S_LO_WAIT: begin
                    if (tx_busy) begin
                        sram_rd_addr <= sram_rd_addr + 1;
                        byte_count   <= byte_count + 1;
                        if (byte_count >= RESULT_BYTES - 1)
                            state <= S_EOL_R;
                        else
                            state <= S_SP_SEND;
                    end
                end

                // ── Space between bytes ───────────────────────────────────────
                S_SP_SEND: begin
                    if (!tx_busy) begin
                        tx_data  <= 8'h20; // ' '
                        tx_valid <= 1;
                        state    <= S_SP_WAIT;
                    end
                end

                S_SP_WAIT: begin
                    if (tx_busy) state <= S_READ;
                end

                // ── End of line: \r\n ─────────────────────────────────────────
                S_EOL_R: begin
                    if (!tx_busy) begin
                        tx_data  <= 8'h0D; // '\r'
                        tx_valid <= 1;
                        state    <= S_EOL_N;
                    end
                end

                S_EOL_N: begin
                    if (!tx_busy) begin
                        tx_data  <= 8'h0A; // '\n'
                        tx_valid <= 1;
                        state    <= S_IDLE; // tx_busy goes high next cycle; S_IDLE waits
                    end
                end
                // Note: S_IDLE checks mem_done_latch so any mem_done that fired
                // during the \r\n transmission is not lost.

                default: state <= S_IDLE;

            endcase
        end
    end

endmodule
