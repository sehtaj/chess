#include "queen.h"

Queen::Queen(char s) : symbol(s) {}

char Queen::getSymbol() const {
    return symbol;
}

bool Queen::isValidMove(int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2) {
        return true; 
    } else if (abs(x1 - x2) == abs(y1 - y2)) {
        return true; 
    } else {
        return false; 
    }
}