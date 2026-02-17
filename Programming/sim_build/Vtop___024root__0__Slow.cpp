// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__instruction_memory_inst__DOT__clk__0 
        = vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__pc_inst__DOT__clk__0 
        = vlSelfRef.cpu__DOT__pc_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__pc_inst__DOT__rst__0 
        = vlSelfRef.cpu__DOT__pc_inst__DOT__rst;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__register_file_inst__DOT__clk__0 
        = vlSelfRef.cpu__DOT__register_file_inst__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__data_memory_inst__DOT__clk__0 
        = vlSelfRef.cpu__DOT__data_memory_inst__DOT__clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___eval_initial__TOP(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial__TOP\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cpu__DOT__control_inst__DOT__alu_control = 0U;
    vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__write_data = 0U;
    vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__write_enable = 0U;
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/james/https---github.com-JamesRyanV1-RV32I-Single-Cycle-capstone/Programming/../cpu/cpu.sv", 4, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtop___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtop___024root___eval_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

VL_ATTR_COLD void Vtop___024root___stl_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cpu__DOT__input_data = vlSelfRef.input_data;
    vlSelfRef.cpu_out = vlSelfRef.cpu__DOT__cpu_out;
    vlSelfRef.cpu__DOT__clk = vlSelfRef.clk;
    vlSelfRef.cpu__DOT__rst = vlSelfRef.rst;
    vlSelfRef.cpu__DOT__pc_inst__DOT__pc_out = vlSelfRef.cpu__DOT__pc_inst__DOT__pc;
    vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__clk 
        = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__branch_unit_inst__DOT__clk 
        = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__pc_inst__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__register_file_inst__DOT__clk 
        = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__data_memory_inst__DOT__clk 
        = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__alu_inst__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__sign_extender_inst__DOT__clk 
        = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__decoder_inst__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__rst_data 
        = vlSelfRef.cpu__DOT__rst;
    vlSelfRef.cpu__DOT__pc_inst__DOT__rst = vlSelfRef.cpu__DOT__rst;
    vlSelfRef.cpu__DOT__register_file_inst__DOT__rst 
        = vlSelfRef.cpu__DOT__rst;
    vlSelfRef.cpu__DOT__data_memory_inst__DOT__rst_data 
        = vlSelfRef.cpu__DOT__rst;
    vlSelfRef.cpu__DOT__alu_inst__DOT__rst = vlSelfRef.cpu__DOT__rst;
    vlSelfRef.cpu__DOT__sign_extender_inst__DOT__rst 
        = vlSelfRef.cpu__DOT__rst;
    vlSelfRef.cpu__DOT__decoder_inst__DOT__rst = vlSelfRef.cpu__DOT__rst;
    vlSelfRef.cpu__DOT__branch_unit_inst__DOT__rst 
        = vlSelfRef.cpu__DOT__rst;
    vlSelfRef.cpu__DOT__pc_next = vlSelfRef.cpu__DOT__pc_inst__DOT__pc_out;
    vlSelfRef.cpu__DOT__register_file_inst__DOT__pc_plus_4 
        = ((IData)(4U) + vlSelfRef.cpu__DOT__pc_next);
    vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__address 
        = vlSelfRef.cpu__DOT__pc_next;
    vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__unnamedblk3__DOT__idx 
        = VL_SHIFTR_III(32,32,32, vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__address, 2U);
    vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__read_data 
        = ((0x01000000U > vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__unnamedblk3__DOT__idx)
            ? vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__mem
           [(0x00ffffffU & vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__unnamedblk3__DOT__idx)]
            : 0U);
    vlSelfRef.cpu__DOT__instruction = vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__read_data;
    vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
        = vlSelfRef.cpu__DOT__instruction;
    vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
        = vlSelfRef.cpu__DOT__instruction;
    vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode = 
        (0x0000007fU & vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction);
    vlSelfRef.cpu__DOT__decoder_inst__DOT__immediate = 0U;
    vlSelfRef.cpu__DOT__decoder_inst__DOT__inst_type = 0U;
    vlSelfRef.cpu__DOT__decoder_inst__DOT__rd = 0U;
    vlSelfRef.cpu__DOT__decoder_inst__DOT__func7 = 0U;
    vlSelfRef.cpu__DOT__decoder_inst__DOT__func3 = 0U;
    vlSelfRef.cpu__DOT__decoder_inst__DOT__imm_type = 7U;
    vlSelfRef.cpu__DOT__decoder_inst__DOT__rs1 = 0U;
    vlSelfRef.cpu__DOT__decoder_inst__DOT__rs2 = 0U;
    if ((0x00000040U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
        if ((0x00000020U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                    if ((4U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                        if ((2U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                            if ((1U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                                vlSelfRef.cpu__DOT__decoder_inst__DOT__immediate 
                                    = ((0x00080000U 
                                        & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                           >> 0x0000000cU)) 
                                       | ((0x0007f800U 
                                           & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                              >> 1U)) 
                                          | ((0x00000400U 
                                              & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                                 >> 0x0000000aU)) 
                                             | (0x000003ffU 
                                                & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                                   >> 0x15U)))));
                                vlSelfRef.cpu__DOT__decoder_inst__DOT__inst_type = 6U;
                                vlSelfRef.cpu__DOT__decoder_inst__DOT__rd 
                                    = (0x0000001fU 
                                       & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                          >> 7U));
                                vlSelfRef.cpu__DOT__decoder_inst__DOT__func7 = 0U;
                                vlSelfRef.cpu__DOT__decoder_inst__DOT__func3 = 0U;
                                vlSelfRef.cpu__DOT__decoder_inst__DOT__imm_type = 4U;
                                vlSelfRef.cpu__DOT__decoder_inst__DOT__rs1 = 0U;
                                vlSelfRef.cpu__DOT__decoder_inst__DOT__rs2 = 0U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__immediate 
                                = (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                   >> 0x14U);
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__inst_type = 7U;
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__rd 
                                = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                                  >> 7U));
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__func7 = 0U;
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__func3 = 0U;
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__imm_type = 0U;
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__rs1 
                                = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                                  >> 0x0fU));
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__rs2 = 0U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__immediate 
                            = ((((2U & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                        >> 0x0000001eU)) 
                                 | (1U & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                          >> 7U))) 
                                << 0x0000000aU) | (
                                                   (0x000003f0U 
                                                    & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                                       >> 0x00000015U)) 
                                                   | (0x0000000fU 
                                                      & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                                         >> 8U))));
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__inst_type = 5U;
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__rd = 0U;
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__func7 = 0U;
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__func3 
                            = (7U & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                     >> 0x0cU));
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__imm_type = 3U;
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__rs1 
                            = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                              >> 0x0fU));
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__rs2 
                            = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                              >> 0x14U));
                    }
                }
            }
        }
    } else if ((0x00000020U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
        if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode) 
                      >> 4U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__immediate 
                                = ((0x00000fe0U & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                                   >> 0x00000014U)) 
                                   | (0x0000001fU & 
                                      (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                       >> 7U)));
                        }
                    }
                }
            }
        }
        if ((0x00000010U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                        if ((1U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__inst_type = 3U;
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__rd 
                                = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                                  >> 7U));
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__func7 
                                = (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                   >> 0x19U);
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__func3 
                                = (7U & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                         >> 0x0cU));
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__imm_type = 2U;
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__rs1 
                                = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                                  >> 0x0fU));
                            vlSelfRef.cpu__DOT__decoder_inst__DOT__rs2 
                                = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                                  >> 0x14U));
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__inst_type = 2U;
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__rd = 0U;
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__func7 = 0U;
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__func3 
                            = (7U & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                     >> 0x0cU));
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__imm_type = 1U;
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__rs1 
                            = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                              >> 0x0fU));
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__rs2 
                            = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                              >> 0x14U));
                    }
                }
            }
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
        if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                    if ((1U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__immediate 
                            = (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                               >> 0x14U);
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__inst_type = 4U;
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__rd 
                            = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                              >> 7U));
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__func7 
                            = (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                               >> 0x19U);
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__func3 
                            = (7U & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                     >> 0x0cU));
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__imm_type = 0U;
                        vlSelfRef.cpu__DOT__decoder_inst__DOT__rs1 
                            = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                              >> 0x0fU));
                    }
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode) 
                         >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                if ((1U & (IData)(vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode))) {
                    vlSelfRef.cpu__DOT__decoder_inst__DOT__immediate 
                        = (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                           >> 0x14U);
                    vlSelfRef.cpu__DOT__decoder_inst__DOT__inst_type = 1U;
                    vlSelfRef.cpu__DOT__decoder_inst__DOT__rd 
                        = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                          >> 7U));
                    vlSelfRef.cpu__DOT__decoder_inst__DOT__func7 = 0U;
                    vlSelfRef.cpu__DOT__decoder_inst__DOT__func3 
                        = (7U & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                 >> 0x0cU));
                    vlSelfRef.cpu__DOT__decoder_inst__DOT__imm_type = 0U;
                    vlSelfRef.cpu__DOT__decoder_inst__DOT__rs1 
                        = (0x0000001fU & (vlSelfRef.cpu__DOT__decoder_inst__DOT__instruction 
                                          >> 0x0fU));
                }
            }
        }
    }
    vlSelfRef.cpu__DOT__opcode = vlSelfRef.cpu__DOT__decoder_inst__DOT__opcode;
    vlSelfRef.cpu__DOT__inst_type = vlSelfRef.cpu__DOT__decoder_inst__DOT__inst_type;
    vlSelfRef.cpu__DOT__reg_destination = vlSelfRef.cpu__DOT__decoder_inst__DOT__rd;
    vlSelfRef.cpu__DOT__func7 = vlSelfRef.cpu__DOT__decoder_inst__DOT__func7;
    vlSelfRef.cpu__DOT__func3 = vlSelfRef.cpu__DOT__decoder_inst__DOT__func3;
    vlSelfRef.cpu__DOT__imm_type = vlSelfRef.cpu__DOT__decoder_inst__DOT__imm_type;
    vlSelfRef.cpu__DOT__rs1 = vlSelfRef.cpu__DOT__decoder_inst__DOT__rs1;
    vlSelfRef.cpu__DOT__rs2 = vlSelfRef.cpu__DOT__decoder_inst__DOT__rs2;
    vlSelfRef.cpu__DOT__control_inst__DOT__op = vlSelfRef.cpu__DOT__opcode;
    vlSelfRef.cpu__DOT__register_file_inst__DOT__rd 
        = vlSelfRef.cpu__DOT__reg_destination;
    vlSelfRef.cpu__DOT__control_inst__DOT__func7 = vlSelfRef.cpu__DOT__func7;
    vlSelfRef.cpu__DOT__control_inst__DOT__func3 = vlSelfRef.cpu__DOT__func3;
    vlSelfRef.cpu__DOT__sign_extender_inst__DOT__imm_type 
        = vlSelfRef.cpu__DOT__imm_type;
    vlSelfRef.cpu__DOT__register_file_inst__DOT__rs1 
        = vlSelfRef.cpu__DOT__rs1;
    vlSelfRef.cpu__DOT__register_file_inst__DOT__rs2 
        = vlSelfRef.cpu__DOT__rs2;
    vlSelfRef.cpu__DOT__control_inst__DOT__imm_source = 0U;
    vlSelfRef.cpu__DOT__control_inst__DOT__mem_read = 0U;
    vlSelfRef.cpu__DOT__control_inst__DOT__register_source = 0U;
    vlSelfRef.cpu__DOT__control_inst__DOT__mem_write = 0U;
    vlSelfRef.cpu__DOT__control_inst__DOT__reg_write = 0U;
    vlSelfRef.cpu__DOT__control_inst__DOT__jalr_override = 0U;
    vlSelfRef.cpu__DOT__control_inst__DOT__alu_source = 0U;
    vlSelfRef.cpu__DOT__control_inst__DOT__pc_source = 0U;
    vlSelfRef.cpu__DOT__control_inst__DOT__alu_op = 0U;
    if ((0x00000040U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
        if ((0x00000020U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op) 
                          >> 4U)))) {
                if ((8U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                    if ((4U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                        if ((2U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                            if ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                                vlSelfRef.cpu__DOT__control_inst__DOT__imm_source = 4U;
                                vlSelfRef.cpu__DOT__control_inst__DOT__mem_read = 0U;
                                vlSelfRef.cpu__DOT__control_inst__DOT__register_source = 2U;
                                vlSelfRef.cpu__DOT__control_inst__DOT__mem_write = 0U;
                                vlSelfRef.cpu__DOT__control_inst__DOT__reg_write = 1U;
                                vlSelfRef.cpu__DOT__control_inst__DOT__alu_source = 0U;
                                vlSelfRef.cpu__DOT__control_inst__DOT__pc_source = 5U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                        if ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                            vlSelfRef.cpu__DOT__control_inst__DOT__imm_source = 0U;
                            vlSelfRef.cpu__DOT__control_inst__DOT__mem_read = 0U;
                            vlSelfRef.cpu__DOT__control_inst__DOT__register_source = 2U;
                            vlSelfRef.cpu__DOT__control_inst__DOT__mem_write = 0U;
                            vlSelfRef.cpu__DOT__control_inst__DOT__reg_write = 1U;
                            vlSelfRef.cpu__DOT__control_inst__DOT__alu_source = 1U;
                            vlSelfRef.cpu__DOT__control_inst__DOT__pc_source = 6U;
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                    if ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                        vlSelfRef.cpu__DOT__control_inst__DOT__imm_source = 3U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__mem_read = 0U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__mem_write = 0U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__reg_write = 0U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__alu_source = 0U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__pc_source 
                            = ((4U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))
                                ? ((2U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))
                                    ? 0U : ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))
                                             ? 4U : 3U))
                                : ((2U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))
                                    ? 0U : ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))
                                             ? 2U : 1U)));
                    }
                }
                if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op) 
                              >> 3U)))) {
                    if ((4U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                        if ((2U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                            if ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                                vlSelfRef.cpu__DOT__control_inst__DOT__jalr_override = 1U;
                            }
                        }
                    }
                    if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                            if ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                                vlSelfRef.cpu__DOT__control_inst__DOT__alu_op = 8U;
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x00000020U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
        if ((0x00000010U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op) 
                          >> 3U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                        if ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                            vlSelfRef.cpu__DOT__control_inst__DOT__imm_source = 0U;
                            vlSelfRef.cpu__DOT__control_inst__DOT__mem_read = 0U;
                            vlSelfRef.cpu__DOT__control_inst__DOT__register_source = 1U;
                            vlSelfRef.cpu__DOT__control_inst__DOT__mem_write = 0U;
                            vlSelfRef.cpu__DOT__control_inst__DOT__reg_write = 1U;
                            vlSelfRef.cpu__DOT__control_inst__DOT__alu_source = 0U;
                            vlSelfRef.cpu__DOT__control_inst__DOT__alu_op 
                                = (((((((((0U == (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                   << 3U) 
                                                  | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))) 
                                          | (0x0100U 
                                             == (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                  << 3U) 
                                                 | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))) 
                                         | (7U == (
                                                   ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                    << 3U) 
                                                   | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))) 
                                        | (6U == (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                   << 3U) 
                                                  | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))) 
                                       | (4U == (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                  << 3U) 
                                                 | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))) 
                                      | (1U == (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                 << 3U) 
                                                | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))) 
                                     | (5U == (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                << 3U) 
                                               | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))) 
                                    | (0x0105U == (
                                                   ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                    << 3U) 
                                                   | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))))
                                    ? ((0U == (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                << 3U) 
                                               | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))
                                        ? 0U : ((0x0100U 
                                                 == 
                                                 (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                   << 3U) 
                                                  | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))
                                                 ? 0U
                                                 : 
                                                ((7U 
                                                  == 
                                                  (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                    << 3U) 
                                                   | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))
                                                  ? 4U
                                                  : 
                                                 ((6U 
                                                   == 
                                                   (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                     << 3U) 
                                                    | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))
                                                   ? 5U
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                      << 3U) 
                                                     | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))
                                                    ? 6U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                       << 3U) 
                                                      | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))
                                                     ? 1U
                                                     : 
                                                    ((5U 
                                                      == 
                                                      (((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7) 
                                                        << 3U) 
                                                       | (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3)))
                                                      ? 2U
                                                      : 3U)))))))
                                    : 0U);
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op) 
                             >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                    if ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                        vlSelfRef.cpu__DOT__control_inst__DOT__imm_source = 1U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__mem_read = 0U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__mem_write = 1U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__reg_write = 0U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__alu_source = 1U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__alu_op = 0U;
                    }
                }
            }
        }
    } else if ((0x00000010U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
        if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op) 
                      >> 3U)))) {
            if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op) 
                          >> 2U)))) {
                if ((2U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                    if ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                        vlSelfRef.cpu__DOT__control_inst__DOT__imm_source = 0U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__mem_read = 0U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__register_source = 1U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__mem_write = 0U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__reg_write = 1U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__alu_source = 1U;
                        vlSelfRef.cpu__DOT__control_inst__DOT__alu_op 
                            = ((4U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))
                                ? ((2U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))
                                    ? ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))
                                        ? 4U : 5U) : 
                                   ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))
                                     ? ((0U == (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7))
                                         ? 2U : ((0x20U 
                                                  == (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func7))
                                                  ? 3U
                                                  : 0U))
                                     : 6U)) : ((2U 
                                                & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))
                                                ? 0U
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__func3))
                                                    ? 1U
                                                    : 0U)));
                    }
                }
            }
        }
    } else if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op) 
                         >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                if ((1U & (IData)(vlSelfRef.cpu__DOT__control_inst__DOT__op))) {
                    vlSelfRef.cpu__DOT__control_inst__DOT__imm_source = 0U;
                    vlSelfRef.cpu__DOT__control_inst__DOT__mem_read = 1U;
                    vlSelfRef.cpu__DOT__control_inst__DOT__register_source = 0U;
                    vlSelfRef.cpu__DOT__control_inst__DOT__mem_write = 0U;
                    vlSelfRef.cpu__DOT__control_inst__DOT__reg_write = 1U;
                    vlSelfRef.cpu__DOT__control_inst__DOT__alu_source = 1U;
                    vlSelfRef.cpu__DOT__control_inst__DOT__alu_op = 0U;
                }
            }
        }
    }
    vlSelfRef.cpu__DOT__sign_extender_inst__DOT__ext_imm 
        = ((4U & (IData)(vlSelfRef.cpu__DOT__sign_extender_inst__DOT__imm_type))
            ? ((2U & (IData)(vlSelfRef.cpu__DOT__sign_extender_inst__DOT__imm_type))
                ? 0U : ((1U & (IData)(vlSelfRef.cpu__DOT__sign_extender_inst__DOT__imm_type))
                         ? 0U : ((((0x00000ffeU & (
                                                   (- (IData)(
                                                              (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                                               >> 0x0000001fU))) 
                                                   << 1U)) 
                                   | (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                      >> 0x0000001fU)) 
                                  << 0x00000014U) | 
                                 ((((0x000001feU & 
                                     (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                      >> 0x0000000bU)) 
                                    | (1U & (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                             >> 0x00000014U))) 
                                   << 0x0000000bU) 
                                  | (0x000007feU & 
                                     (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                      >> 0x00000014U))))))
            : ((2U & (IData)(vlSelfRef.cpu__DOT__sign_extender_inst__DOT__imm_type))
                ? ((1U & (IData)(vlSelfRef.cpu__DOT__sign_extender_inst__DOT__imm_type))
                    ? (((- (IData)((vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                    >> 0x0000001fU))) 
                        << 0x0000000dU) | ((((2U & 
                                              (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                               >> 0x0000001eU)) 
                                             | (1U 
                                                & (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                                   >> 7U))) 
                                            << 0x0000000bU) 
                                           | ((0x000007e0U 
                                               & (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                                  >> 0x00000014U)) 
                                              | (0x0000001eU 
                                                 & (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                                    >> 7U)))))
                    : 0U) : ((1U & (IData)(vlSelfRef.cpu__DOT__sign_extender_inst__DOT__imm_type))
                              ? (((- (IData)((vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                              >> 0x0000001fU))) 
                                  << 0x0000000cU) | 
                                 ((0x00000fe0U & (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                                  >> 0x00000014U)) 
                                  | (0x0000001fU & 
                                     (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                      >> 7U)))) : (
                                                   ((- (IData)(
                                                               (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                                                >> 0x0000001fU))) 
                                                    << 0x0000000cU) 
                                                   | (vlSelfRef.cpu__DOT__sign_extender_inst__DOT__inst 
                                                      >> 0x00000014U)))));
    vlSelfRef.cpu__DOT__register_file_inst__DOT__rd1 
        = ((0U == (IData)(vlSelfRef.cpu__DOT__register_file_inst__DOT__rs1))
            ? 0U : vlSelfRef.cpu__DOT__register_file_inst__DOT__regs
           [vlSelfRef.cpu__DOT__register_file_inst__DOT__rs1]);
    vlSelfRef.cpu__DOT__register_file_inst__DOT__rd2 
        = ((0U == (IData)(vlSelfRef.cpu__DOT__register_file_inst__DOT__rs2))
            ? 0U : vlSelfRef.cpu__DOT__register_file_inst__DOT__regs
           [vlSelfRef.cpu__DOT__register_file_inst__DOT__rs2]);
    vlSelfRef.cpu__DOT__memRead = vlSelfRef.cpu__DOT__control_inst__DOT__mem_read;
    vlSelfRef.cpu__DOT__register_source = vlSelfRef.cpu__DOT__control_inst__DOT__register_source;
    vlSelfRef.cpu__DOT__memWrite = vlSelfRef.cpu__DOT__control_inst__DOT__mem_write;
    vlSelfRef.cpu__DOT__reg_write = vlSelfRef.cpu__DOT__control_inst__DOT__reg_write;
    vlSelfRef.cpu__DOT__override = vlSelfRef.cpu__DOT__control_inst__DOT__jalr_override;
    vlSelfRef.cpu__DOT__alu_source = vlSelfRef.cpu__DOT__control_inst__DOT__alu_source;
    vlSelfRef.cpu__DOT__pc_source = vlSelfRef.cpu__DOT__control_inst__DOT__pc_source;
    vlSelfRef.cpu__DOT__alu_ctrl = vlSelfRef.cpu__DOT__control_inst__DOT__alu_op;
    vlSelfRef.cpu__DOT__immediate = vlSelfRef.cpu__DOT__sign_extender_inst__DOT__ext_imm;
    vlSelfRef.cpu__DOT__regData1 = vlSelfRef.cpu__DOT__register_file_inst__DOT__rd1;
    vlSelfRef.cpu__DOT__regData2 = vlSelfRef.cpu__DOT__register_file_inst__DOT__rd2;
    vlSelfRef.cpu__DOT__register_file_inst__DOT__register_source 
        = vlSelfRef.cpu__DOT__register_source;
    vlSelfRef.cpu__DOT__data_memory_inst__DOT__write_enable 
        = vlSelfRef.cpu__DOT__memWrite;
    vlSelfRef.cpu__DOT__register_file_inst__DOT__enableWrite 
        = vlSelfRef.cpu__DOT__reg_write;
    vlSelfRef.cpu__DOT__pc_inst__DOT__override = vlSelfRef.cpu__DOT__override;
    vlSelfRef.cpu__DOT__alu_inst__DOT__alu_source = vlSelfRef.cpu__DOT__alu_source;
    vlSelfRef.cpu__DOT__branch_unit_inst__DOT__cntrl 
        = vlSelfRef.cpu__DOT__pc_source;
    vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl = vlSelfRef.cpu__DOT__alu_ctrl;
    vlSelfRef.cpu__DOT__pc_inst__DOT__offset = vlSelfRef.cpu__DOT__immediate;
    vlSelfRef.cpu__DOT__pc_inst__DOT__jalr_imm = vlSelfRef.cpu__DOT__immediate;
    vlSelfRef.cpu__DOT__alu_inst__DOT__immediate = vlSelfRef.cpu__DOT__immediate;
    vlSelfRef.cpu__DOT__pc_inst__DOT__rs1 = vlSelfRef.cpu__DOT__regData1;
    vlSelfRef.cpu__DOT__branch_unit_inst__DOT__d1 = vlSelfRef.cpu__DOT__regData1;
    vlSelfRef.cpu__DOT__alu_inst__DOT__d1 = vlSelfRef.cpu__DOT__regData1;
    vlSelfRef.cpu__DOT__data_memory_inst__DOT__write_data 
        = vlSelfRef.cpu__DOT__regData2;
    vlSelfRef.cpu__DOT__branch_unit_inst__DOT__d2 = vlSelfRef.cpu__DOT__regData2;
    vlSelfRef.cpu__DOT__alu_inst__DOT__rs2 = vlSelfRef.cpu__DOT__regData2;
    vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__cntrl 
        = vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl;
    vlSelfRef.cpu__DOT__alu_inst__DOT__shift_type = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl) 
                  >> 3U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl) 
                      >> 2U)))) {
            if ((2U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl))) {
                vlSelfRef.cpu__DOT__alu_inst__DOT__shift_type 
                    = ((1U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl))
                        ? 2U : 1U);
            } else if ((1U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl))) {
                vlSelfRef.cpu__DOT__alu_inst__DOT__shift_type = 0U;
            }
        }
    }
    vlSelfRef.cpu__DOT__pc_inst__DOT__jalr_target = 
        (0xfffffffeU & (vlSelfRef.cpu__DOT__pc_inst__DOT__jalr_imm 
                        + vlSelfRef.cpu__DOT__pc_inst__DOT__rs1));
    vlSelfRef.cpu__DOT__alu_inst__DOT__adder_inst__DOT__a 
        = vlSelfRef.cpu__DOT__alu_inst__DOT__d1;
    vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__a 
        = vlSelfRef.cpu__DOT__alu_inst__DOT__d1;
    vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__a 
        = vlSelfRef.cpu__DOT__alu_inst__DOT__d1;
    vlSelfRef.cpu__DOT__branch_unit_inst__DOT__take_branch 
        = (1U & ((~ (IData)(vlSelfRef.cpu__DOT__branch_unit_inst__DOT__rst)) 
                 & ((4U & (IData)(vlSelfRef.cpu__DOT__branch_unit_inst__DOT__cntrl))
                     ? ((~ ((IData)(vlSelfRef.cpu__DOT__branch_unit_inst__DOT__cntrl) 
                            >> 1U)) & ((IData)(vlSelfRef.cpu__DOT__branch_unit_inst__DOT__cntrl) 
                                       | VL_GTES_III(32, vlSelfRef.cpu__DOT__branch_unit_inst__DOT__d1, vlSelfRef.cpu__DOT__branch_unit_inst__DOT__d2)))
                     : ((2U & (IData)(vlSelfRef.cpu__DOT__branch_unit_inst__DOT__cntrl))
                         ? ((1U & (IData)(vlSelfRef.cpu__DOT__branch_unit_inst__DOT__cntrl))
                             ? VL_LTS_III(32, vlSelfRef.cpu__DOT__branch_unit_inst__DOT__d1, vlSelfRef.cpu__DOT__branch_unit_inst__DOT__d2)
                             : (vlSelfRef.cpu__DOT__branch_unit_inst__DOT__d1 
                                != vlSelfRef.cpu__DOT__branch_unit_inst__DOT__d2))
                         : ((IData)(vlSelfRef.cpu__DOT__branch_unit_inst__DOT__cntrl) 
                            & (vlSelfRef.cpu__DOT__branch_unit_inst__DOT__d1 
                               == vlSelfRef.cpu__DOT__branch_unit_inst__DOT__d2))))));
    vlSelfRef.cpu__DOT__alu_inst__DOT__d2 = ((IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__alu_source)
                                              ? vlSelfRef.cpu__DOT__alu_inst__DOT__immediate
                                              : vlSelfRef.cpu__DOT__alu_inst__DOT__rs2);
    vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_type 
        = vlSelfRef.cpu__DOT__alu_inst__DOT__shift_type;
    vlSelfRef.cpu__DOT__take_branch = vlSelfRef.cpu__DOT__branch_unit_inst__DOT__take_branch;
    vlSelfRef.cpu__DOT__alu_inst__DOT__adder_inst__DOT__b 
        = vlSelfRef.cpu__DOT__alu_inst__DOT__d2;
    vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shamt 
        = (0x0000001fU & vlSelfRef.cpu__DOT__alu_inst__DOT__d2);
    vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__b 
        = vlSelfRef.cpu__DOT__alu_inst__DOT__d2;
    vlSelfRef.cpu__DOT__pc_inst__DOT__branch = vlSelfRef.cpu__DOT__take_branch;
    vlSelfRef.cpu__DOT__alu_inst__DOT__adder_inst__DOT__sum 
        = (vlSelfRef.cpu__DOT__alu_inst__DOT__adder_inst__DOT__a 
           + vlSelfRef.cpu__DOT__alu_inst__DOT__adder_inst__DOT__b);
    vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_result 
        = ((0U == (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_type))
            ? (vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__a 
               << (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shamt))
            : ((1U == (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_type))
                ? (vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__a 
                   >> (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shamt))
                : ((2U == (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_type))
                    ? VL_SHIFTRS_III(32,32,5, vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__a, (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shamt))
                    : 0U)));
    vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__logic_output 
        = ((4U == (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__cntrl))
            ? (vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__a 
               & vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__b)
            : ((5U == (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__cntrl))
                ? (vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__a 
                   | vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__b)
                : ((6U == (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__cntrl))
                    ? (vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__a 
                       ^ vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__b)
                    : 0U)));
    vlSelfRef.cpu__DOT__alu_inst__DOT__add_result = vlSelfRef.cpu__DOT__alu_inst__DOT__adder_inst__DOT__sum;
    vlSelfRef.cpu__DOT__alu_inst__DOT__shift_result 
        = vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_result;
    vlSelfRef.cpu__DOT__alu_inst__DOT__logic_result 
        = vlSelfRef.cpu__DOT__alu_inst__DOT__logic_inst__DOT__logic_output;
    vlSelfRef.cpu__DOT__alu_inst__DOT__alu_output = 0U;
    vlSelfRef.cpu__DOT__alu_inst__DOT__zero = (0U == vlSelfRef.cpu__DOT__alu_inst__DOT__alu_output);
    vlSelfRef.cpu__DOT__alu_inst__DOT__last_bit = (1U 
                                                   & vlSelfRef.cpu__DOT__alu_inst__DOT__alu_output);
    vlSelfRef.cpu__DOT__alu_inst__DOT__alu_output = 
        ((8U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl))
          ? 0U : ((4U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl))
                   ? ((2U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl))
                       ? ((1U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl))
                           ? (VL_LTS_III(32, vlSelfRef.cpu__DOT__alu_inst__DOT__d1, vlSelfRef.cpu__DOT__alu_inst__DOT__d2)
                               ? 1U : 0U) : vlSelfRef.cpu__DOT__alu_inst__DOT__logic_result)
                       : vlSelfRef.cpu__DOT__alu_inst__DOT__logic_result)
                   : ((2U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl))
                       ? vlSelfRef.cpu__DOT__alu_inst__DOT__shift_result
                       : ((1U & (IData)(vlSelfRef.cpu__DOT__alu_inst__DOT__cntrl))
                           ? vlSelfRef.cpu__DOT__alu_inst__DOT__shift_result
                           : vlSelfRef.cpu__DOT__alu_inst__DOT__add_result))));
    vlSelfRef.cpu__DOT__alu_inst__DOT__zero = (0U == vlSelfRef.cpu__DOT__alu_inst__DOT__alu_output);
    vlSelfRef.cpu__DOT__alu_inst__DOT__last_bit = (1U 
                                                   & vlSelfRef.cpu__DOT__alu_inst__DOT__alu_output);
    vlSelfRef.cpu__DOT__alu_zero = vlSelfRef.cpu__DOT__alu_inst__DOT__zero;
    vlSelfRef.cpu__DOT__alu_last_bit = vlSelfRef.cpu__DOT__alu_inst__DOT__last_bit;
    vlSelfRef.cpu__DOT__alu_result = vlSelfRef.cpu__DOT__alu_inst__DOT__alu_output;
    vlSelfRef.cpu__DOT__control_inst__DOT__alu_zero 
        = vlSelfRef.cpu__DOT__alu_zero;
    vlSelfRef.cpu__DOT__control_inst__DOT__alu_last_bit 
        = vlSelfRef.cpu__DOT__alu_last_bit;
    vlSelfRef.cpu__DOT__register_file_inst__DOT__alu_result 
        = vlSelfRef.cpu__DOT__alu_result;
    vlSelfRef.cpu__DOT__data_memory_inst__DOT__address 
        = vlSelfRef.cpu__DOT__alu_result;
    vlSelfRef.cpu__DOT__data_memory_inst__DOT__unnamedblk3__DOT__idx 
        = VL_SHIFTR_III(32,32,32, vlSelfRef.cpu__DOT__data_memory_inst__DOT__address, 2U);
    vlSelfRef.cpu__DOT__data_memory_inst__DOT__read_data 
        = ((0x01000000U > vlSelfRef.cpu__DOT__data_memory_inst__DOT__unnamedblk3__DOT__idx)
            ? vlSelfRef.cpu__DOT__data_memory_inst__DOT__mem
           [(0x00ffffffU & vlSelfRef.cpu__DOT__data_memory_inst__DOT__unnamedblk3__DOT__idx)]
            : 0U);
    vlSelfRef.cpu__DOT__dData = vlSelfRef.cpu__DOT__data_memory_inst__DOT__read_data;
    vlSelfRef.cpu__DOT__register_file_inst__DOT__wd 
        = vlSelfRef.cpu__DOT__dData;
}

