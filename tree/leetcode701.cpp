#include <iostream>
#include "tree.h"

using namespace std;
void insert(TreeNode* &root, int val){
    if (root == nullptr){
        root = new TreeNode(val);
        return;
    }
    if (val < root->val){
        insert(root->left, val);
    }
    else{
        insert(root->right, val);
    }

}
TreeNode* insertIntoBST(TreeNode* root, int val){
    insert(root, val);
    return root;
}

int main(){
    TreeNode *root;
    int i = 0;
    vector<int> nums = {4,2,7,1,3, -1, -1};
    makeTree(root, nums, i);
    insertIntoBST(root, 5);
    // root = searchBST(root, 2);
    system("pause");
    return 0;
}
