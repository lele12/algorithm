#include <iostream>
#include <vector>

using namespace std;
void bubbleSort(vector<int>& nums)
{
    if (nums.size() <= 1)
    {
        return;
    }
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = 1; j < nums.size() - i; j++)
        {
            if (nums[j] < nums[j-1])
            {
                swap(nums[j], nums[j - 1]);
            }
        }
    }
    return;
}
int main()
{
    vector<int> nums = {};
    bubbleSort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
        system("pause");
    return 0;
}