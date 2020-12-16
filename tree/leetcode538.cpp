#include <iostream>
#include "tree.h"

using namespace std;

void computeSum(TreeNode* root, int& sum){
    if (root == nullptr){
        return;
    }
    computeSum(root->right, sum);
    root->val += sum;
    sum = root->val;
    computeSum(root->left, sum);
}

TreeNode* convertBST(TreeNode* root){

    int sum = 0;
    computeSum(root, sum);
    return root;
}

int main(){
    int i = 0;
    TreeNode *root;
    vector<int> nums = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    makeTree(root, nums, i);
    root = convertBST(root);
    mid_order(root);
    system("pause");
    return 0;
}