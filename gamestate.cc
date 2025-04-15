#include "gamestate.h"

GameState::GameState(Board* board, Player* whitePlayer, Player* blackPlayer)
    :board(board), whitePlayer(whitePlayer), blackPlayer(blackPlayer){
    currentPlayer = whitePlayer;
}

GameState::~GameState(){}

void GameState::start(){
    bool gameRunning = true;
    while (gameRunning && !isGameOver()){
        cout << board;
        cout << currentPlayer->getColor() << "'s turn" << endl;
    }
}

                                                        // TBD
bool GameState::getRowCol(const std::string& pos, int& row, int& col) { 
    if (pos.length() != 2){
        return false;
    } 

    char alphabet = pos[0];
    char num = pos[1];

    if (alphabet == 'a'){
        col = 0;
    } else if (alphabet == 'b'){
        col = 1;
    } else if (alphabet == 'c'){
        col = 2;
    } else if (alphabet == 'd'){
        col = 3;
    } else if (alphabet == 'e'){
        col = 4;
    } else if (alphabet == 'f'){
        col = 5;
    } else if (alphabet == 'g'){
        col = 6;
    } else if (alphabet == 'h'){
        col = 7;
    } else{
        return false; 
    }

    row = 8 - (num - '0');  
    if (row < 0 || row > 7){
        return false;
    } 
    return true;
}

bool GameState::isCheck(){}

bool GameState::isCheckmate(){}

bool GameState::isStalemate(){}

void GameState::resign(){
    if (currentPlayer == whitePlayer){
        blackWins();
    } else {
        whiteWins();
    }
}

bool GameState::isGameOver(){}

void GameState::updateGameState(){}

Player* GameState::getCurrentPlayer(){
    return currentPlayer;
}

void GameState::printState(){
    cout << board;
}

void GameState::whiteWins(){}

void GameState::blackWins(){}
