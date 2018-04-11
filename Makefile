C = gcc
flag = -c -Wall -Werror -std=c99
testflag = -Wall -Werror -std=c99 -g -O0

all: chess
chess: make Main.o ChessPrint.o ChessC.o
	$(C) ./build/main.o  ./build/board_print_plain.o ./build/board.o -o ./bin/chess
	$(C) $(testflag) ./src/main.c ./src/board.c ./src/board_print_plain.c -o ./bin/chesstest
Main.o:
	$(C) $(flag) ./src/main.c -o ./build/main.o

ChessPrint.o:
	$(C) $(flag) ./src/board_print_plain.c -o ./build/board_print_plain.o

ChessC.o:
	$(C) $(flag) ./src/board.c -o ./build/board.o

make:
	mkdir -p bin
	mkdir -p build

.PHONY: clean
clean:
	rm -rf ./build/*.o
