#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int>&nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if(nums[j] < nums[j-1])
            {
                swap(nums[j], nums[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}
int main()
{
    vector<int> nums = {-1, -1, 94, 0, -89};
    insertSort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
        system("pause");
    return 0;
}