// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VTop_top__Syms.h"
#include "VTop_top.h"
#include "VTop_top___024root.h"

// FUNCTIONS
VTop_top__Syms::~VTop_top__Syms()
{
}

VTop_top__Syms::VTop_top__Syms(VerilatedContext* contextp, const char* namep, VTop_top* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
