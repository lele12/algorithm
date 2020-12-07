#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>&flowerbed, int n)
{
    if (flowerbed.size() == 0 && n == 0)
    {
        return true;
    }
    if (flowerbed.size() == 1 && n == 0)
    {
        return true;
    }
    if(flowerbed.size() == 1 && flowerbed[0] == 0)
    {
        return true;
    }
    int s = 0;
    for (int i = 0; i < flowerbed.size(); i ++)
    {
        if (i == 0)
        {
            if (flowerbed[i]+flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                s++;
            }
        }
        else if( i != flowerbed.size()-1)
        {
            if(flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                s++;
            }
        }
        else
        {
            if(flowerbed[i-1] + flowerbed[i] == 0)
            {
                flowerbed[i] = 1;
                s++;
            }
        }
        if (s == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> flowerbed = {1, 0, 0, 0, 0, 1};
    int n = 2;
    bool is_can = canPlaceFlowers(flowerbed, n);
    cout << is_can;
    system("pause");
    return 0;
}