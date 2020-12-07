#include <iostream>
#include <vector>

using namespace std;

void sortColor(vector<int>& nums)
{
    if(nums.size() <= 1)
    {
        return;
    }
    int i = 0, j = nums.size() - 1;
    while(i < j)
    {
        while(i < j && nums[j] == 2)
        {
            j--;
        }
        while(i < j && nums[i] != 2)
        {
            i++;
        }
        swap(nums[i], nums[j]);
    }
    i = 0;
    while(i < j)
    {
        while(i < j)
        {
            while(i < j && nums[j] == 1)
            {
                j--;
            }
            while(i < j && nums[i] == 0)
            {
                i++;
            }
            swap(nums[i], nums[j]);
        }
    }
    return;
}
int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    sortColor(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    system("pause");
    return 0;
}