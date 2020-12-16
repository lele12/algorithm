#include <iostream>
#include "tree.h"

using namespace std;

void find(TreeNode* root, int& s, int k, int& res){
    if (root == nullptr){
        return ;
    }
    find(root->left, s, k, res);
    s++;
    if(s == k){
        res = root->val;
    }
    find(root->right, s, k, res);
}

int kthSmallest(TreeNode* root, int k){
    int s = 0;
    int res = -1;
    find(root, s, k, res);
    return res;
}

int main(){
    TreeNode *root;
    vector<int> nums = {5,3,6,2,4,-1,-1,1};
    int i = 0;
    makeTree(root, nums, i);
    int s = kthSmallest(root, 3);
    system("pause");
    return 0;
}