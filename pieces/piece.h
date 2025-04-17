#ifndef PIECE_H
#define PIECE_H

class Board;

class Piece{
protected:
    char colour;
    char type;

public:
    Piece(char colour, char type);
    virtual ~Piece();
    char getColour();
    char getType();
    virtual bool canMove(Board &board, int startRow, int startCol, int endRow, int endCol) = 0;
};

#endif