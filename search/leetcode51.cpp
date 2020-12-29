#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_valid(vector<string>& board, int row, int col){
    for (int i = 0; i < row; i++){
        if (board[i][col] == 'Q'){
            return false;
        }
    }
    for (int i = 0; i < board.size(); i++){
        if (board[row][i] == 'Q'){
            return false;
        }
    }
    for (int i = row + 1, j = col - 1; i < board.size() && j >= 0; i++, j --)
    {
        if (board[i][j] == 'Q'){
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++){
        if (board[i][j] == 'Q'){
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if (board[i][j] == 'Q'){
            return false;
        }
    }
    for (int i = row + 1, j = col + 1; i < board.size() && j < board.size(); i++, j++){
        if (board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}
void backtrack(vector<string>& board, int row, vector<vector<string>>& res){
    if (row == board.size()){
        res.push_back(board);
    }

    for (int i = 0; i < board.size(); i++){
        if (! is_valid(board, row, i)){
            continue;
        }
        board[row][i] = 'Q';
        backtrack(board, row + 1, res);
        board[row][i] = '.';
    }
}
vector<vector<string>> solveQueens(int n){
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0, res);
    return res;
}

int main(){
    vector<vector<string>> ans = solveQueens(4);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            std::cout << ans[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    system("pause");
    return 0;
}