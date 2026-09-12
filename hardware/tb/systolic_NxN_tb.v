module systolic_NxN_tb;

    parameter N = 64;

    reg clk, reset;
    reg [7:0] a[0:N-1];
    reg [7:0] b[0:N-1];
    wire [31:0] out[0:N-1][0:N-1];

    systolic_NxN #(.N(N)) sysc (
        .clk(clk),
        .reset(reset),
        .a_in(a),
        .b_in(b),
        .out(out)
    );

    always #5 clk = ~clk;

    initial begin
        $dumpfile("systolic_NxN.vcd");
        $dumpvars(0, systolic_NxN_tb);

        clk = 0; reset = 1;
        for (integer i = 0; i < N; i = i + 1) begin
            a[i] = 0;
            b[i] = 0;
        end
        #10;

        reset = 0;
        a[0] = 8'd1; a[1] = 8'd2;
        b[0] = 8'd3; b[1] = 8'd4;
        #80;

        $finish;
    end

    always @(posedge clk)
        $display("time=%0t out[0][0]=%0d out[0][1]=%0d out[1][0]=%0d out[1][1]=%0d",
                  $time, out[0][0], out[0][1], out[1][0], out[1][1]);

endmodule