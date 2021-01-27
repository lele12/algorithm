#include "binary_tree.h"
#include <queue>

// int minDepth(TreeNode* root){
//     if (root == nullptr){
//         return 0;
//     }
//     if (root->left == nullptr && root->right == nullptr){
//         return 1;
//     }
//     if (root->left == nullptr){
//         return minDepth(root->right) + 1;
//     }
//     if (root->right == nullptr){
//         return minDepth(root->left) + 1;
//     }
//     int left = minDepth(root->left);
//     int right = minDepth(root->right) ;
//     int re = min(left, right) + 1;
//     return re;
// }

int minDepth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }

    queue<TreeNode *> q;
    q.push(root);
    int depth = 0;
    bool flag = false;
    while (!q.empty()){
        int q_size = q.size();
        depth++;
        for (int i = 0; i < q_size; i++){
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left != nullptr){
                q.push(cur->left);
            }
            if (cur->right != nullptr){
                q.push(cur->right);
            }
            if (cur->left == nullptr && cur->right == nullptr){
                return depth;
            }
        }
    }
}
int main(){
    // vector<int> nums = {2, -1, 3, -1, 4, -1, 5, -1, 6};
    // TreeNode *root = make_tree(nums);
    TreeNode *root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(5);
    root->right->right->right->right = new TreeNode(6);
    int depth = minDepth(root);
    cout << depth;
    system("pause");
    return 0;
}
