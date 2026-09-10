module systolic_2x2(
    input clk,
    input reset,
    input [7:0] a0, a1,
    input [7:0] b0, b1,
    output [31:0] out00, out01, out10, out11
);

    wire [7:0] a00_out, a10_out;  // a passing right
    wire [7:0] b00_out, b01_out;  // b passing down

    // MAC00 — top left
    mac mac00(
        .clk(clk), .reset(reset),
        .a(a0), .b(b0),
        .out(out00),
        .a_out(a00_out),   // → MAC01.a
        .b_out(b00_out)    // → MAC10.b
    );

    // MAC01 — top right
    mac mac01(
        .clk(clk), .reset(reset),
        .a(a00_out),       // ← MAC00.a_out
        .b(b1),
        .out(out01),
        .a_out(),
        .b_out(b01_out)    // → MAC11.b
    );

    // MAC10 — bottom left
    mac mac10(
        .clk(clk), .reset(reset),
        .a(a1),
        .b(b00_out),       // ← MAC00.b_out
        .out(out10),
        .a_out(a10_out),   // → MAC11.a
        .b_out()
    );

    // MAC11 — bottom right
    mac mac11(
        .clk(clk), .reset(reset),
        .a(a10_out),       // ← MAC10.a_out
        .b(b01_out),       // ← MAC01.b_out
        .out(out11),
        .a_out(),
        .b_out()
    );

endmodule