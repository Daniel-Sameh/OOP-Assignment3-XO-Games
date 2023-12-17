// Class definition for XO_RandomPlayer class
// Which is a computer player playing randomly
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
RandomPlayer::RandomPlayer (char symbol, int dimension):Player(symbol)
{
    srand(time(NULL));
    this->dimension = dimension;
    this->name = "Random Computer Player "+ std::to_string(n++);
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}

int RandomPlayer::n=1;
