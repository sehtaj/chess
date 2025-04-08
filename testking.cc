#include <iostream>
#include "king.h"
using namespace std;

int main() {
    King whiteKing('w');
    King blackKing('b');

    cout << "White King Symbol: " << whiteKing.getSymbol() << endl;
    cout << "Black King Symbol: " << blackKing.getSymbol() << endl;

    cout << "Move from (4,4) to (5,5): ";
    if (whiteKing.isValidMove(4, 4, 5, 5)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    cout << "Move from (4,4) to (4,6): ";
    if (whiteKing.isValidMove(4, 4, 4, 6)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    cout << "Move from (7,7) to (6,6): ";
    if (blackKing.isValidMove(7, 7, 6, 6)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}