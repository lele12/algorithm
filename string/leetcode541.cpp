#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void reverseString(string& s, int left, int right){
    while(left < right){
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

string reverseStr(string s, int k){
    int s_len = s.length();
    int i = 0;
    while(i < s_len){
        if (i + k - 1 >= s_len){
            reverseString(s, i, s_len - 1);
        }else{
            reverseString(s, i, i + k - 1);
        }
        i += 2 * k;
    }
    return s;
}

int main(){
    string s = "abcdefgl";
    int k = 3;
    string re = reverseStr(s, k);
    cout << re;
    system("pause");
    return 0;
}

