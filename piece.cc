#include "piece.h"

Piece::Piece(char colour, char type): colour(colour), type(type){}

Piece::~Piece(){}

char Piece::getColour() {
    return colour;
}

char Piece::getType() {
    return type;
}