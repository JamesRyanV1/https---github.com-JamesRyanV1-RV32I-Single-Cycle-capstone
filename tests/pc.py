import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer

@cocotb.test()
async def pc(dut):
    """Test PC increments correctly each clock cycle."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Reset
    dut.rst.value = 1
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst.value = 0
    await Timer(1, unit="ps")

    # Check that PC starts at 0
    await ReadOnly()
    assert int(dut.pc.value) == 0, f"PC should start at 0 after reset, got {int(dut.pc.value)}"

    # Check PC increments by 4 each cycle
    for i in range(1, 10):
        await RisingEdge(dut.clk)
        await ReadOnly()
        expected_pc = i * 4
        print(expected_pc)
        actual_pc = int(dut.pc.value)
        assert actual_pc == expected_pc, f"After {i} cycles, PC should be {expected_pc}, got {actual_pc}"