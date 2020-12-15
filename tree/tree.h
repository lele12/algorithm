#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left_, TreeNode* right_):val(x), left(left_), right(right_){}
};


void makeTree(TreeNode* &root, vector<int>& nums, int i){
    if (i >= nums.size() or nums[i] == -1){
        root = nullptr;
        return;
    }
    root = new TreeNode(nums[i]);
    makeTree(root->left, nums, 2*i+1);
    makeTree(root->right, nums, 2*i+2);
    return;
}

void pre_order(TreeNode* root){
    if (root == nullptr)
        return;
    cout << root->val << "  ";
    pre_order(root->left);
    pre_order(root->right);
}

void mid_order(TreeNode* root){
    if (root == nullptr)
        return;
    mid_order(root->left);
    cout << root->val << "  ";
    mid_order(root->right);
}

void post_order(TreeNode* root){
    if (root == nullptr)
        return;
    post_order(root->left);
    post_order(root->right);
    cout << root->val << "  ";

}

void add(queue<TreeNode*>& que, TreeNode* root){
    if (root != nullptr)
        que.push(root);
    return;
}

void layer_order(TreeNode* root){
    if (root == nullptr)
        return;
    queue<TreeNode *> que;
    que.push(root);
    while(!que.empty()){
        TreeNode *leaf = que.front();
        cout << leaf->val << "  ";
        add(que, leaf->left);
        add(que, leaf->right);
        que.pop();
    }
    return;
}

int maxDepth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
