// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"

#include "VTop___024root.h"

VL_ATTR_COLD void VTop___024root___eval_static(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_static\n"); );
}

VL_ATTR_COLD void VTop___024root___eval_initial(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clock = vlSelf->clock;
}

VL_ATTR_COLD void VTop___024root___eval_final(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_final\n"); );
}

VL_ATTR_COLD void VTop___024root___eval_triggers__stl(VTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf);

VL_ATTR_COLD void VTop___024root___eval_settle(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        VTop___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex6ShiftReg/verilog/vsrc/Top.v", 91, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            VTop___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___stl_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___stl_sequent__TOP__0\n"); );
    // Body
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

VL_ATTR_COLD void VTop___024root___eval_stl(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        VTop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VTop___024root___ctor_var_reset(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = 0;
    vlSelf->reset = 0;
    vlSelf->io_clk = 0;
    vlSelf->io_reset = 0;
    vlSelf->io_seg_out = 0;
    vlSelf->Top__DOT__shiftreg__DOT__shiftreg = 0;
    vlSelf->Top__DOT__shiftreg__DOT___shiftreg_T_1 = 0;
    vlSelf->__Vtrigrprev__TOP__clock = 0;
}
