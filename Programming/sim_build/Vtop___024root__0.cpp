// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
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
    vlSelfRef.cpu__DOT__pc_inst__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__register_file_inst__DOT__clk 
        = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__data_memory_inst__DOT__clk 
        = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__branch_unit_inst__DOT__clk 
        = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__alu_inst__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__sign_extender_inst__DOT__clk 
        = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__decoder_inst__DOT__clk = vlSelfRef.cpu__DOT__clk;
    vlSelfRef.cpu__DOT__pc_inst__DOT__rst = vlSelfRef.cpu__DOT__rst;
    vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__rst_data 
        = vlSelfRef.cpu__DOT__rst;
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

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.cpu__DOT__data_memory_inst__DOT__clk) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__data_memory_inst__DOT__clk__0))) 
                                                      << 4U) 
                                                     | (((((IData)(vlSelfRef.cpu__DOT__register_file_inst__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__register_file_inst__DOT__clk__0))) 
                                                          << 3U) 
                                                         | (((IData)(vlSelfRef.cpu__DOT__pc_inst__DOT__rst) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__pc_inst__DOT__rst__0))) 
                                                            << 2U)) 
                                                        | ((((IData)(vlSelfRef.cpu__DOT__pc_inst__DOT__clk) 
                                                             & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__pc_inst__DOT__clk__0))) 
                                                            << 1U) 
                                                           | ((IData)(vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__clk) 
                                                              & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__cpu__DOT__instruction_memory_inst__DOT__clk__0))))))));
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
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__cpu__DOT__pc_inst__DOT__pc;
    __Vdly__cpu__DOT__pc_inst__DOT__pc = 0;
    // Body
    __Vdly__cpu__DOT__pc_inst__DOT__pc = vlSelfRef.cpu__DOT__pc_inst__DOT__pc;
    if (vlSelfRef.cpu__DOT__pc_inst__DOT__rst) {
        __Vdly__cpu__DOT__pc_inst__DOT__pc = 0U;
    } else if (vlSelfRef.cpu__DOT__pc_inst__DOT__override) {
        __Vdly__cpu__DOT__pc_inst__DOT__pc = vlSelfRef.cpu__DOT__pc_inst__DOT__jalr_target;
    } else if (vlSelfRef.cpu__DOT__pc_inst__DOT__branch) {
        __Vdly__cpu__DOT__pc_inst__DOT__pc = ((IData)(4U) 
                                              + (vlSelfRef.cpu__DOT__pc_inst__DOT__pc 
                                                 + vlSelfRef.cpu__DOT__pc_inst__DOT__offset));
    } else if ((1U & (~ (IData)(vlSelfRef.cpu__DOT__pc_inst__DOT__branch)))) {
        __Vdly__cpu__DOT__pc_inst__DOT__pc = ((IData)(4U) 
                                              + vlSelfRef.cpu__DOT__pc_inst__DOT__pc);
    }
    vlSelfRef.cpu__DOT__pc_inst__DOT__pc = __Vdly__cpu__DOT__pc_inst__DOT__pc;
    vlSelfRef.cpu__DOT__pc_inst__DOT__pc_out = vlSelfRef.cpu__DOT__pc_inst__DOT__pc;
    vlSelfRef.cpu__DOT__pc_next = vlSelfRef.cpu__DOT__pc_inst__DOT__pc_out;
}

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*23:0*/ __VdlyDim0__cpu__DOT__data_memory_inst__DOT__mem__v0;
    __VdlyDim0__cpu__DOT__data_memory_inst__DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__cpu__DOT__data_memory_inst__DOT__mem__v1;
    __VdlyVal__cpu__DOT__data_memory_inst__DOT__mem__v1 = 0;
    IData/*23:0*/ __VdlyDim0__cpu__DOT__data_memory_inst__DOT__mem__v1;
    __VdlyDim0__cpu__DOT__data_memory_inst__DOT__mem__v1 = 0;
    // Body
    if (vlSelfRef.cpu__DOT__data_memory_inst__DOT__rst_data) {
        vlSelfRef.cpu__DOT__data_memory_inst__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x01000000U, vlSelfRef.cpu__DOT__data_memory_inst__DOT__unnamedblk1__DOT__i)) {
            __VdlyDim0__cpu__DOT__data_memory_inst__DOT__mem__v0 
                = (0x00ffffffU & vlSelfRef.cpu__DOT__data_memory_inst__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueuecpu__DOT__data_memory_inst__DOT__mem.enqueue(0U, __VdlyDim0__cpu__DOT__data_memory_inst__DOT__mem__v0);
            vlSelfRef.cpu__DOT__data_memory_inst__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.cpu__DOT__data_memory_inst__DOT__unnamedblk1__DOT__i);
        }
    } else if (vlSelfRef.cpu__DOT__data_memory_inst__DOT__write_enable) {
        vlSelfRef.cpu__DOT__data_memory_inst__DOT__unnamedblk2__DOT__idx 
            = VL_SHIFTR_III(32,32,32, vlSelfRef.cpu__DOT__data_memory_inst__DOT__address, 2U);
        if (((0U != vlSelfRef.cpu__DOT__data_memory_inst__DOT__address) 
             & (0x01000000U > vlSelfRef.cpu__DOT__data_memory_inst__DOT__unnamedblk2__DOT__idx))) {
            __VdlyVal__cpu__DOT__data_memory_inst__DOT__mem__v1 
                = vlSelfRef.cpu__DOT__data_memory_inst__DOT__write_data;
            __VdlyDim0__cpu__DOT__data_memory_inst__DOT__mem__v1 
                = (0x00ffffffU & vlSelfRef.cpu__DOT__data_memory_inst__DOT__unnamedblk2__DOT__idx);
            vlSelfRef.__VdlyCommitQueuecpu__DOT__data_memory_inst__DOT__mem.enqueue(__VdlyVal__cpu__DOT__data_memory_inst__DOT__mem__v1, __VdlyDim0__cpu__DOT__data_memory_inst__DOT__mem__v1);
        }
    }
    vlSelfRef.__VdlyCommitQueuecpu__DOT__data_memory_inst__DOT__mem.commit(vlSelfRef.cpu__DOT__data_memory_inst__DOT__mem);
}

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*4:0*/ __VdlyDim0__cpu__DOT__register_file_inst__DOT__regs__v0;
    __VdlyDim0__cpu__DOT__register_file_inst__DOT__regs__v0 = 0;
    IData/*31:0*/ __VdlyVal__cpu__DOT__register_file_inst__DOT__regs__v1;
    __VdlyVal__cpu__DOT__register_file_inst__DOT__regs__v1 = 0;
    CData/*4:0*/ __VdlyDim0__cpu__DOT__register_file_inst__DOT__regs__v1;
    __VdlyDim0__cpu__DOT__register_file_inst__DOT__regs__v1 = 0;
    // Body
    if (vlSelfRef.cpu__DOT__register_file_inst__DOT__rst) {
        vlSelfRef.cpu__DOT__register_file_inst__DOT__i = 0U;
        while (VL_GTS_III(32, 0x00000020U, vlSelfRef.cpu__DOT__register_file_inst__DOT__i)) {
            __VdlyDim0__cpu__DOT__register_file_inst__DOT__regs__v0 
                = (0x0000001fU & vlSelfRef.cpu__DOT__register_file_inst__DOT__i);
            vlSelfRef.__VdlyCommitQueuecpu__DOT__register_file_inst__DOT__regs.enqueue(0U, (IData)(__VdlyDim0__cpu__DOT__register_file_inst__DOT__regs__v0));
            vlSelfRef.cpu__DOT__register_file_inst__DOT__i 
                = ((IData)(1U) + vlSelfRef.cpu__DOT__register_file_inst__DOT__i);
        }
    } else if (((IData)(vlSelfRef.cpu__DOT__register_file_inst__DOT__enableWrite) 
                & (0U != (IData)(vlSelfRef.cpu__DOT__register_file_inst__DOT__rd)))) {
        __VdlyVal__cpu__DOT__register_file_inst__DOT__regs__v1 
            = ((0U == (IData)(vlSelfRef.cpu__DOT__register_file_inst__DOT__register_source))
                ? vlSelfRef.cpu__DOT__register_file_inst__DOT__wd
                : ((1U == (IData)(vlSelfRef.cpu__DOT__register_file_inst__DOT__register_source))
                    ? vlSelfRef.cpu__DOT__register_file_inst__DOT__alu_result
                    : ((2U == (IData)(vlSelfRef.cpu__DOT__register_file_inst__DOT__register_source))
                        ? vlSelfRef.cpu__DOT__register_file_inst__DOT__pc_plus_4
                        : vlSelfRef.cpu__DOT__register_file_inst__DOT__wd)));
        __VdlyDim0__cpu__DOT__register_file_inst__DOT__regs__v1 
            = vlSelfRef.cpu__DOT__register_file_inst__DOT__rd;
        vlSelfRef.__VdlyCommitQueuecpu__DOT__register_file_inst__DOT__regs.enqueue(__VdlyVal__cpu__DOT__register_file_inst__DOT__regs__v1, (IData)(__VdlyDim0__cpu__DOT__register_file_inst__DOT__regs__v1));
    }
    vlSelfRef.__VdlyCommitQueuecpu__DOT__register_file_inst__DOT__regs.commit(vlSelfRef.cpu__DOT__register_file_inst__DOT__regs);
}

