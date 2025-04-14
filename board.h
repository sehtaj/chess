#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "piece.h"

using namespace std;

class Board{
    Piece* grid[8][8]; 

public:
    Board();
    ~Board();
    void initializeBoard();
    void clearBoard(); 
    Piece* getPiece(int row, int col);
    void setPiece(int row, int col, Piece* piece);
    void removePiece(int row, int col);
    friend ostream& operator<<(ostream &out, Board &board);
};
#endif