#include <ctest.h>
#include <board.h>
#include <board_print_plain.h>

CTEST(move_check, pawn_initial_pos_move)
{
	// Given
	char mv [7] = "e2e4\0";
	Board * game = NULL;
	game = init_board(game);
	default_board(game);

	// When
	const int result = move_check(mv, game);

	// Then
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(move_check, pawn_move_true)
{
	// Given
	char mv [7] = "e2e3\0";
	Board * game = NULL;
	game = init_board(game);
	default_board(game);

	// When
	const int result = move_check(mv, game);

	// Then
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(move_check, pawn_move_false)
{
	// Given
	char mv [7] = "e2e5\0";
	Board * game = NULL;
	game = init_board(game);
	default_board(game);

	// When
	const int result = move_check(mv, game);

	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}

CTEST(move_check, rook_move_true)
{
	// Given
	char mv [7] = "h1h4\0";
	Board * game = NULL;
	game = init_board(game);
	default_board(game);
	game->cell[6][7].fill = false;

	// When
	const int result = move_check(mv, game);

	// Then
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(move_check, rook_move_false)
{
	// Given
	char mv [7] = "h1h4\0";
	Board * game = NULL;
	game = init_board(game);
	default_board(game);

	// When
	const int result = move_check(mv, game);

	// Then
	const int expected = -1;
	ASSERT_EQUAL(expected, result);
}
