#include<iostream>
#include<vector>

using namespace std;

int quickSelection(vector<int>& nums, int l, int r)
{
    int flag = nums[l];
    int i = l, j = r;
    while(i < j)
    {
        while(i < j && nums[j] >= flag)
        {
            j--;
        }
        swap(nums[j], nums[i]);
        while(i < j && nums[i] <= flag)
        {
            i++;
        }
        swap(nums[i], nums[j]);
    }
    return i;
}

int findKthLargest(vector<int>& nums, int k)
{
    int left = 0, right = nums.size() - 1, target = nums.size() - k;
    int mid = quickSelection(nums, left, right);
    while(mid != target)
    {
        if(mid < target)
        {
            left = mid + 1;
            mid = quickSelection(nums, left, right);
        }
        else
        {
            right = mid - 1;
            mid = quickSelection(nums, left, right);
        }
    }
    return nums[mid];
}
int main()
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    int re = findKthLargest(nums, k);
    cout << re;
    system("pause");
    return 0;
}