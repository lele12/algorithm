#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
    set<string> word_list(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    set<string> visited;
    q.push({beginWord});
    visited.insert(beginWord);
    vector<vector<string>> res;
    while(!q.empty()){
        int q_size = q.size();
        vector<string> tmp;
        for (int i = 0; i < q_size; i++){
            vector<string> road = q.front();
            q.pop();
            string cur = road[road.size()-1];
            if (cur == endWord){
                res.push_back(road);
            }
            
            for (int j = 0; j < cur.size(); j++){
                for (int k = 0; k < 26; k ++){
                    string new_word = cur;
                    new_word[j] = 'a' + k;
                    if (word_list.find(new_word) == word_list.end()){
                        continue;
                    }
                    if (visited.find(new_word) == visited.end()){
                        vector<string> ss(road);
                        ss.push_back(new_word);
                        q.push(ss);
                        tmp.push_back(new_word);             
                    }
                }
            }

        }
        for(auto t:tmp){
            visited.insert(t);
        }
        if (res.size() > 0){
            break;
        }
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