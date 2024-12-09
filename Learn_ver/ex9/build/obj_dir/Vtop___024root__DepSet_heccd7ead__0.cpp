// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*2:0*/ __Vdly__top__DOT__ps2_kb__DOT__ps2_clk_sync;
    __Vdly__top__DOT__ps2_kb__DOT__ps2_clk_sync = 0;
    CData/*2:0*/ __Vdly__top__DOT__ps2_kb__DOT__r_ptr;
    __Vdly__top__DOT__ps2_kb__DOT__r_ptr = 0;
    CData/*2:0*/ __Vdlyvdim0__top__DOT__ps2_kb__DOT__fifo__v0;
    __Vdlyvdim0__top__DOT__ps2_kb__DOT__fifo__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__ps2_kb__DOT__fifo__v0;
    __Vdlyvval__top__DOT__ps2_kb__DOT__fifo__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__ps2_kb__DOT__fifo__v0;
    __Vdlyvset__top__DOT__ps2_kb__DOT__fifo__v0 = 0;
    CData/*2:0*/ __Vdly__top__DOT__ps2_kb__DOT__w_ptr;
    __Vdly__top__DOT__ps2_kb__DOT__w_ptr = 0;
    CData/*3:0*/ __Vdly__top__DOT__ps2_kb__DOT__count;
    __Vdly__top__DOT__ps2_kb__DOT__count = 0;
    SData/*9:0*/ __Vdly__top__DOT__u_vga_ctrl__DOT__y_cnt;
    __Vdly__top__DOT__u_vga_ctrl__DOT__y_cnt = 0;
    // Body
    __Vdly__top__DOT__ps2_kb__DOT__ps2_clk_sync = vlSelf->top__DOT__ps2_kb__DOT__ps2_clk_sync;
    __Vdly__top__DOT__u_vga_ctrl__DOT__y_cnt = vlSelf->top__DOT__u_vga_ctrl__DOT__y_cnt;
    __Vdly__top__DOT__ps2_kb__DOT__count = vlSelf->top__DOT__ps2_kb__DOT__count;
    __Vdly__top__DOT__ps2_kb__DOT__w_ptr = vlSelf->top__DOT__ps2_kb__DOT__w_ptr;
    vlSelf->__Vdly__top__DOT__ready = vlSelf->top__DOT__ready;
    __Vdly__top__DOT__ps2_kb__DOT__r_ptr = vlSelf->top__DOT__ps2_kb__DOT__r_ptr;
    __Vdlyvset__top__DOT__ps2_kb__DOT__fifo__v0 = 0U;
    __Vdly__top__DOT__ps2_kb__DOT__ps2_clk_sync = (
                                                   (6U 
                                                    & ((IData)(vlSelf->top__DOT__ps2_kb__DOT__ps2_clk_sync) 
                                                       << 1U)) 
                                                   | (IData)(vlSelf->ps2_clk));
    if (vlSelf->clrn) {
        __Vdly__top__DOT__u_vga_ctrl__DOT__y_cnt = 1U;
        if (vlSelf->top__DOT__ready) {
            if ((1U & (~ (IData)(vlSelf->top__DOT__ps2_kb__DOT__nextdata_n)))) {
                __Vdly__top__DOT__ps2_kb__DOT__r_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__ps2_kb__DOT__r_ptr)));
                if (((IData)(vlSelf->top__DOT__ps2_kb__DOT__w_ptr) 
                     == (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__ps2_kb__DOT__r_ptr))))) {
                    vlSelf->__Vdly__top__DOT__ready = 0U;
                }
            }
        }
        if ((IData)((4U == (6U & (IData)(vlSelf->top__DOT__ps2_kb__DOT__ps2_clk_sync))))) {
            if ((0xaU == (IData)(vlSelf->top__DOT__ps2_kb__DOT__count))) {
                if ((((~ (IData)(vlSelf->top__DOT__ps2_kb__DOT__buffer)) 
                      & (IData)(vlSelf->ps2_data)) 
                     & VL_REDXOR_32((0x1ffU & ((IData)(vlSelf->top__DOT__ps2_kb__DOT__buffer) 
                                               >> 1U))))) {
                    __Vdlyvval__top__DOT__ps2_kb__DOT__fifo__v0 
                        = (0xffU & ((IData)(vlSelf->top__DOT__ps2_kb__DOT__buffer) 
                                    >> 1U));
                    __Vdlyvset__top__DOT__ps2_kb__DOT__fifo__v0 = 1U;
                    __Vdlyvdim0__top__DOT__ps2_kb__DOT__fifo__v0 
                        = vlSelf->top__DOT__ps2_kb__DOT__w_ptr;
                    vlSelf->__Vdly__top__DOT__ready = 1U;
                    __Vdly__top__DOT__ps2_kb__DOT__w_ptr 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->top__DOT__ps2_kb__DOT__w_ptr)));
                    vlSelf->top__DOT__overflow_signal 
                        = ((IData)(vlSelf->top__DOT__overflow_signal) 
                           | ((IData)(vlSelf->top__DOT__ps2_kb__DOT__r_ptr) 
                              == (7U & ((IData)(1U) 
                                        + (IData)(vlSelf->top__DOT__ps2_kb__DOT__w_ptr)))));
                }
                __Vdly__top__DOT__ps2_kb__DOT__count = 0U;
            } else {
                vlSelf->top__DOT__ps2_kb__DOT____Vlvbound_h1a91ade8__0 
                    = vlSelf->ps2_data;
                if ((9U >= (IData)(vlSelf->top__DOT__ps2_kb__DOT__count))) {
                    vlSelf->top__DOT__ps2_kb__DOT__buffer 
                        = (((~ ((IData)(1U) << (IData)(vlSelf->top__DOT__ps2_kb__DOT__count))) 
                            & (IData)(vlSelf->top__DOT__ps2_kb__DOT__buffer)) 
                           | (0x3ffU & ((IData)(vlSelf->top__DOT__ps2_kb__DOT____Vlvbound_h1a91ade8__0) 
                                        << (IData)(vlSelf->top__DOT__ps2_kb__DOT__count))));
                }
                __Vdly__top__DOT__ps2_kb__DOT__count 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->top__DOT__ps2_kb__DOT__count)));
            }
        }
    } else {
        if (((0x20dU == (IData)(vlSelf->top__DOT__u_vga_ctrl__DOT__y_cnt)) 
             & (0x320U == (IData)(vlSelf->top__DOT__u_vga_ctrl__DOT__x_cnt)))) {
            __Vdly__top__DOT__u_vga_ctrl__DOT__y_cnt = 1U;
        } else if ((0x320U == (IData)(vlSelf->top__DOT__u_vga_ctrl__DOT__x_cnt))) {
            __Vdly__top__DOT__u_vga_ctrl__DOT__y_cnt 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->top__DOT__u_vga_ctrl__DOT__y_cnt)));
        }
        __Vdly__top__DOT__ps2_kb__DOT__count = 0U;
        __Vdly__top__DOT__ps2_kb__DOT__w_ptr = 0U;
        __Vdly__top__DOT__ps2_kb__DOT__r_ptr = 0U;
        vlSelf->top__DOT__overflow_signal = 0U;
        vlSelf->__Vdly__top__DOT__ready = 0U;
    }
    vlSelf->top__DOT__u_vga_ctrl__DOT__y_cnt = __Vdly__top__DOT__u_vga_ctrl__DOT__y_cnt;
    vlSelf->top__DOT__ps2_kb__DOT__ps2_clk_sync = __Vdly__top__DOT__ps2_kb__DOT__ps2_clk_sync;
    vlSelf->top__DOT__ps2_kb__DOT__w_ptr = __Vdly__top__DOT__ps2_kb__DOT__w_ptr;
    vlSelf->top__DOT__ps2_kb__DOT__count = __Vdly__top__DOT__ps2_kb__DOT__count;
    vlSelf->top__DOT__ps2_kb__DOT__r_ptr = __Vdly__top__DOT__ps2_kb__DOT__r_ptr;
    if (__Vdlyvset__top__DOT__ps2_kb__DOT__fifo__v0) {
        vlSelf->top__DOT__ps2_kb__DOT__fifo[__Vdlyvdim0__top__DOT__ps2_kb__DOT__fifo__v0] 
            = __Vdlyvval__top__DOT__ps2_kb__DOT__fifo__v0;
    }
    vlSelf->vsync = (2U < (IData)(vlSelf->top__DOT__u_vga_ctrl__DOT__y_cnt));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->top__DOT__u_vga_ctrl__DOT__x_cnt = ((IData)(vlSelf->clrn)
                                                 ? 1U
                                                 : 
                                                ((0x320U 
                                                  == (IData)(vlSelf->top__DOT__u_vga_ctrl__DOT__x_cnt))
                                                  ? 1U
                                                  : 
                                                 (0x3ffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelf->top__DOT__u_vga_ctrl__DOT__x_cnt)))));
    vlSelf->hsync = (0x60U < (IData)(vlSelf->top__DOT__u_vga_ctrl__DOT__x_cnt));
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    // Init
    VlUnpacked<CData/*7:0*/, 16> top__DOT__input_buffer;
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        top__DOT__input_buffer[__Vi0] = 0;
    }
    CData/*3:0*/ __Vdly__top__DOT__char_count;
    __Vdly__top__DOT__char_count = 0;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__input_buffer__v0;
    __Vdlyvdim0__top__DOT__input_buffer__v0 = 0;
    CData/*7:0*/ __Vdlyvval__top__DOT__input_buffer__v0;
    __Vdlyvval__top__DOT__input_buffer__v0 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__input_buffer__v0;
    __Vdlyvset__top__DOT__input_buffer__v0 = 0;
    // Body
    __Vdly__top__DOT__char_count = vlSelf->top__DOT__char_count;
    __Vdlyvset__top__DOT__input_buffer__v0 = 0U;
    if (vlSelf->clrn) {
        vlSelf->top__DOT__ascii_distinguish = ((0xf0U 
                                                == (IData)(vlSelf->top__DOT__ascii_data))
                                                ? 0U
                                                : (IData)(vlSelf->top__DOT__ps2_dist__DOT__ascii_result));
        if (((IData)(vlSelf->top__DOT__ready) & (~ (IData)(vlSelf->top__DOT__key_release)))) {
            if ((0xdU == (IData)(vlSelf->top__DOT__ascii_data))) {
                vlSelf->top__DOT__y = (0x3ffU & ((IData)(8U) 
                                                 + (IData)(vlSelf->top__DOT__y)));
                __Vdly__top__DOT__char_count = 0U;
                vlSelf->top__DOT__x = 0U;
            } else {
                __Vdlyvval__top__DOT__input_buffer__v0 
                    = vlSelf->top__DOT__ascii_data;
                __Vdlyvset__top__DOT__input_buffer__v0 = 1U;
                __Vdlyvdim0__top__DOT__input_buffer__v0 
                    = vlSelf->top__DOT__char_count;
                vlSelf->top__DOT__x = (0x3ffU & (VL_MODDIV_III(32, (IData)(vlSelf->top__DOT__char_count), (IData)(0x50U)) 
                                                 << 3U));
                vlSelf->top__DOT__y = (0x3ffU & (VL_DIV_III(32, (IData)(vlSelf->top__DOT__char_count), (IData)(0x50U)) 
                                                 << 3U));
                __Vdly__top__DOT__char_count = (0xfU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelf->top__DOT__char_count)));
            }
        }
    } else {
        vlSelf->top__DOT__ascii_distinguish = 0U;
        vlSelf->top__DOT__y = 0U;
        __Vdly__top__DOT__char_count = 0U;
        vlSelf->top__DOT__x = 0U;
    }
    vlSelf->top__DOT__char_count = __Vdly__top__DOT__char_count;
    if (__Vdlyvset__top__DOT__input_buffer__v0) {
        top__DOT__input_buffer[__Vdlyvdim0__top__DOT__input_buffer__v0] 
            = __Vdlyvval__top__DOT__input_buffer__v0;
    }
    if ((0x41U == (IData)(vlSelf->top__DOT__ascii_distinguish))) {
        vlSelf->top__DOT__char_display_inst__DOT__current_font[0U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_A
            [0U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[1U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_A
            [1U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[2U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_A
            [2U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[3U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_A
            [3U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[4U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_A
            [4U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[5U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_A
            [5U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[6U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_A
            [6U];
    } else if ((0x42U == (IData)(vlSelf->top__DOT__ascii_distinguish))) {
        vlSelf->top__DOT__char_display_inst__DOT__current_font[0U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_B
            [0U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[1U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_B
            [1U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[2U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_B
            [2U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[3U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_B
            [3U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[4U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_B
            [4U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[5U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_B
            [5U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[6U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_B
            [6U];
    } else if ((0x43U == (IData)(vlSelf->top__DOT__ascii_distinguish))) {
        vlSelf->top__DOT__char_display_inst__DOT__current_font[0U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_C
            [0U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[1U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_C
            [1U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[2U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_C
            [2U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[3U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_C
            [3U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[4U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_C
            [4U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[5U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_C
            [5U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[6U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_C
            [6U];
    } else if ((0x44U == (IData)(vlSelf->top__DOT__ascii_distinguish))) {
        vlSelf->top__DOT__char_display_inst__DOT__current_font[0U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_D
            [0U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[1U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_D
            [1U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[2U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_D
            [2U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[3U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_D
            [3U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[4U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_D
            [4U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[5U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_D
            [5U];
        vlSelf->top__DOT__char_display_inst__DOT__current_font[6U] 
            = vlSelf->top__DOT__char_display_inst__DOT__font_D
            [6U];
    } else {
        vlSelf->top__DOT__char_display_inst__DOT__current_font[0U] = 0U;
        vlSelf->top__DOT__char_display_inst__DOT__current_font[1U] = 0U;
        vlSelf->top__DOT__char_display_inst__DOT__current_font[2U] = 0U;
        vlSelf->top__DOT__char_display_inst__DOT__current_font[3U] = 0U;
        vlSelf->top__DOT__char_display_inst__DOT__current_font[4U] = 0U;
        vlSelf->top__DOT__char_display_inst__DOT__current_font[5U] = 0U;
        vlSelf->top__DOT__char_display_inst__DOT__current_font[6U] = 0U;
    }
    vlSelf->top__DOT__key_release = ((IData)(vlSelf->clrn) 
                                     & (0xf0U == (IData)(vlSelf->top__DOT__ascii_data)));
    vlSelf->vga_r = (((7U > (IData)(vlSelf->top__DOT__x)) 
                      & ((7U > (IData)(vlSelf->top__DOT__y)) 
                         & ((6U >= (7U & (IData)(vlSelf->top__DOT__x))) 
                            & (((6U >= (7U & (IData)(vlSelf->top__DOT__y)))
                                 ? vlSelf->top__DOT__char_display_inst__DOT__current_font
                                [(7U & (IData)(vlSelf->top__DOT__y))]
                                 : 0U) >> (7U & (IData)(vlSelf->top__DOT__x))))))
                      ? 0xffU : 0U);
    vlSelf->vga_g = vlSelf->vga_r;
    vlSelf->vga_b = vlSelf->vga_r;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    // Init
    CData/*7:0*/ top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out;
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out = 0;
    CData/*0:0*/ top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit;
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit = 0;
    // Body
    vlSelf->top__DOT__ready = vlSelf->__Vdly__top__DOT__ready;
    vlSelf->top__DOT__ascii_data = vlSelf->top__DOT__ps2_kb__DOT__fifo
        [vlSelf->top__DOT__ps2_kb__DOT__r_ptr];
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                       == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
           [0U]);
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->top__DOT__ascii_data) == 
           vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
           [0U]);
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [1U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [1U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [2U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [2U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [3U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [3U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [4U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [4U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [4U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [5U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [5U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [5U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [6U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [6U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [6U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [7U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [7U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [7U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [8U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [8U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [8U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [9U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [9U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [9U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0xaU]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0xaU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0xaU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0xbU]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0xbU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0xbU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0xcU]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0xcU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0xcU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0xdU]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0xdU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0xdU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0xeU]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0xeU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0xeU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0xfU]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0xfU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0xfU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x10U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x10U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x10U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x11U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x11U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x11U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x12U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x12U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x12U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x13U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x13U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x13U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x14U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x14U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x14U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x15U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x15U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x15U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x16U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x16U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x16U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x17U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x17U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x17U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x18U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x18U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x18U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x19U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x19U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x19U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x1aU]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x1aU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x1aU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x1bU]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x1bU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x1bU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x1cU]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x1cU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x1cU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x1dU]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x1dU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x1dU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x1eU]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x1eU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x1eU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x1fU]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x1fU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x1fU]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x20U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x20U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x20U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x21U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x21U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x21U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x22U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x22U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x22U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->top__DOT__ascii_data) 
                          == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x23U]))) & vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x23U]));
    top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->top__DOT__ascii_data) 
              == vlSelf->top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x23U]));
    vlSelf->top__DOT__ps2_dist__DOT__ascii_result = 
        ((IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__hit)
          ? (IData)(top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__lut_out)
          : 0U);
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(2U)) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
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
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex9/vsrc/top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex9/vsrc/top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->clrn & 0xfeU))) {
        Verilated::overWidthError("clrn");}
    if (VL_UNLIKELY((vlSelf->ps2_clk & 0xfeU))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY((vlSelf->ps2_data & 0xfeU))) {
        Verilated::overWidthError("ps2_data");}
}
#endif  // VL_DEBUG
