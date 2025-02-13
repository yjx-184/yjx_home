// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VAlu.h for the primary calling header

#ifndef VERILATED_VALU___024ROOT_H_
#define VERILATED_VALU___024ROOT_H_  // guard

#include "verilated.h"

class VAlu__Syms;

class VAlu___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_op,2,0);
    VL_IN8(io_a,3,0);
    VL_IN8(io_b,3,0);
    VL_OUT8(io_carry,0,0);
    VL_OUT8(io_zero,0,0);
    VL_OUT8(io_overflow,0,0);
    VL_OUT8(io_result,3,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VAlu__Syms* const vlSymsp;

    // CONSTRUCTORS
    VAlu___024root(VAlu__Syms* symsp, const char* v__name);
    ~VAlu___024root();
    VL_UNCOPYABLE(VAlu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
