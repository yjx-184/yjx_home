// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCombinational_top.h for the primary calling header

#include "verilated.h"

#include "VCombinational_top__Syms.h"
#include "VCombinational_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VCombinational_top___024root___dump_triggers__ico(VCombinational_top___024root* vlSelf);
#endif  // VL_DEBUG

void VCombinational_top___024root___eval_triggers__ico(VCombinational_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCombinational_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCombinational_top___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCombinational_top___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCombinational_top___024root___dump_triggers__act(VCombinational_top___024root* vlSelf);
#endif  // VL_DEBUG

void VCombinational_top___024root___eval_triggers__act(VCombinational_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VCombinational_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCombinational_top___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCombinational_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
