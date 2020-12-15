#include <iostream>
#include "tree.h"

using namespace std;

bool check(int a, const vector<int>& nums){
    bool flag = false;
    for(int num:nums){
        if (num == a){
            flag = true;
            break;
        }
    }
    return flag;
}

void process(vector<TreeNode*>& res, TreeNode* &root, vector<int>& to_delete){
    if (root == nullptr){
        return;
    }
    process(res, root->left, to_delete);
    process(res, root->right, to_delete);
    if (check(root->val, to_delete)){
        if (root->left != nullptr){
            res.push_back(root->left);
        }
        if (root->right != nullptr){
            res.push_back(root->right);
        }
        root = nullptr;
    }
    return;
}
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
    vector<TreeNode*> res;
    process(res, root, to_delete);
    if (root != nullptr){
        res.push_back(root);
    }
    return res;
}

int main(){
    vector<int>nums = {1,2,3,4,5,6,7};
    TreeNode* root;
    int i = 0;
    makeTree(root, nums, i);
    vector<int> to_delete = {3, 5};
    vector<TreeNode*> res = delNodes(root, to_delete);
    system("pause");

    return 0;
}