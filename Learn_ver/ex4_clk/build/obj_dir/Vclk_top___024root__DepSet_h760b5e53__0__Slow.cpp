// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vclk_top.h for the primary calling header

#include "verilated.h"

#include "Vclk_top___024root.h"

VL_ATTR_COLD void Vclk_top___024root___eval_static(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vclk_top___024root___eval_initial(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk_top__DOT__clk_1s 
        = vlSelf->clk_top__DOT__clk_1s;
    vlSelf->__Vtrigrprev__TOP__reset = vlSelf->reset;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vclk_top___024root___eval_final(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vclk_top___024root___eval_triggers__stl(Vclk_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vclk_top___024root___dump_triggers__stl(Vclk_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vclk_top___024root___eval_stl(Vclk_top___024root* vlSelf);

VL_ATTR_COLD void Vclk_top___024root___eval_settle(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vclk_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vclk_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex4_clk/vsrc/clk_top.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vclk_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vclk_top___024root___dump_triggers__stl(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*7:0*/, 16> Vclk_top__ConstPool__TABLE_h88432187_0;

VL_ATTR_COLD void Vclk_top___024root___stl_sequent__TOP__0(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    __Vtableidx1 = (0xfU & VL_DIV_III(32, (IData)(vlSelf->clk_top__DOT__count), (IData)(0xaU)));
    vlSelf->seg_tens = Vclk_top__ConstPool__TABLE_h88432187_0
        [__Vtableidx1];
    __Vtableidx2 = (0xfU & VL_MODDIV_III(32, (IData)(vlSelf->clk_top__DOT__count), (IData)(0xaU)));
    vlSelf->seg_units = Vclk_top__ConstPool__TABLE_h88432187_0
        [__Vtableidx2];
}

VL_ATTR_COLD void Vclk_top___024root___eval_stl(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vclk_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vclk_top___024root___dump_triggers__act(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk_top.clk_1s or posedge reset)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or posedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vclk_top___024root___dump_triggers__nba(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk_top.clk_1s or posedge reset)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or posedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vclk_top___024root___ctor_var_reset(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->reset = 0;
    vlSelf->sta = 0;
    vlSelf->seg_tens = 0;
    vlSelf->seg_units = 0;
    vlSelf->led_o = 0;
    vlSelf->clk_top__DOT__clk_1s = 0;
    vlSelf->clk_top__DOT__count = 0;
    vlSelf->clk_top__DOT__clkck_divider__DOT__count_clk = 0;
    vlSelf->__Vtrigrprev__TOP__clk_top__DOT__clk_1s = 0;
    vlSelf->__Vtrigrprev__TOP__reset = 0;
    vlSelf->__Vtrigrprev__TOP__clk = 0;
}
