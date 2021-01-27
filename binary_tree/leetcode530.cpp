#include "binary_tree.h"

int value = INT_MAX;
int s = -1;
int getMinimumDifference(TreeNode* root){
    if (root == nullptr){
        return value;
    }

    getMinimumDifference(root->left);
    if (s != -1){
        int a = root->val - s;
        if (a < value){
            value = a;
        }
    }
    s = root->val;
    getMinimumDifference(root->right);
    return value;
}

int main(){
    vector<int> nums = {2, 1, 3};
    TreeNode* root = make_tree(nums);
    int re = getMinimumDifference(root);
    cout << re;
    system("pause");
    return 0;
}