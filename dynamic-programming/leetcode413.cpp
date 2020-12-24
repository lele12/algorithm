#include <iostream>
#include <vector>
using namespace std;

int numberOfArithmeticSlices(vector<int>& A){
    if (A.size() < 3){
        return 0;
    }
    int i = 0, j = 1;
    int k = 0;
    int s = A[1] - A[0];
    int re = 0;
    while(j < A.size()){

        k = A[j] - A[j-1];

        if (k == s){
            j++;
        }else{
            if (j - i >= 3){
                re += (j - i - 2 + 1) * (j - i - 2) / 2;
            }
            i = j-1;
            s = A[j] - A[j - 1];
        }
    }
    if (j - i >= 3){
        re += (j - i - 2 + 1) * (j - i - 2) / 2;
    }

    return re;
}


int main(){
    vector<int> A = {1,2,3,4,5,6,12,14,16};
    int re = numberOfArithmeticSlices(A);
    cout << re;
    system("pause");
    return 0;
}