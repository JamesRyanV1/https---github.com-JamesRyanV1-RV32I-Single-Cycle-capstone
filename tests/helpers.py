
def compile_I_type(opcode, rd, func3, rs1, imm):
    """Helper function to compile I-type instructions."""
    imm_11_0 = imm & 0xFFF
    instruction = (imm_11_0 << 20) | (rs1 << 15) | (func3 << 12) | (rd << 7) | opcode
    return instruction
def compile_S_type(opcode, func3, rs1, rs2, imm):
    """Helper function to compile S-type instructions."""
    imm_11_5 = (imm >> 5) & 0x7F
    imm_4_0 = imm & 0x1F
    instruction = (imm_11_5 << 25) | (rs2 << 20) | (rs1 << 15) | (func3 << 12) | (imm_4_0 << 7) | opcode
    return instruction
def compile_B_type( func3, rs1, rs2, imm):
    """Helper function to compile B-type instructions."""
    imm_12 = (imm >> 12) & 0x1
    imm_10_5 = (imm >> 5) & 0x3F
    imm_4_1 = (imm >> 1) & 0xF
    imm_11 = (imm >> 11) & 0x1
    instruction = (imm_12 << 31) | (imm_11 << 7) | (imm_10_5 << 25) | (rs2 << 20) | (rs1 << 15) | (func3 << 12) | (imm_4_1 << 8) | 0b1100011
    return instruction
def compile_R_type(opcode, rd, func3, rs1, rs2, func7):
    """Helper function to compile R-type instructions."""
    instruction = (func7 << 25) | (rs2 << 20) | (rs1 << 15) | (func3 << 12) | (rd << 7) | opcode
    return instruction
def compile_L_type(rd, rs1, imm):
    """Compile a lw instruction."""
    opcode = 0b0000011
    func3 = 0b010
    return compile_I_type(opcode, rd, func3, rs1, imm)

