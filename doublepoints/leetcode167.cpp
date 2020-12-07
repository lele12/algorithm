#include <iostream>
#include <vector>

using namespace std;


vector<int> twoSum(vector<int>& numbers, int target)
{
    int i = 0, j = numbers.size() - 1;
    vector<int> re(2, 0);
    while(i < j)
    {
        if (numbers[i] + numbers[j] == target)
        {
            re[0] = i;
            re[1] = j;
            return re;
        }
        else if (numbers[i] + numbers[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}
int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> re = twoSum(numbers, target);
    cout << re[0] << ' ' << re[1] << endl;
    system("pause");
    return 0;
}