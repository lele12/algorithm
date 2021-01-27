#include <iostream>
#include <string>
#include <stack>

using namespace std;
string removeDuplicates(string S){
    stack<char> ss;
    for (int i = S.length() - 1; i >= 0; i--){
        if (ss.empty()){
            ss.push(S[i]);
        }else if (S[i] != ss.top()){
            ss.push(S[i]);
        }else{
            ss.pop();
        }
    }
    string re;
    while(!ss.empty()){
        re += ss.top();
        ss.pop();
    }
    return re;
}

int main(){
    string S = "abbaca";
    string re = removeDuplicates(S);
    cout << re;
    system("pause");
    return 0;
}