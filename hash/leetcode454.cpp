#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
    unordered_map<int, int> map_a, map_b;
    for (int i = 0; i < A.size(); i++){
        for (int j = 0; j < B.size(); j++){
            int val = A[i] + B[j];
            map_a[val]++;
        }
    }

    for (int i = 0; i < C.size(); i++){
        for (int j = 0; j < D.size(); j++){
            int val = C[i] + D[j];
            map_b[val]++;
        }
    }

    int sum = 0;
    for (auto s:map_a){
        int val = -s.first;
        if (map_b.count(val)){
            sum += s.second * map_b[val];
        }
    }
    return sum;
}

int main(){
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    int re = fourSumCount(A, B, C, D);
    cout << re;
    system("pause");
    return 0;
}