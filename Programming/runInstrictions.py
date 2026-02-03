import Instructions as i
import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly

arr = i.makeList() # input instructions here in i.instruction(), i.instruction, format
@cocotb.test()
async def run_instructions(dut):
    @cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    async def reset_dut():
        dut.rst.value = 1
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)
        dut.rst.value = 0
        
    await reset_dut()

    # loads instruction memory with the given program
    for i in range(len(arr)):
        dut.instruction_memory_inst.memory[i*4].value = arr[i]  # Load instruction into instruction memory
    # ALSO PRELOAD REGISTERS AND NEEDED MEMORY DURING THIS CLOCK CYCLE 
    
    # Run the instructions ASSUMES THERE IS AN ESTOP OR SMTN THAT STOPS IT, I HAVNT IMPLIMENTED THIS YET BUT IT JS WORKS IN TB
    while arr(dut.pc.value // 4) != 0:
        await RisingEdge(dut.clk)
    
    assert True # change this assertion to something usefull depending on the program (last expected value for traceable programs, otherwise idk)