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

# for each time this runs, pc only hits 124 once, so it can be contained in a loop
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
    return ( first + sub + second )

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
    # print(f"Unique results: {len(results)} out of 256")
    # for i in results:
    #     print(i)

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

def output_item_to_port() -> list[int]:
    """
    HAS NO UNCONDITIONAL JUMPS TO REGISTERS SO DOES NOT CARE WHERE IN MEMORY IT IS PLACED
    returns instructions for a subroutine that puts 4 special charachters into the output port, then the width and height of the array, then the entire array
    """
    body = i.makeList(
        
        i.beq(0,7,28), # if x7 is 0, skip the initializing values
        i.addi(7,0,1), # sets register 7 to 1
        # special sequence to signify start of array output, can be used to trigger something in the testbench, only runs once
        i.addi(31,0,0x48), # H
        i.addi(31,0,0x45), # E
        i.addi(31,0,0x4C), # L
        i.addi(31,0,0x4F), # O
        # width and height output,
        i.addr(31,0,8),
        i.addr(31,0,9),

        # loop to multiply the current row by current columns, store in reg 11
        # x11 = current row, x10 = num columns
        # uses x13 as accumulator, x14 as counter
        i.addi(13,0,0), # acc = 0
        i.addi(14,0,0), # counter = 0
        i.blt(14,11,8), # if counter < row, jump to body
        i.beq(0,0,16),  # else skip loop
        i.addr(13,13,10), # acc += cols
        i.addi(14,14,1),  # counter++
        i.beq(0,0,-12), # jump back to compare
        i.addi(11,13,0), # x11 = acc

        i.addi(13,0,0),
        i.addi(31,0,0), # clear x31 to be used for output
        i.addi(4,4,4), # point to the next element in the array
        i.blt(13,11,-4), # if current element < total elements,
        i.addi(4,4,4),
        i.addi(31,4,0),
        i.addi(31,0,0) # clear x31 to be used for output


    )
    return body

# p2 outputs the entire array that is processed by iterate_arr_type, along with some special charachters at the start and the width and height of the array, this is used for testing and debugging, but could be used for other things too, it has no jumps to registers so it can be placed anywhere in memory without needing to change anything
def new_snake() -> list[int]: 
    """
    puts a snake head somewhere in the arr
    """
    ret1 = i.makeList(
        # adds random snake space and random xor shifted number to array
        i.addi(4,0,5120), # point to base adress of array in memory
    )
    rand = xorshift32_random_in_256_range_body() # generates a random number and puts it's short version in x31, also updates the state in x30 for the next random number
    ret2 = i.makeList(
        i.addr(20,31,4), # adds the current xorshift random number to the current snake space, makes first snake body
        i.addi(21,0,1), # snake len register is at 21, starts at 1
        i.sw(20,21,0) # store the snake body position in x21 (random spot)
    )
    ret3 = i.makeList(
    )
    apple_reg = i.makeList(
        i.addi(27,0,0xfff), # load apple value into x27
    )
    return ret1 + rand + ret2 + ret3 + apple_reg
def load_apple_to_array() -> list[int]:
    """
    puts an apple somewhere in the arr, represented by 0xfff, checks if the random spot is taken, if so keeps going
    """
    ret = i.makeList(
        i.addi(4,0,5120), # point to base adress of array in memory
    )
    rand = xorshift32_random_in_256_range_body() # generates a random number and puts it's short version in x31, also updates the state in x30 for the next random number
    ret2 = i.makeList(
        i.addr(20,31,8), # adds the current xorshift random number the array base adress
        i.lw(23,20,0), # loads the value at the random spot from mem into x23
        i.beq(0,23,8), # if the random spot is empty (0), jump to store apple
        i.beq(0,0,-8), # else try again
        i.addi(20,0,0xfff), # load apple value into x20
        i.sw(20,23,4) # store the apple in the random spot
    )
    return ret + rand + ret2
