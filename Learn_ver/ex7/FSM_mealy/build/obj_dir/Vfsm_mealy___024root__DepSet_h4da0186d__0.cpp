// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsm_mealy.h for the primary calling header

#include "verilated.h"

#include "Vfsm_mealy___024root.h"

extern const VlUnpacked<CData/*3:0*/, 32> Vfsm_mealy__ConstPool__TABLE_h95e8df4d_0;

VL_INLINE_OPT void Vfsm_mealy___024root___ico_sequent__TOP__0(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->out = ((~ ((IData)(vlSelf->fsm_mealy__DOT__state) 
                       >> 3U)) & ((4U & (IData)(vlSelf->fsm_mealy__DOT__state))
                                   ? (IData)(vlSelf->in)
                                   : ((~ ((IData)(vlSelf->fsm_mealy__DOT__state) 
                                          >> 1U)) & (IData)(vlSelf->in))));
    __Vtableidx1 = (((IData)(vlSelf->in) << 4U) | (IData)(vlSelf->fsm_mealy__DOT__state));
    vlSelf->fsm_mealy__DOT__next_state = Vfsm_mealy__ConstPool__TABLE_h95e8df4d_0
        [__Vtableidx1];
}

void Vfsm_mealy___024root___eval_ico(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vfsm_mealy___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vfsm_mealy___024root___eval_act(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vfsm_mealy___024root___nba_sequent__TOP__0(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->fsm_mealy__DOT__state = ((IData)(vlSelf->reset)
                                      ? 0U : (IData)(vlSelf->fsm_mealy__DOT__next_state));
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

VL_INLINE_OPT void Vfsm_mealy___024root___nba_sequent__TOP__1(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->fsm_mealy__DOT__btn_clk = ((IData)(vlSelf->fsm_mealy__DOT__u_btn_clk__DOT__btn_sta2) 
                                       & (~ (IData)(vlSelf->fsm_mealy__DOT__u_btn_clk__DOT__btn_last)));
    vlSelf->fsm_mealy__DOT__u_btn_clk__DOT__btn_last 
        = vlSelf->fsm_mealy__DOT__u_btn_clk__DOT__btn_sta2;
    vlSelf->fsm_mealy__DOT__u_btn_clk__DOT__btn_sta2 
        = vlSelf->fsm_mealy__DOT__u_btn_clk__DOT__btn_sta1;
    vlSelf->fsm_mealy__DOT__u_btn_clk__DOT__btn_sta1 
        = vlSelf->btn;
}

void Vfsm_mealy___024root___eval_nba(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vfsm_mealy___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vfsm_mealy___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vfsm_mealy___024root___eval_triggers__ico(Vfsm_mealy___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsm_mealy___024root___dump_triggers__ico(Vfsm_mealy___024root* vlSelf);
#endif  // VL_DEBUG
void Vfsm_mealy___024root___eval_triggers__act(Vfsm_mealy___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsm_mealy___024root___dump_triggers__act(Vfsm_mealy___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsm_mealy___024root___dump_triggers__nba(Vfsm_mealy___024root* vlSelf);
#endif  // VL_DEBUG

void Vfsm_mealy___024root___eval(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vfsm_mealy___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vfsm_mealy___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex7/FSM_mealy/vsrc/fsm_mealy.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vfsm_mealy___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vfsm_mealy___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vfsm_mealy___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex7/FSM_mealy/vsrc/fsm_mealy.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vfsm_mealy___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vfsm_mealy___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex7/FSM_mealy/vsrc/fsm_mealy.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vfsm_mealy___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vfsm_mealy___024root___eval_debug_assertions(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->in & 0xfeU))) {
        Verilated::overWidthError("in");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->btn & 0xfeU))) {
        Verilated::overWidthError("btn");}
}
#endif  // VL_DEBUG
