#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>&a, vector<int>&b)
{
    return a[a.size() - 1] < b[b.size() - 1];
}

int findMinArrowShot(vector<vector<int>>& points)
{
    if (points.size() == 0)
    {
        return 0;
    }
    

    int re = 1;
    sort(points.begin(), points.end(), cmp);
    int j = 0;
    for (int i = 1; i < points.size(); i++)
    {
        int tmp = points[j][points[j].size() - 1];
        if(tmp < points[i][0])
        {
            re++;
            j = i;
        }
    }
    return re;
}

int main()
{
    vector<vector<int>> points = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int re = findMinArrowShot(points);
    cout << re;
    system("pause");
    return 0;
}