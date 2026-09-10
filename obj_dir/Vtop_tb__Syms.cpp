// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop_tb__pch.h"
#include "Vtop_tb.h"
#include "Vtop_tb___024root.h"
#include "Vtop_tb_chain_CxC.h"

// FUNCTIONS
Vtop_tb__Syms::~Vtop_tb__Syms()
{
}

Vtop_tb__Syms::Vtop_tb__Syms(VerilatedContext* contextp, const char* namep, Vtop_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst{this, Verilated::catName(namep, "top_tb.dut.grid.grow[0].gcol[0].chain_inst")}
    , TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__1__KET____DOT__chain_inst{this, Verilated::catName(namep, "top_tb.dut.grid.grow[0].gcol[1].chain_inst")}
    , TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__1__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst{this, Verilated::catName(namep, "top_tb.dut.grid.grow[1].gcol[0].chain_inst")}
    , TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__1__KET____DOT__gcol__BRA__1__KET____DOT__chain_inst{this, Verilated::catName(namep, "top_tb.dut.grid.grow[1].gcol[1].chain_inst")}
{
        // Check resources
        Verilated::stackCheck(1228);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst = &TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst;
    TOP.__PVT__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__1__KET____DOT__chain_inst = &TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__1__KET____DOT__chain_inst;
    TOP.__PVT__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__1__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst = &TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__1__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst;
    TOP.__PVT__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__1__KET____DOT__gcol__BRA__1__KET____DOT__chain_inst = &TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__1__KET____DOT__gcol__BRA__1__KET____DOT__chain_inst;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst.__Vconfigure(true);
    TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__0__KET____DOT__gcol__BRA__1__KET____DOT__chain_inst.__Vconfigure(false);
    TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__1__KET____DOT__gcol__BRA__0__KET____DOT__chain_inst.__Vconfigure(false);
    TOP__top_tb__DOT__dut__DOT__grid__DOT__grow__BRA__1__KET____DOT__gcol__BRA__1__KET____DOT__chain_inst.__Vconfigure(false);
}
