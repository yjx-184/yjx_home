// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMux4to1.h for the primary calling header

#include "verilated.h"

#include "VMux4to1___024root.h"

VL_INLINE_OPT void VMux4to1___024root___ico_sequent__TOP__0(VMux4to1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMux4to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux4to1___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->io_F = ((0U == (IData)(vlSelf->io_Y)) ? (IData)(vlSelf->io_X0)
                     : ((1U == (IData)(vlSelf->io_Y))
                         ? (IData)(vlSelf->io_X1) : 
                        ((2U == (IData)(vlSelf->io_Y))
                          ? (IData)(vlSelf->io_X2) : 
                         ((3U == (IData)(vlSelf->io_Y))
                           ? (IData)(vlSelf->io_X3)
                           : 0U))));
}

void VMux4to1___024root___eval_ico(VMux4to1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMux4to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux4to1___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VMux4to1___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VMux4to1___024root___eval_act(VMux4to1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMux4to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux4to1___024root___eval_act\n"); );
}

void VMux4to1___024root___eval_nba(VMux4to1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMux4to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux4to1___024root___eval_nba\n"); );
}

void VMux4to1___024root___eval_triggers__ico(VMux4to1___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VMux4to1___024root___dump_triggers__ico(VMux4to1___024root* vlSelf);
#endif  // VL_DEBUG
void VMux4to1___024root___eval_triggers__act(VMux4to1___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VMux4to1___024root___dump_triggers__act(VMux4to1___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VMux4to1___024root___dump_triggers__nba(VMux4to1___024root* vlSelf);
#endif  // VL_DEBUG

void VMux4to1___024root___eval(VMux4to1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMux4to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux4to1___024root___eval\n"); );
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
        VMux4to1___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VMux4to1___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex1Mux/verilog/vsrc/Mux4to1.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VMux4to1___024root___eval_ico(vlSelf);
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
            VMux4to1___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VMux4to1___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex1Mux/verilog/vsrc/Mux4to1.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VMux4to1___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VMux4to1___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex1Mux/verilog/vsrc/Mux4to1.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VMux4to1___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VMux4to1___024root___eval_debug_assertions(VMux4to1___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMux4to1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux4to1___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_X0 & 0xfcU))) {
        Verilated::overWidthError("io_X0");}
    if (VL_UNLIKELY((vlSelf->io_X1 & 0xfcU))) {
        Verilated::overWidthError("io_X1");}
    if (VL_UNLIKELY((vlSelf->io_X2 & 0xfcU))) {
        Verilated::overWidthError("io_X2");}
    if (VL_UNLIKELY((vlSelf->io_X3 & 0xfcU))) {
        Verilated::overWidthError("io_X3");}
    if (VL_UNLIKELY((vlSelf->io_Y & 0xfcU))) {
        Verilated::overWidthError("io_Y");}
}
#endif  // VL_DEBUG
