#include "board.h"
#include <ctype.h>

int move (char *s, Board *board) {

	char m1 [4] = "";

	char m2 [4] = "";

	if (str_to_moves (s, m1, m2) == 2) {
		if (move_check (m1, board) == 0) {
			if (move_make (m1, board)) {
				return -1;
			}
		} else {
			return -1;
		}

		if (move_check (m2, board) == 0) {
			if (move_make (m2, board)) {
				return -1;
			}
		} else {
			return -1;
		}
	} else if (str_to_moves (s, m1, m2) == 1) {
		if (move_check (m1, board) == 0) {
			if (move_make (m1, board)) {
				return -1;
			}
		} else {
			return -1;
		}
	} else {
		return -1;
	}

	return 0;
}

int str_to_moves (char *s, char *move1, char *move2) {
	int m1fill = 0;
	int m2fill = 0;

	for (int k = 0; s[k] != '\n'; k++) {
		bool read = false;

		for (char ltr = 'a'; ltr != 'i' && (!read); ltr++) {
			if (tolower (s[k]) == ltr) {
				if (k < 6) {
					move1 [m1fill] = s[k];
					m1fill++;
					read = true;
				} else {
					move2 [m2fill] = s[k];
					m2fill++;
					read = true;
				}
			}
		}

		if (read) {
			continue;
		}

		for (int i = 1; i < 9 && (!read); i++) {
			if ((s[k]-48) == i) {
				if (k < 6) {
					move1 [m1fill] = s[k];
					m1fill++;
					read = true;
				} else {
					move2 [m2fill] = s[k];
					m2fill++;
					read = true;
				}
			}
		}

		if (s[k] == '\n') {
			break;
		}
	}

	if (((m1fill != 4) || (m2fill != 4))) {
		if (m2fill != 0) {
			return -1;
		}
	}

	move1 [0] = tolower (move1 [0]);
	move1 [2] = tolower (move1 [2]);

	if (m2fill != 0) {
		move2 [0] = tolower (move2 [0]);
		move2 [2] = tolower (move2 [2]);
		return 2;
	}

	return 1;
}

