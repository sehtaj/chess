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
    void createBoard(); 
    void clearBoard(); 
    Piece* getPiece(int row, int col);
    void setPiece(int row, int col, Piece* piece);
    void removePiece(int row, int col);
    void print(); 
    friend std::ostream& operator<<(std::ostream &out, Board &board);
};
#endif