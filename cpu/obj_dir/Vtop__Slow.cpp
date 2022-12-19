// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*479:0*/ __Vtemp1[15];
    WData/*479:0*/ __Vtemp2[15];
    // Body
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x64617461U;
    __Vtemp1[2U] = 0x7369732fU;
    __Vtemp1[3U] = 0x6e746865U;
    __Vtemp1[4U] = 0x725f5379U;
    __Vtemp1[5U] = 0x6b5f666fU;
    __Vtemp1[6U] = 0x656d6172U;
    __Vtemp1[7U] = 0x2f436f72U;
    __Vtemp1[8U] = 0x61726b73U;
    __Vtemp1[9U] = 0x6e63686dU;
    __Vtemp1[0xaU] = 0x702f6265U;
    __Vtemp1[0xbU] = 0x62336578U;
    __Vtemp1[0xcU] = 0x6e6a6f2fU;
    __Vtemp1[0xdU] = 0x652f6465U;
    __Vtemp1[0xeU] = 0x2f686f6dU;
    VL_READMEM_N(true, 32, 32769, 0, VL_CVT_PACK_STR_NW(15, __Vtemp1)
                 , vlTOPp->cpu__DOT__data_memory0__DOT__mem
                 , 0, ~0ULL);
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[1U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[2U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[3U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[4U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[5U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[6U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[7U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[8U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[9U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0xaU] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0xbU] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0xcU] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0xdU] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0xeU] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0xfU] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x10U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x11U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x12U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x13U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x14U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x15U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x16U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x17U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x18U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x19U] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x1aU] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x1bU] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x1cU] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x1dU] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x1eU] = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__regs[0x1fU] = 0U;
    __Vtemp2[0U] = 0x2e686578U;
    __Vtemp2[1U] = 0x636f6465U;
    __Vtemp2[2U] = 0x7369732fU;
    __Vtemp2[3U] = 0x6e746865U;
    __Vtemp2[4U] = 0x725f5379U;
    __Vtemp2[5U] = 0x6b5f666fU;
    __Vtemp2[6U] = 0x656d6172U;
    __Vtemp2[7U] = 0x2f436f72U;
    __Vtemp2[8U] = 0x61726b73U;
    __Vtemp2[9U] = 0x6e63686dU;
    __Vtemp2[0xaU] = 0x702f6265U;
    __Vtemp2[0xbU] = 0x62336578U;
    __Vtemp2[0xcU] = 0x6e6a6f2fU;
    __Vtemp2[0xdU] = 0x652f6465U;
    __Vtemp2[0xeU] = 0x2f686f6dU;
    VL_READMEM_N(true, 32, 32769, 0, VL_CVT_PACK_STR_NW(15, __Vtemp2)
                 , vlTOPp->cpu__DOT__instruction_memory0__DOT__mem
                 , 0, ~0ULL);
}

void Vtop::_settle__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->uart_tx = vlTOPp->cpu__DOT__uart_OUT_data;
    vlTOPp->cpu__DOT__uart0__DOT__uart_busy = (0U != 
                                               (7U 
                                                & ((IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount) 
                                                   >> 1U)));
    vlTOPp->cpu__DOT__uart0__DOT__sending = (0U != (IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount));
    vlTOPp->cpu__DOT__uart0__DOT__dNxt = (0x1fffffffU 
                                          & (vlTOPp->cpu__DOT__uart0__DOT__d 
                                             + ((0x10000000U 
                                                 & vlTOPp->cpu__DOT__uart0__DOT__d)
                                                 ? 0x1c200U
                                                 : 0xfe37fe80U)));
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

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst_n = VL_RAND_RESET_I(1);
    uart_tx = VL_RAND_RESET_I(1);
    cpu__DOT__dstreg_num = VL_RAND_RESET_I(5);
    cpu__DOT__imm = VL_RAND_RESET_I(32);
    cpu__DOT__dec_alucode = VL_RAND_RESET_I(6);
    cpu__DOT__aluop1_type = VL_RAND_RESET_I(2);
    cpu__DOT__aluop2_type = VL_RAND_RESET_I(2);
    cpu__DOT__op1 = VL_RAND_RESET_I(32);
    cpu__DOT__op2 = VL_RAND_RESET_I(32);
    cpu__DOT__alu_result = VL_RAND_RESET_I(32);
    cpu__DOT__br_taken = VL_RAND_RESET_I(1);
    cpu__DOT__data_out = VL_RAND_RESET_I(32);
    cpu__DOT__r1_data = VL_RAND_RESET_I(32);
    cpu__DOT__r2_data = VL_RAND_RESET_I(32);
    cpu__DOT__instruction = VL_RAND_RESET_I(32);
    cpu__DOT__pc = VL_RAND_RESET_I(32);
    cpu__DOT__next_pc = VL_RAND_RESET_I(32);
    cpu__DOT__uart_we = VL_RAND_RESET_I(1);
    cpu__DOT__uart_OUT_data = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            cpu__DOT__register_file0__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<32769; ++__Vi0) {
            cpu__DOT__data_memory0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    cpu__DOT__data_memory0__DOT__count = VL_RAND_RESET_I(5);
    cpu__DOT__data_memory0__DOT____Vlvbound1 = VL_RAND_RESET_I(8);
    cpu__DOT__data_memory0__DOT____Vlvbound2 = VL_RAND_RESET_I(16);
    cpu__DOT__data_memory0__DOT____Vlvbound3 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32769; ++__Vi0) {
            cpu__DOT__instruction_memory0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    cpu__DOT__uart0__DOT__bitcount = VL_RAND_RESET_I(4);
    cpu__DOT__uart0__DOT__shifter = VL_RAND_RESET_I(9);
    cpu__DOT__uart0__DOT__uart_busy = VL_RAND_RESET_I(1);
    cpu__DOT__uart0__DOT__sending = VL_RAND_RESET_I(1);
    cpu__DOT__uart0__DOT__d = VL_RAND_RESET_I(29);
    cpu__DOT__uart0__DOT__dNxt = VL_RAND_RESET_I(29);
    cpu__DOT__hardware_counter0__DOT__cycles = VL_RAND_RESET_I(32);
    __Vdly__cpu__DOT__hardware_counter0__DOT__cycles = VL_RAND_RESET_I(32);
}
