#include "binary_tree.h"

TreeNode *cur = new TreeNode(0);

TreeNode* convertBST(TreeNode* root){
    if (root == nullptr){
        return nullptr;
    }
    root->right = convertBST(root->right);
    root->val += cur->val;
    cur->val = root->val;
    root->left = convertBST(root->left);
    return root;
}

int main(){
    vector<int> nums = {4, 2, 7, 1, 3};

    TreeNode* root = make_tree(nums);
    TreeNode *node = convertBST(root);
    system("pause");
    return 0;
}