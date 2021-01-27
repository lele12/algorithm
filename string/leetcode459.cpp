#include <iostream>
#include <string>

using namespace std;

bool repeatedSubstringPattern(string s){
    if (s.length() ==  1){
        return false;
    }
    for (int i = 0; i < s.length() / 2; i++){
        if (s.length() % (i + 1) != 0){
            continue;
        }
        string sub = s.substr(0, i + 1);
        int repeat = s.length() / (i + 1);
        string ss;
        while(repeat--){
            ss += sub;
        }
        if (ss == s){
            return true;
        }
    }
    return false;
}

int main(){
    string s = "abcabcabc";
    bool re = repeatedSubstringPattern(s);
    cout << re;
    system("pause");
    return 0;
}