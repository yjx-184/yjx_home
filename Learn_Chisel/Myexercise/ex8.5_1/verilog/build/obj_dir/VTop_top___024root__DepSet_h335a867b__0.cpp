// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop_top.h for the primary calling header

#include "verilated.h"

#include "VTop_top___024root.h"

void VTop_top___024root___eval_act(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void VTop_top___024root___nba_sequent__TOP__0(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___nba_sequent__TOP__0\n"); );
    // Body
    if (vlSelf->res) {
        vlSelf->Top_top__DOT__uut__DOT__counter4 = 0U;
        vlSelf->Top_top__DOT__uut__DOT__secCounter = 0U;
    } else {
        if ((0x2faf07fU == vlSelf->Top_top__DOT__uut__DOT__secCounter)) {
            vlSelf->Top_top__DOT__uut__DOT__counter4 
                = vlSelf->Top_top__DOT__uut__DOT___counter4_T_1;
        }
        vlSelf->Top_top__DOT__uut__DOT__secCounter 
            = ((IData)(vlSelf->Top_top__DOT__uut__DOT__tick)
                ? 0U : vlSelf->Top_top__DOT__uut__DOT___secCounter_T_1);
    }
    vlSelf->seg = ((0U == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                    ? 3U : ((1U == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                             ? 0x9fU : ((2U == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                         ? 0x25U : 
                                        ((3U == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                          ? 0xdU : 
                                         ((4U == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                           ? 0x99U : 
                                          ((5U == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                            ? 0x49U
                                            : ((6U 
                                                == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                                ? 0x41U
                                                : (
                                                   (7U 
                                                    == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                                    ? 0x1fU
                                                    : 
                                                   ((8U 
                                                     == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                                     ? 1U
                                                     : 
                                                    ((9U 
                                                      == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                                      ? 9U
                                                      : 
                                                     ((0xaU 
                                                       == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                                       ? 0x11U
                                                       : 
                                                      ((0xbU 
                                                        == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                                        ? 0xc1U
                                                        : 
                                                       ((0xcU 
                                                         == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                                         ? 0x63U
                                                         : 
                                                        ((0xdU 
                                                          == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                                          ? 0x85U
                                                          : 
                                                         ((0xeU 
                                                           == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                                           ? 0x61U
                                                           : 
                                                          ((0xfU 
                                                            == (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4))
                                                            ? 0x71U
                                                            : 0xffU))))))))))))))));
    vlSelf->Top_top__DOT__uut__DOT___counter4_T_1 = 
        (0xfU & ((IData)(1U) + (IData)(vlSelf->Top_top__DOT__uut__DOT__counter4)));
    vlSelf->Top_top__DOT__uut__DOT__tick = (0x2faf07fU 
                                            == vlSelf->Top_top__DOT__uut__DOT__secCounter);
    vlSelf->Top_top__DOT__uut__DOT___secCounter_T_1 
        = (0x7ffffffU & ((IData)(1U) + vlSelf->Top_top__DOT__uut__DOT__secCounter));
}

void VTop_top___024root___eval_nba(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VTop_top___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VTop_top___024root___eval_triggers__act(VTop_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop_top___024root___dump_triggers__act(VTop_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop_top___024root___dump_triggers__nba(VTop_top___024root* vlSelf);
#endif  // VL_DEBUG

void VTop_top___024root___eval(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___eval\n"); );
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
            VTop_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VTop_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/Myexercise/ex8.5/verilog/vsrc/Top_top.v", 4, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                VTop_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                VTop_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/Myexercise/ex8.5/verilog/vsrc/Top_top.v", 4, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            VTop_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void VTop_top___024root___eval_debug_assertions(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->res & 0xfeU))) {
        Verilated::overWidthError("res");}
}
#endif  // VL_DEBUG
