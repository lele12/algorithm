#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace __gnu_cxx;
using namespace std;

bool check( unordered_map<char, int> &ori,  unordered_map<char, int>& counts)
{
    for ( unordered_map<char, int>::iterator it = ori.begin(); it != ori.end(); it++)
    {
        if(counts[it->first] < it->second)
        {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t)
{
    unordered_map<char, int> ori;
    unordered_map<char, int> counts;
    for (int i = 0; i < t.size(); i++)
    {
        ori[t[i]]++;
    }

        int l = 0;
    int cnt = 0;
    int min_size = s.size() + 1, min_l = 0, min_r = 0;
    for (int r = 0; r < s.size(); r++)
    {
        if(ori.find(s[r]) != ori.end())
        {
            counts[s[r]]++;
        }

        if(check(ori, counts))
        {
            while(l <= r)
            {
                if(ori.find(s[l]) != ori.end())
                {
                    counts[s[l]]--;
                    
                    if (!check(ori, counts))
                    {
                        if (r - l < min_size)
                        {
                            min_size = r - l + 1;
                            min_l = l;
                            min_r = r;
                        }
                        l++;
                        break;
                    }
                }
                l++;
            }
        }
    }
    if (min_size > s.size())
    {
        return "";
    }
    else
    {
        return s.substr(min_l, min_size);
    }
    
}

int main()
{
    string s = "cabefgecdaecf";
    string t = "cae";
    string re = minWindow(s, t);
    cout << re;
    system("pause");
    return 0;
}