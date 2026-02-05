import Instructions as i

# x1 is the stack pointer, x2 is the return adress


# Runs at the start of a subroutine, I just put it somewhere far off in memory
start_subroutine = i.makeList(i.addi(1,1,4), 
                              i.sw(2,1))# change 0x1 in first bge, idk if sw works like it does
# ends a subroutine by loading the teturn adress from the top of the stack, incrementing the stack pointer
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
        i.lw(4,0,0), # sets current adress to 0, may remove to save a register, and just do math
        i.lw(8,0,base_adress_adress), # loads base adress of the array into x8
        i.lw(9,0,base_num_rows_adress), # loads number of rows into x9
        i.lw(10,0,base_num_cols_adress), # loads number of columns into x10
    )
        # loop
    second = i.makeList(
        # sub will jump back, so it doesnt effect the looping
        i.addi(12,12,4), # increments column count, may need to be by 4 if this is just going straight to byte adressed mem
        i.blt(12,10,-8), # if column count < columns, jump back 2, to the subroutine
        i.addi(11,11,4), # increments row count
        i.blt(11,9,-12), # if row count < rows, jump back 3, to the start of the loop

        
        )
        # x8-12 are zerod at the start of the next loop. 
        # no programs should assume 
        # any non 0 register is not left filled
        # by some other program that ended.
    return [
        start_subroutine,
        first, # setup
        *sub, # code running
        second, # loop
        end_subroutine
        ]

# subroutine to load the snake array, im thinking of a 16x16 array, 4 is the memory pointer
def load_snake_array() -> list[int]:
    """ 
    returns the instructions to load zeros to the array
    """
    x = i.makeList(i.sw(4,0,0)),

    return [
            start_subroutine,
            x,
            end_subroutine
            ]

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

    return[
        start_subroutine,
        x,
        end_subroutine,
    ]