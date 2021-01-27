#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> get_next(string s){
    vector<int> next(s.length(), 0);
    for (int i = 0; i < s.length(); i++){
        
    }
    return next;
}

vector<int> getNext(const string& s) {
    vector<int> next(s.length(), 0);
    int j = -1;
    next[0] = j;
    for(int i = 1; i < s.size(); i++) { // 注意i从1开始
        while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
            j = next[j]; // 向前回溯
        }
        if (s[i] == s[j + 1]) { // 找到相同的前后缀
            j++;
        }
        next[i] = j; // 将j（前缀的长度）赋给next[i]
    }
    return next;
}
int strStr(string haystack, string needle){
    if (needle.length() == 0){
        return 0;
    }
    vector<int> next = getNext(needle);
    int j = -1;
    for (int i = 0; i < haystack.length(); i++){
        while (j >= 0 && haystack[i] != needle[j+1]){
            j = next[j];
        }
        if (haystack[i] == needle[j+1]){
            j++;
        }
        if (j == needle.length() - 1){
            return i - needle.length() + 1;
        }

    }
    return -1;
}

int main(){
    string haystack = "mississippi";
    string needle = "issip";
    int re = strStr(haystack, needle);
    cout << re;
    system("pause");
    return 0;
}