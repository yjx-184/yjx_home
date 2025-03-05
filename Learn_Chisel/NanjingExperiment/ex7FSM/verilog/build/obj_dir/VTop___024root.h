// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class VTop__Syms;

class VTop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_clrn,0,0);
    VL_IN8(io_ps2_clk,0,0);
    VL_IN8(io_ps2_data,0,0);
    VL_OUT8(io_seg_out_0,7,0);
    VL_OUT8(io_seg_out_1,7,0);
    VL_OUT8(io_seg_out_2,7,0);
    VL_OUT8(io_seg_out_3,7,0);
    VL_OUT8(io_seg_out_4,7,0);
    VL_OUT8(io_seg_out_5,7,0);
    CData/*7:0*/ Top__DOT__keyboard_io_data;
    CData/*7:0*/ Top__DOT__decoder_io_ascii;
    CData/*0:0*/ Top__DOT__decoder_io_released;
    CData/*0:0*/ Top__DOT__counter_io_key_press;
    CData/*0:0*/ Top__DOT__readySync;
    CData/*0:0*/ Top__DOT__ready_p1;
    CData/*0:0*/ Top__DOT__nextdata_n;
    CData/*7:0*/ Top__DOT__data_d1;
    CData/*7:0*/ Top__DOT__key_ascii_display_reg;
    CData/*0:0*/ Top__DOT__display_en;
    CData/*0:0*/ Top__DOT___GEN_5;
    CData/*7:0*/ Top__DOT__keyboard__DOT__fifo_0;
    CData/*7:0*/ Top__DOT__keyboard__DOT__fifo_1;
    CData/*7:0*/ Top__DOT__keyboard__DOT__fifo_2;
    CData/*7:0*/ Top__DOT__keyboard__DOT__fifo_3;
    CData/*7:0*/ Top__DOT__keyboard__DOT__fifo_4;
    CData/*7:0*/ Top__DOT__keyboard__DOT__fifo_5;
    CData/*7:0*/ Top__DOT__keyboard__DOT__fifo_6;
    CData/*7:0*/ Top__DOT__keyboard__DOT__fifo_7;
    CData/*2:0*/ Top__DOT__keyboard__DOT__w_ptr;
    CData/*2:0*/ Top__DOT__keyboard__DOT__r_ptr;
    CData/*3:0*/ Top__DOT__keyboard__DOT__count;
    CData/*0:0*/ Top__DOT__keyboard__DOT__ready;
    CData/*2:0*/ Top__DOT__keyboard__DOT__ps2_clk_sync;
    CData/*2:0*/ Top__DOT__keyboard__DOT___ps2_clk_sync_T_1;
    CData/*0:0*/ Top__DOT__keyboard__DOT__sampling;
    CData/*2:0*/ Top__DOT__keyboard__DOT___r_ptr_T_1;
    CData/*0:0*/ Top__DOT__keyboard__DOT___GEN_1;
    CData/*0:0*/ Top__DOT__keyboard__DOT__valid;
    CData/*7:0*/ Top__DOT__keyboard__DOT___GEN_10;
    CData/*7:0*/ Top__DOT__keyboard__DOT___GEN_11;
    CData/*7:0*/ Top__DOT__keyboard__DOT___GEN_12;
    CData/*7:0*/ Top__DOT__keyboard__DOT___GEN_13;
    CData/*7:0*/ Top__DOT__keyboard__DOT___GEN_14;
    CData/*7:0*/ Top__DOT__keyboard__DOT___GEN_15;
    CData/*7:0*/ Top__DOT__keyboard__DOT___GEN_16;
    CData/*7:0*/ Top__DOT__keyboard__DOT___GEN_17;
    CData/*2:0*/ Top__DOT__keyboard__DOT___GEN_18;
    CData/*3:0*/ Top__DOT__keyboard__DOT___count_T_1;
    CData/*0:0*/ Top__DOT__decoder__DOT__isBreakCode;
    CData/*3:0*/ Top__DOT__counter__DOT__ones;
    CData/*3:0*/ Top__DOT__counter__DOT__tens;
    CData/*0:0*/ Top__DOT__counter__DOT__counted;
    CData/*3:0*/ Top__DOT__counter__DOT___tens_T_3;
    CData/*3:0*/ Top__DOT__counter__DOT___ones_T_1;
    CData/*0:0*/ Top__DOT__counter__DOT___GEN_2;
    CData/*0:0*/ __Vtrigrprev__TOP__clock;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ Top__DOT__keyboard__DOT__buffer;
    SData/*9:0*/ Top__DOT__keyboard__DOT___buffer_T;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VTop__Syms* const vlSymsp;

    // CONSTRUCTORS
    VTop___024root(VTop__Syms* symsp, const char* v__name);
    ~VTop___024root();
    VL_UNCOPYABLE(VTop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
