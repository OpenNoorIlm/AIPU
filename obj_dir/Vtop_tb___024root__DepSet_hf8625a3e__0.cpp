// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_tb.h for the primary calling header

#include "Vtop_tb__pch.h"
#include "Vtop_tb__Syms.h"
#include "Vtop_tb___024root.h"

VL_INLINE_OPT VlCoroutine Vtop_tb___024root___eval_initial__TOP__Vtiming__0(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlUnpacked<CData/*7:0*/, 1024> top_tb__DOT__sram;
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        top_tb__DOT__sram[__Vi0] = 0;
    }
    IData/*31:0*/ top_tb__DOT__i;
    top_tb__DOT__i = 0;
    IData/*31:0*/ top_tb__DOT__unnamedblk1_6__DOT____Vrepeat5;
    top_tb__DOT__unnamedblk1_6__DOT____Vrepeat5 = 0;
    CData/*7:0*/ __Vtask_top_tb__DOT__push_task__0__id;
    __Vtask_top_tb__DOT__push_task__0__id = 0;
    IData/*31:0*/ __Vtask_top_tb__DOT__push_task__0__cycles;
    __Vtask_top_tb__DOT__push_task__0__cycles = 0;
    CData/*7:0*/ __Vtask_top_tb__DOT__push_task__1__id;
    __Vtask_top_tb__DOT__push_task__1__id = 0;
    IData/*31:0*/ __Vtask_top_tb__DOT__push_task__1__cycles;
    __Vtask_top_tb__DOT__push_task__1__cycles = 0;
    CData/*7:0*/ __Vtask_top_tb__DOT__push_task__2__id;
    __Vtask_top_tb__DOT__push_task__2__id = 0;
    IData/*31:0*/ __Vtask_top_tb__DOT__push_task__2__cycles;
    __Vtask_top_tb__DOT__push_task__2__cycles = 0;
    CData/*7:0*/ __Vtask_top_tb__DOT__push_task__3__id;
    __Vtask_top_tb__DOT__push_task__3__id = 0;
    IData/*31:0*/ __Vtask_top_tb__DOT__push_task__3__cycles;
    __Vtask_top_tb__DOT__push_task__3__cycles = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x705f7462U;
    __Vtemp_1[2U] = 0x746fU;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(3, __Vtemp_1));
    VL_PRINTF_MT("-Info: top_tb.v:69: $dumpvar ignored, as Verilated without --trace\n");
    vlSelfRef.top_tb__DOT__clk = 0U;
    vlSelfRef.top_tb__DOT__reset = 1U;
    vlSelfRef.top_tb__DOT__task_valid = 0U;
    vlSelfRef.top_tb__DOT__task_id = 0U;
    vlSelfRef.top_tb__DOT__task_cycles = 0U;
    top_tb__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, top_tb__DOT__i)) {
        top_tb__DOT__sram[(0x3ffU & top_tb__DOT__i)] 
            = (0xffU & top_tb__DOT__i);
        top_tb__DOT__i = ((IData)(1U) + top_tb__DOT__i);
    }
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         83);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         83);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         83);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         83);
    vlSelfRef.top_tb__DOT__reset = 0U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         85);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         85);
    __Vtask_top_tb__DOT__push_task__0__cycles = 0x14U;
    __Vtask_top_tb__DOT__push_task__0__id = 1U;
    vlSelfRef.top_tb__DOT__task_valid = 1U;
    vlSelfRef.top_tb__DOT__task_id = __Vtask_top_tb__DOT__push_task__0__id;
    vlSelfRef.top_tb__DOT__task_cycles = __Vtask_top_tb__DOT__push_task__0__cycles;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         60);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "top_tb.v", 
                                         61);
    vlSelfRef.top_tb__DOT__task_valid = 0U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         89);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         89);
    __Vtask_top_tb__DOT__push_task__1__cycles = 0xfU;
    __Vtask_top_tb__DOT__push_task__1__id = 2U;
    vlSelfRef.top_tb__DOT__task_valid = 1U;
    vlSelfRef.top_tb__DOT__task_id = __Vtask_top_tb__DOT__push_task__1__id;
    vlSelfRef.top_tb__DOT__task_cycles = __Vtask_top_tb__DOT__push_task__1__cycles;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         60);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "top_tb.v", 
                                         61);
    vlSelfRef.top_tb__DOT__task_valid = 0U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         92);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         92);
    __Vtask_top_tb__DOT__push_task__2__cycles = 0xaU;
    __Vtask_top_tb__DOT__push_task__2__id = 3U;
    vlSelfRef.top_tb__DOT__task_valid = 1U;
    vlSelfRef.top_tb__DOT__task_id = __Vtask_top_tb__DOT__push_task__2__id;
    vlSelfRef.top_tb__DOT__task_cycles = __Vtask_top_tb__DOT__push_task__2__cycles;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         60);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "top_tb.v", 
                                         61);
    vlSelfRef.top_tb__DOT__task_valid = 0U;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         95);
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         95);
    __Vtask_top_tb__DOT__push_task__3__cycles = 0x19U;
    __Vtask_top_tb__DOT__push_task__3__id = 4U;
    vlSelfRef.top_tb__DOT__task_valid = 1U;
    vlSelfRef.top_tb__DOT__task_id = __Vtask_top_tb__DOT__push_task__3__id;
    vlSelfRef.top_tb__DOT__task_cycles = __Vtask_top_tb__DOT__push_task__3__cycles;
    co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge top_tb.clk)", 
                                                         "top_tb.v", 
                                                         60);
    co_await vlSelfRef.__VdlySched.delay(1ULL, nullptr, 
                                         "top_tb.v", 
                                         61);
    vlSelfRef.top_tb__DOT__task_valid = 0U;
    top_tb__DOT__unnamedblk1_6__DOT____Vrepeat5 = 0xc8U;
    while (VL_LTS_III(32, 0U, top_tb__DOT__unnamedblk1_6__DOT____Vrepeat5)) {
        co_await vlSelfRef.__VtrigSched_h5710a71e__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge top_tb.clk)", 
                                                             "top_tb.v", 
                                                             101);
        top_tb__DOT__unnamedblk1_6__DOT____Vrepeat5 
            = (top_tb__DOT__unnamedblk1_6__DOT____Vrepeat5 
               - (IData)(1U));
    }
    VL_FINISH_MT("top_tb.v", 103, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_tb___024root___dump_triggers__act(Vtop_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_tb___024root___eval_triggers__act(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.top_tb__DOT__clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top_tb__DOT__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((IData)(vlSelfRef.top_tb__DOT__reset) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__top_tb__DOT__reset__0))));
    vlSelfRef.__VactTriggered.set(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__top_tb__DOT__clk__0 
        = vlSelfRef.top_tb__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__top_tb__DOT__reset__0 
        = vlSelfRef.top_tb__DOT__reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
