// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSeg.h for the primary calling header

#include "verilated.h"

#include "VSeg___024root.h"

VL_INLINE_OPT void VSeg___024root___ico_sequent__TOP__0(VSeg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSeg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSeg___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->io_valid = (0U != (IData)(vlSelf->io_in));
    vlSelf->io_out = ((0x80U & (IData)(vlSelf->io_in))
                       ? 7U : ((0x40U & (IData)(vlSelf->io_in))
                                ? 6U : ((0x20U & (IData)(vlSelf->io_in))
                                         ? 5U : ((0x10U 
                                                  & (IData)(vlSelf->io_in))
                                                  ? 4U
                                                  : 
                                                 ((8U 
                                                   & (IData)(vlSelf->io_in))
                                                   ? 3U
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlSelf->io_in))
                                                    ? 2U
                                                    : 
                                                   (1U 
                                                    & ((IData)(vlSelf->io_in) 
                                                       >> 1U))))))));
    vlSelf->io_seg = ((IData)(vlSelf->io_sel) ? ((0U 
                                                  == (IData)(vlSelf->io_out))
                                                  ? 1U
                                                  : 
                                                 ((1U 
                                                   == (IData)(vlSelf->io_out))
                                                   ? 0x4fU
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlSelf->io_out))
                                                    ? 0x12U
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlSelf->io_out))
                                                     ? 6U
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlSelf->io_out))
                                                      ? 0x4cU
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlSelf->io_out))
                                                       ? 0x24U
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlSelf->io_out))
                                                        ? 0x20U
                                                        : 
                                                       ((7U 
                                                         == (IData)(vlSelf->io_out))
                                                         ? 0xfU
                                                         : 0U))))))))
                       : 0U);
}

void VSeg___024root___eval_ico(VSeg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSeg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSeg___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VSeg___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VSeg___024root___eval_act(VSeg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSeg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSeg___024root___eval_act\n"); );
}

void VSeg___024root___eval_nba(VSeg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSeg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSeg___024root___eval_nba\n"); );
}

void VSeg___024root___eval_triggers__ico(VSeg___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VSeg___024root___dump_triggers__ico(VSeg___024root* vlSelf);
#endif  // VL_DEBUG
void VSeg___024root___eval_triggers__act(VSeg___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VSeg___024root___dump_triggers__act(VSeg___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VSeg___024root___dump_triggers__nba(VSeg___024root* vlSelf);
#endif  // VL_DEBUG

void VSeg___024root___eval(VSeg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSeg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSeg___024root___eval\n"); );
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
        VSeg___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VSeg___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex2Decoders_Encoders/verilog/vsrc/Seg.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VSeg___024root___eval_ico(vlSelf);
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
            VSeg___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VSeg___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex2Decoders_Encoders/verilog/vsrc/Seg.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VSeg___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VSeg___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex2Decoders_Encoders/verilog/vsrc/Seg.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VSeg___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VSeg___024root___eval_debug_assertions(VSeg___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VSeg__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSeg___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->io_sel & 0xfeU))) {
        Verilated::overWidthError("io_sel");}
}
#endif  // VL_DEBUG
