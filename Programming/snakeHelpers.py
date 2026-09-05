import GeneralProgram as gp
import Instructions as i
import xorShifter as xs
import Array as arr

base_address = 4 # non-zero, word-aligned base address encodable by addi and valid for data memory
base_address_reg = 3

x_reg = 1
y_reg = 2
x = 16
y = 16

xorShift_seed_reg = 31
xorShift_masked_reg = 30
xorShift_state_reg = 20
xorShift_temp_reg = 21

apple_value = -0xFF# the value in the array that represents an apple, can be any negative number since the snake body is represented by positive numbers and empty cells are 0
apple_value_reg =  4

input_reg = 5
output_reg = 6

head_position_reg = 7
head_value_reg = 12
temp_reg_1 = 8
temp_reg_2 = 9
temp_reg_3 = 10
apple_exists_reg = 11
const_one_reg = 13
grow_this_tic_reg = 14

def initialize_board():
    """
    Returns a program that initializes all 256 cells of the board to 0.
    Must be called before any game logic runs.
    """
    body = gp.GeneralizedProgram([])
    body.instructions += i.makeList(
        i.addi(base_address_reg, 0, base_address), # reset address to start of board
        i.addi(temp_reg_1, 0, 0), # zero value to store
        i.addi(temp_reg_2, 0, 256), # count down from 256 cells
    )
    body.addLoop(
        i.makeList(
            i.sw(temp_reg_1, base_address_reg, 0), # store 0 to current cell
            i.addi(base_address_reg, base_address_reg, 4) # advance to next cell
        ),
        times=256,
        timesReg=24,
        countReg=25
    )
    body.instructions += i.makeList(
        i.addi(base_address_reg, 0, base_address), # return pointer to board base
        i.addi(temp_reg_1, 0, 1), # initial snake head value
        i.sw(temp_reg_1, base_address_reg, 0), # place initial snake head at cell [0,0]
        i.addi(head_position_reg, 0, base_address), # initialize tracked head address to first cell
        i.addi(head_value_reg, 0, 1) # initialize tracked head value
    )
    return body

def deathCheck():
    """
    Returns a program called once each game tic.
    It computes the next head address from current head + input direction,
    then checks bounds and body collision on that destination cell.
    If death is detected, clear x15 so the outer Game while-loop exits.
    """
    body = i.makeList(
        i.addi(temp_reg_1, head_position_reg, 0), # current head address
        i.addi(temp_reg_2, temp_reg_1, 4), # default next head: right
        i.addi(temp_reg_3, 0, 40), # down key
        i.bne(input_reg, temp_reg_3, 4),
        i.addi(temp_reg_2, temp_reg_1, 64), # next head: down
        i.addi(temp_reg_3, 0, 39), # left key
        i.bne(input_reg, temp_reg_3, 4),
        i.addi(temp_reg_2, temp_reg_1, -4), # next head: left
        i.addi(temp_reg_3, 0, 38), # up key
        i.bne(input_reg, temp_reg_3, 4),
        i.addi(temp_reg_2, temp_reg_1, -64), # next head: up
        i.addi(temp_reg_3, 0, base_address), # lower bound (inclusive)
        i.blt(temp_reg_2, temp_reg_3, 20), # if next head < base, branch to death handler
        i.addi(temp_reg_3, 0, 4*x*y + base_address), # upper bound (exclusive): base + (cells * 4 bytes)
        i.bge(temp_reg_2, temp_reg_3, 12), # if next head >= upper bound, branch to death handler
        i.lw(temp_reg_3, temp_reg_2, 0), # destination cell value
        i.blt(temp_reg_3, const_one_reg, 8), # empty (<1): safe
        i.beq(temp_reg_3, apple_value_reg, 4), # apple: safe
        i.addi(15, 0, 0) # death handler: clear outer loop condition reg x15 to stop the game loop
    )
    return gp.GeneralizedProgram(body)
