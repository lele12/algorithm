#include <iostream>

#include "tree.h"

using namespace std;

void mid_order(vector<TreeNode*>& re, TreeNode* root){
    if (root == nullptr){
        return;
    }

    mid_order(re, root->left);
    re.push_back(root);
    mid_order(re, root->right);
    return;
}

void recoverTree(TreeNode* root){
    vector<TreeNode *> re;
    mid_order(re, root);
    TreeNode* x = nullptr;
    TreeNode* y = nullptr;

    for(int i=0;i<re.size()-1;++i) {
        if(re[i]->val>re[i+1]->val) {
            y = re[i+1];
            if(x==nullptr) {
                x = re[i];
            }
        }
    }
    if(x!=nullptr && y!=nullptr) {
        swap(x->val, y->val);
    }
    return;
}

int main(){
    TreeNode *root;
    int i = 0;
    vector<int> nums = {3, 1, 4, -1, -1, 2};
    makeTree(root, nums, i);
    recoverTree(root);
    system("pause");
    return 0;
}