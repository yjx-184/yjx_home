// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadd4__Syms.h"


void Vadd4___024root__trace_chg_sub_0(Vadd4___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vadd4___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root__trace_chg_top_0\n"); );
    // Init
    Vadd4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4___024root*>(voidSelf);
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vadd4___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vadd4___024root__trace_chg_sub_0(Vadd4___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->add4__DOT____Vcellinp__u1____pinNumber3));
        bufp->chgBit(oldp+1,(((IData)(vlSelf->add4__DOT__u1__DOT____VdfgTmp_h36175ebf__0) 
                              ^ (IData)(vlSelf->add4__DOT____Vcellinp__u1____pinNumber3))));
        bufp->chgBit(oldp+2,(vlSelf->add4__DOT____Vcellinp__u2____pinNumber3));
        bufp->chgBit(oldp+3,(((IData)(vlSelf->add4__DOT__u2__DOT____VdfgTmp_h36175ebf__0) 
                              ^ (IData)(vlSelf->add4__DOT____Vcellinp__u2____pinNumber3))));
        bufp->chgBit(oldp+4,(vlSelf->add4__DOT____Vcellinp__u3____pinNumber3));
        bufp->chgBit(oldp+5,(((IData)(vlSelf->add4__DOT__u3__DOT____VdfgTmp_h36175ebf__0) 
                              ^ (IData)(vlSelf->add4__DOT____Vcellinp__u3____pinNumber3))));
    }
    bufp->chgCData(oldp+6,(vlSelf->a),4);
    bufp->chgCData(oldp+7,(vlSelf->b),4);
    bufp->chgBit(oldp+8,(vlSelf->ci));
    bufp->chgCData(oldp+9,(vlSelf->sum),4);
    bufp->chgBit(oldp+10,(vlSelf->co));
    bufp->chgCData(oldp+11,((((IData)(vlSelf->co) << 3U) 
                             | (((IData)(vlSelf->add4__DOT____Vcellinp__u3____pinNumber3) 
                                 << 2U) | (((IData)(vlSelf->add4__DOT____Vcellinp__u2____pinNumber3) 
                                            << 1U) 
                                           | (IData)(vlSelf->add4__DOT____Vcellinp__u1____pinNumber3))))),4);
    bufp->chgBit(oldp+12,((1U & (IData)(vlSelf->a))));
    bufp->chgBit(oldp+13,((1U & (IData)(vlSelf->b))));
    bufp->chgBit(oldp+14,(((IData)(vlSelf->add4__DOT__u0__DOT____VdfgTmp_h36175ebf__0) 
                           ^ (IData)(vlSelf->ci))));
    bufp->chgBit(oldp+15,((1U & ((IData)(vlSelf->a) 
                                 >> 1U))));
    bufp->chgBit(oldp+16,((1U & ((IData)(vlSelf->b) 
                                 >> 1U))));
    bufp->chgBit(oldp+17,((1U & ((IData)(vlSelf->a) 
                                 >> 2U))));
    bufp->chgBit(oldp+18,((1U & ((IData)(vlSelf->b) 
                                 >> 2U))));
    bufp->chgBit(oldp+19,((1U & ((IData)(vlSelf->a) 
                                 >> 3U))));
    bufp->chgBit(oldp+20,((1U & ((IData)(vlSelf->b) 
                                 >> 3U))));
}

void Vadd4___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vadd4___024root__trace_cleanup\n"); );
    // Init
    Vadd4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4___024root*>(voidSelf);
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
