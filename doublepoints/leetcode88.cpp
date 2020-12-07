#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int i = m - 1, j = n - 1;
    while(i >= 0 && j >= 0)
    {
        if (nums1[i] < nums2[j])
        {
            nums1[i + j + 1] = nums2[j];
            j--;
        }
        else
        {
            nums1[i + j + 1] = nums1[i];
            i--;
        }
    }

    while(j >= 0)
    {
        nums1[j] = nums2[j];
        j--;
    }
    return;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << ' ';

    }
    system("pause");
    return 0;
}