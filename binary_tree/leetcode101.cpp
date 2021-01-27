#include "binary_tree.h"

bool symmetric(TreeNode* left, TreeNode* right){

    if (left == nullptr && right == nullptr){
        return true;
    }else if (left == nullptr && right != nullptr){
        return false;
    }else if (left != nullptr && right == nullptr){
        return false;
    }
    bool left_node = symmetric(left->left, right->right);
    bool right_node = symmetric(left->right, right->left);
    return (left->val == right->val) && (left_node && right_node);
}
bool isSymmetric(TreeNode* root){
    if (root == nullptr){
        return true;
    }
    return symmetric(root->left, root->right);
}

int main(){
    vector<int> nums = {1, 2, 2, 3, 3, 3, 3};
    TreeNode *root = make_tree(nums);
    bool re = isSymmetric(root);
    cout << re;
    system("pause");
    return 0;
}