#include <vector>
#include <iostream>

using namespace std;

void backtracking(vector<int>& path, vector<vector<int>>& res, const vector<int>& nums, int start){
    res.push_back(path);
    if (start >= nums.size()){
        return;
    }
    for (int i = start; i< nums.size(); i++){
        path.push_back(nums[i]);
        backtracking(path, res, nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> path;
    backtracking(path, res, nums, 0);
    return res;
}

int main(){
    vector<int> nums = {0};
    vector<vector<int>> res = subsets(nums);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}