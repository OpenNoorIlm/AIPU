/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off WIDTHTRUNC */
module mac(
    input        clk,
    input        reset,
    input  [1:0] precision,
    input  [7:0] in_out_reset,
    input  [7:0] a,
    input  [7:0] b,
    input  [7:0] next_a,
    input  [7:0] next_b,
    output reg [31:0] out,
    output reg [7:0]  a_out,
    output reg [7:0]  b_out,
    output reg [7:0]  out_reset
);
    wire signed [15:0] prod = $signed(a) * $signed(b);

    wire [31:0] next_val = (in_out_reset != 8'h00)
                         ? 32'd0
                         : out + {{16{prod[15]}}, prod};

    always @(posedge clk) begin
        if (reset) begin
            out <= 32'd0; a_out <= 8'd0; b_out <= 8'd0; out_reset <= 8'd0;
        end else begin
            out_reset <= in_out_reset;
            a_out     <= a;
            b_out     <= b;
            out       <= next_val;
        end
    end
endmodule
