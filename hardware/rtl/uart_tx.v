/* verilator lint_off WIDTHEXPAND */
module uart_tx #(
    parameter CLK_FREQ  = 27_000_000,
    parameter BAUD_RATE = 115_200
)(
    input  clk,
    input  reset,
    input  [7:0] data,
    input  valid,        // pulse high to send a byte
    output reg tx,       // UART TX pin
    output reg busy      // high while sending
);

    localparam CLKS_PER_BIT = CLK_FREQ / BAUD_RATE;  // 234

    localparam IDLE  = 2'd0;
    localparam START = 2'd1;
    localparam DATA  = 2'd2;
    localparam STOP  = 2'd3;

    reg [1:0]  state;
    reg [7:0]  shift_reg;   // data being sent
    reg [8:0]  clk_count;   // counts cycles per bit (max 234, fits in 9 bits)
    reg [2:0]  bit_index;   // which bit we're sending

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state     <= IDLE;
            tx        <= 1;   // UART idle = high
            busy      <= 0;
            clk_count <= 0;
            bit_index <= 0;
            shift_reg <= 0;
        end else begin
            case (state)

                IDLE: begin
                    tx   <= 1;
                    busy <= 0;
                    if (valid) begin
                        shift_reg <= data;
                        busy      <= 1;
                        clk_count <= 0;
                        state     <= START;
                    end
                end

                START: begin
                    tx <= 0;  // start bit
                    if (clk_count < CLKS_PER_BIT - 1) begin
                        clk_count <= clk_count + 1;
                    end else begin
                        clk_count <= 0;
                        bit_index <= 0;
                        state     <= DATA;
                    end
                end

                DATA: begin
                    tx <= shift_reg[bit_index];
                    if (clk_count < CLKS_PER_BIT - 1) begin
                        clk_count <= clk_count + 1;
                    end else begin
                        clk_count <= 0;
                        if (bit_index < 7) begin
                            bit_index <= bit_index + 1;
                        end else begin
                            state <= STOP;
                        end
                    end
                end

                STOP: begin
                    tx <= 1;  // stop bit
                    if (clk_count < CLKS_PER_BIT - 1) begin
                        clk_count <= clk_count + 1;
                    end else begin
                        clk_count <= 0;
                        state     <= IDLE;
                        busy      <= 0;
                    end
                end

            endcase
        end
    end

endmodule
