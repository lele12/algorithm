#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void backtracking(vector<int>& path, vector<vector<int>>& res, const vector<int>& candidates, int target, int start){
    if (target < 0){
        return;
    }
    if (target == 0){
        res.push_back(path);
        return;
    }
    for (int i = start; i < candidates.size(); i++){
        path.push_back(candidates[i]);
        backtracking(path, res, candidates, target - candidates[i], i);
        path.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    backtracking(path, res, candidates, target, 0);
    return res;
}

int main(){
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    vector<vector<int>> res = combinationSum(candidates, target);
        for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}