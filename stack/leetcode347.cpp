#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include<queue>

using namespace std;

class mycomparison{
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second > b.second;
}
};

vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++){
        m[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
    for (auto iter = m.begin(); iter != m.end(); iter++){
        pri_que.push(*iter);
        if (pri_que.size() > k){
            pri_que.pop();
        }
    }


    
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> re = topKFrequent(nums, k);
    for (int i = 0; i < re.size(); i++){
        cout << re[i] << ' ';
    }
    system("pause");
    return 0;
}