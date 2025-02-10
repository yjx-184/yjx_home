// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMux4to1.h for the primary calling header

#include "verilated.h"

#include "VMux4to1__Syms.h"
#include "VMux4to1___024root.h"

void VMux4to1___024root___ctor_var_reset(VMux4to1___024root* vlSelf);

VMux4to1___024root::VMux4to1___024root(VMux4to1__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VMux4to1___024root___ctor_var_reset(this);
}

void VMux4to1___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VMux4to1___024root::~VMux4to1___024root() {
}
