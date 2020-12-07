#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& nums, int left, int right)
{
    if(left+1 > right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    vector<int> tmp(right - left+1, 0);
    int i = left;
    int j = mid + 1;
    int s = 0;
    while(i < mid+1 && j < right+1)
    {
        if(nums[i] < nums[j])
        {
            tmp[s] = nums[i];
            i++;
            s++;
        }
        else
        {
            tmp[s] = nums[j];
            j++;
            s++;
        }
    }
    while(i < mid+1)
    {
        tmp[s] = nums[i];
        i++;
        s++;
    }
    while(j < right+1)
    {
        tmp[s] = nums[j];
        j++;
        s++;
    }
    for (int i = 0; i < tmp.size(); i++)
    {
        nums[left + i] = tmp[i];
    }
}


int main()
{
    vector<int> nums = {};
    mergeSort(nums, 0, nums.size()-1);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    system("pause");
    return 0;
}