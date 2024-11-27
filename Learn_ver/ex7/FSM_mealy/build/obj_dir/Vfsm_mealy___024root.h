// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfsm_mealy.h for the primary calling header

#ifndef VERILATED_VFSM_MEALY___024ROOT_H_
#define VERILATED_VFSM_MEALY___024ROOT_H_  // guard

#include "verilated.h"

class Vfsm_mealy__Syms;

class Vfsm_mealy___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ fsm_mealy__DOT__btn_clk;
    VL_IN8(in,0,0);
    VL_OUT8(out,0,0);
    VL_OUT8(sta,3,0);
    VL_IN8(btn,0,0);
    CData/*3:0*/ fsm_mealy__DOT__state;
    CData/*3:0*/ fsm_mealy__DOT__next_state;
    CData/*0:0*/ fsm_mealy__DOT__u_btn_clk__DOT__btn_sta1;
    CData/*0:0*/ fsm_mealy__DOT__u_btn_clk__DOT__btn_sta2;
    CData/*0:0*/ fsm_mealy__DOT__u_btn_clk__DOT__btn_last;
    CData/*0:0*/ __Vtrigrprev__TOP__fsm_mealy__DOT__btn_clk;
    CData/*0:0*/ __Vtrigrprev__TOP__reset;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfsm_mealy__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfsm_mealy___024root(Vfsm_mealy__Syms* symsp, const char* v__name);
    ~Vfsm_mealy___024root();
    VL_UNCOPYABLE(Vfsm_mealy___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
