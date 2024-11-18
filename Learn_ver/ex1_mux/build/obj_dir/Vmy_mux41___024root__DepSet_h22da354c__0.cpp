// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_mux41.h for the primary calling header

#include "verilated.h"

#include "Vmy_mux41___024root.h"

VL_INLINE_OPT void Vmy_mux41___024root___ico_sequent__TOP__0(Vmy_mux41___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmy_mux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_mux41___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*1:0*/ my_mux41__DOT__i0__DOT__i0__DOT__lut_out;
    my_mux41__DOT__i0__DOT__i0__DOT__lut_out = 0;
    CData/*0:0*/ my_mux41__DOT__i0__DOT__i0__DOT__hit;
    my_mux41__DOT__i0__DOT__i0__DOT__hit = 0;
    // Body
    vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__data_list[0U] 
        = vlSelf->X3;
    vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__data_list[1U] 
        = vlSelf->X2;
    vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__data_list[2U] 
        = vlSelf->X1;
    vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__data_list[3U] 
        = vlSelf->X0;
    my_mux41__DOT__i0__DOT__i0__DOT__lut_out = ((- (IData)(
                                                           ((IData)(vlSelf->Y) 
                                                            == 
                                                            vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__key_list
                                                            [0U]))) 
                                                & vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__data_list
                                                [0U]);
    my_mux41__DOT__i0__DOT__i0__DOT__hit = ((IData)(vlSelf->Y) 
                                            == vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__key_list
                                            [0U]);
    my_mux41__DOT__i0__DOT__i0__DOT__lut_out = ((IData)(my_mux41__DOT__i0__DOT__i0__DOT__lut_out) 
                                                | ((- (IData)(
                                                              ((IData)(vlSelf->Y) 
                                                               == 
                                                               vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__key_list
                                                               [1U]))) 
                                                   & vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__data_list
                                                   [1U]));
    my_mux41__DOT__i0__DOT__i0__DOT__hit = ((IData)(my_mux41__DOT__i0__DOT__i0__DOT__hit) 
                                            | ((IData)(vlSelf->Y) 
                                               == vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__key_list
                                               [1U]));
    my_mux41__DOT__i0__DOT__i0__DOT__lut_out = ((IData)(my_mux41__DOT__i0__DOT__i0__DOT__lut_out) 
                                                | ((- (IData)(
                                                              ((IData)(vlSelf->Y) 
                                                               == 
                                                               vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__key_list
                                                               [2U]))) 
                                                   & vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__data_list
                                                   [2U]));
    my_mux41__DOT__i0__DOT__i0__DOT__hit = ((IData)(my_mux41__DOT__i0__DOT__i0__DOT__hit) 
                                            | ((IData)(vlSelf->Y) 
                                               == vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__key_list
                                               [2U]));
    my_mux41__DOT__i0__DOT__i0__DOT__lut_out = ((IData)(my_mux41__DOT__i0__DOT__i0__DOT__lut_out) 
                                                | ((- (IData)(
                                                              ((IData)(vlSelf->Y) 
                                                               == 
                                                               vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__key_list
                                                               [3U]))) 
                                                   & vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__data_list
                                                   [3U]));
    my_mux41__DOT__i0__DOT__i0__DOT__hit = ((IData)(my_mux41__DOT__i0__DOT__i0__DOT__hit) 
                                            | ((IData)(vlSelf->Y) 
                                               == vlSelf->my_mux41__DOT__i0__DOT__i0__DOT__key_list
                                               [3U]));
    vlSelf->F = ((IData)(my_mux41__DOT__i0__DOT__i0__DOT__hit)
                  ? (IData)(my_mux41__DOT__i0__DOT__i0__DOT__lut_out)
                  : 0U);
}

void Vmy_mux41___024root___eval_ico(Vmy_mux41___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmy_mux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_mux41___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vmy_mux41___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vmy_mux41___024root___eval_act(Vmy_mux41___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmy_mux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_mux41___024root___eval_act\n"); );
}

void Vmy_mux41___024root___eval_nba(Vmy_mux41___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmy_mux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_mux41___024root___eval_nba\n"); );
}

void Vmy_mux41___024root___eval_triggers__ico(Vmy_mux41___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmy_mux41___024root___dump_triggers__ico(Vmy_mux41___024root* vlSelf);
#endif  // VL_DEBUG
void Vmy_mux41___024root___eval_triggers__act(Vmy_mux41___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmy_mux41___024root___dump_triggers__act(Vmy_mux41___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmy_mux41___024root___dump_triggers__nba(Vmy_mux41___024root* vlSelf);
#endif  // VL_DEBUG

void Vmy_mux41___024root___eval(Vmy_mux41___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmy_mux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_mux41___024root___eval\n"); );
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
        Vmy_mux41___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vmy_mux41___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex1_mux/vsrc/my_mux41.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vmy_mux41___024root___eval_ico(vlSelf);
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
            Vmy_mux41___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vmy_mux41___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex1_mux/vsrc/my_mux41.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vmy_mux41___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vmy_mux41___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex1_mux/vsrc/my_mux41.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vmy_mux41___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vmy_mux41___024root___eval_debug_assertions(Vmy_mux41___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmy_mux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_mux41___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->X0 & 0xfcU))) {
        Verilated::overWidthError("X0");}
    if (VL_UNLIKELY((vlSelf->X1 & 0xfcU))) {
        Verilated::overWidthError("X1");}
    if (VL_UNLIKELY((vlSelf->X2 & 0xfcU))) {
        Verilated::overWidthError("X2");}
    if (VL_UNLIKELY((vlSelf->X3 & 0xfcU))) {
        Verilated::overWidthError("X3");}
    if (VL_UNLIKELY((vlSelf->Y & 0xfcU))) {
        Verilated::overWidthError("Y");}
}
#endif  // VL_DEBUG
