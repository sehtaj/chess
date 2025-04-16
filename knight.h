#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece{
public:
    Knight(char colour);
    bool canMove(Board &board, int startRow, int startCol, int endRow, int endCol) override;
};
#endif