module systolic_2x2_tb;

    reg clk, reset;
    reg [7:0] a0, a1, b0, b1;
    wire [31:0] out00, out01, out10, out11;

    systolic_2x2 sysc (
        .clk(clk), .reset(reset),
        .a0(a0), .a1(a1),
        .b0(b0), .b1(b1),
        .out00(out00), .out01(out01),
        .out10(out10), .out11(out11)
    );

    always #5 clk = ~clk;

    initial begin
        $dumpfile("systolic.vcd");
        $dumpvars(0, systolic_2x2_tb);

        clk = 0; reset = 1;
        a0 = 0; a1 = 0; b0 = 0; b1 = 0;
        #10;

        reset = 0;
        a0 = 8'd1; a1 = 8'd2;
        b0 = 8'd3; b1 = 8'd4;
        #80;

        $finish;
    end

    always @(posedge clk)
        $display("time=%0t out00=%0d out01=%0d out10=%0d out11=%0d",
                  $time, out00, out01, out10, out11);

endmodule
