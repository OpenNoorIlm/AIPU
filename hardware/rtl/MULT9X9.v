// Verilator behavioural stub for Gowin MULT9X9 DSP primitive
module MULT9X9 #(parameter AREG=0, BREG=0)(
    input  [8:0]  A,
    input  [8:0]  B,
    output [17:0] O
);
    assign O = $signed(A) * $signed(B);
endmodule
