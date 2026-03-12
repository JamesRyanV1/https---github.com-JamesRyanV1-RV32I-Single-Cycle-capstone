import GeneralProgram
import Instructions as i
import cocotb
from cocotb.triggers import Timer
from cocotb.clock import Clock
from cocotb.clock import RisingEdge

# make a test program with a loop inside a loop. The outside will add 2 to register 3, the inside will add 2 to register 4. The outside loop will run 3 times, and the inside loop will run 2 times. So at the end, register 3 should be 6 and register 4 should be 12.
innerLoop = GeneralProgram.GeneralizedProgram([])
innerLoop.addLoop(
    i.makeList(
        i.addi(4,4,2) # add 2 to register 4
    ),
    times=2,
    timesReg=26,
    countReg=27
)
program = GeneralProgram.GeneralizedProgram([])
program.addLoop(
    i.makeList(
        i.addi(3,3,2) # add 2 to register 3
    ) + innerLoop.get_instructions(), # add the inner loop instructions
    times=3,
    timesReg=22,
    countReg=23
)




@cocotb.test()
async def test_nested_loop(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    async def reset():
        dut.rst.value = 1
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)
        dut.rst.value = 0
        await Timer(1, unit="ps")
    await reset()
    # load program
    # loads instruction memory with the given program
    instructions = program.get_instructions()
    iterations = 0
    for i in range(len(instructions)):
        # Instructions can be either binary strings or integers, so handle both (ooops)
        if isinstance(instructions[i], str):
            dut.instruction_memory_inst.mem[i].value = int(instructions[i], 2)
        else:
            dut.instruction_memory_inst.mem[i].value = instructions[i]
    while int(dut.pc_inst.pc_out.value) // 4 < len(instructions):
        await RisingEdge(dut.clk)
        iterations += 1
        if iterations > 100:  # Prevent infinite loop
            print("Test had to be stopped")
            break

    await Timer(1, unit="ns")
    assert dut.register_file_inst.regs[3].value == 6, f"Expected register 3 to be 6, but got {dut.register_file_inst.regs[3].value}"
    assert dut.register_file_inst.regs[4].value == 12, f"Expected register 4 to be 12, but got {dut.register_file_inst.regs[4].value}"
    print("Test passed!")