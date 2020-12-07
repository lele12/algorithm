#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void backtracking(vector<int>& nums, int level, vector<vector<int>>& ans){
    if (level == nums.size() - 1){
        ans.push_back(nums);
        return;
    }

    for (int i = level; i < nums.size(); i++){
        std::swap(nums[i], nums[level]);
        backtracking(nums, level + 1, ans);
        std::swap(nums[i], nums[level]);
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector < vector<int>> ans;
    backtracking(nums, 0, ans);
    return ans;
}
int main(){
    vector<int> nums= {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            std::cout << ans[i][j] << ' ';
        }
        std::cout << std::endl;
    }
        system("pause");
    return 0;
}