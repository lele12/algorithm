#include <iostream>
#include <string>

using namespace std;

bool isPalingrome(string s, int i, int j)
{
    while(i <= j)
    {
        if(s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool validPalingrome(string s)
{
    int i = 0;
    int j = s.size();
    int num = 0;
    while(i <= j)
    {
        if (s[i] != s[j])
        {
            if (isPalingrome(s, i+1, j) || isPalingrome(s, i, j-1))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    system("pause");
    return 0;
}