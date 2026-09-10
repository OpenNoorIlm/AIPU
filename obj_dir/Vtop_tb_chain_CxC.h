// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_tb.h for the primary calling header

#ifndef VERILATED_VTOP_TB_CHAIN_CXC_H_
#define VERILATED_VTOP_TB_CHAIN_CXC_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtop_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_tb_chain_CxC final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(in_out_reset,7,0);
    VL_IN8(a_in[4],7,0);
    VL_IN8(b_in[4],7,0);
    VL_OUT(out[2][4][4],31,0);
    VL_OUT8(a_out[4],7,0);
    VL_OUT8(b_out[4],7,0);
    VL_OUT8(__PVT__out_reset[2][4],7,0);

    // INTERNAL VARIABLES
    Vtop_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_tb_chain_CxC(Vtop_tb__Syms* symsp, const char* v__name);
    ~Vtop_tb_chain_CxC();
    VL_UNCOPYABLE(Vtop_tb_chain_CxC);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
