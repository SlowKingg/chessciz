#include "board.h"
#include "theme.h"
#include <stdio.h>
#include <stdlib.h>

void print_board (Board *board) {
	system ("clear");

    int line,col;

	printf (AQUA BLACKF BOLD"    A  B  C  D  E  F  G  H   \n" DEFAULT);
	printf (AQUA BLACKF BOLD"—————————————————————————————\n" DEFAULT);
    for (line = 0; line < 8; line++) {
    	printf (AQUA BLACKF BOLD "%d ꟾ" DEFAULT, 8 - line);
        for (col = 0; col < 8; col++) {
            if (board->cell[line][col].fill) {
                switch (board->cell[line][col].piecetype) {
				case Pawn:
					if (board->cell[line][col].piececolor == White &&\
							board->cell[line][col].color == White) {
						printf(GREEN GRAYF " P " DEFAULT);
					} else if (board->cell[line][col].piececolor == White &&\
							board->cell[line][col].color == Black) {
						printf(GREEN BLACKF " P " DEFAULT);
					} else if (board->cell[line][col].piececolor == Black &&\
							board->cell[line][col].color == White) {
						printf(RED GRAYF " P " DEFAULT);
					} else if (board->cell[line][col].piececolor == Black &&\
							board->cell[line][col].color == Black) {
						printf(RED BLACKF " P " DEFAULT);
					}
					break;

				case Rook:
					if (board->cell[line][col].piececolor == White &&\
							board->cell[line][col].color == White) {
						printf(GREEN GRAYF " R " DEFAULT);
					} else if (board->cell[line][col].piececolor == White &&\
							board->cell[line][col].color == Black) {
						printf(GREEN BLACKF " R " DEFAULT);
					} else if (board->cell[line][col].piececolor == Black &&\
							board->cell[line][col].color == White) {
						printf(RED GRAYF " R " DEFAULT);
					} else if (board->cell[line][col].piececolor == Black &&\
							board->cell[line][col].color == Black) {
						printf(RED BLACKF " R " DEFAULT);
					}
					break;

				case Horse:
					if (board->cell[line][col].piececolor == White &&\
							board->cell[line][col].color == White) {
						printf(GREEN GRAYF " H " DEFAULT);
					} else if (board->cell[line][col].piececolor == White &&\
							board->cell[line][col].color == Black) {
						printf(GREEN BLACKF " H " DEFAULT);
					} else if (board->cell[line][col].piececolor == Black &&\
							board->cell[line][col].color == White) {
						printf(RED GRAYF " H " DEFAULT);
					} else if (board->cell[line][col].piececolor == Black &&\
							board->cell[line][col].color == Black) {
						printf(RED BLACKF " H " DEFAULT);
					}
					break;

				case Bishop:
					if (board->cell[line][col].piececolor == White &&\
							board->cell[line][col].color == White) {
						printf(GREEN GRAYF " B " DEFAULT);
					} else if (board->cell[line][col].piececolor == White &&\
							board->cell[line][col].color == Black) {
						printf(GREEN BLACKF " B " DEFAULT);
					} else if (board->cell[line][col].piececolor == Black &&\
							board->cell[line][col].color == White) {
						printf(RED GRAYF " B " DEFAULT);
					} else if (board->cell[line][col].piececolor == Black &&\
							board->cell[line][col].color == Black) {
						printf(RED BLACKF " B " DEFAULT);
					}
					break;

				case Queen:
					if (board->cell[line][col].piececolor == White &&\
							board->cell[line][col].color == White) {
						printf(GREEN GRAYF " Q " DEFAULT);
					} else if (board->cell[line][col].piececolor == White &&\
							board->cell[line][col].color == Black) {
						printf(GREEN BLACKF " Q " DEFAULT);
					} else if (board->cell[line][col].piececolor == Black &&\
							board->cell[line][col].color == White) {
						printf(RED GRAYF " Q " DEFAULT);
					} else if (board->cell[line][col].piececolor == Black &&\
							board->cell[line][col].color == Black) {
						printf(RED BLACKF " Q " DEFAULT);
					}
					break;

				case King:
					if (board->cell[line][col].piececolor == White &&\
							board->cell[line][col].color == White) {
						printf(GREEN GRAYF " K " DEFAULT);
					} else if (board->cell[line][col].piececolor == White &&\
							board->cell[line][col].color == Black) {
						printf(GREEN BLACKF " K " DEFAULT);
					} else if (board->cell[line][col].piececolor == Black &&\
							board->cell[line][col].color == White) {
						printf(RED GRAYF " K " DEFAULT);
					} else if (board->cell[line][col].piececolor == Black &&\
							board->cell[line][col].color == Black) {
						printf(RED BLACKF " K " DEFAULT);
					}
					break;
				}
			} else if (board->cell[line][col].color == White){
				printf(GRAYF "   " DEFAULT);
			} else if (board->cell[line][col].color == Black){
				printf(BLACKF "   " DEFAULT);
			}

            if (col == 7) {
    			printf (AQUA BLACKF BOLD "ꟾ %d" DEFAULT, 8 - line);
                printf("\n");
            }
        }
    }
	printf (AQUA BLACKF BOLD"—————————————————————————————\n" DEFAULT);
    printf (AQUA BLACKF BOLD"    A  B  C  D  E  F  G  H   \n" DEFAULT);
	printf( AQUA BLACKF "                             \n" DEFAULT);
}

