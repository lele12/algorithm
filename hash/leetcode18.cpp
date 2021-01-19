#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    vector<vector<int>> re;
    for (int i = 0; i < nums.size(); i++){
        if (i > 0 && nums[i] == nums[i-1]){
            continue;
        }
        for (int j = i + 1; j < nums.size(); j++){
            if (j > i + 1 && nums[j] == nums[j-1]){
                continue;
            }
            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right){
                if (nums[i] + nums[j] + nums[left] + nums[right] < target){
                    left++;
                }else if (nums[i] + nums[j] + nums[left] + nums[right] > target){
                    right--;
                }else{
                    re.push_back({nums[i], nums[j], nums[left], nums[right]});
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
    }
    return re;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4, 0, 0, 0, 0};
    int target = 0;
    vector<vector<int>> re = fourSum(nums, target);
    for (int i = 0; i < re.size(); i++){
        for (int j = 0; j < re[i].size(); j++){
            cout << re[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}