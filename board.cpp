#include "board.h"
#include "cell.h"

#include <exception>
#include <iostream>

std::vector<std::vector<Cell>> board;

Board::Board() {
	for (int i = 0; i < 3; i++) {
		std::vector<Cell> row;
		for (int i = 0; i < 3; i++) {
			Cell cell;
			cell.set_status(' ');
			row.push_back(cell);
		}
		board.push_back(row);
	}
}

std::vector<std::vector<Cell>> Board::get_board() {
	return board;
}

bool Board::set_cell(int x, int y, char status) {
	if (x < 3 && y < 3) {
		board[x][y].set_status(status);
		return true;
	}
	else {
		throw_invalid_cell_exception(x, y);
	}
	return false;
}

void Board::throw_invalid_cell_exception(int x, int y) {
	try {
		throw "error: cell (" + std::to_string(x) + ", " + std::to_string(y) + ") does not exist";
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Board::print_board() {
	std::cout << " " << board[0][0].get_status() << "|" << board[1][0].get_status() << "|" << board[2][0].get_status() << std::endl;
	std::cout << "—+-+—" << std::endl;
	std::cout << " " << board[0][0].get_status() << "|" << board[1][0].get_status() << "|" << board[2][0].get_status() << std::endl;
	std::cout << "—+-+—" << std::endl;
	std::cout << " " << board[0][0].get_status() << "|" << board[1][0].get_status() << "|" << board[2][0].get_status() << std::endl;
}