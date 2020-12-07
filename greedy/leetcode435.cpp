#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>&a, vector<int>&b)
{
    return a[a.size() - 1] < b[b.size() - 1];
}
int earseOverlapIntervals(vector<vector<int>>&intervals)
{
    int re = 1;
    if (intervals.size() <= 1)
    {
        return 0;
    }
    sort(intervals.begin(), intervals.end(), cmp);
    int j = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        int tmp = intervals[j][intervals[j].size() - 1];
        if(tmp <= intervals[i][0])
        {
            re++;
            j = i;
        }
    }
    return intervals.size() - re;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}};
    int re = earseOverlapIntervals(intervals);
    cout << re;

    system("pause");
    return 0;
}