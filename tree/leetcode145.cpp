#include <iostream>
#include <stack>
#include <algorithm>
#include "tree.h"

using namespace std;

vector <int> postorderTraversal(TreeNode* root){
    vector<int> res;
    if(root == nullptr){
        return res;
    }
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()){
        TreeNode *node = s.top();
        s.pop();
        res.push_back(node->val);
        if (node->left){
            s.push(node->left);
        }
        if(node->right){
            s.push(node->right);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    // vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    vector<int> nums = {2, 3, -1, 1};
    TreeNode *root;
    int i = 0;
    makeTree(root, nums, i);
    preorderTraversal(root);
    // pre_order(root);
    // mid_order(root);

    system("pause");
    return 0;
}