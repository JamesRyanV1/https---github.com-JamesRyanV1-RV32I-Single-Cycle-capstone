import cocotb
from cocotb.triggers import RisingEdge, Timer
import sys
import select

def key_input():
    return select.select([sys.stdin], [], [], 0) == ([sys.stdin], [], [])

@cocotb.test()
async def keyboard_input_test(dut):
    dut.key.value = 0

    
