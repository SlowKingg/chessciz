cmake_minimum_required(VERSION 3.10)
set(CMAKE_C_STANDARD 99)

set(SOURCES ./src/main.c ./src/board.c ./src/board_print_plain.c)
set(TSOURCES ./src/board.c ./src/board_print_plain.c ./src/sum.c
            ./test/main.c ./test/test.c ./test/board_test.c)
include_directories("src/")
include_directories("thirdparty/")

add_executable(chess ${SOURCES})

add_executable(chesstest ${TSOURCES})

enable_testing()
add_test(chesstest chesstest)