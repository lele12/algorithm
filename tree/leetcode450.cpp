#include <iostream>
#include "tree.h"

using namespace std;

void del(TreeNode* &root, int key){
    if (root == nullptr){
        return;
    }
    if (key == root->val){
        if (root->right == nullptr){
            root = root->left;
            return;
        }
        if (root->left == nullptr){
            root = root->right;
            return;
        }
        TreeNode *p = root->right;
        while(p->left != nullptr){
            p = p->left;
        }
        root->val = p->val;
        del(root->right, p->val);
    }
    if (key < root->val){
        del(root->left, key);
    }
    else
    {
        del(root->right, key);
    }
    
}
TreeNode* deleteNode(TreeNode* root, int key){
    del(root, key);
    return root;
}

int main(){
    TreeNode *root;
    int i = 0;
    vector<int> nums = {5,3,6,2,4,-1,7};
    makeTree(root, nums, i);
    root = deleteNode(root, 3);

    return 0;
}