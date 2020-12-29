#include <iostream>
#include <vector>

using namespace std;

void findWays(vector<int> &nums, int &res, int S, int k, int pos){
    
    if (k == S && pos == nums.size()){
        res += 1;
    }
    if (pos > nums.size()-1){
        return;
    }
    // cout << pos << "  " << k << endl;
    k += nums[pos];
    findWays(nums, res, S, k, pos + 1);
    k -= nums[pos];

    k -= nums[pos];
    findWays(nums, res, S, k, pos + 1);
    k += nums[pos];
}

int findTargetSumWays(vector<int>& nums, int S){
    int res = 0;
    findWays(nums, res, S, 0, 0);
    return res;
}
int main(){
    vector<int> nums = {2,7,9,13,27,31,37,3,2,3,5,7,11,13,17,19,23,29,47,53};
    int S = 3;
    int re = findTargetSumWays(nums, S);
    cout << re;
    system("pause");
    return 0;
}