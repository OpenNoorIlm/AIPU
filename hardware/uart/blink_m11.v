module blink_m11(input clk, output reg uart_tx_pin);
    reg [24:0] cnt = 0;
    always @(posedge clk) begin
        cnt <= cnt + 1;
        if (cnt == 25'd13_500_000) begin
            cnt <= 0;
            uart_tx_pin <= ~uart_tx_pin;
        end
    end
endmodule
