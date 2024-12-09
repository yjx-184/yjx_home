// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(clrn,0,0);
    VL_IN8(ps2_clk,0,0);
    VL_IN8(ps2_data,0,0);
    VL_OUT8(hsync,0,0);
    VL_OUT8(vsync,0,0);
    VL_OUT8(vga_r,7,0);
    VL_OUT8(vga_g,7,0);
    VL_OUT8(vga_b,7,0);
    CData/*7:0*/ top__DOT__ascii_data;
    CData/*7:0*/ top__DOT__ascii_distinguish;
    CData/*0:0*/ top__DOT__key_release;
    CData/*0:0*/ top__DOT__ready;
    CData/*0:0*/ top__DOT__overflow_signal;
    CData/*3:0*/ top__DOT__char_count;
    CData/*0:0*/ top__DOT__ps2_kb__DOT__nextdata_n;
    CData/*2:0*/ top__DOT__ps2_kb__DOT__w_ptr;
    CData/*2:0*/ top__DOT__ps2_kb__DOT__r_ptr;
    CData/*3:0*/ top__DOT__ps2_kb__DOT__count;
    CData/*2:0*/ top__DOT__ps2_kb__DOT__ps2_clk_sync;
    CData/*0:0*/ top__DOT__ps2_kb__DOT____Vlvbound_h1a91ade8__0;
    CData/*7:0*/ top__DOT__ps2_dist__DOT__ascii_result;
    CData/*0:0*/ __Vdly__top__DOT__ready;
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__clrn;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ top__DOT__x;
    SData/*9:0*/ top__DOT__y;
    SData/*9:0*/ top__DOT__ps2_kb__DOT__buffer;
    SData/*9:0*/ top__DOT__u_vga_ctrl__DOT__x_cnt;
    SData/*9:0*/ top__DOT__u_vga_ctrl__DOT__y_cnt;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 8> top__DOT__ps2_kb__DOT__fifo;
    VlUnpacked<CData/*7:0*/, 36> top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__key_list;
    VlUnpacked<CData/*7:0*/, 36> top__DOT__ps2_dist__DOT__key_ascii__DOT__i0__DOT__data_list;
    VlUnpacked<CData/*6:0*/, 7> top__DOT__char_display_inst__DOT__font_A;
    VlUnpacked<CData/*6:0*/, 7> top__DOT__char_display_inst__DOT__font_B;
    VlUnpacked<CData/*6:0*/, 7> top__DOT__char_display_inst__DOT__font_C;
    VlUnpacked<CData/*6:0*/, 7> top__DOT__char_display_inst__DOT__font_D;
    VlUnpacked<CData/*6:0*/, 7> top__DOT__char_display_inst__DOT__current_font;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* v__name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
