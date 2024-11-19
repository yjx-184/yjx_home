// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd1.h for the primary calling header

#include "verilated.h"

#include "Vadd1__Syms.h"
#include "Vadd1___024root.h"

void Vadd1___024root___ctor_var_reset(Vadd1___024root* vlSelf);

Vadd1___024root::Vadd1___024root(Vadd1__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vadd1___024root___ctor_var_reset(this);
}

void Vadd1___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vadd1___024root::~Vadd1___024root() {
}
