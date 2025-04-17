#include "gamestate.h"

GameState::GameState(Board* board, Player* whitePlayer, Player* blackPlayer)
    : board(board), whitePlayer(whitePlayer), blackPlayer(blackPlayer){
        currentPlayer = whitePlayer;
    }

GameState::~GameState(){}

void GameState::start(){
    cout << board;
}

bool GameState::isCheck(){
    char myColour = currentPlayer->getColor();
    char enemyColour;
    if(myColour == 'w'){
        enemyColour = 'b';
    } else{
        enemyColour = 'w';
    }

    int kingRow = -1;
    int kingCol = -1;

    for(int row = 1; row <= 8; ++row){
        for(int col = 1; col <= 8; ++col){
            Piece* piece = board->getPiece(row, col);
            if(piece != nullptr){
                if(piece->getType() == 'K' && piece->getColour() == myColour){
                    kingRow = row;
                    kingCol = col;
                    break;
                }
            }
        }
    }

    for(int row = 1; row <= 8; ++row){
        for(int col = 1; col <= 8; ++col){
            Piece* enemy = board->getPiece(row, col);
            if(enemy != nullptr){
                if(enemy->getColour() == enemyColour){
                    if(enemy->canMove(*board, row, col, kingRow, kingCol)){
                        return true;
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
    
    int kingRow = -1, kingCol = -1;
    for(int row = 1; row <= 8; ++row){
        for(int col = 1; col <= 8; ++col){
            Piece* piece = board->getPiece(row, col);
            if(piece && piece->getType() == 'K' && piece->getColour() == myColour){
                kingRow = row;
                kingCol = col;
                break;
            }
        }
    }

    for(int endRow = kingRow - 1; endRow <= kingRow + 1; ++endRow){
        for(int endCol = kingCol - 1; endCol <= kingCol + 1; ++endCol){
            if(endRow >= 1 && endRow <= 8 && endCol >= 1 && endCol <= 8){
                if(endRow == kingRow && endCol == kingCol){
                    continue;
                } 

                Piece* target = board->getPiece(endRow, endCol);

                if(target && target->getColour() == myColour){
                    continue;
                } 

                Piece* captured = board->getPiece(endRow, endCol);
                board->setPiece(endRow, endCol, board->getPiece(kingRow, kingCol));
                board->setPiece(kingRow, kingCol, nullptr);

                if(!isCheck()){
                    board->setPiece(kingRow, kingCol, board->getPiece(endRow, endCol));
                    board->setPiece(endRow, endCol, captured);
                    return false; 
                }

                board->setPiece(kingRow, kingCol, board->getPiece(endRow, endCol));
                board->setPiece(endRow, endCol, captured);
            }
        }
    }
    return true;
}

bool GameState::isStalemate(){
    if(isCheck()){
        return false;
    }

    char myColour = currentPlayer->getColor();

    for(int startRow = 1; startRow <= 8; ++startRow){
        for(int startCol = 1; startCol <= 8; ++startCol){

            Piece* piece = board->getPiece(startRow, startCol);
            if(!piece || piece->getColour() != myColour){
                continue;
            } 

            for(int endRow = 1; endRow <= 8; ++endRow){
                for(int endCol = 1; endCol <= 8; ++endCol){

                    if(piece->canMove(*board, startRow, startCol, endRow, endCol)){
                        Piece* captured = board->getPiece(endRow, endCol);
                        board->setPiece(endRow, endCol, piece);
                        board->setPiece(startRow, startCol, nullptr);

                        bool inCheck = isCheck();

                        board->setPiece(startRow, startCol, piece);
                        board->setPiece(endRow, endCol, captured);

                        if(!inCheck){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool GameState::processMove(string from, string to, char currentTurn){
    if(from.size() != 2 || to.size() != 2){
        cout << "Invalid input.\n";
        return false;
    }

    int startCol = board->getColIndex(from[0]);
    int startRow = from[1] - '0';
    int colToReach = board->getColIndex(to[0]);
    int rowToReach = to[1] - '0';

    if(startRow < 1 || startRow > 8 || rowToReach < 1 || rowToReach > 8 ||
        startCol < 1 || startCol > 8 || colToReach < 1 || colToReach > 8){
        cout << "Out of bounds\n";
        return false;
    }

    Piece* piece = board->getPiece(startRow, startCol);
    if(!piece){
        cout << "No piece at " << from << "\n";
        return false;
    }

    if(piece->getColour() != currentTurn){
        cout << "Not your turn.\n";
        return false;
    }

    if(!piece->canMove(*board, startRow, startCol, rowToReach, colToReach)){
        cout << "Invalid move\n";
        return false;
    }

    Piece* target = board->getPiece(rowToReach, colToReach);

    board->setPiece(rowToReach, colToReach, piece);
    board->setPiece(startRow, startCol, nullptr);

    if(isCheck()){
        board->setPiece(startRow, startCol, piece);
        board->setPiece(rowToReach, colToReach, target);
        cout << "King still in check\n";
        return false;
    }

    if(isCheckmate()){
        cout << "Checkmate! " << currentTurn << " loses.\n";
        if(currentTurn == 'w'){
            blackWins();
        } else{
            whiteWins();
        }
        return true;
    }

    if(isStalemate()){
        cout << "Stalemate! The game is a draw.\n";
        return true;
    }

    if(target && target->getColour() != piece->getColour()){
        cout << "Captured " << target->getColour() << " " << target->getType() << "\n";
    }

    cout << "Move successful!\n";
    cout << *board;

    currentPlayer =(currentPlayer == whitePlayer) ? blackPlayer : whitePlayer;

    if(currentPlayer->getColor() == 'w' && isCheck()){
        cout << "White's king is in check!\n";
    } else if(currentPlayer->getColor() == 'b' && isCheck()){
        cout << "Black's king is in check!\n";
    }
    return true;
}

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
    cout << "White Wins\n";
}

void GameState::blackWins(){
    cout << "Black Wins\n";
}
