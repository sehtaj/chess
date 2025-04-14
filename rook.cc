#include "rook.h"
#include "board.h"

Rook::Rook(char colour) : Piece(colour, 'R'){}

bool Rook::canMove(Board &board, int startRow, int startCol, int endRow, int endCol){
    bool isValidMove = false;
    
    if(startRow == endRow && startCol == endCol){
        return false;
    }
    
    if(endRow < 0 || endRow> 7 || endCol < 0 || endCol > 7){
        return false;
    }
    
    bool isMovingHorizontally = false;
    bool isMovingVertically= false;
    
    if(startRow == endRow){
        isMovingHorizontally = true;
    }
    
    if(startCol == endCol){
        isMovingVertically = true;
    }
    
    if(isMovingHorizontally == false && isMovingVertically == false){
        return false;
    }
        
    if(isMovingHorizontally == true){
        int direction;
        if(endCol > startCol){
            direction = 1; 
        } else{
            direction = -1; 
        }
        int distance = abs(endCol - startCol);
        for (int i = 1; i < distance; i++){
            int currentCol = startCol + (i * direction);
            
            Piece* pieceInWay = board.getPiece(startRow, currentCol);
            
            if(pieceInWay != nullptr){
                return false;
            }
        }
    }
    
    if(isMovingVertically == true){
        int direction;
        if(endRow > startRow){
            direction = 1;
        } else{
            direction = -1; 
        }
        
        int distance = abs(endRow - startRow);
        
        for (int i = 1; i < distance; i++){
            int currentRow = startRow + (i * direction);
            
            Piece* pieceInWay = board.getPiece(currentRow, startCol);
            
            if(pieceInWay != nullptr){
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