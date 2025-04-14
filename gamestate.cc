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
