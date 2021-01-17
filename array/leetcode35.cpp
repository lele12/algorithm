#include <iostream>
#include <vector>

using namespace std;

// int search_insert(vector<int>& nums, int target){
//     if (nums.size() == 0){
//         return 0;
//     }

//     int left = 0;
//     int right = nums.size();

//     while (left < right){
//         int mid = left + (right - left) / 2;
//         if (nums[mid] == target){
//             return mid;
//         }else if (nums[mid] < target){
//             left = mid + 1;
//         }else{
//             right = mid;
//         }
//     }
//     return left;
// }

int search_insert(vector<int>& nums, int target){
    if (nums.size() == 0){
        return 0;
    }

    int left = 0;
    int right = nums.size();

    while (left < right){
        int mid = left + (right - left) / 2;
        if (nums[mid] == target){
            left = mid + 1;
        }else if (nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left-1;
}

int main(){
    vector<int> nums = {1, 3, 5, 5, 5, 5, 6};
    int target = 5;
    int re = search_insert(nums, target);
    cout << re;
    system("pause");
    return 0;
}