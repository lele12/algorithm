#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& candidates, vector<int>& track, int target, vector<vector<int>>& res, int start, vector<bool>& used){
    if (target == 0){
        res.push_back(track);
        return;
    }

    for (int i = start; i < candidates.size(); i++){
        if (target - candidates[i] >= 0){
            if (i != 0 && candidates[i] == candidates[i-1]&& used[i-1]==false){
                continue;
            }
            track.push_back(candidates[i]);
            used[i] = true;
            backtrack(candidates, track, target - candidates[i], res, i+1, used);
            used[i] = false;
            track.pop_back();
        }

    }
    return;
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    vector<vector<int>> res;
    if (candidates.size() <= 0){
        return res;
    }
    sort(candidates.begin(), candidates.end(), greater<int>());
    vector<int> track;
    vector<bool> used(candidates.size(), false);
    backtrack(candidates, track, target, res, 0, used);
    return res;
}
int main(){
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = combinationSum2(nums, target);
    system("pause");
    return 0;
}