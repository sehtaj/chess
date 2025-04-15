#include <iostream>
#include <string>
#include <sstream>
#include "board.h"
#include "rook.h"
#include "bishop.h"

// display, quit, move startRow startCol rowToReach colToReach

int main() {
    Board board;
    string input;
    bool gameRunning = true;
    board.initializeBoard();

    char currentTurn = 'w';
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
                cout << "Give value between 0 to 7";// D
                continue;
            }
            
            Piece* piece = board.getPiece(startRow, startCol);

            if (piece == nullptr) {
                cout << "No piece at " << startRow << " " << startCol << endl;
                continue;
            }

            if (piece->getColour() != currentTurn){
                cout << "NOT MY TURN.\n";
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
                if (currentTurn == 'w') {
                    currentTurn = 'b';  
                } else {
                    currentTurn = 'w';  
                }
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
// if a peice is moved from x to y then y should be freed 