#include "binary_tree.h"

int find_node(const vector<int>& inorder, int in_left, int in_right, int value){
    for (int i = in_left; i <= in_right; i++){
        if (inorder[i] == value){
            return i;
        }
    }
    return -1;
}
TreeNode* build(vector<int>& inorder, int in_left, int in_right, 
        vector<int>& postorder, int post_left, int post_right){
    if (in_left > in_right){
        return nullptr;
    }
    int idx = find_node(inorder, in_left, in_right, postorder[post_right]);
    int dis = idx - in_left;
    TreeNode *root = new TreeNode(postorder[post_right]);
    root->left = build(inorder, in_left, idx - 1, postorder, post_left, post_left + dis - 1);
    root->right = build(inorder, idx + 1, in_right, postorder, post_left + dis, post_right - 1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}

int main(){
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *root = buildTree(inorder, postorder);
    system("pause");
    return 0;
}