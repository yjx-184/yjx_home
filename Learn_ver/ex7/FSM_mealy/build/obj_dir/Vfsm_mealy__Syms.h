// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VFSM_MEALY__SYMS_H_
#define VERILATED_VFSM_MEALY__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vfsm_mealy.h"

// INCLUDE MODULE CLASSES
#include "Vfsm_mealy___024root.h"

// SYMS CLASS (contains all model state)
class Vfsm_mealy__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vfsm_mealy* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vfsm_mealy___024root           TOP;

    // CONSTRUCTORS
    Vfsm_mealy__Syms(VerilatedContext* contextp, const char* namep, Vfsm_mealy* modelp);
    ~Vfsm_mealy__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
