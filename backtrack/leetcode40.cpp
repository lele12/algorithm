#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void backtracking(vector<int>& path, vector<vector<int>>& res, const vector<int>& candidates, int target, int start, vector<bool>& used){
    if (target < 0){
        return;
    }
    if (target == 0){
        res.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size(); i++){
        if (i > 0 && used[i-1] == false && candidates[i] == candidates[i-1]){
            continue;
        }
        used[i] = true;
        path.push_back(candidates[i]);
        backtracking(path, res, candidates, target - candidates[i], i+1, used);
        path.pop_back();
        used[i] = false;
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(candidates.size(), false);
    backtracking(path, res, candidates, target, 0, used);
    return res;
}

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = combinationSum2(candidates, target);
        for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}