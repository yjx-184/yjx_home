// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vclk_top.h for the primary calling header

#include "verilated.h"

#include "Vclk_top__Syms.h"
#include "Vclk_top___024root.h"

void Vclk_top___024root___ctor_var_reset(Vclk_top___024root* vlSelf);

Vclk_top___024root::Vclk_top___024root(Vclk_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vclk_top___024root___ctor_var_reset(this);
}

void Vclk_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vclk_top___024root::~Vclk_top___024root() {
}
