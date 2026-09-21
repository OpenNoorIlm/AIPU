/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off WIDTHTRUNC */
//
// mac.v  —  Multiply-Accumulate cell with selectable precision
//
// precision[1:0]:
//   2'b00 = INT8  : signed 8x8 -> INT32 accumulator  (original, unchanged)
//   2'b01 = FP8   : FP8 E4M3 x FP8 E4M3 -> FP32 accumulator
//   2'b10 = BF16  : ** STUB ** see BF16_UPGRADE_GUIDE.md; aliases FP8 path
//   2'b11 = INT8  : reserved, aliases INT8
//
// out[31:0] meaning:
//   precision==INT8  -> signed 32-bit integer
//   precision==FP8   -> IEEE 754 FP32 bit pattern
//
// FP8 E4M3 format:
//   bit 7    : sign
//   bits 6:3 : exponent, bias = 7
//   bits 2:0 : mantissa, implicit leading 1
//   Special  : exp=0xF mant=0x7 -> NaN  (no Inf in E4M3)
//
module mac(
    input        clk,
    input        reset,
    input  [1:0] precision,
    input  [7:0] in_out_reset,
    input  [7:0] a,
    input  [7:0] b,
    input  [7:0] next_a,
    input  [7:0] next_b,
    output reg [31:0] out,
    output reg [7:0]  a_out,
    output reg [7:0]  b_out,
    output reg [7:0]  out_reset
);

    // ── INT8 path ────────────────────────────────────────────────────────
    (* use_dsp = "yes" *)
    wire signed [15:0] int8_prod = $signed(a) * $signed(b);
    wire [31:0] int8_next = (in_out_reset != 8'h00)
                          ? 32'd0
                          : out + {{16{int8_prod[15]}}, int8_prod};

    // ── FP8 E4M3 multiplier ──────────────────────────────────────────────
    // fp8_mul: 4x4 integer mantissa multiply (maps to 1 DSP / < 20 LUTs)
    function automatic [31:0] fp8_mul;
        input [7:0] fa, fb;
        reg        sa, sb, sp;
        reg [3:0]  ea, eb;
        reg [3:0]  ma, mb;
        reg [7:0]  mp;
        reg [8:0]  ep;
        reg [7:0]  e32;
        reg [22:0] m32;
        begin
            sa = fa[7]; ea = fa[6:3]; ma = {1'b1, fa[2:0]};
            sb = fb[7]; eb = fb[6:3]; mb = {1'b1, fb[2:0]};
            sp = sa ^ sb;
            if (ea == 4'd0 || eb == 4'd0) begin
                fp8_mul = 32'd0;
            end else if ((ea == 4'hF && fa[2:0] == 3'h7) ||
                         (eb == 4'hF && fb[2:0] == 3'h7)) begin
                fp8_mul = {sp, 8'hFF, 23'h400000};
            end else begin
                ep = {1'b0, ea} + {1'b0, eb} + 9'd113;
                mp = ma * mb;
                if (mp[7]) begin
                    e32 = ep[7:0] + 8'd1;
                    m32 = {mp[6:0], 16'd0};
                end else begin
                    e32 = ep[7:0];
                    m32 = {mp[5:0], 17'd0};
                end
                fp8_mul = {sp, e32, m32};
            end
        end
    endfunction

    // ── FP32 adder (for accumulation) ────────────────────────────────────
    function automatic [31:0] fp32_add;
        input [31:0] x, y;
        reg        sx, sy, s_big, s_res;
        reg [7:0]  ex, ey, e_big, e_res, e_diff;
        reg [22:0] mx, my;
        reg [24:0] ax, ay, sm, ns;
        reg [4:0]  sh;
        begin
            sx = x[31]; ex = x[30:23]; mx = x[22:0];
            sy = y[31]; ey = y[30:23]; my = y[22:0];
            if (x[30:0] == 0) begin
                fp32_add = y;
            end else if (y[30:0] == 0) begin
                fp32_add = x;
            end else begin
                if (ex >= ey) begin
                    e_big = ex; s_big = sx;
                    ax = {2'b01, mx};
                    e_diff = ex - ey;
                    ay = (e_diff >= 8'd25) ? 25'd0 : ({2'b01, my} >> e_diff);
                end else begin
                    e_big = ey; s_big = sy;
                    ax = {2'b01, my};
                    e_diff = ey - ex;
                    ay = (e_diff >= 8'd25) ? 25'd0 : ({2'b01, mx} >> e_diff);
                end
                e_res = e_big;
                if (sx == sy) begin
                    sm = ax + ay;
                    s_res = s_big;
                    if (sm[24])
                        fp32_add = {s_res, (e_res + 8'd1), sm[23:1]};
                    else
                        fp32_add = {s_res, e_res, sm[22:0]};
                end else begin
                    if (ax >= ay) begin sm = ax - ay; s_res = s_big;  end
                    else          begin sm = ay - ax; s_res = ~s_big; end
                    if (sm == 25'd0) begin
                        fp32_add = 32'd0;
                    end else begin
                        if      (sm[24]) sh = 5'd0;
                        else if (sm[23]) sh = 5'd1;
                        else if (sm[22]) sh = 5'd2;
                        else if (sm[21]) sh = 5'd3;
                        else if (sm[20]) sh = 5'd4;
                        else if (sm[19]) sh = 5'd5;
                        else if (sm[18]) sh = 5'd6;
                        else if (sm[17]) sh = 5'd7;
                        else if (sm[16]) sh = 5'd8;
                        else if (sm[15]) sh = 5'd9;
                        else if (sm[14]) sh = 5'd10;
                        else if (sm[13]) sh = 5'd11;
                        else if (sm[12]) sh = 5'd12;
                        else if (sm[11]) sh = 5'd13;
                        else if (sm[10]) sh = 5'd14;
                        else if (sm[9])  sh = 5'd15;
                        else if (sm[8])  sh = 5'd16;
                        else if (sm[7])  sh = 5'd17;
                        else if (sm[6])  sh = 5'd18;
                        else if (sm[5])  sh = 5'd19;
                        else if (sm[4])  sh = 5'd20;
                        else if (sm[3])  sh = 5'd21;
                        else if (sm[2])  sh = 5'd22;
                        else if (sm[1])  sh = 5'd23;
                        else             sh = 5'd24;
                        ns = sm << sh;
                        if ({3'd0, sh} > {1'b0, e_res})
                            fp32_add = 32'd0;
                        else
                            fp32_add = {s_res, (e_res - {3'd0, sh}), ns[23:1]};
                    end
                end
            end
        end
    endfunction

    wire [31:0] fp8_prod = fp8_mul(a, b);
    wire [31:0] fp8_next = (in_out_reset != 8'h00)
                         ? 32'd0
                         : fp32_add(out, fp8_prod);

    // ── Main register ────────────────────────────────────────────────────
    always @(posedge clk) begin
        if (reset) begin
            out       <= 32'd0;
            a_out     <= 8'd0;
            b_out     <= 8'd0;
            out_reset <= 8'd0;
        end else begin
            out_reset <= in_out_reset;
            a_out     <= a;
            b_out     <= b;
            case (precision)
                2'b01:   out <= fp8_next;
                2'b10:   out <= fp8_next;   // BF16 stub
                default: out <= int8_next;  // INT8 (00) and reserved (11)
            endcase
        end
    end
endmodule
