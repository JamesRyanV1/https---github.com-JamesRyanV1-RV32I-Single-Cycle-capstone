from helpers import compile_jalr

import random
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly

@cocotb.test()
async def jalr(dut):
    """
    Test JALR instruction functionality.
    JALR preloaded to instruction memory at address 0.
    1. Preload rs1 register with a target address
    2. Execute JALR instruction with an immediate offset
    3. Verify that PC is set to (rs1 + immediate + 4) at the correct time
    4. Verify that return address is written to destination register
    """

    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    
    # Reset
    dut.rst.value = 1
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst.value = 0

    for iteration in range(10):
        # Reset each iteration to start from PC=0
        dut.rst.value = 1
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)
        dut.rst.value = 0

        # Setup: Preload registers and instruction
        rd = 1  # Destination register (where return address will be saved)
        rs1 = 5  # Source register containing the base address
        imm = random.randint(0, 0x7FF)  # 12-bit immediate (positive for now)
        jalr_instruction = compile_jalr(rd, rs1, imm)

        # Preload rs1 register with random target base
        target_base = random.randint(0, 0x3FF) << 2  # word-aligned base
        dut.register_file_inst.regs[rs1].value = target_base

        # Preload instruction memory
        dut.instruction_memory_inst.mem[0].value = jalr_instruction

        # First clock: instruction is fetched, decoded, PC latches the value
        await RisingEdge(dut.clk)

        # Read outputs after JALR has executed
        await ReadOnly()

        # Expected PC = (rs1 + imm) with bit 0 cleared (JALR spec)
        expected_pc = (target_base + imm) & ~1
        actual_pc = int(dut.pc_inst.pc.value)

        # Expected return address = PC + 4 = 4 (since PC was at 0 when JALR was fetched)
        expected_return_address = 4
        actual_return_address = int(dut.register_file_inst.regs[rd].value)

        # Assertions
        assert actual_pc == expected_pc, (
            f"JALR PC update failed on iter {iteration}: expected PC={expected_pc} (0x{expected_pc:x}), "
            f"got {actual_pc} (0x{actual_pc:x})"
        )
        assert actual_return_address == expected_return_address, (
            f"JALR return address failed on iter {iteration}: expected return address {expected_return_address}, "
            f"got {actual_return_address}"
        )
        await RisingEdge(dut.clk)  # Advance clock for next iteration

    print("JALR randomized test passed!")
