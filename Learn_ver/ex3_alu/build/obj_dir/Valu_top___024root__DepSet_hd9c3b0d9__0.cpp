// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu_top.h for the primary calling header

#include "verilated.h"

#include "Valu_top___024root.h"

extern const VlUnpacked<CData/*7:0*/, 32> Valu_top__ConstPool__TABLE_hdca558d7_0;

VL_INLINE_OPT void Valu_top___024root___ico_sequent__TOP__0(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ alu_top__DOT__result_0;
    alu_top__DOT__result_0 = 0;
    CData/*3:0*/ alu_top__DOT__result_1;
    alu_top__DOT__result_1 = 0;
    CData/*3:0*/ alu_top__DOT__o_result_0;
    alu_top__DOT__o_result_0 = 0;
    CData/*0:0*/ alu_top__DOT__max_0;
    alu_top__DOT__max_0 = 0;
    CData/*0:0*/ alu_top__DOT____Vcellinp__u0_seg__i_signbit;
    alu_top__DOT____Vcellinp__u0_seg__i_signbit = 0;
    CData/*0:0*/ alu_top__DOT__i0__DOT__i0__DOT__lut_out;
    alu_top__DOT__i0__DOT__i0__DOT__lut_out = 0;
    CData/*0:0*/ alu_top__DOT__i1__DOT__i0__DOT__lut_out;
    alu_top__DOT__i1__DOT__i0__DOT__lut_out = 0;
    CData/*0:0*/ alu_top__DOT__i2__DOT__i0__DOT__lut_out;
    alu_top__DOT__i2__DOT__i0__DOT__lut_out = 0;
    CData/*3:0*/ alu_top__DOT__i3__DOT__i0__DOT__lut_out;
    alu_top__DOT__i3__DOT__i0__DOT__lut_out = 0;
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->o_equ = ((7U == (IData)(vlSelf->i_op)) 
                     & ((IData)(vlSelf->i_a) == (IData)(vlSelf->i_b)));
    alu_top__DOT__i0__DOT__i0__DOT__lut_out = (((IData)(vlSelf->i_op) 
                                                == 
                                                vlSelf->alu_top__DOT__i0__DOT__i0__DOT__key_list
                                                [0U]) 
                                               & vlSelf->alu_top__DOT__i0__DOT__i0__DOT__data_list
                                               [0U]);
    alu_top__DOT__i0__DOT__i0__DOT__lut_out = ((IData)(alu_top__DOT__i0__DOT__i0__DOT__lut_out) 
                                               | (((IData)(vlSelf->i_op) 
                                                   == 
                                                   vlSelf->alu_top__DOT__i0__DOT__i0__DOT__key_list
                                                   [1U]) 
                                                  & vlSelf->alu_top__DOT__i0__DOT__i0__DOT__data_list
                                                  [1U]));
    vlSelf->o_cin = alu_top__DOT__i0__DOT__i0__DOT__lut_out;
    vlSelf->alu_top__DOT__i1__DOT__i0__DOT__data_list[0U] 
        = (1U & (((IData)(vlSelf->i_a) + (0xfU & ((IData)(1U) 
                                                  + 
                                                  (~ (IData)(vlSelf->i_b))))) 
                 >> 4U));
    vlSelf->alu_top__DOT__i1__DOT__i0__DOT__data_list[1U] 
        = (1U & (((IData)(vlSelf->i_a) + (IData)(vlSelf->i_b)) 
                 >> 4U));
    alu_top__DOT__result_0 = (0xfU & ((IData)(vlSelf->i_a) 
                                      + (IData)(vlSelf->i_b)));
    alu_top__DOT__result_1 = (0xfU & ((IData)(1U) + 
                                      ((IData)(vlSelf->i_a) 
                                       + (~ (IData)(vlSelf->i_b)))));
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list[0U] 
        = vlSelf->i_a;
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list[5U] 
        = (0xfU & (~ (IData)(vlSelf->i_a)));
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list[2U] 
        = ((IData)(vlSelf->i_a) ^ (IData)(vlSelf->i_b));
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list[3U] 
        = ((IData)(vlSelf->i_a) | (IData)(vlSelf->i_b));
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list[4U] 
        = ((IData)(vlSelf->i_a) & (IData)(vlSelf->i_b));
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list[6U] 
        = (0xfU & ((IData)(1U) + ((IData)(vlSelf->i_a) 
                                  + (~ (IData)(vlSelf->i_b)))));
    vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list[7U] 
        = (0xfU & ((IData)(vlSelf->i_a) + (IData)(vlSelf->i_b)));
    alu_top__DOT__max_0 = ((IData)(vlSelf->i_a) > (IData)(vlSelf->i_b));
    alu_top__DOT__i1__DOT__i0__DOT__lut_out = (((IData)(vlSelf->i_op) 
                                                == 
                                                vlSelf->alu_top__DOT__i1__DOT__i0__DOT__key_list
                                                [0U]) 
                                               & vlSelf->alu_top__DOT__i1__DOT__i0__DOT__data_list
                                               [0U]);
    alu_top__DOT__i1__DOT__i0__DOT__lut_out = ((IData)(alu_top__DOT__i1__DOT__i0__DOT__lut_out) 
                                               | (((IData)(vlSelf->i_op) 
                                                   == 
                                                   vlSelf->alu_top__DOT__i1__DOT__i0__DOT__key_list
                                                   [1U]) 
                                                  & vlSelf->alu_top__DOT__i1__DOT__i0__DOT__data_list
                                                  [1U]));
    vlSelf->o_carry = alu_top__DOT__i1__DOT__i0__DOT__lut_out;
    vlSelf->alu_top__DOT__i2__DOT__i0__DOT__data_list[1U] 
        = (((1U & ((IData)(vlSelf->i_a) >> 3U)) == 
            (1U & ((IData)(vlSelf->i_b) >> 3U))) & 
           ((1U & ((IData)(alu_top__DOT__result_0) 
                   >> 3U)) != (1U & ((IData)(vlSelf->i_a) 
                                     >> 3U))));
    vlSelf->alu_top__DOT__i2__DOT__i0__DOT__data_list[0U] 
        = (((1U & ((IData)(vlSelf->i_a) >> 3U)) == 
            (1U & (((IData)(1U) + (~ (IData)(vlSelf->i_b))) 
                   >> 3U))) & ((1U & ((IData)(alu_top__DOT__result_1) 
                                      >> 3U)) != (1U 
                                                  & ((IData)(vlSelf->i_a) 
                                                     >> 3U))));
    if (alu_top__DOT__max_0) {
        vlSelf->o_max = (6U == (IData)(vlSelf->i_op));
        vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list[1U] 
            = vlSelf->i_a;
    } else {
        vlSelf->o_max = 0U;
        vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list[1U] 
            = vlSelf->i_b;
    }
    alu_top__DOT__i2__DOT__i0__DOT__lut_out = (((IData)(vlSelf->i_op) 
                                                == 
                                                vlSelf->alu_top__DOT__i2__DOT__i0__DOT__key_list
                                                [0U]) 
                                               & vlSelf->alu_top__DOT__i2__DOT__i0__DOT__data_list
                                               [0U]);
    alu_top__DOT__i2__DOT__i0__DOT__lut_out = ((IData)(alu_top__DOT__i2__DOT__i0__DOT__lut_out) 
                                               | (((IData)(vlSelf->i_op) 
                                                   == 
                                                   vlSelf->alu_top__DOT__i2__DOT__i0__DOT__key_list
                                                   [1U]) 
                                                  & vlSelf->alu_top__DOT__i2__DOT__i0__DOT__data_list
                                                  [1U]));
    vlSelf->o_overflow = alu_top__DOT__i2__DOT__i0__DOT__lut_out;
    alu_top__DOT__i3__DOT__i0__DOT__lut_out = ((- (IData)(
                                                          ((IData)(vlSelf->i_op) 
                                                           == 
                                                           vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list
                                                           [0U]))) 
                                               & vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list
                                               [0U]);
    alu_top__DOT__i3__DOT__i0__DOT__lut_out = ((IData)(alu_top__DOT__i3__DOT__i0__DOT__lut_out) 
                                               | ((- (IData)(
                                                             ((IData)(vlSelf->i_op) 
                                                              == 
                                                              vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list
                                                              [1U]))) 
                                                  & vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list
                                                  [1U]));
    alu_top__DOT__i3__DOT__i0__DOT__lut_out = ((IData)(alu_top__DOT__i3__DOT__i0__DOT__lut_out) 
                                               | ((- (IData)(
                                                             ((IData)(vlSelf->i_op) 
                                                              == 
                                                              vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list
                                                              [2U]))) 
                                                  & vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list
                                                  [2U]));
    alu_top__DOT__i3__DOT__i0__DOT__lut_out = ((IData)(alu_top__DOT__i3__DOT__i0__DOT__lut_out) 
                                               | ((- (IData)(
                                                             ((IData)(vlSelf->i_op) 
                                                              == 
                                                              vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list
                                                              [3U]))) 
                                                  & vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list
                                                  [3U]));
    alu_top__DOT__i3__DOT__i0__DOT__lut_out = ((IData)(alu_top__DOT__i3__DOT__i0__DOT__lut_out) 
                                               | ((- (IData)(
                                                             ((IData)(vlSelf->i_op) 
                                                              == 
                                                              vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list
                                                              [4U]))) 
                                                  & vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list
                                                  [4U]));
    alu_top__DOT__i3__DOT__i0__DOT__lut_out = ((IData)(alu_top__DOT__i3__DOT__i0__DOT__lut_out) 
                                               | ((- (IData)(
                                                             ((IData)(vlSelf->i_op) 
                                                              == 
                                                              vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list
                                                              [5U]))) 
                                                  & vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list
                                                  [5U]));
    alu_top__DOT__i3__DOT__i0__DOT__lut_out = ((IData)(alu_top__DOT__i3__DOT__i0__DOT__lut_out) 
                                               | ((- (IData)(
                                                             ((IData)(vlSelf->i_op) 
                                                              == 
                                                              vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list
                                                              [6U]))) 
                                                  & vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list
                                                  [6U]));
    alu_top__DOT__i3__DOT__i0__DOT__lut_out = ((IData)(alu_top__DOT__i3__DOT__i0__DOT__lut_out) 
                                               | ((- (IData)(
                                                             ((IData)(vlSelf->i_op) 
                                                              == 
                                                              vlSelf->alu_top__DOT__i3__DOT__i0__DOT__key_list
                                                              [7U]))) 
                                                  & vlSelf->alu_top__DOT__i3__DOT__i0__DOT__data_list
                                                  [7U]));
    alu_top__DOT__o_result_0 = alu_top__DOT__i3__DOT__i0__DOT__lut_out;
    vlSelf->o_result = ((IData)(vlSelf->o_overflow)
                         ? 0U : (IData)(alu_top__DOT__o_result_0));
    alu_top__DOT____Vcellinp__u0_seg__i_signbit = (
                                                   (~ (IData)(vlSelf->o_overflow)) 
                                                   & ((IData)(alu_top__DOT__o_result_0) 
                                                      >> 3U));
    vlSelf->o_signbit = ((IData)(alu_top__DOT____Vcellinp__u0_seg__i_signbit)
                          ? 0xfdU : 0xffU);
    __Vtableidx1 = ((0x1eU & (((IData)(alu_top__DOT____Vcellinp__u0_seg__i_signbit)
                                ? ((IData)(1U) + (~ (IData)(vlSelf->o_result)))
                                : (IData)(vlSelf->o_result)) 
                              << 1U)) | (IData)(alu_top__DOT____Vcellinp__u0_seg__i_signbit));
    vlSelf->o_seg = Valu_top__ConstPool__TABLE_hdca558d7_0
        [__Vtableidx1];
}

