#include "king.h"
#include "board.h"

King::King(char colour) : Piece(colour, 'K'){}

bool King::canMove(Board &board, int startRow, int startCol, int endRow, int endCol){
    if(startRow == endRow && startCol == endCol){
        return false;
    }

    if(endRow < 1 || endRow > 8 || endCol < 1 || endCol > 8){
        return false;
    }

    int rowDiff = abs(endRow - startRow);
    int colDiff = abs(endCol - startCol);

    if(rowDiff > 1 || colDiff > 1){
        return false;
    }

    Piece* target = board.getPiece(endRow, endCol);
    if(!target){
        return true;
    } else if(target->getColour() != this->getColour()){
        return true;
    }
    return false;
}