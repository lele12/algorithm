#include "binary_tree.h"
#include <queue>

// int maxDepth(TreeNode* root){
//     if (root == nullptr){
//         return 0;
//     }
//     int left = maxDepth(root->left);
//     int right = maxDepth(root->right);
//     return 1 + max(left, right);
// }

int maxDepth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    int layer = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()){
        int q_size = q.size();
        layer++;
        for (int i = 0; i < q_size; i++){
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left){
                q.push(cur->left);
            }
            if (cur->right){
                q.push(cur->right);
            }
        }
    }
    return layer;
}
int main(){
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *root = make_tree(nums);
    int depth = maxDepth(root);
    system("pause");
    return 0;
}