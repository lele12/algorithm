#include <iostream>
#include <vector>

using namespace std;

int mySqrt(int x)
{
    if (x <= 1)
    {
        return x;
    }

    int left = 0;
    int right = x;
    while(left < right)
    {
        int mid = left + (right - left) / 2;
        if (mid * mid == x)
        {
            return mid;
        }
        else if (mid * mid < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return right - 1;
}

int main()
{
    int x = 3;
    int re = mySqrt(x);
    cout << re;
    system("pause");
    return 0;
}