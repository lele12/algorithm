#include <iostream>
#include <vector>

using namespace std;

// bool canJump(vector<int>& nums){
//     if(nums.size() <= 1){
//         return true;
//     }
//     int n = nums.size();
//     vector<bool> dp(n, false);
//     dp[0] = true;
//     for (int i = 0; i < n-1; i++){
//         for (int j = 0; j <= nums[i]; j++){
//             if(dp[i]==true){
//                 dp[i + j] = true;
//             }
//         }
//     }
//     return dp[n - 1];
// }

bool canJump(vector<int>& nums){
    if(nums.size() <= 1){
        return true;
    }
    int n = nums.size();
    int s = 0;
    for (int i = 0; i < n-1; i++){
        s = max(s, i + nums[i]);
        if(s <= i){
            return false;
        }
    }
    return s >= n-1;
}

int main(){
    vector<int> nums = {0, 2, 3};
    bool re = canJump(nums);
    cout << re;
    system("pause");
    return 0;
}