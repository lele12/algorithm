#include <iostream>
#include "tree.h"

using namespace std;
TreeNode *pre = nullptr;

bool isValidBST(TreeNode* root){
    if (root == nullptr){
        return true;
    }

    bool left = isValidBST(root->left);
    if (pre && pre->val >= root->val){
        return false;
    }
    pre = root;
    bool right = isValidBST(root->right);
    return left && right;
}
int main(){
    int i = 0;
    vector<int> nums = {};
    TreeNode* root;
    makeTree(root, nums, i);

    return 0;
}