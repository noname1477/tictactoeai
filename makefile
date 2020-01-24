CC = g++

all: tictactoe.out

tictactoe.out: tictactoe.o cell.o board.o
	$(CC) -o tictactoe.out tictactoe.o cell.o board.o

clean:
		rm *.o *.out