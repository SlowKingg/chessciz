#ifndef CHESS_H
#define CHESS_H

//Structes
typedef enum {
    Pawn,
    Rook,
    Horse,
    Bishop,
    Queen,
    King
} PieceType;

typedef enum {
    White,
    Black
} Color;

typedef enum {
    false,
    true
} bool;

typedef struct {
    bool fill;
    Color color;
    PieceType piecetype;
    Color piececolor;
} Cell;

typedef struct {
    Cell cell [8][8];
} Board;

//Functions

int move (char *s, Board *board);
int str_to_moves (char *s, char *move1, char *move2);
int move_check (char *move, Board *board);
int move_make (char *move, Board *board);
int get_coord (char *move, int *start, int *end);
int game_status (Board *board);

#endif
