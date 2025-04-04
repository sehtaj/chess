#include "rook.h"

Rook::Rook(char color) : Piece(color) {}

char Rook::getSymbol() const {
    if (color == 'w') {
        return 'R';
    } else {
        return 'r';
    }
}

bool Rook::isValidMove(int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2) {
        return true;
    } else {
        return false;
    }
}