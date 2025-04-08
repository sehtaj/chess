#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen {
private:
    char symbol;

public:
    Queen(char s);
    char getSymbol() const;
    bool isValidMove(int x1, int y1, int x2, int y2);  

};

#endif 