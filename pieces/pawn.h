#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece {
public:
    Pawn(char colour);
    bool canMove(Board &board, int startRow, int startCol, int endRow, int endCol) override;
};
#endif