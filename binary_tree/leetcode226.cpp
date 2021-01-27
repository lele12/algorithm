#include "binary_tree.h"
#include <algorithm>
using namespace std;

TreeNode* invertTree(TreeNode* root){
    if (root == nullptr){
        return nullptr;
    }

    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
int main(){
    vector<int> nums = {4, 2, 7, 1, 3, 6, 9};
    TreeNode *root = make_tree(nums);
    invertTree(root);
    system("pause");
    return 0;
}