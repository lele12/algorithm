#include <iostream>
#include <cmath>


using namespace std;

bool judgeSequareSum(int c)
{
    long s = sqrt(c);
    long i = 0;
    while(i <= s)
    {
        if(i * i + s * s == c)
        {
            return true;
        }
        else if (i * i + s * s < c)
        {
            i++;
        }
        else
        {
            s--;
        }
    }
    return false;
}
int main()
{
    system("pause");
    return 0;
}