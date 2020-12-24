#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n){
    if (n <= 2){
        return n;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int climb(int n, vector<int>&nums){
    if (n <= 2) {
        return n;
    }
    if (nums[n] != 0)
    {
        return nums[n];
    }
    nums[n] = climb(n - 1, nums) + climb(n - 2, nums);

    return nums[n];
}

int help(int n, vector<int>& nums){
    if (n <= 2){
        return n;
    }
    if(nums[n-1] == 0){
        nums[n - 1] = help(n - 1, nums);
    }
    if(nums[n-2] == 0){
        nums[n - 2] = help(n - 2, nums);
    }
    nums[n] = nums[n - 1] + nums[n - 2];
    return nums[n];
}
int climbStairs1(int n){
    vector<int> nums(n+1, 0);
    return help(n, nums);
}

int climbStairs2(int n){
    vector<int> nums(n + 1, 0);
    nums[1] = 1;
    nums[2] = 2;
    for (int i = 3; i < n + 1; i++){
        nums[i] = nums[i - 1] + nums[i - 2];
    }
    return nums[n];
}

int climbStair3(int n){
    if (n <= 2){
        return n;
    }
    int a = 1;
    int b = 2;
    int s = 0;
    for (int i = 3; i < n + 1; i++){
        s = a + b;
        a = b;
        b = s;
    }
    return s;
}

int main(){
    int n = 10;
    cout << climbStair3(10);
    system("pause");
    return 0;
}