//
// Created by Daniel Sameh on 12/9/2023.
//
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

void Connect4Player::get_move(int &x){
    cout << "\nPlease enter your move column (0 to 6) separated by spaces: ";
    cin >> x;
}

Connect4Player::Connect4Player(char symbol) : Player(symbol) {}

Connect4Player::Connect4Player(int order, char symbol) : Player(order, symbol) {}
