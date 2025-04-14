#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human : public Player{
public:
    Human(char playerColor); 
    bool makeMove(Board &board) override;
};
#endif