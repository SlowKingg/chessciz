set(SOURCES ./src/main.c ./src/board.c ./src/board_print_plain.c)
include_directories("src/")

add_executable(chess ${SOURCES})