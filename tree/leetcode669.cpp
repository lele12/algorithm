#include <iostream>

#include "tree.h"

using namespace std;

TreeNode* trimBST(TreeNode* root, int low, int high){
    if (root == nullptr){
        return nullptr;
    }
    if(root->val > high){
        return trimBST(root->left, low, high);
    }
    if (root->val < low){
        return trimBST(root->right, low, high);
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;

}

ing main(){

    return 0;
}