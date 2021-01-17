#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


string removeDuplicateLetters(string s){
    string re;
    vector<int> flag(26);
    vector<bool> note(26, false);
    for (int i = 0; i < s.length(); i++){
        int a = s[i] - 'a';
        flag[a]++;
    }
    stack<char> ss;
    for (int i = 0; i < s.length(); i++)
    {
        int a = s[i] - 'a';
        flag[a]--;
        if(note[a]){
            continue;
        }
        while(!ss.empty()){
            char ch = ss.top();
            if(ch > s[i] && flag[ch-'a'] > 0){
                ss.pop();
                note[ch-'a'] = false;
            }else{
                break;
            }
            
        }

        ss.push(s[i]);
        note[a] = true;
    }
    while(!ss.empty()){
        char ch = ss.top();
        re += ch;
        ss.pop();
    }
    string res;
    for (int i = re.size()-1; i >= 0; i--){
        res += re[i];
    }
    return res;
}

int main(){
    string s = "cbacdcbc";
    string re = removeDuplicateLetters(s);
    cout << re;
    system("pause");
    return 0;
}