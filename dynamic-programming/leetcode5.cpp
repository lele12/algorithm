#include <iostream>
#include <string>

using namespace std;

string palindrome(const string& s, int l, int r){
    while(l >=0 && r<s.length() && s[l] == s[r]){
        l--;
        r++;
    }
    return s.substr(l+1, r - l-1);
}

string longestPalindrome(string s){
    string res;
    for (int i = 0; i < s.length(); i++){
        string s1 = palindrome(s, i, i);
        string s2 = palindrome(s, i, i + 1);
        if(res.size() < s1.size()){
            res = s1;
        }
        if(res.size() < s2.size()){
            res = s2;
        }
    }
    return res;
}

int main(){
    string s = "babad";
    string re = longestPalindrome(s);
    cout << re;
    system("pause");
    return 0;
}