#include "cell.h"

#include <iostream>
#include <vector>

char status = ' ';

char Cell::get_status() {
	return status;
}

bool Cell::set_status(char status) {
	if (status == ' ' or status == 'X' or status == 'O') {
		this->status = status;
		return true;
	}
	else {
		throw_invalid_char_exception(status);
	}
	return false;
}

void Cell::throw_invalid_char_exception(char status) {
	try {
		throw "error: can't assign char \'" + std::string(1, status)+ "\' to cell (only \' \', \'X\' and \'O\' allowed)";
	}
	catch (std::string e) {
		std::cout << e << std::endl;
		exit(EXIT_FAILURE);
	}
}