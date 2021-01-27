#include "binary_tree.h"
bool find_node(TreeNode* root, TreeNode* p, TreeNode*q, TreeNode* &res){
    if (root == nullptr){
        return false;
    }

    bool left = find_node(root->left, p, q, res);
    bool right = find_node(root->right, p, q, res);
    if ((left && right) || ((left || right) && (root->val == p->val || root->val == q->val))){
        if (res == nullptr){
            res = root;
        }
        
    }

    return left || right || p->val==root->val || q->val == root->val;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    TreeNode *res = nullptr;
    find_node(root, p, q, res);
    return res;
}

int main(){
    vector<int> nums = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode *root = make_tree(nums);
    TreeNode* res = lowestCommonAncestor(root, new TreeNode(5), new TreeNode(1));
    system("pause");
    return 0;
}