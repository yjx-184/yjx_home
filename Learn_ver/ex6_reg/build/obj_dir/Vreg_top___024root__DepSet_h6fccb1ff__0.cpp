// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vreg_top.h for the primary calling header

#include "verilated.h"

#include "Vreg_top__Syms.h"
#include "Vreg_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vreg_top___024root___dump_triggers__act(Vreg_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vreg_top___024root___eval_triggers__act(Vreg_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = (((IData)(vlSelf->clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk))) 
                                      | ((~ (IData)(vlSelf->reset)) 
                                         & (IData)(vlSelf->__Vtrigrprev__TOP__reset)));
    vlSelf->__VactTriggered.at(1U) = (((IData)(vlSelf->reg_top__DOT__btn_clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__reg_top__DOT__btn_clk))) 
                                      | ((~ (IData)(vlSelf->reset)) 
                                         & (IData)(vlSelf->__Vtrigrprev__TOP__reset)));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__reset = vlSelf->reset;
    vlSelf->__Vtrigrprev__TOP__reg_top__DOT__btn_clk 
        = vlSelf->reg_top__DOT__btn_clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vreg_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
