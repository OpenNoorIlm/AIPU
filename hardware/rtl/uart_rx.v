/* verilator lint_off WIDTHEXPAND */
// uart_rx.v  —  8N1 UART receiver
// data_ready pulses high for exactly ONE cycle when a valid byte is received.
// data_out holds the byte on that cycle.
// Samples at mid-bit. Two-stage sync on RX input to prevent metastability.
//
// Parameters: CLK_FREQ (Hz), BAUD_RATE (bps)

module uart_rx #(
    parameter CLK_FREQ  = 27_000_000,
    parameter BAUD_RATE = 115_200
)(
    input            clk,
    input            reset,
    input            rx,
    output reg [7:0] data_out,
    output reg       data_ready
);

    localparam CLK_PER_BIT  = CLK_FREQ / BAUD_RATE;   // 234
    localparam CLK_HALF_BIT = CLK_PER_BIT / 2;        // 117

    localparam S_IDLE  = 2'd0;
    localparam S_START = 2'd1;
    localparam S_DATA  = 2'd2;
    localparam S_STOP  = 2'd3;

    // Two-stage synchroniser
    reg rx_s1, rx_s2;
    always @(posedge clk) begin
        rx_s1 <= rx;
        rx_s2 <= rx_s1;
    end

    reg [1:0] state;
    reg [7:0] shift;
    reg [2:0] bit_idx;
    reg [8:0] clk_cnt;

    always @(posedge clk) begin
        if (reset) begin
            state      <= S_IDLE;
            shift      <= 8'd0;
            bit_idx    <= 0;
            clk_cnt    <= 0;
            data_out   <= 8'd0;
            data_ready <= 1'b0;
        end else begin
            data_ready <= 1'b0;

            case (state)
                S_IDLE: begin
                    clk_cnt <= 0;
                    if (!rx_s2)           // falling edge = start bit
                        state <= S_START;
                end
                S_START: begin            // wait to mid-start-bit, confirm low
                    if (clk_cnt < CLK_HALF_BIT - 1)
                        clk_cnt <= clk_cnt + 1;
                    else begin
                        clk_cnt <= 0;
                        if (!rx_s2) begin
                            bit_idx <= 0;
                            state   <= S_DATA;
                        end else
                            state <= S_IDLE; // glitch, abort
                    end
                end
                S_DATA: begin             // sample at centre of each bit
                    if (clk_cnt < CLK_PER_BIT - 1)
                        clk_cnt <= clk_cnt + 1;
                    else begin
                        clk_cnt        <= 0;
                        shift[bit_idx] <= rx_s2;
                        if (bit_idx == 3'd7)
                            state <= S_STOP;
                        else
                            bit_idx <= bit_idx + 1;
                    end
                end
                S_STOP: begin             // verify stop bit
                    if (clk_cnt < CLK_PER_BIT - 1)
                        clk_cnt <= clk_cnt + 1;
                    else begin
                        clk_cnt <= 0;
                        if (rx_s2) begin  // valid stop bit
                            data_out   <= shift;
                            data_ready <= 1'b1;
                        end
                        // framing error: drop byte silently
                        state <= S_IDLE;
                    end
                end
            endcase
        end
    end

endmodule
/* verilator lint_on WIDTHEXPAND */