def move_snake() -> list[int]:
    """
    moves the snake by 1 space in the direction specified by x5, which is set by input, 38 = up, 37 = right, 40 = down, 39 = left, also checks if the snake eats an apple or itself and updates the array accordingly
    NOTE: APPLE VAL MUST BE A REGISTER, BECAUSE BRANCHES TAKE NO IMMEDIATE (BC OFFSET). ALSO NOTE: THIS MUST STORE A 0,1, OR 2 IN A REGISTER TO SIGNIFY IF THE SNAKE ATE AN APPLE, MOVED NORMALLY, OR DIED. S
    """
    ret1 = i.makeList(
        i.addi(4,0,5120), # point to base adress of array in memory
    )
    getHead = i.makeList(
        # loops to find the head (highest value), x22 stores head address
        i.addi(20,0,0), # max snake value seen so far
        i.addi(21,0,0), # counter/index register
        i.addi(22,0,0), # head address register
        i.blt(21,256,8), # if counter < total elements, jump to body
        i.beq(0,0,40), # done scanning, jump to reset base address
        i.lw(23,4,0), # load current element into x23
        i.beq(0,23,20), # if current element is 0, jump to increment
        i.blt(20,23,8), # if current element > max, jump to update
        i.beq(0,0,12), # else jump to increment
        i.addi(20,23,0), # update max value
        i.addi(22,4,0), # update head address
        i.addi(21,21,1), # increment counter
        i.addi(4,4,4), # advance pointer to next element
        i.beq(0,0,-40), # jump back to compare
        i.addi(4,0,5120) # point back to base adress of array in memory
    )
    # head location is +1 if snake is right, -1 if left, column count if down, negative column count if up, this is added to the head address to get the new head address, if the new head address is an apple, snake len is increased by 1, if it's a body, snake dies and len is set to 0, if it's empty, snake moves forward by 1
    moveHead = i.makeList( # NOTE: fix  jumps i coppy and pasted them so none of them actualy jump to the subtraction phase
        i.addi(20,0,0), # new head address register
        i.addi(21,0,0), # value at new head address register
        i.beq(5,38,8), # if input is up, jump to up
        i.beq(5,37,8), # if input is right, jump to right
        i.beq(5,40,8), # if input is down, jump to down
        i.beq(5,39,8), # if input is left, jump to left
        i.beq(0,0,16), # invalid input, jump to end
        # up:
        i.addi(20,22,0), # new head address = old head address - column count
        i.addi(20,20,-16),
        i.beq(0,20,8), # if new head address is empty, jump to move
        i.beq(0,20,16), # if new head address is empty, jump to move
        i.beq(20,27,8), # if new head address is apple, jump to eat
        i.beq(0,0,16), # else jump to end
        # right:
        i.addi(20,22,0), # new head address = old head address + 1
        i.addi(20,20,4),
        i.beq(0,20,8), # if new head address is empty, jump to move
        i.beq(0,20,16), # if new head address is empty, jump to move
        i.beq(20,27,8), # if new head address is apple, jump to eat
        i.beq(0,0,16), # else jump to end
        # down:
        i.addi(20,22,0), # new head address = old head address + column count
        i.addi(20,20,64),
        i.beq(0,20,8), # if new head address is empty, jump to move
        i.beq(0,20,16), # if new head address is empty, jump to move
        i.beq(20,27,8),  # if new head address is apple, jump to eat
        i.beq(0,0,16), # else jump to end
        # left:
        i.addi(20,22,0), # new head address = old head address - 1
        i.addi(20,20,-4),
        i.beq(0,20,8), # if new head address is empty, jump to move
        i.beq(0,20,16), # if new head address is empty, jump to move
        i.beq(20,27,8), # if new head address is apple, jump to eat
        i.beq(0,0,16), # else jump to end
        # move:
        i.sw(20,21,0), # store new head address in snake body register
        i.addi(21,21,1), # increment snake length
        i.sw(20,21,0), # store new head address in snake body register
        i.addi(4,0,5120), # point to base adress of array in memory
        i.addi(22,0,0), # reset head address register
        i.addi(21,0,0), # reset snake length register
        i.beq(0,0,16), # jump to end
    )
    check_apple = i.makeList(
        i.beq(20,27,8), # if new head address is apple, jump to eat
        i.beq(0,0,8), # else jump to end
        # eat:
        i.addi(21,21,1), # increment snake length
        i.sw(20,21,0), # store new head address in snake body register
        i.addi(4,0,5120), # point to base adress of array in memory
        i.addi(22,0,0), # reset head address register
        i.addi(21,0,0), # reset snake length register
    )
    check_self = i.makeList(
        i.beq(20,27,8), # if new head address is apple, jump to end
        i.beq(20,0,8), # if new head address is empty, jump to end
        i.beq(0,0,8), # else jump to end
        # die:
        i.addi(21,0,0), # reset snake length
    )# NOTE: SW ORDER MIGHT BE WRONG IN SUB
    sub = iterate_arr_type(i.makeList(
        i.lw(25,4,0), 
        i.beq(25,0,12), # if current element is 0, jump to increment
        i.beq(25,27,8), # if current element is apple, jump to increment
        i.addi(25,25,-1),
        i.sw(4,25,0),

        ), 5120, 16, 16) # SUBTRACTS EACH ELEMENT OF AN ARRAY by 1, this is used to move the snake forward by 1, if the snake eats an apple, the new head is added before this subroutine so the tail is not subtracted, if the snake dies, the tail is not readded so it is subtracted and effectively removed from the array, if the snake moves normally, DOESNT LF APPLE OOOPS

        
    # resets memory pointer, loops to get head, calculates new head position, checks if it's an apple or body, updates snake length and position
    return ret1 + getHead + moveHead + check_apple + check_self + sub
p2 = iterate_arr_type(xorshift32_random_in_256_range(),4,8,12) + output_item_to_port()
p1 = xorshift32_random_in_256_range()
def play_snake() -> list[int]:
    output = output_item_to_port()
    move = move_snake()
    start = load_snake_array()
    apple = load_apple_to_array()
    return start + i.makeList(i.lw(1,len(start),0)) + apple + move + output #NOTE: make jumps so it actualy loops, right now no loop
# for i in play_snake():
#     print(i)
x33 = play_snake()
# fillRandomArray = iterate_arr_type(xorshift32_random_in_256_range_body(),4,8,12)
# for i in fillRandomArray:
#     print(i)
# z = iterate_arr_type(xorshift32_random_in_256_range(),2 << 8, 16, )
# code to jump to iterate_arr_type, run subroutine, jump back, complete
# for p in z:
#     print(p)
