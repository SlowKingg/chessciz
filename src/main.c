#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>

int main () {
    
    Board game;
    
    char move[15];

    fgets(move, sizeof (move), stdin);
    printf ("%s\n", move);
    
    init_board(&game);
    init_default_board(&game);
    print_board(game);
	piece_check (move, &game);
	print_board(game);
    return 0;
}
