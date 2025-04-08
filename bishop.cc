#include "bishop.h"

Bishop::Bishop(char color) : Piece(color) {}
char Bishop::getSymbol() const {
    return (color == 'w') ? 'B' : 'b';
}
bool Bishop::isValidMove(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) == abs(y1 - y2);
}