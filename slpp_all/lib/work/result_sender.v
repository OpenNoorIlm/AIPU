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
    input mem_done,   // pulse from memory controller
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

    // state machine
    localparam IDLE = 2'd0;
    localparam READ = 2'd1;
    localparam SEND = 2'd2;
    localparam WAIT = 2'd3;

    reg [1:0]  state;
    reg [31:0] byte_count;
    localparam TOTAL_BYTES = G * G * C * N * N * 4; // 4 bytes per 32-bit result

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state        <= IDLE;
            byte_count   <= 0;
            sram_rd_addr <= 0;
            tx_valid     <= 0;
            tx_data      <= 0;
        end else begin
            tx_valid <= 0; // default

            case (state)

                IDLE: begin
                    byte_count <= 0;
                    if (mem_done) begin
                        sram_rd_addr <= 0;
                        state        <= READ;
                    end
                end

                READ: begin
                    // wait one cycle for SRAM read
                    state <= SEND;
                end

                SEND: begin
                    if (!tx_busy) begin
                        tx_data  <= sram_rd_data;
                        tx_valid <= 1;
                        state    <= WAIT;
                    end
                end

                WAIT: begin
                    if (!tx_busy) begin
                        byte_count   <= byte_count + 1;
                        sram_rd_addr <= sram_rd_addr + 1;
                        if (byte_count >= TOTAL_BYTES - 1)
                            state <= IDLE;
                        else
                            state <= READ;
                    end
                end

            endcase
        end
    end

endmodule
