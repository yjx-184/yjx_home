// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvga_top.h for the primary calling header

#include "verilated.h"

#include "Vvga_top___024root.h"

VL_ATTR_COLD void Vvga_top___024root___eval_static(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vvga_top___024root___eval_initial__TOP(Vvga_top___024root* vlSelf);

VL_ATTR_COLD void Vvga_top___024root___eval_initial(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_initial\n"); );
    // Body
    Vvga_top___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vvga_top___024root___eval_initial__TOP(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_hf4afe648__0;
    // Body
    __Vtemp_hf4afe648__0[0U] = 0x2e686578U;
    __Vtemp_hf4afe648__0[1U] = 0x74757265U;
    __Vtemp_hf4afe648__0[2U] = 0x2f706963U;
    __Vtemp_hf4afe648__0[3U] = 0x76737263U;
    VL_READMEM_N(true, 24, 524288, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_hf4afe648__0)
                 ,  &(vlSelf->vga_top__DOT__my_vmem__DOT__vga_mem)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vvga_top___024root___eval_final(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vvga_top___024root___eval_triggers__stl(Vvga_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___dump_triggers__stl(Vvga_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___eval_stl(Vvga_top___024root* vlSelf);

VL_ATTR_COLD void Vvga_top___024root___eval_settle(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vvga_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vvga_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("/home/yjx/Mystudy/yjx_learn/Learn_ver/ex8_vga/vsrc/vga_top.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vvga_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___dump_triggers__stl(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vvga_top___024root___stl_sequent__TOP__0(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*23:0*/ vga_top__DOT__vga_data;
    vga_top__DOT__vga_data = 0;
    // Body
    vlSelf->hsync = (0x60U < (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt));
    vlSelf->vsync = (2U < (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__y_cnt));
    vlSelf->vga_top__DOT__u_vga_ctrl__DOT__h_valid 
        = ((0x90U < (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt)) 
           & (0x310U >= (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt)));
    vlSelf->vga_top__DOT__u_vga_ctrl__DOT__v_valid 
        = ((0x23U < (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__y_cnt)) 
           & (0x203U >= (IData)(vlSelf->vga_top__DOT__u_vga_ctrl__DOT__y_cnt)));
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

VL_ATTR_COLD void Vvga_top___024root___eval_stl(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vvga_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___dump_triggers__act(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vvga_top___024root___dump_triggers__nba(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vvga_top___024root___ctor_var_reset(Vvga_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vvga_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->rst = 0;
    vlSelf->hsync = 0;
    vlSelf->vsync = 0;
    vlSelf->valid = 0;
    vlSelf->vga_r = 0;
    vlSelf->vga_g = 0;
    vlSelf->vga_b = 0;
    vlSelf->vga_top__DOT__u_vga_ctrl__DOT__x_cnt = 0;
    vlSelf->vga_top__DOT__u_vga_ctrl__DOT__y_cnt = 0;
    vlSelf->vga_top__DOT__u_vga_ctrl__DOT__h_valid = 0;
    vlSelf->vga_top__DOT__u_vga_ctrl__DOT__v_valid = 0;
    for (int __Vi0 = 0; __Vi0 < 524288; ++__Vi0) {
        vlSelf->vga_top__DOT__my_vmem__DOT__vga_mem[__Vi0] = 0;
    }
    vlSelf->__Vdly__vga_top__DOT__u_vga_ctrl__DOT__x_cnt = 0;
    vlSelf->__Vtrigrprev__TOP__clk = 0;
    vlSelf->__Vtrigrprev__TOP__rst = 0;
}
