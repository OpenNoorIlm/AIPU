// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_tb.h for the primary calling header

#include "Vtop_tb__pch.h"
#include "Vtop_tb___024root.h"

VlCoroutine Vtop_tb___024root___eval_initial__TOP__Vtiming__0(Vtop_tb___024root* vlSelf);
VlCoroutine Vtop_tb___024root___eval_initial__TOP__Vtiming__1(Vtop_tb___024root* vlSelf);

void Vtop_tb___024root___eval_initial(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtop_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__top_tb__DOT__clk__0 
        = vlSelfRef.top_tb__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top_tb__DOT__reset__0 
        = vlSelfRef.top_tb__DOT__reset;
}

VL_INLINE_OPT VlCoroutine Vtop_tb___024root___eval_initial__TOP__Vtiming__1(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(5ULL, 
                                             nullptr, 
                                             "top_tb.v", 
                                             53);
        vlSelfRef.top_tb__DOT__clk = (1U & (~ (IData)(vlSelfRef.top_tb__DOT__clk)));
    }
}

void Vtop_tb___024root___eval_act(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop_tb___024root___nba_sequent__TOP__0(Vtop_tb___024root* vlSelf);
void Vtop_tb___024root___nba_sequent__TOP__1(Vtop_tb___024root* vlSelf);

void Vtop_tb___024root___eval_nba(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop_tb___024root___nba_sequent__TOP__1(vlSelf);
    }
}

VL_INLINE_OPT void Vtop_tb___024root___nba_sequent__TOP__0(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelfRef.top_tb__DOT__reset))))) {
        VL_WRITEF_NX("time=%0t | accepted=%0b | queue=%0# | full=%0b\n",0,
                     64,VL_TIME_UNITED_Q(1),-12,1,(IData)(vlSelfRef.top_tb__DOT__task_accepted),
                     4,vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count,
                     1,(8U == (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count)));
    }
}

