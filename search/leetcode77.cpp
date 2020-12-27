#include <iostream>
#include <vector>

using namespace std;

void backtack(int n, int k, int start, vector<int>& track, vector<vector<int>>& res){
    if (track.size() == k){
        res.push_back(track);
    }

    for (int i = start; i < n + 1; i++){
        track.push_back(i);
        backtack(n, k, i + 1, track, res);
        track.pop_back();
    }
}
vector<vector<int>> combine(int n, int k){
    vector<vector<int>> res;
    vector<int> track;
    backtack(n, k, 1, track, res);
    return res;
}


int main(){
    int n = 4, k = 2;
    vector<vector<int>> res = combine(4, 2);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}