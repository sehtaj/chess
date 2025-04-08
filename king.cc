#include "king.h"

King::King(char color) : Piece(color) {}

char King::getSymbol() const {
    return (color == 'w') ? 'K' : 'k';
}

bool King::isValidMove(int x1, int y1, int x2, int y2) {
    if (abs(x2 - x1) <= 1 && abs(y2 - y1) <= 1) {
        return true;
    }
    return false;
}