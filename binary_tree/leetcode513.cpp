#include "binary_tree.h"

int findBottomLeftValuse(TreeNode* root){
    queue<TreeNode *> q;
    q.push(root);
    int val = 0;
    while (!q.empty()){
        int q_size = q.size();
        for (int i = 0; i < q_size; i++){
            TreeNode *cur = q.front();
            q.pop();
            if (i == 0 && cur->left == nullptr && cur->right == nullptr){
                val = cur->val;
            }
            if (cur->left){
                q.push(cur->left);
            }
            if (cur->right){
                q.push(cur->right);
            }
        }
    }
    return val;
}
int main(){
    vector<int> nums = {1, 2, 3, -1, 5};
    TreeNode *root = make_tree(nums);
    int re = findBottomLeftValuse(root);
    cout << re;
    system("pause");
    return 0;
}