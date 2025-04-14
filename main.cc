#include <iostream>
#include <string>
#include <sstream>
#include "board.h"
#include "rook.h"

// display, quit, move startRow startCol rowToReach colToReach

int main() {
    Board board;
    string input;
    bool gameRunning = true;

    board.setPiece(0, 0, new Rook('w'));
    board.setPiece(0, 7, new Rook('w'));
    board.setPiece(7, 0, new Rook('b'));
    board.setPiece(7, 7, new Rook('b'));

    while (gameRunning) {

        getline(cin, input);
        stringstream ss(input);
        string command;
        ss >> command;

        if (command == "quit") {
            cout << "exited";//D
            gameRunning = false;
        }
        else if (command == "display") {
            cout << "board displayed\n";// D
            cout << board;
        }
        else if (command == "move") {
            int startRow, startCol, rowToReach, colToReach;
            if (!(ss >> startRow >> startCol >> rowToReach >> colToReach)) {
                cout << "sjnscjknosn"; // D
                continue;
            }

            if (startRow < 0 || startRow > 7 || startCol < 0 || startCol > 7 || rowToReach < 0 || rowToReach > 7 || colToReach < 0 || colToReach > 7) {
                cout << "000000000000";// D
                continue;
            }

            Piece* piece = board.getPiece(startRow, startCol);
            if (piece == nullptr) {
                cout << "No piece at " << startRow << " " << startCol << endl;
                continue;
            }

            if (piece->canMove(board, startRow, startCol, rowToReach, colToReach)) {
                Piece* target = board.getPiece(rowToReach, colToReach);
                if (target) {
                    if (target->getColour() != piece->getColour()) {
                        cout << "Captured " << target->getColour() << " " << target->getType() << endl;
                        board.removePiece(rowToReach, colToReach);
                    }
                }

                board.setPiece(rowToReach, colToReach, piece);
                board.setPiece(startRow, startCol, nullptr);
                cout << "Move successful!" << endl;// D
                cout << board;
            } else {
                cout << "Invalid move";
            }
        }
        else {
            cout << "Unknown command "<< endl;
        }
    }
    return 0;
}