// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_tb.h for the primary calling header

#include "Vtop_tb__pch.h"
#include "Vtop_tb__Syms.h"
#include "Vtop_tb_mac.h"

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [0U][0U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [0U][0U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__0__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__0__fa;
    __Vfunc_fp8_mul__0__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__0__fb;
    __Vfunc_fp8_mul__0__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__0__sp;
    __Vfunc_fp8_mul__0__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__0__ea;
    __Vfunc_fp8_mul__0__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__0__eb;
    __Vfunc_fp8_mul__0__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__0__ma;
    __Vfunc_fp8_mul__0__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__0__mb;
    __Vfunc_fp8_mul__0__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__2__fa;
    __Vfunc_bf16_mul__2__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__2__fb;
    __Vfunc_bf16_mul__2__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__2__s;
    __Vfunc_bf16_mul__2__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__2__ea;
    __Vfunc_bf16_mul__2__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__2__eb;
    __Vfunc_bf16_mul__2__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__2__ma;
    __Vfunc_bf16_mul__2__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__2__mb;
    __Vfunc_bf16_mul__2__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [0U]
                                                                    [0U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [0U]
                                                                [0U])))));
    __Vfunc_bf16_mul__2__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [0U][0U];
    __Vfunc_bf16_mul__2__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [0U][0U];
    __Vfunc_bf16_mul__2__s = (1U & (((IData)(__Vfunc_bf16_mul__2__fa) 
                                     ^ (IData)(__Vfunc_bf16_mul__2__fb)) 
                                    >> 0xfU));
    __Vfunc_bf16_mul__2__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__2__fa) 
                                        >> 7U));
    __Vfunc_bf16_mul__2__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__2__fa)));
    __Vfunc_bf16_mul__2__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__2__fb) 
                                        >> 7U));
    __Vfunc_bf16_mul__2__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__2__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__2__ea)) | 
         (0U == (IData)(__Vfunc_bf16_mul__2__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__2__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__2__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__2__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__2__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_bf16_mul__2__s) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__2__ep = (0xffU 
                                             & (((IData)(__Vfunc_bf16_mul__2__ea) 
                                                 + (IData)(__Vfunc_bf16_mul__2__eb)) 
                                                - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__2__mp = (0xffffU 
                                             & ((IData)(__Vfunc_bf16_mul__2__ma) 
                                                * (IData)(__Vfunc_bf16_mul__2__mb)));
        vlSelfRef.__Vfunc_bf16_mul__2__Vfuncout = (
                                                   (0x8000U 
                                                    & (IData)(vlSelfRef.__Vfunc_bf16_mul__2__mp))
                                                    ? 
                                                   (((IData)(__Vfunc_bf16_mul__2__s) 
                                                     << 0x1fU) 
                                                    | ((0x7f800000U 
                                                        & (((IData)(1U) 
                                                            + (IData)(vlSelfRef.__Vfunc_bf16_mul__2__ep)) 
                                                           << 0x17U)) 
                                                       | (0x7f0000U 
                                                          & ((IData)(vlSelfRef.__Vfunc_bf16_mul__2__mp) 
                                                             << 8U))))
                                                    : 
                                                   (((IData)(__Vfunc_bf16_mul__2__s) 
                                                     << 0x1fU) 
                                                    | (((IData)(vlSelfRef.__Vfunc_bf16_mul__2__ep) 
                                                        << 0x17U) 
                                                       | (0x7f0000U 
                                                          & ((IData)(vlSelfRef.__Vfunc_bf16_mul__2__mp) 
                                                             << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__2__Vfuncout;
    __Vfunc_fp8_mul__0__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                              [0U][0U]);
    __Vfunc_fp8_mul__0__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                              [0U][0U]);
    __Vfunc_fp8_mul__0__sp = (1U & (((IData)(__Vfunc_fp8_mul__0__fa) 
                                     ^ (IData)(__Vfunc_fp8_mul__0__fb)) 
                                    >> 7U));
    __Vfunc_fp8_mul__0__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__0__fa) 
                                      >> 3U));
    __Vfunc_fp8_mul__0__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__0__fa)));
    __Vfunc_fp8_mul__0__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__0__fb) 
                                      >> 3U));
    __Vfunc_fp8_mul__0__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__0__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__0__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__0__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__0__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__0__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__0__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__0__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__0__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__0__Vfuncout = (0x7fc00000U 
                                                  | ((IData)(__Vfunc_fp8_mul__0__sp) 
                                                     << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__0__ep = (0x1ffU 
                                            & ((IData)(0x71U) 
                                               + ((IData)(__Vfunc_fp8_mul__0__ea) 
                                                  + (IData)(__Vfunc_fp8_mul__0__eb))));
        vlSelfRef.__Vfunc_fp8_mul__0__mp = (0xffU & 
                                            ((IData)(__Vfunc_fp8_mul__0__ma) 
                                             * (IData)(__Vfunc_fp8_mul__0__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__0__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__0__e32 = (0xffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelfRef.__Vfunc_fp8_mul__0__ep)));
            vlSelfRef.__Vfunc_fp8_mul__0__m32 = (0x7f0000U 
                                                 & ((IData)(vlSelfRef.__Vfunc_fp8_mul__0__mp) 
                                                    << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__0__e32 = (0xffU 
                                                 & (IData)(vlSelfRef.__Vfunc_fp8_mul__0__ep));
            vlSelfRef.__Vfunc_fp8_mul__0__m32 = (0x7e0000U 
                                                 & ((IData)(vlSelfRef.__Vfunc_fp8_mul__0__mp) 
                                                    << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__0__Vfuncout = (((IData)(__Vfunc_fp8_mul__0__sp) 
                                                   << 0x1fU) 
                                                  | (((IData)(vlSelfRef.__Vfunc_fp8_mul__0__e32) 
                                                      << 0x17U) 
                                                     | vlSelfRef.__Vfunc_fp8_mul__0__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__0__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__3__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__3__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__3__sx = 
                    (vlSelfRef.__Vfunc_fp32_add__3__x 
                     >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__3__ex = 
                    (0xffU & (vlSelfRef.__Vfunc_fp32_add__3__x 
                              >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__3__mx = 
                    (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__3__x);
                vlSelfRef.__Vfunc_fp32_add__3__sy = 
                    (vlSelfRef.__Vfunc_fp32_add__3__y 
                     >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__3__ey = 
                    (0xffU & (vlSelfRef.__Vfunc_fp32_add__3__y 
                              >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__3__my = 
                    (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__3__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__3__x))) {
                    vlSelfRef.__Vfunc_fp32_add__3__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__3__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__3__y))) {
                    vlSelfRef.__Vfunc_fp32_add__3__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__3__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__3__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__3__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__3__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__3__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__3__ey)));
                        vlSelfRef.__Vfunc_fp32_add__3__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__3__ex;
                        vlSelfRef.__Vfunc_fp32_add__3__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__3__sx;
                        vlSelfRef.__Vfunc_fp32_add__3__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__3__mx);
                        vlSelfRef.__Vfunc_fp32_add__3__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__3__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__3__my), (IData)(vlSelfRef.__Vfunc_fp32_add__3__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__3__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__3__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__3__ex)));
                        vlSelfRef.__Vfunc_fp32_add__3__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__3__ey;
                        vlSelfRef.__Vfunc_fp32_add__3__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__3__sy;
                        vlSelfRef.__Vfunc_fp32_add__3__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__3__my);
                        vlSelfRef.__Vfunc_fp32_add__3__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__3__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__3__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__3__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__3__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__3__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__3__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__3__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__3__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__3__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__3__ay));
                        vlSelfRef.__Vfunc_fp32_add__3__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__3__s_big;
                        vlSelfRef.__Vfunc_fp32_add__3__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__3__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__3__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__3__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__3__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__3__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__3__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__3__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__3__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__3__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__3__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__3__ay));
                            vlSelfRef.__Vfunc_fp32_add__3__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__3__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__3__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__3__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__3__ax));
                            vlSelfRef.__Vfunc_fp32_add__3__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__3__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__3__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__3__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__3__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__3__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__3__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__3__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__3__sh)));
                            vlSelfRef.__Vfunc_fp32_add__3__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__3__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__3__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__3__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__3__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__3__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__3__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__3__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__1__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__1__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__1__sx = 
                    (vlSelfRef.__Vfunc_fp32_add__1__x 
                     >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__1__ex = 
                    (0xffU & (vlSelfRef.__Vfunc_fp32_add__1__x 
                              >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__1__mx = 
                    (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__1__x);
                vlSelfRef.__Vfunc_fp32_add__1__sy = 
                    (vlSelfRef.__Vfunc_fp32_add__1__y 
                     >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__1__ey = 
                    (0xffU & (vlSelfRef.__Vfunc_fp32_add__1__y 
                              >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__1__my = 
                    (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__1__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__1__x))) {
                    vlSelfRef.__Vfunc_fp32_add__1__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__1__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__1__y))) {
                    vlSelfRef.__Vfunc_fp32_add__1__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__1__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__1__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__1__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__1__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__1__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__1__ey)));
                        vlSelfRef.__Vfunc_fp32_add__1__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__1__ex;
                        vlSelfRef.__Vfunc_fp32_add__1__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__1__sx;
                        vlSelfRef.__Vfunc_fp32_add__1__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__1__mx);
                        vlSelfRef.__Vfunc_fp32_add__1__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__1__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__1__my), (IData)(vlSelfRef.__Vfunc_fp32_add__1__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__1__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__1__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__1__ex)));
                        vlSelfRef.__Vfunc_fp32_add__1__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__1__ey;
                        vlSelfRef.__Vfunc_fp32_add__1__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__1__sy;
                        vlSelfRef.__Vfunc_fp32_add__1__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__1__my);
                        vlSelfRef.__Vfunc_fp32_add__1__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__1__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__1__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__1__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__1__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__1__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__1__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__1__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__1__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__1__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__1__ay));
                        vlSelfRef.__Vfunc_fp32_add__1__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__1__s_big;
                        vlSelfRef.__Vfunc_fp32_add__1__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__1__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__1__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__1__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__1__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__1__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__1__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__1__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__1__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__1__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__1__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__1__ay));
                            vlSelfRef.__Vfunc_fp32_add__1__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__1__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__1__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__1__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__1__ax));
                            vlSelfRef.__Vfunc_fp32_add__1__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__1__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__1__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__1__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__1__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__1__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__1__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__1__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__1__sh)));
                            vlSelfRef.__Vfunc_fp32_add__1__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__1__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__1__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__1__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__1__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__1__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__1__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__1__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [0U][1U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [0U][1U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__1__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__4__fa;
    __Vfunc_fp8_mul__4__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__4__fb;
    __Vfunc_fp8_mul__4__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__4__sp;
    __Vfunc_fp8_mul__4__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__4__ea;
    __Vfunc_fp8_mul__4__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__4__eb;
    __Vfunc_fp8_mul__4__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__4__ma;
    __Vfunc_fp8_mul__4__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__4__mb;
    __Vfunc_fp8_mul__4__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__6__fa;
    __Vfunc_bf16_mul__6__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__6__fb;
    __Vfunc_bf16_mul__6__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__6__s;
    __Vfunc_bf16_mul__6__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__6__ea;
    __Vfunc_bf16_mul__6__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__6__eb;
    __Vfunc_bf16_mul__6__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__6__ma;
    __Vfunc_bf16_mul__6__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__6__mb;
    __Vfunc_bf16_mul__6__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [0U]
                                                                    [1U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [0U]
                                                                [1U])))));
    __Vfunc_bf16_mul__6__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [0U][1U];
    __Vfunc_bf16_mul__6__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [0U][1U];
    __Vfunc_bf16_mul__6__s = (1U & (((IData)(__Vfunc_bf16_mul__6__fa) 
                                     ^ (IData)(__Vfunc_bf16_mul__6__fb)) 
                                    >> 0xfU));
    __Vfunc_bf16_mul__6__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__6__fa) 
                                        >> 7U));
    __Vfunc_bf16_mul__6__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__6__fa)));
    __Vfunc_bf16_mul__6__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__6__fb) 
                                        >> 7U));
    __Vfunc_bf16_mul__6__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__6__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__6__ea)) | 
         (0U == (IData)(__Vfunc_bf16_mul__6__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__6__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__6__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__6__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__6__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_bf16_mul__6__s) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__6__ep = (0xffU 
                                             & (((IData)(__Vfunc_bf16_mul__6__ea) 
                                                 + (IData)(__Vfunc_bf16_mul__6__eb)) 
                                                - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__6__mp = (0xffffU 
                                             & ((IData)(__Vfunc_bf16_mul__6__ma) 
                                                * (IData)(__Vfunc_bf16_mul__6__mb)));
        vlSelfRef.__Vfunc_bf16_mul__6__Vfuncout = (
                                                   (0x8000U 
                                                    & (IData)(vlSelfRef.__Vfunc_bf16_mul__6__mp))
                                                    ? 
                                                   (((IData)(__Vfunc_bf16_mul__6__s) 
                                                     << 0x1fU) 
                                                    | ((0x7f800000U 
                                                        & (((IData)(1U) 
                                                            + (IData)(vlSelfRef.__Vfunc_bf16_mul__6__ep)) 
                                                           << 0x17U)) 
                                                       | (0x7f0000U 
                                                          & ((IData)(vlSelfRef.__Vfunc_bf16_mul__6__mp) 
                                                             << 8U))))
                                                    : 
                                                   (((IData)(__Vfunc_bf16_mul__6__s) 
                                                     << 0x1fU) 
                                                    | (((IData)(vlSelfRef.__Vfunc_bf16_mul__6__ep) 
                                                        << 0x17U) 
                                                       | (0x7f0000U 
                                                          & ((IData)(vlSelfRef.__Vfunc_bf16_mul__6__mp) 
                                                             << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__6__Vfuncout;
    __Vfunc_fp8_mul__4__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                              [0U][1U]);
    __Vfunc_fp8_mul__4__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                              [0U][1U]);
    __Vfunc_fp8_mul__4__sp = (1U & (((IData)(__Vfunc_fp8_mul__4__fa) 
                                     ^ (IData)(__Vfunc_fp8_mul__4__fb)) 
                                    >> 7U));
    __Vfunc_fp8_mul__4__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__4__fa) 
                                      >> 3U));
    __Vfunc_fp8_mul__4__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__4__fa)));
    __Vfunc_fp8_mul__4__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__4__fb) 
                                      >> 3U));
    __Vfunc_fp8_mul__4__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__4__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__4__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__4__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__4__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__4__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__4__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__4__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__4__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__4__Vfuncout = (0x7fc00000U 
                                                  | ((IData)(__Vfunc_fp8_mul__4__sp) 
                                                     << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__4__ep = (0x1ffU 
                                            & ((IData)(0x71U) 
                                               + ((IData)(__Vfunc_fp8_mul__4__ea) 
                                                  + (IData)(__Vfunc_fp8_mul__4__eb))));
        vlSelfRef.__Vfunc_fp8_mul__4__mp = (0xffU & 
                                            ((IData)(__Vfunc_fp8_mul__4__ma) 
                                             * (IData)(__Vfunc_fp8_mul__4__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__4__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__4__e32 = (0xffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelfRef.__Vfunc_fp8_mul__4__ep)));
            vlSelfRef.__Vfunc_fp8_mul__4__m32 = (0x7f0000U 
                                                 & ((IData)(vlSelfRef.__Vfunc_fp8_mul__4__mp) 
                                                    << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__4__e32 = (0xffU 
                                                 & (IData)(vlSelfRef.__Vfunc_fp8_mul__4__ep));
            vlSelfRef.__Vfunc_fp8_mul__4__m32 = (0x7e0000U 
                                                 & ((IData)(vlSelfRef.__Vfunc_fp8_mul__4__mp) 
                                                    << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__4__Vfuncout = (((IData)(__Vfunc_fp8_mul__4__sp) 
                                                   << 0x1fU) 
                                                  | (((IData)(vlSelfRef.__Vfunc_fp8_mul__4__e32) 
                                                      << 0x17U) 
                                                     | vlSelfRef.__Vfunc_fp8_mul__4__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__4__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__7__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__7__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__7__sx = 
                    (vlSelfRef.__Vfunc_fp32_add__7__x 
                     >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__7__ex = 
                    (0xffU & (vlSelfRef.__Vfunc_fp32_add__7__x 
                              >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__7__mx = 
                    (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__7__x);
                vlSelfRef.__Vfunc_fp32_add__7__sy = 
                    (vlSelfRef.__Vfunc_fp32_add__7__y 
                     >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__7__ey = 
                    (0xffU & (vlSelfRef.__Vfunc_fp32_add__7__y 
                              >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__7__my = 
                    (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__7__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__7__x))) {
                    vlSelfRef.__Vfunc_fp32_add__7__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__7__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__7__y))) {
                    vlSelfRef.__Vfunc_fp32_add__7__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__7__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__7__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__7__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__7__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__7__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__7__ey)));
                        vlSelfRef.__Vfunc_fp32_add__7__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__7__ex;
                        vlSelfRef.__Vfunc_fp32_add__7__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__7__sx;
                        vlSelfRef.__Vfunc_fp32_add__7__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__7__mx);
                        vlSelfRef.__Vfunc_fp32_add__7__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__7__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__7__my), (IData)(vlSelfRef.__Vfunc_fp32_add__7__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__7__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__7__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__7__ex)));
                        vlSelfRef.__Vfunc_fp32_add__7__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__7__ey;
                        vlSelfRef.__Vfunc_fp32_add__7__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__7__sy;
                        vlSelfRef.__Vfunc_fp32_add__7__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__7__my);
                        vlSelfRef.__Vfunc_fp32_add__7__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__7__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__7__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__7__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__7__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__7__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__7__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__7__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__7__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__7__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__7__ay));
                        vlSelfRef.__Vfunc_fp32_add__7__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__7__s_big;
                        vlSelfRef.__Vfunc_fp32_add__7__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__7__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__7__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__7__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__7__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__7__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__7__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__7__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__7__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__7__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__7__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__7__ay));
                            vlSelfRef.__Vfunc_fp32_add__7__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__7__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__7__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__7__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__7__ax));
                            vlSelfRef.__Vfunc_fp32_add__7__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__7__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__7__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__7__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__7__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__7__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__7__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__7__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__7__sh)));
                            vlSelfRef.__Vfunc_fp32_add__7__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__7__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__7__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__7__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__7__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__7__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__7__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__7__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__5__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__5__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__5__sx = 
                    (vlSelfRef.__Vfunc_fp32_add__5__x 
                     >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__5__ex = 
                    (0xffU & (vlSelfRef.__Vfunc_fp32_add__5__x 
                              >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__5__mx = 
                    (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__5__x);
                vlSelfRef.__Vfunc_fp32_add__5__sy = 
                    (vlSelfRef.__Vfunc_fp32_add__5__y 
                     >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__5__ey = 
                    (0xffU & (vlSelfRef.__Vfunc_fp32_add__5__y 
                              >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__5__my = 
                    (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__5__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__5__x))) {
                    vlSelfRef.__Vfunc_fp32_add__5__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__5__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__5__y))) {
                    vlSelfRef.__Vfunc_fp32_add__5__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__5__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__5__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__5__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__5__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__5__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__5__ey)));
                        vlSelfRef.__Vfunc_fp32_add__5__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__5__ex;
                        vlSelfRef.__Vfunc_fp32_add__5__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__5__sx;
                        vlSelfRef.__Vfunc_fp32_add__5__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__5__mx);
                        vlSelfRef.__Vfunc_fp32_add__5__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__5__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__5__my), (IData)(vlSelfRef.__Vfunc_fp32_add__5__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__5__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__5__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__5__ex)));
                        vlSelfRef.__Vfunc_fp32_add__5__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__5__ey;
                        vlSelfRef.__Vfunc_fp32_add__5__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__5__sy;
                        vlSelfRef.__Vfunc_fp32_add__5__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__5__my);
                        vlSelfRef.__Vfunc_fp32_add__5__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__5__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__5__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__5__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__5__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__5__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__5__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__5__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__5__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__5__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__5__ay));
                        vlSelfRef.__Vfunc_fp32_add__5__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__5__s_big;
                        vlSelfRef.__Vfunc_fp32_add__5__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__5__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__5__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__5__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__5__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__5__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__5__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__5__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__5__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__5__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__5__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__5__ay));
                            vlSelfRef.__Vfunc_fp32_add__5__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__5__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__5__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__5__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__5__ax));
                            vlSelfRef.__Vfunc_fp32_add__5__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__5__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__5__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__5__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__5__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__5__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__5__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__5__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__5__sh)));
                            vlSelfRef.__Vfunc_fp32_add__5__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__5__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__5__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__5__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__5__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__5__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__5__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__5__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [0U][2U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [0U][2U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__2__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__8__fa;
    __Vfunc_fp8_mul__8__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__8__fb;
    __Vfunc_fp8_mul__8__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__8__sp;
    __Vfunc_fp8_mul__8__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__8__ea;
    __Vfunc_fp8_mul__8__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__8__eb;
    __Vfunc_fp8_mul__8__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__8__ma;
    __Vfunc_fp8_mul__8__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__8__mb;
    __Vfunc_fp8_mul__8__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__10__fa;
    __Vfunc_bf16_mul__10__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__10__fb;
    __Vfunc_bf16_mul__10__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__10__s;
    __Vfunc_bf16_mul__10__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__10__ea;
    __Vfunc_bf16_mul__10__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__10__eb;
    __Vfunc_bf16_mul__10__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__10__ma;
    __Vfunc_bf16_mul__10__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__10__mb;
    __Vfunc_bf16_mul__10__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [0U]
                                                                    [2U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [0U]
                                                                [2U])))));
    __Vfunc_bf16_mul__10__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [0U][2U];
    __Vfunc_bf16_mul__10__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [0U][2U];
    __Vfunc_bf16_mul__10__s = (1U & (((IData)(__Vfunc_bf16_mul__10__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__10__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__10__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__10__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__10__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__10__fa)));
    __Vfunc_bf16_mul__10__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__10__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__10__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__10__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__10__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__10__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__10__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__10__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__10__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__10__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__10__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__10__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__10__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__10__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__10__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__10__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__10__mb)));
        vlSelfRef.__Vfunc_bf16_mul__10__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__10__mp))
              ? (((IData)(__Vfunc_bf16_mul__10__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__10__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__10__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__10__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__10__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__10__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__10__Vfuncout;
    __Vfunc_fp8_mul__8__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                              [0U][2U]);
    __Vfunc_fp8_mul__8__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                              [0U][2U]);
    __Vfunc_fp8_mul__8__sp = (1U & (((IData)(__Vfunc_fp8_mul__8__fa) 
                                     ^ (IData)(__Vfunc_fp8_mul__8__fb)) 
                                    >> 7U));
    __Vfunc_fp8_mul__8__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__8__fa) 
                                      >> 3U));
    __Vfunc_fp8_mul__8__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__8__fa)));
    __Vfunc_fp8_mul__8__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__8__fb) 
                                      >> 3U));
    __Vfunc_fp8_mul__8__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__8__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__8__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__8__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__8__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__8__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__8__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__8__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__8__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__8__Vfuncout = (0x7fc00000U 
                                                  | ((IData)(__Vfunc_fp8_mul__8__sp) 
                                                     << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__8__ep = (0x1ffU 
                                            & ((IData)(0x71U) 
                                               + ((IData)(__Vfunc_fp8_mul__8__ea) 
                                                  + (IData)(__Vfunc_fp8_mul__8__eb))));
        vlSelfRef.__Vfunc_fp8_mul__8__mp = (0xffU & 
                                            ((IData)(__Vfunc_fp8_mul__8__ma) 
                                             * (IData)(__Vfunc_fp8_mul__8__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__8__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__8__e32 = (0xffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelfRef.__Vfunc_fp8_mul__8__ep)));
            vlSelfRef.__Vfunc_fp8_mul__8__m32 = (0x7f0000U 
                                                 & ((IData)(vlSelfRef.__Vfunc_fp8_mul__8__mp) 
                                                    << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__8__e32 = (0xffU 
                                                 & (IData)(vlSelfRef.__Vfunc_fp8_mul__8__ep));
            vlSelfRef.__Vfunc_fp8_mul__8__m32 = (0x7e0000U 
                                                 & ((IData)(vlSelfRef.__Vfunc_fp8_mul__8__mp) 
                                                    << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__8__Vfuncout = (((IData)(__Vfunc_fp8_mul__8__sp) 
                                                   << 0x1fU) 
                                                  | (((IData)(vlSelfRef.__Vfunc_fp8_mul__8__e32) 
                                                      << 0x17U) 
                                                     | vlSelfRef.__Vfunc_fp8_mul__8__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__8__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__11__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__11__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__11__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__11__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__11__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__11__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__11__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__11__x);
                vlSelfRef.__Vfunc_fp32_add__11__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__11__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__11__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__11__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__11__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__11__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__11__x))) {
                    vlSelfRef.__Vfunc_fp32_add__11__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__11__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__11__y))) {
                    vlSelfRef.__Vfunc_fp32_add__11__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__11__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__11__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__11__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__11__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__11__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__11__ey)));
                        vlSelfRef.__Vfunc_fp32_add__11__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__11__ex;
                        vlSelfRef.__Vfunc_fp32_add__11__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__11__sx;
                        vlSelfRef.__Vfunc_fp32_add__11__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__11__mx);
                        vlSelfRef.__Vfunc_fp32_add__11__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__11__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__11__my), (IData)(vlSelfRef.__Vfunc_fp32_add__11__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__11__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__11__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__11__ex)));
                        vlSelfRef.__Vfunc_fp32_add__11__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__11__ey;
                        vlSelfRef.__Vfunc_fp32_add__11__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__11__sy;
                        vlSelfRef.__Vfunc_fp32_add__11__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__11__my);
                        vlSelfRef.__Vfunc_fp32_add__11__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__11__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__11__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__11__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__11__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__11__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__11__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__11__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__11__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__11__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__11__ay));
                        vlSelfRef.__Vfunc_fp32_add__11__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__11__s_big;
                        vlSelfRef.__Vfunc_fp32_add__11__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__11__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__11__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__11__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__11__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__11__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__11__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__11__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__11__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__11__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__11__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__11__ay));
                            vlSelfRef.__Vfunc_fp32_add__11__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__11__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__11__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__11__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__11__ax));
                            vlSelfRef.__Vfunc_fp32_add__11__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__11__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__11__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__11__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__11__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__11__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__11__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__11__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__11__sh)));
                            vlSelfRef.__Vfunc_fp32_add__11__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__11__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__11__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__11__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__11__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__11__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__11__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__11__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__9__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__9__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__9__sx = 
                    (vlSelfRef.__Vfunc_fp32_add__9__x 
                     >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__9__ex = 
                    (0xffU & (vlSelfRef.__Vfunc_fp32_add__9__x 
                              >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__9__mx = 
                    (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__9__x);
                vlSelfRef.__Vfunc_fp32_add__9__sy = 
                    (vlSelfRef.__Vfunc_fp32_add__9__y 
                     >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__9__ey = 
                    (0xffU & (vlSelfRef.__Vfunc_fp32_add__9__y 
                              >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__9__my = 
                    (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__9__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__9__x))) {
                    vlSelfRef.__Vfunc_fp32_add__9__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__9__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__9__y))) {
                    vlSelfRef.__Vfunc_fp32_add__9__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__9__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__9__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__9__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__9__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__9__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__9__ey)));
                        vlSelfRef.__Vfunc_fp32_add__9__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__9__ex;
                        vlSelfRef.__Vfunc_fp32_add__9__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__9__sx;
                        vlSelfRef.__Vfunc_fp32_add__9__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__9__mx);
                        vlSelfRef.__Vfunc_fp32_add__9__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__9__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__9__my), (IData)(vlSelfRef.__Vfunc_fp32_add__9__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__9__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__9__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__9__ex)));
                        vlSelfRef.__Vfunc_fp32_add__9__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__9__ey;
                        vlSelfRef.__Vfunc_fp32_add__9__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__9__sy;
                        vlSelfRef.__Vfunc_fp32_add__9__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__9__my);
                        vlSelfRef.__Vfunc_fp32_add__9__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__9__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__9__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__9__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__9__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__9__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__9__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__9__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__9__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__9__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__9__ay));
                        vlSelfRef.__Vfunc_fp32_add__9__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__9__s_big;
                        vlSelfRef.__Vfunc_fp32_add__9__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__9__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__9__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__9__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__9__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__9__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__9__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__9__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__9__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__9__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__9__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__9__ay));
                            vlSelfRef.__Vfunc_fp32_add__9__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__9__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__9__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__9__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__9__ax));
                            vlSelfRef.__Vfunc_fp32_add__9__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__9__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__9__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__9__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__9__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__9__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__9__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__9__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__9__sh)));
                            vlSelfRef.__Vfunc_fp32_add__9__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__9__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__9__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__9__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__9__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__9__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__9__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__9__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [0U][3U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [0U][3U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__0__KET____DOT__col__BRA__3__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__12__fa;
    __Vfunc_fp8_mul__12__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__12__fb;
    __Vfunc_fp8_mul__12__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__12__sp;
    __Vfunc_fp8_mul__12__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__12__ea;
    __Vfunc_fp8_mul__12__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__12__eb;
    __Vfunc_fp8_mul__12__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__12__ma;
    __Vfunc_fp8_mul__12__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__12__mb;
    __Vfunc_fp8_mul__12__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__14__fa;
    __Vfunc_bf16_mul__14__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__14__fb;
    __Vfunc_bf16_mul__14__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__14__s;
    __Vfunc_bf16_mul__14__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__14__ea;
    __Vfunc_bf16_mul__14__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__14__eb;
    __Vfunc_bf16_mul__14__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__14__ma;
    __Vfunc_bf16_mul__14__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__14__mb;
    __Vfunc_bf16_mul__14__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [0U]
                                                                    [3U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [0U]
                                                                [3U])))));
    __Vfunc_bf16_mul__14__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [0U][3U];
    __Vfunc_bf16_mul__14__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [0U][3U];
    __Vfunc_bf16_mul__14__s = (1U & (((IData)(__Vfunc_bf16_mul__14__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__14__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__14__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__14__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__14__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__14__fa)));
    __Vfunc_bf16_mul__14__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__14__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__14__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__14__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__14__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__14__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__14__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__14__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__14__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__14__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__14__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__14__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__14__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__14__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__14__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__14__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__14__mb)));
        vlSelfRef.__Vfunc_bf16_mul__14__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__14__mp))
              ? (((IData)(__Vfunc_bf16_mul__14__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__14__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__14__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__14__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__14__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__14__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__14__Vfuncout;
    __Vfunc_fp8_mul__12__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [0U][3U]);
    __Vfunc_fp8_mul__12__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [0U][3U]);
    __Vfunc_fp8_mul__12__sp = (1U & (((IData)(__Vfunc_fp8_mul__12__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__12__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__12__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__12__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__12__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__12__fa)));
    __Vfunc_fp8_mul__12__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__12__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__12__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__12__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__12__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__12__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__12__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__12__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__12__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__12__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__12__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__12__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__12__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__12__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__12__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__12__eb))));
        vlSelfRef.__Vfunc_fp8_mul__12__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__12__ma) 
                                                * (IData)(__Vfunc_fp8_mul__12__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__12__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__12__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__12__ep)));
            vlSelfRef.__Vfunc_fp8_mul__12__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__12__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__12__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__12__ep));
            vlSelfRef.__Vfunc_fp8_mul__12__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__12__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__12__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__12__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__12__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__12__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__12__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__15__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__15__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__15__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__15__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__15__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__15__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__15__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__15__x);
                vlSelfRef.__Vfunc_fp32_add__15__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__15__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__15__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__15__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__15__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__15__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__15__x))) {
                    vlSelfRef.__Vfunc_fp32_add__15__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__15__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__15__y))) {
                    vlSelfRef.__Vfunc_fp32_add__15__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__15__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__15__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__15__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__15__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__15__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__15__ey)));
                        vlSelfRef.__Vfunc_fp32_add__15__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__15__ex;
                        vlSelfRef.__Vfunc_fp32_add__15__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__15__sx;
                        vlSelfRef.__Vfunc_fp32_add__15__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__15__mx);
                        vlSelfRef.__Vfunc_fp32_add__15__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__15__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__15__my), (IData)(vlSelfRef.__Vfunc_fp32_add__15__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__15__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__15__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__15__ex)));
                        vlSelfRef.__Vfunc_fp32_add__15__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__15__ey;
                        vlSelfRef.__Vfunc_fp32_add__15__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__15__sy;
                        vlSelfRef.__Vfunc_fp32_add__15__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__15__my);
                        vlSelfRef.__Vfunc_fp32_add__15__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__15__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__15__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__15__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__15__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__15__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__15__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__15__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__15__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__15__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__15__ay));
                        vlSelfRef.__Vfunc_fp32_add__15__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__15__s_big;
                        vlSelfRef.__Vfunc_fp32_add__15__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__15__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__15__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__15__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__15__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__15__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__15__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__15__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__15__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__15__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__15__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__15__ay));
                            vlSelfRef.__Vfunc_fp32_add__15__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__15__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__15__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__15__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__15__ax));
                            vlSelfRef.__Vfunc_fp32_add__15__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__15__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__15__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__15__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__15__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__15__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__15__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__15__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__15__sh)));
                            vlSelfRef.__Vfunc_fp32_add__15__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__15__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__15__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__15__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__15__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__15__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__15__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__15__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__13__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__13__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__13__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__13__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__13__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__13__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__13__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__13__x);
                vlSelfRef.__Vfunc_fp32_add__13__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__13__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__13__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__13__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__13__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__13__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__13__x))) {
                    vlSelfRef.__Vfunc_fp32_add__13__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__13__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__13__y))) {
                    vlSelfRef.__Vfunc_fp32_add__13__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__13__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__13__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__13__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__13__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__13__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__13__ey)));
                        vlSelfRef.__Vfunc_fp32_add__13__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__13__ex;
                        vlSelfRef.__Vfunc_fp32_add__13__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__13__sx;
                        vlSelfRef.__Vfunc_fp32_add__13__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__13__mx);
                        vlSelfRef.__Vfunc_fp32_add__13__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__13__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__13__my), (IData)(vlSelfRef.__Vfunc_fp32_add__13__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__13__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__13__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__13__ex)));
                        vlSelfRef.__Vfunc_fp32_add__13__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__13__ey;
                        vlSelfRef.__Vfunc_fp32_add__13__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__13__sy;
                        vlSelfRef.__Vfunc_fp32_add__13__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__13__my);
                        vlSelfRef.__Vfunc_fp32_add__13__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__13__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__13__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__13__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__13__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__13__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__13__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__13__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__13__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__13__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__13__ay));
                        vlSelfRef.__Vfunc_fp32_add__13__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__13__s_big;
                        vlSelfRef.__Vfunc_fp32_add__13__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__13__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__13__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__13__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__13__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__13__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__13__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__13__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__13__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__13__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__13__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__13__ay));
                            vlSelfRef.__Vfunc_fp32_add__13__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__13__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__13__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__13__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__13__ax));
                            vlSelfRef.__Vfunc_fp32_add__13__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__13__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__13__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__13__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__13__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__13__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__13__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__13__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__13__sh)));
                            vlSelfRef.__Vfunc_fp32_add__13__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__13__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__13__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__13__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__13__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__13__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__13__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__13__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [1U][0U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [1U][0U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__0__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__16__fa;
    __Vfunc_fp8_mul__16__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__16__fb;
    __Vfunc_fp8_mul__16__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__16__sp;
    __Vfunc_fp8_mul__16__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__16__ea;
    __Vfunc_fp8_mul__16__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__16__eb;
    __Vfunc_fp8_mul__16__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__16__ma;
    __Vfunc_fp8_mul__16__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__16__mb;
    __Vfunc_fp8_mul__16__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__18__fa;
    __Vfunc_bf16_mul__18__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__18__fb;
    __Vfunc_bf16_mul__18__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__18__s;
    __Vfunc_bf16_mul__18__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__18__ea;
    __Vfunc_bf16_mul__18__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__18__eb;
    __Vfunc_bf16_mul__18__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__18__ma;
    __Vfunc_bf16_mul__18__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__18__mb;
    __Vfunc_bf16_mul__18__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [1U]
                                                                    [0U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [1U]
                                                                [0U])))));
    __Vfunc_bf16_mul__18__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [1U][0U];
    __Vfunc_bf16_mul__18__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [1U][0U];
    __Vfunc_bf16_mul__18__s = (1U & (((IData)(__Vfunc_bf16_mul__18__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__18__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__18__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__18__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__18__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__18__fa)));
    __Vfunc_bf16_mul__18__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__18__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__18__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__18__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__18__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__18__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__18__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__18__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__18__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__18__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__18__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__18__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__18__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__18__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__18__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__18__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__18__mb)));
        vlSelfRef.__Vfunc_bf16_mul__18__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__18__mp))
              ? (((IData)(__Vfunc_bf16_mul__18__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__18__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__18__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__18__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__18__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__18__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__18__Vfuncout;
    __Vfunc_fp8_mul__16__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [1U][0U]);
    __Vfunc_fp8_mul__16__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [1U][0U]);
    __Vfunc_fp8_mul__16__sp = (1U & (((IData)(__Vfunc_fp8_mul__16__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__16__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__16__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__16__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__16__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__16__fa)));
    __Vfunc_fp8_mul__16__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__16__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__16__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__16__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__16__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__16__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__16__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__16__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__16__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__16__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__16__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__16__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__16__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__16__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__16__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__16__eb))));
        vlSelfRef.__Vfunc_fp8_mul__16__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__16__ma) 
                                                * (IData)(__Vfunc_fp8_mul__16__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__16__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__16__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__16__ep)));
            vlSelfRef.__Vfunc_fp8_mul__16__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__16__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__16__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__16__ep));
            vlSelfRef.__Vfunc_fp8_mul__16__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__16__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__16__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__16__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__16__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__16__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__16__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__19__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__19__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__19__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__19__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__19__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__19__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__19__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__19__x);
                vlSelfRef.__Vfunc_fp32_add__19__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__19__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__19__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__19__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__19__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__19__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__19__x))) {
                    vlSelfRef.__Vfunc_fp32_add__19__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__19__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__19__y))) {
                    vlSelfRef.__Vfunc_fp32_add__19__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__19__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__19__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__19__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__19__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__19__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__19__ey)));
                        vlSelfRef.__Vfunc_fp32_add__19__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__19__ex;
                        vlSelfRef.__Vfunc_fp32_add__19__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__19__sx;
                        vlSelfRef.__Vfunc_fp32_add__19__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__19__mx);
                        vlSelfRef.__Vfunc_fp32_add__19__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__19__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__19__my), (IData)(vlSelfRef.__Vfunc_fp32_add__19__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__19__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__19__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__19__ex)));
                        vlSelfRef.__Vfunc_fp32_add__19__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__19__ey;
                        vlSelfRef.__Vfunc_fp32_add__19__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__19__sy;
                        vlSelfRef.__Vfunc_fp32_add__19__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__19__my);
                        vlSelfRef.__Vfunc_fp32_add__19__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__19__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__19__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__19__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__19__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__19__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__19__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__19__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__19__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__19__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__19__ay));
                        vlSelfRef.__Vfunc_fp32_add__19__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__19__s_big;
                        vlSelfRef.__Vfunc_fp32_add__19__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__19__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__19__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__19__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__19__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__19__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__19__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__19__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__19__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__19__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__19__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__19__ay));
                            vlSelfRef.__Vfunc_fp32_add__19__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__19__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__19__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__19__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__19__ax));
                            vlSelfRef.__Vfunc_fp32_add__19__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__19__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__19__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__19__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__19__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__19__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__19__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__19__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__19__sh)));
                            vlSelfRef.__Vfunc_fp32_add__19__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__19__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__19__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__19__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__19__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__19__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__19__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__19__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__17__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__17__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__17__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__17__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__17__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__17__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__17__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__17__x);
                vlSelfRef.__Vfunc_fp32_add__17__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__17__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__17__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__17__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__17__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__17__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__17__x))) {
                    vlSelfRef.__Vfunc_fp32_add__17__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__17__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__17__y))) {
                    vlSelfRef.__Vfunc_fp32_add__17__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__17__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__17__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__17__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__17__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__17__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__17__ey)));
                        vlSelfRef.__Vfunc_fp32_add__17__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__17__ex;
                        vlSelfRef.__Vfunc_fp32_add__17__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__17__sx;
                        vlSelfRef.__Vfunc_fp32_add__17__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__17__mx);
                        vlSelfRef.__Vfunc_fp32_add__17__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__17__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__17__my), (IData)(vlSelfRef.__Vfunc_fp32_add__17__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__17__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__17__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__17__ex)));
                        vlSelfRef.__Vfunc_fp32_add__17__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__17__ey;
                        vlSelfRef.__Vfunc_fp32_add__17__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__17__sy;
                        vlSelfRef.__Vfunc_fp32_add__17__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__17__my);
                        vlSelfRef.__Vfunc_fp32_add__17__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__17__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__17__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__17__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__17__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__17__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__17__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__17__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__17__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__17__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__17__ay));
                        vlSelfRef.__Vfunc_fp32_add__17__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__17__s_big;
                        vlSelfRef.__Vfunc_fp32_add__17__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__17__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__17__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__17__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__17__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__17__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__17__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__17__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__17__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__17__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__17__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__17__ay));
                            vlSelfRef.__Vfunc_fp32_add__17__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__17__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__17__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__17__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__17__ax));
                            vlSelfRef.__Vfunc_fp32_add__17__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__17__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__17__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__17__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__17__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__17__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__17__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__17__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__17__sh)));
                            vlSelfRef.__Vfunc_fp32_add__17__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__17__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__17__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__17__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__17__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__17__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__17__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__17__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [1U][1U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [1U][1U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__1__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__20__fa;
    __Vfunc_fp8_mul__20__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__20__fb;
    __Vfunc_fp8_mul__20__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__20__sp;
    __Vfunc_fp8_mul__20__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__20__ea;
    __Vfunc_fp8_mul__20__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__20__eb;
    __Vfunc_fp8_mul__20__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__20__ma;
    __Vfunc_fp8_mul__20__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__20__mb;
    __Vfunc_fp8_mul__20__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__22__fa;
    __Vfunc_bf16_mul__22__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__22__fb;
    __Vfunc_bf16_mul__22__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__22__s;
    __Vfunc_bf16_mul__22__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__22__ea;
    __Vfunc_bf16_mul__22__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__22__eb;
    __Vfunc_bf16_mul__22__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__22__ma;
    __Vfunc_bf16_mul__22__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__22__mb;
    __Vfunc_bf16_mul__22__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [1U]
                                                                    [1U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [1U]
                                                                [1U])))));
    __Vfunc_bf16_mul__22__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [1U][1U];
    __Vfunc_bf16_mul__22__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [1U][1U];
    __Vfunc_bf16_mul__22__s = (1U & (((IData)(__Vfunc_bf16_mul__22__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__22__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__22__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__22__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__22__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__22__fa)));
    __Vfunc_bf16_mul__22__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__22__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__22__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__22__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__22__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__22__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__22__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__22__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__22__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__22__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__22__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__22__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__22__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__22__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__22__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__22__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__22__mb)));
        vlSelfRef.__Vfunc_bf16_mul__22__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__22__mp))
              ? (((IData)(__Vfunc_bf16_mul__22__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__22__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__22__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__22__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__22__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__22__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__22__Vfuncout;
    __Vfunc_fp8_mul__20__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [1U][1U]);
    __Vfunc_fp8_mul__20__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [1U][1U]);
    __Vfunc_fp8_mul__20__sp = (1U & (((IData)(__Vfunc_fp8_mul__20__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__20__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__20__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__20__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__20__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__20__fa)));
    __Vfunc_fp8_mul__20__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__20__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__20__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__20__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__20__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__20__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__20__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__20__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__20__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__20__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__20__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__20__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__20__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__20__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__20__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__20__eb))));
        vlSelfRef.__Vfunc_fp8_mul__20__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__20__ma) 
                                                * (IData)(__Vfunc_fp8_mul__20__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__20__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__20__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__20__ep)));
            vlSelfRef.__Vfunc_fp8_mul__20__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__20__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__20__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__20__ep));
            vlSelfRef.__Vfunc_fp8_mul__20__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__20__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__20__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__20__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__20__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__20__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__20__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__23__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__23__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__23__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__23__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__23__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__23__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__23__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__23__x);
                vlSelfRef.__Vfunc_fp32_add__23__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__23__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__23__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__23__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__23__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__23__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__23__x))) {
                    vlSelfRef.__Vfunc_fp32_add__23__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__23__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__23__y))) {
                    vlSelfRef.__Vfunc_fp32_add__23__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__23__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__23__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__23__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__23__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__23__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__23__ey)));
                        vlSelfRef.__Vfunc_fp32_add__23__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__23__ex;
                        vlSelfRef.__Vfunc_fp32_add__23__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__23__sx;
                        vlSelfRef.__Vfunc_fp32_add__23__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__23__mx);
                        vlSelfRef.__Vfunc_fp32_add__23__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__23__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__23__my), (IData)(vlSelfRef.__Vfunc_fp32_add__23__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__23__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__23__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__23__ex)));
                        vlSelfRef.__Vfunc_fp32_add__23__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__23__ey;
                        vlSelfRef.__Vfunc_fp32_add__23__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__23__sy;
                        vlSelfRef.__Vfunc_fp32_add__23__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__23__my);
                        vlSelfRef.__Vfunc_fp32_add__23__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__23__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__23__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__23__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__23__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__23__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__23__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__23__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__23__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__23__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__23__ay));
                        vlSelfRef.__Vfunc_fp32_add__23__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__23__s_big;
                        vlSelfRef.__Vfunc_fp32_add__23__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__23__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__23__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__23__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__23__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__23__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__23__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__23__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__23__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__23__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__23__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__23__ay));
                            vlSelfRef.__Vfunc_fp32_add__23__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__23__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__23__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__23__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__23__ax));
                            vlSelfRef.__Vfunc_fp32_add__23__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__23__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__23__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__23__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__23__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__23__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__23__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__23__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__23__sh)));
                            vlSelfRef.__Vfunc_fp32_add__23__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__23__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__23__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__23__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__23__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__23__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__23__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__23__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__21__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__21__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__21__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__21__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__21__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__21__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__21__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__21__x);
                vlSelfRef.__Vfunc_fp32_add__21__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__21__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__21__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__21__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__21__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__21__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__21__x))) {
                    vlSelfRef.__Vfunc_fp32_add__21__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__21__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__21__y))) {
                    vlSelfRef.__Vfunc_fp32_add__21__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__21__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__21__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__21__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__21__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__21__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__21__ey)));
                        vlSelfRef.__Vfunc_fp32_add__21__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__21__ex;
                        vlSelfRef.__Vfunc_fp32_add__21__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__21__sx;
                        vlSelfRef.__Vfunc_fp32_add__21__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__21__mx);
                        vlSelfRef.__Vfunc_fp32_add__21__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__21__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__21__my), (IData)(vlSelfRef.__Vfunc_fp32_add__21__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__21__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__21__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__21__ex)));
                        vlSelfRef.__Vfunc_fp32_add__21__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__21__ey;
                        vlSelfRef.__Vfunc_fp32_add__21__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__21__sy;
                        vlSelfRef.__Vfunc_fp32_add__21__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__21__my);
                        vlSelfRef.__Vfunc_fp32_add__21__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__21__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__21__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__21__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__21__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__21__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__21__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__21__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__21__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__21__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__21__ay));
                        vlSelfRef.__Vfunc_fp32_add__21__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__21__s_big;
                        vlSelfRef.__Vfunc_fp32_add__21__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__21__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__21__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__21__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__21__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__21__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__21__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__21__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__21__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__21__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__21__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__21__ay));
                            vlSelfRef.__Vfunc_fp32_add__21__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__21__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__21__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__21__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__21__ax));
                            vlSelfRef.__Vfunc_fp32_add__21__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__21__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__21__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__21__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__21__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__21__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__21__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__21__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__21__sh)));
                            vlSelfRef.__Vfunc_fp32_add__21__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__21__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__21__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__21__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__21__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__21__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__21__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__21__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [1U][2U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [1U][2U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__2__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__24__fa;
    __Vfunc_fp8_mul__24__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__24__fb;
    __Vfunc_fp8_mul__24__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__24__sp;
    __Vfunc_fp8_mul__24__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__24__ea;
    __Vfunc_fp8_mul__24__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__24__eb;
    __Vfunc_fp8_mul__24__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__24__ma;
    __Vfunc_fp8_mul__24__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__24__mb;
    __Vfunc_fp8_mul__24__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__26__fa;
    __Vfunc_bf16_mul__26__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__26__fb;
    __Vfunc_bf16_mul__26__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__26__s;
    __Vfunc_bf16_mul__26__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__26__ea;
    __Vfunc_bf16_mul__26__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__26__eb;
    __Vfunc_bf16_mul__26__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__26__ma;
    __Vfunc_bf16_mul__26__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__26__mb;
    __Vfunc_bf16_mul__26__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [1U]
                                                                    [2U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [1U]
                                                                [2U])))));
    __Vfunc_bf16_mul__26__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [1U][2U];
    __Vfunc_bf16_mul__26__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [1U][2U];
    __Vfunc_bf16_mul__26__s = (1U & (((IData)(__Vfunc_bf16_mul__26__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__26__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__26__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__26__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__26__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__26__fa)));
    __Vfunc_bf16_mul__26__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__26__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__26__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__26__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__26__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__26__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__26__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__26__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__26__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__26__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__26__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__26__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__26__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__26__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__26__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__26__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__26__mb)));
        vlSelfRef.__Vfunc_bf16_mul__26__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__26__mp))
              ? (((IData)(__Vfunc_bf16_mul__26__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__26__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__26__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__26__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__26__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__26__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__26__Vfuncout;
    __Vfunc_fp8_mul__24__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [1U][2U]);
    __Vfunc_fp8_mul__24__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [1U][2U]);
    __Vfunc_fp8_mul__24__sp = (1U & (((IData)(__Vfunc_fp8_mul__24__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__24__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__24__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__24__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__24__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__24__fa)));
    __Vfunc_fp8_mul__24__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__24__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__24__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__24__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__24__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__24__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__24__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__24__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__24__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__24__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__24__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__24__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__24__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__24__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__24__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__24__eb))));
        vlSelfRef.__Vfunc_fp8_mul__24__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__24__ma) 
                                                * (IData)(__Vfunc_fp8_mul__24__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__24__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__24__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__24__ep)));
            vlSelfRef.__Vfunc_fp8_mul__24__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__24__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__24__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__24__ep));
            vlSelfRef.__Vfunc_fp8_mul__24__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__24__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__24__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__24__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__24__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__24__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__24__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__27__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__27__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__27__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__27__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__27__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__27__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__27__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__27__x);
                vlSelfRef.__Vfunc_fp32_add__27__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__27__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__27__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__27__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__27__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__27__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__27__x))) {
                    vlSelfRef.__Vfunc_fp32_add__27__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__27__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__27__y))) {
                    vlSelfRef.__Vfunc_fp32_add__27__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__27__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__27__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__27__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__27__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__27__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__27__ey)));
                        vlSelfRef.__Vfunc_fp32_add__27__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__27__ex;
                        vlSelfRef.__Vfunc_fp32_add__27__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__27__sx;
                        vlSelfRef.__Vfunc_fp32_add__27__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__27__mx);
                        vlSelfRef.__Vfunc_fp32_add__27__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__27__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__27__my), (IData)(vlSelfRef.__Vfunc_fp32_add__27__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__27__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__27__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__27__ex)));
                        vlSelfRef.__Vfunc_fp32_add__27__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__27__ey;
                        vlSelfRef.__Vfunc_fp32_add__27__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__27__sy;
                        vlSelfRef.__Vfunc_fp32_add__27__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__27__my);
                        vlSelfRef.__Vfunc_fp32_add__27__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__27__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__27__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__27__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__27__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__27__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__27__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__27__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__27__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__27__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__27__ay));
                        vlSelfRef.__Vfunc_fp32_add__27__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__27__s_big;
                        vlSelfRef.__Vfunc_fp32_add__27__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__27__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__27__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__27__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__27__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__27__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__27__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__27__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__27__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__27__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__27__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__27__ay));
                            vlSelfRef.__Vfunc_fp32_add__27__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__27__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__27__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__27__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__27__ax));
                            vlSelfRef.__Vfunc_fp32_add__27__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__27__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__27__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__27__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__27__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__27__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__27__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__27__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__27__sh)));
                            vlSelfRef.__Vfunc_fp32_add__27__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__27__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__27__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__27__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__27__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__27__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__27__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__27__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__25__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__25__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__25__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__25__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__25__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__25__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__25__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__25__x);
                vlSelfRef.__Vfunc_fp32_add__25__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__25__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__25__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__25__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__25__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__25__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__25__x))) {
                    vlSelfRef.__Vfunc_fp32_add__25__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__25__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__25__y))) {
                    vlSelfRef.__Vfunc_fp32_add__25__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__25__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__25__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__25__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__25__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__25__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__25__ey)));
                        vlSelfRef.__Vfunc_fp32_add__25__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__25__ex;
                        vlSelfRef.__Vfunc_fp32_add__25__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__25__sx;
                        vlSelfRef.__Vfunc_fp32_add__25__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__25__mx);
                        vlSelfRef.__Vfunc_fp32_add__25__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__25__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__25__my), (IData)(vlSelfRef.__Vfunc_fp32_add__25__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__25__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__25__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__25__ex)));
                        vlSelfRef.__Vfunc_fp32_add__25__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__25__ey;
                        vlSelfRef.__Vfunc_fp32_add__25__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__25__sy;
                        vlSelfRef.__Vfunc_fp32_add__25__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__25__my);
                        vlSelfRef.__Vfunc_fp32_add__25__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__25__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__25__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__25__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__25__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__25__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__25__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__25__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__25__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__25__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__25__ay));
                        vlSelfRef.__Vfunc_fp32_add__25__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__25__s_big;
                        vlSelfRef.__Vfunc_fp32_add__25__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__25__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__25__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__25__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__25__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__25__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__25__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__25__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__25__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__25__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__25__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__25__ay));
                            vlSelfRef.__Vfunc_fp32_add__25__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__25__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__25__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__25__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__25__ax));
                            vlSelfRef.__Vfunc_fp32_add__25__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__25__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__25__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__25__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__25__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__25__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__25__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__25__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__25__sh)));
                            vlSelfRef.__Vfunc_fp32_add__25__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__25__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__25__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__25__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__25__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__25__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__25__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__25__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [1U][3U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [1U][3U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__1__KET____DOT__col__BRA__3__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__28__fa;
    __Vfunc_fp8_mul__28__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__28__fb;
    __Vfunc_fp8_mul__28__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__28__sp;
    __Vfunc_fp8_mul__28__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__28__ea;
    __Vfunc_fp8_mul__28__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__28__eb;
    __Vfunc_fp8_mul__28__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__28__ma;
    __Vfunc_fp8_mul__28__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__28__mb;
    __Vfunc_fp8_mul__28__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__30__fa;
    __Vfunc_bf16_mul__30__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__30__fb;
    __Vfunc_bf16_mul__30__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__30__s;
    __Vfunc_bf16_mul__30__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__30__ea;
    __Vfunc_bf16_mul__30__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__30__eb;
    __Vfunc_bf16_mul__30__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__30__ma;
    __Vfunc_bf16_mul__30__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__30__mb;
    __Vfunc_bf16_mul__30__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [1U]
                                                                    [3U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [1U]
                                                                [3U])))));
    __Vfunc_bf16_mul__30__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [1U][3U];
    __Vfunc_bf16_mul__30__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [1U][3U];
    __Vfunc_bf16_mul__30__s = (1U & (((IData)(__Vfunc_bf16_mul__30__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__30__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__30__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__30__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__30__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__30__fa)));
    __Vfunc_bf16_mul__30__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__30__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__30__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__30__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__30__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__30__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__30__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__30__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__30__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__30__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__30__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__30__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__30__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__30__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__30__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__30__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__30__mb)));
        vlSelfRef.__Vfunc_bf16_mul__30__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__30__mp))
              ? (((IData)(__Vfunc_bf16_mul__30__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__30__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__30__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__30__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__30__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__30__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__30__Vfuncout;
    __Vfunc_fp8_mul__28__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [1U][3U]);
    __Vfunc_fp8_mul__28__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [1U][3U]);
    __Vfunc_fp8_mul__28__sp = (1U & (((IData)(__Vfunc_fp8_mul__28__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__28__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__28__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__28__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__28__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__28__fa)));
    __Vfunc_fp8_mul__28__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__28__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__28__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__28__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__28__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__28__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__28__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__28__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__28__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__28__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__28__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__28__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__28__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__28__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__28__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__28__eb))));
        vlSelfRef.__Vfunc_fp8_mul__28__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__28__ma) 
                                                * (IData)(__Vfunc_fp8_mul__28__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__28__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__28__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__28__ep)));
            vlSelfRef.__Vfunc_fp8_mul__28__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__28__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__28__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__28__ep));
            vlSelfRef.__Vfunc_fp8_mul__28__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__28__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__28__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__28__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__28__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__28__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__28__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__31__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__31__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__31__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__31__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__31__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__31__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__31__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__31__x);
                vlSelfRef.__Vfunc_fp32_add__31__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__31__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__31__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__31__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__31__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__31__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__31__x))) {
                    vlSelfRef.__Vfunc_fp32_add__31__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__31__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__31__y))) {
                    vlSelfRef.__Vfunc_fp32_add__31__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__31__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__31__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__31__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__31__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__31__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__31__ey)));
                        vlSelfRef.__Vfunc_fp32_add__31__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__31__ex;
                        vlSelfRef.__Vfunc_fp32_add__31__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__31__sx;
                        vlSelfRef.__Vfunc_fp32_add__31__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__31__mx);
                        vlSelfRef.__Vfunc_fp32_add__31__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__31__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__31__my), (IData)(vlSelfRef.__Vfunc_fp32_add__31__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__31__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__31__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__31__ex)));
                        vlSelfRef.__Vfunc_fp32_add__31__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__31__ey;
                        vlSelfRef.__Vfunc_fp32_add__31__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__31__sy;
                        vlSelfRef.__Vfunc_fp32_add__31__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__31__my);
                        vlSelfRef.__Vfunc_fp32_add__31__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__31__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__31__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__31__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__31__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__31__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__31__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__31__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__31__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__31__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__31__ay));
                        vlSelfRef.__Vfunc_fp32_add__31__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__31__s_big;
                        vlSelfRef.__Vfunc_fp32_add__31__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__31__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__31__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__31__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__31__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__31__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__31__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__31__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__31__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__31__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__31__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__31__ay));
                            vlSelfRef.__Vfunc_fp32_add__31__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__31__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__31__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__31__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__31__ax));
                            vlSelfRef.__Vfunc_fp32_add__31__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__31__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__31__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__31__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__31__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__31__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__31__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__31__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__31__sh)));
                            vlSelfRef.__Vfunc_fp32_add__31__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__31__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__31__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__31__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__31__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__31__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__31__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__31__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__29__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__29__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__29__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__29__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__29__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__29__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__29__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__29__x);
                vlSelfRef.__Vfunc_fp32_add__29__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__29__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__29__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__29__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__29__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__29__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__29__x))) {
                    vlSelfRef.__Vfunc_fp32_add__29__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__29__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__29__y))) {
                    vlSelfRef.__Vfunc_fp32_add__29__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__29__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__29__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__29__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__29__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__29__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__29__ey)));
                        vlSelfRef.__Vfunc_fp32_add__29__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__29__ex;
                        vlSelfRef.__Vfunc_fp32_add__29__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__29__sx;
                        vlSelfRef.__Vfunc_fp32_add__29__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__29__mx);
                        vlSelfRef.__Vfunc_fp32_add__29__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__29__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__29__my), (IData)(vlSelfRef.__Vfunc_fp32_add__29__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__29__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__29__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__29__ex)));
                        vlSelfRef.__Vfunc_fp32_add__29__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__29__ey;
                        vlSelfRef.__Vfunc_fp32_add__29__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__29__sy;
                        vlSelfRef.__Vfunc_fp32_add__29__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__29__my);
                        vlSelfRef.__Vfunc_fp32_add__29__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__29__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__29__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__29__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__29__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__29__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__29__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__29__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__29__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__29__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__29__ay));
                        vlSelfRef.__Vfunc_fp32_add__29__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__29__s_big;
                        vlSelfRef.__Vfunc_fp32_add__29__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__29__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__29__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__29__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__29__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__29__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__29__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__29__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__29__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__29__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__29__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__29__ay));
                            vlSelfRef.__Vfunc_fp32_add__29__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__29__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__29__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__29__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__29__ax));
                            vlSelfRef.__Vfunc_fp32_add__29__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__29__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__29__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__29__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__29__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__29__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__29__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__29__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__29__sh)));
                            vlSelfRef.__Vfunc_fp32_add__29__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__29__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__29__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__29__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__29__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__29__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__29__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__29__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [2U][0U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [2U][0U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__0__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__32__fa;
    __Vfunc_fp8_mul__32__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__32__fb;
    __Vfunc_fp8_mul__32__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__32__sp;
    __Vfunc_fp8_mul__32__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__32__ea;
    __Vfunc_fp8_mul__32__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__32__eb;
    __Vfunc_fp8_mul__32__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__32__ma;
    __Vfunc_fp8_mul__32__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__32__mb;
    __Vfunc_fp8_mul__32__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__34__fa;
    __Vfunc_bf16_mul__34__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__34__fb;
    __Vfunc_bf16_mul__34__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__34__s;
    __Vfunc_bf16_mul__34__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__34__ea;
    __Vfunc_bf16_mul__34__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__34__eb;
    __Vfunc_bf16_mul__34__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__34__ma;
    __Vfunc_bf16_mul__34__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__34__mb;
    __Vfunc_bf16_mul__34__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [2U]
                                                                    [0U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [2U]
                                                                [0U])))));
    __Vfunc_bf16_mul__34__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [2U][0U];
    __Vfunc_bf16_mul__34__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [2U][0U];
    __Vfunc_bf16_mul__34__s = (1U & (((IData)(__Vfunc_bf16_mul__34__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__34__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__34__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__34__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__34__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__34__fa)));
    __Vfunc_bf16_mul__34__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__34__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__34__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__34__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__34__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__34__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__34__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__34__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__34__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__34__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__34__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__34__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__34__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__34__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__34__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__34__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__34__mb)));
        vlSelfRef.__Vfunc_bf16_mul__34__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__34__mp))
              ? (((IData)(__Vfunc_bf16_mul__34__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__34__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__34__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__34__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__34__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__34__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__34__Vfuncout;
    __Vfunc_fp8_mul__32__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [2U][0U]);
    __Vfunc_fp8_mul__32__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [2U][0U]);
    __Vfunc_fp8_mul__32__sp = (1U & (((IData)(__Vfunc_fp8_mul__32__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__32__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__32__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__32__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__32__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__32__fa)));
    __Vfunc_fp8_mul__32__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__32__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__32__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__32__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__32__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__32__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__32__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__32__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__32__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__32__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__32__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__32__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__32__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__32__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__32__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__32__eb))));
        vlSelfRef.__Vfunc_fp8_mul__32__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__32__ma) 
                                                * (IData)(__Vfunc_fp8_mul__32__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__32__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__32__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__32__ep)));
            vlSelfRef.__Vfunc_fp8_mul__32__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__32__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__32__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__32__ep));
            vlSelfRef.__Vfunc_fp8_mul__32__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__32__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__32__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__32__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__32__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__32__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__32__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__35__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__35__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__35__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__35__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__35__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__35__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__35__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__35__x);
                vlSelfRef.__Vfunc_fp32_add__35__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__35__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__35__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__35__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__35__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__35__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__35__x))) {
                    vlSelfRef.__Vfunc_fp32_add__35__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__35__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__35__y))) {
                    vlSelfRef.__Vfunc_fp32_add__35__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__35__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__35__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__35__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__35__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__35__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__35__ey)));
                        vlSelfRef.__Vfunc_fp32_add__35__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__35__ex;
                        vlSelfRef.__Vfunc_fp32_add__35__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__35__sx;
                        vlSelfRef.__Vfunc_fp32_add__35__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__35__mx);
                        vlSelfRef.__Vfunc_fp32_add__35__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__35__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__35__my), (IData)(vlSelfRef.__Vfunc_fp32_add__35__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__35__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__35__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__35__ex)));
                        vlSelfRef.__Vfunc_fp32_add__35__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__35__ey;
                        vlSelfRef.__Vfunc_fp32_add__35__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__35__sy;
                        vlSelfRef.__Vfunc_fp32_add__35__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__35__my);
                        vlSelfRef.__Vfunc_fp32_add__35__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__35__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__35__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__35__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__35__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__35__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__35__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__35__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__35__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__35__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__35__ay));
                        vlSelfRef.__Vfunc_fp32_add__35__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__35__s_big;
                        vlSelfRef.__Vfunc_fp32_add__35__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__35__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__35__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__35__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__35__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__35__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__35__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__35__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__35__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__35__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__35__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__35__ay));
                            vlSelfRef.__Vfunc_fp32_add__35__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__35__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__35__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__35__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__35__ax));
                            vlSelfRef.__Vfunc_fp32_add__35__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__35__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__35__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__35__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__35__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__35__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__35__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__35__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__35__sh)));
                            vlSelfRef.__Vfunc_fp32_add__35__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__35__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__35__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__35__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__35__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__35__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__35__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__35__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__33__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__33__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__33__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__33__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__33__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__33__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__33__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__33__x);
                vlSelfRef.__Vfunc_fp32_add__33__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__33__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__33__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__33__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__33__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__33__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__33__x))) {
                    vlSelfRef.__Vfunc_fp32_add__33__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__33__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__33__y))) {
                    vlSelfRef.__Vfunc_fp32_add__33__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__33__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__33__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__33__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__33__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__33__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__33__ey)));
                        vlSelfRef.__Vfunc_fp32_add__33__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__33__ex;
                        vlSelfRef.__Vfunc_fp32_add__33__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__33__sx;
                        vlSelfRef.__Vfunc_fp32_add__33__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__33__mx);
                        vlSelfRef.__Vfunc_fp32_add__33__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__33__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__33__my), (IData)(vlSelfRef.__Vfunc_fp32_add__33__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__33__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__33__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__33__ex)));
                        vlSelfRef.__Vfunc_fp32_add__33__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__33__ey;
                        vlSelfRef.__Vfunc_fp32_add__33__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__33__sy;
                        vlSelfRef.__Vfunc_fp32_add__33__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__33__my);
                        vlSelfRef.__Vfunc_fp32_add__33__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__33__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__33__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__33__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__33__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__33__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__33__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__33__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__33__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__33__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__33__ay));
                        vlSelfRef.__Vfunc_fp32_add__33__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__33__s_big;
                        vlSelfRef.__Vfunc_fp32_add__33__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__33__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__33__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__33__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__33__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__33__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__33__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__33__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__33__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__33__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__33__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__33__ay));
                            vlSelfRef.__Vfunc_fp32_add__33__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__33__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__33__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__33__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__33__ax));
                            vlSelfRef.__Vfunc_fp32_add__33__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__33__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__33__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__33__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__33__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__33__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__33__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__33__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__33__sh)));
                            vlSelfRef.__Vfunc_fp32_add__33__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__33__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__33__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__33__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__33__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__33__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__33__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__33__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [2U][1U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [2U][1U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__1__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__36__fa;
    __Vfunc_fp8_mul__36__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__36__fb;
    __Vfunc_fp8_mul__36__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__36__sp;
    __Vfunc_fp8_mul__36__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__36__ea;
    __Vfunc_fp8_mul__36__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__36__eb;
    __Vfunc_fp8_mul__36__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__36__ma;
    __Vfunc_fp8_mul__36__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__36__mb;
    __Vfunc_fp8_mul__36__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__38__fa;
    __Vfunc_bf16_mul__38__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__38__fb;
    __Vfunc_bf16_mul__38__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__38__s;
    __Vfunc_bf16_mul__38__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__38__ea;
    __Vfunc_bf16_mul__38__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__38__eb;
    __Vfunc_bf16_mul__38__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__38__ma;
    __Vfunc_bf16_mul__38__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__38__mb;
    __Vfunc_bf16_mul__38__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [2U]
                                                                    [1U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [2U]
                                                                [1U])))));
    __Vfunc_bf16_mul__38__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [2U][1U];
    __Vfunc_bf16_mul__38__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [2U][1U];
    __Vfunc_bf16_mul__38__s = (1U & (((IData)(__Vfunc_bf16_mul__38__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__38__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__38__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__38__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__38__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__38__fa)));
    __Vfunc_bf16_mul__38__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__38__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__38__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__38__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__38__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__38__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__38__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__38__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__38__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__38__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__38__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__38__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__38__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__38__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__38__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__38__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__38__mb)));
        vlSelfRef.__Vfunc_bf16_mul__38__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__38__mp))
              ? (((IData)(__Vfunc_bf16_mul__38__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__38__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__38__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__38__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__38__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__38__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__38__Vfuncout;
    __Vfunc_fp8_mul__36__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [2U][1U]);
    __Vfunc_fp8_mul__36__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [2U][1U]);
    __Vfunc_fp8_mul__36__sp = (1U & (((IData)(__Vfunc_fp8_mul__36__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__36__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__36__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__36__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__36__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__36__fa)));
    __Vfunc_fp8_mul__36__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__36__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__36__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__36__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__36__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__36__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__36__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__36__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__36__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__36__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__36__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__36__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__36__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__36__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__36__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__36__eb))));
        vlSelfRef.__Vfunc_fp8_mul__36__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__36__ma) 
                                                * (IData)(__Vfunc_fp8_mul__36__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__36__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__36__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__36__ep)));
            vlSelfRef.__Vfunc_fp8_mul__36__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__36__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__36__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__36__ep));
            vlSelfRef.__Vfunc_fp8_mul__36__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__36__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__36__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__36__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__36__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__36__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__36__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__39__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__39__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__39__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__39__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__39__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__39__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__39__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__39__x);
                vlSelfRef.__Vfunc_fp32_add__39__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__39__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__39__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__39__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__39__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__39__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__39__x))) {
                    vlSelfRef.__Vfunc_fp32_add__39__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__39__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__39__y))) {
                    vlSelfRef.__Vfunc_fp32_add__39__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__39__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__39__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__39__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__39__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__39__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__39__ey)));
                        vlSelfRef.__Vfunc_fp32_add__39__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__39__ex;
                        vlSelfRef.__Vfunc_fp32_add__39__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__39__sx;
                        vlSelfRef.__Vfunc_fp32_add__39__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__39__mx);
                        vlSelfRef.__Vfunc_fp32_add__39__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__39__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__39__my), (IData)(vlSelfRef.__Vfunc_fp32_add__39__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__39__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__39__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__39__ex)));
                        vlSelfRef.__Vfunc_fp32_add__39__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__39__ey;
                        vlSelfRef.__Vfunc_fp32_add__39__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__39__sy;
                        vlSelfRef.__Vfunc_fp32_add__39__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__39__my);
                        vlSelfRef.__Vfunc_fp32_add__39__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__39__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__39__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__39__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__39__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__39__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__39__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__39__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__39__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__39__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__39__ay));
                        vlSelfRef.__Vfunc_fp32_add__39__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__39__s_big;
                        vlSelfRef.__Vfunc_fp32_add__39__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__39__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__39__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__39__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__39__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__39__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__39__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__39__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__39__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__39__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__39__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__39__ay));
                            vlSelfRef.__Vfunc_fp32_add__39__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__39__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__39__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__39__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__39__ax));
                            vlSelfRef.__Vfunc_fp32_add__39__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__39__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__39__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__39__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__39__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__39__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__39__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__39__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__39__sh)));
                            vlSelfRef.__Vfunc_fp32_add__39__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__39__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__39__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__39__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__39__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__39__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__39__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__39__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__37__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__37__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__37__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__37__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__37__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__37__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__37__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__37__x);
                vlSelfRef.__Vfunc_fp32_add__37__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__37__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__37__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__37__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__37__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__37__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__37__x))) {
                    vlSelfRef.__Vfunc_fp32_add__37__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__37__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__37__y))) {
                    vlSelfRef.__Vfunc_fp32_add__37__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__37__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__37__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__37__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__37__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__37__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__37__ey)));
                        vlSelfRef.__Vfunc_fp32_add__37__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__37__ex;
                        vlSelfRef.__Vfunc_fp32_add__37__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__37__sx;
                        vlSelfRef.__Vfunc_fp32_add__37__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__37__mx);
                        vlSelfRef.__Vfunc_fp32_add__37__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__37__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__37__my), (IData)(vlSelfRef.__Vfunc_fp32_add__37__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__37__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__37__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__37__ex)));
                        vlSelfRef.__Vfunc_fp32_add__37__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__37__ey;
                        vlSelfRef.__Vfunc_fp32_add__37__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__37__sy;
                        vlSelfRef.__Vfunc_fp32_add__37__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__37__my);
                        vlSelfRef.__Vfunc_fp32_add__37__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__37__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__37__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__37__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__37__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__37__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__37__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__37__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__37__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__37__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__37__ay));
                        vlSelfRef.__Vfunc_fp32_add__37__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__37__s_big;
                        vlSelfRef.__Vfunc_fp32_add__37__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__37__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__37__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__37__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__37__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__37__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__37__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__37__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__37__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__37__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__37__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__37__ay));
                            vlSelfRef.__Vfunc_fp32_add__37__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__37__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__37__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__37__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__37__ax));
                            vlSelfRef.__Vfunc_fp32_add__37__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__37__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__37__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__37__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__37__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__37__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__37__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__37__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__37__sh)));
                            vlSelfRef.__Vfunc_fp32_add__37__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__37__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__37__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__37__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__37__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__37__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__37__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__37__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [2U][2U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [2U][2U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__2__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__40__fa;
    __Vfunc_fp8_mul__40__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__40__fb;
    __Vfunc_fp8_mul__40__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__40__sp;
    __Vfunc_fp8_mul__40__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__40__ea;
    __Vfunc_fp8_mul__40__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__40__eb;
    __Vfunc_fp8_mul__40__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__40__ma;
    __Vfunc_fp8_mul__40__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__40__mb;
    __Vfunc_fp8_mul__40__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__42__fa;
    __Vfunc_bf16_mul__42__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__42__fb;
    __Vfunc_bf16_mul__42__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__42__s;
    __Vfunc_bf16_mul__42__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__42__ea;
    __Vfunc_bf16_mul__42__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__42__eb;
    __Vfunc_bf16_mul__42__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__42__ma;
    __Vfunc_bf16_mul__42__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__42__mb;
    __Vfunc_bf16_mul__42__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [2U]
                                                                    [2U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [2U]
                                                                [2U])))));
    __Vfunc_bf16_mul__42__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [2U][2U];
    __Vfunc_bf16_mul__42__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [2U][2U];
    __Vfunc_bf16_mul__42__s = (1U & (((IData)(__Vfunc_bf16_mul__42__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__42__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__42__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__42__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__42__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__42__fa)));
    __Vfunc_bf16_mul__42__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__42__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__42__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__42__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__42__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__42__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__42__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__42__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__42__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__42__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__42__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__42__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__42__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__42__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__42__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__42__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__42__mb)));
        vlSelfRef.__Vfunc_bf16_mul__42__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__42__mp))
              ? (((IData)(__Vfunc_bf16_mul__42__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__42__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__42__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__42__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__42__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__42__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__42__Vfuncout;
    __Vfunc_fp8_mul__40__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [2U][2U]);
    __Vfunc_fp8_mul__40__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [2U][2U]);
    __Vfunc_fp8_mul__40__sp = (1U & (((IData)(__Vfunc_fp8_mul__40__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__40__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__40__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__40__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__40__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__40__fa)));
    __Vfunc_fp8_mul__40__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__40__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__40__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__40__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__40__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__40__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__40__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__40__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__40__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__40__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__40__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__40__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__40__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__40__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__40__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__40__eb))));
        vlSelfRef.__Vfunc_fp8_mul__40__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__40__ma) 
                                                * (IData)(__Vfunc_fp8_mul__40__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__40__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__40__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__40__ep)));
            vlSelfRef.__Vfunc_fp8_mul__40__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__40__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__40__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__40__ep));
            vlSelfRef.__Vfunc_fp8_mul__40__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__40__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__40__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__40__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__40__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__40__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__40__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__43__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__43__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__43__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__43__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__43__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__43__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__43__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__43__x);
                vlSelfRef.__Vfunc_fp32_add__43__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__43__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__43__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__43__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__43__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__43__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__43__x))) {
                    vlSelfRef.__Vfunc_fp32_add__43__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__43__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__43__y))) {
                    vlSelfRef.__Vfunc_fp32_add__43__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__43__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__43__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__43__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__43__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__43__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__43__ey)));
                        vlSelfRef.__Vfunc_fp32_add__43__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__43__ex;
                        vlSelfRef.__Vfunc_fp32_add__43__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__43__sx;
                        vlSelfRef.__Vfunc_fp32_add__43__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__43__mx);
                        vlSelfRef.__Vfunc_fp32_add__43__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__43__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__43__my), (IData)(vlSelfRef.__Vfunc_fp32_add__43__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__43__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__43__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__43__ex)));
                        vlSelfRef.__Vfunc_fp32_add__43__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__43__ey;
                        vlSelfRef.__Vfunc_fp32_add__43__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__43__sy;
                        vlSelfRef.__Vfunc_fp32_add__43__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__43__my);
                        vlSelfRef.__Vfunc_fp32_add__43__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__43__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__43__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__43__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__43__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__43__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__43__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__43__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__43__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__43__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__43__ay));
                        vlSelfRef.__Vfunc_fp32_add__43__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__43__s_big;
                        vlSelfRef.__Vfunc_fp32_add__43__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__43__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__43__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__43__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__43__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__43__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__43__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__43__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__43__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__43__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__43__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__43__ay));
                            vlSelfRef.__Vfunc_fp32_add__43__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__43__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__43__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__43__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__43__ax));
                            vlSelfRef.__Vfunc_fp32_add__43__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__43__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__43__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__43__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__43__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__43__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__43__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__43__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__43__sh)));
                            vlSelfRef.__Vfunc_fp32_add__43__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__43__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__43__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__43__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__43__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__43__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__43__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__43__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__41__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__41__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__41__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__41__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__41__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__41__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__41__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__41__x);
                vlSelfRef.__Vfunc_fp32_add__41__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__41__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__41__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__41__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__41__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__41__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__41__x))) {
                    vlSelfRef.__Vfunc_fp32_add__41__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__41__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__41__y))) {
                    vlSelfRef.__Vfunc_fp32_add__41__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__41__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__41__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__41__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__41__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__41__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__41__ey)));
                        vlSelfRef.__Vfunc_fp32_add__41__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__41__ex;
                        vlSelfRef.__Vfunc_fp32_add__41__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__41__sx;
                        vlSelfRef.__Vfunc_fp32_add__41__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__41__mx);
                        vlSelfRef.__Vfunc_fp32_add__41__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__41__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__41__my), (IData)(vlSelfRef.__Vfunc_fp32_add__41__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__41__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__41__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__41__ex)));
                        vlSelfRef.__Vfunc_fp32_add__41__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__41__ey;
                        vlSelfRef.__Vfunc_fp32_add__41__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__41__sy;
                        vlSelfRef.__Vfunc_fp32_add__41__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__41__my);
                        vlSelfRef.__Vfunc_fp32_add__41__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__41__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__41__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__41__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__41__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__41__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__41__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__41__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__41__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__41__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__41__ay));
                        vlSelfRef.__Vfunc_fp32_add__41__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__41__s_big;
                        vlSelfRef.__Vfunc_fp32_add__41__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__41__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__41__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__41__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__41__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__41__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__41__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__41__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__41__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__41__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__41__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__41__ay));
                            vlSelfRef.__Vfunc_fp32_add__41__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__41__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__41__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__41__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__41__ax));
                            vlSelfRef.__Vfunc_fp32_add__41__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__41__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__41__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__41__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__41__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__41__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__41__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__41__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__41__sh)));
                            vlSelfRef.__Vfunc_fp32_add__41__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__41__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__41__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__41__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__41__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__41__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__41__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__41__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [2U][3U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [2U][3U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__2__KET____DOT__col__BRA__3__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__44__fa;
    __Vfunc_fp8_mul__44__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__44__fb;
    __Vfunc_fp8_mul__44__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__44__sp;
    __Vfunc_fp8_mul__44__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__44__ea;
    __Vfunc_fp8_mul__44__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__44__eb;
    __Vfunc_fp8_mul__44__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__44__ma;
    __Vfunc_fp8_mul__44__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__44__mb;
    __Vfunc_fp8_mul__44__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__46__fa;
    __Vfunc_bf16_mul__46__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__46__fb;
    __Vfunc_bf16_mul__46__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__46__s;
    __Vfunc_bf16_mul__46__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__46__ea;
    __Vfunc_bf16_mul__46__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__46__eb;
    __Vfunc_bf16_mul__46__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__46__ma;
    __Vfunc_bf16_mul__46__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__46__mb;
    __Vfunc_bf16_mul__46__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [2U]
                                                                    [3U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [2U]
                                                                [3U])))));
    __Vfunc_bf16_mul__46__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [2U][3U];
    __Vfunc_bf16_mul__46__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [2U][3U];
    __Vfunc_bf16_mul__46__s = (1U & (((IData)(__Vfunc_bf16_mul__46__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__46__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__46__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__46__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__46__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__46__fa)));
    __Vfunc_bf16_mul__46__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__46__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__46__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__46__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__46__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__46__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__46__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__46__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__46__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__46__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__46__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__46__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__46__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__46__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__46__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__46__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__46__mb)));
        vlSelfRef.__Vfunc_bf16_mul__46__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__46__mp))
              ? (((IData)(__Vfunc_bf16_mul__46__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__46__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__46__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__46__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__46__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__46__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__46__Vfuncout;
    __Vfunc_fp8_mul__44__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [2U][3U]);
    __Vfunc_fp8_mul__44__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [2U][3U]);
    __Vfunc_fp8_mul__44__sp = (1U & (((IData)(__Vfunc_fp8_mul__44__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__44__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__44__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__44__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__44__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__44__fa)));
    __Vfunc_fp8_mul__44__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__44__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__44__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__44__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__44__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__44__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__44__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__44__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__44__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__44__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__44__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__44__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__44__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__44__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__44__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__44__eb))));
        vlSelfRef.__Vfunc_fp8_mul__44__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__44__ma) 
                                                * (IData)(__Vfunc_fp8_mul__44__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__44__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__44__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__44__ep)));
            vlSelfRef.__Vfunc_fp8_mul__44__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__44__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__44__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__44__ep));
            vlSelfRef.__Vfunc_fp8_mul__44__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__44__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__44__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__44__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__44__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__44__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__44__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__47__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__47__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__47__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__47__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__47__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__47__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__47__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__47__x);
                vlSelfRef.__Vfunc_fp32_add__47__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__47__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__47__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__47__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__47__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__47__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__47__x))) {
                    vlSelfRef.__Vfunc_fp32_add__47__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__47__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__47__y))) {
                    vlSelfRef.__Vfunc_fp32_add__47__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__47__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__47__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__47__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__47__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__47__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__47__ey)));
                        vlSelfRef.__Vfunc_fp32_add__47__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__47__ex;
                        vlSelfRef.__Vfunc_fp32_add__47__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__47__sx;
                        vlSelfRef.__Vfunc_fp32_add__47__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__47__mx);
                        vlSelfRef.__Vfunc_fp32_add__47__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__47__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__47__my), (IData)(vlSelfRef.__Vfunc_fp32_add__47__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__47__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__47__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__47__ex)));
                        vlSelfRef.__Vfunc_fp32_add__47__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__47__ey;
                        vlSelfRef.__Vfunc_fp32_add__47__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__47__sy;
                        vlSelfRef.__Vfunc_fp32_add__47__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__47__my);
                        vlSelfRef.__Vfunc_fp32_add__47__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__47__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__47__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__47__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__47__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__47__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__47__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__47__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__47__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__47__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__47__ay));
                        vlSelfRef.__Vfunc_fp32_add__47__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__47__s_big;
                        vlSelfRef.__Vfunc_fp32_add__47__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__47__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__47__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__47__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__47__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__47__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__47__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__47__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__47__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__47__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__47__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__47__ay));
                            vlSelfRef.__Vfunc_fp32_add__47__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__47__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__47__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__47__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__47__ax));
                            vlSelfRef.__Vfunc_fp32_add__47__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__47__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__47__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__47__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__47__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__47__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__47__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__47__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__47__sh)));
                            vlSelfRef.__Vfunc_fp32_add__47__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__47__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__47__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__47__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__47__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__47__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__47__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__47__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__45__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__45__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__45__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__45__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__45__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__45__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__45__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__45__x);
                vlSelfRef.__Vfunc_fp32_add__45__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__45__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__45__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__45__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__45__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__45__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__45__x))) {
                    vlSelfRef.__Vfunc_fp32_add__45__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__45__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__45__y))) {
                    vlSelfRef.__Vfunc_fp32_add__45__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__45__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__45__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__45__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__45__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__45__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__45__ey)));
                        vlSelfRef.__Vfunc_fp32_add__45__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__45__ex;
                        vlSelfRef.__Vfunc_fp32_add__45__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__45__sx;
                        vlSelfRef.__Vfunc_fp32_add__45__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__45__mx);
                        vlSelfRef.__Vfunc_fp32_add__45__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__45__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__45__my), (IData)(vlSelfRef.__Vfunc_fp32_add__45__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__45__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__45__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__45__ex)));
                        vlSelfRef.__Vfunc_fp32_add__45__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__45__ey;
                        vlSelfRef.__Vfunc_fp32_add__45__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__45__sy;
                        vlSelfRef.__Vfunc_fp32_add__45__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__45__my);
                        vlSelfRef.__Vfunc_fp32_add__45__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__45__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__45__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__45__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__45__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__45__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__45__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__45__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__45__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__45__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__45__ay));
                        vlSelfRef.__Vfunc_fp32_add__45__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__45__s_big;
                        vlSelfRef.__Vfunc_fp32_add__45__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__45__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__45__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__45__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__45__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__45__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__45__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__45__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__45__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__45__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__45__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__45__ay));
                            vlSelfRef.__Vfunc_fp32_add__45__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__45__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__45__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__45__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__45__ax));
                            vlSelfRef.__Vfunc_fp32_add__45__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__45__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__45__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__45__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__45__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__45__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__45__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__45__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__45__sh)));
                            vlSelfRef.__Vfunc_fp32_add__45__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__45__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__45__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__45__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__45__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__45__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__45__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__45__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [3U][0U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [3U][0U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__0__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__48__fa;
    __Vfunc_fp8_mul__48__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__48__fb;
    __Vfunc_fp8_mul__48__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__48__sp;
    __Vfunc_fp8_mul__48__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__48__ea;
    __Vfunc_fp8_mul__48__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__48__eb;
    __Vfunc_fp8_mul__48__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__48__ma;
    __Vfunc_fp8_mul__48__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__48__mb;
    __Vfunc_fp8_mul__48__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__50__fa;
    __Vfunc_bf16_mul__50__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__50__fb;
    __Vfunc_bf16_mul__50__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__50__s;
    __Vfunc_bf16_mul__50__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__50__ea;
    __Vfunc_bf16_mul__50__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__50__eb;
    __Vfunc_bf16_mul__50__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__50__ma;
    __Vfunc_bf16_mul__50__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__50__mb;
    __Vfunc_bf16_mul__50__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [3U]
                                                                    [0U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [3U]
                                                                [0U])))));
    __Vfunc_bf16_mul__50__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [3U][0U];
    __Vfunc_bf16_mul__50__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [3U][0U];
    __Vfunc_bf16_mul__50__s = (1U & (((IData)(__Vfunc_bf16_mul__50__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__50__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__50__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__50__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__50__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__50__fa)));
    __Vfunc_bf16_mul__50__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__50__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__50__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__50__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__50__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__50__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__50__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__50__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__50__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__50__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__50__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__50__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__50__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__50__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__50__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__50__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__50__mb)));
        vlSelfRef.__Vfunc_bf16_mul__50__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__50__mp))
              ? (((IData)(__Vfunc_bf16_mul__50__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__50__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__50__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__50__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__50__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__50__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__50__Vfuncout;
    __Vfunc_fp8_mul__48__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [3U][0U]);
    __Vfunc_fp8_mul__48__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [3U][0U]);
    __Vfunc_fp8_mul__48__sp = (1U & (((IData)(__Vfunc_fp8_mul__48__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__48__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__48__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__48__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__48__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__48__fa)));
    __Vfunc_fp8_mul__48__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__48__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__48__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__48__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__48__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__48__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__48__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__48__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__48__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__48__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__48__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__48__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__48__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__48__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__48__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__48__eb))));
        vlSelfRef.__Vfunc_fp8_mul__48__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__48__ma) 
                                                * (IData)(__Vfunc_fp8_mul__48__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__48__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__48__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__48__ep)));
            vlSelfRef.__Vfunc_fp8_mul__48__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__48__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__48__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__48__ep));
            vlSelfRef.__Vfunc_fp8_mul__48__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__48__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__48__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__48__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__48__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__48__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__48__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__51__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__51__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__51__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__51__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__51__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__51__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__51__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__51__x);
                vlSelfRef.__Vfunc_fp32_add__51__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__51__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__51__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__51__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__51__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__51__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__51__x))) {
                    vlSelfRef.__Vfunc_fp32_add__51__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__51__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__51__y))) {
                    vlSelfRef.__Vfunc_fp32_add__51__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__51__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__51__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__51__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__51__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__51__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__51__ey)));
                        vlSelfRef.__Vfunc_fp32_add__51__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__51__ex;
                        vlSelfRef.__Vfunc_fp32_add__51__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__51__sx;
                        vlSelfRef.__Vfunc_fp32_add__51__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__51__mx);
                        vlSelfRef.__Vfunc_fp32_add__51__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__51__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__51__my), (IData)(vlSelfRef.__Vfunc_fp32_add__51__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__51__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__51__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__51__ex)));
                        vlSelfRef.__Vfunc_fp32_add__51__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__51__ey;
                        vlSelfRef.__Vfunc_fp32_add__51__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__51__sy;
                        vlSelfRef.__Vfunc_fp32_add__51__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__51__my);
                        vlSelfRef.__Vfunc_fp32_add__51__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__51__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__51__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__51__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__51__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__51__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__51__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__51__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__51__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__51__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__51__ay));
                        vlSelfRef.__Vfunc_fp32_add__51__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__51__s_big;
                        vlSelfRef.__Vfunc_fp32_add__51__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__51__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__51__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__51__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__51__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__51__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__51__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__51__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__51__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__51__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__51__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__51__ay));
                            vlSelfRef.__Vfunc_fp32_add__51__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__51__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__51__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__51__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__51__ax));
                            vlSelfRef.__Vfunc_fp32_add__51__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__51__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__51__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__51__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__51__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__51__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__51__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__51__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__51__sh)));
                            vlSelfRef.__Vfunc_fp32_add__51__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__51__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__51__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__51__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__51__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__51__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__51__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__51__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__49__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__49__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__49__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__49__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__49__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__49__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__49__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__49__x);
                vlSelfRef.__Vfunc_fp32_add__49__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__49__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__49__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__49__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__49__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__49__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__49__x))) {
                    vlSelfRef.__Vfunc_fp32_add__49__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__49__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__49__y))) {
                    vlSelfRef.__Vfunc_fp32_add__49__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__49__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__49__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__49__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__49__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__49__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__49__ey)));
                        vlSelfRef.__Vfunc_fp32_add__49__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__49__ex;
                        vlSelfRef.__Vfunc_fp32_add__49__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__49__sx;
                        vlSelfRef.__Vfunc_fp32_add__49__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__49__mx);
                        vlSelfRef.__Vfunc_fp32_add__49__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__49__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__49__my), (IData)(vlSelfRef.__Vfunc_fp32_add__49__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__49__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__49__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__49__ex)));
                        vlSelfRef.__Vfunc_fp32_add__49__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__49__ey;
                        vlSelfRef.__Vfunc_fp32_add__49__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__49__sy;
                        vlSelfRef.__Vfunc_fp32_add__49__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__49__my);
                        vlSelfRef.__Vfunc_fp32_add__49__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__49__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__49__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__49__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__49__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__49__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__49__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__49__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__49__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__49__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__49__ay));
                        vlSelfRef.__Vfunc_fp32_add__49__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__49__s_big;
                        vlSelfRef.__Vfunc_fp32_add__49__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__49__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__49__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__49__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__49__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__49__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__49__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__49__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__49__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__49__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__49__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__49__ay));
                            vlSelfRef.__Vfunc_fp32_add__49__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__49__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__49__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__49__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__49__ax));
                            vlSelfRef.__Vfunc_fp32_add__49__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__49__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__49__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__49__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__49__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__49__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__49__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__49__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__49__sh)));
                            vlSelfRef.__Vfunc_fp32_add__49__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__49__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__49__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__49__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__49__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__49__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__49__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__49__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [3U][1U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [3U][1U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__1__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__52__fa;
    __Vfunc_fp8_mul__52__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__52__fb;
    __Vfunc_fp8_mul__52__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__52__sp;
    __Vfunc_fp8_mul__52__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__52__ea;
    __Vfunc_fp8_mul__52__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__52__eb;
    __Vfunc_fp8_mul__52__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__52__ma;
    __Vfunc_fp8_mul__52__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__52__mb;
    __Vfunc_fp8_mul__52__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__54__fa;
    __Vfunc_bf16_mul__54__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__54__fb;
    __Vfunc_bf16_mul__54__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__54__s;
    __Vfunc_bf16_mul__54__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__54__ea;
    __Vfunc_bf16_mul__54__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__54__eb;
    __Vfunc_bf16_mul__54__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__54__ma;
    __Vfunc_bf16_mul__54__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__54__mb;
    __Vfunc_bf16_mul__54__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [3U]
                                                                    [1U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [3U]
                                                                [1U])))));
    __Vfunc_bf16_mul__54__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [3U][1U];
    __Vfunc_bf16_mul__54__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [3U][1U];
    __Vfunc_bf16_mul__54__s = (1U & (((IData)(__Vfunc_bf16_mul__54__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__54__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__54__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__54__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__54__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__54__fa)));
    __Vfunc_bf16_mul__54__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__54__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__54__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__54__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__54__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__54__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__54__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__54__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__54__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__54__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__54__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__54__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__54__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__54__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__54__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__54__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__54__mb)));
        vlSelfRef.__Vfunc_bf16_mul__54__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__54__mp))
              ? (((IData)(__Vfunc_bf16_mul__54__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__54__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__54__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__54__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__54__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__54__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__54__Vfuncout;
    __Vfunc_fp8_mul__52__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [3U][1U]);
    __Vfunc_fp8_mul__52__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [3U][1U]);
    __Vfunc_fp8_mul__52__sp = (1U & (((IData)(__Vfunc_fp8_mul__52__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__52__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__52__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__52__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__52__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__52__fa)));
    __Vfunc_fp8_mul__52__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__52__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__52__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__52__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__52__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__52__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__52__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__52__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__52__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__52__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__52__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__52__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__52__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__52__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__52__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__52__eb))));
        vlSelfRef.__Vfunc_fp8_mul__52__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__52__ma) 
                                                * (IData)(__Vfunc_fp8_mul__52__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__52__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__52__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__52__ep)));
            vlSelfRef.__Vfunc_fp8_mul__52__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__52__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__52__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__52__ep));
            vlSelfRef.__Vfunc_fp8_mul__52__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__52__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__52__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__52__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__52__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__52__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__52__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__55__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__55__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__55__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__55__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__55__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__55__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__55__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__55__x);
                vlSelfRef.__Vfunc_fp32_add__55__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__55__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__55__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__55__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__55__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__55__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__55__x))) {
                    vlSelfRef.__Vfunc_fp32_add__55__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__55__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__55__y))) {
                    vlSelfRef.__Vfunc_fp32_add__55__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__55__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__55__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__55__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__55__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__55__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__55__ey)));
                        vlSelfRef.__Vfunc_fp32_add__55__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__55__ex;
                        vlSelfRef.__Vfunc_fp32_add__55__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__55__sx;
                        vlSelfRef.__Vfunc_fp32_add__55__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__55__mx);
                        vlSelfRef.__Vfunc_fp32_add__55__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__55__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__55__my), (IData)(vlSelfRef.__Vfunc_fp32_add__55__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__55__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__55__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__55__ex)));
                        vlSelfRef.__Vfunc_fp32_add__55__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__55__ey;
                        vlSelfRef.__Vfunc_fp32_add__55__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__55__sy;
                        vlSelfRef.__Vfunc_fp32_add__55__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__55__my);
                        vlSelfRef.__Vfunc_fp32_add__55__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__55__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__55__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__55__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__55__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__55__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__55__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__55__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__55__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__55__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__55__ay));
                        vlSelfRef.__Vfunc_fp32_add__55__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__55__s_big;
                        vlSelfRef.__Vfunc_fp32_add__55__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__55__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__55__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__55__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__55__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__55__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__55__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__55__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__55__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__55__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__55__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__55__ay));
                            vlSelfRef.__Vfunc_fp32_add__55__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__55__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__55__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__55__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__55__ax));
                            vlSelfRef.__Vfunc_fp32_add__55__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__55__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__55__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__55__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__55__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__55__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__55__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__55__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__55__sh)));
                            vlSelfRef.__Vfunc_fp32_add__55__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__55__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__55__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__55__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__55__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__55__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__55__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__55__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__53__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__53__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__53__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__53__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__53__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__53__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__53__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__53__x);
                vlSelfRef.__Vfunc_fp32_add__53__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__53__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__53__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__53__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__53__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__53__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__53__x))) {
                    vlSelfRef.__Vfunc_fp32_add__53__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__53__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__53__y))) {
                    vlSelfRef.__Vfunc_fp32_add__53__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__53__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__53__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__53__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__53__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__53__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__53__ey)));
                        vlSelfRef.__Vfunc_fp32_add__53__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__53__ex;
                        vlSelfRef.__Vfunc_fp32_add__53__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__53__sx;
                        vlSelfRef.__Vfunc_fp32_add__53__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__53__mx);
                        vlSelfRef.__Vfunc_fp32_add__53__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__53__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__53__my), (IData)(vlSelfRef.__Vfunc_fp32_add__53__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__53__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__53__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__53__ex)));
                        vlSelfRef.__Vfunc_fp32_add__53__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__53__ey;
                        vlSelfRef.__Vfunc_fp32_add__53__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__53__sy;
                        vlSelfRef.__Vfunc_fp32_add__53__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__53__my);
                        vlSelfRef.__Vfunc_fp32_add__53__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__53__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__53__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__53__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__53__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__53__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__53__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__53__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__53__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__53__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__53__ay));
                        vlSelfRef.__Vfunc_fp32_add__53__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__53__s_big;
                        vlSelfRef.__Vfunc_fp32_add__53__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__53__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__53__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__53__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__53__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__53__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__53__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__53__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__53__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__53__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__53__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__53__ay));
                            vlSelfRef.__Vfunc_fp32_add__53__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__53__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__53__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__53__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__53__ax));
                            vlSelfRef.__Vfunc_fp32_add__53__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__53__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__53__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__53__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__53__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__53__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__53__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__53__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__53__sh)));
                            vlSelfRef.__Vfunc_fp32_add__53__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__53__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__53__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__53__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__53__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__53__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__53__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__53__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [3U][2U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [3U][2U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__2__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__56__fa;
    __Vfunc_fp8_mul__56__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__56__fb;
    __Vfunc_fp8_mul__56__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__56__sp;
    __Vfunc_fp8_mul__56__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__56__ea;
    __Vfunc_fp8_mul__56__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__56__eb;
    __Vfunc_fp8_mul__56__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__56__ma;
    __Vfunc_fp8_mul__56__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__56__mb;
    __Vfunc_fp8_mul__56__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__58__fa;
    __Vfunc_bf16_mul__58__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__58__fb;
    __Vfunc_bf16_mul__58__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__58__s;
    __Vfunc_bf16_mul__58__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__58__ea;
    __Vfunc_bf16_mul__58__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__58__eb;
    __Vfunc_bf16_mul__58__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__58__ma;
    __Vfunc_bf16_mul__58__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__58__mb;
    __Vfunc_bf16_mul__58__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [3U]
                                                                    [2U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [3U]
                                                                [2U])))));
    __Vfunc_bf16_mul__58__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [3U][2U];
    __Vfunc_bf16_mul__58__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [3U][2U];
    __Vfunc_bf16_mul__58__s = (1U & (((IData)(__Vfunc_bf16_mul__58__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__58__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__58__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__58__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__58__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__58__fa)));
    __Vfunc_bf16_mul__58__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__58__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__58__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__58__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__58__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__58__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__58__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__58__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__58__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__58__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__58__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__58__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__58__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__58__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__58__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__58__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__58__mb)));
        vlSelfRef.__Vfunc_bf16_mul__58__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__58__mp))
              ? (((IData)(__Vfunc_bf16_mul__58__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__58__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__58__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__58__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__58__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__58__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__58__Vfuncout;
    __Vfunc_fp8_mul__56__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [3U][2U]);
    __Vfunc_fp8_mul__56__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [3U][2U]);
    __Vfunc_fp8_mul__56__sp = (1U & (((IData)(__Vfunc_fp8_mul__56__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__56__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__56__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__56__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__56__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__56__fa)));
    __Vfunc_fp8_mul__56__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__56__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__56__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__56__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__56__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__56__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__56__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__56__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__56__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__56__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__56__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__56__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__56__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__56__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__56__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__56__eb))));
        vlSelfRef.__Vfunc_fp8_mul__56__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__56__ma) 
                                                * (IData)(__Vfunc_fp8_mul__56__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__56__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__56__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__56__ep)));
            vlSelfRef.__Vfunc_fp8_mul__56__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__56__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__56__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__56__ep));
            vlSelfRef.__Vfunc_fp8_mul__56__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__56__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__56__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__56__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__56__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__56__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__56__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__59__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__59__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__59__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__59__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__59__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__59__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__59__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__59__x);
                vlSelfRef.__Vfunc_fp32_add__59__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__59__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__59__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__59__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__59__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__59__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__59__x))) {
                    vlSelfRef.__Vfunc_fp32_add__59__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__59__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__59__y))) {
                    vlSelfRef.__Vfunc_fp32_add__59__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__59__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__59__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__59__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__59__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__59__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__59__ey)));
                        vlSelfRef.__Vfunc_fp32_add__59__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__59__ex;
                        vlSelfRef.__Vfunc_fp32_add__59__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__59__sx;
                        vlSelfRef.__Vfunc_fp32_add__59__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__59__mx);
                        vlSelfRef.__Vfunc_fp32_add__59__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__59__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__59__my), (IData)(vlSelfRef.__Vfunc_fp32_add__59__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__59__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__59__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__59__ex)));
                        vlSelfRef.__Vfunc_fp32_add__59__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__59__ey;
                        vlSelfRef.__Vfunc_fp32_add__59__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__59__sy;
                        vlSelfRef.__Vfunc_fp32_add__59__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__59__my);
                        vlSelfRef.__Vfunc_fp32_add__59__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__59__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__59__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__59__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__59__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__59__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__59__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__59__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__59__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__59__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__59__ay));
                        vlSelfRef.__Vfunc_fp32_add__59__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__59__s_big;
                        vlSelfRef.__Vfunc_fp32_add__59__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__59__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__59__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__59__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__59__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__59__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__59__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__59__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__59__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__59__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__59__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__59__ay));
                            vlSelfRef.__Vfunc_fp32_add__59__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__59__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__59__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__59__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__59__ax));
                            vlSelfRef.__Vfunc_fp32_add__59__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__59__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__59__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__59__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__59__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__59__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__59__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__59__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__59__sh)));
                            vlSelfRef.__Vfunc_fp32_add__59__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__59__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__59__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__59__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__59__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__59__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__59__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__59__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__57__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__57__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__57__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__57__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__57__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__57__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__57__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__57__x);
                vlSelfRef.__Vfunc_fp32_add__57__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__57__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__57__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__57__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__57__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__57__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__57__x))) {
                    vlSelfRef.__Vfunc_fp32_add__57__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__57__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__57__y))) {
                    vlSelfRef.__Vfunc_fp32_add__57__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__57__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__57__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__57__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__57__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__57__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__57__ey)));
                        vlSelfRef.__Vfunc_fp32_add__57__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__57__ex;
                        vlSelfRef.__Vfunc_fp32_add__57__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__57__sx;
                        vlSelfRef.__Vfunc_fp32_add__57__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__57__mx);
                        vlSelfRef.__Vfunc_fp32_add__57__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__57__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__57__my), (IData)(vlSelfRef.__Vfunc_fp32_add__57__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__57__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__57__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__57__ex)));
                        vlSelfRef.__Vfunc_fp32_add__57__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__57__ey;
                        vlSelfRef.__Vfunc_fp32_add__57__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__57__sy;
                        vlSelfRef.__Vfunc_fp32_add__57__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__57__my);
                        vlSelfRef.__Vfunc_fp32_add__57__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__57__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__57__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__57__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__57__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__57__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__57__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__57__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__57__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__57__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__57__ay));
                        vlSelfRef.__Vfunc_fp32_add__57__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__57__s_big;
                        vlSelfRef.__Vfunc_fp32_add__57__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__57__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__57__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__57__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__57__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__57__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__57__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__57__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__57__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__57__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__57__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__57__ay));
                            vlSelfRef.__Vfunc_fp32_add__57__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__57__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__57__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__57__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__57__ax));
                            vlSelfRef.__Vfunc_fp32_add__57__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__57__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__57__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__57__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__57__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__57__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__57__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__57__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__57__sh)));
                            vlSelfRef.__Vfunc_fp32_add__57__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__57__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__57__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__57__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__57__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__57__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__57__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__57__Vfuncout));
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__mac_inst__0(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__mac_inst__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSymsp->TOP.top_tb__DOT__reset) {
        vlSelfRef.a_out = 0U;
        vlSelfRef.b_out = 0U;
        vlSelfRef.out = 0U;
    } else {
        vlSelfRef.a_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
            [3U][3U];
        vlSelfRef.b_out = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
            [3U][3U];
        vlSelfRef.out = ((1U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                          ? vlSelfRef.__PVT__fp8_next
                          : ((2U == (IData)(vlSymsp->TOP.top_tb__DOT__precision))
                              ? vlSelfRef.__PVT__bf16_next
                              : vlSelfRef.__PVT__int8_next));
    }
}

