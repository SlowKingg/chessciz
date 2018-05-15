#include "board.h"
#include "board_print_plain.h"
#include "theme.h"
#include <stdio.h>
#include <stdlib.h>

void flush_input(void);

int main () {

char string[12];
char ch;
int read = 0;

Board *game = NULL;

game = init_board (game);

default_board (game);

print_board(game);

printf(AQUA BLACKF "GAME START\n" DEFAULT);

for (int i = 1;;i++) {
	read = 0;

	printf(AQUA BLACKF);

	printf("%d. ", i);

	for (int i = 0; i < sizeof(string); i++) {
		string [i] = ' ';
	}

	do {
		ch = getchar ();
		if (ch == 'q' || ch == 'Q') {
			return 0;
		}

		string [read] = ch;

		if (read == 13) {
			flush_input();
			break;
		}

		read++;
	} while (ch != '\n');

	if (string [11] != '\n' && string [5] != '\n') {
		print_board (game);
		printf(CRED BLACKF "INPUT ERROR\n" AQUA BLACKF);
		i--;
		continue;
	}

	if (move (string, game) == 0) {
		print_board(game);

		printf(AQUA BLACKF);

		if (game_status(game) == 0) {
			printf("GAME IN PROCESS\n");
		} else if (game_status(game) == 1) {
			system("clear");
			printf("\tGAME OVER\n");
			printf("\tRED WIN\n");
			return 0;
		} else if (game_status(game) == 2) {
			system("clear");
			printf("\tGAME OVER\n");
			printf("\tGREEN WIN\n");
			return 0;
		} else {
			printf(DEFAULT RED BLACKF "GAME ERROR\n");
			return 0;
		}
		continue;
	} else {
		print_board (game);
		printf(CRED BLACKF "WRONG MOVE\n" AQUA BLACKF);
		i--;
		continue;
	}
}

return 0;
}

void flush_input(void)
{
    char c;

	c = getc(stdin);
    while (c != '\n') {
		c = getc(stdin);
	}
}
