import random

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly


# Constants for opcode fields
R_OPCODE = 0b0110011  # RV32I integer register-register operations
I_OPCODE = 0b0010011  # RV32I integer register-immediate operations

# Maps for R-type and I-type ALU operations (func3, func7)
R_TYPE_ALU_FUNCS = {
	"add": (0b000, 0b0000000),
	"sll": (0b001, 0b0000000),
	"srl": (0b101, 0b0000000),
	"sra": (0b101, 0b0100000),
	"and": (0b111, 0b0000000),
	"or":  (0b110, 0b0000000),
	"xor": (0b100, 0b0000000),
}

I_TYPE_ALU_FUNCS = {
	"addi": (0b000, None),
	"slli": (0b001, 0b0000000),
	"srli": (0b101, 0b0000000),
	"srai": (0b101, 0b0100000),
	"andi": (0b111, None),
	"ori":  (0b110, None),
	"xori": (0b100, None),
}

BASE_OP_FOR_IMM = {
	"addi": "add",
	"slli": "sll",
	"srli": "srl",
	"srai": "sra",
	"andi": "and",
	"ori": "or",
	"xori": "xor",
}


def encode_r_type(rd: int, rs1: int, rs2: int, func3: int | None = None, func7: int | None = None, opcode: int = R_OPCODE) -> int:
	"""Assemble an RV32I R-type instruction."""
	f3 = 0 if func3 is None else func3 & 0x7
	f7 = 0 if func7 is None else func7 & 0x7F
	return ((f7 << 25) | (rs2 << 20) | (rs1 << 15) | (f3 << 12) | (rd << 7) | (opcode & 0x7F))


def encode_i_type(rd: int, rs1: int, imm: int, func3: int | None = None, func7: int | None = None, opcode: int = I_OPCODE) -> int:
	"""Assemble an RV32I I-type instruction. If func7 is supplied (shift immediates), its bits occupy imm[11:5]."""
	f3 = 0 if func3 is None else func3 & 0x7
	imm12 = imm & 0xFFF
	if func7 is not None:
		imm12 = ((func7 & 0x7F) << 5) | (imm12 & 0x1F)
	return ((imm12 << 20) | (rs1 << 15) | (f3 << 12) | (rd << 7) | (opcode & 0x7F))


def sign_extend_12(value: int) -> int:
	value &= 0xFFF
	if value & 0x800:
		return value | ~0xFFF
	return value


def to_signed32(value: int) -> int:
	value &= 0xFFFFFFFF
	return value if value < 0x80000000 else value - (1 << 32)


def apply_alu(op: str, a: int, b: int) -> int:
	mask = 0xFFFFFFFF
	a_u = a & mask
	b_u = b & mask
	if op == "add":
		return (a_u + b_u) & mask
	if op == "and":
		return a_u & b_u
	if op == "or":
		return a_u | b_u
	if op == "xor":
		return a_u ^ b_u
	if op == "sll":
		return (a_u << (b_u & 0x1F)) & mask
	if op == "srl":
		return (a_u >> (b_u & 0x1F)) & mask
	if op == "sra":
		shamt = b_u & 0x1F
		return (to_signed32(a_u) >> shamt) & mask
	raise ValueError(f"Unsupported op {op}")


async def init_and_reset(dut):
	cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
	dut.rst.value = 1
	dut.instruction_in.value = 0
	await RisingEdge(dut.clk)
	await RisingEdge(dut.clk)
	dut.rst.value = 0
	await RisingEdge(dut.clk)


