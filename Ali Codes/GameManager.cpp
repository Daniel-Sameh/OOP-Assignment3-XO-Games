
#include <iostream>
#include"header.h"
using namespace std;

GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    int x, y;

    boardPtr->display_board();
    int depth_;
    if(boardPtr->gameID()) depth_ = 10;
    int add=0;
    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x,depth_, y,boardPtr);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, depth_,y,boardPtr);
            }


            cout<<"--------------------------------------";
            boardPtr->display_board();
            if(!boardPtr->gameID())
            {
                if (boardPtr->is_winner()) {
                    cout << players[i]->to_string() << " wins\n";
                    return;
                }
                if (boardPtr->is_draw()) {
                    cout << "Draw!\n";
                    return;
                }
            }

        }
    }
    if(boardPtr->gameID()){
        if(boardPtr->is_winner()){
            cout << players[0]->to_string() << " wins\n";
            return;
        }
        else if(boardPtr->is_draw()){
            cout << "Draw!\n";
            return;
        }
        else{
            cout << players[1]->to_string() << " wins\n";
            return;
        }
    }
}
