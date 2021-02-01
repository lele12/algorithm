#include <vector>
#include <iostream>

using namespace std;

void backtracking(vector<int> &path, vector<vector<int>> &res, int k, int n, int start){

    if (path.size() == k){
        res.push_back(path);
        return;
    }
    for (int i = start; i <= n; i++){
        path.push_back(i);
        backtracking(path, res, k, n, i + 1);
        path.pop_back();
    }
}
vector<vector<int>> combine(int n, int k){
    vector<vector<int>> res;
    vector<int> path;
    backtracking(path, res, k, n, 1);
    return res;
}
int main(){
    int n = 4;
    int k = 2;
    vector<vector<int>> re = combine(n, k);
    for (int i = 0; i < re.size(); i++){
        for (int j = 0; j < re[i].size(); j++){
            cout << re[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}