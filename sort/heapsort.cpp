#include <iostream>
#include <vector>

using namespace std;


void adjustHeap(vector<int>& nums, int i, int len_nums)
{
    for (int j = i; j <= len_nums / 2 - 1; j++)
    {
        if (i + 1 < len_nums && nums[i] < nums[2*i+1])
        {
            swap(nums[i], nums[2 * i + 1]);
        }
        if (i + 2 < len_nums && nums[i] < nums[2*i+2])
        {
            swap(nums[i], nums[2 * i + 2]);
        }
    }
}


void heapSort(vector<int>& nums)
{
    int len_nums = nums.size();
    if(len_nums <= 1)
    {
        return;
    }
    for (int i = len_nums / 2 - 1; i >= 0; i-- )
    {
        adjustHeap(nums, i, len_nums);
    }

    for (int i = len_nums - 1; i >= 0; i--)
    {
        swap(nums[0], nums[i]);
        adjustHeap(nums, 0, i);
    }
    return;
}

int main()
{
    vector<int> nums = {-1, -1, 94, 0, -89};
    heapSort(nums);
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    system("pause");
    return 0;
}
