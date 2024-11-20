// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd4b__Syms.h"


void Vadd4b___024root__trace_chg_sub_0(Vadd4b___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd4b___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4b___024root__trace_chg_top_0\n"); );
    // Init
    Vadd4b___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4b___024root*>(voidSelf);
    Vadd4b__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vadd4b___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd4b___024root__trace_chg_sub_0(Vadd4b___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4b__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4b___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgCData(oldp+0,(vlSelf->a),4);
    bufp->chgCData(oldp+1,(vlSelf->b),4);
    bufp->chgCData(oldp+2,(vlSelf->sum),4);
    bufp->chgBit(oldp+3,(vlSelf->co));
}

void Vadd4b___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4b___024root__trace_cleanup\n"); );
    // Init
    Vadd4b___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4b___024root*>(voidSelf);
    Vadd4b__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
