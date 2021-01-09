#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2){
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++){
        memo[i][0] = memo[i-1][0] + 1;
    }
    for (int j = 1; j <= n; j++){
        memo[0][j] = memo[0][j-1] + 1;
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if(word1[i-1] == word2[j-1]){
                memo[i][j] = memo[i - 1][j - 1];
            }else{
                memo[i][j] = min(min(memo[i][j - 1], memo[i - 1][j]), memo[i - 1][j - 1]) + 1;
            }
        }
    }

    return memo[m][n];
}

int main(){
    string word1 = "horse";
    string word2 = "ros";
    int re = minDistance(word1, word2);
    cout << re;
    system("pause");
    return 0;
}