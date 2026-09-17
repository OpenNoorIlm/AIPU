/* verilator lint_off UNUSEDSIGNAL */
module mac(
    input clk,
    input reset,
    input [7:0] in_out_reset,
    input [7:0] a,
    input [7:0] b,
    input [7:0] next_a,
    input [7:0] next_b,
    output reg [31:0] out,
    output reg [7:0] a_out,
    output reg [7:0] b_out,
    output reg [7:0] out_reset
);
    wire [7:0] a_sel = (a == 0 || b == 0) ? next_a : a;
    wire [7:0] b_sel = (a == 0 || b == 0) ? next_b : b;

    // 8x8 signed multiply -- synthesises to MULT9X9 on Gowin
    (* use_dsp = "yes" *)
    wire signed [15:0] product = $signed(a_sel) * $signed(b_sel);

    always @(posedge clk) begin
        if (reset) begin
            out       <= 0;
            a_out     <= 0;
            b_out     <= 0;
            out_reset <= 0;
        end else begin
            out_reset <= in_out_reset;
            a_out     <= a_sel;
            b_out     <= b_sel;
            if (in_out_reset != 8'h00)
                out <= 0;
            else
                out <= out + {{16{product[15]}}, product}; // sign-extend to 32b
        end
    end
endmodule