void Vtop___024root___nba_sequent__TOP__3(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*23:0*/ __VdlyDim0__cpu__DOT__instruction_memory_inst__DOT__mem__v0;
    __VdlyDim0__cpu__DOT__instruction_memory_inst__DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__cpu__DOT__instruction_memory_inst__DOT__mem__v1;
    __VdlyVal__cpu__DOT__instruction_memory_inst__DOT__mem__v1 = 0;
    IData/*23:0*/ __VdlyDim0__cpu__DOT__instruction_memory_inst__DOT__mem__v1;
    __VdlyDim0__cpu__DOT__instruction_memory_inst__DOT__mem__v1 = 0;
    // Body
    if (vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__rst_data) {
        vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__unnamedblk1__DOT__i = 0U;
        while (VL_GTS_III(32, 0x01000000U, vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__unnamedblk1__DOT__i)) {
            __VdlyDim0__cpu__DOT__instruction_memory_inst__DOT__mem__v0 
                = (0x00ffffffU & vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueuecpu__DOT__instruction_memory_inst__DOT__mem.enqueue(0U, __VdlyDim0__cpu__DOT__instruction_memory_inst__DOT__mem__v0);
            vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__unnamedblk1__DOT__i);
        }
    } else if (vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__write_enable) {
        vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__unnamedblk2__DOT__idx 
            = VL_SHIFTR_III(32,32,32, vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__address, 2U);
        if (((0U != vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__address) 
             & (0x01000000U > vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__unnamedblk2__DOT__idx))) {
            __VdlyVal__cpu__DOT__instruction_memory_inst__DOT__mem__v1 
                = vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__write_data;
            __VdlyDim0__cpu__DOT__instruction_memory_inst__DOT__mem__v1 
                = (0x00ffffffU & vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__unnamedblk2__DOT__idx);
            vlSelfRef.__VdlyCommitQueuecpu__DOT__instruction_memory_inst__DOT__mem.enqueue(__VdlyVal__cpu__DOT__instruction_memory_inst__DOT__mem__v1, __VdlyDim0__cpu__DOT__instruction_memory_inst__DOT__mem__v1);
        }
    }
    vlSelfRef.__VdlyCommitQueuecpu__DOT__instruction_memory_inst__DOT__mem.commit(vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__mem);
}

