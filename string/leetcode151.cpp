#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reverseWords(string s){
    int left = 0, right = 0;
    string re;
    vector<string> ss;
    s += ' ';
    while(right < s.length()){
        if (s[right] == ' '){
            if (left == right){
                right++;
                left++;
                continue;
            }else{
                ss.push_back(s.substr(left, right - left));
                right++;
                left = right;
            }
        }else{
            right++;
        }
    }

    for (int i = ss.size() - 1; i >= 0; i--){
        re += ss[i];
        if (i != 0){
            re += ' ';
        }
    }
    return re;
}

int main(){
    string s = "  hello world!  ";
    string re = reverseWords(s);
    cout << re;
    system("pause");
    return 0;
}