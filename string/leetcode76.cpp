#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace __gnu_cxx;
using namespace std;

// bool check(unordered_map<char, int>& counts, unordered_map<char, int>& window){
//     bool flag = true;
//     for (unordered_map<char, int>::iterator iter = counts.begin(); iter != counts.end(); iter++){
//         char ch = iter->first;
//         if(window[ch] < counts[ch] ){
//             flag = false;
//             break;
//         }
//     }
//     return flag;
// }

// string minWindow(string s, string t){
//     int left = 0;
//     int right = 0;
//     unordered_map<char, int> counts;
//     unordered_map<char, int> window;
//     for (char ch:t){
//         counts[ch]++;
//     }
//     string re;
//     int min_l = 0;
//     int min_r = 0;
//     int length = s.length()+1;
//     while(right < s.size()){
//         char ch = s[right];
//         right++;
//         if(counts.count(ch)){
//             window[ch]++;
//         }
//         if(check(counts, window)){
//             while(left < right){
//                 char ch_l = s[left];
//                 if(window.count(ch_l)){
//                     window[ch_l]--;
//                     if(!check(counts, window)){
//                         if(right - left  < length){
//                             length = right - left;
//                             min_l = left;
//                             min_r = right;
//                         }
//                         left++;
//                         break;
//                     }
//                 }
//                 left++;
//             }
            
//         }
//     }
//     if (length <= s.size())
//     {
//         re = s.substr(min_l, length);
//     }
//     return re;
// }

string minWindow(string s, string t){
    int left = 0, right = 0;
    unordered_map<char, int> counts, window;
    int min_size = s.size() + 1;
    int min_left = 0;
    for(char & ch:t){
        counts[ch]++;
    }
    int valid = 0;
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
            if(counts.count(ch_l)){
                if(counts[ch_l] == window[ch_l]){
                    valid--;
                    if(right - left < min_size){
                        min_size = right - left;
                        min_left = left;
                    }
                }
                window[ch_l]--;
            }
            left++;
        }
    }
    string re;
    if (min_size <= s.size())
    {
        re = s.substr(min_left, min_size);
    }
    return re;
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string re = minWindow(s, t); 
    cout << re;
    system("pause");
    return 0;
}