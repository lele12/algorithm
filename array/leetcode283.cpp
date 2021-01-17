#include <iostream>
#include <vector>

using namespace std;

void moveZeros(vector<int>& nums){
    if(nums.size() == 0){
        return;
    }
    int slow = 0;
    int fast = 0;
    while(fast < nums.size()){
        if(nums[fast] == 0){
            fast++;
        }else{
            nums[slow] = nums[fast];
            slow++;
            fast++;
        }
    }
    while(slow < fast){
        nums[slow] = 0;
        slow++;
    }
    return;
}

int main(){
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeros(nums);
    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << ' ';
    }
    system("pause");
    return 0;
}