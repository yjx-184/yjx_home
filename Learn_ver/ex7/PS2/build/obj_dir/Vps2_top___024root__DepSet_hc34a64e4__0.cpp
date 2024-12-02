// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vps2_top.h for the primary calling header

#include "verilated.h"

#include "Vps2_top___024root.h"

void Vps2_top___024root___eval_act(Vps2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vps2_top___024root___nba_sequent__TOP__0(Vps2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*2:0*/ __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__ps2_clk_sync;
    __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__ps2_clk_sync = 0;
    CData/*2:0*/ __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__r_ptr;
    __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__r_ptr = 0;
    CData/*2:0*/ __Vdlyvdim0__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0;
    __Vdlyvdim0__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0 = 0;
    CData/*7:0*/ __Vdlyvval__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0;
    __Vdlyvval__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0 = 0;
    CData/*0:0*/ __Vdlyvset__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0;
    __Vdlyvset__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0 = 0;
    CData/*2:0*/ __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__w_ptr;
    __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__w_ptr = 0;
    CData/*3:0*/ __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__count;
    __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__count = 0;
    // Body
    __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__ps2_clk_sync 
        = vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__ps2_clk_sync;
    __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__count = vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__count;
    __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__w_ptr = vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__w_ptr;
    vlSelf->__Vdly__ps2_top__DOT__ready = vlSelf->ps2_top__DOT__ready;
    __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__r_ptr = vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__r_ptr;
    __Vdlyvset__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0 = 0U;
    __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__ps2_clk_sync 
        = ((6U & ((IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__ps2_clk_sync) 
                  << 1U)) | (IData)(vlSelf->ps2_clk));
    if (vlSelf->clrn) {
        if (vlSelf->ps2_top__DOT__ready) {
            if ((1U & (~ (IData)(vlSelf->ps2_top__DOT__nextdata_n)))) {
                __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__r_ptr 
                    = (7U & ((IData)(1U) + (IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__r_ptr)));
                if (((IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__w_ptr) 
                     == (7U & ((IData)(1U) + (IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__r_ptr))))) {
                    vlSelf->__Vdly__ps2_top__DOT__ready = 0U;
                }
            }
        }
        if ((IData)((4U == (6U & (IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__ps2_clk_sync))))) {
            if ((0xaU == (IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__count))) {
                if ((((~ (IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__buffer)) 
                      & (IData)(vlSelf->ps2_data)) 
                     & VL_REDXOR_32((0x1ffU & ((IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__buffer) 
                                               >> 1U))))) {
                    __Vdlyvval__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0 
                        = (0xffU & ((IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__buffer) 
                                    >> 1U));
                    __Vdlyvset__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0 = 1U;
                    __Vdlyvdim0__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0 
                        = vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__w_ptr;
                    vlSelf->__Vdly__ps2_top__DOT__ready = 1U;
                    __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__w_ptr 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__w_ptr)));
                    vlSelf->overflow = ((IData)(vlSelf->overflow) 
                                        | ((IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__r_ptr) 
                                           == (7U & 
                                               ((IData)(1U) 
                                                + (IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__w_ptr)))));
                }
                __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__count = 0U;
            } else {
                vlSelf->ps2_top__DOT__u0_ps2_kb__DOT____Vlvbound_h1a91ade8__0 
                    = vlSelf->ps2_data;
                if ((9U >= (IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__count))) {
                    vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__buffer 
                        = (((~ ((IData)(1U) << (IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__count))) 
                            & (IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__buffer)) 
                           | (0x3ffU & ((IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT____Vlvbound_h1a91ade8__0) 
                                        << (IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__count))));
                }
                __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__count 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__count)));
            }
        }
    } else {
        __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__count = 0U;
        __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__w_ptr = 0U;
        __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__r_ptr = 0U;
        vlSelf->overflow = 0U;
        vlSelf->__Vdly__ps2_top__DOT__ready = 0U;
    }
    vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__ps2_clk_sync 
        = __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__ps2_clk_sync;
    vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__w_ptr = __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__w_ptr;
    vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__count = __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__count;
    vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__r_ptr = __Vdly__ps2_top__DOT__u0_ps2_kb__DOT__r_ptr;
    if (__Vdlyvset__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0) {
        vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__fifo[__Vdlyvdim0__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0] 
            = __Vdlyvval__ps2_top__DOT__u0_ps2_kb__DOT__fifo__v0;
    }
}

extern const VlUnpacked<CData/*7:0*/, 16> Vps2_top__ConstPool__TABLE_h1f93ebb4_0;
extern const VlUnpacked<CData/*7:0*/, 32> Vps2_top__ConstPool__TABLE_h66eba408_0;

