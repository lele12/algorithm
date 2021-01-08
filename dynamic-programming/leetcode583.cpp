#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestCommonSubsequence(string word1, string word2){
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> mome(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if(word1[i-1] == word2[j-1]){
                mome[i][j] = 1 + mome[i - 1][j - 1];
            }else{
                mome[i][j] = max(mome[i - 1][j], mome[i][j - 1]);
            }
        }
    }
    return mome[m][n];
}
int minDistance(string word1, string word2){
    int m = word1.length();
    int n = word2.length();
    int s = longestCommonSubsequence(word1, word2);
    return m + n - 2 * s;
}
int main(){
    string word1 = "sea";
    string word2 = "eat";
    cout << minDistance(word1, word2);
    system("pause");
    return 0;
}