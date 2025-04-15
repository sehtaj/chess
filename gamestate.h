#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "board.h"
#include "player.h"
#include<map>

class GameState{
private:
    Board* board;         
    Player* whitePlayer;  
    Player* blackPlayer;  
    Player* currentPlayer; 
    bool check;            
    bool checkmate;        
    bool stalemate;        
    map<char, int> fileToCol;

public:
    GameState(Board* board, Player* whitePlayer, Player* blackPlayer);
    ~GameState();

    void start(); 
    bool isCheck(); 
    bool isCheckmate(); 
    bool isStalemate(); 
    void resign(); 
    void updateGameState(); 
    void printState();
    void whiteWins(); 
    void blackWins(); 
    bool isGameOver(); 
    Player* getCurrentPlayer(); 
    bool getRowCol(const std::string& pos, int& row, int& col);
};

#endif