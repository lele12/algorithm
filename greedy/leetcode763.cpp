#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> partitionLabels(string S)
{
    vector<int> last(26, 0);
    for (int i = 0; i < S.size(); i ++)
    {
        last[S[i] - 'a'] = i;
    }
    int i = 0;
    int end = 0;
    vector<int> re;
    while(i < S.size())
    {
        end = max(last[S[i] - 'a'], end);
        int s = 0;
        while (i < end)
        {
            i++;
            s++;
            end = max(last[S[i] - 'a'], end);
        }
        re.push_back(s+1);
        i++;
    }
    return re;
}

int main()
{
    string S = "ababcbacadefegdehijhklij";
    vector<int> re = partitionLabels(S);
    for (int i = 0; i < re.size(); i++)
    {
        cout << re[i] << ' ';
    }
    system("pause");
    return 0;
}