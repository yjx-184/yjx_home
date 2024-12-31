// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vhello_top.h for the primary calling header

#include "verilated.h"

#include "Vhello_top___024root.h"

void Vhello_top___024root___eval_act(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vhello_top___024root___nba_sequent__TOP__0(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__hello_top__DOT__h__DOT__cntReg;
    __Vdly__hello_top__DOT__h__DOT__cntReg = 0;
    // Body
    __Vdly__hello_top__DOT__h__DOT__cntReg = vlSelf->hello_top__DOT__h__DOT__cntReg;
    if ((0x17d783fU == vlSelf->hello_top__DOT__h__DOT__cntReg)) {
        __Vdly__hello_top__DOT__h__DOT__cntReg = 0U;
        vlSelf->hello_top__DOT__h__DOT__blkReg = (1U 
                                                  & (~ (IData)(vlSelf->hello_top__DOT__h__DOT__blkReg)));
    } else {
        __Vdly__hello_top__DOT__h__DOT__cntReg = vlSelf->hello_top__DOT__h__DOT___cntReg_T_1;
    }
    vlSelf->hello_top__DOT__h__DOT__cntReg = __Vdly__hello_top__DOT__h__DOT__cntReg;
    vlSelf->hello_top__DOT__h__DOT___cntReg_T_1 = ((IData)(1U) 
                                                   + vlSelf->hello_top__DOT__h__DOT__cntReg);
    vlSelf->led = vlSelf->hello_top__DOT__h__DOT__blkReg;
}

void Vhello_top___024root___eval_nba(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vhello_top___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vhello_top___024root___eval_triggers__act(Vhello_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vhello_top___024root___dump_triggers__act(Vhello_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vhello_top___024root___dump_triggers__nba(Vhello_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vhello_top___024root___eval(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
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
            Vhello_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vhello_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/hello-world/verilog/vsrc/hello_top.v", 4, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vhello_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vhello_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/hello-world/verilog/vsrc/hello_top.v", 4, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vhello_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vhello_top___024root___eval_debug_assertions(Vhello_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vhello_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vhello_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
