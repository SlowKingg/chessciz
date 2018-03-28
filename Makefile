C = gcc
flag = -c -Wall

all: chess
chess: make Main.o ChessPrint.o
	$(C) ./build/main.o  ./build/board_print_plain.o -o ./bin/chess

Main.o: 
	$(C) $(flag) ./src/main.c -o ./build/main.o

ChessPrint.o: 
	$(C) $(flag) ./src/board_print_plain.c -o ./build/board_print_plain.o

make: 
	mkdir -p bin
	mkdir -p build

clean:
	rm -rf ./build/*.o
