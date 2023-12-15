// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 2

#include <iostream>
#include "BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player(1, 'X');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;

    if (choice == 1) {
        // Create a RandomPlayer object
        players[1] = new PyramicRandomPlayer('O',5);
    } else {
        // Create a Player object for the second player
        players[1] = new Player(2, 'O');
    }

    // Create an X_O_Board object
    PyramicBoard* board = new PyramicBoard();

    // Create a GameManager object
    GameManager pyramic_game( board, players);

    // Run the game
    pyramic_game.run();

    // Pause the console before exiting
    system("pause");

    return 0;
}
