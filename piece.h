#ifndef PIECE_H
#define PIECE_H
#include <iostream>
using namespace std;

class Piece {
    protected:
        char color; 
    public:
        Piece(char color) : color(color) {}
        virtual ~Piece() {}  
        virtual char getSymbol() const = 0; 
        virtual bool isValidMove(int x1, int y1, int x2, int y2) = 0; 
};
#endif