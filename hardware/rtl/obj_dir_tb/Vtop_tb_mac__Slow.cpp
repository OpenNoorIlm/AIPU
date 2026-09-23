// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_tb.h for the primary calling header

#include "Vtop_tb__pch.h"
#include "Vtop_tb__Syms.h"
#include "Vtop_tb_mac.h"

void Vtop_tb_mac___ctor_var_reset(Vtop_tb_mac* vlSelf);

Vtop_tb_mac::Vtop_tb_mac(Vtop_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_tb_mac___ctor_var_reset(this);
}

void Vtop_tb_mac::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_tb_mac::~Vtop_tb_mac() {
}
