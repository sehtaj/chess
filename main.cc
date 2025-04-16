#include <iostream>
#include <string>
#include <sstream>
#include "board.h"
#include "gamestate.h"
#include "human.h"
#include "player.h"

// display, quit, move from to

int main() {
    Board board;
    string input;
    bool gameRunning = true;
    board.initializeBoard();

    cout << "Choose game mode: (1) Human vs Human (2) Human vs Computer: ";
    int choice;
    cin >> choice;

    Player* whitePlayer;
    Player* blackPlayer;

    if (choice == 1) {
        whitePlayer = new Human('w');
        blackPlayer = new Human('b');
    // } else if (choice == 2) {
    //     // Human vs Computer
    //     whitePlayer = new Human('w');
    //     blackPlayer = new Computer('b');  
    } else {
        cout << "Invalid choice, exiting...\n";
        return 1;  
    }

    GameState gameState(&board, whitePlayer, blackPlayer);
    
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
            string from, to;
            ss >> from >> to;

            if (from.size() != 2 || to.size() != 2) {
                cout << "invalid format of input\n";
                continue;
            }

            int startCol = board.getColIndex(from[0]);
            int startRow = from[1] - '0';               
            int colToReach = board.getColIndex(to[0]);  
            int rowToReach = to[1] - '0';  
            
        
            if (startRow < 1 || startRow > 8 || rowToReach < 1 || rowToReach > 8) {
                cout << "Out of bounds\n";
                continue;
            }
            
            Piece* piece = board.getPiece(startRow, startCol);

            if (piece == nullptr) {
                cout << "No piece at " << startRow << " " << startCol << endl;
                continue;
            }

            if (piece->getColour() != currentTurn){
                cout << "NOT YOUR TURN.\n";
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
                cout << "Invalid move\n";
            }
        }
        else {
            cout << "Unknown command\n"<< endl;
        }
    }
    return 0;
}