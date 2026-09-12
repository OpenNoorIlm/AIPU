/* verilator lint_off TIMESCALEMOD */
`timescale 1ns/1ps
module uart_top_tb;
    parameter CLK_PERIOD = 37;
    reg clk = 0;
    always #(CLK_PERIOD/2) clk = ~clk;

    wire uart_tx_pin;
    uart_top dut (.clk(clk), .uart_tx_pin(uart_tx_pin));

    // RX to decode what comes out
    wire [7:0] rx_data;
    wire       rx_ready;
    uart_rx #(.CLK_FREQ(27_000_000), .BAUD_RATE(115_200)) u_rx (
        .clk(clk), .reset(1'b0),
        .rx(uart_tx_pin),
        .data_out(rx_data), .data_ready(rx_ready)
    );

    integer recvd = 0;
    integer cycles = 0;
    // BOOT_DELAY=27M cycles + 9 bytes * 10 bits * 234 cycles = ~27M + 21060
    // use 27.1M cycles max
    parameter MAX_CYCLES = 27_100_000;

    always @(posedge clk) begin
        if (rx_ready) begin
            $display("[RX] byte %0d  0x%02X  '%s'",
                recvd, rx_data,
                (rx_data >= 8'h20 && rx_data < 8'h7F) ? {rx_data} : ".");
            recvd = recvd + 1;
        end
        cycles <= cycles + 1;
        if (recvd == 9) begin
            $display("\n=== uart_top TX works! All 9 bytes received ===\n");
            $finish;
        end
        if (cycles > MAX_CYCLES) begin
            $display("\n=== TIMEOUT  recvd=%0d ===\n", recvd);
            $finish;
        end
    end
endmodule
/* verilator lint_on TIMESCALEMOD */
