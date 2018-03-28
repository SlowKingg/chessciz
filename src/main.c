#include "board.h"
#include "board_print_plain.h"

int main () {
    
    Board game;
    
    init_board(&game);
    init_default_board(&game);
    print_board(game);

    return 0;
}
