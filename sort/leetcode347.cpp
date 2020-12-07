#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    int max_count = 0;
    unordered_map<int, int> counts;
    for(const int &num : nums)
    {   
        counts[num]++;
        max_count = max(max_count, counts[num]);
    }

    vector<vector<int>> buckets(max_count + 1);
    for(const auto& p: counts)
    {
        buckets[p.second].push_back(p.first);
    }
    vector<int> re;
    for (int i = buckets.size() - 1; i >= 0 ; i--)
    {
        for(const int &num :buckets[i])
        {
            re.push_back(num);
            if(re.size() == k)
            {
                return re;
            }
        }
    }
    return re; 
}

int main()
{
    vector<int> nums = {1};
    int k = 1;
    vector<int> re = topKFrequent(nums, k);
    for(int i = 0; i < re.size(); i++)
    {
        cout << re[i] << ' ';
    }
    system("pause");
    return 0;
}