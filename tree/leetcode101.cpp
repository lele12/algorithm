#include <iostream>
#include "tree.h"

using namespace std;

bool cmp(TreeNode* left, TreeNode* right){
    if (left == nullptr && right == nullptr){
        return true;
    }
    if ((left != nullptr && right == nullptr) || (left == nullptr && right != nullptr)){
        return false;
    }
    return left->val == right->val && cmp(left->left, right->right) && cmp(left->right, right->left);
}

bool isSymmetric(TreeNode* root){
    if (root == nullptr){
        return true;
    }
    return cmp(root->left, root->right);
}

int main(){
    vector<int> nums = {1,2,3};
    TreeNode* root;
    int i = 0;
    makeTree(root, nums, i);
    cout << isSymmetric(root);

    return 0;
}