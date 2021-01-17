#include <iostream>
#include <string>
#include <unordered_map>

using namespace __gnu_cxx;
using namespace std;

int lengthOfLongestSubstring(string s){
    if(s.length() <= 1){
        return s.length();
    }
    int left = 0, right = 0;
    unordered_map<char, int> window;
    int min_size = 0;
    while(right < s.size()){
        char ch = s[right];
        window[ch]++;
        right++;
        while(window[ch] > 1){
            window[s[left]]--; 
            left++;
        }
        if(min_size < right -left){
            min_size = right - left;
        }
    }
    return min_size;
}

int main(){
    string s = "abcabcbb";
    int re = lengthOfLongestSubstring(s);
    cout << re;
    system("pause");
    return 0;
}