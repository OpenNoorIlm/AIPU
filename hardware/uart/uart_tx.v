/* verilator lint_off WIDTHEXPAND */
// uart_tx.v  —  8N1 UART transmitter
// Pulse valid=1 for ONE cycle with data on `data` to send a byte.
// busy is high from the start bit until the stop bit completes.
// Never assert valid while busy=1.
//
// Parameters: CLK_FREQ (Hz), BAUD_RATE (bps)

module uart_tx #(
    parameter CLK_FREQ  = 27_000_000,
    parameter BAUD_RATE = 115_200
)(
    input            clk,
    input            reset,
    input      [7:0] data,
    input            valid,
    output reg       tx,
    output reg       busy
);

    localparam CLK_PER_BIT = 234; // 27_000_000 / 115_200 hardcoded // 234 @ 27MHz/115200

    localparam S_IDLE  = 2'd0;
    localparam S_START = 2'd1;
    localparam S_DATA  = 2'd2;
    localparam S_STOP  = 2'd3;

    reg [1:0] state;
    reg [7:0] shift;
    reg [2:0] bit_idx;
    reg [8:0] clk_cnt; // max 234 fits in 9 bits

    always @(posedge clk) begin
        if (reset) begin
            state   <= S_IDLE;
            tx      <= 1'b1;
            busy    <= 1'b0;
            clk_cnt <= 0;
            bit_idx <= 0;
            shift   <= 8'd0;
        end else begin
            case (state)
                S_IDLE: begin
                    tx   <= 1'b1;
                    busy <= 1'b0;
                    if (valid) begin
                        shift   <= data;
                        busy    <= 1'b1;
                        clk_cnt <= 0;
                        state   <= S_START;
                    end
                end
                S_START: begin
                    tx <= 1'b0;
                    if (clk_cnt < CLK_PER_BIT - 1)
                        clk_cnt <= clk_cnt + 1;
                    else begin
                        clk_cnt <= 0;
                        bit_idx <= 0;
                        state   <= S_DATA;
                    end
                end
                S_DATA: begin
                    tx <= shift[bit_idx];
                    if (clk_cnt < CLK_PER_BIT - 1)
                        clk_cnt <= clk_cnt + 1;
                    else begin
                        clk_cnt <= 0;
                        if (bit_idx == 3'd7)
                            state <= S_STOP;
                        else
                            bit_idx <= bit_idx + 1;
                    end
                end
                S_STOP: begin
                    tx <= 1'b1;
                    if (clk_cnt < CLK_PER_BIT - 1)
                        clk_cnt <= clk_cnt + 1;
                    else begin
                        clk_cnt <= 0;
                        busy    <= 1'b0;
                        state   <= S_IDLE;
                    end
                end
            endcase
        end
    end

endmodule
/* verilator lint_on WIDTHEXPAND */