Board* init_board (Board *board){

	board = malloc (sizeof (Board));
	if (board == NULL) {
		return NULL;
	}

	for (int col = 0; col < 8; col++) {
		for(int line = 0; line < 8; line++) {
			board->cell[line][col].fill = false;

			if (line % 2 == 0) {
				if (col % 2 == 0) {
					board->cell[line][col].color = White;
				} else {
					board->cell[line][col].color = Black;
				}
			} else {
				if (col % 2 == 0) {
					board->cell[line][col].color = Black;
				} else {
					board->cell[line][col].color = White;
				}
			}
		}
	}

	return board;
}

void default_board (Board *board) {
    int line,col;

    line = 1;

    for (col = 0; col <= 7; col++) {
        board->cell[line][col].fill = 1;
        board->cell[line][col].piecetype = Pawn;
        board->cell[line][col].piececolor = Black;
    }

    line = 6;

    for (col = 0; col <= 7; col++) {
        board->cell[line][col].fill = 1;
        board->cell[line][col].piecetype = Pawn;
        board->cell[line][col].piececolor = White;
    }

    line = 0;

    for (col = 0; col <= 7; col++) {
        switch(col) {
        case 0:
        case 7:
            board->cell[line][col].fill = 1;
            board->cell[line][col].piecetype = Rook;
            board->cell[line][col].piececolor = Black;
            break;

        case 1:
        case 6:
            board->cell[line][col].fill = 1;
            board->cell[line][col].piecetype = Horse;
            board->cell[line][col].piececolor = Black;
            break;

        case 2:
        case 5:
            board->cell[line][col].fill = 1;
            board->cell[line][col].piecetype = Bishop;
            board->cell[line][col].piececolor = Black;
            break;

        case 3:
            board->cell[line][col].fill = 1;
            board->cell[line][col].piecetype = Queen;
            board->cell[line][col].piececolor = Black;
            break;

        case 4:
            board->cell[line][col].fill = 1;
            board->cell[line][col].piecetype = King;
            board->cell[line][col].piececolor = Black;
            break;

        default:
            break;
        }
    }

    line = 7;

    for (col = 0; col <= 7; col++) {
        switch(col){
        case 0:
        case 7:
            board->cell[line][col].fill = 1;
            board->cell[line][col].piecetype = Rook;
            board->cell[line][col].piececolor = White;
            break;

        case 1:
        case 6:
            board->cell[line][col].fill = 1;
            board->cell[line][col].piecetype = Horse;
            board->cell[line][col].piececolor = White;
            break;

        case 2:
        case 5:
            board->cell[line][col].fill = 1;
            board->cell[line][col].piecetype = Bishop;
            board->cell[line][col].piececolor = White;
            break;

        case 3:
            board->cell[line][col].fill = 1;
            board->cell[line][col].piecetype = Queen;
            board->cell[line][col].piececolor = White;
            break;

        case 4:
            board->cell[line][col].fill = 1;
            board->cell[line][col].piecetype = King;
            board->cell[line][col].piececolor = White;
            break;

        default:
            break;
        }
    }

    for (line = 3; line < 4; line++) {
        for (col = 0; col < 8; col++) {
            board->cell[line][col].fill = 0;
        }
    }
}
