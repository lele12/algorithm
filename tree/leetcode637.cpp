#include <iostream>
#include <queue>

#include "tree.h"

using namespace std;
vector<double> averageOfLevels(TreeNode* root){
    vector<double> res;
    if(root == nullptr)
        return;
    queue<TreeNode*> q;
    q.push(root);
    while(! q.empty()){
        int q_size = q.size();
        double sum = 0;
        for (int i = 0; i < q_size; i++){
            TreeNode *node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            sum += node->val;
        }
        res.push_back(sum / q_size);
    }
    return res;
}

int main(){
    system("pause");
    return 0;
}