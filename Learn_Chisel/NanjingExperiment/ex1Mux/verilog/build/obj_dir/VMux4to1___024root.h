// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMux4to1.h for the primary calling header

#ifndef VERILATED_VMUX4TO1___024ROOT_H_
#define VERILATED_VMUX4TO1___024ROOT_H_  // guard

#include "verilated.h"

class VMux4to1__Syms;

class VMux4to1___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_X0,1,0);
    VL_IN8(io_X1,1,0);
    VL_IN8(io_X2,1,0);
    VL_IN8(io_X3,1,0);
    VL_IN8(io_Y,1,0);
    VL_OUT8(io_F,1,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VMux4to1__Syms* const vlSymsp;

    // CONSTRUCTORS
    VMux4to1___024root(VMux4to1__Syms* symsp, const char* v__name);
    ~VMux4to1___024root();
    VL_UNCOPYABLE(VMux4to1___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
