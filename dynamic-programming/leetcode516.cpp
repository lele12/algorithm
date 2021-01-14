#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestPalindromeSubseq(string s){
    int len_s = s.length();
    vector<vector<int>> dp(len_s, vector<int>(len_s, 0));
    for (int i = 0; i < len_s; i++){
        dp[i][i] = 1;
    }
        for (int i = len_s - 1; i >= 0; i--)
        {
            for (int j = i+1; j < len_s; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
    return dp[0][len_s - 1];
}

int main(){
    string s = "bbbab";
    int re = longestPalindromeSubseq(s);
    cout << re;
    system("pause");
    return 0;
}