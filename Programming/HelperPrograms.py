import Instructions as i
# x1 is the stack pointer, x2 is the return adress


# Runs at the start of a subroutine, I just put it somewhere far off in memory
start_subroutine = i.makeList(
                              i.addi(1,1,4), 
                              i.sw(2,1,0))# change 0x1 in first bge, idk if sw works like it does
# ends a subroutine by loading the teturn adress from the top of the stack into x2, incrementing the stack pointer
end_subroutine = i.makeList(i.lw(2,1,0),
                            i.addi(1,1,4))



# performs a subroutine on each element of a 2d array.
# x8-12 are reserved
# x8 is the base adress, x9 is the number of rows, x10 is the number of columns, x11 is the current row, x12 is current column, x4 is the current adress.

# the base adresses are where they are preloaded into memory, this will just compile to machine code with no arguments
def iterate_arr_type(sub, base_adress_adress: int, base_num_rows_adress: int, base_num_cols_adress: int) -> list[int]:
    """
    returns a list of binary instructions that will perform a subroutine on each element of a 2d array.
    the subroutine is expected to update the stack, and will not use registers x8-12

    the subroutine can be used for the initial setup of the array if the base adress is kept,
    for example setting the entire contigous block of memory to 0
    incraments counts by 4 bytes, or 1 word.
    """
    # sub is a list of binary instructions created elsewhere, other subroutine using the start/end subroutines to maintain the stack
    first = i.makeList(
        i.addi(11,0,0), # sets row count to 0
        i.addi(12,0,0), # sets column count to 0, may remove to save a register, and just do math
        i.lw(8,0,base_adress_adress), # loads base adress of the array into x8
        # i.addi(8,0,5120),
        i.addi(4,8,0), # sets current adress to base address, may remove to save a register, and just do math
        # READ WHEN RUNNING make 3 contigous values saved in memory for ease of use
        i.lw(9,0,base_num_rows_adress), # loads number of rows into x9
        i.lw(10,0,base_num_cols_adress), # loads number of columns into x10
        # i.addi(9,0,16), # loads number of rows into x9
        # i.addi(10,0,16) # loads number of columns into x10
    )

        # loop, the jump should store the word in the adress stored in x4
    sub_len = len(sub)
    # Branch back offsets (bytes). Jump to start of subroutine block.
    col_loop_back = -4 * (sub_len + 3)  # from blt at instr #3 back to sub start
    row_loop_back = -4 * (sub_len + 6)  # from blt at instr #6 back to sub start

    second = i.makeList(
        # increment x4 by 4 to point to the next element.
        i.addi(4,4,4), # increments current adress by 4, may need to be by 4 if this is just going straight to byte adressed mem
        i.addi(12,12,1), # increments column count by 1
        i.blt(12,10,col_loop_back), # if column count < columns, jump back to subroutine
        i.addi(11,11,1), # increments row count by 1
        i.addi(12,0,0), # reset column count
        i.blt(11,9,row_loop_back), # if row count < rows, jump back to subroutine
        # zeros x4 to be the base adress once loop is done
        i.addi(4,8,0)

        
        )
        # x8-12 are zerod at the start of the next loop. 
        # no programs should assume 
        # any non 0 register is not left filled
        # by some other program that ended.
    return (start_subroutine + first + sub + second + end_subroutine)

# subroutine to load the snake array, im thinking of a 16x16 array, 4 is the memory pointer
def load_snake_array() -> list[int]:
    """ 
    returns the instructions to load zeros to the array
    """
    x = i.makeList(i.sw(4,0,0))

    return start_subroutine + x + end_subroutine

def random_in_256_range() -> int:
    """ 
    returns a random number, used for random food generation in the snake game or whatnot
    """
    x = i.makeList(
        i.addi(20,0,0xFE3), # loads some random number into x20, hopefully the adding 1 each time works well also
        i.addi(20,1,0), # adds the stack pointer to x20, change this some time
        i.srai(21,20,8),
        i.xorr(21,20,21), # xor stack pointer with itself shifted right by 4
        i.srai(21,21,11),
        i.xori(21,21,0xfe13),
        i.andi(21,21,0xff) # and with 255 to get a number 0-255

    )

    return(
        start_subroutine +
        x +
        end_subroutine
    )
