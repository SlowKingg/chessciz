C = gcc
flag = -c -Wall -Werror

all: chess
chess: make Main.o ChessPrint.o ChessC.o
	$(C) ./build/main.o  ./build/board_print_plain.o ./build/board.o -o ./bin/chess

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
