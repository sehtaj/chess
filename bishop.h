#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece {
public:
    Bishop(char color);
    char getSymbol() const override;
    bool isValidMove(int x1, int y1, int x2, int y2) override;
};
#endif