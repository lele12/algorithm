#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

bool isValid(string s){
    stack<char> ss;
    unordered_map<char, char> m;
    m[')'] = '(';
    m['}'] = '{';
    m[']'] = '[';
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '{' or s[i] == '(' or s[i] == '['){
            ss.push(s[i]);
        }else{
            if (ss.empty()){
                return false;
            } else if (m[s[i]] != ss.top()){
                return false;
            } else{
                ss.pop();
            }
        }
    }
    return ss.empty();
}

int main(){
    string s = "()(";
    bool re = isValid(s);
    cout << re;
    system("pause");
    return 0;
}