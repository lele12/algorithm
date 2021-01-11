#include <iostream>
#include <vector>

using namespace std;

void backtrack(int i, vector<int>& nums, int target, bool & flag){
    if (target == 0){
        flag = true;
        return;
    }
    if(i >= nums.size() || flag == true){
        return;
    }
    target += nums[i];
    backtrack(i + 1, nums, target, flag);
    target -= nums[i];

    target -= nums[i];
    backtrack(i + 1, nums, target, flag);
    target += nums[i];
}

bool canPartition(vector<int>& nums){
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < nums.size(); i++){
        sum += nums[i];
    }
    if (sum % 2 == 1){
        return false;
    }
    int value = sum / 2;
    vector<vector<bool>> dp(n+1, vector<bool>(value+1, false));
    for (int i = 0; i <= n; i++){
        dp[i][0] = true;
    }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= value; j++)
            {
                if (j - nums[i - 1] < 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    if (dp[i - 1][j] == true || dp[i-1][j - nums[i - 1]] == true)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
            }
        }
    return dp[n][value];
}

int main(){
    vector<int> nums = {1, 5, 11, 5};
    bool re = canPartition(nums);

    cout << re;

    system("pause");
    return 0;
}