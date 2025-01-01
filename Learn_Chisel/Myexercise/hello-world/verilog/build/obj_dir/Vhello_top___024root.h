// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vhello_top.h for the primary calling header

#ifndef VERILATED_VHELLO_TOP___024ROOT_H_
#define VERILATED_VHELLO_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vhello_top__Syms;

class Vhello_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_OUT8(led,0,0);
    CData/*0:0*/ hello_top__DOT__h__DOT__blkReg;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ hello_top__DOT__h__DOT__cntReg;
    IData/*31:0*/ hello_top__DOT__h__DOT___cntReg_T_1;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vhello_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vhello_top___024root(Vhello_top__Syms* symsp, const char* v__name);
    ~Vhello_top___024root();
    VL_UNCOPYABLE(Vhello_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
