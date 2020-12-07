#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int candy(vector<int> &ratings)
{
    int r_size = ratings.size();
    if (r_size < 2)
    {
        return 1;
    }
    vector<int> re(r_size, 1);
    for (int i = 1; i < r_size; i++)
    {
        if(ratings[i] > ratings[i-1])
        {
            re[i] = re[i - 1] + 1;
        }
    }

    for (int i = r_size - 2; i >= 0; i--)
    {
        if(ratings[i] > ratings[i + 1])
        {
            re[i] = max(re[i + 1] + 1, re[i]);
        }
    }
    return accumulate(re.begin(), re.end(), 0);
}

int main()
{
    vector<int> ratings = {1,2,2};
    cout << candy(ratings) << endl;
    system("pause");
    return 0;
}