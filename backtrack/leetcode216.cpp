#include <vector>
#include <iostream>

using namespace std;

void backtracking(vector<int>& path, vector<vector<int>>& res, int k, int n, int start){
    if (n < 0 || path.size() > k){
        return;
    }
    if (path.size() == k && n == 0){
        res.push_back(path);
        return;
    }
    for (int i = start; i < 10; i++){
        path.push_back(i);
        backtracking(path, res, k, n - i, i+1);
        path.pop_back();
    }
}
vector<vector<int>> combinationSum(int k, int n){
    vector<vector<int>> res;
    vector<int> path;
    backtracking(path, res, k, n, 1);
    return res;
}

int main(){
    int n = 7;
    int k = 3;
    vector<vector<int>> re = combinationSum(k, n);
    for (int i = 0; i < re.size(); i++){
        for (int j = 0; j < re[i].size(); j++){
            cout << re[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}