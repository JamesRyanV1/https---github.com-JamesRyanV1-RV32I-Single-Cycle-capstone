# Instructons.py creates a function for each instruction that the cpu can execute, and returns the binary representation of that instruction.
# Used elsewhere to compile lists of instructions to preload into instruction memory for testing.

# Opcode constants (RV32I subset implemented by this CPU)
OP_R_TYPE = 0b0110011
OP_I_TYPE = 0b0010011
OP_LOAD = 0b0000011
OP_STORE = 0b0100011
OP_BRANCH = 0b1100011
OP_JAL = 0b1101111


def _encode_r_type(rd: int, rs1: int, rs2: int, func3: int, func7: int, opcode: int = OP_R_TYPE) -> int:
    return ((func7 & 0x7F) << 25) | ((rs2 & 0x1F) << 20) | ((rs1 & 0x1F) << 15) | ((func3 & 0x7) << 12) | ((rd & 0x1F) << 7) | (opcode & 0x7F)


def _encode_i_type(rd: int, rs1: int, imm: int, func3: int, opcode: int = OP_I_TYPE) -> int:
    imm_11_0 = imm & 0xFFF
    return (imm_11_0 << 20) | ((rs1 & 0x1F) << 15) | ((func3 & 0x7) << 12) | ((rd & 0x1F) << 7) | (opcode & 0x7F)


def _encode_i_type_shift(rd: int, rs1: int, shamt: int, func3: int, func7: int, opcode: int = OP_I_TYPE) -> int:
    imm_11_0 = ((func7 & 0x7F) << 5) | (shamt & 0x1F)
    return (imm_11_0 << 20) | ((rs1 & 0x1F) << 15) | ((func3 & 0x7) << 12) | ((rd & 0x1F) << 7) | (opcode & 0x7F)


def _encode_s_type(rs1: int, rs2: int, imm: int, func3: int, opcode: int = OP_STORE) -> int:
    imm_11_5 = (imm >> 5) & 0x7F
    imm_4_0 = imm & 0x1F
    return ((imm_11_5 << 25) | ((rs2 & 0x1F) << 20) | ((rs1 & 0x1F) << 15) | ((func3 & 0x7) << 12) | (imm_4_0 << 7) | (opcode & 0x7F))


def _encode_b_type(rs1: int, rs2: int, imm: int, func3: int, opcode: int = OP_BRANCH) -> int:
    imm_12 = (imm >> 12) & 0x1
    imm_10_5 = (imm >> 5) & 0x3F
    imm_4_1 = (imm >> 1) & 0xF
    imm_11 = (imm >> 11) & 0x1
    return (
        (imm_12 << 31)
        | (imm_10_5 << 25)
        | ((rs2 & 0x1F) << 20)
        | ((rs1 & 0x1F) << 15)
        | ((func3 & 0x7) << 12)
        | (imm_4_1 << 8)
        | (imm_11 << 7)
        | (opcode & 0x7F)
    )


def _encode_j_type(rd: int, imm: int, opcode: int = OP_JAL) -> int:
    imm_20 = (imm >> 20) & 0x1
    imm_10_1 = (imm >> 1) & 0x3FF
    imm_11 = (imm >> 11) & 0x1
    imm_19_12 = (imm >> 12) & 0xFF
    return (imm_20 << 31) | (imm_10_1 << 21) | (imm_11 << 20) | (imm_19_12 << 12) | ((rd & 0x1F) << 7) | (opcode & 0x7F)


# R-type ALU instructions
def addr(rd: int, rs1: int, rs2: int) -> int:
    return _encode_r_type(rd, rs1, rs2, func3=0b000, func7=0b0000000)


def subr(rd: int, rs1: int, rs2: int) -> int:
    return _encode_r_type(rd, rs1, rs2, func3=0b000, func7=0b0100000)


def sllr(rd: int, rs1: int, rs2: int) -> int:
    return _encode_r_type(rd, rs1, rs2, func3=0b001, func7=0b0000000)


def srlr(rd: int, rs1: int, rs2: int) -> int:
    return _encode_r_type(rd, rs1, rs2, func3=0b101, func7=0b0000000)


def srar(rd: int, rs1: int, rs2: int) -> int:
    return _encode_r_type(rd, rs1, rs2, func3=0b101, func7=0b0100000)


def andr(rd: int, rs1: int, rs2: int) -> int:
    return _encode_r_type(rd, rs1, rs2, func3=0b111, func7=0b0000000)


def orr(rd: int, rs1: int, rs2: int) -> int:
    return _encode_r_type(rd, rs1, rs2, func3=0b110, func7=0b0000000)


def xorr(rd: int, rs1: int, rs2: int) -> int:
    return _encode_r_type(rd, rs1, rs2, func3=0b100, func7=0b0000000)


# I-type ALU instructions
def addi(rd: int, rs1: int, imm: int) -> int:
    return _encode_i_type(rd, rs1, imm, func3=0b000)


def andi(rd: int, rs1: int, imm: int) -> int:
    return _encode_i_type(rd, rs1, imm, func3=0b111)


def ori(rd: int, rs1: int, imm: int) -> int:
    return _encode_i_type(rd, rs1, imm, func3=0b110)


def xori(rd: int, rs1: int, imm: int) -> int:
    return _encode_i_type(rd, rs1, imm, func3=0b100)


def slli(rd: int, rs1: int, shamt: int) -> int:
    return _encode_i_type_shift(rd, rs1, shamt, func3=0b001, func7=0b0000000)


def srli(rd: int, rs1: int, shamt: int) -> int:
    return _encode_i_type_shift(rd, rs1, shamt, func3=0b101, func7=0b0000000)


def srai(rd: int, rs1: int, shamt: int) -> int:
    return _encode_i_type_shift(rd, rs1, shamt, func3=0b101, func7=0b0100000)


# Load/store
def lw(rd: int, rs1: int, imm: int) -> int:
    return _encode_i_type(rd, rs1, imm, func3=0b010, opcode=OP_LOAD)


def sw(rs1: int, rs2: int, imm: int) -> int:
    return _encode_s_type(rs1, rs2, imm, func3=0b010, opcode=OP_STORE)


# Branches
def beq(rs1: int, rs2: int, imm: int) -> int:
    return _encode_b_type(rs1, rs2, imm, func3=0b000)


def bne(rs1: int, rs2: int, imm: int) -> int:
    return _encode_b_type(rs1, rs2, imm, func3=0b001)


def blt(rs1: int, rs2: int, imm: int) -> int:
    return _encode_b_type(rs1, rs2, imm, func3=0b100)


def bge(rs1: int, rs2: int, imm: int) -> int:
    return _encode_b_type(rs1, rs2, imm, func3=0b101)


# Jumps
def jal(rd: int, imm: int) -> int:
    """
    Compile a JAL instruction.

    :param rd: Destination register (0-31)
    :param imm: Immediate value (jump offset)
    :return: 32-bit binary representation of the JAL instruction
    """
    return _encode_j_type(rd, imm, opcode=OP_JAL)

def makeList(* instructions) -> list[int]:
    """
    Create a list of instructions, taking however many correctly called instruction functions as arguments.
    """
    return list(instructions) + [0]  # Append a 0 to signify end of program