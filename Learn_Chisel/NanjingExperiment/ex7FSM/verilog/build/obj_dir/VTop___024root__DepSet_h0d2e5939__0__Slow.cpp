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
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex7FSM2/verilog/vsrc/Top.v", 542, "", "Settle region did not converge.");
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
    // Init
    CData/*3:0*/ Top__DOT__seg0_io_in;
    Top__DOT__seg0_io_in = 0;
    CData/*3:0*/ Top__DOT__seg1_io_in;
    Top__DOT__seg1_io_in = 0;
    CData/*3:0*/ Top__DOT__seg2_io_in;
    Top__DOT__seg2_io_in = 0;
    CData/*3:0*/ Top__DOT__seg3_io_in;
    Top__DOT__seg3_io_in = 0;
    // Body
    vlSelf->Top__DOT__keyboard__DOT___r_ptr_T_2 = (7U 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->Top__DOT__keyboard__DOT__r_ptr)));
    vlSelf->Top__DOT__keyboard__DOT___count_T_1 = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->Top__DOT__keyboard__DOT__count)));
    vlSelf->Top__DOT__keyboard__DOT__sampling = (IData)(
                                                        (4U 
                                                         == 
                                                         (6U 
                                                          & (IData)(vlSelf->Top__DOT__keyboard__DOT__ps2_clk_sync))));
    vlSelf->io_seg_out_4 = ((0U == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                             ? 3U : ((1U == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                      ? 0x9fU : ((2U 
                                                  == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                  ? 0x25U
                                                  : 
                                                 ((3U 
                                                   == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                   ? 0xdU
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                    ? 0x99U
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                     ? 0x49U
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                      ? 0x41U
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                       ? 0x1fU
                                                       : 
                                                      ((8U 
                                                        == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                        ? 1U
                                                        : 
                                                       ((9U 
                                                         == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                         ? 9U
                                                         : 
                                                        ((0xaU 
                                                          == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                          ? 0x11U
                                                          : 
                                                         ((0xbU 
                                                           == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                           ? 0xc1U
                                                           : 
                                                          ((0xcU 
                                                            == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                            ? 0x63U
                                                            : 
                                                           ((0xdU 
                                                             == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                             ? 0x85U
                                                             : 
                                                            ((0xeU 
                                                              == (IData)(vlSelf->Top__DOT__counter__DOT__ones))
                                                              ? 0x61U
                                                              : 0xffU)))))))))))))));
    vlSelf->Top__DOT__counter__DOT___ones_T_1 = (0xfU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->Top__DOT__counter__DOT__ones)));
    vlSelf->io_seg_out_5 = ((0U == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                             ? 3U : ((1U == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                      ? 0x9fU : ((2U 
                                                  == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                  ? 0x25U
                                                  : 
                                                 ((3U 
                                                   == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                   ? 0xdU
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                    ? 0x99U
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                     ? 0x49U
                                                     : 
                                                    ((6U 
                                                      == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                      ? 0x41U
                                                      : 
                                                     ((7U 
                                                       == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                       ? 0x1fU
                                                       : 
                                                      ((8U 
                                                        == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                        ? 1U
                                                        : 
                                                       ((9U 
                                                         == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                         ? 9U
                                                         : 
                                                        ((0xaU 
                                                          == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                          ? 0x11U
                                                          : 
                                                         ((0xbU 
                                                           == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                           ? 0xc1U
                                                           : 
                                                          ((0xcU 
                                                            == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                            ? 0x63U
                                                            : 
                                                           ((0xdU 
                                                             == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                             ? 0x85U
                                                             : 
                                                            ((0xeU 
                                                              == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                              ? 0x61U
                                                              : 0xffU)))))))))))))));
    vlSelf->Top__DOT__counter__DOT___tens_T_3 = ((9U 
                                                  == (IData)(vlSelf->Top__DOT__counter__DOT__tens))
                                                  ? 0U
                                                  : 
                                                 (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->Top__DOT__counter__DOT__tens))));
    vlSelf->Top__DOT__counter__DOT___debounce_count_T_1 
        = (7U & ((IData)(1U) + (IData)(vlSelf->Top__DOT__counter__DOT__debounce_count)));
    vlSelf->Top__DOT__keyboard__DOT___ps2_clk_sync_T_1 
        = ((6U & ((IData)(vlSelf->Top__DOT__keyboard__DOT__ps2_clk_sync) 
                  << 1U)) | (IData)(vlSelf->io_ps2_clk));
    vlSelf->Top__DOT__counter__DOT__stable_key_rise 
        = ((~ (IData)(vlSelf->Top__DOT__counter__DOT__stable_key_rise_REG)) 
           & (IData)(vlSelf->Top__DOT__counter__DOT__stable_key_press));
    vlSelf->Top__DOT__keyboard__DOT___buffer_T = ((0x200U 
                                                   & (((9U 
                                                        == (IData)(vlSelf->Top__DOT__keyboard__DOT__count))
                                                        ? (IData)(vlSelf->io_ps2_data)
                                                        : 
                                                       ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                                                        >> 9U)) 
                                                      << 9U)) 
                                                  | ((0x100U 
                                                      & (((8U 
                                                           == (IData)(vlSelf->Top__DOT__keyboard__DOT__count))
                                                           ? (IData)(vlSelf->io_ps2_data)
                                                           : 
                                                          ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                                                           >> 8U)) 
                                                         << 8U)) 
                                                     | ((0x80U 
                                                         & (((7U 
                                                              == (IData)(vlSelf->Top__DOT__keyboard__DOT__count))
                                                              ? (IData)(vlSelf->io_ps2_data)
                                                              : 
                                                             ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                                                              >> 7U)) 
                                                            << 7U)) 
                                                        | ((0x40U 
                                                            & (((6U 
                                                                 == (IData)(vlSelf->Top__DOT__keyboard__DOT__count))
                                                                 ? (IData)(vlSelf->io_ps2_data)
                                                                 : 
                                                                ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                                                                 >> 6U)) 
                                                               << 6U)) 
                                                           | ((0x20U 
                                                               & (((5U 
                                                                    == (IData)(vlSelf->Top__DOT__keyboard__DOT__count))
                                                                    ? (IData)(vlSelf->io_ps2_data)
                                                                    : 
                                                                   ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                                                                    >> 5U)) 
                                                                  << 5U)) 
                                                              | ((0x10U 
                                                                  & (((4U 
                                                                       == (IData)(vlSelf->Top__DOT__keyboard__DOT__count))
                                                                       ? (IData)(vlSelf->io_ps2_data)
                                                                       : 
                                                                      ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                                                                       >> 4U)) 
                                                                     << 4U)) 
                                                                 | ((8U 
                                                                     & (((3U 
                                                                          == (IData)(vlSelf->Top__DOT__keyboard__DOT__count))
                                                                          ? (IData)(vlSelf->io_ps2_data)
                                                                          : 
                                                                         ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                                                                          >> 3U)) 
                                                                        << 3U)) 
                                                                    | ((4U 
                                                                        & (((2U 
                                                                             == (IData)(vlSelf->Top__DOT__keyboard__DOT__count))
                                                                             ? (IData)(vlSelf->io_ps2_data)
                                                                             : 
                                                                            ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                                                                             >> 2U)) 
                                                                           << 2U)) 
                                                                       | ((2U 
                                                                           & (((1U 
                                                                                == (IData)(vlSelf->Top__DOT__keyboard__DOT__count))
                                                                                ? (IData)(vlSelf->io_ps2_data)
                                                                                : 
                                                                               ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                                                                                >> 1U)) 
                                                                              << 1U)) 
                                                                          | (1U 
                                                                             & ((0U 
                                                                                == (IData)(vlSelf->Top__DOT__keyboard__DOT__count))
                                                                                 ? (IData)(vlSelf->io_ps2_data)
                                                                                 : (IData)(vlSelf->Top__DOT__keyboard__DOT__buffer))))))))))));
    vlSelf->Top__DOT__keyboard__DOT___GEN_1 = (((~ (IData)(vlSelf->Top__DOT__nextdata_n)) 
                                                & (IData)(vlSelf->Top__DOT__keyboard__DOT__ready))
                                                ? ((IData)(vlSelf->Top__DOT__keyboard__DOT__w_ptr) 
                                                   != 
                                                   ((7U 
                                                     == (IData)(vlSelf->Top__DOT__keyboard__DOT__r_ptr))
                                                     ? 0U
                                                     : 
                                                    (7U 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelf->Top__DOT__keyboard__DOT__r_ptr)))))
                                                : (IData)(vlSelf->Top__DOT__keyboard__DOT__ready));
    vlSelf->Top__DOT__keyboard__DOT__valid = ((~ (IData)(vlSelf->Top__DOT__keyboard__DOT__buffer)) 
                                              & ((IData)(vlSelf->io_ps2_data) 
                                                 & VL_REDXOR_32(
                                                                (0x1ffU 
                                                                 & ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                                                                    >> 1U)))));
    vlSelf->Top__DOT__keyboard_io_data = ((7U == (IData)(vlSelf->Top__DOT__keyboard__DOT__r_ptr))
                                           ? (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_7)
                                           : ((6U == (IData)(vlSelf->Top__DOT__keyboard__DOT__r_ptr))
                                               ? (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_6)
                                               : ((5U 
                                                   == (IData)(vlSelf->Top__DOT__keyboard__DOT__r_ptr))
                                                   ? (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_5)
                                                   : 
                                                  ((4U 
                                                    == (IData)(vlSelf->Top__DOT__keyboard__DOT__r_ptr))
                                                    ? (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_4)
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlSelf->Top__DOT__keyboard__DOT__r_ptr))
                                                     ? (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_3)
                                                     : 
                                                    ((2U 
                                                      == (IData)(vlSelf->Top__DOT__keyboard__DOT__r_ptr))
                                                      ? (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_2)
                                                      : 
                                                     ((1U 
                                                       == (IData)(vlSelf->Top__DOT__keyboard__DOT__r_ptr))
                                                       ? (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_1)
                                                       : (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_0))))))));
    if (vlSelf->Top__DOT__keyboard__DOT__valid) {
        if ((7U == (IData)(vlSelf->Top__DOT__keyboard__DOT__w_ptr))) {
            vlSelf->Top__DOT__keyboard__DOT___GEN_19 
                = (7U & 0U);
            vlSelf->Top__DOT__keyboard__DOT___GEN_18 
                = (0xffU & ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                            >> 1U));
        } else {
            vlSelf->Top__DOT__keyboard__DOT___GEN_19 
                = (7U & ((IData)(1U) + (IData)(vlSelf->Top__DOT__keyboard__DOT__w_ptr)));
            vlSelf->Top__DOT__keyboard__DOT___GEN_18 
                = (0xffU & (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_7));
        }
        vlSelf->Top__DOT__keyboard__DOT___GEN_11 = 
            (0xffU & ((0U == (IData)(vlSelf->Top__DOT__keyboard__DOT__w_ptr))
                       ? ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                          >> 1U) : (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_0)));
        vlSelf->Top__DOT__keyboard__DOT___GEN_12 = 
            (0xffU & ((1U == (IData)(vlSelf->Top__DOT__keyboard__DOT__w_ptr))
                       ? ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                          >> 1U) : (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_1)));
        vlSelf->Top__DOT__keyboard__DOT___GEN_13 = 
            (0xffU & ((2U == (IData)(vlSelf->Top__DOT__keyboard__DOT__w_ptr))
                       ? ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                          >> 1U) : (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_2)));
        vlSelf->Top__DOT__keyboard__DOT___GEN_14 = 
            (0xffU & ((3U == (IData)(vlSelf->Top__DOT__keyboard__DOT__w_ptr))
                       ? ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                          >> 1U) : (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_3)));
        vlSelf->Top__DOT__keyboard__DOT___GEN_15 = 
            (0xffU & ((4U == (IData)(vlSelf->Top__DOT__keyboard__DOT__w_ptr))
                       ? ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                          >> 1U) : (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_4)));
        vlSelf->Top__DOT__keyboard__DOT___GEN_16 = 
            (0xffU & ((5U == (IData)(vlSelf->Top__DOT__keyboard__DOT__w_ptr))
                       ? ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                          >> 1U) : (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_5)));
        vlSelf->Top__DOT__keyboard__DOT___GEN_17 = 
            (0xffU & ((6U == (IData)(vlSelf->Top__DOT__keyboard__DOT__w_ptr))
                       ? ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                          >> 1U) : (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_6)));
    } else {
        vlSelf->Top__DOT__keyboard__DOT___GEN_19 = 
            (7U & (IData)(vlSelf->Top__DOT__keyboard__DOT__w_ptr));
        vlSelf->Top__DOT__keyboard__DOT___GEN_11 = 
            (0xffU & (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_0));
        vlSelf->Top__DOT__keyboard__DOT___GEN_12 = 
            (0xffU & (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_1));
        vlSelf->Top__DOT__keyboard__DOT___GEN_13 = 
            (0xffU & (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_2));
        vlSelf->Top__DOT__keyboard__DOT___GEN_14 = 
            (0xffU & (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_3));
        vlSelf->Top__DOT__keyboard__DOT___GEN_15 = 
            (0xffU & (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_4));
        vlSelf->Top__DOT__keyboard__DOT___GEN_16 = 
            (0xffU & (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_5));
        vlSelf->Top__DOT__keyboard__DOT___GEN_17 = 
            (0xffU & (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_6));
        vlSelf->Top__DOT__keyboard__DOT___GEN_18 = 
            (0xffU & (IData)(vlSelf->Top__DOT__keyboard__DOT__fifo_7));
    }
    vlSelf->Top__DOT__decoder_io_pressed = ((~ ((IData)(vlSelf->Top__DOT__decoder__DOT__isBreakCode) 
                                                | (0xf0U 
                                                   == (IData)(vlSelf->Top__DOT__keyboard_io_data)))) 
                                            & (IData)(vlSelf->io_clrn));
    if (vlSelf->Top__DOT__decoder_io_pressed) {
        Top__DOT__seg0_io_in = (0xfU & (IData)(vlSelf->Top__DOT__keyboard_io_data));
        Top__DOT__seg1_io_in = (0xfU & ((IData)(vlSelf->Top__DOT__keyboard_io_data) 
                                        >> 4U));
        if (vlSelf->io_clrn) {
            if ((0xf0U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 0U;
                Top__DOT__seg3_io_in = 0U;
            } else if (vlSelf->Top__DOT__decoder__DOT__isBreakCode) {
                Top__DOT__seg2_io_in = 0U;
                Top__DOT__seg3_io_in = 0U;
            } else if ((0x45U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 0U;
                Top__DOT__seg3_io_in = 3U;
            } else if ((0x16U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 1U;
                Top__DOT__seg3_io_in = 3U;
            } else if ((0x1eU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 2U;
                Top__DOT__seg3_io_in = 3U;
            } else if ((0x26U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 3U;
                Top__DOT__seg3_io_in = 3U;
            } else if ((0x25U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 4U;
                Top__DOT__seg3_io_in = 3U;
            } else if ((0x2eU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 5U;
                Top__DOT__seg3_io_in = 3U;
            } else if ((0x36U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 6U;
                Top__DOT__seg3_io_in = 3U;
            } else if ((0x3dU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 7U;
                Top__DOT__seg3_io_in = 3U;
            } else if ((0x3eU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 8U;
                Top__DOT__seg3_io_in = 3U;
            } else if ((0x46U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 9U;
                Top__DOT__seg3_io_in = 3U;
            } else if ((0x1cU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 1U;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x32U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 2U;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x21U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 3U;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x23U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 4U;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x24U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 5U;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x2bU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 6U;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x34U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 7U;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x33U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 8U;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x43U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 9U;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x3bU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 0xaU;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x42U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 0xbU;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x4bU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 0xcU;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x3aU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 0xdU;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x31U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 0xeU;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x44U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 0xfU;
                Top__DOT__seg3_io_in = 4U;
            } else if ((0x4dU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 0U;
                Top__DOT__seg3_io_in = 5U;
            } else if ((0x15U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 1U;
                Top__DOT__seg3_io_in = 5U;
            } else if ((0x2dU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 2U;
                Top__DOT__seg3_io_in = 5U;
            } else if ((0x1bU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 3U;
                Top__DOT__seg3_io_in = 5U;
            } else if ((0x2cU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 4U;
                Top__DOT__seg3_io_in = 5U;
            } else if ((0x3cU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 5U;
                Top__DOT__seg3_io_in = 5U;
            } else if ((0x2aU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 6U;
                Top__DOT__seg3_io_in = 5U;
            } else if ((0x1dU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 7U;
                Top__DOT__seg3_io_in = 5U;
            } else if ((0x1aU == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 8U;
                Top__DOT__seg3_io_in = 5U;
            } else if ((0x22U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 9U;
                Top__DOT__seg3_io_in = 5U;
            } else if ((0x14U == (IData)(vlSelf->Top__DOT__keyboard_io_data))) {
                Top__DOT__seg2_io_in = 0xaU;
                Top__DOT__seg3_io_in = 5U;
            } else {
                Top__DOT__seg2_io_in = 0U;
                Top__DOT__seg3_io_in = 0U;
            }
        } else {
            Top__DOT__seg2_io_in = 0U;
            Top__DOT__seg3_io_in = 0U;
        }
    } else {
        Top__DOT__seg0_io_in = 0xfU;
        Top__DOT__seg1_io_in = 0xfU;
        Top__DOT__seg2_io_in = 0xfU;
        Top__DOT__seg3_io_in = 0xfU;
    }
    vlSelf->io_seg_out_0 = ((0U == (IData)(Top__DOT__seg0_io_in))
                             ? 3U : ((1U == (IData)(Top__DOT__seg0_io_in))
                                      ? 0x9fU : ((2U 
                                                  == (IData)(Top__DOT__seg0_io_in))
                                                  ? 0x25U
                                                  : 
                                                 ((3U 
                                                   == (IData)(Top__DOT__seg0_io_in))
                                                   ? 0xdU
                                                   : 
                                                  ((4U 
                                                    == (IData)(Top__DOT__seg0_io_in))
                                                    ? 0x99U
                                                    : 
                                                   ((5U 
                                                     == (IData)(Top__DOT__seg0_io_in))
                                                     ? 0x49U
                                                     : 
                                                    ((6U 
                                                      == (IData)(Top__DOT__seg0_io_in))
                                                      ? 0x41U
                                                      : 
                                                     ((7U 
                                                       == (IData)(Top__DOT__seg0_io_in))
                                                       ? 0x1fU
                                                       : 
                                                      ((8U 
                                                        == (IData)(Top__DOT__seg0_io_in))
                                                        ? 1U
                                                        : 
                                                       ((9U 
                                                         == (IData)(Top__DOT__seg0_io_in))
                                                         ? 9U
                                                         : 
                                                        ((0xaU 
                                                          == (IData)(Top__DOT__seg0_io_in))
                                                          ? 0x11U
                                                          : 
                                                         ((0xbU 
                                                           == (IData)(Top__DOT__seg0_io_in))
                                                           ? 0xc1U
                                                           : 
                                                          ((0xcU 
                                                            == (IData)(Top__DOT__seg0_io_in))
                                                            ? 0x63U
                                                            : 
                                                           ((0xdU 
                                                             == (IData)(Top__DOT__seg0_io_in))
                                                             ? 0x85U
                                                             : 
                                                            ((0xeU 
                                                              == (IData)(Top__DOT__seg0_io_in))
                                                              ? 0x61U
                                                              : 0xffU)))))))))))))));
    vlSelf->io_seg_out_1 = ((0U == (IData)(Top__DOT__seg1_io_in))
                             ? 3U : ((1U == (IData)(Top__DOT__seg1_io_in))
                                      ? 0x9fU : ((2U 
                                                  == (IData)(Top__DOT__seg1_io_in))
                                                  ? 0x25U
                                                  : 
                                                 ((3U 
                                                   == (IData)(Top__DOT__seg1_io_in))
                                                   ? 0xdU
                                                   : 
                                                  ((4U 
                                                    == (IData)(Top__DOT__seg1_io_in))
                                                    ? 0x99U
                                                    : 
                                                   ((5U 
                                                     == (IData)(Top__DOT__seg1_io_in))
                                                     ? 0x49U
                                                     : 
                                                    ((6U 
                                                      == (IData)(Top__DOT__seg1_io_in))
                                                      ? 0x41U
                                                      : 
                                                     ((7U 
                                                       == (IData)(Top__DOT__seg1_io_in))
                                                       ? 0x1fU
                                                       : 
                                                      ((8U 
                                                        == (IData)(Top__DOT__seg1_io_in))
                                                        ? 1U
                                                        : 
                                                       ((9U 
                                                         == (IData)(Top__DOT__seg1_io_in))
                                                         ? 9U
                                                         : 
                                                        ((0xaU 
                                                          == (IData)(Top__DOT__seg1_io_in))
                                                          ? 0x11U
                                                          : 
                                                         ((0xbU 
                                                           == (IData)(Top__DOT__seg1_io_in))
                                                           ? 0xc1U
                                                           : 
                                                          ((0xcU 
                                                            == (IData)(Top__DOT__seg1_io_in))
                                                            ? 0x63U
                                                            : 
                                                           ((0xdU 
                                                             == (IData)(Top__DOT__seg1_io_in))
                                                             ? 0x85U
                                                             : 
                                                            ((0xeU 
                                                              == (IData)(Top__DOT__seg1_io_in))
                                                              ? 0x61U
                                                              : 0xffU)))))))))))))));
    vlSelf->io_seg_out_2 = ((0U == (IData)(Top__DOT__seg2_io_in))
                             ? 3U : ((1U == (IData)(Top__DOT__seg2_io_in))
                                      ? 0x9fU : ((2U 
                                                  == (IData)(Top__DOT__seg2_io_in))
                                                  ? 0x25U
                                                  : 
                                                 ((3U 
                                                   == (IData)(Top__DOT__seg2_io_in))
                                                   ? 0xdU
                                                   : 
                                                  ((4U 
                                                    == (IData)(Top__DOT__seg2_io_in))
                                                    ? 0x99U
                                                    : 
                                                   ((5U 
                                                     == (IData)(Top__DOT__seg2_io_in))
                                                     ? 0x49U
                                                     : 
                                                    ((6U 
                                                      == (IData)(Top__DOT__seg2_io_in))
                                                      ? 0x41U
                                                      : 
                                                     ((7U 
                                                       == (IData)(Top__DOT__seg2_io_in))
                                                       ? 0x1fU
                                                       : 
                                                      ((8U 
                                                        == (IData)(Top__DOT__seg2_io_in))
                                                        ? 1U
                                                        : 
                                                       ((9U 
                                                         == (IData)(Top__DOT__seg2_io_in))
                                                         ? 9U
                                                         : 
                                                        ((0xaU 
                                                          == (IData)(Top__DOT__seg2_io_in))
                                                          ? 0x11U
                                                          : 
                                                         ((0xbU 
                                                           == (IData)(Top__DOT__seg2_io_in))
                                                           ? 0xc1U
                                                           : 
                                                          ((0xcU 
                                                            == (IData)(Top__DOT__seg2_io_in))
                                                            ? 0x63U
                                                            : 
                                                           ((0xdU 
                                                             == (IData)(Top__DOT__seg2_io_in))
                                                             ? 0x85U
                                                             : 
                                                            ((0xeU 
                                                              == (IData)(Top__DOT__seg2_io_in))
                                                              ? 0x61U
                                                              : 0xffU)))))))))))))));
    vlSelf->io_seg_out_3 = ((0U == (IData)(Top__DOT__seg3_io_in))
                             ? 3U : ((1U == (IData)(Top__DOT__seg3_io_in))
                                      ? 0x9fU : ((2U 
                                                  == (IData)(Top__DOT__seg3_io_in))
                                                  ? 0x25U
                                                  : 
                                                 ((3U 
                                                   == (IData)(Top__DOT__seg3_io_in))
                                                   ? 0xdU
                                                   : 
                                                  ((4U 
                                                    == (IData)(Top__DOT__seg3_io_in))
                                                    ? 0x99U
                                                    : 
                                                   ((5U 
                                                     == (IData)(Top__DOT__seg3_io_in))
                                                     ? 0x49U
                                                     : 
                                                    ((6U 
                                                      == (IData)(Top__DOT__seg3_io_in))
                                                      ? 0x41U
                                                      : 
                                                     ((7U 
                                                       == (IData)(Top__DOT__seg3_io_in))
                                                       ? 0x1fU
                                                       : 
                                                      ((8U 
                                                        == (IData)(Top__DOT__seg3_io_in))
                                                        ? 1U
                                                        : 
                                                       ((9U 
                                                         == (IData)(Top__DOT__seg3_io_in))
                                                         ? 9U
                                                         : 
                                                        ((0xaU 
                                                          == (IData)(Top__DOT__seg3_io_in))
                                                          ? 0x11U
                                                          : 
                                                         ((0xbU 
                                                           == (IData)(Top__DOT__seg3_io_in))
                                                           ? 0xc1U
                                                           : 
                                                          ((0xcU 
                                                            == (IData)(Top__DOT__seg3_io_in))
                                                            ? 0x63U
                                                            : 
                                                           ((0xdU 
                                                             == (IData)(Top__DOT__seg3_io_in))
                                                             ? 0x85U
                                                             : 
                                                            ((0xeU 
                                                              == (IData)(Top__DOT__seg3_io_in))
                                                              ? 0x61U
                                                              : 0xffU)))))))))))))));
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
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

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
    vlSelf->io_clrn = 0;
    vlSelf->io_ps2_clk = 0;
    vlSelf->io_ps2_data = 0;
    vlSelf->io_seg_out_0 = 0;
    vlSelf->io_seg_out_1 = 0;
    vlSelf->io_seg_out_2 = 0;
    vlSelf->io_seg_out_3 = 0;
    vlSelf->io_seg_out_4 = 0;
    vlSelf->io_seg_out_5 = 0;
    vlSelf->Top__DOT__keyboard_io_data = 0;
    vlSelf->Top__DOT__decoder_io_pressed = 0;
    vlSelf->Top__DOT__nextdata_n = 0;
    vlSelf->Top__DOT__ready_delay = 0;
    vlSelf->Top__DOT__keyboard__DOT__buffer = 0;
    vlSelf->Top__DOT__keyboard__DOT__fifo_0 = 0;
    vlSelf->Top__DOT__keyboard__DOT__fifo_1 = 0;
    vlSelf->Top__DOT__keyboard__DOT__fifo_2 = 0;
    vlSelf->Top__DOT__keyboard__DOT__fifo_3 = 0;
    vlSelf->Top__DOT__keyboard__DOT__fifo_4 = 0;
    vlSelf->Top__DOT__keyboard__DOT__fifo_5 = 0;
    vlSelf->Top__DOT__keyboard__DOT__fifo_6 = 0;
    vlSelf->Top__DOT__keyboard__DOT__fifo_7 = 0;
    vlSelf->Top__DOT__keyboard__DOT__w_ptr = 0;
    vlSelf->Top__DOT__keyboard__DOT__r_ptr = 0;
    vlSelf->Top__DOT__keyboard__DOT__count = 0;
    vlSelf->Top__DOT__keyboard__DOT__ready = 0;
    vlSelf->Top__DOT__keyboard__DOT__ps2_clk_sync = 0;
    vlSelf->Top__DOT__keyboard__DOT___ps2_clk_sync_T_1 = 0;
    vlSelf->Top__DOT__keyboard__DOT__sampling = 0;
    vlSelf->Top__DOT__keyboard__DOT___r_ptr_T_2 = 0;
    vlSelf->Top__DOT__keyboard__DOT___GEN_1 = 0;
    vlSelf->Top__DOT__keyboard__DOT__valid = 0;
    vlSelf->Top__DOT__keyboard__DOT___GEN_11 = 0;
    vlSelf->Top__DOT__keyboard__DOT___GEN_12 = 0;
    vlSelf->Top__DOT__keyboard__DOT___GEN_13 = 0;
    vlSelf->Top__DOT__keyboard__DOT___GEN_14 = 0;
    vlSelf->Top__DOT__keyboard__DOT___GEN_15 = 0;
    vlSelf->Top__DOT__keyboard__DOT___GEN_16 = 0;
    vlSelf->Top__DOT__keyboard__DOT___GEN_17 = 0;
    vlSelf->Top__DOT__keyboard__DOT___GEN_18 = 0;
    vlSelf->Top__DOT__keyboard__DOT___GEN_19 = 0;
    vlSelf->Top__DOT__keyboard__DOT___buffer_T = 0;
    vlSelf->Top__DOT__keyboard__DOT___count_T_1 = 0;
    vlSelf->Top__DOT__decoder__DOT__isBreakCode = 0;
    vlSelf->Top__DOT__counter__DOT__ones = 0;
    vlSelf->Top__DOT__counter__DOT__tens = 0;
    vlSelf->Top__DOT__counter__DOT__debounce_count = 0;
    vlSelf->Top__DOT__counter__DOT__stable_key_press = 0;
    vlSelf->Top__DOT__counter__DOT___debounce_count_T_1 = 0;
    vlSelf->Top__DOT__counter__DOT__stable_key_rise_REG = 0;
    vlSelf->Top__DOT__counter__DOT__stable_key_rise = 0;
    vlSelf->Top__DOT__counter__DOT___tens_T_3 = 0;
    vlSelf->Top__DOT__counter__DOT___ones_T_1 = 0;
    vlSelf->__Vtrigrprev__TOP__clock = 0;
}