int move_check (char *move, Board *board) {

	int st[2];
	int en[2];

	if (get_coord (move, st, en)) {
		return -1;
	}

	int linedif = st[0] - en[0];
	int coldif = en[1] - st[1];

	if (board->cell[st[0]][st[1]].fill == false) {
		return -1;
	}

	switch (board->cell[st[0]][st[1]].piecetype) {
	case Pawn:
		if (board->cell[en[0]][en[1]].fill && coldif == 0 ) {
			return -1;
		}

		if (board->cell[en[0]][en[1]].fill && (coldif == -1 || coldif == 1) && (linedif == -1 || linedif == 1)) {
			return 0;
		}

		if ((linedif == 1 || linedif == -1) && coldif == 0) {
			if (board->cell[st[0]][st[1]].piececolor == White &&
				 											linedif == -1) {
				return -1;
			}
			if (board->cell[st[0]][st[1]].piececolor == Black &&
				 											linedif == 1) {
				return -1;
			}
			return 0;
		} else if ((linedif == 2 || linedif == -2) && coldif == 0 &&
			((st[0] == 1 && board->cell[st[0]][st[1]].piececolor == Black) ||
			(st[0] == 6 && board->cell[st[0]][st[1]].piececolor == White))) {
			return 0;
		}
		break;

	case Rook:
		if ((linedif != 0 && (linedif < 8 || linedif > -8)) && coldif == 0) {
			if (linedif > 0) {
				for (int line = st[0] - 1; line > en[0]; line--) {
					if (board->cell[line][st[1]].fill) {
						return -1;
					}
				}
			} else if (linedif < 0) {
				for (int line = st[0] + 1; line < en[0]; line++) {
					if (board->cell[line][st[1]].fill) {
						return -1;
					}
				}
			}
			return 0;
		} else if ((coldif != 0 && (coldif < 8 || coldif > -8))
		 													&& linedif == 0) {
			if (coldif > 0) {
				for (int col = st[1] + 1; col < en[1]; col++) {
					if (board->cell[st[0]][col].fill) {
						return -1;
					}
				}
			} else if (coldif < 0) {
				for (int col = st[1] - 1; col > en[1]; col--) {
					if (board->cell[st[0]][col].fill) {
						return -1;
					}
				}
			}
			return 0;
		}
		break;

	case Horse:
		if (linedif == 2 || linedif == -2) {
			if (coldif == 1 || coldif == -1) {
				return 0;
			}
		} else if (coldif == 2 || coldif == -2) {
			if (linedif == 1 || linedif == -1) {
				return 0;
			}
		}
		break;

	case Bishop:
		if ((linedif == coldif) && (coldif != 0)) {
			if (linedif > 0) {
				int col = st[1];

				for (int line = st[0] - 1; line > en [0]; line--) {
					col++;

					if (board->cell[line][col].fill) {
						return -1;
					}
				}
			} else if (linedif < 0) {
				int col = st[1];

				for (int line = st[0] + 1; line < en [0];  line ++) {
					col--;

					if (board->cell[line][col].fill) {
						return -1;
					}
				}
			}
			return 0;
		} else if (((-linedif) == coldif) && (coldif != 0)) {
			if (linedif > 0) {
				int col = st[1];

				for (int line = st[0] - 1; line > en [0]; line--) {
					col--;

					if (board->cell[line][col].fill) {
						return -1;
					}
				}
			} else if (linedif < 0) {
				int col = st[1];

				for (int line = st[0] + 1; line < en [0];  line ++) {
					col++;

					if (board->cell[line][col].fill) {
						return -1;
					}
				}
			}
			return 0;
		}
		break;

	case Queen:
		if ((linedif != 0 && (linedif < 8 || linedif > -8)) && coldif == 0) {
			if (linedif > 0) {
				for (int line = st[0] - 1; line > en[0]; line--) {
					if (board->cell[line][st[1]].fill) {
						return -1;
					}
				}
			} else if (linedif < 0) {
				for (int line = st[0] + 1; line < en[0]; line++) {
					if (board->cell[line][st[1]].fill) {
						return -1;
					}
				}
			}
			return 0;
		} else if ((coldif != 0 && (coldif < 8 || coldif > -8))
		 													&& linedif == 0) {
			if (coldif > 0) {
				for (int col = st[1] + 1; col < en[1]; col++) {
					if (board->cell[st[0]][col].fill) {
						return -1;
					}
				}
			} else if (coldif < 0) {
				for (int col = st[1] - 1; col > en[1]; col--) {
					if (board->cell[st[0]][col].fill) {
						return -1;
					}
				}
			}
			return 0;
		} else if ((linedif == coldif) && (coldif != 0)) {
			if (linedif > 0) {
				int col = st[1];

				for (int line = st[0] - 1; line > en [0]; line--) {
					col++;

					if (board->cell[line][col].fill) {
						return -1;
					}
				}
			} else if (linedif < 0) {
				int col = st[1];

				for (int line = st[0] + 1; line < en [0];  line ++) {
					col--;

					if (board->cell[line][col].fill) {
						return -1;
					}
				}
			}
			return 0;
		} else if (((-linedif) == coldif) && (coldif != 0)) {
			if (linedif > 0) {
				int col = st[1];

				for (int line = st[0] - 1; line > en [0]; line--) {
					col--;

					if (board->cell[line][col].fill) {
						return -1;
					}
				}
			} else if (linedif < 0) {
				int col = st[1];

				for (int line = st[0] + 1; line < en [0];  line ++) {
					col++;

					if (board->cell[line][col].fill) {
						return -1;
					}
				}
			}
			return 0;
		}
		break;

	case King:
		for (int lined = 0; lined < 2; lined++) {
			for (int cold = 0; cold < 2; cold++) {
				if ((cold == 0) && (lined == cold)) {
					continue;
				} else {
					if ((linedif == lined) && (coldif == cold)) {
						return 0;
					} else if ((linedif == (-lined)) && (coldif == (-cold))) {
						return 0;
					} else if ((linedif == lined) && (coldif == (-cold))) {
						return 0;
					} else if ((linedif == (-lined)) && (coldif == cold)) {
						return 0;
					}
				}
			}
		}
		break;

	default:
		return -1;
		break;
	}

	return -1;
}

int move_make (char *move, Board *board) {

	int st[2];
	int en[2];

	if (get_coord (move, st, en)) {
		return -1;
	}

	board->cell[st[0]][st[1]].fill = false;

	board->cell[en[0]][en[1]].fill = true;
	board->cell[en[0]][en[1]].piecetype = board->cell[st[0]][st[1]].piecetype;
	board->cell[en[0]][en[1]].piececolor = board->cell[st[0]][st[1]].piececolor;

	return 0;
}

int get_coord (char *move, int *start, int *end) {

	start [1] = move[0] - 97; //start col
	start [0] = 8 - (move [1] - 48); //start line

	end [1] = move[2] - 97; //end col
	end [0] = 8 - (move [3] - 48); //end line

	return 0;
}

int game_status (Board *board) {

	bool bflag = false;
	bool wflag = false;

	for (int col = 0; col < 8; col++) {
		for(int line = 0; line < 8; line++) {
			if (board->cell[line][col].piecetype == King) {
				switch (board->cell[line][col].piececolor) {
				case Black:
					bflag = true;
					break;
				case White:
					wflag = true;
					break;
				default:
					break;
				}
			}
		}
	}

	if (bflag && wflag) {
		return 0;
	} else if (bflag) {
		return 1;
	} else if (wflag) {
		return 2;
	}

	return -1;
}
