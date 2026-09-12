module mac_tb;

    // declare signals
    reg clk, reset;
    reg [7:0] a, b;
    wire [31:0] out;

    // connect your MAC module
    mac uut (
        .clk(clk),
        .reset(reset),
        .a(a),
        .b(b),
        .out(out)
    );

    // clock: flips every 5 units
    always #5 clk = ~clk;

    initial begin
        $dumpfile("mac.vcd");
        $dumpvars(0, mac_tb);

        // initialize
        clk = 0; reset = 1; a = 0; b = 0;
        #10;

        // release reset
        reset = 0;

        // test: 3 × 4 = 12, accumulated each cycle
        a = 8'd3; b = 8'd4;
        #50;

        // test: change inputs
        a = 8'd2; b = 8'd5;
        #50;

        $finish;
    end

    // print output every clock
    always @(posedge clk)
        $display("time=%0t a=%0d b=%0d out=%0d", $time, a, b, out);

endmodule
