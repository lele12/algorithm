#include <iostream>
#include <stack>
#include "tree.h"

using namespace std;

vector<int> preorderTraversal(TreeNode* root){
    vector<int> res;
    if (root == nullptr)
        return res;
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()){
        TreeNode *node = s.top();
        s.pop();
        res.push_back(node->val);
        if (node->right){
            s.push(node->right);
        }
        if (node->left){
            s.push(node->left);
        }
    }
    return res;
}
int main(){
    TreeNode *root;
    int i = 0;
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    makeTree(root, nums, i);
    pre_order(root);
    vector<int> res = preorderTraversal(root);
    system("pause");
    return 0;
}