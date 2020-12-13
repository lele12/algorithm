#include <iostream>
#include "tree.h"

using namespace std;

TreeNode* build(vector<int>& preorder, int pre_low, int pre_high, vector<int>& inorder, int in_low, int in_high){
    if (pre_low >= pre_high){
        return nullptr;
    }
    int idx = -1;
    for (int i = in_low; i < in_high; i++){
        if (preorder[pre_low] == inorder[i]){
            idx = i;
            break;
        }
    }
    int left_num = idx - in_low;
    TreeNode *root = new TreeNode(preorder[pre_low]);
    root->left = build(preorder, pre_low+1, pre_low+left_num+1, inorder, in_low, idx);
    root->right = build(preorder, pre_low+left_num+1, pre_high, inorder, idx + 1, in_high);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}


int main(){
    vector<int> pre_order = {1, 2};
    vector<int> in_order = {1, 2};
    TreeNode *root = buildTree(pre_order, in_order);
    system("pause"); 
    return 0;
}