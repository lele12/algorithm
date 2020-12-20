#include <iostream>
#include <stack>
#include <map>
#include <unordered_map>
#include "tree.h"

using namespace std;

// vector<int> inorderTraversal(TreeNode* root){
//     vector<int> res;
//     if(root == nullptr){
//         return res;
//     }
//     stack<TreeNode *> s;
//     TreeNode * node = root;
//     while(node || !s.empty()){   
//         while(node){
//             s.push(node);
//             node = node->left;
//         }
//         node = s.top();
//         s.pop();
//         res.push_back(node->val);
//         // cout << node->val << " ";
//         node = node->right;  
//     }
//     return res;
// }

vector<int> inorderTraversal(TreeNode* root){
    vector<int> res;
    if(root == nullptr){
        return res;
    }
    unordered_map<TreeNode *, int> flag;
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()){
        TreeNode *node = s.top();
        while(node->left){
            if (flag[node->left] == 1){
                break;
            }
            s.push(node->left);
            node = node->left;
        }
        res.push_back(node->val);
        cout << node->val << " ";
        s.pop();
        flag[node] = 1;
        if (node->right){
            s.push(node->right);
            node = node->right;
        }
    }
    return res;
}

vector<int> preorderTraversal(TreeNode* root){
    vector<int> res;
    if (root == nullptr){
        return res;
    }
    stack<TreeNode*> s;
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
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    // vector<int> nums = {2, 3, -1, 1};
    TreeNode *root;
    int i = 0;
    makeTree(root, nums, i);
    mid_order(root);
    inorderTraversal(root);

    // mid_order(root);

    system("pause");
    return 0;
}