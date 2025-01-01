// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop_top.h for the primary calling header

#include "verilated.h"

#include "VTop_top___024root.h"

VL_ATTR_COLD void VTop_top___024root___eval_static(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void VTop_top___024root___eval_initial(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void VTop_top___024root___eval_final(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void VTop_top___024root___eval_triggers__stl(VTop_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop_top___024root___dump_triggers__stl(VTop_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VTop_top___024root___eval_stl(VTop_top___024root* vlSelf);

VL_ATTR_COLD void VTop_top___024root___eval_settle(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VTop_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VTop_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/Myexercise/ex8.5/verilog/vsrc/Top_top.v", 4, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VTop_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop_top___024root___dump_triggers__stl(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop_top___024root___stl_sequent__TOP__0(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___stl_sequent__TOP__0\n"); );
    // Body
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

VL_ATTR_COLD void VTop_top___024root___eval_stl(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        VTop_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop_top___024root___dump_triggers__act(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void VTop_top___024root___dump_triggers__nba(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop_top___024root___ctor_var_reset(VTop_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->res = 0;
    vlSelf->seg = 0;
    vlSelf->Top_top__DOT__uut__DOT__counter4 = 0;
    vlSelf->Top_top__DOT__uut__DOT__secCounter = 0;
    vlSelf->Top_top__DOT__uut__DOT__tick = 0;
    vlSelf->Top_top__DOT__uut__DOT___secCounter_T_1 = 0;
    vlSelf->Top_top__DOT__uut__DOT___counter4_T_1 = 0;
    vlSelf->__Vtrigrprev__TOP__clk = 0;
}
