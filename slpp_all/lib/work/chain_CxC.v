module chain_CxC #(parameter N = 4, C = 2)(
    input clk,
    input reset,
    input [7:0] in_out_reset,
    input  [7:0] a_in[0:N-1],
    input  [7:0] b_in[0:N-1],
    input  [7:0] next_a_in[0:C-1][0:N-1],
    input  [7:0] next_b_in[0:C-1][0:N-1],
    output [31:0] out[0:C-1][0:N-1][0:N-1],
    output [7:0] a_out[0:N-1],
    output [7:0] b_out[0:N-1],
    output [7:0] out_reset[0:C-1][0:N-1]
);
    wire [7:0] a_chain[0:C][0:N-1];
    wire [7:0] b_chain[0:C][0:N-1];

    genvar i, t;
    generate
        for (i = 0; i < N; i = i + 1) begin
            assign a_chain[0][i] = a_in[i];
            assign b_chain[0][i] = b_in[i];
            assign a_out[i]      = a_chain[C][i];
            assign b_out[i]      = b_chain[C][i];
        end
    endgenerate

    generate
        for (t = 0; t < C; t = t + 1) begin : tile
            systolic_NxN #(.N(N)) tile_inst(
                .clk(clk),
                .reset(reset),
                .in_out_reset(in_out_reset),
                .a_in(a_chain[t]),
                .b_in(b_chain[t]),
                .next_a_in(next_a_in[t]),
                .next_b_in(next_b_in[t]),
                .out(out[t]),
                .a_out(a_chain[t+1]),
                .b_out(b_chain[t+1]),
                .out_reset(out_reset[t])
            );
        end
    endgenerate
endmodule
