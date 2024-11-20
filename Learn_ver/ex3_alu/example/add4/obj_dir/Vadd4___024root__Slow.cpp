// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4.h for the primary calling header

#include "verilated.h"

#include "Vadd4__Syms.h"
#include "Vadd4___024root.h"

void Vadd4___024root___ctor_var_reset(Vadd4___024root* vlSelf);

Vadd4___024root::Vadd4___024root(Vadd4__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vadd4___024root___ctor_var_reset(this);
}

void Vadd4___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vadd4___024root::~Vadd4___024root() {
}
