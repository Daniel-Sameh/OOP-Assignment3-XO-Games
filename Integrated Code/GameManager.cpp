// Class definition for XO_GameManager class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include <windows.h>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    int x, y;
    system("cls");
    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
                players[i]->get_move(x,y);
                while (!boardPtr->update_board (x,y, players[i]->get_symbol())){
                    players[i]->get_move(x,y);
                }

            system("cls");
            boardPtr->display_board();
            Sleep(500);
            if (!boardPtr->gameID()) {
                if (boardPtr->is_winner()) {
                    cout << players[i]->to_string() << " wins\n";
                    //Sleep(10000);
                    return;
                }
                if (boardPtr->is_draw()) {
                    cout << "Draw!\n";
                    //Sleep(10000);
                    return;
                }
            }
        }
    }
    if(boardPtr->gameID()){
        if(boardPtr->is_winner()){
            cout << players[0]->to_string() << " wins\n";
            //Sleep(10000);
            return;
        }
        else if(boardPtr->is_draw()){
            cout << "Draw!\n";
            //Sleep(10000);
            return;
        }
        else{
            cout << players[1]->to_string() << " wins\n";
            //Sleep(10000);
            return;
        }
    }
}
