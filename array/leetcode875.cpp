#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_finish(const vector<int>& piles, int H, int speed){
    int times = 0;
    for (int i = 0; i < piles.size(); i++){
        int s = piles[i] % speed;
        int a = 0;
        if (s != 0){
            a = 1;
        }
        times = times + piles[i] / speed + a;
    }
    return times <= H;
}
int minEatingSpeed(vector<int>& piles, int H){
    int max_num = 0;
    for (int i = 0; i < piles.size(); i++){
        if (max_num < piles[i]){
            max_num = piles[i];
        }
    }
    int left = 1;
    int right = max_num + 1;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(can_finish(piles, H, mid)){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    vector<int> piles = {30, 11, 23, 4, 20};
    int H = 5;
    int re = minEatingSpeed(piles, H);
    cout << re;
    system("pause");
    return 0;
}