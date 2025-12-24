import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, ReadWrite
import random as rd


@cocotb.test()
async def registerFile(dut):
    """Test registerFile functionality
    
    Test coverage:
    - Set all ports to 0 to start
    - Loop through and perform random reads/writes:
        - Random addresses (1-31)
        - Read from rs1 and rs2, compare to expected values
        - Write to rd if enableWrite is high
    - Try to write to register 0, ensure it stays 0
    """
    
    # Start a cocotb-driven clock (10 ns period)
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    
    # Set all ports to 0 to start
    dut.rst.value = 1
    dut.rs1.value = 0
    dut.rs2.value = 0
    dut.rd.value = 0
    dut.wd.value = 0
    dut.enableWrite.value = 0
    
    # Wait for reset to take effect
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)
    
    # Dictionary to track register values in software model
    register_model = {i: 0 for i in range(32)}
    
    # Perform random reads/writes
    for iteration in range(200):
        # Randomly choose addresses (1-31 for writes, 0-31 for reads)
        rs1_addr = rd.randint(0, 31)
        rs2_addr = rd.randint(0, 31)
        rd_addr = rd.randint(1, 31)  # Don't write to 0
        write_data = rd.randint(0, 0xFFFFFFFF)
        enable_write = rd.choice([0, 1])
        
        # Set inputs
        dut.rs1.value = rs1_addr
        dut.rs2.value = rs2_addr
        dut.rd.value = rd_addr
        dut.wd.value = write_data
        dut.enableWrite.value = enable_write
        
        # Wait for combinational reads to settle
        await ReadOnly()
        
        # Check read outputs
        expected_rd1 = register_model[rs1_addr]
        expected_rd2 = register_model[rs2_addr]
        
        assert dut.rd1.value == expected_rd1, \
            f"Register read failed at rs1={rs1_addr}: got {dut.rd1.value:#010x}, expected {expected_rd1:#010x}"
        assert dut.rd2.value == expected_rd2, \
            f"Register read failed at rs2={rs2_addr}: got {dut.rd2.value:#010x}, expected {expected_rd2:#010x}"
        
        # Wait for clock edge (write happens on clock edge)
        await RisingEdge(dut.clk)
        
        # Update software model if write was enabled
        if enable_write and rd_addr != 0:
            register_model[rd_addr] = write_data
    # Test writing to register 0 - should stay 0
    dut.rs1.value = 0
    dut.rs2.value = 0
    dut.rd.value = 0
    dut.wd.value = 0xDEADBEEF  # Try to write this to register 0
    dut.enableWrite.value = 1
    
    await RisingEdge(dut.clk)
    
    # Read from register 0
    dut.rs1.value = 0
    dut.enableWrite.value = 0
    await ReadOnly()
    
    assert dut.rd1.value == 0, \
        f"Register 0 write protection failed: got {dut.rd1.value:#010x}, expected 0"
    await RisingEdge(dut.clk)
    await ReadWrite()
    # Final verification of all non-zero registers match our model
    for reg_idx in range(1, 32):
        dut.rs1.value = reg_idx
        await ReadOnly()
        assert dut.rd1.value == register_model[reg_idx], \
            f"Register {reg_idx} mismatch: got {dut.rd1.value:#010x}, expected {register_model[reg_idx]:#010x}"
        await RisingEdge(dut.clk)
        await ReadWrite()
