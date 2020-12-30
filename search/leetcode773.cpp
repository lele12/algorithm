#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int slidingPuzzle(vector<vector<int>>& board){
    int m = 2, n = 3;
    string start = "";
    string end = "123450";
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j ++){
            start.push_back(board[i][j] + '0');
        }
    }
    vector<vector<int>> neighbor = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    queue<string> q;
    set<string> visited;
    q.push(start);
    visited.insert(start);
    int step = 0;
    while(!q.empty()){
        int q_size = q.size();
        for (int i = 0; i < q_size; i++){
            string cur = q.front();
            q.pop();
            if (end == cur){
                return step;
            }
            int idx = 0;
            for (int j = 0; j < cur.size(); j ++){
                if (cur[j] == '0'){
                    idx = j;
                    break;
                }
            }
            for (int j = 0; j < neighbor[idx].size(); j++){
                string new_board = cur;
                swap(new_board[neighbor[idx][j]], new_board[idx]);
                if (visited.find(new_board) == visited.end()){
                    q.push(new_board);
                    visited.insert(new_board);
                }
            }
        }
        step++;
    }
    return -1;
}
int main(){
    vector<vector<int>> board = {{1, 2, 3}, {5, 4, 0}}; 
    int re = slidingPuzzle(board);
    cout << re;
    system("pause");
    return 0;
}