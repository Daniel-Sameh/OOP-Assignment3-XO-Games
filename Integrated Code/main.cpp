//Authors: Daniel Sameh 20221050 S20
//         Mariam Essam 20220511 S20
//         Ali Mohsen   20221106 S19
//Date:    December @2023
#include <iostream>
#include "include/BoardGame_Classes.hpp"
using namespace std;
int gameType(){
    cout << "To play with - a friend, type 1\n"
            "             - The computer, type 2\n"
            "             - AI player, type 3\n"
            "             - The computer with itself, type anything else:";
    int in;
    cin >> in;
    return in;
}
int main() {
    cout<<"Welcome to Mariam, Daniel & Ali GAMES!\n";
    cout<<"Choose one of those Games: \n";
    cout<<"(1)Classic X_O.\n"
          "(2)Pyramic X_O.\n"
          "(3)Connect four X_O.\n"
          "(4)Last X_O.\n";
    int ch=0; int tmp=0;
    while (ch!=1&&ch!=2&&ch!=3&&ch!=4){
        if (tmp){
            cout<<"Enter a valid option please: \n";
        }
        cin>>ch;
        ++tmp;
    }
    if (ch==1){
        X_O_Board x;
        int in=gameType();
        if (in == 1) {
            Player o(0, '0');
            Player b(1, 'x');
            Player* p[2];
            p[0]=&o,p[1]=&b;
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        } else if (in == 2){
            Connect4Player o(0, '0');
            RandomPlayer b('x',7);
            Player* p[2];
            p[0]=&o,p[1]=&b;
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        }else if (in==3) {
            cout<<"Sorry unavailable AI for this game yet.\n";
        }else{
            RandomPlayer o('0',7);
            RandomPlayer b('x',7);
            Player* p[2];
            p[0]=&o,p[1]=&b;
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        }

    }else if (ch==2){
        cout << "Welcome to Mariam's Pyramic Game!\n";
        PyramicBoard x;
        int in=gameType();
        Player* p[2];
        if (in == 1) {
            p[0]=new  Player (0, 'o'),p[1]=new Player (1, 'x');
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        } else if (in == 2){
//            Player (0, 'o');
//            PyramicRandomPlayer b('x',7);
            p[0]=new Player (0, 'o'),p[1]=new RandomPlayer ('x',5);
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        }else if (in==3) {
            //cout<<"Sorry unavailable AI for this game yet.\n";
            PyramicAiPlayer o(&x,'o');
            Player b(1,'x');
            Player* p[2];
            p[0]=&o,p[1]=&b;
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        }else{
            RandomPlayer o('o',5);
            RandomPlayer b('x',5);
//            Player* p[2];
            p[0]=&o,p[1]=&b;
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        }
    }else if (ch==3){
        cout << "Welcome to Daniel's Connect Four Game!\n";
        connectFour_X_O_Board x;
        int in=gameType();
        if (in == 1) {
            Connect4Player o(0, '0');
            Connect4Player b(1, 'x');
            Player* p[2];
            p[0]=&o,p[1]=&b;
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        } else if (in == 2){
            Connect4Player o(0, '0');
            RandomPlayer b('x',7);
            Player* p[2];
            p[0]=&o,p[1]=&b;
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        }else if (in==3) {
//            cout<<"Sorry unavailable AI for this game yet.\n";
//            AIConnect4Player o(x,'o','x');
//            Connect4Player b(1,'x');
            Player* p[2];
//            p[0]=&o,p[1]=&b;
            p[0]= new  AIConnect4Player (x,'o','x'), p[1]= new Connect4Player (1,'x');
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        }else{
            RandomPlayer o('0',7);
            RandomPlayer b('x',7);
            Player* p[2];
            p[0]=&o,p[1]=&b;
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        }

    }else{
        cout << "Welcome to ALi's 5*5 tic-tac-toe Game!\n";
        _5_tic_tac_toe x;
        int in=gameType();
        if (in==1) {
            Player o(0, '0');
            Player b(1, 'x');
            Player *p[2];
            p[0] = &o, p[1] = &b;
            GameManager gm(&x, p);
            gm.run();
            delete p[0], delete p[1];
        }else if (in==2){
            Player* p[2];
            p[0]=new Player (0, 'o'),p[1]=new RandomPlayer ('x',5);
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        }else if (in==3){
            //cout<<"Sorry unavailable AI for this game yet.\n";
            Player* p[2];
            p[1]= new _5_tic_tac_toe_AIplayer (&x,'O');
            p[0]=new Player (1,'X');
            GameManager gm(&x,p);
            gm.run();
            delete p[0], delete p[1];
        }else{
            RandomPlayer o('o',5);
            RandomPlayer b('x',5);
            Player *p[2];
            p[0] = &o, p[1] = &b;
            GameManager gm(&x, p);
            gm.run();
            delete p[0], delete p[1];
        }
    }
    system ("pause");

}
