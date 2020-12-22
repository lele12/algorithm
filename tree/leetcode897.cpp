#include <iostream>
#include "tree.h"

using namespace std;


void convert(TreeNode* root, TreeNode* &p){
    if(root == nullptr){
        return;
    }
    convert(root->left, p);
    p->right = new TreeNode(root->val);
    p = p->right;
    convert(root->right, p);
    return;
}
TreeNode* increasingBST(TreeNode* root){
    if(root == nullptr){
        return nullptr;
    }
    TreeNode *node = new TreeNode(0);
    TreeNode *p = node;
    convert(root, p);
    return node->right;
}
int main(){
    vector<int> nums = {5, 3, 6, 2, 4, -1, 8, 1, -1, -1, -1, 7, 9};
    int i = 0;
    TreeNode *root;
    makeTree(root, nums, i);
    increasingBST(root);
    system("pause");
    return 0;
}