#ifndef H_Chess
#define H_Chess
 
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
} PieceColor;

typedef enum {
    false,
    true
} bool;

typedef struct {
    bool fill;
    PieceType piecetype;
    PieceColor piececolor;
} Cell;

typedef struct {
    Cell cell [8][8];
} Board;

int piece_check (char *move, Board* board);

#endif
