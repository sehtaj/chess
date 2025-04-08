#include <iostream>
#include "queen.h"
using namespace std;

int main() {
    Queen whiteQueen('w');
    Queen blackQueen('b');

    cout << "White Queen Symbol: " << whiteQueen.getSymbol() << endl;
    cout << "Black Queen Symbol: " << blackQueen.getSymbol() << endl;

    cout << "Move from (4,4) to (4,7): ";
    if (whiteQueen.isValidMove(4, 4, 4, 7)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    cout << "Move from (4,4) to (6,6): ";
    if (whiteQueen.isValidMove(4, 4, 6, 6)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    cout << "Move from (4,4) to (5,6): ";
    if (whiteQueen.isValidMove(4, 4, 5, 6)) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
    return 0;
}