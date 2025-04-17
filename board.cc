#include "board.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/queen.h"
#include "pieces/knight.h"
#include "pieces/pawn.h"
#include "pieces/king.h"

Board::Board(){
    for(int i = 1; i <= 8; ++i){
        for(int j = 1; j <= 8; ++j){
            grid[i][j] = nullptr;
        }
    }
}

Board::~Board(){
    clearBoard();
}

void Board::initializeBoard(){
    setPiece(1, 1, new Rook('w'));
    setPiece(1, 2, new Knight('w'));
    setPiece(1, 3, new Bishop('w'));
    setPiece(1, 4, new Queen('w'));
    setPiece(1, 6, new Bishop('w'));
    setPiece(1, 7, new Knight('w'));
    setPiece(1, 8, new Rook('w'));
    setPiece(1, 5, new King('w'));


    for (int col = 1; col <= 8; ++col){
        setPiece(2, col, new Pawn('w')); 
    }

    setPiece(8, 1, new Rook('b'));
    setPiece(8, 2, new Knight('b'));
    setPiece(8, 3, new Bishop('b'));
    setPiece(8, 4, new Queen('b'));
    setPiece(8, 6, new Bishop('b'));
    setPiece(8, 7, new Knight('b'));
    setPiece(8, 8, new Rook('b'));
    setPiece(8, 5, new King('b'));


    for (int col = 1; col <= 8; ++col){
        setPiece(7, col, new Pawn('b'));
    }
}


void Board::clearBoard(){
    for(int i = 1; i <= 8; ++i){
        for(int j = 1; j <= 8; ++j){
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

int Board::getColIndex(const char& pos){
    if (pos == 'a'){
        return 1;
    } else if (pos == 'b'){
        return 2;
    } else if (pos == 'c'){
        return 3;
    } else if (pos == 'd'){
        return 4;
    } else if (pos == 'e'){
        return 5;
    } else if (pos == 'f'){
        return 6;
    } else if (pos == 'g'){
        return 7;
    } else if (pos == 'h'){
        return 8;
    } else{
        return -1;
    }
}

ostream& operator<<(ostream &out, Board &board){
    for(int row = 8; row >= 1; row--){
        out << row << " ";
        for(int col = 1; col <= 8; col++){
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