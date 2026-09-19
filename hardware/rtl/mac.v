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
    // Signed 8x8 multiply — no zero-skip, use inputs directly
    (* use_dsp = "yes" *)
    wire signed [15:0] product = $signed(a) * $signed(b);

    always @(posedge clk) begin
        if (reset) begin
            out       <= 0;
            a_out     <= 0;
            b_out     <= 0;
            out_reset <= 0;
        end else begin
            out_reset <= in_out_reset;
            a_out     <= a;
            b_out     <= b;
            if (in_out_reset != 8'h00)
                out <= 0;
            else
                out <= out + {{16{product[15]}}, product};
        end
    end
endmodule
