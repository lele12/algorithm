#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

void backtracking(vector<int>& path, vector<vector<int>>& res, const vector<int>& nums, int start){
    if (path.size() >= 2){
        res.push_back(path);
    }
    
    if (start >= nums.size()){
        return;
    }
    set<int> used;
    for (int i = start; i< nums.size(); i++){
        // if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false){
        //     continue;
        // }
        // if ((i > 0 && path.size() > 0 && path[path.size()-1] == nums[i]) || used.count(nums[i]) == 1){
        //         continue;
        // }
        // if (path.size() == 0 || path[path.size()-1] <= nums[i]){
 
        //     used.insert(nums[i]);
        //     path.push_back(nums[i]);
        //     backtracking(path, res, nums, i + 1, used);
        //     path.pop_back();
        //     // used.erase(nums[i]);
        // }
        if ((!path.empty() && nums[i] < path.back())
                || used.find(nums[i]) != used.end()) {
                continue;
        }
        used.insert(nums[i]);
        path.push_back(nums[i]);
        backtracking(path, res, nums, i + 1);
        path.pop_back();
        // used.erase(nums[i]);
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums){
    // sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> path;
    backtracking(path, res, nums, 0);
    return res;
}

int main(){
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> res = findSubsequences(nums);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}