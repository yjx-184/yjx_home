// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vclk_top.h for the primary calling header

#include "verilated.h"

#include "Vclk_top__Syms.h"
#include "Vclk_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vclk_top___024root___dump_triggers__act(Vclk_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vclk_top___024root___eval_triggers__act(Vclk_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclk_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclk_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = (((IData)(vlSelf->clk_top__DOT__clk_1s) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk_top__DOT__clk_1s))) 
                                      | ((IData)(vlSelf->reset) 
                                         & (~ (IData)(vlSelf->__Vtrigrprev__TOP__reset))));
    vlSelf->__VactTriggered.at(1U) = (((IData)(vlSelf->clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk))) 
                                      | ((IData)(vlSelf->reset) 
                                         & (~ (IData)(vlSelf->__Vtrigrprev__TOP__reset))));
    vlSelf->__Vtrigrprev__TOP__clk_top__DOT__clk_1s 
        = vlSelf->clk_top__DOT__clk_1s;
    vlSelf->__Vtrigrprev__TOP__reset = vlSelf->reset;
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vclk_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
