// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop_top.h for the primary calling header

#ifndef VERILATED_VTOP_TOP___024ROOT_H_
#define VERILATED_VTOP_TOP___024ROOT_H_  // guard

#include "verilated.h"

class VTop_top__Syms;

class VTop_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(res,0,0);
    VL_OUT8(seg,7,0);
    CData/*3:0*/ Top_top__DOT__uut__DOT__counter4;
    CData/*0:0*/ Top_top__DOT__uut__DOT__tick;
    CData/*3:0*/ Top_top__DOT__uut__DOT___counter4_T_1;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    IData/*26:0*/ Top_top__DOT__uut__DOT__secCounter;
    IData/*26:0*/ Top_top__DOT__uut__DOT___secCounter_T_1;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTop_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop_top___024root(VTop_top__Syms* symsp, const char* v__name);
    ~VTop_top___024root();
    VL_UNCOPYABLE(VTop_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
