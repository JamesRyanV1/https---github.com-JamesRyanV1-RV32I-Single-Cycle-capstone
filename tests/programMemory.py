import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly, Timer


@cocotb.test()
async def programMemory(dut):
    """
    Tests that the program memory is correctly initialized and can be read, then makes sure that it reads the correct value each pc iteration
    Should read preloaded instructions in order starting from address 0, iterating by 4 bytes each clock cycle. ( as the pc does )
    """

    