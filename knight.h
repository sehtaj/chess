#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight : public Piece {
    public:
        Knight(char color);
        char getSymbol() const override;
        bool isValidMove(int x1, int y1, int x2, int y2) override;
};
#endif