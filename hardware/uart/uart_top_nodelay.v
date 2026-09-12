// uart_top_nodelay.v — NO boot delay, transmits "AIPU OK\r\n" immediately and continuously
module uart_top (
    input  clk,
    output uart_tx_pin
);
    parameter CLK_FREQ  = 27_000_000;
    parameter BAUD_RATE = 115_200;
    localparam CLKS_PER_BIT = CLK_FREQ / BAUD_RATE;

    localparam MSG_LEN = 9;
    reg [7:0] msg [0:MSG_LEN-1];
    initial begin
        msg[0] = 8'h41; msg[1] = 8'h49; msg[2] = 8'h50; msg[3] = 8'h55;
        msg[4] = 8'h20; msg[5] = 8'h4F; msg[6] = 8'h4B;
        msg[7] = 8'h0D; msg[8] = 8'h0A;
    end

    reg [7:0]  shift_reg = 8'hFF;
    reg [31:0] clk_cnt   = 0;
    reg [3:0]  bit_idx   = 0;
    reg [3:0]  msg_idx   = 0;
    reg        tx_reg    = 1;
    reg [1:0]  state     = 0; // 0=START 1=DATA 2=STOP 3=NEXT

    assign uart_tx_pin = tx_reg;

    always @(posedge clk) begin
        case (state)
            0: begin // START BIT
                tx_reg  <= 0;
                shift_reg <= msg[msg_idx];
                if (clk_cnt < CLKS_PER_BIT-1) clk_cnt <= clk_cnt + 1;
                else begin clk_cnt <= 0; bit_idx <= 0; state <= 1; end
            end
            1: begin // DATA BITS
                tx_reg <= shift_reg[bit_idx];
                if (clk_cnt < CLKS_PER_BIT-1) clk_cnt <= clk_cnt + 1;
                else begin
                    clk_cnt <= 0;
                    if (bit_idx < 7) bit_idx <= bit_idx + 1;
                    else state <= 2;
                end
            end
            2: begin // STOP BIT
                tx_reg <= 1;
                if (clk_cnt < CLKS_PER_BIT-1) clk_cnt <= clk_cnt + 1;
                else begin clk_cnt <= 0; state <= 3; end
            end
            3: begin // NEXT BYTE
                if (msg_idx < MSG_LEN-1) msg_idx <= msg_idx + 1;
                else msg_idx <= 0;
                state <= 0;
            end
        endcase
    end
endmodule
