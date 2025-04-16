#include "knight.h"
#include "board.h"

Knight::Knight(char colour) : Piece(colour, 'N'){}

bool Knight::canMove(Board &board, int startRow, int startCol, int endRow, int endCol){
    bool isValidMove = false;

    if(startRow == endRow && startCol == endCol){
        return false;
    }

    if(endRow < 1 || endRow > 8 || endCol < 1 || endCol > 8){
        return false;
    }

    int rowDiff = abs(endRow - startRow);
    int colDiff = abs(endCol - startCol);

    if(rowDiff != 1 && rowDiff != 2){
        return false;
    }
    
    if(colDiff != 1 && colDiff != 2){
        return false;
    }

    Piece* pieceAtDestination = board.getPiece(endRow, endCol);

    if(pieceAtDestination == nullptr){
        isValidMove = true;
    } else{
        char pieceColour = pieceAtDestination->getColour();
        char myColour = this->getColour();

        if(pieceColour != myColour){
            isValidMove = true;
        } else{
            isValidMove = false;
        }
    }
    return isValidMove;
}