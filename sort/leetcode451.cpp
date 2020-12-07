#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

string frequencySort(string s)
{
    unordered_map<char, int> chs;
    int max_count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        chs[s[i]]++;
        max_count = max(max_count, chs[s[i]]);
    }
    vector<vector<char>> buckets(max_count + 1);
    for(const auto &p: chs)
    {
        buckets[p.second].push_back(p.first);
    }
    string re;
    for (int i = buckets.size() - 1; i >= 0; i--)
    {
        // if (buckets[i].size() > 2)
        // {
        //     sort(buckets[i].begin(), buckets[i].end());
        // }
        for (int j = 0; j < buckets[i].size(); j++)
        {
            for (int k = 0; k < i; k++)
            {
                re += buckets[i][j];
            }
                
        }
    }
    return re;
}
int main()
{
    string s = "tree";
    string re = frequencySort(s);
    cout << re;
    system("pause");
    return 0;
}