VL_INLINE_OPT void Vps2_top___024root___nba_sequent__TOP__1(Vps2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_top___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*7:0*/ ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out;
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out = 0;
    CData/*0:0*/ ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit;
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit = 0;
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*4:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*4:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    CData/*4:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    CData/*3:0*/ __Vtableidx5;
    __Vtableidx5 = 0;
    CData/*3:0*/ __Vtableidx6;
    __Vtableidx6 = 0;
    CData/*3:0*/ __Vdly__ps2_top__DOT__high_units;
    __Vdly__ps2_top__DOT__high_units = 0;
    // Body
    __Vdly__ps2_top__DOT__high_units = vlSelf->ps2_top__DOT__high_units;
    if (vlSelf->clrn) {
        vlSelf->ps2_top__DOT__ready_d1 = vlSelf->ps2_top__DOT__ready;
        if ((((~ (IData)(vlSelf->ps2_top__DOT__key_release)) 
              & (IData)(vlSelf->ps2_top__DOT__ready_p1)) 
             & (~ (IData)(vlSelf->ps2_top__DOT__u2_ps2_cer__DOT__counted)))) {
            if ((9U == (IData)(vlSelf->ps2_top__DOT__high_units))) {
                vlSelf->ps2_top__DOT__high_tens = (
                                                   (9U 
                                                    == (IData)(vlSelf->ps2_top__DOT__high_tens))
                                                    ? 0U
                                                    : 
                                                   (0xfU 
                                                    & ((IData)(1U) 
                                                       + (IData)(vlSelf->ps2_top__DOT__high_tens))));
                __Vdly__ps2_top__DOT__high_units = 0U;
            } else {
                __Vdly__ps2_top__DOT__high_units = 
                    (0xfU & ((IData)(1U) + (IData)(vlSelf->ps2_top__DOT__high_units)));
            }
            vlSelf->ps2_top__DOT__u2_ps2_cer__DOT__counted = 1U;
        } else if (vlSelf->ps2_top__DOT__key_release) {
            vlSelf->ps2_top__DOT__u2_ps2_cer__DOT__counted = 0U;
        }
    } else {
        vlSelf->ps2_top__DOT__ready_d1 = 0U;
        __Vdly__ps2_top__DOT__high_units = 0U;
        vlSelf->ps2_top__DOT__high_tens = 0U;
        vlSelf->ps2_top__DOT__u2_ps2_cer__DOT__counted = 0U;
    }
    vlSelf->ps2_top__DOT__high_units = __Vdly__ps2_top__DOT__high_units;
    __Vtableidx6 = vlSelf->ps2_top__DOT__high_tens;
    vlSelf->seg_out_5 = Vps2_top__ConstPool__TABLE_h1f93ebb4_0
        [__Vtableidx6];
    __Vtableidx5 = vlSelf->ps2_top__DOT__high_units;
    vlSelf->seg_out_4 = Vps2_top__ConstPool__TABLE_h1f93ebb4_0
        [__Vtableidx5];
    if (vlSelf->clrn) {
        if (vlSelf->ps2_top__DOT__ready_p1) {
            vlSelf->ps2_top__DOT__key_scan_display 
                = vlSelf->ps2_top__DOT__data;
            vlSelf->ps2_top__DOT__key_ascii_display 
                = vlSelf->ps2_top__DOT__ascii;
            vlSelf->ps2_top__DOT__en = 1U;
        } else if (vlSelf->ps2_top__DOT__key_release) {
            vlSelf->ps2_top__DOT__en = 0U;
        }
    } else {
        vlSelf->ps2_top__DOT__key_scan_display = 0U;
        vlSelf->ps2_top__DOT__key_ascii_display = 0U;
        vlSelf->ps2_top__DOT__en = 0U;
    }
    __Vtableidx1 = ((0x1eU & ((IData)(vlSelf->ps2_top__DOT__key_ascii_display) 
                              << 1U)) | (IData)(vlSelf->ps2_top__DOT__en));
    vlSelf->seg_out_2 = Vps2_top__ConstPool__TABLE_h66eba408_0
        [__Vtableidx1];
    __Vtableidx2 = ((0x1eU & ((IData)(vlSelf->ps2_top__DOT__key_ascii_display) 
                              >> 3U)) | (IData)(vlSelf->ps2_top__DOT__en));
    vlSelf->seg_out_3 = Vps2_top__ConstPool__TABLE_h66eba408_0
        [__Vtableidx2];
    __Vtableidx3 = ((0x1eU & ((IData)(vlSelf->ps2_top__DOT__key_scan_display) 
                              << 1U)) | (IData)(vlSelf->ps2_top__DOT__en));
    vlSelf->seg_out_0 = Vps2_top__ConstPool__TABLE_h66eba408_0
        [__Vtableidx3];
    __Vtableidx4 = ((0x1eU & ((IData)(vlSelf->ps2_top__DOT__key_scan_display) 
                              >> 3U)) | (IData)(vlSelf->ps2_top__DOT__en));
    vlSelf->seg_out_1 = Vps2_top__ConstPool__TABLE_h66eba408_0
        [__Vtableidx4];
    if (vlSelf->clrn) {
        if (vlSelf->ps2_top__DOT__ready_p1) {
            vlSelf->ps2_top__DOT__nextdata_n = 0U;
        } else if ((1U & (~ (IData)(vlSelf->ps2_top__DOT__key_release)))) {
            vlSelf->ps2_top__DOT__nextdata_n = 1U;
        }
        if ((0xf0U == (IData)(vlSelf->ps2_top__DOT__data_d1))) {
            vlSelf->ps2_top__DOT__key_release = 1U;
            vlSelf->ps2_top__DOT__ascii = 0U;
        } else {
            vlSelf->ps2_top__DOT__key_release = 0U;
            vlSelf->ps2_top__DOT__ascii = vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__ascii_result;
        }
        if (vlSelf->ps2_top__DOT__ready_p1) {
            vlSelf->ps2_top__DOT__data_d1 = vlSelf->ps2_top__DOT__data;
        }
    } else {
        vlSelf->ps2_top__DOT__nextdata_n = 1U;
        vlSelf->ps2_top__DOT__key_release = 0U;
        vlSelf->ps2_top__DOT__ascii = 0U;
        vlSelf->ps2_top__DOT__data_d1 = 0U;
    }
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                       == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
           [0U]);
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(vlSelf->ps2_top__DOT__data_d1) == 
           vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
           [0U]);
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [1U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [1U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [2U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [2U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [3U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [3U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [4U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [4U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [4U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [5U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [5U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [5U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [6U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [6U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [6U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [7U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [7U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [7U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [8U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [8U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [8U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [9U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [9U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [9U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0xaU]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0xaU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0xaU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0xbU]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0xbU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0xbU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0xcU]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0xcU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0xcU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0xdU]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0xdU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0xdU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0xeU]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0xeU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0xeU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0xfU]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0xfU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0xfU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x10U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x10U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x10U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x11U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x11U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x11U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x12U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x12U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x12U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x13U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x13U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x13U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x14U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x14U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x14U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x15U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x15U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x15U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x16U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x16U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x16U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x17U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x17U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x17U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x18U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x18U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x18U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x19U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x19U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x19U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x1aU]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x1aU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x1aU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x1bU]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x1bU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x1bU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x1cU]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x1cU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x1cU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x1dU]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x1dU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x1dU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x1eU]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x1eU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x1eU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x1fU]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x1fU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x1fU]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x20U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x20U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x20U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x21U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x21U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x21U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x22U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x22U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x22U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out) 
           | ((- (IData)(((IData)(vlSelf->ps2_top__DOT__data_d1) 
                          == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
                          [0x23U]))) & vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list
              [0x23U]));
    ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit) 
           | ((IData)(vlSelf->ps2_top__DOT__data_d1) 
              == vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list
              [0x23U]));
    vlSelf->ps2_top__DOT__u1_ps2_dsh__DOT__ascii_result 
        = ((IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__hit)
            ? (IData)(ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__lut_out)
            : 0U);
}

VL_INLINE_OPT void Vps2_top___024root___nba_sequent__TOP__2(Vps2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_top___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->ps2_top__DOT__ready = vlSelf->__Vdly__ps2_top__DOT__ready;
    vlSelf->ps2_top__DOT__data = vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__fifo
        [vlSelf->ps2_top__DOT__u0_ps2_kb__DOT__r_ptr];
}

VL_INLINE_OPT void Vps2_top___024root___nba_comb__TOP__0(Vps2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_top___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->ps2_top__DOT__ready_p1 = ((~ (IData)(vlSelf->ps2_top__DOT__ready_d1)) 
                                      & (IData)(vlSelf->ps2_top__DOT__ready));
}

void Vps2_top___024root___eval_nba(Vps2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vps2_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vps2_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vps2_top___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vps2_top___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vps2_top___024root___eval_triggers__act(Vps2_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2_top___024root___dump_triggers__act(Vps2_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vps2_top___024root___dump_triggers__nba(Vps2_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vps2_top___024root___eval(Vps2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_top___024root___eval\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
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
            Vps2_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vps2_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex7/PS2/vsrc/ps2_top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vps2_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vps2_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex7/PS2/vsrc/ps2_top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vps2_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vps2_top___024root___eval_debug_assertions(Vps2_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vps2_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vps2_top___024root___eval_debug_assertions\n"); );
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
