// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvga_top.h for the primary calling header

#include "verilated.h"

#include "Vvga_top___024root.h"

void Vvga_top___024root___eval_act(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vvga_top___024root___nba_sequent__TOP__0(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__vga_top__DOT__u_vga_ctrl__DOT__x_cnt 
        = vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt;
    vlSelf->__Vdly__vga_top__DOT__u_vga_ctrl__DOT__x_cnt 
        = ((IData)(vlSelf->rst) ? 1U : ((0x320U == (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt))
                                         ? 1U : (0x3ffU 
                                                 & ((IData)(1U) 
                                                    + (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt)))));
}

VL_INLINE_OPT void Vvga_top___024root___nba_sequent__TOP__1(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___nba_sequent__TOP__1\n"); );
    // Init
    SData/*9:0*/ __Vdly__vga_top__DOT__u_vga_ctrl__DOT__y_cnt;
    __Vdly__vga_top__DOT__u_vga_ctrl__DOT__y_cnt = 0;
    // Body
    __Vdly__vga_top__DOT__u_vga_ctrl__DOT__y_cnt = vlSelf->vga_top__DOT__u_vga_ctrl__DOT__y_cnt;
    if (vlSelf->rst) {
        __Vdly__vga_top__DOT__u_vga_ctrl__DOT__y_cnt = 1U;
    } else if (((0x20dU == (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__y_cnt)) 
                & (0x320U == (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt)))) {
        __Vdly__vga_top__DOT__u_vga_ctrl__DOT__y_cnt = 1U;
    } else if ((0x320U == (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt))) {
        __Vdly__vga_top__DOT__u_vga_ctrl__DOT__y_cnt 
            = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__y_cnt)));
    }
    vlSelf->vga_top__DOT__u_vga_ctrl__DOT__y_cnt = __Vdly__vga_top__DOT__u_vga_ctrl__DOT__y_cnt;
    vlSelf->vsync = (2U < (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__y_cnt));
    vlSelf->vga_top__DOT__u_vga_ctrl__DOT__v_valid 
        = ((0x23U < (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__y_cnt)) 
           & (0x203U >= (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__y_cnt)));
}

VL_INLINE_OPT void Vvga_top___024root___nba_sequent__TOP__2(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt = vlSelf->__Vdly__vga_top__DOT__u_vga_ctrl__DOT__x_cnt;
    vlSelf->hsync = (0x60U < (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt));
    vlSelf->vga_top__DOT__u_vga_ctrl__DOT__h_valid 
        = ((0x90U < (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt)) 
           & (0x310U >= (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt)));
}

VL_INLINE_OPT void Vvga_top___024root___nba_comb__TOP__0(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___nba_comb__TOP__0\n"); );
    // Init
    IData/*23:0*/ vga_top__DOT__vga_data;
    vga_top__DOT__vga_data = 0;
    // Body
    vlSelf->valid = ((IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__h_valid) 
                     & (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__v_valid));
    vga_top__DOT__vga_data = vlSelf->vga_top__DOT__my_vmem__DOT__vga_mem
        [((((IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__h_valid)
             ? (0x3ffU & ((IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt) 
                          - (IData)(0x91U))) : 0U) 
           << 9U) | ((IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__v_valid)
                      ? (0x1ffU & ((IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__y_cnt) 
                                   - (IData)(0x24U)))
                      : 0U))];
    vlSelf->vga_r = (0xffU & (vga_top__DOT__vga_data 
                              >> 0x10U));
    vlSelf->vga_g = (0xffU & (vga_top__DOT__vga_data 
                              >> 8U));
    vlSelf->vga_b = (0xffU & vga_top__DOT__vga_data);
}

void Vvga_top___024root___eval_nba(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vvga_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vvga_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vvga_top___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vvga_top___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vvga_top___024root___eval_triggers__act(Vvga_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___dump_triggers__act(Vvga_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___dump_triggers__nba(Vvga_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vvga_top___024root___eval(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval\n"); );
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
            Vvga_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vvga_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex8_vga/vsrc/vga_top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vvga_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vvga_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex8_vga/vsrc/vga_top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vvga_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vvga_top___024root___eval_debug_assertions(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
