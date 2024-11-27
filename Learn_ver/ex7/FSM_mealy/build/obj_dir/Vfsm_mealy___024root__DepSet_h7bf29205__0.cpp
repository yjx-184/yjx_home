// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsm_mealy.h for the primary calling header

#include "verilated.h"

#include "Vfsm_mealy__Syms.h"
#include "Vfsm_mealy___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsm_mealy___024root___dump_triggers__ico(Vfsm_mealy___024root* vlSelf);
#endif  // VL_DEBUG

void Vfsm_mealy___024root___eval_triggers__ico(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfsm_mealy___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsm_mealy___024root___dump_triggers__act(Vfsm_mealy___024root* vlSelf);
#endif  // VL_DEBUG

void Vfsm_mealy___024root___eval_triggers__act(Vfsm_mealy___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsm_mealy__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsm_mealy___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = (((IData)(vlSelf->fsm_mealy__DOT__btn_clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__fsm_mealy__DOT__btn_clk))) 
                                      | ((IData)(vlSelf->reset) 
                                         & (~ (IData)(vlSelf->__Vtrigrprev__TOP__reset))));
    vlSelf->__VactTriggered.at(1U) = ((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk)));
    vlSelf->__Vtrigrprev__TOP__fsm_mealy__DOT__btn_clk 
        = vlSelf->fsm_mealy__DOT__btn_clk;
    vlSelf->__Vtrigrprev__TOP__reset = vlSelf->reset;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfsm_mealy___024root___dump_triggers__act(vlSelf);
    }
#endif
}
