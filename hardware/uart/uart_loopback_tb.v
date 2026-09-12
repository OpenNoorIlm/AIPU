/* verilator lint_off TIMESCALEMOD */
`timescale 1ns/1ps

// uart_loopback_tb.v
// Wires uart_tx directly into uart_rx and sends "AIPU OK\r\n".
// Every received byte is checked against what was sent.

module uart_loopback_tb;

    parameter CLK_PERIOD = 37;          // ~27 MHz
    parameter CLK_FREQ   = 27_000_000;
    parameter BAUD_RATE  = 115_200;
    parameter MAX_CYCLES = 30_000;

    reg clk = 0;
    always #(CLK_PERIOD/2) clk = ~clk;

    reg reset = 1;
    initial #(CLK_PERIOD*4) reset = 0;

    // TX
    reg  [7:0] tx_data  = 0;
    reg        tx_valid = 0;
    wire       tx_busy;
    wire       tx_line;

    uart_tx #(.CLK_FREQ(CLK_FREQ), .BAUD_RATE(BAUD_RATE)) DUT_TX (
        .clk(clk), .reset(reset),
        .data(tx_data), .valid(tx_valid),
        .tx(tx_line), .busy(tx_busy)
    );

    // RX — loopback
    wire [7:0] rx_data;
    wire       rx_ready;

    uart_rx #(.CLK_FREQ(CLK_FREQ), .BAUD_RATE(BAUD_RATE)) DUT_RX (
        .clk(clk), .reset(reset),
        .rx(tx_line),
        .data_out(rx_data), .data_ready(rx_ready)
    );

    // "AIPU OK\r\n"
    reg [7:0] msg [0:8];
    initial begin
        msg[0]=8'h41; msg[1]=8'h49; msg[2]=8'h50; msg[3]=8'h55;
        msg[4]=8'h20; msg[5]=8'h4F; msg[6]=8'h4B;
        msg[7]=8'h0D; msg[8]=8'h0A;
    end

    integer sent   = 0;
    integer recvd  = 0;
    integer errors = 0;
    integer cycles = 0;

    // Sender
    initial begin
        @(negedge reset);
        repeat(4) @(posedge clk);
        while (sent < 9) begin
            @(posedge clk);
            if (!tx_busy && !tx_valid) begin
                tx_data  = msg[sent];
                tx_valid = 1;
                @(posedge clk);
                tx_valid = 0;
                $display("[TX] byte %0d  0x%02X  '%s'",
                    sent, msg[sent],
                    (msg[sent]>=8'h20 && msg[sent]<8'h7F) ? {msg[sent]} : ".");
                sent = sent + 1;
            end
        end
    end

    // Receiver checker
    always @(posedge clk) begin
        if (rx_ready) begin
            $display("[RX] byte %0d  0x%02X  '%s'  %s",
                recvd, rx_data,
                (rx_data>=8'h20 && rx_data<8'h7F) ? {rx_data} : ".",
                (rx_data === msg[recvd]) ? "OK" : "MISMATCH !!!");
            if (rx_data !== msg[recvd]) errors = errors + 1;
            recvd = recvd + 1;
        end
    end

    // Watchdog
    always @(posedge clk) begin
        cycles <= cycles + 1;
        if (recvd == 9) begin
            $display("\n=== UART LOOPBACK %s  (%0d errors) ===\n",
                errors != 0 ? "FAILED" : "PASSED", errors);
            $finish;
        end
        if (cycles > MAX_CYCLES) begin
            $display("\n=== TIMEOUT  sent=%0d  recvd=%0d ===\n", sent, recvd);
            $finish;
        end
    end

endmodule
/* verilator lint_on TIMESCALEMOD */
