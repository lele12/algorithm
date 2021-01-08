#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minimumDeleteSum(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if(s1[i-1] == s2[j-1]){
                memo[i][j] = int(s1[i - 1]) + memo[i - 1][j - 1];
            }else{
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }
    int s = 0;
    for (int i = 0; i < m; i++){
        s += int(s1[i]);
    }
    for (int i = 0; i < n; i++){
        s += int(s2[i]);
    }
    s = s - 2 * memo[m][n];
    return s;
}
int main(){
    string s1 = "delete";
    string s2 = "leet";
    int s = minimumDeleteSum(s1, s2);
    cout << s;
    system("pause");
    return 0;
}