VL_ATTR_COLD void Vtop___024root___eval_stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge cpu.instruction_memory_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge cpu.pc_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge cpu.pc_inst.rst)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(posedge cpu.register_file_inst.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(posedge cpu.data_memory_inst.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->input_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1923588759227995539ull);
    vlSelf->cpu_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13444098637817323218ull);
    vlSelf->cpu__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5456728620559131056ull);
    vlSelf->cpu__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1036890782672763000ull);
    vlSelf->cpu__DOT__input_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2823786025492899096ull);
    vlSelf->cpu__DOT__cpu_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11042500167407896543ull);
    vlSelf->cpu__DOT__regData = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3973661071736944394ull);
    vlSelf->cpu__DOT__dData = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8982753614822577214ull);
    vlSelf->cpu__DOT__alu_ctrl = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16087251851447578871ull);
    vlSelf->cpu__DOT__data_address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11401522026226022857ull);
    vlSelf->cpu__DOT__reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15999734060210743814ull);
    vlSelf->cpu__DOT__inst_type = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1750695976759353934ull);
    vlSelf->cpu__DOT__imm_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17827448035177763944ull);
    vlSelf->cpu__DOT__regData1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6087999292544751732ull);
    vlSelf->cpu__DOT__regData2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9040989194382061386ull);
    vlSelf->cpu__DOT__memRead = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11003136556836275685ull);
    vlSelf->cpu__DOT__memWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2082886368590517521ull);
    vlSelf->cpu__DOT__alu_zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17161198845646111129ull);
    vlSelf->cpu__DOT__alu_last_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 400036621919628728ull);
    vlSelf->cpu__DOT__alu_source = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6534914121567284302ull);
    vlSelf->cpu__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12522730548817195188ull);
    vlSelf->cpu__DOT__instruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3676520396987702001ull);
    vlSelf->cpu__DOT__rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12318826599970682371ull);
    vlSelf->cpu__DOT__rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16010416863125722875ull);
    vlSelf->cpu__DOT__immediate = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7657775539254847072ull);
    vlSelf->cpu__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 971283180709441233ull);
    vlSelf->cpu__DOT__func3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13118965370309043891ull);
    vlSelf->cpu__DOT__func7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 16253131968242293764ull);
    vlSelf->cpu__DOT__rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11012281022938861904ull);
    vlSelf->cpu__DOT__rd_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15137657089399572166ull);
    vlSelf->cpu__DOT__take_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13470451122425122238ull);
    vlSelf->cpu__DOT__pc_source = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16370498713040622867ull);
    vlSelf->cpu__DOT__reg_destination = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 5979035607267431917ull);
    vlSelf->cpu__DOT__pc_next = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11401018961025754907ull);
    vlSelf->cpu__DOT__register_source = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 10982062309258846795ull);
    vlSelf->cpu__DOT__override = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5997717718516662694ull);
    vlSelf->cpu__DOT__instruction_memory_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14951642093827029141ull);
    vlSelf->cpu__DOT__instruction_memory_inst__DOT__address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14024145394528774012ull);
    vlSelf->cpu__DOT__instruction_memory_inst__DOT__write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7651066703335655894ull);
    vlSelf->cpu__DOT__instruction_memory_inst__DOT__write_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7293330847848702158ull);
    vlSelf->cpu__DOT__instruction_memory_inst__DOT__rst_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7331479118988361832ull);
    vlSelf->cpu__DOT__instruction_memory_inst__DOT__read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4472548508868799397ull);
    for (int __Vi0 = 0; __Vi0 < 16777216; ++__Vi0) {
        vlSelf->cpu__DOT__instruction_memory_inst__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10687643926156722897ull);
    }
    vlSelf->cpu__DOT__instruction_memory_inst__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->cpu__DOT__instruction_memory_inst__DOT__unnamedblk2__DOT__idx = 0;
    vlSelf->cpu__DOT__instruction_memory_inst__DOT__unnamedblk3__DOT__idx = 0;
    vlSelf->cpu__DOT__branch_unit_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 437938152193438527ull);
    vlSelf->cpu__DOT__branch_unit_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10149624483759812386ull);
    vlSelf->cpu__DOT__branch_unit_inst__DOT__d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15646114127378676910ull);
    vlSelf->cpu__DOT__branch_unit_inst__DOT__d2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11430323552326070909ull);
    vlSelf->cpu__DOT__branch_unit_inst__DOT__cntrl = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11182108508733225677ull);
    vlSelf->cpu__DOT__branch_unit_inst__DOT__take_branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 322670582725095667ull);
    vlSelf->cpu__DOT__pc_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6220749187723941928ull);
    vlSelf->cpu__DOT__pc_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15981658260280629282ull);
    vlSelf->cpu__DOT__pc_inst__DOT__branch = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4879220685816875158ull);
    vlSelf->cpu__DOT__pc_inst__DOT__offset = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16865491521436844320ull);
    vlSelf->cpu__DOT__pc_inst__DOT__override = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15057518696630600005ull);
    vlSelf->cpu__DOT__pc_inst__DOT__rs1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10080847585350569572ull);
    vlSelf->cpu__DOT__pc_inst__DOT__jalr_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8147025881628463135ull);
    vlSelf->cpu__DOT__pc_inst__DOT__pc_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8700401787201701408ull);
    vlSelf->cpu__DOT__pc_inst__DOT__pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1902108937650023274ull);
    vlSelf->cpu__DOT__pc_inst__DOT__jalr_target = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18094963014505474560ull);
    vlSelf->cpu__DOT__register_file_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9042641150028864991ull);
    vlSelf->cpu__DOT__register_file_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7675694688945276420ull);
    vlSelf->cpu__DOT__register_file_inst__DOT__rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 16923753964025716089ull);
    vlSelf->cpu__DOT__register_file_inst__DOT__rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2498080627110620639ull);
    vlSelf->cpu__DOT__register_file_inst__DOT__rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3524367300830631240ull);
    vlSelf->cpu__DOT__register_file_inst__DOT__register_source = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13164256463643038856ull);
    vlSelf->cpu__DOT__register_file_inst__DOT__alu_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9500776990550601111ull);
    vlSelf->cpu__DOT__register_file_inst__DOT__pc_plus_4 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7946093066297558003ull);
    vlSelf->cpu__DOT__register_file_inst__DOT__wd = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8896020815019561985ull);
    vlSelf->cpu__DOT__register_file_inst__DOT__enableWrite = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17033327448482340561ull);
    vlSelf->cpu__DOT__register_file_inst__DOT__rd1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14311704320026007130ull);
    vlSelf->cpu__DOT__register_file_inst__DOT__rd2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 202779084240563462ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->cpu__DOT__register_file_inst__DOT__regs[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9528204814512800538ull);
    }
    vlSelf->cpu__DOT__register_file_inst__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7248637153945366602ull);
    vlSelf->cpu__DOT__data_memory_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1524732246661913147ull);
    vlSelf->cpu__DOT__data_memory_inst__DOT__address = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12254086290878150462ull);
    vlSelf->cpu__DOT__data_memory_inst__DOT__write_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14807029702026821745ull);
    vlSelf->cpu__DOT__data_memory_inst__DOT__write_enable = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7625443710685205085ull);
    vlSelf->cpu__DOT__data_memory_inst__DOT__rst_data = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12922219130901175502ull);
    vlSelf->cpu__DOT__data_memory_inst__DOT__read_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9423853666446534598ull);
    for (int __Vi0 = 0; __Vi0 < 16777216; ++__Vi0) {
        vlSelf->cpu__DOT__data_memory_inst__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12358108427157226750ull);
    }
    vlSelf->cpu__DOT__data_memory_inst__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->cpu__DOT__data_memory_inst__DOT__unnamedblk2__DOT__idx = 0;
    vlSelf->cpu__DOT__data_memory_inst__DOT__unnamedblk3__DOT__idx = 0;
    vlSelf->cpu__DOT__alu_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13637354043403333114ull);
    vlSelf->cpu__DOT__alu_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17759119830351910676ull);
    vlSelf->cpu__DOT__alu_inst__DOT__alu_source = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6403359298385016425ull);
    vlSelf->cpu__DOT__alu_inst__DOT__cntrl = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10515117779334963611ull);
    vlSelf->cpu__DOT__alu_inst__DOT__d1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9741973593906596863ull);
    vlSelf->cpu__DOT__alu_inst__DOT__immediate = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18374264064885274508ull);
    vlSelf->cpu__DOT__alu_inst__DOT__rs2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13010707222945814774ull);
    vlSelf->cpu__DOT__alu_inst__DOT__alu_output = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9257741522290395642ull);
    vlSelf->cpu__DOT__alu_inst__DOT__zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14474213535884226629ull);
    vlSelf->cpu__DOT__alu_inst__DOT__last_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15397634673879318311ull);
    vlSelf->cpu__DOT__alu_inst__DOT__d2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12978859040146682017ull);
    vlSelf->cpu__DOT__alu_inst__DOT__add_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10249586743254649354ull);
    vlSelf->cpu__DOT__alu_inst__DOT__shift_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5134735416197274835ull);
    vlSelf->cpu__DOT__alu_inst__DOT__shift_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8201961302329266113ull);
    vlSelf->cpu__DOT__alu_inst__DOT__logic_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2823162319888271641ull);
    vlSelf->cpu__DOT__alu_inst__DOT__adder_inst__DOT__a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13483141882350338719ull);
    vlSelf->cpu__DOT__alu_inst__DOT__adder_inst__DOT__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8373744586397649152ull);
    vlSelf->cpu__DOT__alu_inst__DOT__adder_inst__DOT__sum = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4954094507322145883ull);
    vlSelf->cpu__DOT__alu_inst__DOT__shifter_inst__DOT__a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15391657530425682579ull);
    vlSelf->cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shamt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8422846403722108069ull);
    vlSelf->cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_type = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 597126998379003337ull);
    vlSelf->cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6110385290627758282ull);
    vlSelf->cpu__DOT__alu_inst__DOT__logic_inst__DOT__a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7798686917466374069ull);
    vlSelf->cpu__DOT__alu_inst__DOT__logic_inst__DOT__b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3081987166403922099ull);
    vlSelf->cpu__DOT__alu_inst__DOT__logic_inst__DOT__cntrl = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10859993682233989508ull);
    vlSelf->cpu__DOT__alu_inst__DOT__logic_inst__DOT__logic_output = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11639992569204156821ull);
    vlSelf->cpu__DOT__control_inst__DOT__op = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 2906538798890991069ull);
    vlSelf->cpu__DOT__control_inst__DOT__func3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3372998295519097410ull);
    vlSelf->cpu__DOT__control_inst__DOT__func7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 18407112948655853625ull);
    vlSelf->cpu__DOT__control_inst__DOT__alu_zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9588139295881377618ull);
    vlSelf->cpu__DOT__control_inst__DOT__alu_last_bit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7182210757213505323ull);
    vlSelf->cpu__DOT__control_inst__DOT__register_source = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3231655453669233859ull);
    vlSelf->cpu__DOT__control_inst__DOT__alu_control = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14287284115200819413ull);
    vlSelf->cpu__DOT__control_inst__DOT__imm_source = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8523762787846925325ull);
    vlSelf->cpu__DOT__control_inst__DOT__mem_read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8484524063767705100ull);
    vlSelf->cpu__DOT__control_inst__DOT__mem_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10030990754896460787ull);
    vlSelf->cpu__DOT__control_inst__DOT__reg_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17940136008938540705ull);
    vlSelf->cpu__DOT__control_inst__DOT__alu_source = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1081039186424228280ull);
    vlSelf->cpu__DOT__control_inst__DOT__pc_source = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6583385940502121012ull);
    vlSelf->cpu__DOT__control_inst__DOT__alu_op = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16866337657669776732ull);
    vlSelf->cpu__DOT__control_inst__DOT__jalr_override = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17468951683590183885ull);
    vlSelf->cpu__DOT__sign_extender_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14474365434017865634ull);
    vlSelf->cpu__DOT__sign_extender_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17482711458530170700ull);
    vlSelf->cpu__DOT__sign_extender_inst__DOT__inst = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4167739932164322729ull);
    vlSelf->cpu__DOT__sign_extender_inst__DOT__imm_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3337995877286938751ull);
    vlSelf->cpu__DOT__sign_extender_inst__DOT__ext_imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2398645374286955416ull);
    vlSelf->cpu__DOT__decoder_inst__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13369038602922653824ull);
    vlSelf->cpu__DOT__decoder_inst__DOT__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2906170547670587221ull);
    vlSelf->cpu__DOT__decoder_inst__DOT__instruction = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14581006568334290932ull);
    vlSelf->cpu__DOT__decoder_inst__DOT__inst_type = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17998585979126737157ull);
    vlSelf->cpu__DOT__decoder_inst__DOT__rd = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 12038061089380025624ull);
    vlSelf->cpu__DOT__decoder_inst__DOT__rs1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 13492435313822939756ull);
    vlSelf->cpu__DOT__decoder_inst__DOT__rs2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11694555372834003282ull);
    vlSelf->cpu__DOT__decoder_inst__DOT__func3 = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18040716809137085206ull);
    vlSelf->cpu__DOT__decoder_inst__DOT__func7 = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 11980901263105098520ull);
    vlSelf->cpu__DOT__decoder_inst__DOT__imm_type = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7945367755148287486ull);
    vlSelf->cpu__DOT__decoder_inst__DOT__opcode = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 6286466875906696056ull);
    vlSelf->cpu__DOT__decoder_inst__DOT__immediate = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 11848885215045776576ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__cpu__DOT__instruction_memory_inst__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9803103677105830505ull);
    vlSelf->__Vtrigprevexpr___TOP__cpu__DOT__pc_inst__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16589532391954277703ull);
    vlSelf->__Vtrigprevexpr___TOP__cpu__DOT__pc_inst__DOT__rst__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5821533658587524951ull);
    vlSelf->__Vtrigprevexpr___TOP__cpu__DOT__register_file_inst__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4817254275275703906ull);
    vlSelf->__Vtrigprevexpr___TOP__cpu__DOT__data_memory_inst__DOT__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11727419871398821292ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