VL_INLINE_OPT void Vtop_tb___024root___nba_sequent__TOP__1(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___nba_sequent__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlUnpacked<VlUnpacked<CData/*0:0*/, 2>, 2> top_tb__DOT__dut__DOT__enable;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            top_tb__DOT__dut__DOT__enable[__Vi0][__Vi1] = 0;
        }
    }
    VlUnpacked<VlUnpacked<CData/*7:0*/, 2>, 2> top_tb__DOT__dut__DOT__active_task;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            top_tb__DOT__dut__DOT__active_task[__Vi0][__Vi1] = 0;
        }
    }
    CData/*2:0*/ __Vdly__top_tb__DOT__dut__DOT__disp__DOT__wr_ptr;
    __Vdly__top_tb__DOT__dut__DOT__disp__DOT__wr_ptr = 0;
    CData/*2:0*/ __Vdly__top_tb__DOT__dut__DOT__disp__DOT__rd_ptr;
    __Vdly__top_tb__DOT__dut__DOT__disp__DOT__rd_ptr = 0;
    CData/*3:0*/ __Vdly__top_tb__DOT__dut__DOT__disp__DOT__count;
    __Vdly__top_tb__DOT__dut__DOT__disp__DOT__count = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__enable__v0;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v0 = 0;
    CData/*7:0*/ __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0;
    __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0 = 0;
    CData/*2:0*/ __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0;
    __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0;
    __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0 = 0;
    IData/*31:0*/ __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__q_cycles__v0;
    __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__q_cycles__v0 = 0;
    CData/*2:0*/ __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_cycles__v0;
    __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_cycles__v0 = 0;
    CData/*2:0*/ __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v8;
    __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v8 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__enable__v4;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v4 = 0;
    IData/*31:0*/ __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v4;
    __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v4 = 0;
    CData/*7:0*/ __VdlyVal__top_tb__DOT__dut__DOT__active_task__v4;
    __VdlyVal__top_tb__DOT__dut__DOT__active_task__v4 = 0;
    CData/*2:0*/ __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v9;
    __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v9 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__enable__v5;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v5 = 0;
    IData/*31:0*/ __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v5;
    __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v5 = 0;
    CData/*7:0*/ __VdlyVal__top_tb__DOT__dut__DOT__active_task__v5;
    __VdlyVal__top_tb__DOT__dut__DOT__active_task__v5 = 0;
    CData/*2:0*/ __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v10;
    __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v10 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__enable__v6;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v6 = 0;
    IData/*31:0*/ __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v6;
    __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v6 = 0;
    CData/*7:0*/ __VdlyVal__top_tb__DOT__dut__DOT__active_task__v6;
    __VdlyVal__top_tb__DOT__dut__DOT__active_task__v6 = 0;
    CData/*2:0*/ __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v11;
    __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v11 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__enable__v7;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v7 = 0;
    IData/*31:0*/ __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v7;
    __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v7 = 0;
    CData/*7:0*/ __VdlyVal__top_tb__DOT__dut__DOT__active_task__v7;
    __VdlyVal__top_tb__DOT__dut__DOT__active_task__v7 = 0;
    CData/*2:0*/ __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v12;
    __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v12 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__enable__v8;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v8 = 0;
    IData/*31:0*/ __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v8;
    __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v8 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v8;
    __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v8 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__enable__v9;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v9 = 0;
    IData/*31:0*/ __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v9;
    __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v9 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v9;
    __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v9 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__enable__v10;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v10 = 0;
    IData/*31:0*/ __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v10;
    __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v10 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v10;
    __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v10 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__enable__v11;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v11 = 0;
    IData/*31:0*/ __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v11;
    __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v11 = 0;
    CData/*0:0*/ __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v11;
    __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v11 = 0;
    // Body
    __Vdly__top_tb__DOT__dut__DOT__disp__DOT__wr_ptr 
        = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__wr_ptr;
    __Vdly__top_tb__DOT__dut__DOT__disp__DOT__rd_ptr 
        = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr;
    __Vdly__top_tb__DOT__dut__DOT__disp__DOT__count 
        = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count;
    __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v8 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v9 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v10 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v11 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v0 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v4 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v5 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v6 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v7 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v8 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v9 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v10 = 0U;
    __VdlySet__top_tb__DOT__dut__DOT__enable__v11 = 0U;
    if (vlSelfRef.top_tb__DOT__reset) {
        __Vdly__top_tb__DOT__dut__DOT__disp__DOT__wr_ptr = 0U;
        __Vdly__top_tb__DOT__dut__DOT__disp__DOT__rd_ptr = 0U;
        __Vdly__top_tb__DOT__dut__DOT__disp__DOT__count = 0U;
        __VdlySet__top_tb__DOT__dut__DOT__enable__v0 = 1U;
        vlSelfRef.top_tb__DOT__task_accepted = 0U;
    } else {
        if (((IData)(vlSelfRef.top_tb__DOT__task_valid) 
             & (~ (IData)(vlSelfRef.top_tb__DOT__queue_full)))) {
            __Vdly__top_tb__DOT__dut__DOT__disp__DOT__count 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count)));
            __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0 
                = vlSelfRef.top_tb__DOT__task_id;
            __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0 
                = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__wr_ptr;
            __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0 = 1U;
            __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__q_cycles__v0 
                = vlSelfRef.top_tb__DOT__task_cycles;
            __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_cycles__v0 
                = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__wr_ptr;
            __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v8 
                = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__wr_ptr;
            __Vdly__top_tb__DOT__dut__DOT__disp__DOT__wr_ptr 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__wr_ptr)));
        }
        if ((0U < (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count))) {
            if (((~ vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy
                  [0U][0U]) & vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid
                 [vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr])) {
                __Vdly__top_tb__DOT__dut__DOT__disp__DOT__count 
                    = (0xfU & ((IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count) 
                               - (IData)(1U)));
                __VdlySet__top_tb__DOT__dut__DOT__enable__v4 = 1U;
                __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v4 
                    = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_cycles
                    [vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr];
                __VdlyVal__top_tb__DOT__dut__DOT__active_task__v4 
                    = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_id
                    [vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr];
                __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v9 
                    = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr;
                __Vdly__top_tb__DOT__dut__DOT__disp__DOT__rd_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr)));
            }
            if (((~ vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy
                  [0U][1U]) & vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid
                 [vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr])) {
                __Vdly__top_tb__DOT__dut__DOT__disp__DOT__count 
                    = (0xfU & ((IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count) 
                               - (IData)(1U)));
                __VdlySet__top_tb__DOT__dut__DOT__enable__v5 = 1U;
                __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v5 
                    = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_cycles
                    [vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr];
                __VdlyVal__top_tb__DOT__dut__DOT__active_task__v5 
                    = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_id
                    [vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr];
                __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v10 
                    = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr;
                __Vdly__top_tb__DOT__dut__DOT__disp__DOT__rd_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr)));
            }
            if (((~ vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy
                  [1U][0U]) & vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid
                 [vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr])) {
                __Vdly__top_tb__DOT__dut__DOT__disp__DOT__count 
                    = (0xfU & ((IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count) 
                               - (IData)(1U)));
                __VdlySet__top_tb__DOT__dut__DOT__enable__v6 = 1U;
                __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v6 
                    = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_cycles
                    [vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr];
                __VdlyVal__top_tb__DOT__dut__DOT__active_task__v6 
                    = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_id
                    [vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr];
                __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v11 
                    = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr;
                __Vdly__top_tb__DOT__dut__DOT__disp__DOT__rd_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr)));
            }
            if (((~ vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy
                  [1U][1U]) & vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid
                 [vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr])) {
                __Vdly__top_tb__DOT__dut__DOT__disp__DOT__count 
                    = (0xfU & ((IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count) 
                               - (IData)(1U)));
                __VdlySet__top_tb__DOT__dut__DOT__enable__v7 = 1U;
                __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v7 
                    = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_cycles
                    [vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr];
                __VdlyVal__top_tb__DOT__dut__DOT__active_task__v7 
                    = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_id
                    [vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr];
                __VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v12 
                    = vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr;
                __Vdly__top_tb__DOT__dut__DOT__disp__DOT__rd_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr)));
            }
        }
        if (vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy
            [0U][0U]) {
            if ((1U >= vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer
                 [0U][0U])) {
                __VdlySet__top_tb__DOT__dut__DOT__enable__v8 = 1U;
            } else {
                __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v8 
                    = (vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer
                       [0U][0U] - (IData)(1U));
                __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v8 = 1U;
            }
        }
        if (vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy
            [0U][1U]) {
            if ((1U >= vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer
                 [0U][1U])) {
                __VdlySet__top_tb__DOT__dut__DOT__enable__v9 = 1U;
            } else {
                __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v9 
                    = (vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer
                       [0U][1U] - (IData)(1U));
                __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v9 = 1U;
            }
        }
        if (vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy
            [1U][0U]) {
            if ((1U >= vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer
                 [1U][0U])) {
                __VdlySet__top_tb__DOT__dut__DOT__enable__v10 = 1U;
            } else {
                __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v10 
                    = (vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer
                       [1U][0U] - (IData)(1U));
                __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v10 = 1U;
            }
        }
        if (vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy
            [1U][1U]) {
            if ((1U >= vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer
                 [1U][1U])) {
                __VdlySet__top_tb__DOT__dut__DOT__enable__v11 = 1U;
            } else {
                __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v11 
                    = (vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer
                       [1U][1U] - (IData)(1U));
                __VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v11 = 1U;
            }
        }
        vlSelfRef.top_tb__DOT__task_accepted = 0U;
        if (((IData)(vlSelfRef.top_tb__DOT__task_valid) 
             & (8U != (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count)))) {
            vlSelfRef.top_tb__DOT__task_accepted = 1U;
        }
    }
    vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__wr_ptr 
        = __Vdly__top_tb__DOT__dut__DOT__disp__DOT__wr_ptr;
    vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__rd_ptr 
        = __Vdly__top_tb__DOT__dut__DOT__disp__DOT__rd_ptr;
    if (__VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v8) {
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer[0U][0U] 
            = __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v8;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v9) {
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer[0U][1U] 
            = __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v9;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v10) {
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer[1U][0U] 
            = __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v10;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v11) {
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer[1U][1U] 
            = __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v11;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0) {
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_id[__VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0] 
            = __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__q_id__v0;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_cycles[__VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_cycles__v0] 
            = __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__q_cycles__v0;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[__VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v8] = 1U;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__enable__v0) {
        top_tb__DOT__dut__DOT__enable[0U][0U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy[0U][0U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer[0U][0U] = 0U;
        top_tb__DOT__dut__DOT__active_task[0U][0U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[0U] = 0U;
        top_tb__DOT__dut__DOT__enable[0U][1U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy[0U][1U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer[0U][1U] = 0U;
        top_tb__DOT__dut__DOT__active_task[0U][1U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[1U] = 0U;
        top_tb__DOT__dut__DOT__enable[1U][0U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy[1U][0U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer[1U][0U] = 0U;
        top_tb__DOT__dut__DOT__active_task[1U][0U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[2U] = 0U;
        top_tb__DOT__dut__DOT__enable[1U][1U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy[1U][1U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer[1U][1U] = 0U;
        top_tb__DOT__dut__DOT__active_task[1U][1U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[3U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[4U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[5U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[6U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[7U] = 0U;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__enable__v4) {
        top_tb__DOT__dut__DOT__enable[0U][0U] = 1U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy[0U][0U] = 1U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer[0U][0U] 
            = __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v4;
        top_tb__DOT__dut__DOT__active_task[0U][0U] 
            = __VdlyVal__top_tb__DOT__dut__DOT__active_task__v4;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[__VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v9] = 0U;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__enable__v5) {
        top_tb__DOT__dut__DOT__enable[0U][1U] = 1U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy[0U][1U] = 1U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer[0U][1U] 
            = __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v5;
        top_tb__DOT__dut__DOT__active_task[0U][1U] 
            = __VdlyVal__top_tb__DOT__dut__DOT__active_task__v5;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[__VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v10] = 0U;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__enable__v6) {
        top_tb__DOT__dut__DOT__enable[1U][0U] = 1U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy[1U][0U] = 1U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer[1U][0U] 
            = __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v6;
        top_tb__DOT__dut__DOT__active_task[1U][0U] 
            = __VdlyVal__top_tb__DOT__dut__DOT__active_task__v6;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[__VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v11] = 0U;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__enable__v7) {
        top_tb__DOT__dut__DOT__enable[1U][1U] = 1U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy[1U][1U] = 1U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_timer[1U][1U] 
            = __VdlyVal__top_tb__DOT__dut__DOT__disp__DOT__chain_timer__v7;
        top_tb__DOT__dut__DOT__active_task[1U][1U] 
            = __VdlyVal__top_tb__DOT__dut__DOT__active_task__v7;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__q_valid[__VdlyDim0__top_tb__DOT__dut__DOT__disp__DOT__q_valid__v12] = 0U;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__enable__v8) {
        top_tb__DOT__dut__DOT__enable[0U][0U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy[0U][0U] = 0U;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__enable__v9) {
        top_tb__DOT__dut__DOT__enable[0U][1U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy[0U][1U] = 0U;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__enable__v10) {
        top_tb__DOT__dut__DOT__enable[1U][0U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy[1U][0U] = 0U;
    }
    if (__VdlySet__top_tb__DOT__dut__DOT__enable__v11) {
        top_tb__DOT__dut__DOT__enable[1U][1U] = 0U;
        vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__chain_busy[1U][1U] = 0U;
    }
    vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count 
        = __Vdly__top_tb__DOT__dut__DOT__disp__DOT__count;
    vlSelfRef.top_tb__DOT__queue_full = (8U == (IData)(vlSelfRef.top_tb__DOT__dut__DOT__disp__DOT__count));
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
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
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
    VlTriggerVec<3> __VpreTriggered;
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
            VL_FATAL_MT("top_tb.v", 1, "", "NBA region did not converge.");
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
                VL_FATAL_MT("top_tb.v", 1, "", "Active region did not converge.");
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
