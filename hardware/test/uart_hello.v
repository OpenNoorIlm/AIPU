// uart_hello.v
// Sends "AIPU OK\r\n" repeatedly over UART TX at 115200 baud
// No dependencies — standalone test for Tang Primer 20K

module uart_hello (
    input  clk,         // H11 — 27MHz
    output uart_tx      // T13 — to ESP32 RX (GPIO17)
);
    parameter CLK_FREQ  = 27_000_000;
    parameter BAUD_RATE = 115_200;
    localparam CLKS_PER_BIT = CLK_FREQ / BAUD_RATE; // 234

    // Message: "AIPU OK\r\n" = 9 bytes
    localparam MSG_LEN = 9;
    reg [7:0] msg [0:MSG_LEN-1];
    initial begin
        msg[0] = 8'h41; // 'A'
        msg[1] = 8'h49; // 'I'
        msg[2] = 8'h50; // 'P'
        msg[3] = 8'h55; // 'U'
        msg[4] = 8'h20; // ' '
        msg[5] = 8'h4F; // 'O'
        msg[6] = 8'h4B; // 'K'
        msg[7] = 8'h0D; // '\r'
        msg[8] = 8'h0A; // '\n'
    end

    // 2-second boot delay
    reg [25:0] boot_cnt = 0;
    localparam BOOT_DELAY = 26'd54_000_000;
    reg boot_done = 0;
    always @(posedge clk) begin
        if (!boot_done) begin
            if (boot_cnt == BOOT_DELAY)
                boot_done <= 1;
            else
                boot_cnt <= boot_cnt + 1;
        end
    end

    // UART TX state machine
    localparam IDLE  = 3'd0;
    localparam START = 3'd1;
    localparam DATA  = 3'd2;
    localparam STOP  = 3'd3;
    localparam NEXT  = 3'd4;
    localparam WAIT  = 3'd5;

    reg [2:0]  state     = IDLE;
    reg [7:0]  shift_reg = 0;
    reg [31:0] clk_cnt   = 0;
    reg [2:0]  bit_idx   = 0;
    reg [3:0]  msg_idx   = 0;
    reg [31:0] gap_cnt   = 0;
    reg        tx_reg    = 1;

    assign uart_tx = tx_reg;

    localparam GAP = CLK_FREQ; // 1 second between messages

    always @(posedge clk) begin
        case (state)
                IDLE: begin
                    tx_reg <= 1;
                    if (boot_done) begin
                        shift_reg <= msg[msg_idx];
                        clk_cnt   <= 0;
                        state     <= START;
                    end
                end

                START: begin
                    tx_reg <= 0; // start bit
                    if (clk_cnt < CLKS_PER_BIT - 1)
                        clk_cnt <= clk_cnt + 1;
                    else begin
                        clk_cnt <= 0;
                        bit_idx <= 0;
                        state   <= DATA;
                    end
                end

                DATA: begin
                    tx_reg <= shift_reg[bit_idx];
                    if (clk_cnt < CLKS_PER_BIT - 1)
                        clk_cnt <= clk_cnt + 1;
                    else begin
                        clk_cnt <= 0;
                        if (bit_idx < 7)
                            bit_idx <= bit_idx + 1;
                        else
                            state <= STOP;
                    end
                end

                STOP: begin
                    tx_reg <= 1; // stop bit
                    if (clk_cnt < CLKS_PER_BIT - 1)
                        clk_cnt <= clk_cnt + 1;
                    else begin
                        clk_cnt <= 0;
                        state   <= NEXT;
                    end
                end

                NEXT: begin
                    if (msg_idx < MSG_LEN - 1) begin
                        msg_idx   <= msg_idx + 1;
                        shift_reg <= msg[msg_idx + 1];
                        state     <= START;
                    end else begin
                        msg_idx <= 0;
                        gap_cnt <= 0;
                        state   <= WAIT;
                    end
                end

                WAIT: begin
                    tx_reg <= 1;
                    if (gap_cnt < GAP - 1)
                        gap_cnt <= gap_cnt + 1;
                    else begin
                        gap_cnt   <= 0;
                        shift_reg <= msg[0];
                        state     <= START;
                    end
                end

                default: state <= IDLE;
            endcase
    end
endmodule
