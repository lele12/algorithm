#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int evalRPN(vector<string>& tokens){
    stack<int> ss;
    for (int i = 0; i < tokens.size(); i++){
        if (tokens[i] == "*"){
            int a = ss.top();
            ss.pop();
            int b = ss.top();
            ss.pop();
            ss.push(a * b);
        }else if(tokens[i] == "/"){
            int a = ss.top();
            ss.pop();
            int b = ss.top();
            ss.pop();
            ss.push(b / a);
        }else if(tokens[i] == "+"){
            int a = ss.top();
            ss.pop();
            int b = ss.top();
            ss.pop();
            ss.push(a + b);
        }
        else if(tokens[i] == "-"){
            int a = ss.top();
            ss.pop();
            int b = ss.top();
            ss.pop();
            ss.push(b - a);
        }else{
            ss.push(stoi(tokens[i]));
        }
    }
    return ss.top();
}

int main(){
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(tokens);
    system("pause");
    return 0;
}