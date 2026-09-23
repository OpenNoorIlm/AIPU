// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_tb.h for the primary calling header

#include "Vtop_tb__pch.h"
#include "Vtop_tb___024root.h"

VL_ATTR_COLD void Vtop_tb___024root___eval_initial__TOP(Vtop_tb___024root* vlSelf);
VlCoroutine Vtop_tb___024root___eval_initial__TOP__Vtiming__0(Vtop_tb___024root* vlSelf);
VlCoroutine Vtop_tb___024root___eval_initial__TOP__Vtiming__1(Vtop_tb___024root* vlSelf);
VlCoroutine Vtop_tb___024root___eval_initial__TOP__Vtiming__2(Vtop_tb___024root* vlSelf);

void Vtop_tb___024root___eval_initial(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_tb___024root___eval_initial__TOP(vlSelf);
    Vtop_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtop_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtop_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__top_tb__DOT__clk__0 
        = vlSelfRef.top_tb__DOT__clk;
}

VL_INLINE_OPT VlCoroutine Vtop_tb___024root___eval_initial__TOP__Vtiming__0(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ top_tb__DOT__fire__Vstatic__t;
    top_tb__DOT__fire__Vstatic__t = 0;
    IData/*31:0*/ top_tb__DOT__pass;
    top_tb__DOT__pass = 0;
    IData/*31:0*/ top_tb__DOT__fail;
    top_tb__DOT__fail = 0;
    IData/*31:0*/ top_tb__DOT__ii;
    top_tb__DOT__ii = 0;
    IData/*31:0*/ top_tb__DOT__raw;
    top_tb__DOT__raw = 0;
    double top_tb__DOT__got;
    top_tb__DOT__got = 0;
    SData/*9:0*/ __Vtask_top_tb__DOT__dump_sram__2__base;
    __Vtask_top_tb__DOT__dump_sram__2__base = 0;
    SData/*9:0*/ __Vtask_top_tb__DOT__dump_sram__5__base;
    __Vtask_top_tb__DOT__dump_sram__5__base = 0;
    double __Vfunc_top_tb__DOT__fp32_to_real__6__Vfuncout;
    __Vfunc_top_tb__DOT__fp32_to_real__6__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_top_tb__DOT__fp32_to_real__6__b;
    __Vfunc_top_tb__DOT__fp32_to_real__6__b = 0;
    SData/*9:0*/ __Vtask_top_tb__DOT__dump_sram__9__base;
    __Vtask_top_tb__DOT__dump_sram__9__base = 0;
    double __Vfunc_top_tb__DOT__fp32_to_real__10__Vfuncout;
    __Vfunc_top_tb__DOT__fp32_to_real__10__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_top_tb__DOT__fp32_to_real__10__b;
    __Vfunc_top_tb__DOT__fp32_to_real__10__b = 0;
    SData/*9:0*/ __Vtask_top_tb__DOT__dump_sram__13__base;
    __Vtask_top_tb__DOT__dump_sram__13__base = 0;
    double __Vfunc_top_tb__DOT__fp32_to_real__14__Vfuncout;
    __Vfunc_top_tb__DOT__fp32_to_real__14__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_top_tb__DOT__fp32_to_real__14__b;
    __Vfunc_top_tb__DOT__fp32_to_real__14__b = 0;
    // Body
    top_tb__DOT__pass = 0U;
    top_tb__DOT__fail = 0U;
    vlSelfRef.top_tb__DOT__reset = 1U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    vlSelfRef.top_tb__DOT__reset = 0U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    VL_WRITEF_NX("\n=== T1: INT8 identity ===\n",0);
    top_tb__DOT__ii = 0U;
    while (VL_GTS_III(32, 0x400U, top_tb__DOT__ii)) {
        vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU & top_tb__DOT__ii)] = 0U;
        top_tb__DOT__ii = ((IData)(1U) + top_tb__DOT__ii);
    }
    vlSelfRef.top_tb__DOT__mem_arr[0U] = 1U;
    vlSelfRef.top_tb__DOT__mem_arr[0x10U] = 1U;
    top_tb__DOT__ii = 1U;
    vlSelfRef.top_tb__DOT__mem_arr[5U] = 1U;
    vlSelfRef.top_tb__DOT__mem_arr[0x15U] = 1U;
    top_tb__DOT__ii = 2U;
    vlSelfRef.top_tb__DOT__mem_arr[0xaU] = 1U;
    vlSelfRef.top_tb__DOT__mem_arr[0x1aU] = 1U;
    top_tb__DOT__ii = 3U;
    vlSelfRef.top_tb__DOT__mem_arr[0xfU] = 1U;
    vlSelfRef.top_tb__DOT__mem_arr[0x1fU] = 1U;
    top_tb__DOT__ii = 4U;
    vlSelfRef.top_tb__DOT__precision = 0U;
    top_tb__DOT__fire__Vstatic__t = 0U;
    while (((8U == (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count)) 
            & VL_GTS_III(32, 0x3e8U, top_tb__DOT__fire__Vstatic__t))) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             63);
        top_tb__DOT__fire__Vstatic__t = ((IData)(1U) 
                                         + top_tb__DOT__fire__Vstatic__t);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         64);
    vlSelfRef.top_tb__DOT__task_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         65);
    vlSelfRef.top_tb__DOT__task_valid = 0U;
    top_tb__DOT__fire__Vstatic__t = 0U;
    while (((~ (IData)(vlSelfRef.top_tb__DOT__task_accepted)) 
            & VL_GTS_III(32, 0xc8U, top_tb__DOT__fire__Vstatic__t))) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             67);
        top_tb__DOT__fire__Vstatic__t = ((IData)(1U) 
                                         + top_tb__DOT__fire__Vstatic__t);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.top_tb__DOT__task_accepted))))) {
        VL_WRITEF_NX("  [fire] WARN task_accepted never fired\n",0);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         70);
    vlSelfRef.top_tb__DOT__mem_start = 1U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         71);
    vlSelfRef.top_tb__DOT__mem_start = 0U;
    top_tb__DOT__fire__Vstatic__t = 0U;
    while (((~ (IData)(vlSelfRef.top_tb__DOT__mem_done)) 
            & VL_GTS_III(32, 0x2710U, top_tb__DOT__fire__Vstatic__t))) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             73);
        top_tb__DOT__fire__Vstatic__t = ((IData)(1U) 
                                         + top_tb__DOT__fire__Vstatic__t);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.top_tb__DOT__mem_done))))) {
        VL_WRITEF_NX("  [fire] WARN mem_done never fired\n",0);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    __Vtask_top_tb__DOT__dump_sram__2__base = 0x200U;
    VL_WRITEF_NX("  SRAM[%0#..%0#] = %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n",0,
                 10,__Vtask_top_tb__DOT__dump_sram__2__base,
                 32,((IData)(0xfU) + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)),
                 8,vlSelfRef.top_tb__DOT__mem_arr[__Vtask_top_tb__DOT__dump_sram__2__base],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(2U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(3U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(4U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(5U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(6U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(7U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(8U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(9U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xaU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xbU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xcU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xdU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xeU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xfU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__2__base)))]);
    top_tb__DOT__raw = (((vlSelfRef.top_tb__DOT__mem_arr
                          [0x200U] << 0x18U) | (vlSelfRef.top_tb__DOT__mem_arr
                                                [0x201U] 
                                                << 0x10U)) 
                        | ((vlSelfRef.top_tb__DOT__mem_arr
                            [0x202U] << 8U) | vlSelfRef.top_tb__DOT__mem_arr
                           [0x203U]));
    if ((1U == top_tb__DOT__raw)) {
        VL_WRITEF_NX("PASS T1: INT8 I[0][0]=%0d\n",0,
                     32,top_tb__DOT__raw);
        top_tb__DOT__pass = ((IData)(1U) + top_tb__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL T1: INT8 I[0][0]=%0d (exp 1)\n",0,
                     32,top_tb__DOT__raw);
        top_tb__DOT__fail = ((IData)(1U) + top_tb__DOT__fail);
    }
    VL_WRITEF_NX("\n=== T2: FP8 1.0 x 1.0 ===\n",0);
    vlSelfRef.top_tb__DOT__reset = 1U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    vlSelfRef.top_tb__DOT__reset = 0U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    top_tb__DOT__ii = 0U;
    while (VL_GTS_III(32, 0x400U, top_tb__DOT__ii)) {
        vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU & top_tb__DOT__ii)] = 0U;
        top_tb__DOT__ii = ((IData)(1U) + top_tb__DOT__ii);
    }
    vlSelfRef.top_tb__DOT__mem_arr[0U] = 0x38U;
    vlSelfRef.top_tb__DOT__mem_arr[0x10U] = 0x38U;
    top_tb__DOT__ii = 1U;
    vlSelfRef.top_tb__DOT__mem_arr[5U] = 0x38U;
    vlSelfRef.top_tb__DOT__mem_arr[0x15U] = 0x38U;
    top_tb__DOT__ii = 2U;
    vlSelfRef.top_tb__DOT__mem_arr[0xaU] = 0x38U;
    vlSelfRef.top_tb__DOT__mem_arr[0x1aU] = 0x38U;
    top_tb__DOT__ii = 3U;
    vlSelfRef.top_tb__DOT__mem_arr[0xfU] = 0x38U;
    vlSelfRef.top_tb__DOT__mem_arr[0x1fU] = 0x38U;
    top_tb__DOT__ii = 4U;
    vlSelfRef.top_tb__DOT__precision = 1U;
    top_tb__DOT__fire__Vstatic__t = 0U;
    while (((8U == (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count)) 
            & VL_GTS_III(32, 0x3e8U, top_tb__DOT__fire__Vstatic__t))) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             63);
        top_tb__DOT__fire__Vstatic__t = ((IData)(1U) 
                                         + top_tb__DOT__fire__Vstatic__t);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         64);
    vlSelfRef.top_tb__DOT__task_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         65);
    vlSelfRef.top_tb__DOT__task_valid = 0U;
    top_tb__DOT__fire__Vstatic__t = 0U;
    while (((~ (IData)(vlSelfRef.top_tb__DOT__task_accepted)) 
            & VL_GTS_III(32, 0xc8U, top_tb__DOT__fire__Vstatic__t))) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             67);
        top_tb__DOT__fire__Vstatic__t = ((IData)(1U) 
                                         + top_tb__DOT__fire__Vstatic__t);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.top_tb__DOT__task_accepted))))) {
        VL_WRITEF_NX("  [fire] WARN task_accepted never fired\n",0);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         70);
    vlSelfRef.top_tb__DOT__mem_start = 1U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         71);
    vlSelfRef.top_tb__DOT__mem_start = 0U;
    top_tb__DOT__fire__Vstatic__t = 0U;
    while (((~ (IData)(vlSelfRef.top_tb__DOT__mem_done)) 
            & VL_GTS_III(32, 0x2710U, top_tb__DOT__fire__Vstatic__t))) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             73);
        top_tb__DOT__fire__Vstatic__t = ((IData)(1U) 
                                         + top_tb__DOT__fire__Vstatic__t);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.top_tb__DOT__mem_done))))) {
        VL_WRITEF_NX("  [fire] WARN mem_done never fired\n",0);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    __Vtask_top_tb__DOT__dump_sram__5__base = 0x200U;
    VL_WRITEF_NX("  SRAM[%0#..%0#] = %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n",0,
                 10,__Vtask_top_tb__DOT__dump_sram__5__base,
                 32,((IData)(0xfU) + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)),
                 8,vlSelfRef.top_tb__DOT__mem_arr[__Vtask_top_tb__DOT__dump_sram__5__base],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(2U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(3U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(4U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(5U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(6U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(7U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(8U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(9U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xaU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xbU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xcU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xdU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xeU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xfU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__5__base)))]);
    top_tb__DOT__raw = (((vlSelfRef.top_tb__DOT__mem_arr
                          [0x200U] << 0x18U) | (vlSelfRef.top_tb__DOT__mem_arr
                                                [0x201U] 
                                                << 0x10U)) 
                        | ((vlSelfRef.top_tb__DOT__mem_arr
                            [0x202U] << 8U) | vlSelfRef.top_tb__DOT__mem_arr
                           [0x203U]));
    __Vfunc_top_tb__DOT__fp32_to_real__6__b = top_tb__DOT__raw;
    if ((0U == (0x7fffffffU & __Vfunc_top_tb__DOT__fp32_to_real__6__b))) {
        __Vfunc_top_tb__DOT__fp32_to_real__6__Vfuncout = -0.0;
    } else {
        vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__exp 
            = (VL_EXTENDS_II(32,9, (0xffU & (__Vfunc_top_tb__DOT__fp32_to_real__6__b 
                                             >> 0x17U))) 
               - (IData)(0x7fU));
        vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__mant 
            = (1.0 + (VL_ITOR_D_I(23, (0x7fffffU & __Vfunc_top_tb__DOT__fp32_to_real__6__b)) 
                      / 8.38860800000000000e+06));
        vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__r 
            = (vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__mant 
               * pow(2.0,VL_ISTOR_D_I(32, vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__exp)));
        __Vfunc_top_tb__DOT__fp32_to_real__6__Vfuncout 
            = ((__Vfunc_top_tb__DOT__fp32_to_real__6__b 
                >> 0x1fU) ? (- vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__r)
                : vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__r);
    }
    top_tb__DOT__got = __Vfunc_top_tb__DOT__fp32_to_real__6__Vfuncout;
    if (((top_tb__DOT__got > 9.89999999999999991e-01) 
         & (top_tb__DOT__got < 1.01000000000000001e+00))) {
        VL_WRITEF_NX("PASS T2: FP8 1.0x1.0=%f\n",0,
                     64,top_tb__DOT__got);
        top_tb__DOT__pass = ((IData)(1U) + top_tb__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL T2: FP8 1.0x1.0=%f (bits=%x)\n",0,
                     64,top_tb__DOT__got,32,top_tb__DOT__raw);
        top_tb__DOT__fail = ((IData)(1U) + top_tb__DOT__fail);
    }
    VL_WRITEF_NX("\n=== T3: FP8 2.0 x 3.0 ===\n",0);
    vlSelfRef.top_tb__DOT__reset = 1U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    vlSelfRef.top_tb__DOT__reset = 0U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    top_tb__DOT__ii = 0U;
    while (VL_GTS_III(32, 0x400U, top_tb__DOT__ii)) {
        vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU & top_tb__DOT__ii)] = 0U;
        top_tb__DOT__ii = ((IData)(1U) + top_tb__DOT__ii);
    }
    vlSelfRef.top_tb__DOT__mem_arr[0U] = 0x40U;
    vlSelfRef.top_tb__DOT__mem_arr[0x10U] = 0x44U;
    top_tb__DOT__ii = 1U;
    vlSelfRef.top_tb__DOT__mem_arr[5U] = 0x40U;
    vlSelfRef.top_tb__DOT__mem_arr[0x15U] = 0x44U;
    top_tb__DOT__ii = 2U;
    vlSelfRef.top_tb__DOT__mem_arr[0xaU] = 0x40U;
    vlSelfRef.top_tb__DOT__mem_arr[0x1aU] = 0x44U;
    top_tb__DOT__ii = 3U;
    vlSelfRef.top_tb__DOT__mem_arr[0xfU] = 0x40U;
    vlSelfRef.top_tb__DOT__mem_arr[0x1fU] = 0x44U;
    top_tb__DOT__ii = 4U;
    vlSelfRef.top_tb__DOT__precision = 1U;
    top_tb__DOT__fire__Vstatic__t = 0U;
    while (((8U == (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count)) 
            & VL_GTS_III(32, 0x3e8U, top_tb__DOT__fire__Vstatic__t))) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             63);
        top_tb__DOT__fire__Vstatic__t = ((IData)(1U) 
                                         + top_tb__DOT__fire__Vstatic__t);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         64);
    vlSelfRef.top_tb__DOT__task_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         65);
    vlSelfRef.top_tb__DOT__task_valid = 0U;
    top_tb__DOT__fire__Vstatic__t = 0U;
    while (((~ (IData)(vlSelfRef.top_tb__DOT__task_accepted)) 
            & VL_GTS_III(32, 0xc8U, top_tb__DOT__fire__Vstatic__t))) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             67);
        top_tb__DOT__fire__Vstatic__t = ((IData)(1U) 
                                         + top_tb__DOT__fire__Vstatic__t);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.top_tb__DOT__task_accepted))))) {
        VL_WRITEF_NX("  [fire] WARN task_accepted never fired\n",0);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         70);
    vlSelfRef.top_tb__DOT__mem_start = 1U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         71);
    vlSelfRef.top_tb__DOT__mem_start = 0U;
    top_tb__DOT__fire__Vstatic__t = 0U;
    while (((~ (IData)(vlSelfRef.top_tb__DOT__mem_done)) 
            & VL_GTS_III(32, 0x2710U, top_tb__DOT__fire__Vstatic__t))) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             73);
        top_tb__DOT__fire__Vstatic__t = ((IData)(1U) 
                                         + top_tb__DOT__fire__Vstatic__t);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.top_tb__DOT__mem_done))))) {
        VL_WRITEF_NX("  [fire] WARN mem_done never fired\n",0);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    __Vtask_top_tb__DOT__dump_sram__9__base = 0x200U;
    VL_WRITEF_NX("  SRAM[%0#..%0#] = %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n",0,
                 10,__Vtask_top_tb__DOT__dump_sram__9__base,
                 32,((IData)(0xfU) + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)),
                 8,vlSelfRef.top_tb__DOT__mem_arr[__Vtask_top_tb__DOT__dump_sram__9__base],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(2U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(3U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(4U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(5U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(6U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(7U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(8U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(9U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xaU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xbU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xcU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xdU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xeU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xfU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__9__base)))]);
    top_tb__DOT__raw = (((vlSelfRef.top_tb__DOT__mem_arr
                          [0x200U] << 0x18U) | (vlSelfRef.top_tb__DOT__mem_arr
                                                [0x201U] 
                                                << 0x10U)) 
                        | ((vlSelfRef.top_tb__DOT__mem_arr
                            [0x202U] << 8U) | vlSelfRef.top_tb__DOT__mem_arr
                           [0x203U]));
    __Vfunc_top_tb__DOT__fp32_to_real__10__b = top_tb__DOT__raw;
    if ((0U == (0x7fffffffU & __Vfunc_top_tb__DOT__fp32_to_real__10__b))) {
        __Vfunc_top_tb__DOT__fp32_to_real__10__Vfuncout = -0.0;
    } else {
        vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__exp 
            = (VL_EXTENDS_II(32,9, (0xffU & (__Vfunc_top_tb__DOT__fp32_to_real__10__b 
                                             >> 0x17U))) 
               - (IData)(0x7fU));
        vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__mant 
            = (1.0 + (VL_ITOR_D_I(23, (0x7fffffU & __Vfunc_top_tb__DOT__fp32_to_real__10__b)) 
                      / 8.38860800000000000e+06));
        vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__r 
            = (vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__mant 
               * pow(2.0,VL_ISTOR_D_I(32, vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__exp)));
        __Vfunc_top_tb__DOT__fp32_to_real__10__Vfuncout 
            = ((__Vfunc_top_tb__DOT__fp32_to_real__10__b 
                >> 0x1fU) ? (- vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__r)
                : vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__r);
    }
    top_tb__DOT__got = __Vfunc_top_tb__DOT__fp32_to_real__10__Vfuncout;
    if (((top_tb__DOT__got > 5.99000000000000021e+00) 
         & (top_tb__DOT__got < 6.00999999999999979e+00))) {
        VL_WRITEF_NX("PASS T3: FP8 2.0x3.0=%f\n",0,
                     64,top_tb__DOT__got);
        top_tb__DOT__pass = ((IData)(1U) + top_tb__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL T3: FP8 2.0x3.0=%f (bits=%x)\n",0,
                     64,top_tb__DOT__got,32,top_tb__DOT__raw);
        top_tb__DOT__fail = ((IData)(1U) + top_tb__DOT__fail);
    }
    VL_WRITEF_NX("\n=== T4: FP8 -1.0 x 2.0 ===\n",0);
    vlSelfRef.top_tb__DOT__reset = 1U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         54);
    vlSelfRef.top_tb__DOT__reset = 0U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         55);
    top_tb__DOT__ii = 0U;
    while (VL_GTS_III(32, 0x400U, top_tb__DOT__ii)) {
        vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU & top_tb__DOT__ii)] = 0U;
        top_tb__DOT__ii = ((IData)(1U) + top_tb__DOT__ii);
    }
    vlSelfRef.top_tb__DOT__mem_arr[0U] = 0xb8U;
    vlSelfRef.top_tb__DOT__mem_arr[0x10U] = 0x40U;
    top_tb__DOT__ii = 1U;
    vlSelfRef.top_tb__DOT__mem_arr[5U] = 0xb8U;
    vlSelfRef.top_tb__DOT__mem_arr[0x15U] = 0x40U;
    top_tb__DOT__ii = 2U;
    vlSelfRef.top_tb__DOT__mem_arr[0xaU] = 0xb8U;
    vlSelfRef.top_tb__DOT__mem_arr[0x1aU] = 0x40U;
    top_tb__DOT__ii = 3U;
    vlSelfRef.top_tb__DOT__mem_arr[0xfU] = 0xb8U;
    vlSelfRef.top_tb__DOT__mem_arr[0x1fU] = 0x40U;
    top_tb__DOT__ii = 4U;
    vlSelfRef.top_tb__DOT__precision = 1U;
    top_tb__DOT__fire__Vstatic__t = 0U;
    while (((8U == (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count)) 
            & VL_GTS_III(32, 0x3e8U, top_tb__DOT__fire__Vstatic__t))) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             63);
        top_tb__DOT__fire__Vstatic__t = ((IData)(1U) 
                                         + top_tb__DOT__fire__Vstatic__t);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         64);
    vlSelfRef.top_tb__DOT__task_valid = 1U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         65);
    vlSelfRef.top_tb__DOT__task_valid = 0U;
    top_tb__DOT__fire__Vstatic__t = 0U;
    while (((~ (IData)(vlSelfRef.top_tb__DOT__task_accepted)) 
            & VL_GTS_III(32, 0xc8U, top_tb__DOT__fire__Vstatic__t))) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             67);
        top_tb__DOT__fire__Vstatic__t = ((IData)(1U) 
                                         + top_tb__DOT__fire__Vstatic__t);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.top_tb__DOT__task_accepted))))) {
        VL_WRITEF_NX("  [fire] WARN task_accepted never fired\n",0);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         69);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         70);
    vlSelfRef.top_tb__DOT__mem_start = 1U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         71);
    vlSelfRef.top_tb__DOT__mem_start = 0U;
    top_tb__DOT__fire__Vstatic__t = 0U;
    while (((~ (IData)(vlSelfRef.top_tb__DOT__mem_done)) 
            & VL_GTS_III(32, 0x2710U, top_tb__DOT__fire__Vstatic__t))) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             73);
        top_tb__DOT__fire__Vstatic__t = ((IData)(1U) 
                                         + top_tb__DOT__fire__Vstatic__t);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.top_tb__DOT__mem_done))))) {
        VL_WRITEF_NX("  [fire] WARN mem_done never fired\n",0);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         75);
    __Vtask_top_tb__DOT__dump_sram__13__base = 0x200U;
    VL_WRITEF_NX("  SRAM[%0#..%0#] = %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x \n",0,
                 10,__Vtask_top_tb__DOT__dump_sram__13__base,
                 32,((IData)(0xfU) + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)),
                 8,vlSelfRef.top_tb__DOT__mem_arr[__Vtask_top_tb__DOT__dump_sram__13__base],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(2U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(3U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(4U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(5U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(6U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(7U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(8U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(9U) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xaU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xbU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xcU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xdU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xeU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))],
                 8,vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU 
                                                   & ((IData)(0xfU) 
                                                      + (IData)(__Vtask_top_tb__DOT__dump_sram__13__base)))]);
    top_tb__DOT__raw = (((vlSelfRef.top_tb__DOT__mem_arr
                          [0x200U] << 0x18U) | (vlSelfRef.top_tb__DOT__mem_arr
                                                [0x201U] 
                                                << 0x10U)) 
                        | ((vlSelfRef.top_tb__DOT__mem_arr
                            [0x202U] << 8U) | vlSelfRef.top_tb__DOT__mem_arr
                           [0x203U]));
    __Vfunc_top_tb__DOT__fp32_to_real__14__b = top_tb__DOT__raw;
    if ((0U == (0x7fffffffU & __Vfunc_top_tb__DOT__fp32_to_real__14__b))) {
        __Vfunc_top_tb__DOT__fp32_to_real__14__Vfuncout = -0.0;
    } else {
        vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__exp 
            = (VL_EXTENDS_II(32,9, (0xffU & (__Vfunc_top_tb__DOT__fp32_to_real__14__b 
                                             >> 0x17U))) 
               - (IData)(0x7fU));
        vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__mant 
            = (1.0 + (VL_ITOR_D_I(23, (0x7fffffU & __Vfunc_top_tb__DOT__fp32_to_real__14__b)) 
                      / 8.38860800000000000e+06));
        vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__r 
            = (vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__mant 
               * pow(2.0,VL_ISTOR_D_I(32, vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__exp)));
        __Vfunc_top_tb__DOT__fp32_to_real__14__Vfuncout 
            = ((__Vfunc_top_tb__DOT__fp32_to_real__14__b 
                >> 0x1fU) ? (- vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__r)
                : vlSelfRef.top_tb__DOT__fp32_to_real__Vstatic__r);
    }
    top_tb__DOT__got = __Vfunc_top_tb__DOT__fp32_to_real__14__Vfuncout;
    if (((top_tb__DOT__got > -2.00999999999999979e+00) 
         & (top_tb__DOT__got < -1.98999999999999999e+00))) {
        VL_WRITEF_NX("PASS T4: FP8 -1.0x2.0=%f\n",0,
                     64,top_tb__DOT__got);
        top_tb__DOT__pass = ((IData)(1U) + top_tb__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL T4: FP8 -1.0x2.0=%f (bits=%x)\n",0,
                     64,top_tb__DOT__got,32,top_tb__DOT__raw);
        top_tb__DOT__fail = ((IData)(1U) + top_tb__DOT__fail);
    }
    VL_WRITEF_NX("\nResults: %0d/%0d passed\n",0,32,
                 top_tb__DOT__pass,32,(top_tb__DOT__pass 
                                       + top_tb__DOT__fail));
    if ((0U == top_tb__DOT__fail)) {
        VL_WRITEF_NX("ALL PASS\n",0);
    } else {
        VL_WRITEF_NX("FAILURES: %0d\n",0,32,top_tb__DOT__fail);
    }
    VL_FINISH_MT("top_tb.v", 183, "");
}

