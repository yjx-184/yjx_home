// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vencode42c__Syms.h"


VL_ATTR_COLD void Vencode42c___024root__trace_init_sub__TOP__0(Vencode42c___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42c__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42c___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1,"in_code", false,-1, 3,0);
    tracep->declBit(c+2,"en", false,-1);
    tracep->declBus(c+3,"out_code", false,-1, 1,0);
    tracep->pushNamePrefix("encode42c ");
    tracep->declBus(c+1,"in_code", false,-1, 3,0);
    tracep->declBit(c+2,"en", false,-1);
    tracep->declBus(c+3,"out_code", false,-1, 1,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vencode42c___024root__trace_init_top(Vencode42c___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42c__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42c___024root__trace_init_top\n"); );
    // Body
    Vencode42c___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vencode42c___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vencode42c___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vencode42c___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vencode42c___024root__trace_register(Vencode42c___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42c__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42c___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vencode42c___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vencode42c___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vencode42c___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vencode42c___024root__trace_full_sub_0(Vencode42c___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vencode42c___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42c___024root__trace_full_top_0\n"); );
    // Init
    Vencode42c___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vencode42c___024root*>(voidSelf);
    Vencode42c__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vencode42c___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vencode42c___024root__trace_full_sub_0(Vencode42c___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vencode42c__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42c___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->in_code),4);
    bufp->fullBit(oldp+2,(vlSelf->en));
    bufp->fullCData(oldp+3,(vlSelf->out_code),2);
}
