#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void reverseString(vector<char>& s){
    int left = 0;
    int right = s.size() - 1;
    while(left < right){
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return;
}

int main(){
    vector<char> s = {'h', 'e', 'l', 'l', '0'};
    reverseString(s);
    for (int i = 0; i < s.size(); i++){
        cout << s[i] << ' ';
    }
    system("pause");
    return 0;
}