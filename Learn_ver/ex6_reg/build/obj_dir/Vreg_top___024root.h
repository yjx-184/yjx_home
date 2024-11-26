// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vreg_top.h for the primary calling header

#ifndef VERILATED_VREG_TOP___024ROOT_H_
#define VERILATED_VREG_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vreg_top__Syms;

class Vreg_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ reg_top__DOT__btn_clk;
    VL_IN8(btn,0,0);
    VL_OUT8(seg_u,7,0);
    VL_OUT8(seg_t,7,0);
    CData/*7:0*/ reg_top__DOT__lfsr_out;
    CData/*0:0*/ reg_top__DOT__u_btn_clk__DOT__btn_sta1;
    CData/*0:0*/ reg_top__DOT__u_btn_clk__DOT__btn_sta2;
    CData/*0:0*/ reg_top__DOT__u_btn_clk__DOT__btn_last;
    CData/*0:0*/ reg_top__DOT__u_lfsr__DOT__feedback;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__reset;
    CData/*0:0*/ __Vtrigrprev__TOP__reg_top__DOT__btn_clk;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vreg_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vreg_top___024root(Vreg_top__Syms* symsp, const char* v__name);
    ~Vreg_top___024root();
    VL_UNCOPYABLE(Vreg_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
