#include "BoardGame_Classes.hpp"
void PyramicRandomPlayer::get_move(int &x, int &y,PyramicBoard &board) {
    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, dimension-1);


    // Generate random coordinates until a valid move is found
    while (true) {
        x = dis(gen);
        y = dis(gen);

        if (board.isvalid(x, y)) {
            break;
        }
    }
}

PyramicRandomPlayer::PyramicRandomPlayer(char symbol,int dimension) : RandomPlayer(symbol,dimension){}