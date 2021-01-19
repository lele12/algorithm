#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNodte, string magazine){
    unordered_map<char, int> m;
    for (auto ch:magazine){
        m[ch]++;
    }

    bool flag = true;
    for (auto ch:ransomNodte){
        if (!m.count(ch)){
            flag = false;
            break;
        }
        m[ch]--;
        if (m[ch] < 0){
            flag = false;
            break;
        }
    }
    return flag;
}

int main(){
    string s = "aa";
    string t = "aab";
    bool re = canConstruct(s, t);
    cout << re;
    system("pause");
    return 0;
}