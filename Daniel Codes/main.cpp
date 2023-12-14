
#include <iostream>
#include "include/BoardGame_Classes.hpp"
using namespace std;
int main() {
    connectFour_X_O_Board x;
//    Connect4Player o(0,'0');
//    Connect4Player b(1, 'x');
    RandomPlayer o('0',7);
    RandomPlayer b('x',7);
    Player* p[2];
    p[0]=&o,p[1]=&b;
    GameManager gm(&x,p);
    gm.run();
}
