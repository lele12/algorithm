#include <iostream>
#include <string>
#include <vector>

using namespace std;

void backtrack(vector<vector<char>>& board, vector<vector<bool>>& visit, int m, int n, 
            string word, int start, bool& find){
    if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size()){
        return;
    }

    if (visit[m][n] || find || word[start] != board[m][n]){
        return;
    }
    if (start == word.length()-1){
        find = true;
        return;
    }
    visit[m][n] = true;
    backtrack(board, visit, m - 1, n, word, start + 1, find);
    backtrack(board, visit, m + 1, n, word, start + 1, find);
    backtrack(board, visit, m , n - 1, word, start + 1, find);
    backtrack(board, visit, m , n + 1, word, start + 1, find);
    visit[m][n] = false;

}
bool exist(vector<vector<char>>& board, string word){
    if (board.size() == 0){
        return false;
    }
    bool find = false;
    vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            backtrack(board, visit, i, j, word, 0, find);
        }
    }
    return find;
}
int main(){
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "SEE";
    cout << exist(board, word);
    system("pause");
    return 0;
}