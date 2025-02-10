// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VCombinational_top.h for the primary calling header

#ifndef VERILATED_VCOMBINATIONAL_TOP___024ROOT_H_
#define VERILATED_VCOMBINATIONAL_TOP___024ROOT_H_  // guard

#include "verilated.h"

class VCombinational_top__Syms;

class VCombinational_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(res,0,0);
    VL_IN8(in,3,0);
    VL_OUT8(seg,7,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VCombinational_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    VCombinational_top___024root(VCombinational_top__Syms* symsp, const char* v__name);
    ~VCombinational_top___024root();
    VL_UNCOPYABLE(VCombinational_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
