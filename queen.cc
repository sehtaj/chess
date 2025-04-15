#include "queen.h"
#include "board.h"

Queen::Queen(char colour) : Piece(colour, 'Q'){}

bool Queen::canMove(Board &board, int startRow, int startCol, int endRow, int endCol){
    bool isValidMove = false;

    if(startRow == endRow && startCol == endCol){
        return false;
    }

    if(endRow < 0 || endRow > 7 || endCol < 0 || endCol > 7){
        return false;
    }

    bool isMovingHorizontally = (startRow == endRow);
    bool isMovingVertically = (startCol == endCol);
    bool isMovingDiagonally = (abs(endRow - startRow) == abs(endCol - startCol));

    if(!isMovingHorizontally && !isMovingVertically && !isMovingDiagonally){
        return false;
    }

    if(isMovingHorizontally){
        int direction = (endCol > startCol) ? 1 : -1;
        int distance = abs(endCol - startCol);
        for(int i = 1; i < distance; ++i){
            int currentCol = startCol + i * direction;
            if(board.getPiece(startRow, currentCol) != nullptr){
                return false;
            }
        }
    }

    if(isMovingVertically){
        int direction = (endRow > startRow) ? 1 : -1;
        int distance = abs(endRow - startRow);
        for(int i = 1; i < distance; ++i){
            int currentRow = startRow + i * direction;
            if(board.getPiece(currentRow, startCol) != nullptr){
                return false;
            }
        }
    }

    if(isMovingDiagonally){
        int rowDirection = (endRow > startRow) ? 1 : -1;
        int colDirection = (endCol > startCol) ? 1 : -1;
        int distance = abs(endRow - startRow);

        for (int i = 1; i < distance; ++i){
            int currentRow = startRow + i * rowDirection;
            int currentCol = startCol + i * colDirection;
            if(board.getPiece(currentRow, currentCol) != nullptr){
                return false;
            }
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