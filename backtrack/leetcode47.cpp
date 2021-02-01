#include <iostream>
#include <vector>

using namespace std;
bool is_in(int val, const vector<int>& nums){
    for (int i = 0; i < nums.size(); i++){
        if (val == nums[i]){
            return true;
        }
    }
    return false;
}
void backtracking(vector<int>& path, vector<vector<int>>& res, const vector<int>& nums, vector<int>& used){
    if (path.size() == nums.size()){
        res.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++){
        if (i > 0 && nums[i] == nums[i-1] && used[i-1]==false){
            continue;
        }
        if(used[i] == true){
            continue;
        }
        used[i] = true;
        path.push_back(nums[i]);
        backtracking(path, res, nums, used);
        path.pop_back();
        used[i] = false;
    }
}
vector<vector<int>> permute(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> path;
    vector<int> used(nums.size(), false);
    backtracking(path, res, nums, used);
    return res;
}
int main(){
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = permute(nums);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}