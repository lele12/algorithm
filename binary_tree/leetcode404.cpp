#include "binary_tree.h"


// void sum(TreeNode* root, int& re){
//     if (root == nullptr){
//         return;
//     }
//     if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr){
//         re = re + root->left->val;
//     }
//     sum(root->left, re);
//     sum(root->right, re);
//     return;  
// }
// int sumOfLeftLeaves(TreeNode* root){
//     int re = 0;
//     sum(root, re);
//     return re;
// }

int sumOfLeftLeaves(TreeNode* root){
    int re = 0;
    if (root == nullptr){
        return re;
    }
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()){
        TreeNode *cur = s.top();
        s.pop();
        if (cur->left){
            s.push(cur->left);
        }
        if (cur->right){
            s.push(cur->right);
        }
        if (cur->left != nullptr && cur->left->left == nullptr && cur->left->right == nullptr){
            re += cur->left->val;
        }
    }
    return re;
}

int main(){
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    TreeNode *root = make_tree(nums);
    int depth = sumOfLeftLeaves(root);
    cout << depth;
    system("pause");
    return 0;
}