#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& nums, int l, int r)
{
    if(l >= r)
    {
        return;
    }
    int flag = nums[l];
    int first = l, last = r; 
    while(first < last)
    {
        while(first < last && nums[last] >= flag)
        {
            last--;
        }
        nums[first] = nums[last];
        while(first < last && nums[first] <= flag)
        {
            first++;
        }
        nums[last] = nums[first];
    }
    nums[first] = flag;
    quickSort(nums, l, first-1);
    quickSort(nums, first+1, r);
}

int main()
{
    vector<int> nums = {-1, -1, 94, 0, -89};
    quickSort(nums, 0, nums.size()-1);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    system("pause");
    return 0;
}