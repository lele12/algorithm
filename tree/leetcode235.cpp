#include <iostream>

#include "tree.h"

using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
     if (root == nullptr){
         return nullptr;
     }

     if(root->val > p->val && root->val > q->val){
         return lowestCommonAncestor(root->left, p, q);
     }
     if (root->val < p->val && root->val < q->val){
         return lowestCommonAncestor(root->right, p, q);
     }
    return root;
}
int main(){
    TreeNode* root;
    int i = 0;
    vector<int> nums = {6,2,8,0,4,7,9,-1,-1,3,5};
    makeTree(root, nums, i);
    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(4);
    TreeNode* res = lowestCommonAncestor(root, p, q);

    return 0;
}