// Class definition for XO game classes
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
#include <iostream>
#include <string>
using namespace std;


class Board {
protected:
     int n_rows, n_cols;
    char** board;
    int  n_moves = 0;
public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    virtual bool update_board (int x,int y, char symbol) = 0;
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    virtual bool is_winner() = 0;
    // Return true if all moves are done and no winner
    virtual bool is_draw() = 0;
    // Display the board and the pieces on it
    virtual void display_board() = 0;
    // Return true if game is over
    virtual bool game_is_over() = 0;
    virtual int gameID()=0;



    // Board(const Board& other);
//   ~Board();
};

///////////////////////////////////////////
// This class represents a 3 x 3 board
// used in X_O game
class X_O_Board:public Board {
public:
    X_O_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int gameID();
};
///////////////////////////////////////////
class connectFour_X_O_Board: public Board {
private:
    int* col;
    int lastPlay=-1;
    char lastSymbol=' ';
public:
    connectFour_X_O_Board ();
    bool update_board (int x,int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int gameID();
    char** getBoard();
    int* getCol();
    void undoPlay(int x);
//   connectFour_X_O_Board(const connectFour_X_O_Board& other);
    connectFour_X_O_Board operator=(const connectFour_X_O_Board& other);
    pair<int,char>getLastPlay();
//   ~connectFour_X_O_Board();
};
////////////////////////////////////////////
class PyramicBoard:public X_O_Board{
public:
    PyramicBoard();
    bool update_board(int x, int y, char mark);
    bool isvalid(int x,int y);
    bool is_winner();
    void display_board();
    void reset(int x, int y) ;
    static int rowsize();
    static int colsize();


};

///////////////////////////////////////////

class _5_tic_tac_toe:public Board {
protected:
    int xs=0,os=0;
public:
    _5_tic_tac_toe ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int gameID();
    //_5_tic_tac_toe(const _5_tic_tac_toe& other);
    ~_5_tic_tac_toe();
};

///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player {
protected:
    string name;
    char symbol;
public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    Player (char symbol); // Needed for computer players
    Player (int order, char symbol);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int& x, int& y);
    // Give player info as a string
    string to_string();
    // Get symbol used by player
    char get_symbol();
};

class Connect4Player:public Player{
public:
    Connect4Player (char symbol); // Needed for computer players
    Connect4Player (int order, char symbol);
    void get_move(int& x, int& y);
    connectFour_X_O_Board & operator=(connectFour_X_O_Board &other);
};



///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class RandomPlayer: public Player {
protected:
    int dimension;
    static int n; // added to know how many random player (to know in win which player won)
public:
    // Take a symbol and pass it to parent
    RandomPlayer (char symbol, int dimension);
    // Generate a random move
    void get_move(int& x, int& y);
};


///////////////////////////////////////////
class GameManager {
protected:
    Board* boardPtr;
    Player* players[2];
public:
    GameManager(Board*, Player* playerPtr[2]);
    virtual void run();
    // This method creates board and players
    // It displays board
    // While True
    //   For each player
    //      It takes a valid move as x, y pair (between 0 - 2)
    //      It updates board and displays otit
    //      If winner, declare so and end
    //      If draw, declare so and end

};

//////////////////////////////////////////////////
//class AIConnect4GameManager:public GameManager{
//private:
//    char AIs,other;
//public:
//    AIConnect4GameManager(Board ,Player playerPtr[2],char AIs, char other);
//    int WinnerRun(int x,bool ai);
//};
/////////////////////////////////////////////////
class AIConnect4Player:public Player{
private:
    connectFour_X_O_Board tmpBoard;
    connectFour_X_O_Board* tmp;
    pair<int,int> minimax(int* col,int play,bool ai);
//    bool empty(int* col);
    int run(int depth,int x,bool ai);
    char otherS;
public:
    AIConnect4Player (connectFour_X_O_Board b,char symbol,char othS);
    AIConnect4Player (connectFour_X_O_Board b,int order, char symbol);
    void get_move(int& x,int& y);
    connectFour_X_O_Board operator=(const connectFour_X_O_Board &other);

};

class PyramicAiPlayer: public Player
{
private:
    PyramicBoard *p_board;

public:
    PyramicAiPlayer(PyramicBoard *b, char symbol);
    void get_move(int &x, int &y);
    int MinMax( bool isMax);
};


#endif
