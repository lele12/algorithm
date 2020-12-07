#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>&b)
{
    if(a[0] > b[0])
    {
        return true;
    }
    else if (a[0] == b[0])
    {
        if (a[1] < b[1])
        {
            return true;
        }
        
    }
    return false;
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
    sort(people.begin(), people.end(), cmp);
    vector<vector<int>> re;
    for(int i = 0; i < people.size(); i++)
    {
        re.insert(re.begin() + people[i][1], people[i]);
    }
    return re;
}

int main()
{
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> re = reconstructQueue(people);
    system("pause");
    return 0;
}