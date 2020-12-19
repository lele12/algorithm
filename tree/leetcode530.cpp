#include <iostream>
#include "tree.h"

using namespace std;

void find(TreeNode* root, vector<int>& res){
    if(root == nullptr){
        return;
    }
    find(root->left, res);
    res.push_back(root->val);
    find(root->right, res);
    return;
}

int getMinimumDifference(TreeNode* root){
    vector<int> res;
    find(root, res);
    int r = INT_MAX;
    for (int i = 1; i < res.size(); i++){
        int k = res[i] - res[i-1];
        if(k < r){
            r = k;
        }
    }
    return r;


}
int main(){
    return 0;
}