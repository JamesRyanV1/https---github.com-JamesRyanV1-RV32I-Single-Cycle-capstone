import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly
import random as rd

@cocotb.test()
async def signExtender_test(dut):
    """Test signExtender for I-type immediates (imm_type = 3'b000)
    
    Tests:
    - 12 LSBs match instruction bits [31:20]
    - 20 MSBs are sign-extended from bit 31
    """
    
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    
    # Initialize
    dut.rst.value = 1
    dut.inst.value = 0
    dut.imm_type.value = 0
    
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)
    
    # Test I-type sign extension (imm_type = 3'b000)
    for _ in range(100):
        # Generate random 32-bit instruction
        inst = rd.randint(0, 0xFFFFFFFF)
        
        # Set inputs
        dut.inst.value = inst
        dut.imm_type.value = 0b000  # I-type
        
        await ReadOnly()
        
        # Extract expected values
        imm_12bit = (inst >> 20) & 0xFFF      # bits [31:20]
        sign_bit = (inst >> 31) & 0x1         # bit 31
        sign_extend = 0xFFFFF if sign_bit else 0x00000  # 20-bit sign extension
        expected_ext_imm = (sign_extend << 12) | imm_12bit
        
        # Read actual output
        got = int(dut.ext_imm.value)
        
        # Assert: 12 LSBs match instruction immediate
        lsb_12 = got & 0xFFF
        assert lsb_12 == imm_12bit, (
            f"I-type 12 LSBs mismatch for {inst:#010x}: "
            f"expected {imm_12bit:#05x}, got {lsb_12:#05x}"
        )
        
        # Assert: 20 MSBs are correct sign extension
        msb_20 = (got >> 12) & 0xFFFFF
        expected_msb = sign_extend
        assert msb_20 == expected_msb, (
            f"I-type 20 MSBs mismatch for {inst:#010x}: "
            f"expected {expected_msb:#08x}, got {msb_20:#08x}"
        )
        
        await RisingEdge(dut.clk)