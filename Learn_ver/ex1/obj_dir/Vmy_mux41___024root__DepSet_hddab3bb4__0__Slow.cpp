// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_mux41.h for the primary calling header

#include "verilated.h"

#include "Vmy_mux41__Syms.h"
#include "Vmy_mux41___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmy_mux41___024root___dump_triggers__stl(Vmy_mux41___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmy_mux41___024root___eval_triggers__stl(Vmy_mux41___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmy_mux41__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_mux41___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.at(0U) = (0U == vlSelf->__VstlIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmy_mux41___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
