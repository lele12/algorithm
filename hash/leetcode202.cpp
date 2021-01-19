#include <iostream>
#include <set>

using namespace std;

int getSum(int n){
    int sum = 0;
    while(n){
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n){
    set<int> repeat;
    int sum = n;
    repeat.insert(sum);

    while(sum != 1){
        sum = getSum(sum);
        if (repeat.count(sum)){
            return false;
        }
        repeat.insert(sum);
    }
    return true;
}

int main(){
    int n = 19;
    bool re = isHappy(n);
    cout << re;
    system("pause");
    return 0;
}