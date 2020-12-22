#include <iostream>
#include <set>
#include "tree.h"

using namespace std;
void find(TreeNode* root, int k, set<int>&s, bool & is_find){
    if (is_find){
        return;
    }
    if(root == nullptr){
        return;
    }

    find(root->left, k, s, is_find);
    if(s.end() != s.find(root->val)){
        is_find = true;
    }
    else{
        s.insert(k - root->val);
    }
    find(root->right, k, s, is_find);
}
bool findTarget(TreeNode* root, int k){
    set<int> s;
    bool is_find = false;
    find(root, k, s, is_find);
    return is_find;
}

int main(){
    TreeNode *root;
    int i = 0;
    vector<int> nums = {5, 3, 6, 2, 4, -1, 7};
    makeTree(root, nums, i);
    cout << findTarget(root, 9);
    system("pause");
    return 0;
}