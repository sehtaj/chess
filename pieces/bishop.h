#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece{
public:
    Bishop(char colour);
    bool canMove(Board &board, int startRow, int startCol, int endRow, int endCol) override;
};

#endif