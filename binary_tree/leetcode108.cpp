#include "binary_tree.h"
TreeNode* make(const vector<int>& nums, int left, int right){
    if (left > right){
        return nullptr;
    }
    int mid = left + (right - left)/2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = make(nums, left, mid - 1);
    root->right = make(nums, mid + 1, right);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums){
    return make(nums, 0, nums.size() - 1);
}

int main(){
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode *node = sortedArrayToBST(nums);
    system("pause");
    return 0;
}