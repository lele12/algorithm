#include <iostream>
#include <vector>

using std::vector;

void dsf(vector<vector<int>>& M, int l, int r){
    for (int i = 0; i < M[l].size(); i++){
        if (M[l][i] == 1){
            M[l][i] = 0;
            dsf(M, i, l);
        }
        
    }
    return;
}
int findCircleNum(vector<vector<int>>& M){
    if (M.size() == 0 && M[0].size() == 0){
        return 0;
    }
    int count = 0;
    for (int i = 0; i < M.size(); i++){  
        if (M[i][i] == 1){
            M[i][i] = 0;
            dsf(M, i, i);
            count++;
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> M = { { 1, 1, 0 },
                              { 1, 1, 0 },
                              { 0, 0, 1 } };
    int re = findCircleNum(M);
    std::cout << re;
    system("pause");
    return 0;
}