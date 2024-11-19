// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd1.h for the primary calling header

#ifndef VERILATED_VADD1___024ROOT_H_
#define VERILATED_VADD1___024ROOT_H_  // guard

#include "verilated.h"

class Vadd1__Syms;

class Vadd1___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a_i,0,0);
    VL_IN8(b_i,0,0);
    VL_IN8(c_i,0,0);
    VL_OUT8(s_i,0,0);
    VL_OUT8(c_o,0,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd1__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd1___024root(Vadd1__Syms* symsp, const char* v__name);
    ~Vadd1___024root();
    VL_UNCOPYABLE(Vadd1___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
