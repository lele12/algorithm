#include <iostream>
#include <vector>

using namespace std;

bool is_valid(const vector<vector<char>>& board, int row, int col, char ch){
    for (int i = 0; i < board.size(); i++){
        if (board[i][col] == ch){
            return false;
        }
    }
    for (int i = 0; i < board[row].size(); i++){
        if (board[row][i] == ch){
            return false;
        }
    }
    int row_start = row - row % 3;
    int col_start = col - col % 3;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[row_start+i][col_start+j] == ch){
                return false;
            }
        }
    }
    return true;
}

bool backtracking(vector<vector<char>>& board){

    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            if (board[i][j] != '.'){
                continue;
            }
            for (char k = '1'; k <= '9'; k++){
                if (is_valid(board, i, j, k))
                {
                    board[i][j] = k;
                    
                    if (backtracking(board)){
                        return true;
                    }
                    board[i][j] = '.';
                } 
            }
            return false;
        }
  
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board){
    backtracking(board);
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