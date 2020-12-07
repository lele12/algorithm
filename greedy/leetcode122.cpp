#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int re = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        
        if(prices[i] - prices[i-1] > 0)
        {
            re += prices[i] - prices[i - 1];
        }
    }
    return re;
}

int main()
{
    vector<int> prices = {7,6,4,3,1};
    int re = maxProfit(prices);
    cout << re;
    system("pause");
    return 0;
}