def test_random_in_256_range(input):
    # tests how random this actualy is
    input = input + 1
    input = input >> 8
    input = input ^ (input << 8)
    input = input >> 11
    input = input ^ 0xfe13
    input = input & 0xff

#print(test_random_in_256_range(0x12345310))

def test_randomness():
    # tests how random the function is
    results = set()
    input = 13
    for i in range(10000):
        input += 1
        results.add(test_random_in_256_range(input))
    print(f"Unique results: {len(results)} out of 256")
    for i in results:
        print(i)

#test_randomness()
#print(random_in_256_range())


def test_xorshift32_masked(value: int) -> tuple[int, int]:
    """
    Runs a simple 32-bit xorshift on the input and returns
    (original_input, masked_output_in_0_255_range).
    """
    original = value & 0xFFFFFFFF
    x = original
    x ^= (x << 13) & 0xFFFFFFFF
    x ^= (x >> 17) & 0xFFFFFFFF
    x ^= (x << 5) & 0xFFFFFFFF
    return (original, x & 0xFF)


# def collect_xorshift32_masked(seed: int, iterations: int) -> set[int]:
#     """
#     Recursively runs xorshift32 on its last 32-bit output and
#     collects the masked (0-255) outputs into a set.
#     """
#     results = set()
#     value = seed & 0xFFFFFFFF
#     for _ in range(iterations):
#         x = value
#         x ^= (x << 13) & 0xFFFFFFFF
#         x ^= (x >> 17) & 0xFFFFFFFF
#         x ^= (x << 5) & 0xFFFFFFFF
#         results.add(x & 0xFF)
#         value = x & 0xFFFFFFFF
#     return results


# print(f"Unique masked outputs: {len(collect_xorshift32_masked(0x12345678, 10000))} out of 256")
def xorshift32_random_in_256_range_body() -> list[int]:
    """
    Returns the xorshift32 body instructions (no prologue/epilogue).
    The new 32-bit state is left in x30, and the masked output is in x31.
    """
    body = i.makeList(
        # If x30 is 0, initialize it with a non-zero seed to avoid the zero-trap
        i.addi(21,30,0),  # copy x30 to x21
        i.addi(20,0,0xA5A), # load a non-zero constant seed (0xA5A) into x20
        i.beq(21,0,8),    # if x30 is zero, skip to seed initialization (2 instructions ahead)
        i.addi(20,30,0),  # x30 is non-zero, use it as seed
        i.beq(0,0,8),     # skip seed initialization (jump 2 instructions)
        # Seed initialization (only runs if x30 was 0):
        i.xorr(20,1,20),  # XOR stack pointer (x1) with constant for better seed
        
        # Now x20 has a guaranteed non-zero value, run xorshift32
        i.addi(21,20,0), # copy x20 to x21 
        i.slli(21,21,13), # shift x21 left 13
        i.xorr(20,20,21), # xor x20 with x21 to x20
        i.addi(21,20,0), # copy x20 to x21
        i.srli(21,21,17), # shift x21 right 17
        i.xorr(20,20,21), # xor x20 with x21 to x20
        i.addi(21,20,0), # copy x20 to x21
        i.slli(21,21,5), # shift x21 left 5
        i.xorr(20,20,21), # xor x20 with x21 to x20
        i.andi(21,20,0xFF), # and x20 with 255 to get a number 0-255 in x21
        i.addi(30,20,0), # copy FULL 32-bit state to x30 for next iteration (NOT the masked value!)
        i.addi(31,21,0), # copy masked result (0-255) to x31 for output
        
        # stores the masked random value (x31) to the memory address in x4
        i.sw(4,31,0)
        # No jalr here - execution falls through to the loop control (second) which branches back
        
    )
    return body

def xorshift32_random_in_256_range() -> list[int]:
    """
    Returns a full subroutine that runs a 32-bit xorshift and masks to 0-255.
    """
    body = xorshift32_random_in_256_range_body()
    return start_subroutine + body + end_subroutine

p1 = xorshift32_random_in_256_range()
# print(p1)
fillRandomArray = iterate_arr_type(xorshift32_random_in_256_range_body(),4,8,12)
for i in fillRandomArray:
    print(i)
# z = iterate_arr_type(xorshift32_random_in_256_range(),2 << 8, 16, 16)
# code to jump to iterate_arr_type, run subroutine, jump back, complete
# for p in z:
#     print(p)
