#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++){
        if (m.count(nums[i])){
            return {m[nums[i]], i};
        }
        int s = target - nums[i];
        m[s] = i;
    }
    return {};
}

int main(){
    vector<int> nums = {3, 3};
    int target = 6;
    vector<int> re = twoSum(nums, target);
    for (int i = 0; i < re.size(); i++){
        cout << re[i] << ' ';
    }
    system("pause");
    return 0;
}