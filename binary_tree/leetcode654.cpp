#include "binary_tree.h"

int find_max_value(const vector<int>& nums, int left, int right){
    int value = INT_MIN;
    int idx = 0;
    for (int i = left; i <= right; i++){
        if (value < nums[i]){
            value = nums[i];
            idx = i;
        }
    }
    return idx;
}

TreeNode* construct(const vector<int>& nums, int left, int right){
    if (left > right){
        return nullptr;
    }

    int idx = find_max_value(nums, left, right);
    TreeNode *root = new TreeNode(nums[idx]);
    root->left = construct(nums, left, idx - 1);
    root->right = construct(nums, idx + 1, right);
    return root;
}
TreeNode* constructMaximumBinaryTree(vector<int>& nums){
    return construct(nums, 0, nums.size() - 1);
}

int main(){
    vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode *root = constructMaximumBinaryTree(nums);
    system("pause");
    return 0;
}