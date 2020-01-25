#include "board.h"
#include "cell.h"

#include <iostream>

void print_menu();
void get_menu_input( int &choice );
void do_menu_action( int choice );

void play_game();
bool play_turn(int cnt, Board &board);
void player_turn(Board &board);
void ai_turn(Board &board);

const char PLAYER_CHAR = 'X';
const char AI_CHAR = 'O';

int main() {
	std::cout << "Welcome to Tic Tac Toe v0.0.1!";
	while (true) {
		print_menu();
		int choice;
		get_menu_input( choice );
		do_menu_action( choice );
	}
}

void print_menu() {
	std::cout << "\n\nChoose an option:\n1. Play\n0. Quit\n\n";
}

void get_menu_input( int &choice ) {
	std::cin >> choice;
}

void do_menu_action( int choice ) {
	switch( choice )
	{
		case 0:
			std::cout << "Bye!\n";
			exit( EXIT_SUCCESS );
		case 1:
			play_game();
			break;
		default:
			break;
	}
}

void play_game() {
	Board board;
	int cnt;
	
	while (true) {
		bool finished;
		
		board.print_board();
		finished = play_turn(cnt, board);
		if (finished) {
			break;
		}
		
		cnt++;
	}
}

bool play_turn(int cnt, Board &board) {
	if (cnt % 2 == 0) {
		player_turn(board);
	}
	else {
		ai_turn(board);
	}
	
	return board.game_ended();
}

void player_turn(Board &board) {
	int x;
	int y;
	
	std::cout << "Your turn: ";
	std::cin >> x;
	std::cin >> y;
	
	board.set_cell(x, y, PLAYER_CHAR);
	board.print_board();
}

void ai_turn(Board &board) {
	
}