async def run_r_type_op_alu(dut, op: str, func3: int, func7: int, iterations: int = 5):
    rs1 = 5
    rs2 = 6
    rd = 7
    for _ in range(iterations):
        await RisingEdge(dut.clk)
        a = random.getrandbits(32)
        b = random.getrandbits(32)
        dut.register_file_inst.regs[rs1].value = a
        dut.register_file_inst.regs[rs2].value = b

        dut.instruction_in.value = encode_r_type(rd, rs1, rs2, func3=func3, func7=func7)
        await RisingEdge(dut.clk)  # decode/execute
        await ReadOnly()

        expected = apply_alu(op, a, b)
        got = int(dut.alu_output.value)
        assert got == expected, f"R-type {op}: got {got:08x}, expected {expected:08x}, a={a:08x}, b={b:08x}"


async def run_i_type_op_alu(dut, op_name: str, func3: int, func7: int | None, iterations: int = 5):
    base_op = BASE_OP_FOR_IMM[op_name]
    rs1 = 8
    rd = 9
    for _ in range(iterations):
        await RisingEdge(dut.clk)
        a = random.getrandbits(32)
        dut.register_file_inst.regs[rs1].value = a

        if base_op in ("sll", "srl", "sra"):
            imm = random.randint(0, 31)
            b_val = imm
        else:
            imm = random.randint(-2048, 2047)
            b_val = sign_extend_12(imm)

        dut.instruction_in.value = encode_i_type(rd, rs1, imm, func3=func3, func7=func7)
        await RisingEdge(dut.clk)  # decode/execute
        await ReadOnly()

        expected = apply_alu(base_op, a, b_val)
        got = int(dut.alu_output.value)
        assert got == expected, f"I-type {op_name}: got {got:08x}, expected {expected:08x}, a={a:08x}, imm={b_val & 0xFFFFFFFF:08x}"


# R-type individual testbenches
@cocotb.test()
async def test_r_type_add(dut):
    await init_and_reset(dut)
    await run_r_type_op_alu(dut, "add", 0b000, 0b0000000)


@cocotb.test()
async def test_r_type_sll(dut):
    await init_and_reset(dut)
    await run_r_type_op_alu(dut, "sll", 0b001, 0b0000000)


@cocotb.test()
async def test_r_type_srl(dut):
    await init_and_reset(dut)
    await run_r_type_op_alu(dut, "srl", 0b101, 0b0000000)


@cocotb.test()
async def test_r_type_sra(dut):
    await init_and_reset(dut)
    await run_r_type_op_alu(dut, "sra", 0b101, 0b0100000)


@cocotb.test()
async def test_r_type_and(dut):
    await init_and_reset(dut)
    await run_r_type_op_alu(dut, "and", 0b111, 0b0000000)


@cocotb.test()
async def test_r_type_or(dut):
    await init_and_reset(dut)
    await run_r_type_op_alu(dut, "or", 0b110, 0b0000000)


@cocotb.test()
async def test_r_type_xor(dut):
    await init_and_reset(dut)
    await run_r_type_op_alu(dut, "xor", 0b100, 0b0000000)


# I-type individual testbenches
@cocotb.test()
async def test_i_type_addi(dut):
    await init_and_reset(dut)
    await run_i_type_op_alu(dut, "addi", 0b000, None)


@cocotb.test()
async def test_i_type_slli(dut):
    await init_and_reset(dut)
    await run_i_type_op_alu(dut, "slli", 0b001, 0b0000000)


@cocotb.test()
async def test_i_type_srli(dut):
    await init_and_reset(dut)
    await run_i_type_op_alu(dut, "srli", 0b101, 0b0000000)


@cocotb.test()
async def test_i_type_srai(dut):
    await init_and_reset(dut)
    await run_i_type_op_alu(dut, "srai", 0b101, 0b0100000)


@cocotb.test()
async def test_i_type_andi(dut):
    await init_and_reset(dut)
    await run_i_type_op_alu(dut, "andi", 0b111, None)


@cocotb.test()
async def test_i_type_ori(dut):
    await init_and_reset(dut)
    await run_i_type_op_alu(dut, "ori", 0b110, None)


@cocotb.test()
async def test_i_type_xori(dut):
    await init_and_reset(dut)
    await run_i_type_op_alu(dut, "xori", 0b100, None)
