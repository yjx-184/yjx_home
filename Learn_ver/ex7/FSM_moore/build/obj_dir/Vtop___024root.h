// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ top__DOT__btn_clk;
    VL_IN8(in,0,0);
    VL_IN8(btn,0,0);
    VL_OUT8(out,0,0);
    VL_OUT8(sta,3,0);
    CData/*0:0*/ top__DOT__u_btn_clk__DOT__btn_sta1;
    CData/*0:0*/ top__DOT__u_btn_clk__DOT__btn_sta2;
    CData/*0:0*/ top__DOT__u_btn_clk__DOT__btn_last;
    CData/*3:0*/ top__DOT__u_fsm_bin__DOT__state_din;
    CData/*3:0*/ top__DOT__u_fsm_bin__DOT__state_dout;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__reset;
    CData/*0:0*/ __Vtrigrprev__TOP__top__DOT__btn_clk;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*3:0*/, 9> top__DOT__u_fsm_bin__DOT__outMux__DOT__i0__DOT__key_list;
    VlUnpacked<CData/*0:0*/, 9> top__DOT__u_fsm_bin__DOT__outMux__DOT__i0__DOT__data_list;
    VlUnpacked<CData/*3:0*/, 9> top__DOT__u_fsm_bin__DOT__stateMux__DOT__i0__DOT__key_list;
    VlUnpacked<CData/*3:0*/, 9> top__DOT__u_fsm_bin__DOT__stateMux__DOT__i0__DOT__data_list;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
