// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "verilated.h"

#include "VTop___024root.h"

VL_INLINE_OPT void VTop___024root___ico_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ico_sequent__TOP__0\n"); );
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
    vlSelf->Top__DOT__keyboard__DOT___ps2_clk_sync_T_1 
        = ((6U & ((IData)(vlSelf->Top__DOT__keyboard__DOT__ps2_clk_sync) 
                  << 1U)) | (IData)(vlSelf->io_ps2_clk));
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
    vlSelf->Top__DOT__decoder_io_pressed = ((~ ((IData)(vlSelf->Top__DOT__decoder__DOT__isBreakCode) 
                                                | (0xf0U 
                                                   == (IData)(vlSelf->Top__DOT__keyboard_io_data)))) 
                                            & (IData)(vlSelf->io_clrn));
    vlSelf->Top__DOT__keyboard__DOT__valid = ((~ (IData)(vlSelf->Top__DOT__keyboard__DOT__buffer)) 
                                              & ((IData)(vlSelf->io_ps2_data) 
                                                 & VL_REDXOR_32(
                                                                (0x1ffU 
                                                                 & ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                                                                    >> 1U)))));
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

void VTop___024root___eval_ico(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        VTop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VTop___024root___eval_act(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_act\n"); );
}

VL_INLINE_OPT void VTop___024root___nba_sequent__TOP__0(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ Top__DOT__seg0_io_in;
    Top__DOT__seg0_io_in = 0;
    CData/*3:0*/ Top__DOT__seg1_io_in;
    Top__DOT__seg1_io_in = 0;
    CData/*3:0*/ Top__DOT__seg2_io_in;
    Top__DOT__seg2_io_in = 0;
    CData/*3:0*/ Top__DOT__seg3_io_in;
    Top__DOT__seg3_io_in = 0;
    CData/*3:0*/ __Vdly__Top__DOT__keyboard__DOT__count;
    __Vdly__Top__DOT__keyboard__DOT__count = 0;
    CData/*2:0*/ __Vdly__Top__DOT__keyboard__DOT__r_ptr;
    __Vdly__Top__DOT__keyboard__DOT__r_ptr = 0;
    CData/*0:0*/ __Vdly__Top__DOT__counter__DOT__stable_key_press;
    __Vdly__Top__DOT__counter__DOT__stable_key_press = 0;
    CData/*3:0*/ __Vdly__Top__DOT__counter__DOT__ones;
    __Vdly__Top__DOT__counter__DOT__ones = 0;
    // Body
    __Vdly__Top__DOT__counter__DOT__ones = vlSelf->Top__DOT__counter__DOT__ones;
    __Vdly__Top__DOT__counter__DOT__stable_key_press 
        = vlSelf->Top__DOT__counter__DOT__stable_key_press;
    __Vdly__Top__DOT__keyboard__DOT__count = vlSelf->Top__DOT__keyboard__DOT__count;
    __Vdly__Top__DOT__keyboard__DOT__r_ptr = vlSelf->Top__DOT__keyboard__DOT__r_ptr;
    if (vlSelf->reset) {
        __Vdly__Top__DOT__counter__DOT__stable_key_press = 0U;
        __Vdly__Top__DOT__keyboard__DOT__r_ptr = 0U;
        vlSelf->Top__DOT__keyboard__DOT__ps2_clk_sync = 0U;
        __Vdly__Top__DOT__counter__DOT__ones = 0U;
        vlSelf->Top__DOT__counter__DOT__tens = 0U;
        vlSelf->Top__DOT__counter__DOT__debounce_count = 0U;
        vlSelf->Top__DOT__keyboard__DOT__buffer = 0U;
        vlSelf->Top__DOT__keyboard__DOT__fifo_0 = 0U;
        vlSelf->Top__DOT__keyboard__DOT__fifo_1 = 0U;
        vlSelf->Top__DOT__keyboard__DOT__fifo_2 = 0U;
        vlSelf->Top__DOT__keyboard__DOT__fifo_3 = 0U;
        vlSelf->Top__DOT__keyboard__DOT__fifo_4 = 0U;
        vlSelf->Top__DOT__keyboard__DOT__fifo_5 = 0U;
        vlSelf->Top__DOT__keyboard__DOT__fifo_6 = 0U;
        vlSelf->Top__DOT__keyboard__DOT__fifo_7 = 0U;
        vlSelf->Top__DOT__keyboard__DOT__w_ptr = 0U;
        __Vdly__Top__DOT__keyboard__DOT__count = 0U;
    } else {
        if ((7U == (IData)(vlSelf->Top__DOT__counter__DOT__debounce_count))) {
            __Vdly__Top__DOT__counter__DOT__stable_key_press 
                = vlSelf->Top__DOT__decoder_io_pressed;
        }
        if (vlSelf->io_clrn) {
            if (((IData)(vlSelf->Top__DOT__keyboard__DOT__ready) 
                 & (~ (IData)(vlSelf->Top__DOT__nextdata_n)))) {
                __Vdly__Top__DOT__keyboard__DOT__r_ptr 
                    = ((7U == (IData)(vlSelf->Top__DOT__keyboard__DOT__r_ptr))
                        ? 0U : (IData)(vlSelf->Top__DOT__keyboard__DOT___r_ptr_T_2));
            }
            if (vlSelf->Top__DOT__counter__DOT__stable_key_rise) {
                if ((9U == (IData)(vlSelf->Top__DOT__counter__DOT__ones))) {
                    __Vdly__Top__DOT__counter__DOT__ones = 0U;
                    vlSelf->Top__DOT__counter__DOT__tens 
                        = vlSelf->Top__DOT__counter__DOT___tens_T_3;
                } else {
                    __Vdly__Top__DOT__counter__DOT__ones 
                        = vlSelf->Top__DOT__counter__DOT___ones_T_1;
                }
            }
            if (vlSelf->Top__DOT__keyboard__DOT__sampling) {
                if ((0xaU != (IData)(vlSelf->Top__DOT__keyboard__DOT__count))) {
                    vlSelf->Top__DOT__keyboard__DOT__buffer 
                        = vlSelf->Top__DOT__keyboard__DOT___buffer_T;
                }
                if ((0xaU == (IData)(vlSelf->Top__DOT__keyboard__DOT__count))) {
                    vlSelf->Top__DOT__keyboard__DOT__fifo_0 
                        = vlSelf->Top__DOT__keyboard__DOT___GEN_11;
                    vlSelf->Top__DOT__keyboard__DOT__fifo_1 
                        = vlSelf->Top__DOT__keyboard__DOT___GEN_12;
                    vlSelf->Top__DOT__keyboard__DOT__fifo_2 
                        = vlSelf->Top__DOT__keyboard__DOT___GEN_13;
                    vlSelf->Top__DOT__keyboard__DOT__fifo_3 
                        = vlSelf->Top__DOT__keyboard__DOT___GEN_14;
                    vlSelf->Top__DOT__keyboard__DOT__fifo_4 
                        = vlSelf->Top__DOT__keyboard__DOT___GEN_15;
                    vlSelf->Top__DOT__keyboard__DOT__fifo_5 
                        = vlSelf->Top__DOT__keyboard__DOT___GEN_16;
                    vlSelf->Top__DOT__keyboard__DOT__fifo_6 
                        = vlSelf->Top__DOT__keyboard__DOT___GEN_17;
                    vlSelf->Top__DOT__keyboard__DOT__fifo_7 
                        = vlSelf->Top__DOT__keyboard__DOT___GEN_18;
                    vlSelf->Top__DOT__keyboard__DOT__w_ptr 
                        = vlSelf->Top__DOT__keyboard__DOT___GEN_19;
                    __Vdly__Top__DOT__keyboard__DOT__count = 0U;
                } else {
                    __Vdly__Top__DOT__keyboard__DOT__count 
                        = vlSelf->Top__DOT__keyboard__DOT___count_T_1;
                }
            }
        } else {
            __Vdly__Top__DOT__keyboard__DOT__r_ptr = 0U;
            __Vdly__Top__DOT__counter__DOT__ones = 0U;
            vlSelf->Top__DOT__counter__DOT__tens = 0U;
            vlSelf->Top__DOT__keyboard__DOT__buffer = 0U;
            vlSelf->Top__DOT__keyboard__DOT__fifo_0 = 0U;
            vlSelf->Top__DOT__keyboard__DOT__fifo_1 = 0U;
            vlSelf->Top__DOT__keyboard__DOT__fifo_2 = 0U;
            vlSelf->Top__DOT__keyboard__DOT__fifo_3 = 0U;
            vlSelf->Top__DOT__keyboard__DOT__fifo_4 = 0U;
            vlSelf->Top__DOT__keyboard__DOT__fifo_5 = 0U;
            vlSelf->Top__DOT__keyboard__DOT__fifo_6 = 0U;
            vlSelf->Top__DOT__keyboard__DOT__fifo_7 = 0U;
            vlSelf->Top__DOT__keyboard__DOT__w_ptr = 0U;
            __Vdly__Top__DOT__keyboard__DOT__count = 0U;
        }
        vlSelf->Top__DOT__keyboard__DOT__ps2_clk_sync 
            = vlSelf->Top__DOT__keyboard__DOT___ps2_clk_sync_T_1;
        vlSelf->Top__DOT__counter__DOT__debounce_count 
            = (((IData)(vlSelf->Top__DOT__decoder_io_pressed) 
                == (IData)(vlSelf->Top__DOT__counter__DOT__stable_key_press))
                ? 0U : (IData)(vlSelf->Top__DOT__counter__DOT___debounce_count_T_1));
    }
    vlSelf->Top__DOT__decoder__DOT__isBreakCode = (
                                                   (~ (IData)(vlSelf->reset)) 
                                                   & ((IData)(vlSelf->io_clrn) 
                                                      & (0xf0U 
                                                         == (IData)(vlSelf->Top__DOT__keyboard_io_data))));
    vlSelf->Top__DOT__keyboard__DOT__r_ptr = __Vdly__Top__DOT__keyboard__DOT__r_ptr;
    vlSelf->Top__DOT__counter__DOT__ones = __Vdly__Top__DOT__counter__DOT__ones;
    vlSelf->Top__DOT__counter__DOT__stable_key_rise_REG 
        = vlSelf->Top__DOT__counter__DOT__stable_key_press;
    vlSelf->Top__DOT__keyboard__DOT___r_ptr_T_2 = (7U 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->Top__DOT__keyboard__DOT__r_ptr)));
    vlSelf->Top__DOT__nextdata_n = (1U & ((IData)(vlSelf->reset) 
                                          | (~ ((~ (IData)(vlSelf->Top__DOT__ready_delay)) 
                                                & (IData)(vlSelf->Top__DOT__keyboard__DOT__ready)))));
    vlSelf->Top__DOT__keyboard__DOT___ps2_clk_sync_T_1 
        = ((6U & ((IData)(vlSelf->Top__DOT__keyboard__DOT__ps2_clk_sync) 
                  << 1U)) | (IData)(vlSelf->io_ps2_clk));
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
    vlSelf->Top__DOT__counter__DOT__stable_key_press 
        = __Vdly__Top__DOT__counter__DOT__stable_key_press;
    vlSelf->Top__DOT__counter__DOT___debounce_count_T_1 
        = (7U & ((IData)(1U) + (IData)(vlSelf->Top__DOT__counter__DOT__debounce_count)));
    vlSelf->Top__DOT__counter__DOT__stable_key_rise 
        = ((~ (IData)(vlSelf->Top__DOT__counter__DOT__stable_key_rise_REG)) 
           & (IData)(vlSelf->Top__DOT__counter__DOT__stable_key_press));
    vlSelf->Top__DOT__ready_delay = ((~ (IData)(vlSelf->reset)) 
                                     & (IData)(vlSelf->Top__DOT__keyboard__DOT__ready));
    vlSelf->Top__DOT__keyboard__DOT__ready = ((~ (IData)(vlSelf->reset)) 
                                              & ((IData)(vlSelf->io_clrn) 
                                                 & ((IData)(vlSelf->Top__DOT__keyboard__DOT__sampling)
                                                     ? 
                                                    ((0xaU 
                                                      == (IData)(vlSelf->Top__DOT__keyboard__DOT__count))
                                                      ? 
                                                     ((IData)(vlSelf->Top__DOT__keyboard__DOT__valid) 
                                                      | (IData)(vlSelf->Top__DOT__keyboard__DOT___GEN_1))
                                                      : (IData)(vlSelf->Top__DOT__keyboard__DOT___GEN_1))
                                                     : (IData)(vlSelf->Top__DOT__keyboard__DOT___GEN_1))));
    vlSelf->Top__DOT__keyboard__DOT__sampling = (IData)(
                                                        (4U 
                                                         == 
                                                         (6U 
                                                          & (IData)(vlSelf->Top__DOT__keyboard__DOT__ps2_clk_sync))));
    vlSelf->Top__DOT__keyboard__DOT__count = __Vdly__Top__DOT__keyboard__DOT__count;
    vlSelf->Top__DOT__keyboard__DOT___count_T_1 = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->Top__DOT__keyboard__DOT__count)));
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
    vlSelf->Top__DOT__keyboard__DOT__valid = ((~ (IData)(vlSelf->Top__DOT__keyboard__DOT__buffer)) 
                                              & ((IData)(vlSelf->io_ps2_data) 
                                                 & VL_REDXOR_32(
                                                                (0x1ffU 
                                                                 & ((IData)(vlSelf->Top__DOT__keyboard__DOT__buffer) 
                                                                    >> 1U)))));
    vlSelf->Top__DOT__decoder_io_pressed = ((~ ((IData)(vlSelf->Top__DOT__decoder__DOT__isBreakCode) 
                                                | (0xf0U 
                                                   == (IData)(vlSelf->Top__DOT__keyboard_io_data)))) 
                                            & (IData)(vlSelf->io_clrn));
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

void VTop___024root___eval_nba(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VTop___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VTop___024root___eval_triggers__ico(VTop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void VTop___024root___dump_triggers__ico(VTop___024root* vlSelf);
#endif  // VL_DEBUG
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
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        VTop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                VTop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex7FSM2/verilog/vsrc/Top.v", 542, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            VTop___024root___eval_ico(vlSelf);
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
            VTop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    VTop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex7FSM2/verilog/vsrc/Top.v", 542, "", "Active region did not converge.");
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
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_Chisel/NanjingExperiment/ex7FSM2/verilog/vsrc/Top.v", 542, "", "NBA region did not converge.");
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
    if (VL_UNLIKELY((vlSelf->io_clrn & 0xfeU))) {
        Verilated::overWidthError("io_clrn");}
    if (VL_UNLIKELY((vlSelf->io_ps2_clk & 0xfeU))) {
        Verilated::overWidthError("io_ps2_clk");}
    if (VL_UNLIKELY((vlSelf->io_ps2_data & 0xfeU))) {
        Verilated::overWidthError("io_ps2_data");}
}
#endif  // VL_DEBUG
