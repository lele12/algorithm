#include <iostream>
#include <vector>

#include "tree.h"

using namespace std;

void get_all_left_leaves(TreeNode* root, vector<int>& res, bool is_left){
    if (root == nullptr){
        return;
    }
    if(root->left == nullptr && root->right == nullptr && is_left){
        res.push_back(root->val);
    }
    get_all_left_leaves(root->left, res, true);
    get_all_left_leaves(root->right, res, false);
    return;
}

int sumOfLeftLeaves(TreeNode* root){
    vector<int> res;
    bool is_left = false;
    get_all_left_leaves(root, res, is_left);
    int sum = 0;
    for (int a: res){
        sum += a;
    }
    return sum;


}

int main(){
    TreeNode* root;
    int i = 0;
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    makeTree(root, nums, i);
    sumOfLeftLeaves(root);
    return 0;
}