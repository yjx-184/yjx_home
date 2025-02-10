// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSeg.h for the primary calling header

#include "verilated.h"

#include "VSeg__Syms.h"
#include "VSeg___024root.h"

void VSeg___024root___ctor_var_reset(VSeg___024root* vlSelf);

VSeg___024root::VSeg___024root(VSeg__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VSeg___024root___ctor_var_reset(this);
}

void VSeg___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VSeg___024root::~VSeg___024root() {
}
