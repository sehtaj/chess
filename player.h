#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Player{
protected:
    char color;

public:
    Player(char playerColor);
    virtual ~Player() = default;
    char getColor();
    virtual bool makeMove(Board& board) = 0;
};

#endif