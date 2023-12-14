//
// Created by VICTUS on 12/7/2023.
//
#include "header.h"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
_5_tic_tac_toe::_5_tic_tac_toe () {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
//////////////////////////////////////////////////////////////
bool _5_tic_tac_toe::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

//////////////////////////////////////////////////////////////
void _5_tic_tac_toe::display_board()
{
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
//////////////////////////////////////////////////////////////
bool _5_tic_tac_toe::is_winner() {
    if (!game_is_over()) {
        return false;
    }

    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (board[i][j] == 'O') {
                int c = 1;
                int q = j + 1;
                while ((i >= 0 && i < 5 && q >= 0 && q < 5) && board[i][q] == board[i][j] && c < 3) {
                    c++;
                    q++;
                }
                if (c == 3)os++;
            }
            if (board[i][j] == 'X') {
                int c = 1;
                int q = j + 1;
                while ((i >= 0 && i < 5 && q >= 0 && q < 5) && board[i][q] == board[i][j] && c < 3) {
                    c++;
                    q++;
                }
                if (c == 3)xs++;
            }
        }
    }
    //os=0,xs=0;
//    cout <<os<<" "<<xs<<endl;
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (board[i][j] == 'O') {
                int c = 1;
                int q = i + 1;
                while ((i >= 0 && i < 5 && q >= 0 && q < 5) && board[q][j] == board[i][j] && c < 3) {
                    c++;
                    q++;
                }
                if (c == 3)os++;
            }
            if (board[i][j] == 'X') {
                int c = 1;
                int q = i + 1;
                while ((i >= 0 && i < 5 && q >= 0 && q < 5) && board[q][j] == board[i][j] && c < 3) {
                    c++;
                    q++;
                }
                if (c == 3)xs++;
            }
        }
    }
   // cout <<os<<" "<<xs<<endl;
   // os=0,xs=0;

    for (int i = 0; i < n_rows - 2; i++) {
        for (int j = 0; j < n_cols - 2; j++) {
            if (board[j][i] == 'O') {
                if ((i + 1 >= 0 && i + 1 < 5 && j + 1 >= 0 && j + 1 < 5) &&
                    (i + 2 >= 0 && i + 2 < 5 && j + 2 >= 0 && j + 2 < 5) && board[i + 1][j + 1] == board[i][j] &&
                    board[i + 2][j + 2] == board[i][j]) {
                    os++;
                }
            }
            if (board[j][i] == 'X') {
                if ((i + 1 >= 0 && i + 1 < 5 && j + 1 >= 0 && j + 1 < 5) &&
                    (i + 2 >= 0 && i + 2 < 5 && j + 2 >= 0 && j + 2 < 5) && board[i + 1][j + 1] == board[i][j] &&
                    board[i + 2][j + 2] == board[i][j]) {
                    xs++;
                }
            }
        }
    }
   //  cout <<os<<" "<<xs<<endl;
xs=0,os=0;
    for (int i = 2; i < n_rows ; i++) {
        for (int j = 0; j < n_cols-2; j++) {
            if (board[i][j] == 'O') {
                if ((j + 1 >= 0 && j + 1 < 5 && i - 1 >= 0 && i - 1 < 5) &&
                    (j + 2 >= 0 && j + 2 < 5 && i - 2 >= 0 && i - 2 < 5) && board[i - 1][j + 1] == board[i][j] &&
                    board[i - 2][j + 2] == board[i][j]) {
                    os++;
                }
            }
            if (board[i][j] == 'X') {
                if ((j + 1 >= 0 && j + 1 < 5 && i - 1 >= 0 && i - 1 < 5) &&
                    (j + 2 >= 0 && j + 2 < 5 && i - 2 >= 0 && i - 2 < 5) && board[i - 1][j + 1] == board[i][j] &&
                    board[i - 2][j + 2] == board[i][j]) {
                    xs++;
                }
            }
        }
    }

    if (xs > os) {
        return true;
    }
    else {
        return false;
    }
}
//////////////////////////////////////////////////////////////
bool _5_tic_tac_toe::is_draw(){
    if(n_moves == 24&&xs==os){
        return 1;
    }
    else return 0;
}
//////////////////////////////////////////////////////////////
bool _5_tic_tac_toe::gameID() {
    return 1;
};
//////////////////////////////////////////////////////////////
bool _5_tic_tac_toe::game_is_over() {
    return (n_moves>=24);
}