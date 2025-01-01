// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhello_top.h for the primary calling header

#include "verilated.h"

#include "Vhello_top___024root.h"

VL_ATTR_COLD void Vhello_top___024root___eval_static(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vhello_top___024root___eval_initial(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vhello_top___024root___eval_final(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vhello_top___024root___eval_triggers__stl(Vhello_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vhello_top___024root___dump_triggers__stl(Vhello_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vhello_top___024root___eval_stl(Vhello_top___024root* vlSelf);

VL_ATTR_COLD void Vhello_top___024root___eval_settle(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vhello_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vhello_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/hello-world/verilog/vsrc/hello_top.v", 4, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vhello_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhello_top___024root___dump_triggers__stl(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vhello_top___024root___stl_sequent__TOP__0(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->led = vlSelf->hello_top__DOT__h__DOT__blkReg;
    vlSelf->hello_top__DOT__h__DOT___cntReg_T_1 = ((IData)(1U) 
                                                   + vlSelf->hello_top__DOT__h__DOT__cntReg);
}

VL_ATTR_COLD void Vhello_top___024root___eval_stl(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vhello_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhello_top___024root___dump_triggers__act(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vhello_top___024root___dump_triggers__nba(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vhello_top___024root___ctor_var_reset(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->led = 0;
    vlSelf->hello_top__DOT__h__DOT__cntReg = 0;
    vlSelf->hello_top__DOT__h__DOT__blkReg = 0;
    vlSelf->hello_top__DOT__h__DOT___cntReg_T_1 = 0;
    vlSelf->__Vtrigrprev__TOP__clk = 0;
}