void Vtop___024root___nba_sequent__TOP__4(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cpu__DOT__register_file_inst__DOT__pc_plus_4 
        = ((IData)(4U) + vlSelfRef.cpu__DOT__pc_next);
    vlSelfRef.cpu__DOT__instruction_memory_inst__DOT__address 
        = vlSelfRef.cpu__DOT__pc_next;
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
    vlSelfRef.cpu__DOT__memRead = vlSelfRef.cpu__DOT__control_inst__DOT__mem_read;
    vlSelfRef.cpu__DOT__register_source = vlSelfRef.cpu__DOT__control_inst__DOT__register_source;
    vlSelfRef.cpu__DOT__memWrite = vlSelfRef.cpu__DOT__control_inst__DOT__mem_write;
    vlSelfRef.cpu__DOT__reg_write = vlSelfRef.cpu__DOT__control_inst__DOT__reg_write;
    vlSelfRef.cpu__DOT__override = vlSelfRef.cpu__DOT__control_inst__DOT__jalr_override;
    vlSelfRef.cpu__DOT__alu_source = vlSelfRef.cpu__DOT__control_inst__DOT__alu_source;
    vlSelfRef.cpu__DOT__pc_source = vlSelfRef.cpu__DOT__control_inst__DOT__pc_source;
    vlSelfRef.cpu__DOT__alu_ctrl = vlSelfRef.cpu__DOT__control_inst__DOT__alu_op;
    vlSelfRef.cpu__DOT__immediate = vlSelfRef.cpu__DOT__sign_extender_inst__DOT__ext_imm;
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
    vlSelfRef.cpu__DOT__alu_inst__DOT__shifter_inst__DOT__shift_type 
        = vlSelfRef.cpu__DOT__alu_inst__DOT__shift_type;
}

