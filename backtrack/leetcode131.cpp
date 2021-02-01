#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool is_palindromic(const string& s){
    int left = 0;
    int right = s.length() - 1;
    bool flag = true;
    while(left <= right){
        if (s[left] != s[right]){
            flag = false;
            break;
        }
        left++;
        right--;
    }
    return flag;
}

void backtracking(vector<string>& path, vector<vector<string>>& res, string s, int start){
    if (start >= s.length()){
        res.push_back(path);
        return;
    }
    for (int i = start; i < s.length(); i++){
        string sub_s = s.substr(start, i-start+1);
        if (is_palindromic(sub_s)){
            path.push_back(sub_s);
            backtracking(path, res, s, i+1);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s){
    vector<vector<string>> res;
    vector<string> path;
    backtracking(path, res, s, 0);
    return res;
}

int main(){
    string s = "aab";
    vector<vector<string>> res = partition(s);
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}