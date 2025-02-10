// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop_top.h for the primary calling header

#include "verilated.h"

#include "VTop_top__Syms.h"
#include "VTop_top___024root.h"

void VTop_top___024root___ctor_var_reset(VTop_top___024root* vlSelf);

VTop_top___024root::VTop_top___024root(VTop_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VTop_top___024root___ctor_var_reset(this);
}

void VTop_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VTop_top___024root::~VTop_top___024root() {
}