def apple(): # MAY NOT WORK
    """
    Returns a program that randomly places an apple in the array by storing apple_value at a random (x,y) position.
    Uses the xorshift subroutine to generate random x and y values, which are then used to calculate the address to store the apple value.
    """
    body = i.makeList(
        # jump to end if apple already exists (apple_exists_reg is 1)
        # change apple_exists_reg to 1 when apple is placed, and change back to 0 when apple is eaten in the main game loop
        i.addi(base_address_reg, 0, base_address), # ensure apple addressing always starts from board base
        i.addi(apple_value_reg, 0, apple_value), # load apple value once before trying candidate cells
        i.bne(apple_exists_reg, 0, 72), # if an apple already exists, skip placement logic
        # get random liniar index from 0 to 255 (always in bounds)
        *xs.xorshift32_random_in_256_range(xorShift_masked_reg, xorShift_seed_reg, xorShift_state_reg, xorShift_temp_reg), # random index in xorShift_masked_reg
        i.slli(temp_reg_1, xorShift_masked_reg, 2), # convert linear index to byte offset
        i.addr(temp_reg_1, temp_reg_1, base_address_reg), # temp reg 1 = candidate cell address
        i.lw(temp_reg_3, temp_reg_1, 0), # load current value at candidate cell
        # jump back to run xorshift again if value at index is not 0
        i.bne(temp_reg_3, 0, -64), # retry until an empty cell is found
        # load value in apple_value_reg to the random address if checks passed to place apple,
        i.sw(apple_value_reg, temp_reg_1, 0), # store apple at chosen empty cell
        i.addi(apple_exists_reg, 0, 1), # mark apple as present
        #finish
    )
    return gp.GeneralizedProgram(body)
def calculate_new_head_address(): # may not work as well, i think it does
    """
    Returns a per-element program for use with Array.game_loop().
    On the first element of each pass, it resets the tracked max value, head address, and head value.
    On every element, it loads the current cell and updates the tracked head address and value when a larger value is found.
    """
    body = i.makeList(
        i.bne(x_reg, 0, 16), # if x != 0, skip first-element initialization block
        i.bne(y_reg, 0, 12), # if y != 0, skip first-element initialization block
        i.addi(head_position_reg, base_address_reg, 0), # initialize tracked head address to first element address
        i.addi(temp_reg_1, 0, 0), # temp reg 1 holds the max value found in this pass
        i.addi(head_value_reg, 0, 0), # head value reg mirrors the current max value
        i.lw(temp_reg_3, base_address_reg, 0), # load current cell value
        i.bge(temp_reg_1, temp_reg_3, 12), # if current max >= current cell, skip update
        i.addi(temp_reg_1, temp_reg_3, 0), # update max value found
        i.addi(head_position_reg, base_address_reg, 0), # update tracked head address
        i.addi(head_value_reg, temp_reg_3, 0) # update tracked head value
    )
    return gp.GeneralizedProgram(body)

def move_snake():
    """
    Moves the snake one cell each tic based on input_reg (x5):
    37=right, 40=down, 39=left, 38=up.
    If the next head cell contains an apple, the snake grows by 1 and apple_exists_reg is cleared
    so a new apple can be placed on the next tic.
    """
    body = i.makeList(
        i.bne(x_reg, 0, 72), # run destination/eat setup only once per tic (at x=0,y=0)
        i.bne(y_reg, 0, 68), # run destination/eat setup only once per tic (at x=0,y=0)
        i.addi(grow_this_tic_reg, 0, 0), # default: no growth this tic
        i.addi(temp_reg_1, head_value_reg, 0), # default new head value (no growth)
        i.addi(temp_reg_2, head_position_reg, 4), # default right: +1 cell (4 bytes)
        i.addi(temp_reg_3, 0, 40), # down key
        i.bne(input_reg, temp_reg_3, 4),
        i.addi(temp_reg_2, head_position_reg, 64), # down: +16 cells
        i.addi(temp_reg_3, 0, 39), # left key
        i.bne(input_reg, temp_reg_3, 4),
        i.addi(temp_reg_2, head_position_reg, -4), # left: -1 cell
        i.addi(temp_reg_3, 0, 38), # up key
        i.bne(input_reg, temp_reg_3, 4),
        i.addi(temp_reg_2, head_position_reg, -64), # up: -16 cells
        i.lw(temp_reg_3, temp_reg_2, 0), # load destination cell to check for apple collision
        i.bne(temp_reg_3, apple_value_reg, 12), # if destination is not apple, skip growth path
        i.addi(temp_reg_1, head_value_reg, 1), # eating apple: grow snake by 1
        i.addi(grow_this_tic_reg, 0, 1), # mark growth for this tic
        i.addi(apple_exists_reg, 0, 0), # mark apple consumed so apple() places a new one next tic
        i.beq(grow_this_tic_reg, const_one_reg, 20), # when growing, skip decrement/store for all cells this tic
        i.addi(temp_reg_3, 0, 0), # temp reg 3 is used for loading each cell value
        i.lw(temp_reg_3, base_address_reg, 0), # load current cell value
        i.blt(temp_reg_3, const_one_reg, 8), # if cell value < 1, skip decrement/store (empty cells are not modified)
        i.addi(temp_reg_3, temp_reg_3, -1), # decrement cell value to move snake forward
        i.sw(temp_reg_3, base_address_reg, 0), # store updated cell value
        i.addi(temp_reg_3, temp_reg_1, 0), # load new head value into temp reg 3
        i.sw(temp_reg_3, temp_reg_2, 0) # store new head value at head address to grow snake
    )
    return gp.GeneralizedProgram(body)
