#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums){
    vector<int> dp(nums.begin(), nums.end());
    for (int i = 1; i < dp.size(); i++){
        if(dp[i-1] > 0){
            dp[i] += dp[i - 1];
        }
    }
    int res = INT_MIN;
    for (int i = 0; i < dp.size(); i++){
        res = max(res, dp[i]);
    }
    return res;
}
int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums);
    system("pause");
    return 0;
}