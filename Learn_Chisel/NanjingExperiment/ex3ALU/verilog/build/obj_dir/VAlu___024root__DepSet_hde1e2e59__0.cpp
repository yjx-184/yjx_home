// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAlu.h for the primary calling header

#include "verilated.h"

#include "VAlu___024root.h"

VL_INLINE_OPT void VAlu___024root___ico_sequent__TOP__0(VAlu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAlu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ Alu__DOT__sum;
    Alu__DOT__sum = 0;
    CData/*4:0*/ Alu__DOT__diff;
    Alu__DOT__diff = 0;
    CData/*1:0*/ Alu__DOT___GEN_1;
    Alu__DOT___GEN_1 = 0;
    CData/*0:0*/ Alu__DOT___overflow_T_5;
    Alu__DOT___overflow_T_5 = 0;
    // Body
    Alu__DOT___GEN_1 = ((6U == (IData)(vlSelf->io_op))
                         ? (VL_LTS_III(4, (IData)(vlSelf->io_a), (IData)(vlSelf->io_b))
                             ? 1U : 0U) : ((7U == (IData)(vlSelf->io_op))
                                            ? (((IData)(vlSelf->io_a) 
                                                == (IData)(vlSelf->io_b))
                                                ? 1U
                                                : 0U)
                                            : 0U));
    Alu__DOT__sum = (0x1fU & (VL_EXTENDS_II(5,4, (IData)(vlSelf->io_a)) 
                              + VL_EXTENDS_II(5,4, (IData)(vlSelf->io_b))));
    Alu__DOT__diff = (0x1fU & (VL_EXTENDS_II(5,4, (IData)(vlSelf->io_a)) 
                               - VL_EXTENDS_II(5,4, (IData)(vlSelf->io_b))));
    if ((0U == (IData)(vlSelf->io_op))) {
        vlSelf->io_carry = (1U & ((IData)(Alu__DOT__sum) 
                                  >> 4U));
        vlSelf->io_result = (0xfU & (IData)(Alu__DOT__sum));
    } else {
        vlSelf->io_carry = (1U & ((1U == (IData)(vlSelf->io_op)) 
                                  & ((IData)(Alu__DOT__diff) 
                                     >> 4U)));
        vlSelf->io_result = (0xfU & ((1U == (IData)(vlSelf->io_op))
                                      ? (IData)(Alu__DOT__diff)
                                      : ((2U == (IData)(vlSelf->io_op))
                                          ? (~ (IData)(vlSelf->io_a))
                                          : ((3U == (IData)(vlSelf->io_op))
                                              ? ((IData)(vlSelf->io_a) 
                                                 & (IData)(vlSelf->io_b))
                                              : ((4U 
                                                  == (IData)(vlSelf->io_op))
                                                  ? 
                                                 ((IData)(vlSelf->io_a) 
                                                  | (IData)(vlSelf->io_b))
                                                  : 
                                                 ((5U 
                                                   == (IData)(vlSelf->io_op))
                                                   ? 
                                                  ((IData)(vlSelf->io_a) 
                                                   ^ (IData)(vlSelf->io_b))
                                                   : 
                                                  ((0xcU 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & ((IData)(Alu__DOT___GEN_1) 
                                                                      >> 1U)))) 
                                                       << 2U)) 
                                                   | (IData)(Alu__DOT___GEN_1))))))));
    }
    vlSelf->io_zero = (0U == (IData)(vlSelf->io_result));
    Alu__DOT___overflow_T_5 = ((1U & ((IData)(vlSelf->io_a) 
                                      >> 3U)) != (1U 
                                                  & ((IData)(vlSelf->io_result) 
                                                     >> 3U)));
    vlSelf->io_overflow = ((0U == (IData)(vlSelf->io_op))
                            ? (((1U & ((IData)(vlSelf->io_a) 
                                       >> 3U)) == (1U 
                                                   & ((IData)(vlSelf->io_b) 
                                                      >> 3U))) 
                               & (IData)(Alu__DOT___overflow_T_5))
                            : ((1U == (IData)(vlSelf->io_op)) 
                               & (((1U & ((IData)(vlSelf->io_a) 
                                          >> 3U)) != 
                                   (1U & ((IData)(vlSelf->io_b) 
                                          >> 3U))) 
                                  & (IData)(Alu__DOT___overflow_T_5))));
}

void VAlu___024root___eval_ico(VAlu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAlu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VAlu___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VAlu___024root___eval_act(VAlu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAlu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu___024root___eval_act\n"); );
}

void VAlu___024root___eval_nba(VAlu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAlu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu___024root___eval_nba\n"); );
}

void VAlu___024root___eval_triggers__ico(VAlu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VAlu___024root___dump_triggers__ico(VAlu___024root* vlSelf);
#endif  // VL_DEBUG
void VAlu___024root___eval_triggers__act(VAlu___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VAlu___024root___dump_triggers__act(VAlu___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VAlu___024root___dump_triggers__nba(VAlu___024root* vlSelf);
#endif  // VL_DEBUG

void VAlu___024root___eval(VAlu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAlu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu___024root___eval\n"); );
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
        VAlu___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VAlu___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex3ALU/verilog/vsrc/Alu.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VAlu___024root___eval_ico(vlSelf);
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
            VAlu___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VAlu___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex3ALU/verilog/vsrc/Alu.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VAlu___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VAlu___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex3ALU/verilog/vsrc/Alu.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VAlu___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VAlu___024root___eval_debug_assertions(VAlu___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VAlu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_op & 0xf8U))) {
        Verilated::overWidthError("io_op");}
    if (VL_UNLIKELY((vlSelf->io_a & 0xf0U))) {
        Verilated::overWidthError("io_a");}
    if (VL_UNLIKELY((vlSelf->io_b & 0xf0U))) {
        Verilated::overWidthError("io_b");}
}
#endif  // VL_DEBUG
