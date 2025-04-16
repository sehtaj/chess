#include "gamestate.h"

GameState::GameState(Board* board, Player* whitePlayer, Player* blackPlayer)
    : board(board), whitePlayer(whitePlayer), blackPlayer(blackPlayer), check(false), checkmate(false), stalemate(false){
    currentPlayer = whitePlayer;
}

GameState::~GameState(){}

void GameState::start(){
    cout << *board;
    cout << currentPlayer->getColor() << "'s turn" << endl;

    bool moveMade = false;
    while(!moveMade){
        moveMade = currentPlayer->makeMove(*board);
    }

    if(isCheckmate()){
        cout << "Checkmate! " << currentPlayer->getColor() << " wins!\n";
        return;
    } else if(isCheck()){
        cout << currentPlayer->getColor() << " is in Check!\n";
    }

    if(currentPlayer == whitePlayer){
        currentPlayer = blackPlayer;
    } else{
        currentPlayer = whitePlayer;
    }
}

bool GameState::isCheck(){
    char myColour = currentPlayer->getColor();
    char enemyColour;
    if(myColour == 'w'){
        enemyColour = 'b';
    } else{
        enemyColour = 'w';
    }

    int kingRow = -1, kingCol = -1;

    for(int row = 1; row <= 8; ++row){
        for(int col = 1; col <= 8; ++col){
            Piece* p = board->getPiece(row, col);
            if(p && p->getType() == 'K' && p->getColour() == myColour){
                kingRow = row;
                kingCol = col;
                break;
            }
        }
    }

    for(int row = 1; row <= 8; ++row){
        for(int col = 1; col <= 8; ++col){

            Piece* enemyPiece = board->getPiece(row, col);

            if(enemyPiece && enemyPiece->getColour() == enemyColour){
                for(int endRow = 1; endRow <= 8; ++endRow){
                    for(int endCol = 1; endCol <= 8; ++endCol){

                        if(enemyPiece->canMove(*board, row, col, endRow, endCol)){
                            Piece* captured = board->getPiece(endRow, endCol);

                            board->setPiece(endRow, endCol, enemyPiece);
                            board->setPiece(row, col, nullptr);
                            
                            Piece* kingPiece = board->getPiece(kingRow, kingCol);
                            if(kingPiece && enemyPiece->canMove(*board, endRow, endCol, kingRow, kingCol)){
                                board->setPiece(row, col, enemyPiece);
                                board->setPiece(endRow, endCol, captured);
                                return true;
                            }
                            board->setPiece(row, col, enemyPiece);
                            board->setPiece(endRow, endCol, captured);
                        }
                    }
                }
            }
        }
    }
    return false; 
}

bool GameState::isCheckmate(){
    if(!isCheck()){
        return false;
    }

    char myColour = currentPlayer->getColor();

    for(int startRow = 1; startRow <= 8; ++startRow){
        for(int startCol = 1; startCol <= 8; ++startCol){
            Piece* piece = board->getPiece(startRow, startCol);

            if(piece && piece->getColour() == myColour){
                for(int endRow = 1; endRow <= 8; ++endRow){
                    for(int endCol = 1; endCol <= 8; ++endCol){
                        if(piece->canMove(*board, startRow, startCol, endRow, endCol)){
                            Piece* captured = board->getPiece(endRow, endCol);
                            board->setPiece(endRow, endCol, piece);
                            board->setPiece(startRow, startCol, nullptr);

                            bool stillInCheck = isCheck();

                            board->setPiece(startRow, startCol, piece);
                            board->setPiece(endRow, endCol, captured);

                            if(!stillInCheck){
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool GameState::isStalemate(){}

void GameState::resign(){
    if(currentPlayer == whitePlayer){
        blackWins();
    } else{
        whiteWins();
    }
}

Player* GameState::getCurrentPlayer(){
    return currentPlayer;
}

void GameState::whiteWins(){
    exit(0);
}

void GameState::blackWins(){
    exit(0);
}
