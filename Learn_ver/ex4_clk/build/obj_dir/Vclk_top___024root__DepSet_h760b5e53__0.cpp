// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vclk_top.h for the primary calling header

#include "verilated.h"

#include "Vclk_top___024root.h"

void Vclk_top___024root___eval_act(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vclk_top___024root___nba_sequent__TOP__0(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*24:0*/ __Vdly__clk_top__DOT__clkck_divider__DOT__count_clk;
    __Vdly__clk_top__DOT__clkck_divider__DOT__count_clk = 0;
    CData/*0:0*/ __Vdly__clk_top__DOT__clk_1s;
    __Vdly__clk_top__DOT__clk_1s = 0;
    // Body
    __Vdly__clk_top__DOT__clk_1s = vlSelf->clk_top__DOT__clk_1s;
    __Vdly__clk_top__DOT__clkck_divider__DOT__count_clk 
        = vlSelf->clk_top__DOT__clkck_divider__DOT__count_clk;
    if (vlSelf->reset) {
        __Vdly__clk_top__DOT__clkck_divider__DOT__count_clk = 0U;
        __Vdly__clk_top__DOT__clk_1s = 0U;
    } else if ((0x17d783fU == vlSelf->clk_top__DOT__clkck_divider__DOT__count_clk)) {
        __Vdly__clk_top__DOT__clk_1s = (1U & (~ (IData)(vlSelf->clk_top__DOT__clk_1s)));
        __Vdly__clk_top__DOT__clkck_divider__DOT__count_clk = 0U;
    } else {
        __Vdly__clk_top__DOT__clkck_divider__DOT__count_clk 
            = (0x1ffffffU & ((IData)(1U) + vlSelf->clk_top__DOT__clkck_divider__DOT__count_clk));
    }
    vlSelf->clk_top__DOT__clkck_divider__DOT__count_clk 
        = __Vdly__clk_top__DOT__clkck_divider__DOT__count_clk;
    vlSelf->clk_top__DOT__clk_1s = __Vdly__clk_top__DOT__clk_1s;
}

extern const VlUnpacked<CData/*7:0*/, 16> Vclk_top__ConstPool__TABLE_h88432187_0;

VL_INLINE_OPT void Vclk_top___024root___nba_sequent__TOP__1(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*6:0*/ __Vdly__clk_top__DOT__count;
    __Vdly__clk_top__DOT__count = 0;
    // Body
    __Vdly__clk_top__DOT__count = vlSelf->clk_top__DOT__count;
    if (vlSelf->reset) {
        __Vdly__clk_top__DOT__count = 0U;
        vlSelf->led_o = 0U;
    } else if (vlSelf->sta) {
        if ((0x63U == (IData)(vlSelf->clk_top__DOT__count))) {
            __Vdly__clk_top__DOT__count = 0U;
            vlSelf->led_o = 1U;
        } else {
            __Vdly__clk_top__DOT__count = (0x7fU & 
                                           ((IData)(1U) 
                                            + (IData)(vlSelf->clk_top__DOT__count)));
            vlSelf->led_o = 0U;
        }
    }
    vlSelf->clk_top__DOT__count = __Vdly__clk_top__DOT__count;
    __Vtableidx1 = (0xfU & VL_DIV_III(32, (IData)(vlSelf->clk_top__DOT__count), (IData)(0xaU)));
    vlSelf->seg_tens = Vclk_top__ConstPool__TABLE_h88432187_0
        [__Vtableidx1];
    __Vtableidx2 = (0xfU & VL_MODDIV_III(32, (IData)(vlSelf->clk_top__DOT__count), (IData)(0xaU)));
    vlSelf->seg_units = Vclk_top__ConstPool__TABLE_h88432187_0
        [__Vtableidx2];
}

void Vclk_top___024root___eval_nba(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vclk_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vclk_top___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vclk_top___024root___eval_triggers__act(Vclk_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vclk_top___024root___dump_triggers__act(Vclk_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vclk_top___024root___dump_triggers__nba(Vclk_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vclk_top___024root___eval(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___eval\n"); );
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
            Vclk_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vclk_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex4_clk/vsrc/clk_top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vclk_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vclk_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex4_clk/vsrc/clk_top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vclk_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vclk_top___024root___eval_debug_assertions(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->sta & 0xfeU))) {
        Verilated::overWidthError("sta");}
}
#endif  // VL_DEBUG
