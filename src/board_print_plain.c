#include "board.h"
#include <stdio.h>

void print_board(Board board) {
    int line,col;

    for (line = 0; line < 8; line++) {
        for (col = 0; col < 8; col++) {
            if (board.cell[line][col].fill) {
                switch (board.cell[line][col].piecetype) {
                case Pawn:
                    if (board.cell[line][col].piececolor == White) {
                        printf("P");
                    } else {
                        printf("p");
                    }
                    break;
                case Rook:
                    if (board.cell[line][col].piececolor == White) {
                        printf("R");
                    } else {
                        printf("r");
                    }
                    break;
                case Horse:
                    if (board.cell[line][col].piececolor == White) {
                        printf("H");
                    } else {
                        printf("h");
                    }
                    break;
                case Bishop:
                    if (board.cell[line][col].piececolor == White) {
                        printf("B");
                    } else {
                        printf("b");
                    }
                    break;
                case Queen:
                    if (board.cell[line][col].piececolor == White) {
                        printf("Q");
                    } else {
                        printf("q");
                    }
                    break;
                case King:
                    if (board.cell[line][col].piececolor == White) {
                        printf("K");
                    } else {
                        printf("k");
                    }
                    break;
                }
            }
            
            if (col == 7) {
                printf("\n");
            }
        }
    }
}

void init_board(Board* board){
    int line,col;
    
    for (col = 0; col < 8; col++) {
        for(line = 0; line < 8; line++) {
            board->cell[line][col].fill = 0;
        }
    }
}

void init_default_board(Board* board) {
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
