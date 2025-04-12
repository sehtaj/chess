#include <iostream>
#include <string>
#include "board.h"

int main() {
    Board board;
    string command;
    bool running = true;
    
    while(running) {
        cout << " Started the command\n";
        getline(cin, command);
        cout << "Command taken\n";
        
        if(command == "quit") {
            running = false;
            cout << "ended" << endl;
        }
        else if(command == "display") {
            cout << board << endl;
        }
        else {
            cout << "Unknown command." << endl;
        }
    }
    return 0;
}