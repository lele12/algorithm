#include <iostream>
#include <queue>
#include <set>

using namespace std;

string plusone(string cur, int j){
    if (cur[j] == '9'){
        cur[j] = '0';
    }else{
        cur[j] += 1;
    }
    return cur;
}

string minuone(string cur, int j){
    if (cur[j] == '0'){
        cur[j] = '9';
    }else{
        cur[j] -= 1;
    }
    return cur;
}

int openLock(vector<string>& deadends, string target){
    queue<string> q;
    set<string> visited;
    set<string> deads(deadends.begin(), deadends.end());
    q.push("0000");
    visited.insert("0000");
    int step = 0;
    while(!q.empty()){
        int q_size = q.size();
        for (int i = 0; i < q_size; i++){
            string cur = q.front();
            q.pop();
            if (deads.find(cur) != deads.end()){
                continue;
            }
            if (cur == target){
                return step;
            }
            for (int j = 0; j < 4; j++){
                string up = plusone(cur, j);
                if(visited.find(up) == visited.end()){
                    q.push(up);
                    visited.insert(up);
                }

                string down = minuone(cur, j);
                if (visited.find(down) == visited.end()){
                    q.push(down);
                    visited.insert(down);
                }
            }
        }
        step++;
    }
    return -1;
}

int main(){
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    int re = openLock(deadends, target);
    cout << re;

    system("pause");
    return 0;
}