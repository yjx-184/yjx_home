// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhello_top.h for the primary calling header

#include "verilated.h"

#include "Vhello_top__Syms.h"
#include "Vhello_top___024root.h"

void Vhello_top___024root___ctor_var_reset(Vhello_top___024root* vlSelf);

Vhello_top___024root::Vhello_top___024root(Vhello_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vhello_top___024root___ctor_var_reset(this);
}

void Vhello_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vhello_top___024root::~Vhello_top___024root() {
}
