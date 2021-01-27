#include "binary_tree.h"

void traversal(TreeNode* root, int targetSum, bool& flag){
    if (flag || root == nullptr){
        return;
    }

    targetSum -= root->val;
    if (targetSum == 0 && root->left == nullptr && root->right == nullptr){
        flag = true;
        return;
    }
    traversal(root->left, targetSum, flag);
    traversal(root->right, targetSum, flag);
    return;
}

bool hasPathSum(TreeNode* root, int targetSum){
    bool flag = false;
    traversal(root, targetSum, flag);
    return flag;
}

int main(){
    vector<int> nums = {1, 2};
    TreeNode *root = make_tree(nums);
    int targetSum = 1;
    bool re = hasPathSum(root, targetSum);
    cout << re;
    system("pause");
    return 0;
}