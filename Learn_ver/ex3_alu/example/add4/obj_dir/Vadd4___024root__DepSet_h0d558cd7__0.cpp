// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4.h for the primary calling header

#include "verilated.h"

#include "Vadd4___024root.h"

VL_INLINE_OPT void Vadd4___024root___ico_sequent__TOP__0(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->add4__DOT__u3__DOT____VdfgTmp_h36175ebf__0 
        = (1U & (((IData)(vlSelf->a) ^ (IData)(vlSelf->b)) 
                 >> 3U));
    vlSelf->add4__DOT__u2__DOT____VdfgTmp_h36175ebf__0 
        = (1U & (((IData)(vlSelf->a) ^ (IData)(vlSelf->b)) 
                 >> 2U));
    vlSelf->add4__DOT__u1__DOT____VdfgTmp_h36175ebf__0 
        = (1U & (((IData)(vlSelf->a) ^ (IData)(vlSelf->b)) 
                 >> 1U));
    vlSelf->add4__DOT__u0__DOT____VdfgTmp_h36175ebf__0 
        = (1U & ((IData)(vlSelf->a) ^ (IData)(vlSelf->b)));
    vlSelf->add4__DOT____Vcellinp__u1____pinNumber3 
        = (1U & (((IData)(vlSelf->add4__DOT__u0__DOT____VdfgTmp_h36175ebf__0) 
                  & (IData)(vlSelf->ci)) | ((IData)(vlSelf->a) 
                                            & (IData)(vlSelf->b))));
    vlSelf->add4__DOT____Vcellinp__u2____pinNumber3 
        = (1U & (((IData)(vlSelf->add4__DOT__u1__DOT____VdfgTmp_h36175ebf__0) 
                  & (IData)(vlSelf->add4__DOT____Vcellinp__u1____pinNumber3)) 
                 | (((IData)(vlSelf->a) & (IData)(vlSelf->b)) 
                    >> 1U)));
    vlSelf->add4__DOT____Vcellinp__u3____pinNumber3 
        = (1U & (((IData)(vlSelf->add4__DOT__u2__DOT____VdfgTmp_h36175ebf__0) 
                  & (IData)(vlSelf->add4__DOT____Vcellinp__u2____pinNumber3)) 
                 | (((IData)(vlSelf->a) & (IData)(vlSelf->b)) 
                    >> 2U)));
    vlSelf->co = (1U & (((IData)(vlSelf->add4__DOT__u3__DOT____VdfgTmp_h36175ebf__0) 
                         & (IData)(vlSelf->add4__DOT____Vcellinp__u3____pinNumber3)) 
                        | (((IData)(vlSelf->a) & (IData)(vlSelf->b)) 
                           >> 3U)));
    vlSelf->sum = ((((IData)(vlSelf->add4__DOT__u3__DOT____VdfgTmp_h36175ebf__0) 
                     ^ (IData)(vlSelf->add4__DOT____Vcellinp__u3____pinNumber3)) 
                    << 3U) | ((((IData)(vlSelf->add4__DOT__u2__DOT____VdfgTmp_h36175ebf__0) 
                                ^ (IData)(vlSelf->add4__DOT____Vcellinp__u2____pinNumber3)) 
                               << 2U) | ((((IData)(vlSelf->add4__DOT__u1__DOT____VdfgTmp_h36175ebf__0) 
                                           ^ (IData)(vlSelf->add4__DOT____Vcellinp__u1____pinNumber3)) 
                                          << 1U) | 
                                         ((IData)(vlSelf->add4__DOT__u0__DOT____VdfgTmp_h36175ebf__0) 
                                          ^ (IData)(vlSelf->ci)))));
}

void Vadd4___024root___eval_ico(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vadd4___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vadd4___024root___eval_act(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___eval_act\n"); );
}

void Vadd4___024root___eval_nba(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___eval_nba\n"); );
}

void Vadd4___024root___eval_triggers__ico(Vadd4___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4___024root___dump_triggers__ico(Vadd4___024root* vlSelf);
#endif  // VL_DEBUG
void Vadd4___024root___eval_triggers__act(Vadd4___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4___024root___dump_triggers__act(Vadd4___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4___024root___dump_triggers__nba(Vadd4___024root* vlSelf);
#endif  // VL_DEBUG

void Vadd4___024root___eval(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<0> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vadd4___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vadd4___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("vsrc/add4.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vadd4___024root___eval_ico(vlSelf);
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
            Vadd4___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vadd4___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/add4.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vadd4___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vadd4___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/add4.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vadd4___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vadd4___024root___eval_debug_assertions(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->a & 0xf0U))) {
        Verilated::overWidthError("a");}
    if (VL_UNLIKELY((vlSelf->b & 0xf0U))) {
        Verilated::overWidthError("b");}
    if (VL_UNLIKELY((vlSelf->ci & 0xfeU))) {
        Verilated::overWidthError("ci");}
}
#endif  // VL_DEBUG
