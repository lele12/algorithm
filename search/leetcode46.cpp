#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

// void backtracking(vector<int>& nums, int level, vector<vector<int>>& ans){
//     if (level == nums.size() - 1){
//         ans.push_back(nums);
//         return;
//     }

//     for (int i = level; i < nums.size(); i++){
//         std::swap(nums[i], nums[level]);
//         std::cout << "i:" << i << "level:" << level << "  "<< nums[0]<< "  "<< nums[1]<< "  "<< nums[2] <<  std::endl;
//         backtracking(nums, level + 1, ans);
//         std::swap(nums[i], nums[level]);
//     }
// }

// vector<vector<int>> permute(vector<int>& nums){
//     vector < vector<int>> ans;
//     backtracking(nums, 0, ans);
//     return ans;
// }
bool is_in(vector<int>& nums, int s){
    bool flag = false;
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] == s){
            flag = true;
            break;
        }
    }
    return flag;
}
void backtrack(vector<int>& nums, vector<int>& track, vector<vector<int>>& res){
    if(track.size() ==  nums.size()){
        res.push_back(track);
    }
    for (int i = 0; i < nums.size(); i++){
        if (is_in(track, nums[i])){
            continue;
        }
        track.push_back(nums[i]);
        backtrack(nums, track, res);
        track.pop_back();
    }
}
 
vector<vector<int>> permute(vector<int>& nums){
    vector < vector<int>> ans;
    vector<int> track;
    backtrack(nums, track, ans);
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