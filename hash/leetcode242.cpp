#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t){
    if (s.length() != t.length()){
        return false;
    }

    unordered_map<char, int> s_ele, t_ele;
    for (int i = 0; i < s.length(); i++){
        s_ele[s[i]]++;
        t_ele[t[i]]++;
    }

    bool flag = true;
    for (auto iter = s_ele.begin(); iter != s_ele.end(); iter++){
        char ch = iter->first;
        if (s_ele[ch] != t_ele[ch]){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){
    string s = "";
    string t = "";
    bool re = isAnagram(s, t);
    cout << re;
    system("pause");
    return 0;
}