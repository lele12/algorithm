#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
using namespace __gnu_cxx;

vector<int> findAnagrams(string s, string p){
    int left = 0, right = 0;
    unordered_map<char, int> counts, window;
    vector<int> re;
    int valid = 0;

    for(char ch:p){
        counts[ch]++;
    }
    while(right < s.size()){
        char ch = s[right];
        right++;
        if(counts.count(ch)){
            window[ch]++;
            if(counts[ch] == window[ch]){
                valid++;
            }
        }
        while(valid == counts.size()){
            char ch_l = s[left];
            // left++;
            if(right - left == p.size()){
                re.push_back(left);
            }
            if(counts.count(ch_l)){   
                if(counts[ch_l] == window[ch_l]){
                    valid--;
                }
                window[ch_l]--;
            }
            left++;

        }
    }
    return re;
}

int main(){
    string s = "abab";
    string p = "ab";
    vector<int> re = findAnagrams(s, p);
    for(int c:re){
        cout << c << ' ';
    }
    system("pause");
    return 0;
}