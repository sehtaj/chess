#include "board.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"

Board::Board(){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            grid[i][j] = nullptr;
        }
    }
}

Board::~Board(){
    clearBoard();
}

void Board::initializeBoard(){
    setPiece(0, 0, new Rook('w'));
    setPiece(0, 7, new Rook('w'));
    setPiece(7, 0, new Rook('b'));
    setPiece(7, 7, new Rook('b'));
    setPiece(0, 2, new Bishop('w'));
    setPiece(0, 5, new Bishop('w'));
    setPiece(7, 2, new Bishop('b'));
    setPiece(7, 5, new Bishop('b'));
    setPiece(0, 3, new Queen('w'));
    setPiece(7, 3, new Queen('b'));
}

void Board::clearBoard(){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if (grid[i][j]){
                delete grid[i][j];
                grid[i][j] = nullptr;
            }
        }
    }
}

void Board::setPiece(int row, int col, Piece* piece){
    grid[row][col] = piece;
}

Piece* Board::getPiece(int row, int col){
    return grid[row][col];
}

void Board::removePiece(int row, int col){
    if (grid[row][col]){
        delete grid[row][col];
        grid[row][col] = nullptr;
    }
}

ostream& operator<<(ostream &out, Board &board){
    for(int row = 7; row >= 0; row--){
        out << row + 1 << " ";
        for(int col = 0; col < 8; col++){
            Piece* piece = board.getPiece(row, col);
            if (piece){
                char symbol = piece->getType();
                if (piece->getColour() == 'b'){
                    symbol = tolower(symbol);
                } else{
                    symbol = toupper(symbol);
                }
                out << symbol << " ";
            } else{
                if ((row + col) % 2 != 0){
                    out << "  "; 
                } else{
                    out << "_ ";  
                }
            }
        }
        out << "\n";
    }
    out << "  a b c d e f g h\n";
    return out;
}