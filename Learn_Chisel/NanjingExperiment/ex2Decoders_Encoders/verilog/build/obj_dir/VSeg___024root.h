// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSeg.h for the primary calling header

#ifndef VERILATED_VSEG___024ROOT_H_
#define VERILATED_VSEG___024ROOT_H_  // guard

#include "verilated.h"

class VSeg__Syms;

class VSeg___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_in,7,0);
    VL_IN8(io_sel,0,0);
    VL_OUT8(io_out,2,0);
    VL_OUT8(io_seg,6,0);
    VL_OUT8(io_valid,0,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VSeg__Syms* const vlSymsp;

    // CONSTRUCTORS
    VSeg___024root(VSeg__Syms* symsp, const char* v__name);
    ~VSeg___024root();
    VL_UNCOPYABLE(VSeg___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
