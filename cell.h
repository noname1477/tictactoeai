#ifndef CELL_H
#define CELL_H

class Cell {
	public:
		char get_status();
		bool set_status(char status);
	private:
		char status = ' ';
		
		void throw_invalid_char_exception(char status);
};

#endif