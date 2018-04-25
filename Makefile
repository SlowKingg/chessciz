C = gcc
flag = -c -Wall -Werror -std=c99
debugflag = -Wall -Werror -std=c99 -g -O0
testflag = -I thirdparty -I src -c

./bin/chess: ./build/src/main.o ./build/src/board_print_plain.o ./build/src/board.o
	$(C) ./build/src/main.o  ./build/src/board_print_plain.o ./build/src/board.o -o ./bin/chess
	$(C) $(debugflag) ./src/main.c ./src/board.c ./src/board_print_plain.c -o ./bin/chess_debug

./build/src/main.o: ./src/main.c
	$(C) $(flag) ./src/main.c -o ./build/src/main.o

./build/src/board_print_plain.o: ./src/board_print_plain.c
	$(C) $(flag) ./src/board_print_plain.c -o ./build/src/board_print_plain.o

./build/src/board.o: ./src/board.c
	$(C) $(flag) ./src/board.c -o ./build/src/board.o

test: ./bin/chesstest

./bin/chesstest: ./build/test/main.o ./build/test/board_test.o
	$(C) ./build/test/main.o ./build/test/board_test.o -o ./bin/chesstest

./build/test/main.o: ./test/main.c
	$(C) $(testflag) ./test/main.c -o ./build/test/main.o

./build/test/board_test.o: ./test/board_test.c
	$(C) $(testflag) ./test/board_test.c -o ./build/test/board_test.o

.PHONY: clean
clean:
	rm -rf ./build/src/*.o
	rm -rf ./build/test/*.o
