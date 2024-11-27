// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsm_mealy.h for the primary calling header

#include "verilated.h"

#include "Vfsm_mealy__Syms.h"
#include "Vfsm_mealy___024root.h"

void Vfsm_mealy___024root___ctor_var_reset(Vfsm_mealy___024root* vlSelf);

Vfsm_mealy___024root::Vfsm_mealy___024root(Vfsm_mealy__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vfsm_mealy___024root___ctor_var_reset(this);
}

void Vfsm_mealy___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vfsm_mealy___024root::~Vfsm_mealy___024root() {
}
