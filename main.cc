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

    Player* whitePlayer = nullptr;
    Player* blackPlayer = nullptr;

    int player1, player2;
    cout << "Player 1 (white): for human press 1, for computer press 2 ";
    cin >> player1;
    cout << "Player 2 (black): for human press 1, for computer press 2 ";
    cin >> player2;
    cin.ignore();

    if (player1 == 1) {
        whitePlayer = new Human('w');
    } //else if (player1 == 2){}

    if (player2 == 1) {
        blackPlayer = new Human('b');
    } //else if (player2 == 2){} 

    GameState gameState(&board, whitePlayer, blackPlayer);
    
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
        
            Player* currentPlayer = gameState.getCurrentPlayer();
            if (currentPlayer->makeMove(from, to)) {
                if (gameState.processMove(from, to, currentPlayer->getColor())) {
                    if (gameState.isCheckmate()) {
                        cout << "Checkmate! " << currentPlayer->getColor() << " wins!\n";
                        break;
                    }
                } else {
                    cout << "Invalid move.\n";
                }
            } else {
                cout << "Invalid input.\n";
            }
        
        }
        else if (command == "resign") {
            Player* currentPlayer = gameState.getCurrentPlayer();
            gameState.resign();  
            gameRunning = false;
            cout << currentPlayer->getColor() << " has resigned.\n";
        }
        
        else {
            cout << "Unknown command\n"<< endl;
        }
    }
    return 0;
}
