#include "pawn.h"
#include "board.h"

Pawn::Pawn(char colour) : Piece(colour, 'P'){}

bool Pawn::canMove(Board &board, int startRow, int startCol, int endRow, int endCol){
    if(startRow == endRow && startCol == endCol){
        return false;
    }

    if(endRow < 1 || endRow > 8 || endCol < 1 || endCol > 8){
        return false;
    }

    char myColour = this->getColour();
    int direction;
    if (myColour == 'w'){
        direction = 1;
    } else{
        direction = -1;
    }
    
    Piece* destinationPiece = board.getPiece(endRow, endCol);

    if(endCol == startCol && endRow == startRow + direction && destinationPiece == nullptr){
        return true;
    }

    if(endCol == startCol && destinationPiece == nullptr){
        if((myColour == 'w' && startRow == 2 && endRow == 4) ||
        (myColour == 'b' && startRow == 7 && endRow == 5)){

            Piece* squareBetween = board.getPiece(startRow + direction, startCol);
            if(squareBetween == nullptr){
                return true;
            }
        }
    }

    if(abs(endCol - startCol) == 1 && endRow == startRow + direction){
        if(destinationPiece != nullptr && destinationPiece->getColour() != myColour){
            return true;
        }
    }
    return false;
}