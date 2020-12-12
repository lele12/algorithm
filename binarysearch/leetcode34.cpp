#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target)
{
    if (nums.size() <= 0)
    {
        return vector<int>(2, -1);
    }
    int left = 0;
    int right = nums.size();
    int mid = 0;
    while(left < right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] == target)
        {
            break;
        }
        else if(nums[mid] < target)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid;
        }
    }

    if (nums[mid] != target)
    {
        return vector<int>(2, -1);
    }
    else
    {
        int l = mid;
        int r = mid;
        while (l > 0 && nums[l-1] == target)
        {
            l--;
        }
        while (r < nums.size()-1 && nums[r+1] == target)
        {
            r++;
        }
        return vector<int>{l, r};
    }
}
int main()
{
    vector<int> nums = {};
    int target = 9;
    vector<int> re =  searchRange(nums, target);
    cout << re[0] << ' ' << re[1];
    // system("pause");
    return 0;
}