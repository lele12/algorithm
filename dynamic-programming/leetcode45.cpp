#include <iostream>
#include <vector>

using namespace std;

// int jump(vector<int>& nums){
//     if(nums.size() <= 1){
//         return 0;
//     }
//     int n = nums.size();
//     vector<int> dp(n, 0);
//     for (int i = 0; i < n; i++){
//         for (int j = 1; j <= nums[i]; j++){
//             if(dp[i+j] == 0){
//                 dp[i + j] = dp[i] + 1;
//             }else{
//                 dp[i + j] = min(dp[i+j], dp[i] + 1);
//             }
            
//         }
//     }
//     return dp[n - 1];
// }

int jump(vector<int>& nums){
    if(nums.size() <= 1){
        return 0;
    }
    int n = nums.size();
    int s = 0;
    int end = 0;
    int step = 0;
    for (int i = 0; i < n - 1; i++){
        s = max(i + nums[i], s);
        if(i == end){
            step++;
            end = s;
        }
    }
    return step;
}

int main(){
    vector<int> nums = {2, 3, 1, 1, 4};
    int re = jump(nums);
    cout << re;
    system("pause");
    return 0;
}