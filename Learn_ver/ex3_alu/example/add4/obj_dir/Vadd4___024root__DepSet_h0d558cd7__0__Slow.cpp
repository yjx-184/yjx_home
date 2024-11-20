// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vadd4.h for the primary calling header

#include "verilated.h"

#include "Vadd4___024root.h"

VL_ATTR_COLD void Vadd4___024root___eval_static(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vadd4___024root___eval_initial(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___eval_initial\n"); );
}

VL_ATTR_COLD void Vadd4___024root___eval_final(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vadd4___024root___eval_triggers__stl(Vadd4___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4___024root___dump_triggers__stl(Vadd4___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vadd4___024root___eval_stl(Vadd4___024root* vlSelf);

VL_ATTR_COLD void Vadd4___024root___eval_settle(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vadd4___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vadd4___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("vsrc/add4.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vadd4___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4___024root___dump_triggers__stl(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vadd4___024root___ico_sequent__TOP__0(Vadd4___024root* vlSelf);

VL_ATTR_COLD void Vadd4___024root___eval_stl(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vadd4___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4___024root___dump_triggers__ico(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vadd4___024root___dump_triggers__act(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vadd4___024root___dump_triggers__nba(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vadd4___024root___ctor_var_reset(Vadd4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a = VL_RAND_RESET_I(4);
    vlSelf->b = VL_RAND_RESET_I(4);
    vlSelf->ci = VL_RAND_RESET_I(1);
    vlSelf->sum = VL_RAND_RESET_I(4);
    vlSelf->co = VL_RAND_RESET_I(1);
    vlSelf->add4__DOT____Vcellinp__u1____pinNumber3 = VL_RAND_RESET_I(1);
    vlSelf->add4__DOT____Vcellinp__u2____pinNumber3 = VL_RAND_RESET_I(1);
    vlSelf->add4__DOT____Vcellinp__u3____pinNumber3 = VL_RAND_RESET_I(1);
    vlSelf->add4__DOT__u0__DOT____VdfgTmp_h36175ebf__0 = 0;
    vlSelf->add4__DOT__u1__DOT____VdfgTmp_h36175ebf__0 = 0;
    vlSelf->add4__DOT__u2__DOT____VdfgTmp_h36175ebf__0 = 0;
    vlSelf->add4__DOT__u3__DOT____VdfgTmp_h36175ebf__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
