module mac(
    input clk,
    input reset,
    input [7:0] in_out_reset,
    input [7:0] a,
    input [7:0] b,
    input [7:0] next_a,      // next non-zero a to use when current is zero
    input [7:0] next_b,      // next non-zero b to use when current is zero
    output reg [31:0] out,
    output reg [7:0] a_out,
    output reg [7:0] b_out,
    output reg [7:0] out_reset
);

    // select real inputs     substitute next if current is zero
    wire [7:0] a_sel = (a == 0 || b == 0) ? next_a : a;
    wire [7:0] b_sel = (a == 0 || b == 0) ? next_b : b;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            out       <= 0;
            a_out     <= 0;
            b_out     <= 0;
            out_reset <= 0;
        end else begin
            out_reset <= in_out_reset;
            a_out     <= a_sel;   // pass selected value downstream
            b_out     <= b_sel;

            if (in_out_reset != 8'h00) begin
                out <= 0;
            end else begin
                out <= out + (a_sel * b_sel);  // always compute     no idle cycles
            end
        end
    end

endmodule
