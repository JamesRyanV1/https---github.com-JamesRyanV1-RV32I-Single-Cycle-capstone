# MORE CASES NEEDED IN FUTURE, BUT EFFECTIVLY COPPY/PASTED FOR TESTING

import cocotb
from cocotb.triggers import ReadOnly

@cocotb.test()
async def control(dut):
    """Test control module for opcode 6'b000011 (lw instruction)
    
    Tests:
    - reg_write = 1
    - imm_source = 3'b000
    - mem_write = 0
    - mem_read = 1
    - alu_source = 1
    - alu_op = 4'b0000
    """
    
    # Set inputs for lw instruction (opcode 7'b0000011)
    dut.op.value = 0b0000011
    dut.func3.value = 0
    dut.func7.value = 0
    dut.alu_zero.value = 0
    dut.alu_last_bit.value = 0
    
    await ReadOnly()
    
    # Expected values for lw
    expected_reg_write = 1
    expected_imm_source = 0b000
    expected_mem_write = 0
    expected_mem_read = 1
    expected_alu_source = 1
    expected_alu_op = 0b0000
    
    # Read actual outputs
    got_reg_write = int(dut.reg_write.value)
    got_imm_source = int(dut.imm_source.value)
    got_mem_write = int(dut.mem_write.value)
    got_mem_read = int(dut.mem_read.value)
    got_alu_source = int(dut.alu_source.value)
    got_alu_op = int(dut.alu_op.value)
    
    # Assert all outputs match expected values
    assert got_reg_write == expected_reg_write, (
        f"reg_write mismatch: got {got_reg_write}, expected {expected_reg_write}"
    )
    assert got_imm_source == expected_imm_source, (
        f"imm_source mismatch: got {got_imm_source:#05b}, expected {expected_imm_source:#05b}"
    )
    assert got_mem_write == expected_mem_write, (
        f"mem_write mismatch: got {got_mem_write}, expected {expected_mem_write}"
    )
    assert got_mem_read == expected_mem_read, (
        f"mem_read mismatch: got {got_mem_read}, expected {expected_mem_read}"
    )
    assert got_alu_source == expected_alu_source, (
        f"alu_source mismatch: got {got_alu_source}, expected {expected_alu_source}"
    )
    assert got_alu_op == expected_alu_op, (
        f"alu_op mismatch: got {got_alu_op:#06b}, expected {expected_alu_op:#06b}"
    )