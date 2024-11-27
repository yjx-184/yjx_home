// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsm_mealy.h for the primary calling header

#include "verilated.h"

#include "Vfsm_mealy___024root.h"

VL_ATTR_COLD void Vfsm_mealy___024root___eval_static(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vfsm_mealy___024root___eval_initial(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__fsm_mealy__DOT__btn_clk 
        = vlSelf->fsm_mealy__DOT__btn_clk;
    vlSelf->__Vtrigrprev__TOP__reset = vlSelf->reset;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vfsm_mealy___024root___eval_final(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vfsm_mealy___024root___eval_triggers__stl(Vfsm_mealy___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsm_mealy___024root___dump_triggers__stl(Vfsm_mealy___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vfsm_mealy___024root___eval_stl(Vfsm_mealy___024root* vlSelf);

VL_ATTR_COLD void Vfsm_mealy___024root___eval_settle(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vfsm_mealy___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vfsm_mealy___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex7/FSM_mealy/vsrc/fsm_mealy.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vfsm_mealy___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsm_mealy___024root___dump_triggers__stl(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*3:0*/, 32> Vfsm_mealy__ConstPool__TABLE_h95e8df4d_0;

VL_ATTR_COLD void Vfsm_mealy___024root___stl_sequent__TOP__0(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->sta = vlSelf->fsm_mealy__DOT__state;
    vlSelf->out = ((~ ((IData)(vlSelf->fsm_mealy__DOT__state) 
                       >> 3U)) & ((4U & (IData)(vlSelf->fsm_mealy__DOT__state))
                                   ? (IData)(vlSelf->in)
                                   : ((~ ((IData)(vlSelf->fsm_mealy__DOT__state) 
                                          >> 1U)) & (IData)(vlSelf->in))));
    __Vtableidx1 = (((IData)(vlSelf->in) << 4U) | (IData)(vlSelf->fsm_mealy__DOT__state));
    vlSelf->fsm_mealy__DOT__next_state = Vfsm_mealy__ConstPool__TABLE_h95e8df4d_0
        [__Vtableidx1];
}

VL_ATTR_COLD void Vfsm_mealy___024root___eval_stl(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vfsm_mealy___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsm_mealy___024root___dump_triggers__ico(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsm_mealy___024root___dump_triggers__act(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge fsm_mealy.btn_clk or posedge reset)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsm_mealy___024root___dump_triggers__nba(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge fsm_mealy.btn_clk or posedge reset)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfsm_mealy___024root___ctor_var_reset(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->in = 0;
    vlSelf->reset = 0;
    vlSelf->out = 0;
    vlSelf->sta = 0;
    vlSelf->btn = 0;
    vlSelf->fsm_mealy__DOT__btn_clk = 0;
    vlSelf->fsm_mealy__DOT__state = 0;
    vlSelf->fsm_mealy__DOT__next_state = 0;
    vlSelf->fsm_mealy__DOT__u_btn_clk__DOT__btn_sta1 = 0;
    vlSelf->fsm_mealy__DOT__u_btn_clk__DOT__btn_sta2 = 0;
    vlSelf->fsm_mealy__DOT__u_btn_clk__DOT__btn_last = 0;
    vlSelf->__Vtrigrprev__TOP__fsm_mealy__DOT__btn_clk = 0;
    vlSelf->__Vtrigrprev__TOP__reset = 0;
    vlSelf->__Vtrigrprev__TOP__clk = 0;
}