void Vtop___024root___nba_comb__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cpu__DOT__register_file_inst__DOT__rd1 
        = ((0U == (IData)(vlSelfRef.cpu__DOT__register_file_inst__DOT__rs1))
            ? 0U : vlSelfRef.cpu__DOT__register_file_inst__DOT__regs
           [vlSelfRef.cpu__DOT__register_file_inst__DOT__rs1]);
    vlSelfRef.cpu__DOT__register_file_inst__DOT__rd2 
        = ((0U == (IData)(vlSelfRef.cpu__DOT__register_file_inst__DOT__rs2))
            ? 0U : vlSelfRef.cpu__DOT__register_file_inst__DOT__regs
           [vlSelfRef.cpu__DOT__register_file_inst__DOT__rs2]);
    vlSelfRef.cpu__DOT__regData1 = vlSelfRef.cpu__DOT__register_file_inst__DOT__rd1;
    vlSelfRef.cpu__DOT__regData2 = vlSelfRef.cpu__DOT__register_file_inst__DOT__rd2;
    vlSelfRef.cpu__DOT__pc_inst__DOT__rs1 = vlSelfRef.cpu__DOT__regData1;
    vlSelfRef.cpu__DOT__branch_unit_inst__DOT__d1 = vlSelfRef.cpu__DOT__regData1;
    vlSelfRef.cpu__DOT__alu_inst__DOT__d1 = vlSelfRef.cpu__DOT__regData1;
    vlSelfRef.cpu__DOT__data_memory_inst__DOT__write_data 
        = vlSelfRef.cpu__DOT__regData2;
    vlSelfRef.cpu__DOT__branch_unit_inst__DOT__d2 = vlSelfRef.cpu__DOT__regData2;
    vlSelfRef.cpu__DOT__alu_inst__DOT__rs2 = vlSelfRef.cpu__DOT__regData2;
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
}

void Vtop___024root___nba_comb__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((6ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x0000000000000010ULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((6ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((7ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x000000000000000fULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__1(vlSelf);
    }
    if ((0x000000000000001fULL & vlSelfRef.__VnbaTriggered
         [0U])) {
        Vtop___024root___nba_comb__TOP__2(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    Vtop___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/james/https---github.com-JamesRyanV1-RV32I-Single-Cycle-capstone/Programming/../cpu/cpu.sv", 4, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/james/https---github.com-JamesRyanV1-RV32I-Single-Cycle-capstone/Programming/../cpu/cpu.sv", 4, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/james/https---github.com-JamesRyanV1-RV32I-Single-Cycle-capstone/Programming/../cpu/cpu.sv", 4, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop___024root___eval_phase__act(vlSelf));
    } while (Vtop___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
