#include "binary_tree.h"

TreeNode* mergeTrees(TreeNode* t1,  TreeNode* t2){
    if (t1 != nullptr && t2 != nullptr){
        t1->val += t2->val;
    }else if (t1 == nullptr && t2 != nullptr){
        t1 = new TreeNode(t2->val);
    }else {
        return t1;
    }
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}