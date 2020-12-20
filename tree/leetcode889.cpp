#include <iostream>
#include "tree.h"

using namespace std;

TreeNode * build(vector<int>& pre, int pre_low, int pre_high,
        vector<int>& post, int post_low, int post_high){
    if (pre_high <= pre_low){
        return nullptr;
    }
    if (pre_high-pre_low == 1){
        return new TreeNode(pre[pre_low]);
    }
    TreeNode *root = new TreeNode(pre[pre_low]);
    int idx = 0;
    for (int i = 0; i < post.size() - 1; i++){
        if (post[i] == pre[pre_low+1]){
            idx = i;
            break;
        }
    }
    int s = idx - post_low + 1;
    root->left = build(pre, pre_low + 1, pre_low + 1 + s, post, post_low, post_low + s);
    root->right = build(pre, pre_low + 1 + s, pre_high, post, post_low + s, post_high - 1);
    return root;
}
TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post){
    return build(pre, 0, pre.size(), post, 0, post.size());
}

int main(){
        vector<int> pre_order = {1,2,4,5,3,6,7};
    vector<int> in_order = {4,5,2,6,7,3,1};
    TreeNode *root = constructFromPrePost(pre_order, in_order);
    layer_order(root);
    system("pause");
    return 0;
}