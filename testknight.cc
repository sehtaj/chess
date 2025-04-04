#include <iostream>
#include "knight.h"

int main() {
    Knight whiteKnight('w');
    cout << "Symbol: " << whiteKnight.getSymbol() << endl;

    cout << "Valid move (0,1 -> 2,2)? ";
    if (whiteKnight.isValidMove(0, 1, 2, 2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}