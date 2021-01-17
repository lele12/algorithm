#include <iostream>
#include <string>
#include <unordered_map>

using namespace __gnu_cxx;
using namespace std;


bool checkInclusion(string s1, string s2){
    int left = 0, right = 0;
    unordered_map<char, int> counts, window;

    for(char ch:s1){
        counts[ch]++;
    }
    int valid = 0;

    while(right < s2.size()){
        char ch = s2[right];
        right++;
        if(counts.count(ch)){
            window[ch]++;
            if(window[ch] == counts[ch]){
                valid++;
            }
        }
        while(valid == counts.size()){
            if(right - left == s1.length()){
                return true;
            }
            char ch_l = s2[left];
            left++;
            if(counts.count(ch_l)){
                if(counts[ch_l] == window[ch_l]){
                    valid--;
                }
                window[ch_l]--;
            }
        }
    }
    return false;
}

int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool re = checkInclusion(s1, s2);
    cout << re;
    system("pause");
    return 0;
}