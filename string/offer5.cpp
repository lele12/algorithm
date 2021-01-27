#include <iostream>
#include <string>

using namespace std;

string replaceSpace(string s){
    string re;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ' '){
            re += "%20";
        }else{
            re += s[i];
        }
    }
    return re;
}

int main(){
    string s = "We are happy.";
    string re = replaceSpace(s);
    system("pause");
    return 0;
}