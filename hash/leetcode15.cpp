#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// vector<vector<int>> threeSum(vector<int>& nums){
//     vector<vector<int>> re;
//     sort(nums.begin(), nums.end());
//     for (int i = 0; i < nums.size(); i++){
//         int s = -nums[i];
//         if (i > 0 && nums[i] == nums[i-1]){
//             continue;
//         }

//         unordered_map<int, int> m;
//         int flag = 0;
//         for (int j = i + 1; j < nums.size(); j++){
//             if (flag){
//                 if (nums[j] == nums[j-1]){
//                     continue;
//                 }else{
//                     flag = 0;
//                 }
//             }
            
//             int t = s - nums[j];
//             if (m.count(nums[j])){
//                 re.push_back({nums[i], t, nums[j]});
//                 flag = 1;
//             }
            
//             m[t] = j;
//         }
//     }
//     return re;
// }

vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> re;

    for (int i = 0; i < nums.size(); i++){
        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right){
           if (nums[i] + nums[left] + nums[right] < 0){
               left++;
           }else if (nums[i] + nums[left] + nums[right] > 0){
               right--;
           }else{
               re.push_back({nums[i], nums[left], nums[right]});
               while (left < right && nums[left] == nums[left + 1]){
                   left++;
               }
               while (left < right && nums[right] == nums[right - 1]){
                   right--;
               }
               left++;
               right--;
           }
       } 
    }
    return re;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4, 0, 0, 0, 0};
    vector<vector<int>> re = threeSum(nums);
    for (int i = 0; i < re.size(); i++){
        for (int j = 0; j < re[i].size(); j++){
            cout << re[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}