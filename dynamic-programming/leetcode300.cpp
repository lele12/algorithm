#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums){
    vector<int> dp(nums.size(), 1);
    for (int i = 0; i < dp.size(); i++){
        for (int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < dp.size(); i++){
        res = max(dp[i], res);
    }
    return res;
}
int main(){
    vector<int> nums = {7,7,7,7,7,7,7};
    cout << lengthOfLIS(nums);
    system("pause");
    return 0;
}