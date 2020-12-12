#include <iostream>
#include "tree.h"

using namespace std;

int diameterOfBinaryTree(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    int depth = maxDepth(root->left) + maxDepth(root->right);
    int dep = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
    return max(depth, dep);
}

int main(){
    vector<int>nums = {1, 2, 3, 4, 5, -1, -1};
    TreeNode* root;
    int i = 0;
    makeTree(root, nums, i);
    cout << diameterOfBinaryTree(root);
    return 0;
}