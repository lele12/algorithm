#include <iostream>
#include <vector>

using namespace std;

int min_sub_array_len(int s, vector<int>& nums){
    int left = 0, right = 0;
    int min_size = nums.size() + 1;
    int sum = 0;
    while(right < nums.size()){
        sum += nums[right];
        right++;
        while(sum >= s){
            if(min_size > right - left){
                min_size = right - left;
            }
            sum -= nums[left];
            left++;
        }
    }
    if(min_size > nums.size()){
        min_size = 0;
    }
    return min_size;
}

int main(){
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int s = 7;
    int re = min_sub_array_len(s, nums);
    cout << re;
    system("pause");
    return 0;
}