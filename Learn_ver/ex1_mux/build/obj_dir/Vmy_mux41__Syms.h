// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VMY_MUX41__SYMS_H_
#define VERILATED_VMY_MUX41__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vmy_mux41.h"

// INCLUDE MODULE CLASSES
#include "Vmy_mux41___024root.h"

// SYMS CLASS (contains all model state)
class Vmy_mux41__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vmy_mux41* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vmy_mux41___024root            TOP;

    // CONSTRUCTORS
    Vmy_mux41__Syms(VerilatedContext* contextp, const char* namep, Vmy_mux41* modelp);
    ~Vmy_mux41__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
