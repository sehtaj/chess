#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece{
public:
    King(char colour);
    bool canMove(Board &board, int startRow, int startCol, int endRow, int endCol) override;
};
#endif