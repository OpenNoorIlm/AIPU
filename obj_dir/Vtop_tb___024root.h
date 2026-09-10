// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_tb.h for the primary calling header

#ifndef VERILATED_VTOP_TB___024ROOT_H_
#define VERILATED_VTOP_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtop_tb_chain_CxC;


class Vtop_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_tb___024root final : public VerilatedModule {
  public:
    // CELLS
    Vtop_tb_chain_CxC* __PVT__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst;
    Vtop_tb_chain_CxC* __PVT__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__1__KET____DOT__chain_inst;
    Vtop_tb_chain_CxC* __PVT__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__1__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst;
    Vtop_tb_chain_CxC* __PVT__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__1__KET____DOT__gcol__BRA__1__KET____DOT__chain_inst;

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ top_tb__DOT__clk;
    CData/*0:0*/ top_tb__DOT__reset;
    CData/*0:0*/ top_tb__DOT__task_valid;
    CData/*7:0*/ top_tb__DOT__task_id;
    CData/*0:0*/ top_tb__DOT__task_accepted;
    CData/*0:0*/ top_tb__DOT__queue_full;
    CData/*2:0*/ top_tb__DOT__dut__DOT__disp__DOT__wr_ptr;
    CData/*2:0*/ top_tb__DOT__dut__DOT__disp__DOT__rd_ptr;
    CData/*3:0*/ top_tb__DOT__dut__DOT__disp__DOT__count;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top_tb__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__top_tb__DOT__reset__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ top_tb__DOT__task_cycles;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> top_tb__DOT__dut__DOT__disp__DOT__q_id;
    VlUnpacked<IData/*31:0*/, 8> top_tb__DOT__dut__DOT__disp__DOT__q_cycles;
    VlUnpacked<CData/*0:0*/, 8> top_tb__DOT__dut__DOT__disp__DOT__q_valid;
    VlUnpacked<VlUnpacked<CData/*0:0*/, 2>, 2> top_tb__DOT__dut__DOT__disp__DOT__chain_busy;
    VlUnpacked<VlUnpacked<IData/*31:0*/, 2>, 2> top_tb__DOT__dut__DOT__disp__DOT__chain_timer;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h5710a71e__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_tb___024root(Vtop_tb__Syms* symsp, const char* v__name);
    ~Vtop_tb___024root();
    VL_UNCOPYABLE(Vtop_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
