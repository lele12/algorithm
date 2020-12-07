#include <iostream>
#include <vector>

using namespace std;

bool checkPossibility(vector<int>& nums)
{
    int s = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] >= nums[i-1])
        {
            continue;
        }
        if (i - 2 >=0 && nums[i] < nums[i-2])
        {
            nums[i] = nums[i - 1];
        }
        else
        {
            nums[i - 1] = nums[i];
        }
        s++;
    }
    return s <= 1;
}
int main()
{
    vector<int> nums = {4,2,3};
    cout << checkPossibility(nums) << endl;
    system("pause");
    return 0;
}