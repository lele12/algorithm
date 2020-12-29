#include <iostream>
#include "tree.h"

using namespace std;

void traverse(TreeNode* root, int& min, int step){
    if (root == nullptr){
        if (step < min){
            min = step;
        }
        return;
    }
    traverse(root->left, min, step + 1);
    traverse(root->right, min, step + 1);
    return;
}

int minDepth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr){
        return 1;
    }
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if (left == 0) {
        return right + 1;
    }
    if (right == 0){
        return left + 1;
    }
    return min(left+1, right+1);
}

int main(){
    vector<int> nums = {3,9,20,-1,-1,15,7};
    int i = 0;
    TreeNode *root;
    makeTree(root, nums, i);
    int min = minDepth(root);
    cout << min;
    system("pause");
    return 0;
}