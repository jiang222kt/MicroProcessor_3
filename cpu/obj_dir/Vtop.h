// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtop__Syms;

//----------

VL_MODULE(Vtop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_OUT8(uart_tx,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*4:0*/ cpu__DOT__dstreg_num;
    CData/*5:0*/ cpu__DOT__dec_alucode;
    CData/*1:0*/ cpu__DOT__aluop1_type;
    CData/*1:0*/ cpu__DOT__aluop2_type;
    CData/*0:0*/ cpu__DOT__br_taken;
    CData/*0:0*/ cpu__DOT__uart_we;
    CData/*0:0*/ cpu__DOT__uart_OUT_data;
    CData/*4:0*/ cpu__DOT__data_memory0__DOT__count;
    CData/*3:0*/ cpu__DOT__uart0__DOT__bitcount;
    CData/*0:0*/ cpu__DOT__uart0__DOT__uart_busy;
    CData/*0:0*/ cpu__DOT__uart0__DOT__sending;
    SData/*8:0*/ cpu__DOT__uart0__DOT__shifter;
    IData/*31:0*/ cpu__DOT__imm;
    IData/*31:0*/ cpu__DOT__op1;
    IData/*31:0*/ cpu__DOT__op2;
    IData/*31:0*/ cpu__DOT__alu_result;
    IData/*31:0*/ cpu__DOT__data_out;
    IData/*31:0*/ cpu__DOT__r1_data;
    IData/*31:0*/ cpu__DOT__r2_data;
    IData/*31:0*/ cpu__DOT__instruction;
    IData/*31:0*/ cpu__DOT__pc;
    IData/*31:0*/ cpu__DOT__next_pc;
    IData/*28:0*/ cpu__DOT__uart0__DOT__d;
    IData/*28:0*/ cpu__DOT__uart0__DOT__dNxt;
    IData/*31:0*/ cpu__DOT__hardware_counter0__DOT__cycles;
    IData/*31:0*/ cpu__DOT__register_file0__DOT__regs[32];
    IData/*31:0*/ cpu__DOT__data_memory0__DOT__mem[32769];
    IData/*31:0*/ cpu__DOT__instruction_memory0__DOT__mem[32769];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*7:0*/ cpu__DOT__data_memory0__DOT____Vlvbound1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst_n;
    SData/*15:0*/ cpu__DOT__data_memory0__DOT____Vlvbound2;
    IData/*31:0*/ cpu__DOT__data_memory0__DOT____Vlvbound3;
    IData/*31:0*/ __Vdly__cpu__DOT__hardware_counter0__DOT__cycles;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
