#include <iostream>
#include <vector>

using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& booking, int n){
    vector<int> nums(n, 0);
    for (int i = 0; i < booking.size(); i++){
        int a = booking[i][0]-1;
        int b = booking[i][1];
        int val = booking[i][2];
        nums[a] += val;
        if(b < n){
            nums[b] -= val;
        }
    }
    for (int i = 1; i < nums.size(); i++){
        nums[i] += nums[i - 1];
    }
    return nums;
}

int main(){
    vector<vector<int>> booking = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    int n = 5;
    vector<int> re = corpFlightBookings(booking, n);
    for (int i = 0; i < re.size(); i++){
        cout << re[i] << ' ';
    }
    system("pause");
    return 0;
}