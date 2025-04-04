#include "knight.h"
#include <cmath>

Knight::Knight(char color) : Piece(color) {}

char Knight::getSymbol() const {
    if (color == 'w') {
        return 'N';
    } else {
        return 'n'; 
    }
}

bool Knight::isValidMove(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
}