#include <vector>
#include <string>
#include <iostream>


using namespace std;

void backtracking(string& path, vector<string>& res, string digits, int start){
    vector<string> mm = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if (path.size() != 0 && path.size() == digits.size()){
        res.push_back(path);
        return;
    }

    for (int i = start; i < digits.size(); i++){
        string dig = mm[digits[start] - '2'];
        for (int j = 0; j < dig.size(); j++){
            path.push_back(dig[j]);
            backtracking(path, res, digits, i+1);
            path.pop_back();
        }
    }
    
}
vector<string> letterCombinations(string digits){
    vector<string> res;
    string path;
    backtracking(path, res, digits, 0);
    return res;
}

int main(){
    string digits = "2";
    vector<string> res = letterCombinations(digits);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << ' ';
    }
    system("pause");
    return 0;
}