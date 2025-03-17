// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VAlu.h"
#include "VAlu__Syms.h"

//============================================================
// Constructors

VAlu::VAlu(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VAlu__Syms(contextp(), _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , reset{vlSymsp->TOP.reset}
    , io_op{vlSymsp->TOP.io_op}
    , io_a{vlSymsp->TOP.io_a}
    , io_b{vlSymsp->TOP.io_b}
    , io_carry{vlSymsp->TOP.io_carry}
    , io_zero{vlSymsp->TOP.io_zero}
    , io_overflow{vlSymsp->TOP.io_overflow}
    , io_result{vlSymsp->TOP.io_result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VAlu::VAlu(const char* _vcname__)
    : VAlu(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VAlu::~VAlu() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VAlu___024root___eval_debug_assertions(VAlu___024root* vlSelf);
#endif  // VL_DEBUG
void VAlu___024root___eval_static(VAlu___024root* vlSelf);
void VAlu___024root___eval_initial(VAlu___024root* vlSelf);
void VAlu___024root___eval_settle(VAlu___024root* vlSelf);
void VAlu___024root___eval(VAlu___024root* vlSelf);

void VAlu::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAlu::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VAlu___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VAlu___024root___eval_static(&(vlSymsp->TOP));
        VAlu___024root___eval_initial(&(vlSymsp->TOP));
        VAlu___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VAlu___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VAlu::eventsPending() { return false; }

uint64_t VAlu::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VAlu::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VAlu___024root___eval_final(VAlu___024root* vlSelf);

VL_ATTR_COLD void VAlu::final() {
    VAlu___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VAlu::hierName() const { return vlSymsp->name(); }
const char* VAlu::modelName() const { return "VAlu"; }
unsigned VAlu::threads() const { return 1; }
