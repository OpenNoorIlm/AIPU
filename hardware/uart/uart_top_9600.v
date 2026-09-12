// uart_top.v
// Standalone FPGA top — sends "AIPU OK\r\n" every second forever.
// Uses uart_tx.v exactly as verified in simulation.
// Tang Primer 20K: clk=H11 (27MHz), uart_tx_pin=T13

module uart_top (
    input  clk,          // H11 — 27MHz
    output uart_tx_pin   // T13 — to ESP32 RX2 (GPIO16)
);

    parameter CLK_FREQ  = 27_000_000;
    parameter BAUD_RATE = 9_600;

    // "AIPU OK\r\n" — 9 bytes
    localparam MSG_LEN = 9;
    reg [7:0] msg [0:MSG_LEN-1];
    initial begin
        msg[0] = 8'h41; // A
        msg[1] = 8'h49; // I
        msg[2] = 8'h50; // P
        msg[3] = 8'h55; // U
        msg[4] = 8'h20; // (space)
        msg[5] = 8'h4F; // O
        msg[6] = 8'h4B; // K
        msg[7] = 8'h0D; // \r
        msg[8] = 8'h0A; // \n
    end

    // 1-second boot delay
    localparam BOOT_DELAY = CLK_FREQ;
    reg [24:0] boot_cnt  = 0;
    reg        boot_done = 0;
    always @(posedge clk) begin
        if (!boot_done) begin
            if (boot_cnt == BOOT_DELAY - 1)
                boot_done <= 1;
            else
                boot_cnt <= boot_cnt + 1;
        end
    end

    // 1-second gap between messages
    localparam GAP = CLK_FREQ;
    reg [24:0] gap_cnt = 0;

    // uart_tx signals
    reg  [7:0] tx_data  = 0;
    reg        tx_valid = 0;
    wire       tx_busy;

    uart_tx #(
        .CLK_FREQ(CLK_FREQ),
        .BAUD_RATE(BAUD_RATE)
    ) u_tx (
        .clk(clk),
        .reset(1'b0),
        .data(tx_data),
        .valid(tx_valid),
        .tx(uart_tx_pin),
        .busy(tx_busy)
    );

    // State machine
    localparam S_BOOT = 2'd0;
    localparam S_SEND = 2'd1;
    localparam S_TICK = 2'd2;
    localparam S_GAP  = 2'd3;

    reg [1:0] state   = S_BOOT;
    reg [3:0] msg_idx = 0;

    always @(posedge clk) begin
        tx_valid <= 0;

        case (state)
            S_BOOT: begin
                if (boot_done) begin
                    msg_idx <= 0;
                    state   <= S_SEND;
                end
            end

            // Load next byte and fire valid
            S_SEND: begin
                if (!tx_busy) begin
                    tx_data  <= msg[msg_idx];
                    tx_valid <= 1;
                    state    <= S_TICK;
                end
            end

            // Wait for tx to go busy then finish
            S_TICK: begin
                if (!tx_busy) begin
                    if (msg_idx < MSG_LEN - 1) begin
                        msg_idx <= msg_idx + 1;
                        state   <= S_SEND;
                    end else begin
                        gap_cnt <= 0;
                        state   <= S_GAP;
                    end
                end
            end

            // 1 second pause then repeat
            S_GAP: begin
                if (gap_cnt < GAP - 1)
                    gap_cnt <= gap_cnt + 1;
                else begin
                    msg_idx <= 0;
                    state   <= S_SEND;
                end
            end
        endcase
    end

endmodule
