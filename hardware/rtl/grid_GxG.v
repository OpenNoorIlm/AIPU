/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off PINCONNECTEMPTY */
module grid_GxG #(
    parameter G = 2,
    parameter C = 2,
    parameter N = 4
)(
    input        clk,
    input        reset,
    input  [1:0] precision,
    input  [7:0] in_out_reset,
    input  [7:0] a_in[0:G-1][0:N-1],
    input  [7:0] b_in[0:G-1][0:N-1],
    input  [7:0] next_a_in[0:G-1][0:C-1][0:N-1],
    input  [7:0] next_b_in[0:G-1][0:C-1][0:N-1],
    input  enable[0:G-1][0:G-1],
    output [31:0] out[0:G-1][0:G-1][0:C-1][0:N-1][0:N-1],
    output [7:0]  a_out[0:G-1][0:N-1],
    output done[0:G-1][0:G-1]
);
    wire [7:0] a_chain     [0:G-1][0:G][0:N-1];
    wire [7:0] b_chain     [0:G][0:G-1][0:N-1];
    wire [7:0] next_a_chain[0:G-1][0:G][0:C-1][0:N-1];
    wire [7:0] next_b_chain[0:G][0:G-1][0:C-1][0:N-1];
    reg  [7:0] a_gated     [0:G-1][0:G-1][0:N-1];
    reg  [7:0] b_gated     [0:G-1][0:G-1][0:N-1];
    reg  [7:0] next_a_gated[0:G-1][0:G-1][0:C-1][0:N-1];
    reg  [7:0] next_b_gated[0:G-1][0:G-1][0:C-1][0:N-1];

    genvar r, c, n, ct;

    generate
        for (r = 0; r < G; r = r + 1) begin : gen_a_chain
            for (n = 0; n < N; n = n + 1) begin : gen_a_n
                assign a_chain[r][0][n] = a_in[r][n];
            end
            for (ct = 0; ct < C; ct = ct + 1) begin : gen_a_ct
                for (n = 0; n < N; n = n + 1) begin : gen_a_ct_n
                    assign next_a_chain[r][0][ct][n] = next_a_in[r][ct][n];
                end
            end
        end
        for (c = 0; c < G; c = c + 1) begin : gen_b_chain
            for (n = 0; n < N; n = n + 1) begin : gen_b_n
                assign b_chain[0][c][n] = b_in[c][n];
            end
            for (ct = 0; ct < C; ct = ct + 1) begin : gen_b_ct
                for (n = 0; n < N; n = n + 1) begin : gen_b_ct_n
                    assign next_b_chain[0][c][ct][n] = next_b_in[c][ct][n];
                end
            end
        end
    endgenerate

    always @(posedge clk) begin
        for (int ri = 0; ri < G; ri = ri + 1) begin
            for (int ci = 0; ci < G; ci = ci + 1) begin
                for (int ni = 0; ni < N; ni = ni + 1) begin
                    a_gated[ri][ci][ni] <= enable[ri][ci] ? a_chain[ri][ci][ni] : 8'h00;
                    b_gated[ri][ci][ni] <= enable[ri][ci] ? b_chain[ri][ci][ni] : 8'h00;
                end
                for (int cti = 0; cti < C; cti = cti + 1) begin
                    for (int ni = 0; ni < N; ni = ni + 1) begin
                        next_a_gated[ri][ci][cti][ni] <= enable[ri][ci] ? next_a_chain[ri][ci][cti][ni] : 8'h00;
                        next_b_gated[ri][ci][cti][ni] <= enable[ri][ci] ? next_b_chain[ri][ci][cti][ni] : 8'h00;
                    end
                end
            end
        end
    end

    generate
        for (r = 0; r < G; r = r + 1) begin : grow
            for (c = 0; c < G; c = c + 1) begin : gcol
                chain_CxC #(.N(N), .C(C)) chain_inst(
                    .clk(clk),
                    .reset(reset),
                    .precision(precision),
                    .in_out_reset((in_out_reset != 8'h00 || !enable[r][c]) ? 8'hFF : 8'h00),
                    .a_in(a_gated[r][c]),
                    .b_in(b_gated[r][c]),
                    .next_a_in(next_a_gated[r][c]),
                    .next_b_in(next_b_gated[r][c]),
                    .out(out[r][c]),
                    .a_out(a_chain[r][c+1]),
                    .b_out(b_chain[r+1][c]),
                    .out_reset()
                );
                assign done[r][c] = !enable[r][c];
            end
        end
    endgenerate

    generate
        for (r = 0; r < G; r = r + 1) begin : gen_a_out
            for (n = 0; n < N; n = n + 1) begin : gen_a_out_n
                assign a_out[r][n] = a_chain[r][G][n];
            end
        end
    endgenerate
endmodule
