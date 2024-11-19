// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd1__Syms.h"


VL_ATTR_COLD void Vadd1___024root__trace_init_sub__TOP__0(Vadd1___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd1___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"a_i", false,-1);
    tracep->declBit(c+2,"b_i", false,-1);
    tracep->declBit(c+3,"c_i", false,-1);
    tracep->declBit(c+4,"s_i", false,-1);
    tracep->declBit(c+5,"c_o", false,-1);
    tracep->pushNamePrefix("add1 ");
    tracep->declBit(c+1,"a_i", false,-1);
    tracep->declBit(c+2,"b_i", false,-1);
    tracep->declBit(c+3,"c_i", false,-1);
    tracep->declBit(c+4,"s_i", false,-1);
    tracep->declBit(c+5,"c_o", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vadd1___024root__trace_init_top(Vadd1___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd1___024root__trace_init_top\n"); );
    // Body
    Vadd1___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd1___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd1___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd1___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd1___024root__trace_register(Vadd1___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd1___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vadd1___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vadd1___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vadd1___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd1___024root__trace_full_sub_0(Vadd1___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd1___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd1___024root__trace_full_top_0\n"); );
    // Init
    Vadd1___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd1___024root*>(voidSelf);
    Vadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd1___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd1___024root__trace_full_sub_0(Vadd1___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd1__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd1___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->a_i));
    bufp->fullBit(oldp+2,(vlSelf->b_i));
    bufp->fullBit(oldp+3,(vlSelf->c_i));
    bufp->fullBit(oldp+4,(vlSelf->s_i));
    bufp->fullBit(oldp+5,(vlSelf->c_o));
}
