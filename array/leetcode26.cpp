#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums){
    if (nums.size() == 0){
        return 0;
    }
    int low = 0;
    int fast = 0;
    while (fast < nums.size()){
        if(nums[low] == nums[fast]){

            fast++;
        }else{
            low++;
            nums[low] = nums[fast];
            fast++;
        }
    }
    return low + 1;
}

int main(){
    vector<int> nums = {};
    int re = removeDuplicates(nums);
    cout << re;
    system("pause");
    return 0;
}