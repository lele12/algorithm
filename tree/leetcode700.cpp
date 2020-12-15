#include <iostream>
#include "tree.h"

using namespace std;

TreeNode* searchBST(TreeNode* root, int val){
    if (root == nullptr){
        return nullptr;
    }
    if (root->val == val){
        return root;
    }
    if (root->val < val){
        return searchBST(root->left, val);
    }
    if (root->val > val){
        return searchBST(root->right, val);
    }
}

int main(){
    TreeNode *root;
    int i = 0;
    vector<int> nums = {};
    makeTree(root, nums, i);
    // root = searchBST(root, 2);
    return 0;
}