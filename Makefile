C = gcc
flag = -c -Wall -Werror -std=c99
testflag = -Wall -Werror -std=c99 -g -O0

./bin/chess: ./build/main.o ./build/board_print_plain.o ./build/board.o
	$(C) ./build/main.o  ./build/board_print_plain.o ./build/board.o -o ./bin/chess
	$(C) $(testflag) ./src/main.c ./src/board.c ./src/board_print_plain.c -o ./bin/chess_debug

./build/main.o: ./src/main.c
	$(C) $(flag) ./src/main.c -o ./build/main.o

./build/board_print_plain.o: ./src/board_print_plain.c
	$(C) $(flag) ./src/board_print_plain.c -o ./build/board_print_plain.o

./build/board.o: ./src/board.c
	$(C) $(flag) ./src/board.c -o ./build/board.o

.PHONY: clean
clean:
	rm -rf ./build/*.o
