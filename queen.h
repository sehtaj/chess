#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "board.h"

class Queen : public Piece{
public:
    Queen(char colour);
    bool canMove(Board &board, int startRow, int startCol, int endRow, int endCol) override;
};

#endif