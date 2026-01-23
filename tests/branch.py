import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer

@cocotb.test()
async def testBranch(dut):
    """Test branch module functionality."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Reset
    dut.rst.value = 1
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)
    await Timer(1, unit="ps")
    # Check initial state after reset
    await ReadOnly()
    assert int(dut.take_branch.value) == 0, f"branch should start at 0 after reset, got {int(dut.take_branch.value)}"

    await RisingEdge(dut.clk)
    data1 = 0xffffffff
    data2 = 0x00000001
    cntrl = 0b001  # BEQ
    dut.d1.value = data1
    dut.d2.value = data2
    dut.cntrl.value = cntrl
    await RisingEdge(dut.clk)    
    await ReadOnly()             

    assert dut.take_branch.value == 0, "BEQ failed when d1 != d2"
    await RisingEdge(dut.clk)
    dut.rst.value = 1
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await RisingEdge(dut.clk)

    dut.d1.value = data1
    dut.d2.value = data1
    dut.cntrl.value = cntrl 
    await Timer(1, unit="ps")
    await ReadOnly()
    assert dut.take_branch.value == 1, "BEQ failed when d1 == d2"