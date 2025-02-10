// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCombinational_top.h for the primary calling header

#include "verilated.h"

#include "VCombinational_top___024root.h"

VL_INLINE_OPT void VCombinational_top___024root___ico_sequent__TOP__0(VCombinational_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCombinational_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCombinational_top___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->seg = ((0U == (IData)(vlSelf->in)) ? 3U
                    : ((1U == (IData)(vlSelf->in)) ? 0x9fU
                        : ((2U == (IData)(vlSelf->in))
                            ? 0x25U : ((3U == (IData)(vlSelf->in))
                                        ? 0xdU : ((4U 
                                                   == (IData)(vlSelf->in))
                                                   ? 0x99U
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlSelf->in))
                                                    ? 0x49U
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlSelf->in))
                                                     ? 0x41U
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlSelf->in))
                                                      ? 0x1fU
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlSelf->in))
                                                       ? 1U
                                                       : 
                                                      ((9U 
                                                        == (IData)(vlSelf->in))
                                                        ? 9U
                                                        : 0xffU))))))))));
}

void VCombinational_top___024root___eval_ico(VCombinational_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCombinational_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCombinational_top___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VCombinational_top___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VCombinational_top___024root___eval_act(VCombinational_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCombinational_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCombinational_top___024root___eval_act\n"); );
}

void VCombinational_top___024root___eval_nba(VCombinational_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCombinational_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCombinational_top___024root___eval_nba\n"); );
}

void VCombinational_top___024root___eval_triggers__ico(VCombinational_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VCombinational_top___024root___dump_triggers__ico(VCombinational_top___024root* vlSelf);
#endif  // VL_DEBUG
void VCombinational_top___024root___eval_triggers__act(VCombinational_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VCombinational_top___024root___dump_triggers__act(VCombinational_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VCombinational_top___024root___dump_triggers__nba(VCombinational_top___024root* vlSelf);
#endif  // VL_DEBUG

void VCombinational_top___024root___eval(VCombinational_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCombinational_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCombinational_top___024root___eval\n"); );
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
        VCombinational_top___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VCombinational_top___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/ex7.4/verilog/vsrc/Combinational_top.v", 4, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VCombinational_top___024root___eval_ico(vlSelf);
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
            VCombinational_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VCombinational_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/ex7.4/verilog/vsrc/Combinational_top.v", 4, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VCombinational_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VCombinational_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/ex7.4/verilog/vsrc/Combinational_top.v", 4, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VCombinational_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VCombinational_top___024root___eval_debug_assertions(VCombinational_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCombinational_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCombinational_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->res & 0xfeU))) {
        Verilated::overWidthError("res");}
    if (VL_UNLIKELY((vlSelf->in & 0xf0U))) {
        Verilated::overWidthError("in");}
}
#endif  // VL_DEBUG