def output():
    """
    Loads the value at the current cell into output_reg for output
    Not done in game loop since output happens at the start of the tic
    Treats board as a 1d array and outputs each cell in sequence
    """
    body = gp.GeneralizedProgram([])
    body.instructions += i.makeList(
        i.addi(base_address_reg, 0, base_address), # reset output traversal to start of board
        # output start sequence
        i.addi(output_reg, 0, 0xFF), # output reg holds 0xFF to signal start of output sequence
        i.addi(output_reg, output_reg, 0), # keep output reg at 0xFF for one cycle to signal start of output sequence
        i.addi(output_reg, 0, 0) # then set output reg to 0 for the rest of the output sequence to signal that it's not the start of the sequence
    )
    body.addLoop(
        i.makeList(
            i.lw(output_reg, base_address_reg, 0) # load current cell value to output reg for output
        ) + i.makeList(
            i.addi(base_address_reg, base_address_reg, 4) # advance to next cell address
        ),
        times=256,
        timesReg=22,
        countReg=23
    )
    return body

arrs = arr.Array(
    base_address,
    x,
    y,
    x_reg,
    y_reg,
    3
)
arrs.program.instructions += i.makeList(
    i.addi(xorShift_seed_reg, 0, 1) # non-zero seed so xorshift does not lock at 0
)
test_game_loop = [gp.GeneralizedProgram(i.makeList(*xs.xorshift32_random_in_256_range(xorShift_masked_reg, xorShift_seed_reg, xorShift_state_reg, xorShift_temp_reg),i.sw(xorShift_masked_reg, base_address_reg, 0)))]
arrs.game_loop(test_game_loop)
test_game = arr.Game(arrs, output())

arr2 = arr.Array(
    base_address,
    x,
    y,
    x_reg,
    y_reg,
    3
)
arr2.program.instructions += i.makeList(
    i.addi(xorShift_seed_reg, 0, 1), # non-zero seed for apple placement RNG
    i.addi(const_one_reg, 0, 1), # constant 1 register used for branch comparisons
    i.addi(input_reg, 0, 37), # default direction input (testbench may overwrite x5 directly)
)
arr2.program.instructions += initialize_board().get_instructions() # initialize board to all zeros before starting game
test_game_loop2 = [
    gp.GeneralizedProgram(move_snake().get_instructions()),
    gp.GeneralizedProgram(calculate_new_head_address().get_instructions())
]
arr2.game_loop(test_game_loop2)
real_tic = gp.GeneralizedProgram(
    i.makeList(
        i.addi(const_one_reg, 0, 1) # keep this register pinned at 1 for comparisons
    )
    + apple().get_instructions()
    + output().get_instructions()
    + deathCheck().get_instructions()
)
real_game = arr.Game(arr2, real_tic)
print(len(real_game.get_program()))
for x in real_game.get_program():
    print(x)