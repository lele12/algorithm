#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_valid(vector<vector<char>>& board, int m, int n, char ch){
    bool flag = true;
    for (int i = 0; i < board.size(); i++){
        if (board[i][n] == ch){
            flag = false;
            return flag;
        }
    }
    for (int i = 0; i < board[0].size(); i++){
        if (board[m][i] == ch){
            flag = false;
            return flag; 
        }
    }
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j++){
            if(board[m-m%3+i][n-n%3+j] == ch){
            flag = false;
            return flag; 
            }
        }
    }
    return flag;
}

void backtrack(vector<vector<char>>& board, int m, int n, bool& flag, vector<vector<char>>& res){
    if (flag){
        return;
    }
    if (n == board[0].size()){
        m++;
        n = 0;
    }
    if (m == board.size()){
        flag = true;
        res = board;
        return;
    }
    for (int i = m; i < board.size(); i++){
        for (int j = n; j < board[0].size(); j++){
            if (board[i][j] != '.'){
                continue;
            }
            for (int k = 0; k < 9; k ++){
                if (!is_valid(board, i, j, '1'+k)){
                    continue;
                }
                board[i][j] = '1' + k;
                backtrack(board, i, j + 1, flag, res);
                board[i][j] = '.';
            }
        }
    }
}

void solveSudoku(vector<vector<char>>& board){
    bool flag = false;
    vector<vector<char>> res;
    backtrack(board, 0, 0, flag, res);
    board = res;
    return;
}

int main(){
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
                                  
    solveSudoku(board);
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
        system("pause");
    return 0;
}