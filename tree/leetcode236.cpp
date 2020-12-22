#include <iostream>

#include "tree.h"

using namespace std;

bool find(TreeNode* root, TreeNode*p, TreeNode* q, TreeNode* & res){

    if(root == nullptr){
        return false;
    }

    bool left = find(root->left, p, q, res);
    bool right = find(root->right, p, q, res);
    if ((left && right) || ((root->val == p->val || root->val == q->val) && (left || right))){
        if (res == nullptr){
            res = root;
        }
    }
    return left || right || (root->val == p->val || root->val == q->val);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode*p, TreeNode* q){
    TreeNode *res = nullptr;
    find(root, p, q, res);
    return res;
}
int main(){
    vector<int> nums = {3,5,1,6,2,0,8,-1,-1,7,4};
    int i = 0;
    TreeNode *root;
    makeTree(root, nums, i);
    TreeNode *p = new TreeNode(7);
    TreeNode *q = new TreeNode(4);
    TreeNode* res = lowestCommonAncestor(root, p, q);
    system("pause");
    return 0;
}