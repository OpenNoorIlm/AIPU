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
    input [7:0] sram_rd_data,
    output reg [$clog2(SRAM_DEPTH)-1:0] sram_rd_addr,
    output uart_tx_pin
);

    // UART TX
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

    // Boot message: "AIPU OK\r\n" = 9 bytes (same as uart_hello.v)
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

    // 1-second boot delay (same as uart_hello.v but shorter)
    localparam BOOT_DELAY = CLK_FREQ; // 1 second
    reg [25:0] boot_cnt  = 0;
    reg        boot_done = 0;
    always @(posedge clk or posedge reset) begin
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

    // States
    localparam S_BOOT_WAIT  = 3'd0; // waiting for boot delay
    localparam S_BOOT_SEND  = 3'd1; // sending boot message chars
    localparam S_BOOT_TICK  = 3'd2; // wait for uart not-busy between boot chars
    localparam S_IDLE       = 3'd3; // waiting for mem_done
    localparam S_READ       = 3'd4; // issue SRAM read
    localparam S_SEND       = 3'd5; // send SRAM byte
    localparam S_WAIT       = 3'd6; // wait for uart not-busy

    reg [2:0]  state;
    reg [3:0]  boot_idx;   // which boot message byte (0..8)
    reg [15:0] byte_count;
    localparam TOTAL_BYTES = G * G * C * N * N * 4;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state        <= S_BOOT_WAIT;
            boot_idx     <= 0;
            byte_count   <= 0;
            sram_rd_addr <= 0;
            tx_valid     <= 0;
            tx_data      <= 0;
        end else begin
            tx_valid <= 0; // default: no new byte

            case (state)

                // --- Boot sequence ---

                S_BOOT_WAIT: begin
                    if (boot_done)
                        state <= S_BOOT_SEND;
                end

                S_BOOT_SEND: begin
                    if (!tx_busy) begin
                        tx_data  <= boot_msg[boot_idx];
                        tx_valid <= 1;
                        state    <= S_BOOT_TICK;
                    end
                end

                S_BOOT_TICK: begin
                    // wait for tx to go busy then clear, then next char
                    if (!tx_busy) begin
                        if (boot_idx < BOOT_MSG_LEN - 1) begin
                            boot_idx <= boot_idx + 1;
                            state    <= S_BOOT_SEND;
                        end else begin
                            state <= S_IDLE;
                        end
                    end
                end

                // --- Result streaming ---

                S_IDLE: begin
                    byte_count   <= 0;
                    sram_rd_addr <= 0;
                    if (mem_done)
                        state <= S_READ;
                end

                S_READ: begin
                    state <= S_SEND; // one cycle SRAM read latency
                end

                S_SEND: begin
                    if (!tx_busy) begin
                        tx_data  <= sram_rd_data;
                        tx_valid <= 1;
                        state    <= S_WAIT;
                    end
                end

                S_WAIT: begin
                    if (!tx_busy) begin
                        byte_count   <= byte_count + 1;
                        sram_rd_addr <= sram_rd_addr + 1;
                        if (byte_count >= TOTAL_BYTES - 1)
                            state <= S_IDLE;
                        else
                            state <= S_READ;
                    end
                end

                default: state <= S_IDLE;

            endcase
        end
    end

endmodule
