#include "binary_tree.h"
#include <queue>

// int countNodes(TreeNode* root){
//     if (root == nullptr){
//         return 0;
//     }
//     int count = 0;
//     queue<TreeNode *> q;
//     q.push(root);
//     while (!q.empty()){
//         int q_size = q.size();
//         count += q_size;
//         for (int i = 0; i < q_size; i++){
//             TreeNode *cur = q.front();
//             q.pop();
//             if (cur->left != nullptr){
//                 q.push(cur->left);
//             }
//             if (cur->right != nullptr){
//                 q.push(cur->right);
//             }
//         }
//     }
//     return count;
// }

int countNodes(TreeNode* root){
    if (root == nullptr){
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    TreeNode *root = make_tree(nums);
    int depth = countNodes(root);
    cout << depth;
    system("pause");
    return 0;
}