#include "binary_tree.h"

int find_node(const vector<int>& inorder, int in_left, int in_right, int value){
    for (int i = in_left; i <= in_right; i++){
        if (inorder[i] == value){
            return i;
        }
    }
    return -1;
}
TreeNode* build(const vector<int>& preorder, int pre_left, int pre_right, 
            const vector<int>& inorder, int in_left, int in_right){
    if (pre_left > pre_right){
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[pre_left]);
    int idx = find_node(inorder, in_left, in_right, preorder[pre_left]);
    int dis = idx - in_left;
    root->left = build(preorder, pre_left + 1, pre_left + dis, inorder, in_left, idx - 1);
    root->right = build(preorder, pre_left + 1 + dis, pre_right, inorder, idx+1, in_right);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

int main(){

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(preorder, inorder);
    system("pause");
    return 0;
}