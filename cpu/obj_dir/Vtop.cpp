// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.v", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("top.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__cpu__DOT__uart0__DOT__bitcount;
    SData/*8:0*/ __Vdly__cpu__DOT__uart0__DOT__shifter;
    // Body
    vlTOPp->__Vdly__cpu__DOT__hardware_counter0__DOT__cycles 
        = vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles;
    __Vdly__cpu__DOT__uart0__DOT__bitcount = vlTOPp->cpu__DOT__uart0__DOT__bitcount;
    __Vdly__cpu__DOT__uart0__DOT__shifter = vlTOPp->cpu__DOT__uart0__DOT__shifter;
    vlTOPp->__Vdly__cpu__DOT__hardware_counter0__DOT__cycles 
        = ((IData)(vlTOPp->rst_n) ? ((IData)(1U) + vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles)
            : 0U);
    if (vlTOPp->rst_n) {
        if (((IData)(vlTOPp->cpu__DOT__uart_we) & (~ (IData)(vlTOPp->cpu__DOT__uart0__DOT__uart_busy)))) {
            __Vdly__cpu__DOT__uart0__DOT__bitcount = 0xbU;
        }
        if (((IData)(vlTOPp->cpu__DOT__uart0__DOT__sending) 
             & (~ (vlTOPp->cpu__DOT__uart0__DOT__d 
                   >> 0x1cU)))) {
            __Vdly__cpu__DOT__uart0__DOT__bitcount 
                = (0xfU & ((IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount) 
                           - (IData)(1U)));
        }
    } else {
        __Vdly__cpu__DOT__uart0__DOT__bitcount = 0U;
    }
    if (vlTOPp->rst_n) {
        if (((IData)(vlTOPp->cpu__DOT__uart_we) & (~ (IData)(
                                                             (0U 
                                                              != 
                                                              (7U 
                                                               & ((IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount) 
                                                                  >> 1U))))))) {
            __Vdly__cpu__DOT__uart0__DOT__shifter = 
                (0x1feU & (vlTOPp->cpu__DOT__r2_data 
                           << 1U));
        }
        if (((0U != (IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount)) 
             & (~ (vlTOPp->cpu__DOT__uart0__DOT__d 
                   >> 0x1cU)))) {
            __Vdly__cpu__DOT__uart0__DOT__shifter = 
                (0x100U | (0xffU & ((IData)(vlTOPp->cpu__DOT__uart0__DOT__shifter) 
                                    >> 1U)));
            vlTOPp->cpu__DOT__uart_OUT_data = (1U & (IData)(vlTOPp->cpu__DOT__uart0__DOT__shifter));
        }
    } else {
        __Vdly__cpu__DOT__uart0__DOT__shifter = 0U;
        vlTOPp->cpu__DOT__uart_OUT_data = 1U;
    }
    vlTOPp->cpu__DOT__pc = ((IData)(vlTOPp->rst_n) ? vlTOPp->cpu__DOT__next_pc
                             : 0x8000U);
    vlTOPp->cpu__DOT__uart0__DOT__shifter = __Vdly__cpu__DOT__uart0__DOT__shifter;
    vlTOPp->cpu__DOT__uart0__DOT__bitcount = __Vdly__cpu__DOT__uart0__DOT__bitcount;
    vlTOPp->uart_tx = vlTOPp->cpu__DOT__uart_OUT_data;
    vlTOPp->cpu__DOT__uart0__DOT__uart_busy = (0U != 
                                               (7U 
                                                & ((IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount) 
                                                   >> 1U)));
    vlTOPp->cpu__DOT__uart0__DOT__sending = (0U != (IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount));
    vlTOPp->cpu__DOT__uart0__DOT__d = ((IData)(vlTOPp->rst_n)
                                        ? vlTOPp->cpu__DOT__uart0__DOT__dNxt
                                        : 0U);
    vlTOPp->cpu__DOT__uart0__DOT__dNxt = (0x1fffffffU 
                                          & (vlTOPp->cpu__DOT__uart0__DOT__d 
                                             + ((0x10000000U 
                                                 & vlTOPp->cpu__DOT__uart0__DOT__d)
                                                 ? 0x1c200U
                                                 : 0xfe37fe80U)));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__cpu__DOT__register_file0__DOT__regs__v0;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__register_file0__DOT__regs__v0;
    CData/*4:0*/ __Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v2;
    SData/*15:0*/ __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v1;
    SData/*15:0*/ __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v1;
    SData/*15:0*/ __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v2;
    IData/*31:0*/ __Vdlyvval__cpu__DOT__register_file0__DOT__regs__v0;
    IData/*31:0*/ __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v2;
    // Body
    __Vdlyvset__cpu__DOT__register_file0__DOT__regs__v0 = 0U;
    __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v0 = 0U;
    __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v1 = 0U;
    __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v2 = 0U;
    if (((((((((0x33U == (0x7fU & vlTOPp->cpu__DOT__instruction)) 
               | (0x13U == (0x7fU & vlTOPp->cpu__DOT__instruction))) 
              | (0x37U == (0x7fU & vlTOPp->cpu__DOT__instruction))) 
             | (0x17U == (0x7fU & vlTOPp->cpu__DOT__instruction))) 
            | (3U == (0x7fU & vlTOPp->cpu__DOT__instruction))) 
           | ((0x6fU == (0x7fU & vlTOPp->cpu__DOT__instruction)) 
              & (0U != (IData)(vlTOPp->cpu__DOT__dstreg_num)))) 
          | ((0x67U == (0x7fU & vlTOPp->cpu__DOT__instruction)) 
             & (0U != (IData)(vlTOPp->cpu__DOT__dstreg_num)))) 
         & (0U != (IData)(vlTOPp->cpu__DOT__dstreg_num)))) {
        __Vdlyvval__cpu__DOT__register_file0__DOT__regs__v0 
            = ((3U == (0x7fU & vlTOPp->cpu__DOT__instruction))
                ? (((0xbU == (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                    & (0xffffff00U == vlTOPp->cpu__DOT__alu_result))
                    ? vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles
                    : vlTOPp->cpu__DOT__data_out) : vlTOPp->cpu__DOT__alu_result);
        __Vdlyvset__cpu__DOT__register_file0__DOT__regs__v0 = 1U;
        __Vdlyvdim0__cpu__DOT__register_file0__DOT__regs__v0 
            = vlTOPp->cpu__DOT__dstreg_num;
    }
    if ((0x23U == (0x7fU & vlTOPp->cpu__DOT__instruction))) {
        if ((0xeU == (IData)(vlTOPp->cpu__DOT__dec_alucode))) {
            vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound1 
                = (0xffU & vlTOPp->cpu__DOT__r2_data);
            if ((0x8000U >= (0xffffU & (vlTOPp->cpu__DOT__alu_result 
                                        >> 2U)))) {
                __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v0 
                    = vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound1;
                __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v0 = 1U;
                __Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v0 
                    = vlTOPp->cpu__DOT__data_memory0__DOT__count;
                __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v0 
                    = (0xffffU & (vlTOPp->cpu__DOT__alu_result 
                                  >> 2U));
            }
        } else {
            if ((0xfU >= (IData)(vlTOPp->cpu__DOT__dec_alucode))) {
                vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound2 
                    = (0xffffU & vlTOPp->cpu__DOT__r2_data);
                if ((0x8000U >= (0xffffU & (vlTOPp->cpu__DOT__alu_result 
                                            >> 2U)))) {
                    __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v1 
                        = vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound2;
                    __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v1 = 1U;
                    __Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v1 
                        = vlTOPp->cpu__DOT__data_memory0__DOT__count;
                    __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v1 
                        = (0xffffU & (vlTOPp->cpu__DOT__alu_result 
                                      >> 2U));
                }
            } else {
                if ((0x10U == (IData)(vlTOPp->cpu__DOT__dec_alucode))) {
                    vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound3 
                        = vlTOPp->cpu__DOT__r2_data;
                    if ((0x8000U >= (0xffffU & (vlTOPp->cpu__DOT__alu_result 
                                                >> 2U)))) {
                        __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v2 
                            = vlTOPp->cpu__DOT__data_memory0__DOT____Vlvbound3;
                        __Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v2 = 1U;
                        __Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v2 
                            = (0xffffU & (vlTOPp->cpu__DOT__alu_result 
                                          >> 2U));
                    }
                }
            }
        }
    }
    if (__Vdlyvset__cpu__DOT__register_file0__DOT__regs__v0) {
        vlTOPp->cpu__DOT__register_file0__DOT__regs[__Vdlyvdim0__cpu__DOT__register_file0__DOT__regs__v0] 
            = __Vdlyvval__cpu__DOT__register_file0__DOT__regs__v0;
    }
    if (__Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v0) {
        vlTOPp->cpu__DOT__data_memory0__DOT__mem[__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v0))) 
                & vlTOPp->cpu__DOT__data_memory0__DOT__mem
                [__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v0]) 
               | ((IData)(__Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v0) 
                  << (IData)(__Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v0)));
    }
    if (__Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v1) {
        vlTOPp->cpu__DOT__data_memory0__DOT__mem[__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v1] 
            = (((~ ((IData)(0xffffU) << (IData)(__Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v1))) 
                & vlTOPp->cpu__DOT__data_memory0__DOT__mem
                [__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v1]) 
               | ((IData)(__Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v1) 
                  << (IData)(__Vdlyvlsb__cpu__DOT__data_memory0__DOT__mem__v1)));
    }
    if (__Vdlyvset__cpu__DOT__data_memory0__DOT__mem__v2) {
        vlTOPp->cpu__DOT__data_memory0__DOT__mem[__Vdlyvdim0__cpu__DOT__data_memory0__DOT__mem__v2] 
            = __Vdlyvval__cpu__DOT__data_memory0__DOT__mem__v2;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles 
        = vlTOPp->__Vdly__cpu__DOT__hardware_counter0__DOT__cycles;
    vlTOPp->cpu__DOT__instruction = ((0x8000U >= (0xffffU 
                                                  & (vlTOPp->cpu__DOT__pc 
                                                     >> 2U)))
                                      ? vlTOPp->cpu__DOT__instruction_memory0__DOT__mem
                                     [(0xffffU & (vlTOPp->cpu__DOT__pc 
                                                  >> 2U))]
                                      : 0U);
    vlTOPp->cpu__DOT__dstreg_num = (((0x63U == (0x7fU 
                                                & vlTOPp->cpu__DOT__instruction)) 
                                     | (0x23U == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction)))
                                     ? 0U : (0x1fU 
                                             & (vlTOPp->cpu__DOT__instruction 
                                                >> 7U)));
    vlTOPp->cpu__DOT__dec_alucode = ((0x13U == (0x7fU 
                                                & vlTOPp->cpu__DOT__instruction))
                                      ? ((0U == (7U 
                                                 & (vlTOPp->cpu__DOT__instruction 
                                                    >> 0xcU)))
                                          ? 0x11U : 
                                         ((2U == (7U 
                                                  & (vlTOPp->cpu__DOT__instruction 
                                                     >> 0xcU)))
                                           ? 0x13U : 
                                          ((3U == (7U 
                                                   & (vlTOPp->cpu__DOT__instruction 
                                                      >> 0xcU)))
                                            ? 0x14U
                                            : ((4U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->cpu__DOT__instruction 
                                                    >> 0xcU)))
                                                ? 0x15U
                                                : (
                                                   (6U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->cpu__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 0x16U
                                                    : 
                                                   ((7U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x17U
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x18U
                                                      : 
                                                     (((5U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            >> 0xcU))) 
                                                       & (0U 
                                                          == 
                                                          (0x7fU 
                                                           & (vlTOPp->cpu__DOT__instruction 
                                                              >> 0x19U))))
                                                       ? 0x19U
                                                       : 
                                                      (((5U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__instruction 
                                                             >> 0xcU))) 
                                                        & (0x20U 
                                                           == 
                                                           (0x7fU 
                                                            & (vlTOPp->cpu__DOT__instruction 
                                                               >> 0x19U))))
                                                        ? 0x1aU
                                                        : 0x3fU)))))))))
                                      : ((0x33U == 
                                          (0x7fU & vlTOPp->cpu__DOT__instruction))
                                          ? (((0U == 
                                               (7U 
                                                & (vlTOPp->cpu__DOT__instruction 
                                                   >> 0xcU))) 
                                              & (0U 
                                                 == 
                                                 (0x7fU 
                                                  & (vlTOPp->cpu__DOT__instruction 
                                                     >> 0x19U))))
                                              ? 0x11U
                                              : (((0U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->cpu__DOT__instruction 
                                                       >> 0xcU))) 
                                                  & (0x20U 
                                                     == 
                                                     (0x7fU 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0x19U))))
                                                  ? 0x12U
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->cpu__DOT__instruction 
                                                       >> 0xcU)))
                                                   ? 0x18U
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->cpu__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 0x13U
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x14U
                                                     : 
                                                    ((4U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x15U
                                                      : 
                                                     (((5U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            >> 0xcU))) 
                                                       & (0U 
                                                          == 
                                                          (0x7fU 
                                                           & (vlTOPp->cpu__DOT__instruction 
                                                              >> 0x19U))))
                                                       ? 0x19U
                                                       : 
                                                      (((5U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__instruction 
                                                             >> 0xcU))) 
                                                        & (0x20U 
                                                           == 
                                                           (0x7fU 
                                                            & (vlTOPp->cpu__DOT__instruction 
                                                               >> 0x19U))))
                                                        ? 0x1aU
                                                        : 
                                                       ((6U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 0x16U
                                                         : 
                                                        ((7U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->cpu__DOT__instruction 
                                                              >> 0xcU)))
                                                          ? 0x17U
                                                          : 0x3fU))))))))))
                                          : ((0x63U 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction))
                                              ? ((0U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->cpu__DOT__instruction 
                                                      >> 0xcU)))
                                                  ? 3U
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->cpu__DOT__instruction 
                                                       >> 0xcU)))
                                                   ? 4U
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->cpu__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 5U
                                                    : 
                                                   ((5U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 6U
                                                     : 
                                                    ((6U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 7U
                                                      : 
                                                     ((7U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->cpu__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 8U
                                                       : 0x3fU))))))
                                              : ((0x23U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction))
                                                  ? 
                                                 ((0U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->cpu__DOT__instruction 
                                                       >> 0xcU)))
                                                   ? 0xeU
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->cpu__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 0xfU
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x10U
                                                     : 0x3fU)))
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__instruction))
                                                   ? 
                                                  ((0U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->cpu__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 9U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0xaU
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0xbU
                                                      : 
                                                     ((4U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->cpu__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 0xcU
                                                       : 
                                                      ((5U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 0xdU
                                                        : 0x3fU)))))
                                                   : 
                                                  ((0x37U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->cpu__DOT__instruction))
                                                    ? 0U
                                                    : 
                                                   ((0x17U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->cpu__DOT__instruction))
                                                     ? 0x11U
                                                     : 
                                                    ((0x6fU 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->cpu__DOT__instruction))
                                                      ? 1U
                                                      : 
                                                     ((0x67U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->cpu__DOT__instruction))
                                                       ? 2U
                                                       : 0x3fU)))))))));
    vlTOPp->cpu__DOT__aluop1_type = (((((((0x33U == 
                                           (0x7fU & vlTOPp->cpu__DOT__instruction)) 
                                          | (0x13U 
                                             == (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction))) 
                                         | (0x23U == 
                                            (0x7fU 
                                             & vlTOPp->cpu__DOT__instruction))) 
                                        | (3U == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction))) 
                                       | (0x67U == 
                                          (0x7fU & vlTOPp->cpu__DOT__instruction))) 
                                      | (0x63U == (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction)))
                                      ? 1U : ((0x17U 
                                               == (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction))
                                               ? 2U
                                               : 0U));
    vlTOPp->cpu__DOT__aluop2_type = (((0x33U == (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction)) 
                                      | (0x63U == (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction)))
                                      ? 1U : (((((0x13U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction)) 
                                                 | (0x23U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->cpu__DOT__instruction))) 
                                                | (3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__instruction))) 
                                               | (0x37U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction)))
                                               ? 2U
                                               : ((
                                                   ((0x17U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->cpu__DOT__instruction)) 
                                                    | (0x6fU 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->cpu__DOT__instruction))) 
                                                   | (0x67U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->cpu__DOT__instruction)))
                                                   ? 3U
                                                   : 0U)));
    vlTOPp->cpu__DOT__r2_data = vlTOPp->cpu__DOT__register_file0__DOT__regs
        [((((0x33U == (0x7fU & vlTOPp->cpu__DOT__instruction)) 
            | (0x23U == (0x7fU & vlTOPp->cpu__DOT__instruction))) 
           | (0x63U == (0x7fU & vlTOPp->cpu__DOT__instruction)))
           ? (0x1fU & (vlTOPp->cpu__DOT__instruction 
                       >> 0x14U)) : 0U)];
    vlTOPp->cpu__DOT__r1_data = vlTOPp->cpu__DOT__register_file0__DOT__regs
        [((((0x37U == (0x7fU & vlTOPp->cpu__DOT__instruction)) 
            | (0x17U == (0x7fU & vlTOPp->cpu__DOT__instruction))) 
           | (0x6fU == (0x7fU & vlTOPp->cpu__DOT__instruction)))
           ? 0U : (0x1fU & (vlTOPp->cpu__DOT__instruction 
                            >> 0xfU)))];
    vlTOPp->cpu__DOT__imm = ((0x13U == (0x7fU & vlTOPp->cpu__DOT__instruction))
                              ? (((1U == (7U & (vlTOPp->cpu__DOT__instruction 
                                                >> 0xcU))) 
                                  | (5U == (7U & (vlTOPp->cpu__DOT__instruction 
                                                  >> 0xcU))))
                                  ? (0x1fU & (vlTOPp->cpu__DOT__instruction 
                                              >> 0x14U))
                                  : ((0xfffff000U & 
                                      ((- (IData)((1U 
                                                   & (vlTOPp->cpu__DOT__instruction 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                                     (0xfffU & (vlTOPp->cpu__DOT__instruction 
                                                >> 0x14U))))
                              : (((0x37U == (0x7fU 
                                             & vlTOPp->cpu__DOT__instruction)) 
                                  | (0x17U == (0x7fU 
                                               & vlTOPp->cpu__DOT__instruction)))
                                  ? (0xfffff000U & vlTOPp->cpu__DOT__instruction)
                                  : ((0x6fU == (0x7fU 
                                                & vlTOPp->cpu__DOT__instruction))
                                      ? ((0xffe00000U 
                                          & ((- (IData)(
                                                        (1U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            >> 0x1fU)))) 
                                             << 0x15U)) 
                                         | ((0x100000U 
                                             & (vlTOPp->cpu__DOT__instruction 
                                                >> 0xbU)) 
                                            | ((0xff000U 
                                                & vlTOPp->cpu__DOT__instruction) 
                                               | ((0x800U 
                                                   & (vlTOPp->cpu__DOT__instruction 
                                                      >> 9U)) 
                                                  | (0x7feU 
                                                     & (vlTOPp->cpu__DOT__instruction 
                                                        >> 0x14U))))))
                                      : (((0x67U == 
                                           (0x7fU & vlTOPp->cpu__DOT__instruction)) 
                                          | (3U == 
                                             (0x7fU 
                                              & vlTOPp->cpu__DOT__instruction)))
                                          ? ((0xfffff000U 
                                              & ((- (IData)(
                                                            (1U 
                                                             & (vlTOPp->cpu__DOT__instruction 
                                                                >> 0x1fU)))) 
                                                 << 0xcU)) 
                                             | (0xfffU 
                                                & (vlTOPp->cpu__DOT__instruction 
                                                   >> 0x14U)))
                                          : ((0x23U 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction))
                                              ? ((0xfffff000U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (vlTOPp->cpu__DOT__instruction 
                                                                    >> 0x1fU)))) 
                                                     << 0xcU)) 
                                                 | ((0xfe0U 
                                                     & (vlTOPp->cpu__DOT__instruction 
                                                        >> 0x14U)) 
                                                    | (0x1fU 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 7U))))
                                              : ((0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction))
                                                  ? 
                                                 ((0xffffe000U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->cpu__DOT__instruction 
                                                                     >> 0x1fU)))) 
                                                      << 0xdU)) 
                                                  | ((0x1000U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0x13U)) 
                                                     | ((0x800U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            << 4U)) 
                                                        | ((0x7e0U 
                                                            & (vlTOPp->cpu__DOT__instruction 
                                                               >> 0x14U)) 
                                                           | (0x1eU 
                                                              & (vlTOPp->cpu__DOT__instruction 
                                                                 >> 7U))))))
                                                  : 0U))))));
    vlTOPp->cpu__DOT__op1 = ((1U == (IData)(vlTOPp->cpu__DOT__aluop1_type))
                              ? vlTOPp->cpu__DOT__r1_data
                              : ((2U == (IData)(vlTOPp->cpu__DOT__aluop1_type))
                                  ? vlTOPp->cpu__DOT__imm
                                  : 0U));
    vlTOPp->cpu__DOT__op2 = ((1U == (IData)(vlTOPp->cpu__DOT__aluop2_type))
                              ? vlTOPp->cpu__DOT__r2_data
                              : ((2U == (IData)(vlTOPp->cpu__DOT__aluop2_type))
                                  ? vlTOPp->cpu__DOT__imm
                                  : ((3U == (IData)(vlTOPp->cpu__DOT__aluop2_type))
                                      ? vlTOPp->cpu__DOT__pc
                                      : 0U)));
    vlTOPp->cpu__DOT__br_taken = ((~ (((((((((0x11U 
                                              == (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                             | (9U 
                                                == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                            | (0xaU 
                                               == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                           | (0xbU 
                                              == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                          | (0xcU == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                         | (0xdU == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                        | (0xeU == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                       | (0xfU == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                      | (0x10U == (IData)(vlTOPp->cpu__DOT__dec_alucode)))) 
                                  & ((0x12U != (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                     & ((0U != (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                        & ((1U == (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                           | ((2U == (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                              | ((0x13U 
                                                  != (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                                 & ((0x14U 
                                                     != (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                                    & ((0x15U 
                                                        != (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                                       & ((0x16U 
                                                           != (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                                          & ((0x17U 
                                                              != (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                                             & ((0x18U 
                                                                 != (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                                                & ((0x19U 
                                                                    != (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                                                   & ((0x1aU 
                                                                       != (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                                                      & ((3U 
                                                                          == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                                          ? 
                                                                         (vlTOPp->cpu__DOT__op1 
                                                                          == vlTOPp->cpu__DOT__op2)
                                                                          : 
                                                                         ((4U 
                                                                           == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                                           ? 
                                                                          (vlTOPp->cpu__DOT__op1 
                                                                           != vlTOPp->cpu__DOT__op2)
                                                                           : 
                                                                          ((5U 
                                                                            == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                                            ? 
                                                                           VL_LTS_III(1,32,32, vlTOPp->cpu__DOT__op1, vlTOPp->cpu__DOT__op2)
                                                                            : 
                                                                           ((6U 
                                                                             == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                                             ? 
                                                                            VL_GTES_III(1,32,32, vlTOPp->cpu__DOT__op1, vlTOPp->cpu__DOT__op2)
                                                                             : 
                                                                            ((7U 
                                                                              == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                                              ? 
                                                                             (vlTOPp->cpu__DOT__op1 
                                                                              < vlTOPp->cpu__DOT__op2)
                                                                              : 
                                                                             ((8U 
                                                                               == (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                                                              & (vlTOPp->cpu__DOT__op1 
                                                                                >= vlTOPp->cpu__DOT__op2))))))))))))))))))));
    vlTOPp->cpu__DOT__alu_result = ((((((((((0x11U 
                                             == (IData)(vlTOPp->cpu__DOT__dec_alucode)) 
                                            | (9U == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                           | (0xaU 
                                              == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                          | (0xbU == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                         | (0xcU == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                        | (0xdU == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                       | (0xeU == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                      | (0xfU == (IData)(vlTOPp->cpu__DOT__dec_alucode))) 
                                     | (0x10U == (IData)(vlTOPp->cpu__DOT__dec_alucode)))
                                     ? (vlTOPp->cpu__DOT__op1 
                                        + vlTOPp->cpu__DOT__op2)
                                     : ((0x12U == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                         ? (vlTOPp->cpu__DOT__op1 
                                            - vlTOPp->cpu__DOT__op2)
                                         : ((0U == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                             ? vlTOPp->cpu__DOT__op2
                                             : ((1U 
                                                 == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                 ? 
                                                ((IData)(4U) 
                                                 + vlTOPp->cpu__DOT__op2)
                                                 : 
                                                ((2U 
                                                  == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                  ? 
                                                 ((IData)(4U) 
                                                  + vlTOPp->cpu__DOT__op2)
                                                  : 
                                                 ((0x13U 
                                                   == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                   ? 
                                                  (VL_LTS_III(1,32,32, vlTOPp->cpu__DOT__op1, vlTOPp->cpu__DOT__op2)
                                                    ? 1U
                                                    : 0U)
                                                   : 
                                                  ((0x14U 
                                                    == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                    ? 
                                                   ((vlTOPp->cpu__DOT__op1 
                                                     < vlTOPp->cpu__DOT__op2)
                                                     ? 1U
                                                     : 0U)
                                                    : 
                                                   ((0x15U 
                                                     == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                     ? 
                                                    (vlTOPp->cpu__DOT__op1 
                                                     ^ vlTOPp->cpu__DOT__op2)
                                                     : 
                                                    ((0x16U 
                                                      == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                      ? 
                                                     (vlTOPp->cpu__DOT__op1 
                                                      | vlTOPp->cpu__DOT__op2)
                                                      : 
                                                     ((0x17U 
                                                       == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                       ? 
                                                      (vlTOPp->cpu__DOT__op1 
                                                       & vlTOPp->cpu__DOT__op2)
                                                       : 
                                                      ((0x18U 
                                                        == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                        ? 
                                                       (vlTOPp->cpu__DOT__op1 
                                                        << 
                                                        (0x1fU 
                                                         & vlTOPp->cpu__DOT__op2))
                                                        : 
                                                       ((0x19U 
                                                         == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                         ? 
                                                        (vlTOPp->cpu__DOT__op1 
                                                         >> 
                                                         (0x1fU 
                                                          & vlTOPp->cpu__DOT__op2))
                                                         : 
                                                        ((0x1aU 
                                                          == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                          ? 
                                                         VL_SHIFTRS_III(32,32,5, vlTOPp->cpu__DOT__op1, 
                                                                        (0x1fU 
                                                                         & vlTOPp->cpu__DOT__op2))
                                                          : 0U)))))))))))));
    vlTOPp->cpu__DOT__next_pc = ((IData)(vlTOPp->cpu__DOT__br_taken)
                                  ? ((2U == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                      ? (vlTOPp->cpu__DOT__r1_data 
                                         + vlTOPp->cpu__DOT__imm)
                                      : (vlTOPp->cpu__DOT__pc 
                                         + vlTOPp->cpu__DOT__imm))
                                  : ((IData)(4U) + vlTOPp->cpu__DOT__pc));
    vlTOPp->cpu__DOT__uart_we = ((0xf6fff070U == vlTOPp->cpu__DOT__alu_result) 
                                 & (0x23U == (0x7fU 
                                              & vlTOPp->cpu__DOT__instruction)));
    vlTOPp->cpu__DOT__data_memory0__DOT__count = ((3U 
                                                   == 
                                                   (3U 
                                                    & vlTOPp->cpu__DOT__alu_result))
                                                   ? 0x18U
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->cpu__DOT__alu_result))
                                                    ? 0x10U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->cpu__DOT__alu_result))
                                                     ? 8U
                                                     : 0U)));
    vlTOPp->cpu__DOT__data_out = ((3U == (0x7fU & vlTOPp->cpu__DOT__instruction))
                                   ? ((9U == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                       ? ((0xffffff00U 
                                           & ((- (IData)(
                                                         (1U 
                                                          & (((0x8000U 
                                                               >= 
                                                               (0xffffU 
                                                                & (vlTOPp->cpu__DOT__alu_result 
                                                                   >> 2U)))
                                                               ? 
                                                              vlTOPp->cpu__DOT__data_memory0__DOT__mem
                                                              [
                                                              (0xffffU 
                                                               & (vlTOPp->cpu__DOT__alu_result 
                                                                  >> 2U))]
                                                               : 0U) 
                                                             >> 
                                                             (0x1fU 
                                                              & ((IData)(7U) 
                                                                 + (IData)(vlTOPp->cpu__DOT__data_memory0__DOT__count))))))) 
                                              << 8U)) 
                                          | (0xffU 
                                             & (((0x8000U 
                                                  >= 
                                                  (0xffffU 
                                                   & (vlTOPp->cpu__DOT__alu_result 
                                                      >> 2U)))
                                                  ? 
                                                 vlTOPp->cpu__DOT__data_memory0__DOT__mem
                                                 [(0xffffU 
                                                   & (vlTOPp->cpu__DOT__alu_result 
                                                      >> 2U))]
                                                  : 0U) 
                                                >> (IData)(vlTOPp->cpu__DOT__data_memory0__DOT__count))))
                                       : ((0xaU == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                           ? ((0xffff0000U 
                                               & ((- (IData)(
                                                             (1U 
                                                              & (((0x8000U 
                                                                   >= 
                                                                   (0xffffU 
                                                                    & (vlTOPp->cpu__DOT__alu_result 
                                                                       >> 2U)))
                                                                   ? 
                                                                  vlTOPp->cpu__DOT__data_memory0__DOT__mem
                                                                  [
                                                                  (0xffffU 
                                                                   & (vlTOPp->cpu__DOT__alu_result 
                                                                      >> 2U))]
                                                                   : 0U) 
                                                                 >> 
                                                                 (0x1fU 
                                                                  & ((IData)(0xfU) 
                                                                     + (IData)(vlTOPp->cpu__DOT__data_memory0__DOT__count))))))) 
                                                  << 0x10U)) 
                                              | (0xffffU 
                                                 & (((0x8000U 
                                                      >= 
                                                      (0xffffU 
                                                       & (vlTOPp->cpu__DOT__alu_result 
                                                          >> 2U)))
                                                      ? 
                                                     vlTOPp->cpu__DOT__data_memory0__DOT__mem
                                                     [
                                                     (0xffffU 
                                                      & (vlTOPp->cpu__DOT__alu_result 
                                                         >> 2U))]
                                                      : 0U) 
                                                    >> (IData)(vlTOPp->cpu__DOT__data_memory0__DOT__count))))
                                           : ((0xcU 
                                               == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                               ? (0xffU 
                                                  & (((0x8000U 
                                                       >= 
                                                       (0xffffU 
                                                        & (vlTOPp->cpu__DOT__alu_result 
                                                           >> 2U)))
                                                       ? 
                                                      vlTOPp->cpu__DOT__data_memory0__DOT__mem
                                                      [
                                                      (0xffffU 
                                                       & (vlTOPp->cpu__DOT__alu_result 
                                                          >> 2U))]
                                                       : 0U) 
                                                     >> (IData)(vlTOPp->cpu__DOT__data_memory0__DOT__count)))
                                               : ((0xdU 
                                                   == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                   ? 
                                                  (0xffffU 
                                                   & (((0x8000U 
                                                        >= 
                                                        (0xffffU 
                                                         & (vlTOPp->cpu__DOT__alu_result 
                                                            >> 2U)))
                                                        ? 
                                                       vlTOPp->cpu__DOT__data_memory0__DOT__mem
                                                       [
                                                       (0xffffU 
                                                        & (vlTOPp->cpu__DOT__alu_result 
                                                           >> 2U))]
                                                        : 0U) 
                                                      >> (IData)(vlTOPp->cpu__DOT__data_memory0__DOT__count)))
                                                   : 
                                                  ((0xbU 
                                                    == (IData)(vlTOPp->cpu__DOT__dec_alucode))
                                                    ? 
                                                   ((0x8000U 
                                                     >= 
                                                     (0xffffU 
                                                      & (vlTOPp->cpu__DOT__alu_result 
                                                         >> 2U)))
                                                     ? 
                                                    vlTOPp->cpu__DOT__data_memory0__DOT__mem
                                                    [
                                                    (0xffffU 
                                                     & (vlTOPp->cpu__DOT__alu_result 
                                                        >> 2U))]
                                                     : 0U)
                                                    : 0U)))))
                                   : 0U);
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rst_n)) & (IData)(vlTOPp->__Vclklast__TOP__rst_n)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rst_n)) & (IData)(vlTOPp->__Vclklast__TOP__rst_n)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
}
#endif  // VL_DEBUG
