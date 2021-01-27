#include "binary_tree.h"

TreeNode *cur = nullptr;
bool isValidBST(TreeNode* root){
    if (root == nullptr){
        return true;
    }
    bool left = isValidBST(root->left);
    if (cur && cur->val >= root->val){
        return false;
    }
    cur = root;
    bool right = isValidBST(root->right);
    return left && right;
}

int main(){
    vector<int> nums = {2, 1, 3};
    TreeNode* root = make_tree(nums);
    bool re = isValidBST(root);
    cout << re;
    system("pause");
    return 0;
}