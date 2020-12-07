#include <iostream>
#include <vector>

using std::vector;


void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& can_reach, int l, int r){
    if (can_reach[l][r]){
        return;
    }
    can_reach[l][r] = true;
    vector<int> dirction = {-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; i++){
        int x = l + dirction[i];
        int y = r + dirction[i + 1];
        if (x >= 0 && y >= 0 && x < matrix.size() && y < matrix[0].size() && matrix[l][r] <= matrix[x][y]){
            dfs(matrix, can_reach, x, y);
        }
    }    
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix){
    if (matrix.size() == 0 ||matrix[0].size() == 0){
        return {};
    }
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
    vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++){
        dfs(matrix, can_reach_p, i, 0);
        dfs(matrix, can_reach_a, i, n - 1);
    }

    for (int j = 0; j < n; j++){
        dfs(matrix, can_reach_p, 0, j);
        dfs(matrix, can_reach_a, m - 1, j);
    }

    vector<vector<int>> ans;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (can_reach_p[i][j] && can_reach_a[i][j]){
                ans.push_back(vector<int>{i, j});
            }
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> matrix = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> ans = pacificAtlantic(matrix);
    for (int i = 0; i < ans.size(); i ++){
        std::cout << ans[i][0] << ' ' << ans[i][1] << std::endl;
    }
        system("pause");
    return 0;
}