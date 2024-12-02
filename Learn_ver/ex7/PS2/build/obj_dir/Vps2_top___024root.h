// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vps2_top.h for the primary calling header

#ifndef VERILATED_VPS2_TOP___024ROOT_H_
#define VERILATED_VPS2_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vps2_top__Syms;

class Vps2_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(clrn,0,0);
    CData/*0:0*/ ps2_top__DOT__en;
    VL_IN8(ps2_clk,0,0);
    VL_IN8(ps2_data,0,0);
    VL_OUT8(seg_out_0,7,0);
    VL_OUT8(seg_out_1,7,0);
    VL_OUT8(seg_out_2,7,0);
    VL_OUT8(seg_out_3,7,0);
    VL_OUT8(seg_out_4,7,0);
    VL_OUT8(seg_out_5,7,0);
    VL_OUT8(overflow,0,0);
    CData/*7:0*/ ps2_top__DOT__data;
    CData/*0:0*/ ps2_top__DOT__ready;
    CData/*0:0*/ ps2_top__DOT__ready_p1;
    CData/*0:0*/ ps2_top__DOT__ready_d1;
    CData/*0:0*/ ps2_top__DOT__nextdata_n;
    CData/*7:0*/ ps2_top__DOT__data_d1;
    CData/*0:0*/ ps2_top__DOT__key_release;
    CData/*7:0*/ ps2_top__DOT__ascii;
    CData/*3:0*/ ps2_top__DOT__high_tens;
    CData/*3:0*/ ps2_top__DOT__high_units;
    CData/*7:0*/ ps2_top__DOT__key_scan_display;
    CData/*7:0*/ ps2_top__DOT__key_ascii_display;
    CData/*2:0*/ ps2_top__DOT__u0_ps2_kb__DOT__w_ptr;
    CData/*2:0*/ ps2_top__DOT__u0_ps2_kb__DOT__r_ptr;
    CData/*3:0*/ ps2_top__DOT__u0_ps2_kb__DOT__count;
    CData/*2:0*/ ps2_top__DOT__u0_ps2_kb__DOT__ps2_clk_sync;
    CData/*0:0*/ ps2_top__DOT__u0_ps2_kb__DOT____Vlvbound_h1a91ade8__0;
    CData/*7:0*/ ps2_top__DOT__u1_ps2_dsh__DOT__ascii_result;
    CData/*0:0*/ ps2_top__DOT__u2_ps2_cer__DOT__counted;
    CData/*0:0*/ __Vdly__ps2_top__DOT__ready;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__clrn;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ ps2_top__DOT__u0_ps2_kb__DOT__buffer;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> ps2_top__DOT__u0_ps2_kb__DOT__fifo;
    VlUnpacked<CData/*7:0*/, 36> ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__key_list;
    VlUnpacked<CData/*7:0*/, 36> ps2_top__DOT__u1_ps2_dsh__DOT__key_ascii__DOT__i0__DOT__data_list;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vps2_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vps2_top___024root(Vps2_top__Syms* symsp, const char* v__name);
    ~Vps2_top___024root();
    VL_UNCOPYABLE(Vps2_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
