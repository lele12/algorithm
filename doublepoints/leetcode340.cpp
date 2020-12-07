#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k)
{
    if (s.size() == 0 || k <= 0){
        return 0;
    }
    int len = 0;
    unordered_map<char, int> m;
    int i = 0;
    for (int j = 0; j < s.size(); j++)
    {
        m[s[j]]++;
        if (m.size() > k)
        {
            if (j - i > len)
            {
                len = j - i;
            }
            while(m.size() > k)
            {
                m[s[i]]--;
                if(m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                i++;
                
            }
        }
    }
    if (s.size() - i > len)
    {
        len = s.size() - i;
    }
    return len;
}
int main()
{
    string s = "eceba";
    int k = 2;
    int re = lengthOfLongestSubstringKDistinct(s, k);
    cout << re;
    system("pause");
    return 0;
}