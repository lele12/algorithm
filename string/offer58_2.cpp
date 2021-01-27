#include <iostream>
#include <string>

using namespace std;

string reverseLeftWords(string s, int n){
    int len = s.length();
    s += s;
    return s.substr(n, len);
}

int main(){
    string s = "lr";
    int k = 6;
    string re = reverseLeftWords(s, k);
    cout << re;
    system("pause");
    return 0;
}