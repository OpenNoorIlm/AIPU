/* verilator lint_off UNUSEDSIGNAL */
module systolic_NxN #(parameter N = 4)(
    input        clk,
    input        reset,
    input  [1:0] precision,
    input  [7:0] in_out_reset,
    input  [7:0] a_in[0:N-1],
    input  [7:0] b_in[0:N-1],
    input  [7:0] next_a_in[0:N-1],
    input  [7:0] next_b_in[0:N-1],
    output reg [31:0] out[0:N-1][0:N-1],
    output reg [7:0] a_out[0:N-1],
    output reg [7:0] b_out[0:N-1],
    output reg [7:0]  out_reset[0:N-1]
);
    wire [7:0] a_wire[0:N-1][0:N];
    wire [7:0] b_wire[0:N][0:N-1];
    wire [7:0]  out_reset_wire[0:N-1][0:N-1];
    wire [7:0] next_a_mac[0:N-1][0:N-1];
    wire [7:0] next_b_mac[0:N-1][0:N-1];

    genvar i, j;

    generate
        for (i = 0; i < N; i = i + 1) begin : gen_a_init
            assign a_wire[i][0] = a_in[i];
        end
        for (j = 0; j < N; j = j + 1) begin : gen_b_init
            assign b_wire[0][j] = b_in[j];
        end
    endgenerate

    generate
        for (i = 0; i < N; i = i + 1) begin : gen_rows
            for (j = 0; j < N; j = j + 1) begin : gen_cols
                if (j < N-1) begin : gen_a_pass
                    assign next_a_mac[i][j] = a_wire[i][j+1];
                end else begin : gen_a_in
                    assign next_a_mac[i][j] = next_a_in[i];
                end
                if (i < N-1) begin : gen_b_pass
                    assign next_b_mac[i][j] = b_wire[i+1][j];
                end else begin : gen_b_in
                    assign next_b_mac[i][j] = next_b_in[j];
                end
            end
        end
    endgenerate

    always @(posedge clk) begin
        for (int ii = 0; ii < N; ii = ii + 1) begin
            a_out[ii]     <= a_wire[ii][N];
            b_out[ii]     <= b_wire[N][ii];
            out_reset[ii] <= out_reset_wire[ii][N-1];
        end
    end

    generate
        for (i = 0; i < N; i = i + 1) begin : row
            for (j = 0; j < N; j = j + 1) begin : col
                wire [31:0] mac_out;
                mac mac_inst(
                    .clk(clk), .reset(reset), .precision(precision),
                    .in_out_reset(in_out_reset),
                    .a(a_wire[i][j]),  .b(b_wire[i][j]),
                    .next_a(next_a_mac[i][j]), .next_b(next_b_mac[i][j]),
                    .out(mac_out),
                    .a_out(a_wire[i][j+1]), .b_out(b_wire[i+1][j]),
                    .out_reset(out_reset_wire[i][j])
                );
                always @(posedge clk) out[i][j] <= mac_out;
            end
        end
    endgenerate
endmodule
