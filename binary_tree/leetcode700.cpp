#include "binary_tree.h"

TreeNode* searchBST(TreeNode* root, int val){
    if (root == nullptr){
        return nullptr;
    }

    if (root->val < val){
        return searchBST(root->right, val);
    }else if (root->val > val){
        return searchBST(root->left, val);
    }else if (root->val == val){
        return root;
    }
    return nullptr;
}

int main(){
    vector<int> nums = {4, 2, 7, 1, 3};
    int val = 2;
    TreeNode* root = make_tree(nums);
    TreeNode *node = searchBST(root, val);
    system("pause");
    return 0;
}