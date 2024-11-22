// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu_top.h for the primary calling header

#include "verilated.h"

#include "Valu_top___024root.h"

VL_ATTR_COLD void Valu_top___024root___eval_static(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Valu_top___024root___eval_initial__TOP(Valu_top___024root* vlSelf);

VL_ATTR_COLD void Valu_top___024root___eval_initial(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___eval_initial\n"); );
    // Body
    Valu_top___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Valu_top___024root___eval_initial__TOP(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->alu_top__DOT__i1__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->alu_top__DOT__i1__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->alu_top__DOT__i2__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->alu_top__DOT__i2__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list[0U] = 7U;
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list[1U] = 6U;
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list[2U] = 5U;
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list[3U] = 4U;
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list[4U] = 3U;
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list[5U] = 2U;
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list[6U] = 1U;
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list[7U] = 0U;
    vlSelf->alu_top__DOT__i0__DOT__i0__DOT__key_list[0U] = 1U;
    vlSelf->alu_top__DOT__i0__DOT__i0__DOT__key_list[1U] = 0U;
    vlSelf->alu_top__DOT__i0__DOT__i0__DOT__data_list[0U] = 1U;
    vlSelf->alu_top__DOT__i0__DOT__i0__DOT__data_list[1U] = 0U;
}

VL_ATTR_COLD void Valu_top___024root___eval_final(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Valu_top___024root___eval_triggers__stl(Valu_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_top___024root___dump_triggers__stl(Valu_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Valu_top___024root___eval_stl(Valu_top___024root* vlSelf);

VL_ATTR_COLD void Valu_top___024root___eval_settle(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Valu_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Valu_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex3_alu/vsrc/alu_top.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Valu_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_top___024root___dump_triggers__stl(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Valu_top___024root___ico_sequent__TOP__0(Valu_top___024root* vlSelf);

VL_ATTR_COLD void Valu_top___024root___eval_stl(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Valu_top___024root___ico_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_top___024root___dump_triggers__ico(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Valu_top___024root___dump_triggers__act(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_top___024root___dump_triggers__nba(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Valu_top___024root___ctor_var_reset(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->i_a = 0;
    vlSelf->i_b = 0;
    vlSelf->i_op = 0;
    vlSelf->o_result = 0;
    vlSelf->o_cin = 0;
    vlSelf->o_carry = 0;
    vlSelf->o_overflow = 0;
    vlSelf->o_max = 0;
    vlSelf->o_equ = 0;
    vlSelf->o_zero = 0;
    vlSelf->o_signbit = 0;
    vlSelf->o_seg = 0;
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->alu_top__DOT__i0__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->alu_top__DOT__i0__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->alu_top__DOT__i1__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->alu_top__DOT__i1__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->alu_top__DOT__i2__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->alu_top__DOT__i2__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list[__Vi0] = 0;
    }
}
