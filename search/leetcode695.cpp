#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <utility>

using std::pair;
using std::stack;
using std::vector;

int dsf(vector<vector<int>>& grid, int l, int r){
    if (l < 0 || l > grid.size()-1 || r < 0 || r > grid[0].size()-1 || grid[l][r] == 0){
        return 0;
    }
    grid[l][r] = 0;
    int num = 1;
    num += dsf(grid, l - 1, r);
    num += dsf(grid, l + 1, r);
    num += dsf(grid, l, r - 1);
    num += dsf(grid, l, r + 1);
    return num;
}

// int maxAreaOfIsland(vector<vector<int>>& grid){
//     if (grid.size() == 0 || grid[0].size() == 0){
//         return 0;
//     }

//     int count = 0;
//     for (unsigned i = 0; i < grid.size(); i++)
//     {
//         for (unsigned j = 0; j < grid[0].size(); j++){
//             if (grid[i][j] == 1){
//                 count = std::max(count, dsf(grid, i, j));
//             }
            
//         }
//     }
//     return count;
// }

bool check(vector<vector<int>> grid, int l, int r){

    if (l >= 0 && l < grid.size() && r >= 0 && r < grid[0].size() && grid[l][r] == 1){
        return true;
    }
    else{
        return false;
    }
}
int maxAreaOfIsland(vector<vector<int>>& grid){
    if (grid.size() == 0 || grid[0].size() == 0){
        return 0;
    }
    int m = grid.size();
    int n = grid[0].size();
    const vector<int> direction = {-1, 0, 1, 0, -1};
    int count = 0, l = 0, r = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 1){
                grid[i][j] = 0;
                stack<pair<int, int>> island;
                island.push({i, j});
                int num = 1;
                while(!island.empty()){
                   
                    pair<int, int> tmp = island.top();
                    island.pop();

                    for (int k = 0; k < 4; k++){
                        l = tmp.first + direction[k];
                        r = tmp.second + direction[k+1];
                        if (check(grid, l, r)){
                            island.push({l, r});
                            grid[l][r] = 0;
                            num += 1;
                        }
                    }
                }
                count = std::max(count, num);
            }
        }
    }
    return count;
}
int main(){

    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    // grid = {{0, 0, 0, 0, 0, 0, 0, 0}};
    int re = maxAreaOfIsland(grid);
    std::cout << re;

    system("pause");
    return 0;
}