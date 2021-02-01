#include <vector>
#include <iostream>

using namespace std;
bool is_valid(const vector<string>& board, int row, int col){
    for (int i = 0; i < row; i++){
        if (board[row][i] == 'Q'){
            return false;
        }
    }
    for (int i = 0; i < board[col].length(); i++){
        if (board[i][col] == 'Q'){
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if (board[i][j] == 'Q'){
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < board[row].length(); i--, j++){
        if (board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}
void backtracking(vector<string>& board, vector<vector<string>>& res, int row){
    if (row >= board.size()){
        res.push_back(board);
        return;
    }
    for (int i = 0; i < board[row].size(); i++){
        if (is_valid(board, row, i)){
            board[row][i] = 'Q';
            backtracking(board, res, row + 1);
            board[row][i] = '.';
        }
    }
}
vector<vector<string>> sloveNQueens(int n){
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> res;
    backtracking(board, res, 0);
    return res;
}

int main(){
    int n = 4;
    vector<vector<string>> res = sloveNQueens(n);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}