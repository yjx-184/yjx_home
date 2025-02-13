// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"

#include "VTop___024root.h"

void VTop___024root___eval_act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_act\n"); );
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->reset) {
        vlSelf->Top__DOT__shiftreg__DOT__shiftreg = 0xffU;
    } else if (vlSelf->io_reset) {
        vlSelf->Top__DOT__shiftreg__DOT__shiftreg = 0xffU;
    } else if (vlSelf->io_clk) {
        vlSelf->Top__DOT__shiftreg__DOT__shiftreg = vlSelf->Top__DOT__shiftreg__DOT___shiftreg_T_1;
    }
    vlSelf->io_seg_out = ((0U == (0xfU & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                           ? 3U : ((1U == (0xfU & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                    ? 0x9fU : ((2U 
                                                == 
                                                (0xfU 
                                                 & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                ? 0x25U
                                                : (
                                                   (3U 
                                                    == 
                                                    (0xfU 
                                                     & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                    ? 0xdU
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (0xfU 
                                                      & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                     ? 0x99U
                                                     : 
                                                    ((5U 
                                                      == 
                                                      (0xfU 
                                                       & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                      ? 0x49U
                                                      : 
                                                     ((6U 
                                                       == 
                                                       (0xfU 
                                                        & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                       ? 0x41U
                                                       : 
                                                      ((7U 
                                                        == 
                                                        (0xfU 
                                                         & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                        ? 0x1fU
                                                        : 
                                                       ((8U 
                                                         == 
                                                         (0xfU 
                                                          & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                         ? 1U
                                                         : 
                                                        ((9U 
                                                          == 
                                                          (0xfU 
                                                           & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                          ? 9U
                                                          : 
                                                         ((0xaU 
                                                           == 
                                                           (0xfU 
                                                            & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                           ? 0x11U
                                                           : 
                                                          ((0xbU 
                                                            == 
                                                            (0xfU 
                                                             & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                            ? 0xc1U
                                                            : 
                                                           ((0xcU 
                                                             == 
                                                             (0xfU 
                                                              & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                             ? 0x63U
                                                             : 
                                                            ((0xdU 
                                                              == 
                                                              (0xfU 
                                                               & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                              ? 0x85U
                                                              : 
                                                             ((0xeU 
                                                               == 
                                                               (0xfU 
                                                                & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                               ? 0x61U
                                                               : 
                                                              ((0xfU 
                                                                == 
                                                                (0xfU 
                                                                 & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg)))
                                                                ? 0x71U
                                                                : 0U))))))))))))))));
    vlSelf->Top__DOT__shiftreg__DOT___shiftreg_T_1 
        = ((0x80U & (VL_REDXOR_8((0x1dU & (IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg))) 
                     << 7U)) | (0x7fU & ((IData)(vlSelf->Top__DOT__shiftreg__DOT__shiftreg) 
                                         >> 1U)));
}

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VTop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VTop___024root___eval_triggers__act(VTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf);
#endif  // VL_DEBUG

void VTop___024root___eval(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval\n"); );
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
            VTop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VTop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex6ShiftReg/verilog/vsrc/Top.v", 91, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VTop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex6ShiftReg/verilog/vsrc/Top.v", 91, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VTop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VTop___024root___eval_debug_assertions(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_clk & 0xfeU))) {
        Verilated::overWidthError("io_clk");}
    if (VL_UNLIKELY((vlSelf->io_reset & 0xfeU))) {
        Verilated::overWidthError("io_reset");}
}
#endif  // VL_DEBUG
