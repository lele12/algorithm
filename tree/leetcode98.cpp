#include <iostream>
#include "tree.h"

using namespace std;

bool is_valid(TreeNode* root, TreeNode* min, TreeNode* max){
    if (root == nullptr){
        return true;
    }

    bool left = is_valid(root->left, min, max);
    bool right = is_valid(root->right, min, max);
    if (root != nullptr && )
    if (min < root->val && root->val < max){
        return true;
    }
    else{
        return false;
    }
    return  left && right; 

}
bool isValidBST(TreeNode* root){
    
}
int main(){
    int i = 0;
    vector<int> nums = {};
    TreeNode* root;
    makeTree(root, nums, i);

    return 0;
}