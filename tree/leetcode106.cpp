#include<iostream>
#include"tree.h"

using namespace std;
TreeNode* build(const vector<int>& inorder, int in_low, int in_high,
                const vector<int>& postorder, int post_low, int post_high){
    if (in_low >= in_high){
        return nullptr;
    }
    int idx = -1;
    for (int i = in_low; i < in_high; i++){
        if (inorder[i] == postorder[post_high-1]){
            idx = i;
            break;
        }
    }
    int len_right = in_high - idx - 1;
    int len_left = idx - in_low;
    TreeNode *root = new TreeNode(inorder[idx]);
    root->left = build(inorder, in_low, idx, postorder, post_low, post_low+len_left);
    root->right = build(inorder, idx + 1, in_high, postorder, post_high - len_right-1, post_high-1);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
}


int main(){
    vector<int> in_order = {9,3,15,20,7};
    vector<int> post_order = {9,15,7,20,3};
    TreeNode *root = buildTree(in_order, post_order);

    system("pause");
    return 0;
}