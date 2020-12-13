#include <iostream>
#include "tree.h"

using namespace std;
TreeNode* build(const vector<int>& nums, int low, int high){
    if (low >= high){
        return nullptr;
    }

    int max_num = INT_MIN;
    int idx = -1;
    for (int i = low; i < high; i++){
        if (max_num < nums[i]){
            max_num = nums[i];
            idx = i;
        }
    }
    TreeNode *root = new TreeNode(max_num);
    root->left = build(nums, low, idx);
    root->right = build(nums, idx + 1, high);
    return root;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums){
    return build(nums, 0, nums.size());
}
int main(){
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* root = constructMaximumBinaryTree(nums);
    system("pause");
    return 0; 
}