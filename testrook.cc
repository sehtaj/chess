#include <iostream>
#include "rook.h"

int main() {
    Rook whiteRook('w');
    Rook blackRook('b');

    std::cout << "White Rook Symbol: " << whiteRook.getSymbol() << std::endl;
    std::cout << "Black Rook Symbol: " << blackRook.getSymbol() << std::endl;

    if (whiteRook.isValidMove(0, 0, 0, 5))
        std::cout << "Valid move (0,0) -> (0,5)" << std::endl;
    else
        std::cout << "Invalid move (0,0) -> (0,5)" << std::endl;

    if (whiteRook.isValidMove(0, 0, 3, 3))
        std::cout << "Valid move (0,0) -> (3,3)" << std::endl;
    else
        std::cout << "Invalid move (0,0) -> (3,3)" << std::endl;

    return 0;
}