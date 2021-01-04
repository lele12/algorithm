#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& board, int r, int c){
    if(r < 0 || c < 0 || r > board.size()-1 || c > board[0].size()-1 || board[r][c] != 'O'){
        return;
    }
    board[r][c] = '#';
    dfs(board, r + 1, c);
    dfs(board, r - 1, c);
    dfs(board, r, c - 1);
    dfs(board, r, c + 1);
    return;
}
void solve(vector<vector<char>>& board){
    if(board.size() == 0 || board[0].size() == 0){
        return;
    }
    for (int i = 0; i < board.size(); i++){
        dfs(board, i, 0);
        dfs(board, i, board[0].size() - 1);
    }
    for (int i = 0; i < board[0].size(); i++){
        dfs(board, 0, i);
        dfs(board, board.size()-1, i);
    }
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            if(board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            if(board[i][j] == '#'){
                board[i][j] = 'O';
            }

        }
    }
    return;
}

int main(){
    vector<vector<char>> board = {{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    solve(board);
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            cout << board[i][j] << ' ';

        }
        cout << endl;
    }
    system("pause");
    return 0;
}