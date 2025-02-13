// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAlu.h for the primary calling header

#include "verilated.h"

#include "VAlu__Syms.h"
#include "VAlu___024root.h"

void VAlu___024root___ctor_var_reset(VAlu___024root* vlSelf);

VAlu___024root::VAlu___024root(VAlu__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VAlu___024root___ctor_var_reset(this);
}

void VAlu___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VAlu___024root::~VAlu___024root() {
}
