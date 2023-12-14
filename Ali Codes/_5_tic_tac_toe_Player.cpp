// Class definition for XO_Player class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"header.h"
using namespace std;


Player::Player(char symbol) {
    this->symbol = symbol;
}


Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}


void Player::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 5) separated by spaces: ";
    cin >> x >> y;
}

string Player::to_string(){
    return "Player: " + name ;
}
char Player::get_symbol() {
    return symbol;
}
