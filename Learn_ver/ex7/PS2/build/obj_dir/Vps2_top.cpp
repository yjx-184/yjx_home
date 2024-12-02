// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vps2_top.h"
#include "Vps2_top__Syms.h"

//============================================================
// Constructors

Vps2_top::Vps2_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vps2_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , clrn{vlSymsp->TOP.clrn}
    , ps2_clk{vlSymsp->TOP.ps2_clk}
    , ps2_data{vlSymsp->TOP.ps2_data}
    , seg_out_0{vlSymsp->TOP.seg_out_0}
    , seg_out_1{vlSymsp->TOP.seg_out_1}
    , seg_out_2{vlSymsp->TOP.seg_out_2}
    , seg_out_3{vlSymsp->TOP.seg_out_3}
    , seg_out_4{vlSymsp->TOP.seg_out_4}
    , seg_out_5{vlSymsp->TOP.seg_out_5}
    , overflow{vlSymsp->TOP.overflow}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vps2_top::Vps2_top(const char* _vcname__)
    : Vps2_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vps2_top::~Vps2_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vps2_top___024root___eval_debug_assertions(Vps2_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vps2_top___024root___eval_static(Vps2_top___024root* vlSelf);
void Vps2_top___024root___eval_initial(Vps2_top___024root* vlSelf);
void Vps2_top___024root___eval_settle(Vps2_top___024root* vlSelf);
void Vps2_top___024root___eval(Vps2_top___024root* vlSelf);

void Vps2_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vps2_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vps2_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vps2_top___024root___eval_static(&(vlSymsp->TOP));
        Vps2_top___024root___eval_initial(&(vlSymsp->TOP));
        Vps2_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vps2_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vps2_top::eventsPending() { return false; }

uint64_t Vps2_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vps2_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vps2_top___024root___eval_final(Vps2_top___024root* vlSelf);

VL_ATTR_COLD void Vps2_top::final() {
    Vps2_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vps2_top::hierName() const { return vlSymsp->name(); }
const char* Vps2_top::modelName() const { return "Vps2_top"; }
unsigned Vps2_top::threads() const { return 1; }
