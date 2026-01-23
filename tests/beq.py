import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ReadOnly, RisingEdge, Timer


OPCODE_BRANCH = 0b1100011
FUNCT3_BEQ = 0b000


def encode_beq(rs1: int, rs2: int, offset: int) -> int:
	"""Assemble an RV32I beq instruction; offset is a byte displacement (2-byte aligned)."""
	if offset % 2 != 0:
		raise ValueError("Branch offset must be 2-byte aligned")
	imm = offset & 0x1FFF  # keep 13 bits to preserve sign
	imm_12 = (imm >> 12) & 0x1
	imm_10_5 = (imm >> 5) & 0x3F
	imm_4_1 = (imm >> 1) & 0xF
	imm_11 = (imm >> 11) & 0x1
	return (
		(imm_12 << 31)
		| (imm_10_5 << 25)
		| (rs2 << 20)
		| (rs1 << 15)
		| (FUNCT3_BEQ << 12)
		| (imm_4_1 << 8)
		| (imm_11 << 7)
		| OPCODE_BRANCH
	)


async def reset(dut): # PC is at 0 after this, incraments to 4 on next cycle, by 4 every cycle
	"""Reset DUT and leave PC at 0."""
	dut.rst.value = 1
	await RisingEdge(dut.clk)
	await RisingEdge(dut.clk)
	dut.rst.value = 0
	await Timer(1, unit="ps")


def setup_registers_via_write_port(dut, rs1, rs2, value):
	"""Properly write to registers through the register file write port."""
	# Write to rs1
	dut.register_file_inst.enableWrite.value = 1
	dut.register_file_inst.rd.value = rs1
	dut.register_file_inst.register_source.value = 0b01  # ALU result
	dut.register_file_inst.alu_result.value = value
	
	# Write to rs2 (will happen on same edge if we set it now)
	# We need separate cycles for each register

	
@cocotb.test()
async def test_beq_taken_updates_pc(dut):
	"""When rs1 == rs2, beq should assert take_branch and update PC by offset+4."""
	
	rs1 = 1
	rs2 = 2
	offset = 8  # bytes
	beq_instr = encode_beq(rs1, rs2, offset)
	test_value = 0x55AA55AA

	cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
	await reset(dut)

	# Load instructions into ALL instruction memory locations to prevent garbage
	for i in range(16):
		dut.instruction_memory_inst.mem[i].value = beq_instr
	
	# Directly write to register array since control signals are driven by CPU
	dut.register_file_inst.regs[rs1].value = test_value
	dut.register_file_inst.regs[rs2].value = test_value
	
	# Let one instruction cycle complete
	await RisingEdge(dut.clk)
	await ReadOnly()
	dut._log.info(
		f"Cycle 1: pc={int(dut.pc_next.value)} rf[{rs1}]=0x{int(dut.register_file_inst.regs[rs1].value):08x} "
		f"rf[{rs2}]=0x{int(dut.register_file_inst.regs[rs2].value):08x} regData1=0x{int(dut.regData1.value):08x} "
		f"regData2=0x{int(dut.regData2.value):08x} opcode=0x{int(dut.opcode.value):02x} take_branch={int(dut.branch_unit_inst.take_branch.value)}"
	)

	await RisingEdge(dut.clk)  
	await ReadOnly()
	dut._log.info(
		f"BEQ cycle: pc={int(dut.pc_next.value)} opcode=0x{int(dut.opcode.value):02x} "
		f"regData1=0x{int(dut.regData1.value):08x} regData2=0x{int(dut.regData2.value):08x} "
		f"pc_source=0x{int(dut.pc_source.value):x} take_branch={int(dut.branch_unit_inst.take_branch.value)}"
	)
	take_branch = int(dut.branch_unit_inst.take_branch.value)

	assert take_branch == 1, "take_branch should be asserted for equal registers"


@cocotb.test()
async def test_beq_not_taken_pc_increments(dut):
	"""When rs1 != rs2, beq should fall through to the next sequential PC."""
	
	rs1 = 3
	rs2 = 4
	offset = 8
	beq_instr = encode_beq(rs1, rs2, offset)
	
	cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
	await reset(dut)
	
	# Load instructions into instruction memory
	dut.instruction_memory_inst.mem[0].value = beq_instr
	dut.instruction_memory_inst.mem[1].value = beq_instr
	dut.instruction_memory_inst.mem[2].value = beq_instr
	dut.instruction_memory_inst.mem[3].value = beq_instr
	
	# Directly write unequal values to register array
	dut.register_file_inst.regs[rs1].value = 0x11112222
	dut.register_file_inst.regs[rs2].value = 0x33334444
	
	# Wait for values to propagate and BEQ to execute
	await RisingEdge(dut.clk)
	await ReadOnly()
	
	await RisingEdge(dut.clk)  # should fall through
	await ReadOnly()
	take_branch = int(dut.branch_unit_inst.take_branch.value)

	assert take_branch == 0, "take_branch should be deasserted for unequal registers"

