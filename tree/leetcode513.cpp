#include <iostream>
#include <queue>
#include "tree.h"

using namespace std;

int findBottomLeftValue(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    int val = 0;
    while(!q.empty()){
        int q_size = q.size();
        for(int i = 0; i < q_size; i++){
            TreeNode* s = q.front();
            if (i == 0 && s->left== nullptr && s->right== nullptr){
                val = s->val;
            }
            q.pop();
            if(s->left){
                q.push(s->left);
            }
            if(s->right){
                q.push(s->right);
            }
        }
    }
    return val;
}
int main(){
    TreeNode* root;
    int i = 0;
    vector<int> nums = {2, 1, 3};
    makeTree(root, nums, i);
    int res = findBottomLeftValue(root);
    cout << res;
    return 0;

}