#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target)
{
    if (nums.size() == 0)
    {
        return false;
    }
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        else if(nums[mid] < nums[right])
        {
            if (nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else if (nums[left] < nums[mid])
        {
            if (nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (nums[mid] == nums[left])
            {
                left++;
            }
            if (nums[mid] == nums[right])
            {
                right--;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {3, 1};
    int target = 1;
    bool re = search(nums, target);
    cout << re;
    system("pause");
    return 0;
}