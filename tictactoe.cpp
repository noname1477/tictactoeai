#include "board.h"
#include "cell.h"

#include <iostream>

void start_game();
void print_menu();
void get_menu_input( int &choice );
void do_menu_action( int choice );

int main()
{
	Board board;
	board.set_cell(2, 1, 'X');
	board.print_board();
	std::cout << "Welcome to Tic Tac Toe v0.0.1!";
	while( true )
	{
		print_menu();
		int choice;
		get_menu_input( choice );
		do_menu_action( choice );
	}
}

void print_menu()
{
	std::cout << "\n\nChoose an option:\n1. Play\n0. Quit\n\n";
}

void get_menu_input( int &choice )
{
	std::cin >> choice;
}

void do_menu_action( int choice )
{
	switch( choice )
	{
		case 0:
			std::cout << "Bye!\n";
			exit( EXIT_SUCCESS );
		case 1:
			start_game();
			break;
		default:
			break;
	}
}

void start_game()
{
	
}