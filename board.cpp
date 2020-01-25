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
	std::cout << std::endl;
	std::cout << " " << board[0][0].get_status() << " | " << board[1][0].get_status() << " | " << board[2][0].get_status() << std::endl;
	std::cout << "---+---+---" << std::endl;
	std::cout << " " << board[0][1].get_status() << " | " << board[1][1].get_status() << " | " << board[2][1].get_status() << std::endl;
	std::cout << "---+---+---" << std::endl;
	std::cout << " " << board[0][2].get_status() << " | " << board[1][2].get_status() << " | " << board[2][2].get_status() << std::endl;
	std::cout << std::endl;
}

bool Board::game_ended() {
	bool ended = false;
	
	for (int i = 0; i < 3; i++) {
		if (board[i][0].get_status() == board[i][1].get_status() && board[i][1].get_status() == board[i][2].get_status() && board[i][1].get_status() != ' ') {
			ended = true;
		}
	}
	
	for (int i = 0; i < 3; i++) {
		if (board[0][i].get_status() == board[1][i].get_status() && board[1][i].get_status() == board[2][i].get_status() && board[1][i].get_status() != ' ') {
			ended = true;
		}
	}
	
	if (board[0][0].get_status() == board[1][1].get_status() && board[1][1].get_status() == board[2][2].get_status() && board[1][1].get_status() != ' ') {
		ended = true;
	}
	
	if (board[2][0].get_status() == board[1][1].get_status() && board[1][1].get_status() == board[0][2].get_status() && board[1][1].get_status() != ' ') {
		ended = true;
	}
	return ended;
}
