#include "player.h"
#include "gamestate.h"
#include <iostream>
using namespace std;

class Human : public Player{
public:
    Human(char color);
    bool makeMove(string& from, string& to) override;
};