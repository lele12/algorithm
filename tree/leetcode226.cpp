#include<iostream>
#include"tree.h"

using namespace std;

void invertTree(TreeNode* root){
    if (root == nullptr){
        return;
    }
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
}

int main(){
    system("pause");
    return 0;
}