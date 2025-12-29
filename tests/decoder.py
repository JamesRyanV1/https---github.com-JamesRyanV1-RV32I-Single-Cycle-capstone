import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly
import random as rd

@cocotb.test()
async def decoder_test(dut):
    """test for the 32 bit instruction decoder (I-type only, opcode 0b0000001)"""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # drive reset low after one cycle
    await RisingEdge(dut.clk)
    dut.rst.value = 0

    # random I-type instruction with opcode forced to 0b0000001
    inst = rd.randint(0, 0xFFFFFFFF)
    inst = (inst & ~0x7F) | 0b0000001  # force opcode bits [6:0]

    dut.instruction.value = inst
    await RisingEdge(dut.clk)
    await ReadOnly()

    # expected fields per decoder.sv for opcode 0b0000001 (I-type)
    expected_inst_type = 1              # 4'b0001
    expected_imm_type = 0               # 3'b000
    expected_immediate = (inst >> 20) & 0xFFF   # bits [31:20]
    expected_rs1 = (inst >> 15) & 0x1F          # bits [19:15]
    expected_rd = (inst >> 7) & 0x1F            # bits [11:7]
    expected_func3 = (inst >> 12) & 0x7        # bits [14:12]

    # assertions
    assert int(dut.inst_type.value) == expected_inst_type, f"inst_type mismatch: got {int(dut.inst_type.value)}, expected {expected_inst_type}"
    assert int(dut.imm_type.value) == expected_imm_type, f"imm_type mismatch: got {int(dut.imm_type.value)}, expected {expected_imm_type}"
    assert int(dut.immediate.value) == expected_immediate, f"immediate mismatch: got {int(dut.immediate.value)}, expected {expected_immediate}"
    assert int(dut.rs1.value) == expected_rs1, f"rs1 mismatch: got {int(dut.rs1.value)}, expected {expected_rs1}"
    assert int(dut.rd.value) == expected_rd, f"rd mismatch: got {int(dut.rd.value)}, expected {expected_rd}"
    assert int(dut.func3.value) == expected_func3, f"func3 mismatch: got {int(dut.func3.value)}, expected {expected_func3}"