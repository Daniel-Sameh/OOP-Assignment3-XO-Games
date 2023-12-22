//
// Created by Daniel Sameh on 12/13/2023.
//

#include <iostream>
#include <windows.h>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

AIConnect4Player::AIConnect4Player(connectFour_X_O_Board& b,char symbol,char othS) : Player(symbol) {
    tmpBoard=b;
    otherS=othS;
    tmp=&b;

}

AIConnect4Player::AIConnect4Player(connectFour_X_O_Board b,int order, char symbol) : Player(order, symbol) { //unnecessary
    tmpBoard=b;
    tmp=&b;
}

void AIConnect4Player::get_move(int &x, int &y) {
    auto ss=tmp->getLastPlay();
    if(ss.first!=-1&&ss.second!=' ')
        tmpBoard.update_board(ss.first,0,ss.second);
//    cout<<"tmpBoard seeing: \n";
//    tmpBoard.display_board();
    //Sleep(1000);
    int* column=tmpBoard.getCol();
    int score=-7;
    for (int i = 0; i < 7; ++i) {
        if(column[i]>=0){
            tmpBoard.update_board(i,0,symbol);
            column=tmpBoard.getCol();
            auto ss = minimax(column,5,true);
            if(ss>score){
                score=ss;
                x=i;
//                cout<<"Good probability:\n";
//                tmpBoard.display_board();
//                Sleep(100);
            }
//            else if(ss>7){
//                score=ss;
//                x=i;
//                break;
//            }
            tmpBoard.undoPlay(i);
            column=tmpBoard.getCol();
        }
    }

    //x = minimax(column,false).first;
    tmpBoard.update_board(x,0,symbol);
    y=0; //unnecessary
}

int AIConnect4Player::minimax( int *col,int depth, bool ai) {
//    int score= ai? 7 : -7; // -7 if AI is playing to maximize it, 7 if the opponent is playing
    int score= evaluate(ai);
    if(!depth||score!=1){
        return score;
    }
    //int move=-1;
    score= ai? 7 : -7;
    if(score==-7){ //AI
        for (int i = 0; i < 7; ++i) {
            if (col[i]>=0){
                int save= savefromLoss(i, false);
                if(save<7&&save!=0) {
//                    cout<<"SAVE HERE!\n";
//                    tmpBoard.display_board();
//                    Sleep(500);
                    return save;
                }
                tmpBoard.update_board(i,0,'x');
                col=tmpBoard.getCol();
                int rn= minimax(col,depth-1,true);
                if(rn>score){
                    score=rn;
                }
                tmpBoard.undoPlay(i);
                col=tmpBoard.getCol();
            }
        }
    }else{ //Other Player
        for (int i = 0; i < 7; ++i) {
            if (col[i]>=0){
                int save= savefromLoss(i,true);
                if(save>7&&save!=0)
                    return save;
                tmpBoard.update_board(i,0,'o');
                col=tmpBoard.getCol();
                int rn= minimax(col,depth-1,false);
                if(rn<score){
                    score=rn;
                }
                tmpBoard.undoPlay(i);
                col=tmpBoard.getCol();
            }
        }
    }
    return score;
}


int AIConnect4Player::run(int depth,int x, bool ai) {  // ai=true-> other player, ai=false-> AI player
    if (!depth||tmpBoard.game_is_over()){
        return evaluate(ai);
    }
    if (tmpBoard.is_winner()) {
        return ai ? 7 : -7; // Assign higher scores for deeper wins
    }
//    if (tmpBoard.is_winner()){
//        if (ai){
//            return -7;
//        }else{
//            return 7;
//        }
//    }
    if (tmpBoard.is_draw()) {
        return 0;
    }
    tmpBoard.update_board(x,0,ai?otherS:symbol);
    int* cl= tmpBoard.getCol();
    int score= ai ? 7 : -7;// -inf if AI is playing to maximize it, +inf if the opponent is playing
    for (int i = 0; i < 7; ++i) {
        if(cl[i]>0){
            tmpBoard.update_board(i,0,!ai?otherS:symbol);
            int next= run(depth-1,i,!ai);
            tmpBoard.undoPlay(i);

            if (!ai) {
                score = max(score, next);
//                cout<<"Score= "<<score<<"\n";
//                tmpBoard.display_board();
            } else {
                score = min(score, next);
//                cout<<"Score= "<<score<<"\n";
//                tmpBoard.display_board();
            }
           // if((ai&&next<score)||(!ai&&next>score)){
             //   score=next;
//                cout<<"Wanted next score:"<<score<<"\n";
//                tmpBoard.display_board();
//                cout<<endl;
//                if(score>=7)
//                    Sleep(1000);
            //}
        }
    }
    tmpBoard.undoPlay(x);
    return score;
}

//////////////////////////////////////////////////////////////////////

int AIConnect4Player::evaluate(bool ai) {
    if (tmpBoard.is_winner()) {
        return !ai ? -7 : 7; // Assign higher scores for deeper wins
    } else if (tmpBoard.is_draw()) {
        return 0;
    } else {
        return 1;
    }
}

int AIConnect4Player::savefromLoss(int move,bool ai) {
    if(!tmpBoard.is_winner()){
        if(ai){
            tmpBoard.update_board(move,0,'x');
            if(tmpBoard.is_winner()){
                tmpBoard.undoPlay(move);
                return 1000;
            }else{
                tmpBoard.undoPlay(move);
            }
        }else{ //not ok
            tmpBoard.update_board(move,0,'o');
            if(tmpBoard.is_winner()) {
                tmpBoard.undoPlay(move);
                return -1000;
            }else{
                tmpBoard.undoPlay(move);
            }
        }
    }
    return 0;
}