VL_INLINE_OPT VlCoroutine Vtop_tb___024root___eval_initial__TOP__Vtiming__1(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x2e90edd000ULL, 
                                         nullptr, "top_tb.v", 
                                         186);
    VL_WRITEF_NX("TIMEOUT\n",0);
    VL_FINISH_MT("top_tb.v", 186, "");
}

VL_INLINE_OPT VlCoroutine Vtop_tb___024root___eval_initial__TOP__Vtiming__2(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x4650ULL, 
                                             nullptr, 
                                             "top_tb.v", 
                                             9);
        vlSelfRef.top_tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.top_tb__DOT__clk)));
    }
}

void Vtop_tb___024root___act_sequent__TOP__0(Vtop_tb___024root* vlSelf);

void Vtop_tb___024root___eval_act(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        Vtop_tb___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop_tb___024root___act_sequent__TOP__0(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___act_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top_tb__DOT__sram_rd_data = vlSelfRef.top_tb__DOT__mem_arr
        [((IData)(vlSelfRef.top_tb__DOT__dut__DOT__rs_owns_sram)
           ? (IData)(vlSelfRef.top_tb__DOT__dut__DOT__rs_sram_rd_addr)
           : (IData)(vlSelfRef.top_tb__DOT__dut__DOT__mem_sram_rd_addr))];
}

void Vtop_tb___024root___timing_resume(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___timing_resume\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h5710a71e__0.resume(
                                                   "@(posedge top_tb.clk)");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtop_tb___024root___timing_commit(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___timing_commit\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h5710a71e__0.commit(
                                                   "@(posedge top_tb.clk)");
    }
}

void Vtop_tb___024root___eval_triggers__act(Vtop_tb___024root* vlSelf);

bool Vtop_tb___024root___eval_phase__act(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop_tb___024root___eval_triggers__act(vlSelf);
    Vtop_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop_tb___024root___timing_resume(vlSelf);
        Vtop_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vtop_tb___024root___eval_nba(Vtop_tb___024root* vlSelf);

bool Vtop_tb___024root___eval_phase__nba(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop_tb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_tb___024root___dump_triggers__nba(Vtop_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_tb___024root___dump_triggers__act(Vtop_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_tb___024root___eval(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("top_tb.v", 7, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("top_tb.v", 7, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop_tb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop_tb___024root___eval_debug_assertions(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
