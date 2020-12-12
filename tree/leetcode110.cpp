#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;


bool isBalanced(TreeNode* root){
    if (root == nullptr){
        return true;
    }
    return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main(){
    vector<int> nums = {};
    TreeNode* root;
    int i = 0;
    makeTree(root, nums, i);
    cout << isBalanced(root);
    return 0;
}