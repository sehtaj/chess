#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece{
public:
    Rook(char colour);
    bool canMove(Board &board, int initialRow, int initialCol, int rowToReach, int colToReach) override;
};
#endif