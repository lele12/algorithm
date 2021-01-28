#include "binary_tree.h"

TreeNode* deleteNode(TreeNode* root, int key){
    if (root == nullptr){
        return nullptr;
    }

    if (root->val > key){
        root->left = deleteNode(root->left, key);
    } else if (root->val < key){
        root->right = deleteNode(root->right, key);
    }else if (root->val == key){
        if (root->left == nullptr){
            return root->right;
        }else if (root->right == nullptr){
            return root->left;
        }else{
            TreeNode *cur = root->right;
            while (cur->left != nullptr){
                cur = cur->left;
            }
            cur->left = root->left;
            TreeNode *tmp = root;
            root = root->right;
            delete tmp;
            return root;
        }
    }
    return root;
}

int main(){
    vector<int> nums = {5, 3, 6, 2, 4, -1, 7};
    int val = 3;
    TreeNode *root = make_tree(nums);
    TreeNode *node = deleteNode(root, 3);
    system("pause");
    return 0;
}