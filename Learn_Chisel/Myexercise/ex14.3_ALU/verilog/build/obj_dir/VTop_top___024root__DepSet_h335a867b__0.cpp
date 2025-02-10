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
    if ((0x270fU == (IData)(vlSelf->Top_top__DOT__uut__DOT__tick_reg))) {
        vlSelf->Top_top__DOT__uut__DOT__btnDeb = vlSelf->Top_top__DOT__uut__DOT__btnsync;
    }
    vlSelf->Top_top__DOT__uut__DOT__btnsync = vlSelf->Top_top__DOT__uut__DOT__btnsync_REG;
    if (vlSelf->res) {
        vlSelf->Top_top__DOT__uut__DOT__counter = 0U;
    } else if ((1U & ((~ (IData)(vlSelf->Top_top__DOT__uut__DOT__risingEdge_REG)) 
                      & ((((IData)(vlSelf->Top_top__DOT__uut__DOT__btnClean_reg) 
                           >> 2U) & (IData)(vlSelf->Top_top__DOT__uut__DOT__btnClean_reg)) 
                         | ((IData)((6U == (6U & (IData)(vlSelf->Top_top__DOT__uut__DOT__btnClean_reg)))) 
                            | (((IData)(vlSelf->Top_top__DOT__uut__DOT__btnClean_reg) 
                                >> 1U) & (IData)(vlSelf->Top_top__DOT__uut__DOT__btnClean_reg))))))) {
        vlSelf->Top_top__DOT__uut__DOT__counter = vlSelf->Top_top__DOT__uut__DOT___counter_T_1;
    }
    vlSelf->led = vlSelf->Top_top__DOT__uut__DOT__counter;
    vlSelf->Top_top__DOT__uut__DOT___counter_T_1 = 
        (0xffU & ((IData)(1U) + (IData)(vlSelf->Top_top__DOT__uut__DOT__counter)));
    vlSelf->Top_top__DOT__uut__DOT__risingEdge_REG 
        = (1U & (((((IData)(vlSelf->Top_top__DOT__uut__DOT__btnClean_reg) 
                    >> 2U) & (IData)(vlSelf->Top_top__DOT__uut__DOT__btnClean_reg)) 
                  | (IData)((6U == (6U & (IData)(vlSelf->Top_top__DOT__uut__DOT__btnClean_reg))))) 
                 | (((IData)(vlSelf->Top_top__DOT__uut__DOT__btnClean_reg) 
                     >> 1U) & (IData)(vlSelf->Top_top__DOT__uut__DOT__btnClean_reg))));
    if (vlSelf->res) {
        vlSelf->Top_top__DOT__uut__DOT__btnClean_reg = 0U;
        vlSelf->Top_top__DOT__uut__DOT__tick_reg = 0U;
    } else {
        if ((0x270fU == (IData)(vlSelf->Top_top__DOT__uut__DOT__tick_reg))) {
            vlSelf->Top_top__DOT__uut__DOT__btnClean_reg 
                = vlSelf->Top_top__DOT__uut__DOT___btnClean_reg_T_1;
        }
        vlSelf->Top_top__DOT__uut__DOT__tick_reg = 
            ((IData)(vlSelf->Top_top__DOT__uut__DOT__tick)
              ? 0U : (IData)(vlSelf->Top_top__DOT__uut__DOT___tick_reg_T_1));
    }
    vlSelf->Top_top__DOT__uut__DOT__btnsync_REG = vlSelf->btn;
    vlSelf->Top_top__DOT__uut__DOT___btnClean_reg_T_1 
        = ((6U & ((IData)(vlSelf->Top_top__DOT__uut__DOT__btnClean_reg) 
                  << 1U)) | (IData)(vlSelf->Top_top__DOT__uut__DOT__btnDeb));
    vlSelf->Top_top__DOT__uut__DOT__tick = (0x270fU 
                                            == (IData)(vlSelf->Top_top__DOT__uut__DOT__tick_reg));
    vlSelf->Top_top__DOT__uut__DOT___tick_reg_T_1 = 
        (0x3fffU & ((IData)(1U) + (IData)(vlSelf->Top_top__DOT__uut__DOT__tick_reg)));
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
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/Myexercise/ex9.5/verilog/vsrc/Top_top.v", 4, "", "Active region did not converge.");
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
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/Myexercise/ex9.5/verilog/vsrc/Top_top.v", 4, "", "NBA region did not converge.");
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
    if (VL_UNLIKELY((vlSelf->btn & 0xfeU))) {
        Verilated::overWidthError("btn");}
}
#endif  // VL_DEBUG
