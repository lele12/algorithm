#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate_matrix(int n){
    vector<vector<int>> re(n, vector<int>(n, 0));

    int loop = n / 2;
    int left = 0, right = n, top = 0, bottom = n;
    int offset = 1;
    int value = 1;
    while (loop){
        for (int i = left + offset - 1; i < right - offset; i++){
            re[top + offset - 1][i] = value;
            value++;
        }

        for (int i = top + offset - 1; i < bottom - offset; i++){
            re[i][right - offset] = value;
            value++;
        }

        for (int i = right - offset; i > top + (offset - 1); i--){
            re[bottom - offset][i] = value;
            value++;
        }

        for (int i = bottom - offset; i > left + (offset - 1); i--){
            re[i][left + offset - 1] = value;
            value++;
        }
        offset++;
        loop--;
    }

    int mid = n / 2;
    if (n % 2 == 1){
        re[mid][mid] = value;
    }

    return re;
}
int main(){
    int n = 0;
    vector<vector<int>> re = generate_matrix(n);
    for (int i = 0; i < re.size(); i++){
        for (int j = 0; j < re[i].size(); j++){
            cout << re[i][j] << ' ';
        }
        cout << endl;
    }

    system("pause");
    return 0;
} 