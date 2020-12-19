#include <iostream>

#include "tree.h"

using namespace std;

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2){
    if (t1 == nullptr){
        return t2;
    }
    if (t2 == nullptr){
        return t1;
    }
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}
int main(){
    TreeNode* node1, *node2;
    int i = 0, j = 0;
    vector<int> nums1 = {1, 3, 2, 5, -1, -1, -1};
    vector<int> nums2 = {2, 1, 3, -1, 4, -1, 7};
    makeTree(node1, nums1, i);
    makeTree(node2, nums2, j);
    TreeNode* node = mergeTrees(node1, node2);

    return 0;
}