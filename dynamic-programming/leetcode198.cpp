#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums){
    vector<int> counts(nums.size() + 1, 0);
    if (nums.size() == 0){
        return 0;
    }else if(nums.size() == 1){
        return nums[0];
    } else if (nums.size() == 2){
        return max(nums[0], nums[1]);
    }
    counts[1] = nums[0];
    counts[2] = max(nums[0], nums[1]);
    for (int i = 3; i < nums.size()+1; i++){
        counts[i] = max(counts[i - 1], nums[i-1] + counts[i - 2]);
    }
    return counts[nums.size()];
}

int rob1(vector<int>& nums){
    if (nums.size() == 0){
        return 0;
    }else if(nums.size() == 1){
        return nums[0];
    } else if (nums.size() == 2){
        return max(nums[0], nums[1]);
    }
    int a = nums[0];
    int b = max(nums[0], nums[1]);
    int s = 0;
    for (int i = 3; i < nums.size() + 1; i++){
        s = max(b, a + nums[i - 1]);
        a = b;
        b = s;
    }
    return s;
}
int main(){
    vector<int> nums = {2,7,9,3,1};
    cout << rob1(nums);
    system("pause");
    return 0;
}