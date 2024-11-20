// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd4b.h for the primary calling header

#ifndef VERILATED_VADD4B___024ROOT_H_
#define VERILATED_VADD4B___024ROOT_H_  // guard

#include "verilated.h"

class Vadd4b__Syms;

class Vadd4b___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a,3,0);
    VL_IN8(b,3,0);
    VL_OUT8(sum,3,0);
    VL_OUT8(co,0,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd4b__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd4b___024root(Vadd4b__Syms* symsp, const char* v__name);
    ~Vadd4b___024root();
    VL_UNCOPYABLE(Vadd4b___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
