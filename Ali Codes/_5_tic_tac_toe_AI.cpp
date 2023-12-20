#include "header.h"
using namespace std;
_5_tic_tac_toe_AIplayer::_5_tic_tac_toe_AIplayer(char symbol): Player(symbol) {
    this->name="smart computer";
};

int _5_tic_tac_toe_AIplayer::check_for_winner(int n_moves) {
    int n_rows=5,n_cols=5,xs=0,os=0;
    if(n_moves<24)return 1;
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
    //xs=0,os=0;
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
    if(xs>os){
        return -5;
    }
    else if(xs==os){
        is_draw=true;
        return 0;
    }
    else{
        return 5;
    }

}
vector<pair<int,int>>_5_tic_tac_toe_AIplayer ::get_x_cells(){
    vector<pair<int,int>> XS;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(board[i][j]=='X'){ XS.push_back({i, j}); }
        }
    }
    return XS;
};
void _5_tic_tac_toe_AIplayer::close_path(int &x,int &y,vector<pair<int,int>>& XS){
  int xd[]={1,0,-1,0,1,1,-1,-1} ,yd[]={0,1,0,-1,1,-1,1,-1};
for(auto it:XS){
    int first=it.first,second=it.second;

    for(int i=0;i<8;i++){
        if(first+xd[i]>=0&&first+xd[i]<5&&second+yd[i]>=0&&second+yd[i]<5){
           int q=xd[i],v=yd[i];
           bool ck=false;
            while(first+q>=0&&first+q<5&&second+v>=0&&second+v<5&&board[first+q][second+v]==board[first][second]&&(board[first][second]=='X'||board[first][second]=='O')){
                ck=true;
                q+=xd[i],v+=yd[i];
            }
            if(ck){
                if(first+q>=0&&first+q<5&&second+v>=0&&second+v<5&&board[first+q][second+v]!='X'&&board[first+q][second+v]!='O') {
                    x = first + q,
                    y = second + v;
                    return ; }
            }
        }
    }

}
    x = (int) (rand()/(RAND_MAX + 1.0) * 5);
    y = (int) (rand()/(RAND_MAX + 1.0) * 5);
    return;
};
void _5_tic_tac_toe_AIplayer::get_move(int &x, int depth,int &y,Board* ptr) {
     char** Board=ptr->get_board();
    board_pointer=ptr;
    for(int i=0;i<5;i++){
        for (int j = 0; j < 5; ++j) {
            board[i][j]=Board[i][j];
        }
    }


    if(ptr->get_n_moves()>=14){ best_move(depth, false, ptr->get_n_moves(), true, x, y); }
else{
    vector<pair<int,int>> XS=get_x_cells();
        close_path(x,y,XS);
}
}
int _5_tic_tac_toe_AIplayer::best_move( int depth, bool ismin, int n_moves, bool first_call, int& coordinate_x, int& coordinate_y){

    {
        if (n_moves >= 24 || depth == 0) {
            return check_for_winner(n_moves);
        }
        if (!ismin) {
            int final_result = -1e9;
            int finalx, finaly;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (board[i][j] != 'X' && board[i][j] != 'O') {
                        board[i][j] = 'O';
                        int scr = best_move(depth - 1, !ismin, n_moves + 1, false, coordinate_x, coordinate_y);
                        board[i][j] = ' ';
                        if (final_result < scr) {
                            final_result = scr;
                            finalx = i, finaly = j;
                        }
                    }
                }
            }
            if (first_call) {
                coordinate_x = finalx, coordinate_y = finaly;
            }
            return final_result;
        } else {
            int final_result = 1e9;

            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (board[i][j] != 'X' && board[i][j] != 'O') {
                        board[i][j] = 'X';
                        int scr = best_move(depth - 1, !ismin, n_moves + 1, false, coordinate_x, coordinate_y);
                        board[i][j] = ' ';
                        final_result = min(final_result, scr);
                    }
                }
            }

            return final_result;
        }
}
};
