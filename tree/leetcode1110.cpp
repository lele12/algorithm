#include <iostream>
#include "tree.h"

using namespace std;

bool check(int a, const vector<int>& nums){
    bool flag = false;
    for(int num:nums){
        if (num == a){
            flag = True;
        }
    }
    return flag;
}

void process(vector<TreeNode*>& res, TreeNode* root, vector<int>& to_delete){
    if (root == nullptr){
        return;
    }


}
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete){
    vector<TreeNode*> res;
    if (root == nullptr){
        return res;
    }
    if (!check(root->val, to_delete)){
        res.push_back(root);
    }

}

int main(){
    vector<int>nums = {};
    TreeNode* root;
    int i = 0;
    makeTree(root, nums, i);

    return 0;
}