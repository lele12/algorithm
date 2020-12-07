#include <iostream>
#include <vector>
#include <string>

using namespace std;

string findLongestWord(string s, vector<string>& d)
{
    int index = -1;
    int length = 0;
    for (int i = 0; i < d.size(); i++)
    {
        int m = s.length() - 1;
        int n = d[i].length() - 1;
        while(m >= 0 && n >= 0 && m >= n)
        {
            if(s[m] == d[i][n])
            {
                m--;
                n--;
            }
            else
            {
                m--;
            }
        }
        if(n < 0)
        {
            if (length < d[i].length())
            {
                index = i;
                length = d[i].length();
            }
            else if(length ==  d[i].length())
            {
                if(d[index] > d[i])
                {
                    index = i;
                    length = d[i].length();
                }
            }
        }
    }
    if (index != -1)
    {
        return d[index];
    }
    else
    {
        return "";
    }
}
int main()
{
    vector<string> d = {"ale","apple","monkey","plea"};
    string s = "abpcplea";
    string re = findLongestWord(s, d);
    cout << re;
    system("pause");
    return 0;
}