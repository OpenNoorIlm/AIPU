// uart_top.v — sends "AIPU OK\r\n" every second forever.
module uart_top (
    input  clk,
    output uart_tx_pin
);
    parameter CLK_FREQ  = 27_000_000;
    parameter BAUD_RATE = 115_200;

    // "AIPU OK\r\n" — 9 bytes
    localparam MSG_LEN = 9;
    reg [7:0] msg [0:MSG_LEN-1];
    initial begin
        msg[0] = 8'h41; msg[1] = 8'h49; msg[2] = 8'h50;
        msg[3] = 8'h55; msg[4] = 8'h20; msg[5] = 8'h4F;
        msg[6] = 8'h4B; msg[7] = 8'h0D; msg[8] = 8'h0A;
    end

    // Power-on reset: hold reset HIGH for 8 cycles
    reg [2:0] rst_cnt = 0;
    reg       reset   = 1;
    always @(posedge clk) begin
        if (rst_cnt < 7) begin rst_cnt <= rst_cnt + 1; reset <= 1; end
        else reset <= 0;
    end

    // 1-second boot delay
    reg [24:0] boot_cnt  = 0;
    reg        boot_done = 0;
    always @(posedge clk) begin
        if (!reset && !boot_done) begin
            if (boot_cnt == CLK_FREQ - 1) boot_done <= 1;
            else boot_cnt <= boot_cnt + 1;
        end
    end

    // uart_tx signals
    reg  [7:0] tx_data  = 0;
    reg        tx_valid = 0;
    wire       tx_busy;

    uart_tx #(.CLK_FREQ(CLK_FREQ), .BAUD_RATE(BAUD_RATE)) u_tx (
        .clk(clk), .reset(reset),
        .data(tx_data), .valid(tx_valid),
        .tx(uart_tx_pin), .busy(tx_busy)
    );

    // State machine
    localparam S_BOOT = 3'd0;
    localparam S_SEND = 3'd1;
    localparam S_WAIT = 3'd2;  // wait for busy to go HIGH
    localparam S_DONE = 3'd3;  // wait for busy to go LOW
    localparam S_GAP  = 3'd4;

    reg [2:0]  state   = S_BOOT;
    reg [3:0]  msg_idx = 0;
    reg [24:0] gap_cnt = 0;

    always @(posedge clk) begin
        tx_valid <= 0;
        if (reset) begin
            state <= S_BOOT; msg_idx <= 0;
        end else begin
            case (state)
                S_BOOT: if (boot_done) begin msg_idx <= 0; state <= S_SEND; end

                S_SEND: begin
                    if (!tx_busy) begin
                        tx_data  <= msg[msg_idx];
                        tx_valid <= 1;
                        state    <= S_WAIT;
                    end
                end

                S_WAIT: begin  // give tx one cycle to assert busy
                    state <= S_DONE;
                end

                S_DONE: begin  // now wait for busy to fall
                    if (!tx_busy) begin
                        if (msg_idx < MSG_LEN - 1) begin
                            msg_idx <= msg_idx + 1;
                            state   <= S_SEND;
                        end else begin
                            gap_cnt <= 0; state <= S_GAP;
                        end
                    end
                end

                S_GAP: begin
                    if (gap_cnt < CLK_FREQ - 1) gap_cnt <= gap_cnt + 1;
                    else begin msg_idx <= 0; state <= S_SEND; end
                end
            endcase
        end
    end
endmodule
