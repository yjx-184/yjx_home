// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmy_mux41.h"
#include "Vmy_mux41__Syms.h"

//============================================================
// Constructors

Vmy_mux41::Vmy_mux41(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmy_mux41__Syms(contextp(), _vcname__, this)}
    , X0{vlSymsp->TOP.X0}
    , X1{vlSymsp->TOP.X1}
    , X2{vlSymsp->TOP.X2}
    , X3{vlSymsp->TOP.X3}
    , Y{vlSymsp->TOP.Y}
    , F{vlSymsp->TOP.F}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vmy_mux41::Vmy_mux41(const char* _vcname__)
    : Vmy_mux41(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmy_mux41::~Vmy_mux41() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmy_mux41___024root___eval_debug_assertions(Vmy_mux41___024root* vlSelf);
#endif  // VL_DEBUG
void Vmy_mux41___024root___eval_static(Vmy_mux41___024root* vlSelf);
void Vmy_mux41___024root___eval_initial(Vmy_mux41___024root* vlSelf);
void Vmy_mux41___024root___eval_settle(Vmy_mux41___024root* vlSelf);
void Vmy_mux41___024root___eval(Vmy_mux41___024root* vlSelf);

void Vmy_mux41::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmy_mux41::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmy_mux41___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmy_mux41___024root___eval_static(&(vlSymsp->TOP));
        Vmy_mux41___024root___eval_initial(&(vlSymsp->TOP));
        Vmy_mux41___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmy_mux41___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmy_mux41::eventsPending() { return false; }

uint64_t Vmy_mux41::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmy_mux41::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmy_mux41___024root___eval_final(Vmy_mux41___024root* vlSelf);

VL_ATTR_COLD void Vmy_mux41::final() {
    Vmy_mux41___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmy_mux41::hierName() const { return vlSymsp->name(); }
const char* Vmy_mux41::modelName() const { return "Vmy_mux41"; }
unsigned Vmy_mux41::threads() const { return 1; }
