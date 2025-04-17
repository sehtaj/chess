#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "board.h"
#include "player.h"

class GameState{
private:
    Board* board;         
    Player* whitePlayer;  
    Player* blackPlayer;  
    Player* currentPlayer;        

public:
    GameState(Board* board, Player* whitePlayer, Player* blackPlayer);
    ~GameState();

    void start(); 
    bool isCheck(); 
    bool isCheckmate(); 
    bool isStalemate(); 
    void resign(); 
    void whiteWins(); 
    void blackWins(); 
    Player* getCurrentPlayer(); 
    bool processMove(string from, string to, char currentTurn);
};
#endif