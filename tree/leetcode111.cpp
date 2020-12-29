#include <iostream>
#include <queue>
#include "tree.h"

using namespace std;

// int minDepth(TreeNode* root){
//     if (root == nullptr){
//         return 0;
//     }
//     if (root->left == nullptr && root->right == nullptr){
//         return 1;
//     }
//     int left = minDepth(root->left);
//     int right = minDepth(root->right);
//     if (left == 0) {
//         return right + 1;
//     }
//     if (right == 0){
//         return left + 1;
//     }
//     return min(left+1, right+1);
// }

int minDepth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    int step = 1;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int q_size = q.size();
        for (int i = 0; i < q_size; i++){
            
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left == nullptr && cur->right== nullptr){
                return step;
            }
            if (cur->left != nullptr){
                q.push(cur->left);
            }
            if (cur->right != nullptr){
                q.push(cur->right);
            }
        }
        step++;
    }
    return step;
}

int main(){
    vector<int> nums = {3,9,20,-1,-1,15,7};
    int i = 0;
    TreeNode *root;
    makeTree(root, nums, i);
    int min = minDepth(root);
    cout << min;
    system("pause");
    return 0;
}