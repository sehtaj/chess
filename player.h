#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"
class GameState;
class Player{
protected:
    char color;

public:
    Player(char playerColor);
    virtual ~Player() = default;
    char getColor();
    virtual bool makeMove(string& from, string& to) = 0;
};

#endif