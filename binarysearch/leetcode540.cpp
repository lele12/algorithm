#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int>& nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }

    int left = 0;
    int right = nums.size() - 1;
    while(left < right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == nums[mid - 1])
        {
            if ((mid - left) % 2 == 0)
            {
                right = mid - 2;
            }
            else
            {
                left = mid + 1;
                
            }
        }
        else if(nums[mid] == nums[mid + 1])
        {
            if ((right - mid) % 2 == 0)
            {
                
                left = mid + 2;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            return nums[mid];
        }
    }
    return nums[left];
}

int main()
{
    vector<int> nums = {1,2,2,3,3};
    int re = singleNonDuplicate(nums);
    cout << re;
    system("pause");
    return 0;
}