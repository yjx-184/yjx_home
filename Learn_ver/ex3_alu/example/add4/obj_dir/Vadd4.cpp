// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vadd4.h"
#include "Vadd4__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vadd4::Vadd4(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vadd4__Syms(contextp(), _vcname__, this)}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , ci{vlSymsp->TOP.ci}
    , sum{vlSymsp->TOP.sum}
    , co{vlSymsp->TOP.co}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vadd4::Vadd4(const char* _vcname__)
    : Vadd4(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vadd4::~Vadd4() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vadd4___024root___eval_debug_assertions(Vadd4___024root* vlSelf);
#endif  // VL_DEBUG
void Vadd4___024root___eval_static(Vadd4___024root* vlSelf);
void Vadd4___024root___eval_initial(Vadd4___024root* vlSelf);
void Vadd4___024root___eval_settle(Vadd4___024root* vlSelf);
void Vadd4___024root___eval(Vadd4___024root* vlSelf);

void Vadd4::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vadd4::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vadd4___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vadd4___024root___eval_static(&(vlSymsp->TOP));
        Vadd4___024root___eval_initial(&(vlSymsp->TOP));
        Vadd4___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vadd4___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vadd4::eventsPending() { return false; }

uint64_t Vadd4::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vadd4::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vadd4___024root___eval_final(Vadd4___024root* vlSelf);

VL_ATTR_COLD void Vadd4::final() {
    Vadd4___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vadd4::hierName() const { return vlSymsp->name(); }
const char* Vadd4::modelName() const { return "Vadd4"; }
unsigned Vadd4::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vadd4::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vadd4___024root__trace_init_top(Vadd4___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vadd4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vadd4___024root*>(voidSelf);
    Vadd4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vadd4___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vadd4___024root__trace_register(Vadd4___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vadd4::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vadd4::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vadd4___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
