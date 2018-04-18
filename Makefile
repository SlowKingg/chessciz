C = gcc
flag = -c -Wall -Werror -std=c99
testflag = -Wall -Werror -std=c99 -g -O0

all: chess
chess: Main.o ChessPrint.o ChessC.o
	$(C) ./build/main.o  ./build/board_print_plain.o ./build/board.o -o ./bin/chess
	$(C) $(testflag) ./src/main.c ./src/board.c ./src/board_print_plain.c -o ./bin/chess_debug
Main.o: ./src/main.c
	$(C) $(flag) ./src/main.c -o ./build/main.o

ChessPrint.o: ./src/board_print_plain.c
	$(C) $(flag) ./src/board_print_plain.c -o ./build/board_print_plain.o

ChessC.o: ./src/board.c
	$(C) $(flag) ./src/board.c -o ./build/board.o

.PHONY: clean
clean:
	rm -rf ./build/*.o