VL_INLINE_OPT void Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__mac_inst__1(Vtop_tb_mac* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtop_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+                Vtop_tb_mac___nba_sequent__TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__row__BRA__3__KET____DOT__col__BRA__3__KET____DOT__mac_inst__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __PVT__int8_prod;
    __PVT__int8_prod = 0;
    IData/*31:0*/ __PVT__fp8_prod;
    __PVT__fp8_prod = 0;
    IData/*31:0*/ __PVT__bf16_prod;
    __PVT__bf16_prod = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__60__fa;
    __Vfunc_fp8_mul__60__fa = 0;
    CData/*7:0*/ __Vfunc_fp8_mul__60__fb;
    __Vfunc_fp8_mul__60__fb = 0;
    CData/*0:0*/ __Vfunc_fp8_mul__60__sp;
    __Vfunc_fp8_mul__60__sp = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__60__ea;
    __Vfunc_fp8_mul__60__ea = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__60__eb;
    __Vfunc_fp8_mul__60__eb = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__60__ma;
    __Vfunc_fp8_mul__60__ma = 0;
    CData/*3:0*/ __Vfunc_fp8_mul__60__mb;
    __Vfunc_fp8_mul__60__mb = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__62__fa;
    __Vfunc_bf16_mul__62__fa = 0;
    SData/*15:0*/ __Vfunc_bf16_mul__62__fb;
    __Vfunc_bf16_mul__62__fb = 0;
    CData/*0:0*/ __Vfunc_bf16_mul__62__s;
    __Vfunc_bf16_mul__62__s = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__62__ea;
    __Vfunc_bf16_mul__62__ea = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__62__eb;
    __Vfunc_bf16_mul__62__eb = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__62__ma;
    __Vfunc_bf16_mul__62__ma = 0;
    CData/*7:0*/ __Vfunc_bf16_mul__62__mb;
    __Vfunc_bf16_mul__62__mb = 0;
    // Body
    __PVT__int8_prod = (0xffffU & VL_MULS_III(16, (0xffffU 
                                                   & VL_EXTENDS_II(16,8, 
                                                                   (0xffU 
                                                                    & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                                                                    [3U]
                                                                    [3U]))), 
                                              (0xffffU 
                                               & VL_EXTENDS_II(16,8, 
                                                               (0xffU 
                                                                & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                                                                [3U]
                                                                [3U])))));
    __Vfunc_bf16_mul__62__fb = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
        [3U][3U];
    __Vfunc_bf16_mul__62__fa = vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
        [3U][3U];
    __Vfunc_bf16_mul__62__s = (1U & (((IData)(__Vfunc_bf16_mul__62__fa) 
                                      ^ (IData)(__Vfunc_bf16_mul__62__fb)) 
                                     >> 0xfU));
    __Vfunc_bf16_mul__62__ea = (0xffU & ((IData)(__Vfunc_bf16_mul__62__fa) 
                                         >> 7U));
    __Vfunc_bf16_mul__62__ma = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__62__fa)));
    __Vfunc_bf16_mul__62__eb = (0xffU & ((IData)(__Vfunc_bf16_mul__62__fb) 
                                         >> 7U));
    __Vfunc_bf16_mul__62__mb = (0x80U | (0x7fU & (IData)(__Vfunc_bf16_mul__62__fb)));
    if (((0U == (IData)(__Vfunc_bf16_mul__62__ea)) 
         | (0U == (IData)(__Vfunc_bf16_mul__62__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__62__Vfuncout = 0U;
    } else if (((0xffU == (IData)(__Vfunc_bf16_mul__62__ea)) 
                | (0xffU == (IData)(__Vfunc_bf16_mul__62__eb)))) {
        vlSelfRef.__Vfunc_bf16_mul__62__Vfuncout = 
            (0x7fc00000U | ((IData)(__Vfunc_bf16_mul__62__s) 
                            << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_bf16_mul__62__ep = (0xffU 
                                              & (((IData)(__Vfunc_bf16_mul__62__ea) 
                                                  + (IData)(__Vfunc_bf16_mul__62__eb)) 
                                                 - (IData)(0x7fU)));
        vlSelfRef.__Vfunc_bf16_mul__62__mp = (0xffffU 
                                              & ((IData)(__Vfunc_bf16_mul__62__ma) 
                                                 * (IData)(__Vfunc_bf16_mul__62__mb)));
        vlSelfRef.__Vfunc_bf16_mul__62__Vfuncout = 
            ((0x8000U & (IData)(vlSelfRef.__Vfunc_bf16_mul__62__mp))
              ? (((IData)(__Vfunc_bf16_mul__62__s) 
                  << 0x1fU) | ((0x7f800000U & (((IData)(1U) 
                                                + (IData)(vlSelfRef.__Vfunc_bf16_mul__62__ep)) 
                                               << 0x17U)) 
                               | (0x7f0000U & ((IData)(vlSelfRef.__Vfunc_bf16_mul__62__mp) 
                                               << 8U))))
              : (((IData)(__Vfunc_bf16_mul__62__s) 
                  << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_bf16_mul__62__ep) 
                                << 0x17U) | (0x7f0000U 
                                             & ((IData)(vlSelfRef.__Vfunc_bf16_mul__62__mp) 
                                                << 9U)))));
    }
    __PVT__bf16_prod = vlSelfRef.__Vfunc_bf16_mul__62__Vfuncout;
    __Vfunc_fp8_mul__60__fb = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__b_wire
                               [3U][3U]);
    __Vfunc_fp8_mul__60__fa = (0xffU & vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__DOT__tile__BRA__0__KET____DOT__tile_inst__DOT__a_wire
                               [3U][3U]);
    __Vfunc_fp8_mul__60__sp = (1U & (((IData)(__Vfunc_fp8_mul__60__fa) 
                                      ^ (IData)(__Vfunc_fp8_mul__60__fb)) 
                                     >> 7U));
    __Vfunc_fp8_mul__60__ea = (0xfU & ((IData)(__Vfunc_fp8_mul__60__fa) 
                                       >> 3U));
    __Vfunc_fp8_mul__60__ma = (8U | (7U & (IData)(__Vfunc_fp8_mul__60__fa)));
    __Vfunc_fp8_mul__60__eb = (0xfU & ((IData)(__Vfunc_fp8_mul__60__fb) 
                                       >> 3U));
    __Vfunc_fp8_mul__60__mb = (8U | (7U & (IData)(__Vfunc_fp8_mul__60__fb)));
    if (((0U == (IData)(__Vfunc_fp8_mul__60__ea)) | 
         (0U == (IData)(__Vfunc_fp8_mul__60__eb)))) {
        vlSelfRef.__Vfunc_fp8_mul__60__Vfuncout = 0U;
    } else if ((((0xfU == (IData)(__Vfunc_fp8_mul__60__ea)) 
                 & (7U == (7U & (IData)(__Vfunc_fp8_mul__60__fa)))) 
                | ((0xfU == (IData)(__Vfunc_fp8_mul__60__eb)) 
                   & (7U == (7U & (IData)(__Vfunc_fp8_mul__60__fb)))))) {
        vlSelfRef.__Vfunc_fp8_mul__60__Vfuncout = (0x7fc00000U 
                                                   | ((IData)(__Vfunc_fp8_mul__60__sp) 
                                                      << 0x1fU));
    } else {
        vlSelfRef.__Vfunc_fp8_mul__60__ep = (0x1ffU 
                                             & ((IData)(0x71U) 
                                                + ((IData)(__Vfunc_fp8_mul__60__ea) 
                                                   + (IData)(__Vfunc_fp8_mul__60__eb))));
        vlSelfRef.__Vfunc_fp8_mul__60__mp = (0xffU 
                                             & ((IData)(__Vfunc_fp8_mul__60__ma) 
                                                * (IData)(__Vfunc_fp8_mul__60__mb)));
        if ((0x80U & (IData)(vlSelfRef.__Vfunc_fp8_mul__60__mp))) {
            vlSelfRef.__Vfunc_fp8_mul__60__e32 = (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.__Vfunc_fp8_mul__60__ep)));
            vlSelfRef.__Vfunc_fp8_mul__60__m32 = (0x7f0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__60__mp) 
                                                     << 0x10U));
        } else {
            vlSelfRef.__Vfunc_fp8_mul__60__e32 = (0xffU 
                                                  & (IData)(vlSelfRef.__Vfunc_fp8_mul__60__ep));
            vlSelfRef.__Vfunc_fp8_mul__60__m32 = (0x7e0000U 
                                                  & ((IData)(vlSelfRef.__Vfunc_fp8_mul__60__mp) 
                                                     << 0x11U));
        }
        vlSelfRef.__Vfunc_fp8_mul__60__Vfuncout = (
                                                   ((IData)(__Vfunc_fp8_mul__60__sp) 
                                                    << 0x1fU) 
                                                   | (((IData)(vlSelfRef.__Vfunc_fp8_mul__60__e32) 
                                                       << 0x17U) 
                                                      | vlSelfRef.__Vfunc_fp8_mul__60__m32));
    }
    __PVT__fp8_prod = vlSelfRef.__Vfunc_fp8_mul__60__Vfuncout;
    vlSelfRef.__PVT__int8_next = ((0U == (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? (vlSelfRef.out 
                                      + (((- (IData)(
                                                     (1U 
                                                      & ((IData)(__PVT__int8_prod) 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (IData)(__PVT__int8_prod)))
                                   : 0U);
    vlSelfRef.__PVT__bf16_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                   ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__63__y = __PVT__bf16_prod;
                vlSelfRef.__Vfunc_fp32_add__63__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__63__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__63__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__63__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__63__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__63__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__63__x);
                vlSelfRef.__Vfunc_fp32_add__63__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__63__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__63__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__63__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__63__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__63__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__63__x))) {
                    vlSelfRef.__Vfunc_fp32_add__63__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__63__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__63__y))) {
                    vlSelfRef.__Vfunc_fp32_add__63__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__63__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__63__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__63__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__63__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__63__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__63__ey)));
                        vlSelfRef.__Vfunc_fp32_add__63__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__63__ex;
                        vlSelfRef.__Vfunc_fp32_add__63__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__63__sx;
                        vlSelfRef.__Vfunc_fp32_add__63__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__63__mx);
                        vlSelfRef.__Vfunc_fp32_add__63__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__63__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__63__my), (IData)(vlSelfRef.__Vfunc_fp32_add__63__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__63__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__63__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__63__ex)));
                        vlSelfRef.__Vfunc_fp32_add__63__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__63__ey;
                        vlSelfRef.__Vfunc_fp32_add__63__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__63__sy;
                        vlSelfRef.__Vfunc_fp32_add__63__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__63__my);
                        vlSelfRef.__Vfunc_fp32_add__63__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__63__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__63__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__63__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__63__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__63__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__63__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__63__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__63__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__63__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__63__ay));
                        vlSelfRef.__Vfunc_fp32_add__63__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__63__s_big;
                        vlSelfRef.__Vfunc_fp32_add__63__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__63__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__63__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__63__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__63__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__63__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__63__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__63__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__63__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__63__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__63__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__63__ay));
                            vlSelfRef.__Vfunc_fp32_add__63__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__63__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__63__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__63__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__63__ax));
                            vlSelfRef.__Vfunc_fp32_add__63__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__63__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__63__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__63__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__63__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__63__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__63__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__63__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__63__sh)));
                            vlSelfRef.__Vfunc_fp32_add__63__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__63__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__63__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__63__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__63__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__63__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__63__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__63__Vfuncout));
    vlSelfRef.__PVT__fp8_next = ((0U != (IData)(vlSymsp->TOP.top_tb__DOT__dut__DOT__grid__DOT____Vcellinp__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst__in_out_reset))
                                  ? 0U : ([&]() {
                vlSelfRef.__Vfunc_fp32_add__61__y = __PVT__fp8_prod;
                vlSelfRef.__Vfunc_fp32_add__61__x = vlSelfRef.out;
                vlSelfRef.__Vfunc_fp32_add__61__sx 
                    = (vlSelfRef.__Vfunc_fp32_add__61__x 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__61__ex 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__61__x 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__61__mx 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__61__x);
                vlSelfRef.__Vfunc_fp32_add__61__sy 
                    = (vlSelfRef.__Vfunc_fp32_add__61__y 
                       >> 0x1fU);
                vlSelfRef.__Vfunc_fp32_add__61__ey 
                    = (0xffU & (vlSelfRef.__Vfunc_fp32_add__61__y 
                                >> 0x17U));
                vlSelfRef.__Vfunc_fp32_add__61__my 
                    = (0x7fffffU & vlSelfRef.__Vfunc_fp32_add__61__y);
                if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__61__x))) {
                    vlSelfRef.__Vfunc_fp32_add__61__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__61__y;
                } else if ((0U == (0x7fffffffU & vlSelfRef.__Vfunc_fp32_add__61__y))) {
                    vlSelfRef.__Vfunc_fp32_add__61__Vfuncout 
                        = vlSelfRef.__Vfunc_fp32_add__61__x;
                } else {
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__61__ex) 
                         >= (IData)(vlSelfRef.__Vfunc_fp32_add__61__ey))) {
                        vlSelfRef.__Vfunc_fp32_add__61__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__61__ex) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__61__ey)));
                        vlSelfRef.__Vfunc_fp32_add__61__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__61__ex;
                        vlSelfRef.__Vfunc_fp32_add__61__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__61__sx;
                        vlSelfRef.__Vfunc_fp32_add__61__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__61__mx);
                        vlSelfRef.__Vfunc_fp32_add__61__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__61__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__61__my), (IData)(vlSelfRef.__Vfunc_fp32_add__61__e_diff))));
                    } else {
                        vlSelfRef.__Vfunc_fp32_add__61__e_diff 
                            = (0xffU & ((IData)(vlSelfRef.__Vfunc_fp32_add__61__ey) 
                                        - (IData)(vlSelfRef.__Vfunc_fp32_add__61__ex)));
                        vlSelfRef.__Vfunc_fp32_add__61__e_big 
                            = vlSelfRef.__Vfunc_fp32_add__61__ey;
                        vlSelfRef.__Vfunc_fp32_add__61__s_big 
                            = vlSelfRef.__Vfunc_fp32_add__61__sy;
                        vlSelfRef.__Vfunc_fp32_add__61__ax 
                            = (0x800000U | vlSelfRef.__Vfunc_fp32_add__61__my);
                        vlSelfRef.__Vfunc_fp32_add__61__ay 
                            = ((0x19U <= (IData)(vlSelfRef.__Vfunc_fp32_add__61__e_diff))
                                ? 0U : (0x1ffffffU 
                                        & VL_SHIFTR_III(25,25,8, 
                                                        (0x800000U 
                                                         | vlSelfRef.__Vfunc_fp32_add__61__mx), (IData)(vlSelfRef.__Vfunc_fp32_add__61__e_diff))));
                    }
                    vlSelfRef.__Vfunc_fp32_add__61__e_res 
                        = vlSelfRef.__Vfunc_fp32_add__61__e_big;
                    if (((IData)(vlSelfRef.__Vfunc_fp32_add__61__sx) 
                         == (IData)(vlSelfRef.__Vfunc_fp32_add__61__sy))) {
                        vlSelfRef.__Vfunc_fp32_add__61__sm 
                            = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__61__ax 
                                             + vlSelfRef.__Vfunc_fp32_add__61__ay));
                        vlSelfRef.__Vfunc_fp32_add__61__s_res 
                            = vlSelfRef.__Vfunc_fp32_add__61__s_big;
                        vlSelfRef.__Vfunc_fp32_add__61__Vfuncout 
                            = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                ? (((IData)(vlSelfRef.__Vfunc_fp32_add__61__s_res) 
                                    << 0x1fU) | ((0x7f800000U 
                                                  & (((IData)(1U) 
                                                      + (IData)(vlSelfRef.__Vfunc_fp32_add__61__e_res)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelfRef.__Vfunc_fp32_add__61__sm 
                                                       >> 1U))))
                                : (((IData)(vlSelfRef.__Vfunc_fp32_add__61__s_res) 
                                    << 0x1fU) | (((IData)(vlSelfRef.__Vfunc_fp32_add__61__e_res) 
                                                  << 0x17U) 
                                                 | (0x7fffffU 
                                                    & vlSelfRef.__Vfunc_fp32_add__61__sm))));
                    } else {
                        if ((vlSelfRef.__Vfunc_fp32_add__61__ax 
                             >= vlSelfRef.__Vfunc_fp32_add__61__ay)) {
                            vlSelfRef.__Vfunc_fp32_add__61__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__61__ax 
                                                 - vlSelfRef.__Vfunc_fp32_add__61__ay));
                            vlSelfRef.__Vfunc_fp32_add__61__s_res 
                                = vlSelfRef.__Vfunc_fp32_add__61__s_big;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__61__sm 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__61__ay 
                                                 - vlSelfRef.__Vfunc_fp32_add__61__ax));
                            vlSelfRef.__Vfunc_fp32_add__61__s_res 
                                = (1U & (~ (IData)(vlSelfRef.__Vfunc_fp32_add__61__s_big)));
                        }
                        if ((0U == vlSelfRef.__Vfunc_fp32_add__61__sm)) {
                            vlSelfRef.__Vfunc_fp32_add__61__Vfuncout = 0U;
                        } else {
                            vlSelfRef.__Vfunc_fp32_add__61__sh 
                                = ((0x1000000U & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                    ? 0U : ((0x800000U 
                                             & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                             ? 1U : 
                                            ((0x400000U 
                                              & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                              ? 2U : 
                                             ((0x200000U 
                                               & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                               ? 3U
                                               : ((0x100000U 
                                                   & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                   ? 4U
                                                   : 
                                                  ((0x80000U 
                                                    & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                    ? 5U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                     ? 6U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                      ? 7U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                       ? 8U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                        ? 9U
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                         ? 0xaU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                          ? 0xbU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                            ? 0xdU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                             ? 0xeU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                              ? 0xfU
                                                              : 
                                                             ((0x100U 
                                                               & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                               ? 0x10U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                                ? 0x11U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                                 ? 0x12U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                                  ? 0x13U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                                   ? 0x14U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                                    ? 0x15U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                                     ? 0x16U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelfRef.__Vfunc_fp32_add__61__sm)
                                                                      ? 0x17U
                                                                      : 0x18U))))))))))))))))))))))));
                            vlSelfRef.__Vfunc_fp32_add__61__ns 
                                = (0x1ffffffU & (vlSelfRef.__Vfunc_fp32_add__61__sm 
                                                 << (IData)(vlSelfRef.__Vfunc_fp32_add__61__sh)));
                            vlSelfRef.__Vfunc_fp32_add__61__Vfuncout 
                                = (((IData)(vlSelfRef.__Vfunc_fp32_add__61__sh) 
                                    > (IData)(vlSelfRef.__Vfunc_fp32_add__61__e_res))
                                    ? 0U : (((IData)(vlSelfRef.__Vfunc_fp32_add__61__s_res) 
                                             << 0x1fU) 
                                            | ((0x7f800000U 
                                                & (((IData)(vlSelfRef.__Vfunc_fp32_add__61__e_res) 
                                                    - (IData)(vlSelfRef.__Vfunc_fp32_add__61__sh)) 
                                                   << 0x17U)) 
                                               | (0x7fffffU 
                                                  & (vlSelfRef.__Vfunc_fp32_add__61__ns 
                                                     >> 1U)))));
                        }
                    }
                }
            }(), vlSelfRef.__Vfunc_fp32_add__61__Vfuncout));
}
