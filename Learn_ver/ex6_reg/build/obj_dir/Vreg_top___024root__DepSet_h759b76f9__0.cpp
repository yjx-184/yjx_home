// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vreg_top.h for the primary calling header

#include "verilated.h"

#include "Vreg_top___024root.h"

void Vreg_top___024root___eval_act(Vreg_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_top___024root___eval_act\n"); );
}

extern const VlUnpacked<CData/*7:0*/, 16> Vreg_top__ConstPool__TABLE_h1f93ebb4_0;

VL_INLINE_OPT void Vreg_top___024root___nba_sequent__TOP__0(Vreg_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    vlSelf->reg_top__DOT__lfsr_out = ((IData)(vlSelf->reset)
                                       ? ((0U == (IData)(vlSelf->reg_top__DOT__lfsr_out))
                                           ? 1U : (
                                                   ((IData)(vlSelf->reg_top__DOT__u_lfsr__DOT__feedback) 
                                                    << 7U) 
                                                   | (0x7fU 
                                                      & ((IData)(vlSelf->reg_top__DOT__lfsr_out) 
                                                         >> 1U))))
                                       : 1U);
    vlSelf->reg_top__DOT__u_lfsr__DOT__feedback = (1U 
                                                   & VL_REDXOR_8(
                                                                 (0x1dU 
                                                                  & (IData)(vlSelf->reg_top__DOT__lfsr_out))));
    __Vtableidx1 = (0xfU & (IData)(vlSelf->reg_top__DOT__lfsr_out));
    vlSelf->seg_u = Vreg_top__ConstPool__TABLE_h1f93ebb4_0
        [__Vtableidx1];
    __Vtableidx2 = (0xfU & ((IData)(vlSelf->reg_top__DOT__lfsr_out) 
                            >> 4U));
    vlSelf->seg_t = Vreg_top__ConstPool__TABLE_h1f93ebb4_0
        [__Vtableidx2];
}

VL_INLINE_OPT void Vreg_top___024root___nba_sequent__TOP__1(Vreg_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_top___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->reg_top__DOT__btn_clk = ((IData)(vlSelf->reset) 
                                     & ((IData)(vlSelf->reg_top__DOT__u_btn_clk__DOT__btn_sta2) 
                                        & (~ (IData)(vlSelf->reg_top__DOT__u_btn_clk__DOT__btn_last))));
    vlSelf->reg_top__DOT__u_btn_clk__DOT__btn_last 
        = ((IData)(vlSelf->reset) & (IData)(vlSelf->reg_top__DOT__u_btn_clk__DOT__btn_sta2));
    vlSelf->reg_top__DOT__u_btn_clk__DOT__btn_sta2 
        = ((IData)(vlSelf->reset) & (IData)(vlSelf->reg_top__DOT__u_btn_clk__DOT__btn_sta1));
    vlSelf->reg_top__DOT__u_btn_clk__DOT__btn_sta1 
        = ((IData)(vlSelf->reset) & (IData)(vlSelf->btn));
}

void Vreg_top___024root___eval_nba(Vreg_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vreg_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vreg_top___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vreg_top___024root___eval_triggers__act(Vreg_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vreg_top___024root___dump_triggers__act(Vreg_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vreg_top___024root___dump_triggers__nba(Vreg_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vreg_top___024root___eval(Vreg_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_top___024root___eval\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vreg_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vreg_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex6_reg/vsrc/reg_top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vreg_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vreg_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex6_reg/vsrc/reg_top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vreg_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vreg_top___024root___eval_debug_assertions(Vreg_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->btn & 0xfeU))) {
        Verilated::overWidthError("btn");}
}
#endif  // VL_DEBUG
