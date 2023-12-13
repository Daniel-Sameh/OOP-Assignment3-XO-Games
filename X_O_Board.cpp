// Class definition for connectFour_X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

// Set the board
connectFour_X_O_Board::connectFour_X_O_Board () {
   n_rows = 6,n_cols = 7;
   board = new char*[n_rows];
   col = new int[n_cols];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++){
         board[i][j] = ' ';
         col[j]=n_rows-1; // to save where should the symbol fall to what row
      }
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool connectFour_X_O_Board::update_board (int x, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > 6) && (col[x]>=0)) {
      board[col[x]--][x] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void connectFour_X_O_Board::display_board() {
    cout << "\n------------------------------";
    for (int i: {0,1,2,3,4,5}) {
      cout << "\n|";
      for (int j: {0,1,2,3,4,5,6}) {
//         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n------------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool connectFour_X_O_Board::is_winner() {
    char row_win[3], col_win[3], diag_win[12];
    int tmp=0; //counter to make sure we have 4 consecutive elements to win
    char b=board[0][0]; //to make sure that the 4 consecutive elements are a character not empty!
    char bb=b;
    //Horizontal Check (Rows)
    for (int i=0;i<n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (board[i][j]==b&&tmp<4){
                ++tmp;
                bb&=board[i][j];
            }else if (bb==b&&tmp==4&&b!=' ')
                return true;
            else if (board[i][j]!=b&&tmp<4){
                tmp=1;
                b=board[i][j];
                bb=b;
            }else{
                tmp=1;
                b=board[i][j];
                bb=b;
            }
        }
        if (board[i][n_cols-1]==b&&tmp==4&&b!=' ') //checking for the last 4 elements in the row ( - - - * * * * )
            return true;
        else
            tmp=0;
    }
    tmp=0;
    //Vertical Check (Columns)
    bb=b;
    for (int i=0;i<n_cols; ++i) {
        for (int j = 0; j < n_rows; ++j) {
            if (board[j][i]==b&&tmp<4){
                ++tmp;
                bb&=board[j][i]; //if they are same sequence it will be the same(bitwise &)
            }else if (bb==b&&tmp==4&&b!=' ')
                return true;
            else if (board[j][i]!=b&&tmp<4){
                tmp=1;
                b=board[j][i];
                bb=b;
            }else{
                tmp=1;
                b=board[j][i];
                bb=b;
            }
        }
        if (board[n_rows-1][i]==b&&tmp==4&&b!=' ') //checking for the last 4 elements in the column
            return true;
        else
            tmp=0;
    }
    tmp=0;
    //All 12 Diagonals
//    for (int d = 0; d < 12; ++d) {
//        if(d<3){
//            for (int i = 0; i < n_rows; ++i) {
//                for (int j = d; j < n_cols-d-1; ++j) {
//                    diag_win[d]&=board[i+1][j];
//                    ++tmp;
//                    if (diag_win[d]==board[i][j]&&tmp==4&&b!=' ')
//                        return true;
//                    else if (tmp==4)
//                        tmp=0;
//                }
//                ++i;
//            }
//        }else{
//            for (int i = 0; i < n_rows-d+3; ++i) {
//                for (int j = d-2; j < n_cols; ++j) {
//                    diag_win[d]&=board[i][j];
//                    ++tmp;
//                    if (diag_win[d]==board[i][j]&&tmp==4&&diag_win[d]!=' ')
//                        return true;
//                    else if (tmp==4)
//                        tmp=0;
//                }
//            }
//        }
////        if (diag_win[d]&&diag_win[d]) //incomplete come here!
////            {return true;}
//    }
    int col_Begin=3,r=0;
    bb=b;
    for (col_Begin; col_Begin >= 0; --col_Begin) {
        for (int j = col_Begin; j < n_cols; ++j) {
            if (board[r][j]==b&&tmp<4){
                ++tmp;
                bb&=board[r][j]; //if they are same sequence it will be the same(bitwise &)
            }else if (bb==b&&tmp==4&&b!=' ')
                return true;
            else if (board[r][j]!=b&&tmp<4){
                tmp=1;
                b=board[r][j];
                bb=b;
            }else{
                tmp=1;
                b=board[r][j];
                bb=b;
            }
            ++r;
            if (r>=n_rows)
                break;
        }
        r=0;
    }
    r=1;
    bb=b;
    for (auto i:{1,2}) {
        for (int j = 0,k=i; j < n_cols,k<n_rows; ++j,++k) {
            if (board[k][j]==b&&tmp<4){
                ++tmp;
                bb&=board[k][j]; //if they are same sequence it will be the same(bitwise &)
            }else if (bb==b&&tmp==4&&b!=' ')
                return true;
            else if (board[k][j]!=b&&tmp<4){
                tmp=1;
                b=board[k][j];
                bb=b;
            }else{
                tmp=1;
                b=board[k][j];
                bb=b;
            }
        }
        if (bb==b&&tmp==4&&b!=' ') //checking for the last 4 elements in the column
            return true;
        else
            tmp=0;
    }
    for (auto i:{3,4,5}) {
        for (int j = 0, k=i; j < n_cols,k>=0; ++j,--k) {
            if (board[k][j]==b&&tmp<4){
                ++tmp;
                bb&=board[k][j]; //if they are same sequence it will be the same(bitwise &)
            }else if (bb==b&&tmp==4&&b!=' ')
                return true;
            else if (board[k][j]!=b&&tmp<4){
                tmp=1;
                b=board[k][j];
                bb=b;
            }else{
                tmp=1;
                b=board[k][j];
                bb=b;
            }
        }
        if (bb==b&&tmp==4&&b!=' ') //checking for the last 4 elements in the column
            return true;
        else
            tmp=0;
    }
    for (auto i:{1,2,3}) { //columns
        for (int j = 5,k=i; j >= 0,k<n_cols; --j,++k) {
            if (board[j][k]==b&&tmp<4){
                ++tmp;
                bb&=board[j][k]; //if they are same sequence it will be the same(bitwise &)
            }else if (bb==b&&tmp==4&&b!=' ')
                return true;
            else if (board[j][k]!=b&&tmp<4){
                tmp=1;
                b=board[j][k];
                bb=b;
            }else{
                tmp=1;
                b=board[j][k];
                bb=b;
            }
        }
        if (bb==b&&tmp==4&&b!=' ') //checking for the last 4 elements in the column
            return true;
        else
            tmp=0;
    }


    return false;
}

// Return true if 9 moves are done and no winner
bool connectFour_X_O_Board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool connectFour_X_O_Board::game_is_over () {
    return n_moves >= 42; //7*6=42
}

connectFour_X_O_Board::~connectFour_X_O_Board() {
    delete[] col;
}

Board::~Board() {
    delete[] board;
}

