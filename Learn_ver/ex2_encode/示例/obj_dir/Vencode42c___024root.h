// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vencode42c.h for the primary calling header

#ifndef VERILATED_VENCODE42C___024ROOT_H_
#define VERILATED_VENCODE42C___024ROOT_H_  // guard

#include "verilated.h"

class Vencode42c__Syms;

class Vencode42c___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(en,0,0);
    VL_IN8(in_code,3,0);
    VL_OUT8(out_code,1,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vencode42c__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vencode42c___024root(Vencode42c__Syms* symsp, const char* v__name);
    ~Vencode42c___024root();
    VL_UNCOPYABLE(Vencode42c___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
