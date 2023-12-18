//
// Created by Mariam Essam on 12/18/2023.
//
#include "include/BoardGame_Classes.hpp"

PyramicAiPlayer::PyramicAiPlayer(PyramicBoard *b, char symbol) : Player(symbol)
{
    p_board = b;
}

int PyramicAiPlayer::MinMax( bool isMax)
{
    //Check if there's a winner or a draw
    if (p_board->is_winner())
    {
        if(isMax)
            return -1;
        else
            return 1;

    }
    else if (p_board->is_draw())
    {
        return 0;
    }

    // Maxmizing algo
    if (isMax)
    {
        int highestScore = -10e5;
        char sym=this->symbol;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if (p_board->update_board(i, j, sym))
                {
                    int score = MinMax( false);
                    p_board->reset(i, j);
                    //get the highest score
                    highestScore = max(highestScore, score);
                }
            }
        }
        return highestScore;
    }
    else
    //mimize algo
    {
        int lowestscore = 10e5;
        char sym=this->symbol;
        char next_sym;
        if(sym=='x')
            next_sym='o';
        else
            next_sym='x';

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                if (p_board->update_board(i, j, next_sym))
                {
                    int score = MinMax( true);
                    p_board->reset(i, j);
                    //get the lowest score
                    lowestscore = min(lowestscore, score);
                }
            }
        }
        return lowestscore;
    }
}
//update get move function
void PyramicAiPlayer::get_move(int &x, int &y)
{
    int highestScore = -10e5;
    x = y=-1;
    char sym=this->symbol;

    //Try all possible moves to get the best move
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (p_board->update_board(i, j, sym))
            {
                int nw_score = MinMax( false);
                //reset the board
                p_board->reset(i, j);

                // Find the move with the highest score
                if (nw_score > highestScore)
                {
                    highestScore = nw_score;
                    x = i;
                    y = j;
                }
            }
        }
    }
}

