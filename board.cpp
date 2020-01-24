#include "board.h"
#include "cell.h"

std::vector<std::vector<char>> board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

std::vector<std::vector<char>> Board::get_board() {
	return board;
}

