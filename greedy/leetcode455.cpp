#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int re = 0;
    int a = 0, b = 0;
    while(a < g.size() && b < s.size())
    {
        if (g[a] <= s[b])
        {
            re++;
            a++;
            b++;
        }
        else
        {
            b++;
        }
    }

        return re;
}

int main()
{
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};
    int re = findContentChildren(g, s);
    cout << re << endl;
    system("pause");
    return 0;
}