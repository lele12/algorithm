#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& nums, int i, vector<int>& track, vector<vector<int>>& res){
    res.push_back(track);
    for (int k = i; k < nums.size(); k++){
        track.push_back(nums[k]);
        backtrack(nums, k+1, track, res);
        track.pop_back();
    }

}
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> track;
    backtrack(nums, 0, track, res);
    return res;
}
int main(){
    vector<int> nums = {1, 2, 3};
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