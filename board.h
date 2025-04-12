#ifndef BOARD_H
#define BOARD_H

#include <iostream>
using namespace std;

class Board {
    private:
        char grid[8][8];

    public:
        Board();
            void createBoard();
            char getGrid(int row, int col);
            friend std::ostream& operator<<(std::ostream &out, Board &board);
};

#endif