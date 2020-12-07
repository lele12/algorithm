#include <iostream>
#include <vector>

using namespace std;
int findMin(vector<int>& nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    int tar = nums[0];

    int left = 0;
    int right = nums.size() - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < tar)
        {
            tar = nums[mid];
        }
        while(left <= right && nums[mid] == nums[left])
        {
            left++;
        }
        while(left <= right && nums[mid] == nums[right])
        {
            right--;
        }
        if (left > right)
        {
            break;
        }
        if (nums[left] < nums[mid])
        {
            if(tar > nums[left])
            {
                tar = nums[left];
            }
            left = mid + 1;
        }
        else if (nums[mid] < nums[right])
        {
            right = mid - 1;
        }
    }
    return tar;
}

int main()
{
    vector<int> nums = {0,1,1,1,2,2};
    int re = findMin(nums);
    cout << re;
    system("pause");
    return 0;
}