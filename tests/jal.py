from helpers import compile_jal

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer, ReadOnly

@cocotb.test()
async def jal(dut):
    """
    Test JAL instruction functionality.
    JAL preloaded to instructon memory at address 0.
    1. Preload register file and instruction memory.
    2. Execute JAL instruction.
    3. Verify that the return address is correctly written to the destination register
    """

    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    # Reset
    dut.rst.value = 1
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst.value = 0

    rd = 5  # Destination register
    imm = 16  # Jump offset
    jal_instruction = compile_jal(rd, imm)
    dut.instruction_memory_inst.mem[0].value = jal_instruction
    await RisingEdge(dut.clk) # instruction processed

    # Assert that register 5 contains the return address (PC + 4)
    await ReadOnly()
    expected_return_address = 4  # Since PC starts at 0 and increments by
    actual_return_address = int(dut.register_file_inst.regs[rd].value)
    assert actual_return_address == expected_return_address, f"JAL failed: expected return address {expected_return_address}, got {actual_return_address}"
    print(f"JAL test passed: Register {rd} contains return address {actual_return_address}")

