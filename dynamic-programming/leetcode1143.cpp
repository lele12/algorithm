#include <iostream>
#include <vector>
#include <string>

using namespace std;

// int dp(string text1, int i, string text2, int j, vector<vector<int>>& memo){
//     if(i == text1.length() || j == text2.length()){
//         return 0;
//     }
//     if (memo[i][j] != -1){
//         return memo[i][j];
//     }
//     if (text1[i] == text2[j]){
//         memo[i][j] = 1 + dp(text1, i + 1, text2, j + 1, memo);
//     }else{
//         memo[i][j] = max(dp(text1, i, text2, j + 1, memo), dp(text1, i + 1, text2, j, memo));
//     }
//     return memo[i][j];
// }
// int longestCommonSubsequence(string text1, string text2){
//     vector<vector<int>> memo(text1.length(), vector<int>(text2.length(), -1));
//     return dp(text1, 0, text2, 0, memo);
// }

int longestCommonSubsequence(string text1, string text2){
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if(text1[i-1] == text2[j-1]){
                memo[i][j] = 1 + memo[i-1][j-1];
            }else{
                memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
            }
        }
    }
    return memo[m][n];
}
int main(){
    string text1 = "abcde";
    string text2 = "ace";
    cout << longestCommonSubsequence(text1, text2);
    system("pause");
    return 0;
}