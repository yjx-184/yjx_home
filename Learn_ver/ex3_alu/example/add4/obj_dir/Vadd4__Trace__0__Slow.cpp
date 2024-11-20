// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd4__Syms.h"


VL_ATTR_COLD void Vadd4___024root__trace_init_sub__TOP__0(Vadd4___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+7,"a", false,-1, 3,0);
    tracep->declBus(c+8,"b", false,-1, 3,0);
    tracep->declBit(c+9,"ci", false,-1);
    tracep->declBus(c+10,"sum", false,-1, 3,0);
    tracep->declBit(c+11,"co", false,-1);
    tracep->pushNamePrefix("add4 ");
    tracep->declBus(c+7,"a", false,-1, 3,0);
    tracep->declBus(c+8,"b", false,-1, 3,0);
    tracep->declBit(c+9,"ci", false,-1);
    tracep->declBus(c+10,"sum", false,-1, 3,0);
    tracep->declBit(c+11,"co", false,-1);
    tracep->declBus(c+12,"count", false,-1, 3,0);
    tracep->pushNamePrefix("u0 ");
    tracep->declBit(c+13,"a", false,-1);
    tracep->declBit(c+14,"b", false,-1);
    tracep->declBit(c+9,"ci", false,-1);
    tracep->declBit(c+15,"sum", false,-1);
    tracep->declBit(c+1,"co", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u1 ");
    tracep->declBit(c+16,"a", false,-1);
    tracep->declBit(c+17,"b", false,-1);
    tracep->declBit(c+1,"ci", false,-1);
    tracep->declBit(c+2,"sum", false,-1);
    tracep->declBit(c+3,"co", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u2 ");
    tracep->declBit(c+18,"a", false,-1);
    tracep->declBit(c+19,"b", false,-1);
    tracep->declBit(c+3,"ci", false,-1);
    tracep->declBit(c+4,"sum", false,-1);
    tracep->declBit(c+5,"co", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u3 ");
    tracep->declBit(c+20,"a", false,-1);
    tracep->declBit(c+21,"b", false,-1);
    tracep->declBit(c+5,"ci", false,-1);
    tracep->declBit(c+6,"sum", false,-1);
    tracep->declBit(c+11,"co", false,-1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vadd4___024root__trace_init_top(Vadd4___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root__trace_init_top\n"); );
    // Body
    Vadd4___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vadd4___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd4___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vadd4___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vadd4___024root__trace_register(Vadd4___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vadd4___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vadd4___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vadd4___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vadd4___024root__trace_full_sub_0(Vadd4___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vadd4___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root__trace_full_top_0\n"); );
    // Init
    Vadd4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4___024root*>(voidSelf);
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vadd4___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vadd4___024root__trace_full_sub_0(Vadd4___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->add4__DOT____Vcellinp__u1____pinNumber3));
    bufp->fullBit(oldp+2,(((IData)(vlSelf->add4__DOT__u1__DOT____VdfgTmp_h36175ebf__0) 
                           ^ (IData)(vlSelf->add4__DOT____Vcellinp__u1____pinNumber3))));
    bufp->fullBit(oldp+3,(vlSelf->add4__DOT____Vcellinp__u2____pinNumber3));
    bufp->fullBit(oldp+4,(((IData)(vlSelf->add4__DOT__u2__DOT____VdfgTmp_h36175ebf__0) 
                           ^ (IData)(vlSelf->add4__DOT____Vcellinp__u2____pinNumber3))));
    bufp->fullBit(oldp+5,(vlSelf->add4__DOT____Vcellinp__u3____pinNumber3));
    bufp->fullBit(oldp+6,(((IData)(vlSelf->add4__DOT__u3__DOT____VdfgTmp_h36175ebf__0) 
                           ^ (IData)(vlSelf->add4__DOT____Vcellinp__u3____pinNumber3))));
    bufp->fullCData(oldp+7,(vlSelf->a),4);
    bufp->fullCData(oldp+8,(vlSelf->b),4);
    bufp->fullBit(oldp+9,(vlSelf->ci));
    bufp->fullCData(oldp+10,(vlSelf->sum),4);
    bufp->fullBit(oldp+11,(vlSelf->co));
    bufp->fullCData(oldp+12,((((IData)(vlSelf->co) 
                               << 3U) | (((IData)(vlSelf->add4__DOT____Vcellinp__u3____pinNumber3) 
                                          << 2U) | 
                                         (((IData)(vlSelf->add4__DOT____Vcellinp__u2____pinNumber3) 
                                           << 1U) | (IData)(vlSelf->add4__DOT____Vcellinp__u1____pinNumber3))))),4);
    bufp->fullBit(oldp+13,((1U & (IData)(vlSelf->a))));
    bufp->fullBit(oldp+14,((1U & (IData)(vlSelf->b))));
    bufp->fullBit(oldp+15,(((IData)(vlSelf->add4__DOT__u0__DOT____VdfgTmp_h36175ebf__0) 
                            ^ (IData)(vlSelf->ci))));
    bufp->fullBit(oldp+16,((1U & ((IData)(vlSelf->a) 
                                  >> 1U))));
    bufp->fullBit(oldp+17,((1U & ((IData)(vlSelf->b) 
                                  >> 1U))));
    bufp->fullBit(oldp+18,((1U & ((IData)(vlSelf->a) 
                                  >> 2U))));
    bufp->fullBit(oldp+19,((1U & ((IData)(vlSelf->b) 
                                  >> 2U))));
    bufp->fullBit(oldp+20,((1U & ((IData)(vlSelf->a) 
                                  >> 3U))));
    bufp->fullBit(oldp+21,((1U & ((IData)(vlSelf->b) 
                                  >> 3U))));
}
