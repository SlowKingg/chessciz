#include "board.h"
#include "board_print_plain.h"
#include "theme.h"
#include <stdio.h>

int main () {

char string[15];
char ch;
int j = 0;

Board *game = NULL;

game = init_board (game);

default_board (game);

print_board(game);

printf(AQUA BLACKF "GAME START\n" DEFAULT);

for (int i = 1;;i++) {
	printf(AQUA BLACKF);

	printf("%d. ", i);

	do {
		ch = getc (stdin);
		if (ch == 'q' || ch == 'Q') {
			return 0;
		}
		string [j] = ch;
		j ++;
	} while (ch != '\n');

	j = 0;

	if (move (string, game) == 0) {
		print_board(game);
		
		printf(AQUA BLACKF);

		if (game_status(game) == 0) {
			printf("GAME IN PROCESS\n");
		} else if (game_status(game) == 1) {
			printf("GAME OVER\n");
			printf("RED WIN\n");
			return 0;
		} else if (game_status(game) == 2) {
			printf("GAME OVER\n");
			printf("GREEN WIN\n");
			return 0;
		} else {
			printf(DEFAULT RED BLACKF "ERROR\n");
			return 0;
		}
		continue;
	} else {
		printf(CRED BLACKF "ERROR\n" AQUA BLACKF);
		i--;
		continue;
	}
}

return 0;
}
