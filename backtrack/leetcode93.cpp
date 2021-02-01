#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(const string& s, int start, int end) {
    if (start > end) {
        return false;
    }
    if (s[start] == '0' && start != end) { // 0开头的数字不合法
            return false;
    }
    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
            return false;
        }
        num = num * 10 + (s[i] - '0');
        if (num > 255) { // 如果大于255了不合法
            return false;
        }
    }
    return true;
}

void backtracking(vector<string>& path, vector<vector<string>>& res, const string& s, int index, int start){
    if (index >= 4){
        if (index == 4 && start >= s.length()){
            res.push_back(path);
        }
        return;
    }
    for (int i = start; i < s.length(); i++){
        string sub_s = s.substr(start, i - start + 1);
        if (isValid(s, start, i)){
            path.push_back(sub_s);
            backtracking(path, res, s, index + 1, i+1);
            path.pop_back();
        }
    }
}
vector<string> restoreIpAddresses(string s){
    vector<string> path;
    vector<vector<string>> res;
    backtracking(path, res, s, 0, 0);
    vector<string> ips;
    for (int i = 0; i < res.size(); i++){
        string ip = "";
        for (int j = 0; j < res[i].size(); j++){
            ip += res[i][j];
            if (j != res[i].size() - 1){
                ip += ".";
            }
        }
        ips.push_back(ip);
    }
    return ips;
}

int main(){
    string s = "25525511135";
    vector<string> res = restoreIpAddresses(s);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << ' ';
    }
    system("pause");
    return 0;
    
}