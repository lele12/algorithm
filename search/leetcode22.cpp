#include <iostream>
#include <string>
#include <vector>

using namespace std;

void backtrack(int left, int right, string& track, vector<string>& res){
    if (right < left){
        return;
    }
    if (left < 0 || right < 0){
        return;
    }
    if (left == right && left == 0){
        res.push_back(track);
        return;
    }
    track.push_back('(');
    backtrack(left - 1, right, track, res);
    track.pop_back();
    track.push_back(')');
    backtrack(left, right - 1, track, res);
    track.pop_back();
    return;
}
vector<string> generateParenthesis(int n){
    string track;
    vector<string> res;
    backtrack(n, n, track, res);
    return res;
}


int main(){
    vector<string> res = generateParenthesis(3);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
        system("pause");
    return 0;
}