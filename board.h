#ifndef BOARD_H
#define BOARD_H

#include "cell.h"

#include <vector>

class Board {
	public:
		std::vector<std::vector<char>> get_board();
		
	private:
		std::vector<std::vector<char>> board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
};

#endif