import Instructions as i
import GeneralProgram as gp
import snakeHelpers as sh
import Array as arr
import xorShifter as xs
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

snek = arr.Array(
    4,
    x,
    y,
    x_reg,
    y_reg,
    3
)
snek.game_loop([
    sh.move_snake(),
])
ticPrograms = [sh.apple(),sh.calculate_new_head_address(),sh.output()]
p = gp.GeneralizedProgram([p.get_instructions() for p in ticPrograms])
snake = arr.Game(snek, p)
print()
print(snake.get_program())
