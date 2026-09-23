// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_tb.h for the primary calling header

#include "Vtop_tb__pch.h"
#include "Vtop_tb___024root.h"

VL_ATTR_COLD void Vtop_tb___024root___eval_static__TOP(Vtop_tb___024root* vlSelf);

VL_ATTR_COLD void Vtop_tb___024root___eval_static(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_tb___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop_tb___024root___eval_static__TOP(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_static__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top_tb__DOT__clk = 0U;
    vlSelfRef.top_tb__DOT__reset = 1U;
    vlSelfRef.top_tb__DOT__precision = 0U;
    vlSelfRef.top_tb__DOT__task_valid = 0U;
    vlSelfRef.top_tb__DOT__mem_start = 0U;
    vlSelfRef.top_tb__DOT__dut__DOT__rs_owns_sram = 0U;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__boot_cnt = 0U;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__boot_done = 0U;
}

VL_ATTR_COLD void Vtop_tb___024root___eval_initial__TOP(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_initial__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ top_tb__DOT__i;
    top_tb__DOT__i = 0;
    // Body
    top_tb__DOT__i = 0U;
    while (VL_GTS_III(32, 0x400U, top_tb__DOT__i)) {
        vlSelfRef.top_tb__DOT__mem_arr[(0x3ffU & top_tb__DOT__i)] = 0U;
        top_tb__DOT__i = ((IData)(1U) + top_tb__DOT__i);
    }
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__boot_msg[0U] = 0x41U;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__boot_msg[1U] = 0x49U;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__boot_msg[2U] = 0x50U;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__boot_msg[3U] = 0x55U;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__boot_msg[4U] = 0x20U;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__boot_msg[5U] = 0x4fU;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__boot_msg[6U] = 0x4bU;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__boot_msg[7U] = 0xdU;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__boot_msg[8U] = 0xaU;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__hdr_msg[0U] = 0x52U;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__hdr_msg[1U] = 0x45U;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__hdr_msg[2U] = 0x53U;
    vlSelfRef.top_tb__DOT__dut__DOT__rs__DOT__hdr_msg[3U] = 0x3aU;
}

VL_ATTR_COLD void Vtop_tb___024root___eval_final(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_tb___024root___dump_triggers__stl(Vtop_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop_tb___024root___eval_phase__stl(Vtop_tb___024root* vlSelf);

VL_ATTR_COLD void Vtop_tb___024root___eval_settle(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop_tb___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("top_tb.v", 7, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop_tb___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_tb___024root___dump_triggers__stl(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_tb___024root___eval_triggers__stl(Vtop_tb___024root* vlSelf);
VL_ATTR_COLD void Vtop_tb___024root___eval_stl(Vtop_tb___024root* vlSelf);

VL_ATTR_COLD bool Vtop_tb___024root___eval_phase__stl(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop_tb___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop_tb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_tb___024root___dump_triggers__act(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge top_tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_tb___024root___dump_triggers__nba(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge top_tb.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_tb___024root___ctor_var_reset(Vtop_tb___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_tb___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->top_tb__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__reset = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__precision = VL_RAND_RESET_I(2);
    vlSelf->top_tb__DOT__task_valid = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__task_accepted = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__queue_full = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__mem_start = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__mem_done = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__sram_wr_addr = VL_RAND_RESET_I(10);
    vlSelf->top_tb__DOT__sram_wr_en = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__sram_rd_data = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->top_tb__DOT__mem_arr[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top_tb__DOT__fp32_to_real__Vstatic__r = 0;
    vlSelf->top_tb__DOT__fp32_to_real__Vstatic__exp = VL_RAND_RESET_I(32);
    vlSelf->top_tb__DOT__fp32_to_real__Vstatic__mant = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 1; ++__Vi1) {
            vlSelf->top_tb__DOT__dut__DOT__enable[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->top_tb__DOT__dut__DOT__a_in[__Vi0][__Vi1] = VL_RAND_RESET_I(16);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->top_tb__DOT__dut__DOT__b_in[__Vi0][__Vi1] = VL_RAND_RESET_I(16);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 1; ++__Vi1) {
            for (int __Vi2 = 0; __Vi2 < 1; ++__Vi2) {
                for (int __Vi3 = 0; __Vi3 < 4; ++__Vi3) {
                    for (int __Vi4 = 0; __Vi4 < 4; ++__Vi4) {
                        vlSelf->top_tb__DOT__dut__DOT__grid_out[__Vi0][__Vi1][__Vi2][__Vi3][__Vi4] = VL_RAND_RESET_I(32);
                    }
                }
            }
        }
    }
    vlSelf->top_tb__DOT__dut__DOT__mem_sram_rd_addr = VL_RAND_RESET_I(10);
    vlSelf->top_tb__DOT__dut__DOT__rs_sram_rd_addr = VL_RAND_RESET_I(10);
    vlSelf->top_tb__DOT__dut__DOT__mac_reset_w = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__dut__DOT__rs_owns_sram = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__disp__DOT__q_id[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__disp__DOT__q_cycles[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__disp__DOT__q_valid[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->top_tb__DOT__dut__DOT__disp__DOT__wr_ptr = VL_RAND_RESET_I(3);
    vlSelf->top_tb__DOT__dut__DOT__disp__DOT__rd_ptr = VL_RAND_RESET_I(3);
    vlSelf->top_tb__DOT__dut__DOT__disp__DOT__count = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 1; ++__Vi1) {
            vlSelf->top_tb__DOT__dut__DOT__disp__DOT__chain_busy[__Vi0][__Vi1] = VL_RAND_RESET_I(1);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 1; ++__Vi1) {
            vlSelf->top_tb__DOT__dut__DOT__disp__DOT__chain_timer[__Vi0][__Vi1] = VL_RAND_RESET_I(16);
        }
    }
    vlSelf->top_tb__DOT__dut__DOT__disp__DOT__found = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__dut__DOT__disp__DOT____Vlvbound_hb9bcdd83__1 = VL_RAND_RESET_I(16);
    vlSelf->top_tb__DOT__dut__DOT__disp__DOT____Vlvbound_h350ae802__1 = VL_RAND_RESET_I(8);
    vlSelf->top_tb__DOT__dut__DOT__disp__DOT____Vlvbound_hb9bcdd83__2 = VL_RAND_RESET_I(16);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            for (int __Vi2 = 0; __Vi2 < 4; ++__Vi2) {
                vlSelf->top_tb__DOT__dut__DOT__grid__DOT__a_chain[__Vi0][__Vi1][__Vi2] = VL_RAND_RESET_I(16);
            }
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 1; ++__Vi1) {
            for (int __Vi2 = 0; __Vi2 < 4; ++__Vi2) {
                vlSelf->top_tb__DOT__dut__DOT__grid__DOT__b_chain[__Vi0][__Vi1][__Vi2] = VL_RAND_RESET_I(16);
            }
        }
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 1; ++__Vi1) {
            for (int __Vi2 = 0; __Vi2 < 4; ++__Vi2) {
                vlSelf->top_tb__DOT__dut__DOT__grid__DOT__a_gated[__Vi0][__Vi1][__Vi2] = VL_RAND_RESET_I(16);
            }
        }
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 1; ++__Vi1) {
            for (int __Vi2 = 0; __Vi2 < 4; ++__Vi2) {
                vlSelf->top_tb__DOT__dut__DOT__grid__DOT__b_gated[__Vi0][__Vi1][__Vi2] = VL_RAND_RESET_I(16);
            }
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__grid__DOT____Vcellout__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__b_out[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__grid__DOT____Vcellout__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__a_out[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            for (int __Vi2 = 0; __Vi2 < 4; ++__Vi2) {
                vlSelf->top_tb__DOT__dut__DOT__grid__DOT____Vcellout__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__out[__Vi0][__Vi1][__Vi2] = VL_RAND_RESET_I(32);
            }
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__b_in[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__a_in[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__a_chain[__Vi0][__Vi1] = VL_RAND_RESET_I(16);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__b_chain[__Vi0][__Vi1] = VL_RAND_RESET_I(16);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT____Vcellout__tile__BRA__0__KET____DOT__tile_inst__b_out[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT____Vcellout__tile__BRA__0__KET____DOT__tile_inst__a_out[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT____Vcellout__tile__BRA__0__KET____DOT__tile_inst__out[__Vi0][__Vi1] = VL_RAND_RESET_I(32);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT____Vcellinp__tile__BRA__0__KET____DOT__tile_inst__b_in[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT____Vcellinp__tile__BRA__0__KET____DOT__tile_inst__a_in[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 5; ++__Vi1) {
            vlSelf->top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire[__Vi0][__Vi1] = VL_RAND_RESET_I(16);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire[__Vi0][__Vi1] = VL_RAND_RESET_I(16);
        }
    }
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__row_counter = VL_RAND_RESET_I(3);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__mac_idx = VL_RAND_RESET_I(4);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__byte_sel = VL_RAND_RESET_I(2);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__col_counter = VL_RAND_RESET_I(7);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__drain_cnt = VL_RAND_RESET_I(4);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__sel_row = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__sel_col = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__dst_latch = VL_RAND_RESET_I(10);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__src_latch = VL_RAND_RESET_I(10);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__k_iter = VL_RAND_RESET_I(3);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__load_hi = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__wait_rd_next = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__mem__DOT__a_buf[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__mem__DOT__b_buf[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__hi_byte = VL_RAND_RESET_I(8);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT__cur_out = VL_RAND_RESET_I(32);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT____Vlvbound_hb331e65f__0 = VL_RAND_RESET_I(16);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT____Vlvbound_hb331e99d__0 = VL_RAND_RESET_I(16);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT____Vlvbound_hb331e5da__0 = VL_RAND_RESET_I(16);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT____Vlvbound_hb331e720__0 = VL_RAND_RESET_I(16);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT____Vlvbound_h5d9904c3__0 = VL_RAND_RESET_I(16);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT____Vlvbound_h5d990405__0 = VL_RAND_RESET_I(16);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT____Vlvbound_h5d990542__0 = VL_RAND_RESET_I(16);
    vlSelf->top_tb__DOT__dut__DOT__mem__DOT____Vlvbound_h5d990684__0 = VL_RAND_RESET_I(16);
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__tx_valid = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__tx_busy = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 9; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__rs__DOT__boot_msg[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->top_tb__DOT__dut__DOT__rs__DOT__hdr_msg[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__boot_cnt = VL_RAND_RESET_I(26);
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__boot_done = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__boot_idx = VL_RAND_RESET_I(4);
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__hdr_idx = VL_RAND_RESET_I(4);
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__byte_val = VL_RAND_RESET_I(8);
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__byte_count = VL_RAND_RESET_I(8);
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__mem_done_latch = VL_RAND_RESET_I(1);
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__uart__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__uart__DOT__clk_count = VL_RAND_RESET_I(9);
    vlSelf->top_tb__DOT__dut__DOT__rs__DOT__uart__DOT__bit_index = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigprevexpr___TOP__top_tb__DOT__clk__0 = VL_RAND_RESET_I(1);
}
