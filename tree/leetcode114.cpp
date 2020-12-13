#include <iostream>
#include "tree.h"

using namespace std;

// void flat(TreeNode* root){
//     if (root == nullptr){
//         return;
//     }

//     flat(root->left);
//     flat(root->right);
//     TreeNode *tmp = root;
//     while(tmp->left != nullptr){
//         tmp = tmp->left;
//     }
//     tmp->left = root->right;
//     root->right = nullptr;
//     return;
// }

// void flatten(TreeNode* root){
//     flat(root);
//     TreeNode* tmp = root;
//     while(tmp != nullptr){
//         tmp->right = tmp->left;
//         tmp->left = nullptr;
//         tmp = tmp->right;
//     }
//     return;
// }
void flatten(TreeNode* root){
    if (root == nullptr){
        return;
    }

    flatten(root->left);
    flatten(root->right);
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    root->left = nullptr;
    root->right = left;

    TreeNode *tmp = root;
    while(tmp->right != nullptr){
        tmp = tmp->right;
    }
    tmp->right = right;
    return;
}
int main(){
    TreeNode *root;
    int i = 0;
    vector<int> nums = {1, 2, 5, 3, 4, -1, 6};
    makeTree(root, nums, i);
    flatten(root);

    system("pause");
    return 0;
}