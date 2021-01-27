#include "binary_tree.h"

int get_depth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    return 1 + max(get_depth(root->left), get_depth(root->right));
}
bool isBalanced(TreeNode* root){
    if (root == nullptr){
        return true;
    }
    int left = get_depth(root->left);
    int right = get_depth(root->right);
    bool left_ba = isBalanced(root->left);
    bool right_ba = isBalanced(root->right);

    return abs(left - right) <= 1 && left_ba && right_ba;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    TreeNode *root = make_tree(nums);
    bool depth = isBalanced(root);
    cout << depth;
    system("pause");
    return 0;
}