#include <iostream>
#include "tree.h"

using namespace std;


int cout_path(TreeNode* root, int sum){
    if (root == nullptr)
    {
        return 0;
    }
    sum -= root->val;
    int re = 0;
    if (sum == 0){re = 1;}
    int left = cout_path(root->left, sum);
    int right = cout_path(root->right, sum);
    return re+left+right;

}
int pathSum(TreeNode* root, int sum){
    if (root == nullptr){
        return 0;
    }
    int result = cout_path(root, sum);
    int left = pathSum(root->left, sum);
    int right = pathSum(root->right, sum);
    return result+left+right;
}
int main(){
    vector<int>nums = {10,5,-3,3,2,-1,11,3,-2,-1,1};
    TreeNode* root;
    int i = 0;
    makeTree(root, nums, i);
    cout << pathSum(root, 8);
    return 0;
}