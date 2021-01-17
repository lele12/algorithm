#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val){
    if(nums.size() == 0){
        return 0;
    }
    int slow = 0;
    int fast = 0;
    while(fast < nums.size()){
        if(nums[fast] != val){
            nums[slow] = nums[fast];
            slow++;
            fast++;

        }else{
            fast++;
        }
    }
    return slow;
}

int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int re = removeElement(nums, val);
    cout << re;
    system("pause");
    return 0;
}