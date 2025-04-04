#include <iostream>
#include "rook.h"

int main() {
    Rook whiteRook('w');
    Rook blackRook('b');

    cout << "White Rook Symbol: " << whiteRook.getSymbol() << endl;
    cout << "Black Rook Symbol: " << blackRook.getSymbol() << endl;

    if (whiteRook.isValidMove(0, 0, 0, 5))
        cout << "Valid move (0,0) -> (0,5)" << endl;
    else
        cout << "Invalid move (0,0) -> (0,5)" << endl;

    if (whiteRook.isValidMove(0, 0, 3, 3))
        cout << "Valid move (0,0) -> (3,3)" << endl;
    else
        cout << "Invalid move (0,0) -> (3,3)" << endl;

    return 0;
}