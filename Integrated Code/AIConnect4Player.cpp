//
// Created by Daniel Sameh on 12/13/2023.
//
#include <iostream>
#include <windows.h>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

AIConnect4Player::AIConnect4Player(connectFour_X_O_Board* b,char symbol,char othS) : Player(symbol) {
    tmpBoard=b;
    otherS=othS;
}

AIConnect4Player::AIConnect4Player(connectFour_X_O_Board* b,int order, char symbol) : Player(order, symbol) { //unnecessary
    tmpBoard=b;
}

void AIConnect4Player::get_move(int &x, int &y) {
    //Initializing a GameManager to try on it all the possible plays.


//    Player* p[2];
//    p[0]=new Connect4Player(symbol);
//    p[1]=new Connect4Player('x');
//    connectFour_X_O_Board bb=*tmpBoard;
//    AIConnect4GameManager aiGm(&bb,p,symbol,'x');


    //Copying the board to cb through tmp(because normal assign will make it point at the original board and will change it)
    char** cb;
    char ** tmp=tmpBoard->getBoard();
    cb=new char*[6];
    for (int i = 0; i < 6; ++i) {
        cb[i]=new char[7];
        for (int j = 0; j < 7; ++j) {
            cb[i][j]=tmp[i][j];
        }
    }
    delete[]tmp;


    int* column=tmpBoard->getCol();
    x = minimax(column,0,false).first;
    y=0; //unnecessary
//    delete p[0];
//    delete p[1];
}

pair<int,int> AIConnect4Player::minimax( int *col, int play,bool ai) {
    int score= -7; // -7 if AI is playing to maximize it, 7 if the opponent is playing
    int move=-1;
    for (int i = 0; i < 7; ++i) {
        if (col[i]>0){
            int rn= run(7,i,ai);
            if(rn>score){
                score=rn;
                move=i;
            }
        }
    }
    return {move,score};
}


int AIConnect4Player::run(int depth,int x, bool ai) {
    int score= ai ? 7 : -7;// -7 if AI is playing to maximize it, 7 if the opponent is playing
    if (!depth){
        return 0;
    }
    if(tmpBoard->game_is_over())
        return 0;

    if (tmpBoard->is_winner()){
        if (ai){
            return -7;
        }else{
            return 7;
        }
    }
    if (tmpBoard->is_draw()) {
        return 0;
    }
    int* cl= tmpBoard->getCol();
    for (int i = 0; i < 7; ++i) {
        if(cl[i]>0){
            tmpBoard->update_board(i,0,ai?otherS:symbol);
            int next= run(depth-1,i,!ai);
            if((ai&&next<score)||(!ai&&next>score)){
                score=next;
            }
            tmpBoard->undoPlay(i);
        }
    }
    return score;
}

//////////////////////////////////////////////////////////////////////

//bool AIConnect4Player::empty(int *col) {
//    int x=0;
//    for (int i = 0; i < 7; ++i) {
//        if (col[i]==0)
//            ++x;
//    }
//    if (x==7)
//        return 1;
//
//    return 0;
//}
