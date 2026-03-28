import Instructions as i

# x31 is the input seed, x30 is the masked output
# x20 holds the 32-bit state, x21 is a temp/output register

def xorshift32_random_in_256_range(masked_reg, seed_reg, state_reg, temp_reg) -> list[int]:
    """
    Inputs: masked reg, seed reg, state reg, temp reg
    Returns a subroutine that runs a 32-bit xorshift and masks to 0-255.
    The new 32-bit state is left in x20, and the masked output is in x30.
    """
    body = i.makeList(
        i.addi(state_reg, seed_reg, 0),
        i.addi(temp_reg, state_reg, 0),
        i.slli(temp_reg, temp_reg, 13),
        i.xorr(state_reg, state_reg, temp_reg),
        i.addi(temp_reg, state_reg, 0),
        i.srli(temp_reg, temp_reg, 17),
        i.xorr(state_reg, state_reg, temp_reg),
        i.addi(temp_reg, state_reg, 0),
        i.slli(temp_reg, temp_reg, 5),
        i.xorr(state_reg, state_reg, temp_reg),
        i.andi(masked_reg, state_reg, 0xFF),
        i.addi(seed_reg, state_reg, 0),
    )

    return body