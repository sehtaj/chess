#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece {
public:
    King(char color);
    char getSymbol() const override;
    bool isValidMove(int x1, int y1, int x2, int y2) override;
};

#endif