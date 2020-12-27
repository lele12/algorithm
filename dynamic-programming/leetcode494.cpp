#include <iostream>
#include <vector>

using namespace std;
void findWays(vector<int>& nums, int i, vector<string>& res, int S){
    if (i == nums.size()-1 && S == nums[i]){
        
    }
    findWays(nums, i + 1, res, S - nums[i]);
    findWays(nums, i + 1, res, S + nums[i]);
}
int findTargetSumWays(vector<int>& nums, int S){

}
int main(){
    system("pause");
    return 0;
}