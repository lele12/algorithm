#include "binary_tree.h"

TreeNode* insertIntoBST(TreeNode* root, int val){
    if (root == nullptr){
        root = new TreeNode(val);
    }
    if (root->val > val){
        root->left = insertIntoBST(root->left, val);
    }
    if (root->val < val){
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}
int main(){
    vector<int> nums = {4, 2, 7, 1, 3};
    int val = 5;
    TreeNode *root = make_tree(nums);
    TreeNode *node = insertIntoBST(root, 5);
    system("pause");
    return 0;
}