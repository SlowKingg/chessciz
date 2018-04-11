#include "board.h"

int piece_check (char *s, Board* board)
{
	bool flag1 = false;
	bool flag2 = false;

	for ( char ltr = 'a'; ltr != 'i'; ltr++) {
		for ( int i = 1; i < 9; i++) {
			if (s[3] == ltr) {
				if ((s[4] - 48) == i) {
					if (board->cell[7-(i-1)][ltr-97].fill == true) {
						if (board->cell[7-(i-1)][ltr-97].piecetype == Pawn) {
							if (board->cell[7-(i-1)][ltr-97].piececolor == White) {
								if (s[3] != s[6]) {
									return -1;
								}

								if (((s[7] - 48) - (s[4] - 48) == 1)\
								 		|| ((s[7] - 48) - (s[4] - 48) == 2)){
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
					if (board->cell[7-(i-1)][ltr-97].fill == true) {
						if (board->cell[7-(i-1)][ltr-97].piecetype == Pawn) {
							if (board->cell[7-(i-1)][ltr-97].piececolor == Black) {
								if (s[9] != s[12]) {
									return -1;
								}

								if (((s[10] - 48) - (s[13] - 48) == 1)\
								 		|| ((s[10] - 48) - (s[13] - 48) == 2)) {
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
		board->cell[7-(s[4]-49)][s[3]-97].fill = false;
		board->cell[7-(s[7]-49)][s[6]-97].fill = true;
		board->cell[7-(s[7]-49)][s[6]-97].piecetype = Pawn;
		board->cell[7-(s[7]-49)][s[6]-97].piececolor = White;

		board->cell[7-(s[10]-49)][s[9]-97].fill = false;
		board->cell[7-(s[13]-49)][s[12]-97].fill = true;
		board->cell[7-(s[13]-49)][s[12]-97].piecetype = Pawn;
		board->cell[7-(s[13]-49)][s[12]-97].piececolor = Black;
	}

	return 0;
}
