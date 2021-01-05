#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void backtrack(vector<int>& nums, vector<int>& track, vector<vector<int>>& res, vector<bool>&used){
    if(track.size() ==  nums.size()){
        res.push_back(track);
    }
    for (int i = 0; i < nums.size(); i++){
        if (i != 0 && nums[i] == nums[i-1]&& used[i-1]==true){
            continue;
        }

        if (used[i] == true){
            continue;
        }
        track.push_back(nums[i]);
        used[i] = true;
        backtrack(nums, track, res, used);
        track.pop_back();
        used[i] = false;
    }
}
 
vector<vector<int>> permute(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector < vector<int>> ans;
    vector<int> track;
    vector<bool> used(nums.size(), false);
    backtrack(nums, track, ans, used);
    return ans;
}

int main(){
    vector<int> nums= {1,1, 2};
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