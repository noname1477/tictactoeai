#ifndef BOARD_H
#define BOARD_H

#include "cell.h"

#include <vector>

class Board {
	public:
		Board();
		
		bool set_cell(int x, int y, char status);
		std::vector<std::vector<Cell>> get_board();
		
		void print_board();
		bool game_ended();
		
	private:
		std::vector<std::vector<Cell>> board;
		void throw_invalid_cell_exception(int x, int y);
};

#endif