#include "board.h"

Board::Board() {
    createBoard();
}

void Board::createBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                grid[i][j] = ' ';  
            } else {
                grid[i][j] = '_';  
            }
        }
    }
}

char Board::getGrid(int row, int col) {
    return grid[row][col];
}

ostream& operator<<(ostream &out, Board &board) {
    for (int i = 0; i < 8; i++) {
        out << 8 - i << " ";
        for (int j = 0; j < 8; j++) {
            out << board.getGrid(i, j) << " ";
        }
        out << endl;
    }
    out << "  a b c d e f g h" << endl;
    return out;
}