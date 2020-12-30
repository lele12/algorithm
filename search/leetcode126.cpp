#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
    set<string> word_list(wordList.begin(), wordList.end());
    map<char, string> word_list_map;
    map<string, string> word_list_index;
    for (int i = 0; i < wordList.size(); i++){
        word_list_map['0' + i] = wordList[i];
        word_list_index[wordList[i]] = to_string(i);
    }
    queue<string> q;
    set<string> visited;
    int step = 0;
    string begin = "a";
    q.push(begin);
    visited.insert(beginWord);
    vector<string> ans;
    while(!q.empty()){
        int q_size = q.size();
        vector<string> tmp;
        for (int i = 0; i < q_size; i++){
            string index = q.front();
            q.pop();
            string cur;
            if (index[index.size()-1] == 'a'){
                cur = beginWord;
            }else{
                cur = word_list_map[index[index.size() - 1]];
            }
            if (cur == endWord){
                ans.push_back(index);
            }
            
            for (int j = 0; j < cur.size(); j++){
                for (int k = 0; k < 26; k ++){
                    string new_word = cur;
                    new_word[j] = 'a' + k;
                    if (word_list.find(new_word) == word_list.end()){
                        continue;
                    }
                    if (visited.find(new_word) == visited.end()){
                        q.push(index + word_list_index[new_word]);
                        tmp.push_back(new_word);             
                    }
                }
            }

        }
        for(auto t:tmp){
            visited.insert(t);
        }
        if (ans.size() > 0){
            break;
        }
    }
    vector<vector<string>> res;
    for (int i = 0; i < ans.size(); i++){
        vector<string> re;
        for (int j = 0; j < ans[i].size(); j++){
            if (ans[i][j] == 'a'){
                re.push_back(beginWord);
            }else{
                re.push_back(word_list_map[ans[i][j]]);
            }
        }
        res.push_back(re);
    }
    return res;
}

int main(){

    string begin_word = "teach";
    string end_word = "place";
    vector<string> word_list = {"peale","wilts","place","fetch","purer","pooch","peace","poach","berra","teach","rheum","peach"};
    vector<vector<string>> res = findLadders(begin_word, end_word, word_list);
    for (int i = 0; i < res.size(); i++){
        vector<string> re;
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}