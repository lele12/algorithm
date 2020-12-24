#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
// int help(vector<vector<int>>& grid, int i, int j){
//     if(i == 0){
//         int re = 0;
//         for (int s = 0; s <= j; s++){
//             re += grid[0][s];
//         }
//         return re;
//     }
//     if (j == 0){
//         int re = 0;
//         for (int s = 0; s <= i; s++){
//             re += grid[s][0];
//         }
//         return re;
//     }

//     return min(help(grid, i - 1, j), help(grid, i, j - 1)) + grid[i][j];
// }
// int minPathSum(vector<vector<int>>& grid){
//     return help(grid, grid.size()-1, grid[0].size()-1);
// }


// int helper(vector<vector<int>>& grid, vector<vector<int>>& grid_sum, int i, int j){
//         if(i == 0){
//         int re = 0;
//         for (int s = 0; s <= j; s++){
//             re += grid[0][s];
//         }
//         return re;
//     }
//     if (j == 0){
//         int re = 0;
//         for (int s = 0; s <= i; s++){
//             re += grid[s][0];
//         }
//         return re;
//     }
//     if (grid_sum[i-1][j] == -1){
//         grid_sum[i - 1][j] = helper(grid, grid_sum, i - 1, j);
//     }
//     if (grid_sum[i][j-1] == -1){
//         grid_sum[i][j-1] = helper(grid, grid_sum, i, j-1);
//     }
//     return min(grid_sum[i][j-1], grid_sum[i - 1][j]) + grid[i][j];
// }

// int helper(vector<vector<int>>& grid, vector<vector<int>>& grid_sum, int i, int j){
//     if(i == 0){
//         int re = 0;
//         for (int s = 0; s <= j; s++){
//             re += grid[0][s];
//         }
//         return re;
//     }
//     if (j == 0){
//         int re = 0;
//         for (int s = 0; s <= i; s++){
//             re += grid[s][0];
//         }
//         return re;
//     }
//     // if (grid_sum[i-1][j] == -1){
//     //     grid_sum[i - 1][j] = helper(grid, grid_sum, i - 1, j);
//     // }
//     // if (grid_sum[i][j-1] == -1){
//     //     grid_sum[i][j-1] = helper(grid, grid_sum, i, j-1);
//     // }
//     if (grid_sum[i][j] == -1){
//         grid_sum[i][j] = min(helper(grid, grid_sum, i, j - 1), helper(grid, grid_sum, i - 1, j)) + grid[i][j];
//     }
//     return  grid_sum[i][j];
// }


int minPathSum(vector<vector<int>>& grid){
    vector<vector<int>> grid_sum(grid.size(), vector<int>(grid[0].size(), -1));
    grid_sum[0][0] = grid[0][0];
    for (int m = 1; m < grid.size(); m++){
        grid_sum[m][0] = grid_sum[m - 1][0] + grid[m][0];
    }
    for (int m = 1; m < grid[0].size(); m++){
        grid_sum[0][m] = grid_sum[0][m - 1] + grid[0][m];
    }
    for (int m = 1; m < grid.size(); m++)
    {
        for (int n = 1; n < grid[0].size(); n++)
        {
            grid_sum[m][n] = min(grid_sum[m][n - 1], grid_sum[m - 1][n]) + grid[m][n];
        }
    }
    return  grid_sum[grid.size()-1][grid[0].size()-1];
}

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int re = minPathSum(grid);
    cout << re;
    system("pause");
    return 0;
}