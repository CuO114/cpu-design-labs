// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vaxi_master_tb__pch.h"
#include "Vaxi_master_tb.h"
#include "Vaxi_master_tb___024root.h"

// FUNCTIONS
Vaxi_master_tb__Syms::~Vaxi_master_tb__Syms()
{
}

Vaxi_master_tb__Syms::Vaxi_master_tb__Syms(VerilatedContext* contextp, const char* namep, Vaxi_master_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscope_axi_master_tb.configure(this, name(), "axi_master_tb", "axi_master_tb", -9, VerilatedScope::SCOPE_OTHER);
}
