#include "bishop.h"
#include "board.h"

Bishop::Bishop(char colour) : Piece(colour, 'B'){}

bool Bishop::canMove(Board &board, int startRow, int startCol, int endRow, int endCol){
    bool isValidMove = false;

    if(startRow == endRow && startCol == endCol){
        return false;
    }

    if(endRow < 1 || endRow > 8 || endCol < 1 || endCol > 8){
        return false;
    }

    bool isMovingDiagonally =(abs(endRow - startRow) == abs(endCol - startCol));

    if(!isMovingDiagonally){
        return false;
    }

    int rowDirection;
    if(endRow > startRow){
        rowDirection = 1;
    } else{
        rowDirection = -1;
    }

    int colDirection;
    if(endCol > startCol){
        colDirection = 1;
    } else{
        colDirection = -1;
    }

    int distance = abs(endRow - startRow);

    for(int i = 1; i < distance; ++i){
        int currentRow = startRow + i * rowDirection;
        int currentCol = startCol + i * colDirection;
        if(board.getPiece(currentRow, currentCol) != nullptr){
            return false;
        }
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