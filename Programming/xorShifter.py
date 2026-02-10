import Instructions as i
import HelperPrograms as hp

# x31 is the input seed, x30 is the masked output
# x20 holds the 32-bit state, x21 is a temp/output register

def xorshift32_random_in_256_range() -> list[int]:
    """
    Returns a subroutine that runs a 32-bit xorshift and masks to 0-255.
    The new 32-bit state is left in x20, and the masked output is in x30.
    """
    body = i.makeList(
        i.addi(20,31,0),
        i.addi(21,20,0),
        i.slli(21,21,13),
        i.xorr(20,20,21),
        i.addi(21,20,0),
        i.srli(21,21,17),
        i.xorr(20,20,21),
        i.addi(21,20,0),
        i.slli(21,21,5),
        i.xorr(20,20,21),
        i.andi(21,20,0xFF),
        i.addi(30,21,0),
    )

    return hp.start_subroutine + body + hp.end_subroutine

# returns the subroutine as a list of 32 bit binary instructions not int.
for i in xorshift32_random_in_256_range():
    x = bin(i)
    offset = 32 - len(x)
    print("0" * offset + x[2:]) # remove the "0b" prefix and pad with zeros