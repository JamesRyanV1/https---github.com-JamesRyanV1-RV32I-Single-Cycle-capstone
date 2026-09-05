from collections import deque
from typing import Iterable

# Input register values used by your CPU/game
RIGHT = 37
UP = 38
LEFT = 39
DOWN = 40

APPLE_VALUE = -255

DIRS = {
	RIGHT: (0, 1),
	DOWN: (1, 0),
	LEFT: (0, -1),
	UP: (-1, 0),
}

OPPOSITE = {
	RIGHT: LEFT,
	LEFT: RIGHT,
	UP: DOWN,
	DOWN: UP,
}


def _normalize_frame(frame: Iterable, rows: int, cols: int) -> list[list[int]]:
	"""Accepts either a flat list or a 2D list and returns a rows x cols 2D int grid."""
	frame = list(frame)
	if not frame:
		return [[0 for _ in range(cols)] for _ in range(rows)]

	if isinstance(frame[0], (list, tuple)):
		# Already 2D
		grid = [list(map(int, row)) for row in frame]
		return grid

	# Flat
	vals = list(map(int, frame))
	if len(vals) != rows * cols:
		raise ValueError(f"Expected {rows * cols} cells, got {len(vals)}")
	return [vals[r * cols:(r + 1) * cols] for r in range(rows)]


def _find_snake_parts(grid: list[list[int]]) -> tuple[tuple[int, int] | None, tuple[int, int] | None, int]:
	"""
	Returns (head_pos, tail_pos, snake_len) using positive cell values.
	Head = max positive value, tail = min positive value.
	"""
	head = None
	tail = None
	head_v = -10**9
	tail_v = 10**9
	length = 0

	for r, row in enumerate(grid):
		for c, v in enumerate(row):
			if v > 0:
				length += 1
				if v > head_v:
					head_v = v
					head = (r, c)
				if v < tail_v:
					tail_v = v
					tail = (r, c)

	return head, tail, length


def _find_apple(grid: list[list[int]]) -> tuple[int, int] | None:
	for r, row in enumerate(grid):
		for c, v in enumerate(row):
			if v == APPLE_VALUE:
				return (r, c)
	return None


def _in_bounds(r: int, c: int, rows: int, cols: int) -> bool:
	return 0 <= r < rows and 0 <= c < cols


def _flood_fill_area(start: tuple[int, int], blocked: set[tuple[int, int]], rows: int, cols: int) -> int:
	if start in blocked:
		return 0
	q = deque([start])
	seen = {start}
	area = 0
	while q:
		r, c = q.popleft()
		area += 1
		for dr, dc in DIRS.values():
			nr, nc = r + dr, c + dc
			p = (nr, nc)
			if _in_bounds(nr, nc, rows, cols) and p not in blocked and p not in seen:
				seen.add(p)
				q.append(p)
	return area


def _manhattan(a: tuple[int, int], b: tuple[int, int]) -> int:
	return abs(a[0] - b[0]) + abs(a[1] - b[1])


def choose_next_input(frame, prev_input: int = RIGHT, rows: int = 16, cols: int = 16) -> int:
	"""
	Choose the best next move from a board frame under standard snake rules.

	Expected board encoding:
	- >0 : snake body (larger = closer to head)
	-  0 : empty
	- -255 : apple

	Returns one of: 37(right), 40(down), 39(left), 38(up)
	"""
	grid = _normalize_frame(frame, rows, cols)
	head, tail, snake_len = _find_snake_parts(grid)
	apple = _find_apple(grid)

	if head is None:
		return prev_input

	# Prefer keeping direction stability by evaluating prev first.
	direction_order = [prev_input] + [k for k in (RIGHT, DOWN, LEFT, UP) if k != prev_input]

	# Standard rule: cannot reverse directly when length > 1.
	if snake_len > 1 and prev_input in OPPOSITE:
		forbidden_reverse = OPPOSITE[prev_input]
	else:
		forbidden_reverse = None

	# Occupied cells are positive cells.
	occupied = {(r, c) for r, row in enumerate(grid) for c, v in enumerate(row) if v > 0}

	candidates = []

	for key in direction_order:
		if key == forbidden_reverse:
			continue

		dr, dc = DIRS[key]
		nr, nc = head[0] + dr, head[1] + dc
		np = (nr, nc)

		if not _in_bounds(nr, nc, rows, cols):
			continue

		cell = grid[nr][nc]
		hits_apple = (cell == APPLE_VALUE)

		# Collision logic:
		# - Any positive cell is body.
		# - Exception: stepping into the tail can be legal if not eating this turn
		#   because tail vacates in normal non-growth snake movement.
		stepping_into_tail = (tail is not None and np == tail)
		if cell > 0 and not (stepping_into_tail and not hits_apple):
			continue

		# Build blocked map for space estimate after this move.
		blocked = set(occupied)
		blocked.discard(head)   # old head no longer special

		if not hits_apple and tail is not None:
			blocked.discard(tail)  # tail vacates on non-growth move

		blocked.add(np)  # new head occupies next cell

		free_area = _flood_fill_area(np, blocked, rows, cols)
		dist = _manhattan(np, apple) if apple is not None else 0

		# Score priorities:
		# 1) eating apple now
		# 2) avoid obvious self-traps (area should at least fit snake)
		# 3) closer to apple
		# 4) more free area
		# 5) keep direction (handled by order, and final tie-break)
		score = (
			1 if hits_apple else 0,
			1 if free_area >= snake_len else 0,
			-dist,
			free_area,
		)

		candidates.append((score, key))

	if not candidates:
		# No safe move found, keep current input as fallback.
		return prev_input

	candidates.sort(reverse=True)
	return candidates[0][1]


class SnakeSolver:
	"""Stateful wrapper so you can call once per frame and directly write x5/input register."""

	def __init__(self, initial_input: int = RIGHT, rows: int = 16, cols: int = 16):
		self.current_input = initial_input
		self.rows = rows
		self.cols = cols

	def next_input(self, frame) -> int:
		self.current_input = choose_next_input(
			frame,
			prev_input=self.current_input,
			rows=self.rows,
			cols=self.cols,
		)
		return self.current_input

