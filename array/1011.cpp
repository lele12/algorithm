#include <iostream>
#include <vector>

using namespace std;

bool can_finish(const vector<int>& weights, int D, int cap){
    int s = cap;
    int day = 0;
    for (int i = 0; i < weights.size(); i++){
        if(s-weights[i]>= 0){
            s -= weights[i];
        }else{
            s = cap;
            s -= weights[i];
            day ++;
        }
    }
    if (s >= 0){
        day++;
    }
    return day <= D;
}

int shipWithinDays(vector<int>& weights, int D){
    int max_num = 0;
    int sum = 0;
    for (int i = 0; i < weights.size(); i++){
        if(max_num < weights[i]){
            max_num = weights[i];
        }
        sum += weights[i];
    }
    int left = max_num;
    int right = sum + 1;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(can_finish(weights, D, mid)){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    vector<int> weights = {337,399,204,451,273,471,37,211,67,224,126,123,294,295,498,69,264,307,419,232,361,301,116,216,227,203,456,195,444,302,58,496,84,280,58,107,300,334,418,241};
    int D = 20;
    int re = shipWithinDays(weights, D);
    cout << re;
    system("pause");
    return 0;
}