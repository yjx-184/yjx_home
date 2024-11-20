// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vadd4.h for the primary calling header

#ifndef VERILATED_VADD4___024ROOT_H_
#define VERILATED_VADD4___024ROOT_H_  // guard

#include "verilated.h"

class Vadd4__Syms;

class Vadd4___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(a,3,0);
    VL_IN8(b,3,0);
    VL_IN8(ci,0,0);
    VL_OUT8(sum,3,0);
    VL_OUT8(co,0,0);
    CData/*0:0*/ add4__DOT____Vcellinp__u1____pinNumber3;
    CData/*0:0*/ add4__DOT____Vcellinp__u2____pinNumber3;
    CData/*0:0*/ add4__DOT____Vcellinp__u3____pinNumber3;
    CData/*0:0*/ add4__DOT__u0__DOT____VdfgTmp_h36175ebf__0;
    CData/*0:0*/ add4__DOT__u1__DOT____VdfgTmp_h36175ebf__0;
    CData/*0:0*/ add4__DOT__u2__DOT____VdfgTmp_h36175ebf__0;
    CData/*0:0*/ add4__DOT__u3__DOT____VdfgTmp_h36175ebf__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vadd4__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vadd4___024root(Vadd4__Syms* symsp, const char* v__name);
    ~Vadd4___024root();
    VL_UNCOPYABLE(Vadd4___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
