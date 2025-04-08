#include <iostream>
#include "bishop.h"
using namespace std;

int main() {
    Bishop whiteBishop('w');
    Bishop blackBishop('b');

    cout << "White Bishop Symbol: " << whiteBishop.getSymbol() << endl;
    cout << "Black Bishop Symbol: " << blackBishop.getSymbol() << endl;

    cout << "Testing moves for Bishop:" << endl;
    
    cout << "Move from (2,0) to (5,3): ";
    cout << (whiteBishop.isValidMove(2, 0, 5, 3) ? "Valid" : "Invalid") << endl;

    cout << "Move from (4,4) to (6,2): ";
    cout << (whiteBishop.isValidMove(4, 4, 6, 2) ? "Valid" : "Invalid") << endl;

    cout << "Move from (1,1) to (1,3): ";
    cout << (blackBishop.isValidMove(1, 1, 1, 3) ? "Valid" : "Invalid") << endl;

    return 0;
}