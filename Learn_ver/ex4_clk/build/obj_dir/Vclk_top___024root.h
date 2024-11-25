// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vclk_top.h for the primary calling header

#ifndef VERILATED_VCLK_TOP___024ROOT_H_
#define VERILATED_VCLK_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vclk_top__Syms;

class Vclk_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ clk_top__DOT__clk_1s;
    VL_IN8(sta,0,0);
    VL_OUT8(seg_tens,7,0);
    VL_OUT8(seg_units,7,0);
    VL_OUT8(led_o,0,0);
    CData/*6:0*/ clk_top__DOT__count;
    CData/*0:0*/ __Vtrigrprev__TOP__clk_top__DOT__clk_1s;
    CData/*0:0*/ __Vtrigrprev__TOP__reset;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    IData/*24:0*/ clk_top__DOT__clkck_divider__DOT__count_clk;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vclk_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vclk_top___024root(Vclk_top__Syms* symsp, const char* v__name);
    ~Vclk_top___024root();
    VL_UNCOPYABLE(Vclk_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
