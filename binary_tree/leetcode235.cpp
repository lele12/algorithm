#include "binary_tree.h"

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode*p, TreeNode* q){
    if (root == nullptr){
        return nullptr;
    }
    if (p->val < root->val && q->val < root->val){
        return lowestCommonAncestor(root->left, p, q);
    }else if (p->val > root->val && q->val > root->val){
        return lowestCommonAncestor(root->right, p, q);
    }else {
        return root;
    }
    return nullptr;
}
int main(){
    vector<int> nums = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode *root = make_tree(nums);
    TreeNode* res = lowestCommonAncestor(root, new TreeNode(5), new TreeNode(1));
    system("pause");
    return 0;
}