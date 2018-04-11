#include "board.h"

int piece_check (char *s, Board* board)
{	
	bool flag1 = false;
	bool flag2 = false;

	for ( char ltr = 'a'; ltr != 'i'; ltr++) {
		for ( int i = 1; i < 9; i++) {		
			if (s[3] == ltr) {
				if ((s[4] - 48) == i) {
					if (board->cell[ltr-97][i-1].fill == true) {
						if (board->cell[ltr-97][i-1].piecetype == Pawn) {
							if (board->cell[ltr-97][i-1].piececolor == White) {
								if (s[3] != s[6]) {
									return -1;
								}
							
								if ((s[7] - 48) - (s[4] - 48) == 1) {
									flag1 = true;
								} else {
									return -1;
								}		
							} else {
								return -1;
							}
						} else {
							return -1;
						}
					} else {
						return -1;
					}
				}
			}
		}
	}
	
	for ( char ltr = 'a'; ltr != 'i'; ltr++) {
		for ( int i = 1; i < 9; i++) {		
			if (s[9] == ltr) {
				if ((s[10] - 48) == i) {
					if (board->cell[ltr-97][i-1].fill == true) {
						if (board->cell[ltr-97][i-1].piecetype == Pawn) {
							if (board->cell[ltr-97][i-1].piececolor == White) {
								if (s[9] != s[12]) {
									return -1;
								}
							
								if ((s[13] - 48) - (s[10] - 48) == 1) {
									flag2 = true;
								} else {
									return -1;
								}		
							} else {
								return -1;
							}
						} else {
							return -1;
						}
					} else {
						return -1;
					}
				}
			}
		}
	}
	
	if (flag1 && flag2) {
		board->cell[s[3]-97][s[4]-49].fill = false;
		board->cell[s[6]-97][s[7]-49].fill = true;
		board->cell[s[6]-97][s[7]-49].piecetype = Pawn;
		board->cell[s[6]-97][s[7]-49].piececolor = White;
		
		board->cell[s[9]-97][s[10]-49].fill = false;
		board->cell[s[12]-97][s[13]-49].fill = true;
		board->cell[s[12]-97][s[13]-49].piecetype = Pawn;
		board->cell[s[12]-97][s[13]-49].piececolor = Black;
	}
	
	return 0;
}
