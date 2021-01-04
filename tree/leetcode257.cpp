#include <iostream>
#include <vector>
#include <string>
#include "tree.h"

using namespace std;

vector<string> binaryTreePaths(TreeNode* root){
    vector<string> res;
    if(root == nullptr){
        return res;
    }

    queue<TreeNode *> q;
    queue<string> re;
    q.push(root);
    re.push(to_string(root->val));
    while(!q.empty()){
        int q_size = q.size();
        for (int i = 0; i < q_size; i++){
            TreeNode *cur = q.front();
            q.pop();
            string s = re.front();
            re.pop();
            if(cur->left == nullptr && cur->right == nullptr){
                res.push_back(s);
            }

            if(cur->left != nullptr){
                q.push(cur->left);
                re.push(s + "->" + to_string(cur->left->val));
            }
            if(cur->right != nullptr){
                q.push(cur->right);
                re.push(s + "->" + to_string(cur->right->val));
            }
        }
    }
    return res;
}
int main(){
    TreeNode *root;
    int i = 0;
    vector<int> nums = {1, 2, 3, -1, 5};
    makeTree(root, nums, i);
    vector<string> res = binaryTreePaths(root);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }
        system("pause");
    return 0;
}