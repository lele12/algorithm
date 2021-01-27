#include "binary_tree.h"

vector<vector<int>> layer_order(TreeNode* root){
    vector<vector<int>> res;
    if (root == nullptr){
        return res;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()){
        int q_size = q.size();
        vector<int> re;
        for (int i = 0; i < q_size; i++){
            TreeNode* node = q.front();
            q.pop();
            re.push_back(node->val);
            if (node->left != nullptr){
                q.push(node->left);
            }
            if (node->right != nullptr){
                q.push(node->right);
            }
        }
        res.push_back(re);
    }
    return res;
}