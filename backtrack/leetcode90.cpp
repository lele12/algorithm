#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

// void backtracking(vector<int>& path, vector<vector<int>>& res, const vector<int>& nums, int start, vector<bool>&used){
//     res.push_back(path);
//     if (start >= nums.size()){
//         return;
//     }
//     for (int i = start; i< nums.size(); i++){
//         if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false){
//             continue;
//         }
//         used[i] = true;
//         path.push_back(nums[i]);
//         backtracking(path, res, nums, i + 1, used);
//         path.pop_back();
//         used[i] = false;
//     }
// }

// vector<vector<int>> subsetsWithDup(vector<int>& nums){
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> res;
//     vector<int> path;
//     vector<bool> used(nums.size(), false);
//     backtracking(path, res, nums, 0, used);
//     return res;
// }

void backtracking(vector<int>& path, vector<vector<int>>& res, const vector<int>& nums, int start){
    res.push_back(path);
    if (start >= nums.size()){
        return;
    }
    set<int> used;
    for (int i = start; i< nums.size(); i++){
        if (used.count(nums[i])){
            continue;
        }
        
        used.insert(nums[i]);
        path.push_back(nums[i]);
        backtracking(path, res, nums, i + 1);
        path.pop_back();
        // used[i] = false;
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> path;
    
    backtracking(path, res, nums, 0);
    return res;
}

int main(){
    vector<int> nums = {4, 4, 4, 1, 4};
    vector<vector<int>> res = subsetsWithDup(nums);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}