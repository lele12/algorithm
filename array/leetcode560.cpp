#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace __gnu_cxx;

int subarraySum(vector<int>& nums, int k){
    int n = nums.size();
    unordered_map<int, int> s;
    int pre = 0;
    s[0] = 1;
    int count = 0;
    for (int i = 0; i < nums.size(); i++){
        int cur = pre + nums[i];
        pre = cur;
        if(s.find(cur-k) != s.end()){
            count += s[cur-k];
        }
        s[cur] ++;
    }
    return count;
}
int main(){
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int re = subarraySum(nums, k);
    cout << re;
    system("pause");
    return 0;
}