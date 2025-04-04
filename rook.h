#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
public:
    Rook(char color);
    char getSymbol() const override;
    bool isValidMove(int x1, int y1, int x2, int y2) override;
};

#endif // ROOK_H