void Valu_top___024root___eval_ico(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Valu_top___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Valu_top___024root___eval_act(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___eval_act\n"); );
}

void Valu_top___024root___eval_nba(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___eval_nba\n"); );
}

void Valu_top___024root___eval_triggers__ico(Valu_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_top___024root___dump_triggers__ico(Valu_top___024root* vlSelf);
#endif  // VL_DEBUG
void Valu_top___024root___eval_triggers__act(Valu_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_top___024root___dump_triggers__act(Valu_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Valu_top___024root___dump_triggers__nba(Valu_top___024root* vlSelf);
#endif  // VL_DEBUG

void Valu_top___024root___eval(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___eval\n"); );
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
        Valu_top___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Valu_top___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex3_alu/vsrc/alu_top.v", 1, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Valu_top___024root___eval_ico(vlSelf);
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
            Valu_top___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Valu_top___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex3_alu/vsrc/alu_top.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Valu_top___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Valu_top___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex3_alu/vsrc/alu_top.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Valu_top___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Valu_top___024root___eval_debug_assertions(Valu_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Valu_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->i_a & 0xf0U))) {
        Verilated::overWidthError("i_a");}
    if (VL_UNLIKELY((vlSelf->i_b & 0xf0U))) {
        Verilated::overWidthError("i_b");}
    if (VL_UNLIKELY((vlSelf->i_op & 0xf8U))) {
        Verilated::overWidthError("i_op");}
}
#endif  // VL_DEBUG
