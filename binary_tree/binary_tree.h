#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* l, TreeNode* r):val(x), left(l), right(r){}
};

TreeNode* build_tree(const vector<int>& nums, int i){
    if (i >= nums.size() || nums[i] == -1){
        return nullptr;
    }
    TreeNode *node = new TreeNode(nums[i]);
    node->left = build_tree(nums, 2 * i + 1);
    node->right = build_tree(nums, 2 * i + 2);
    return node;
}

TreeNode* make_tree(const vector<int>& nums){
    int i = 0;
    return build_tree(nums, i);
}

void pre_order(TreeNode* root){
    if (root == nullptr){
        return;
    }
    cout << root->val << ' ';
    pre_order(root->left);
    pre_order(root->right);
    return;
}

void mid_order(TreeNode* root){
    if (root == nullptr){
        return;
    }
    mid_order(root->left);
    cout << root->val << ' ';
    mid_order(root->right);
    return;
}

void post_order(TreeNode* root){
    if (root == nullptr){
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout << root->val << ' ';
    return;
}

void layer_order(TreeNode* root){
    if (root == nullptr){
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()){
        int q_size = q.size();
        for (int i = 0; i < q_size; i++){
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << ' ';
            if (node->left != nullptr){
                q.push(node->left);
            }
            if (node->right != nullptr){
                q.push(node->right);
            }
        }
    }
    return;
}

void pre_traversal(TreeNode* root){
    if (root == nullptr){
        return;
    }
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()){
        TreeNode *node = s.top();
        s.pop();
        cout << node->val << ' ';
        if (node->left != nullptr){
            s.push(node->left);
        }
        if (node->right != nullptr){
            s.push(node->right);
        }
    }
    return;
}

void mid_traversal(TreeNode* root){
    if (root == nullptr){
        return;
    }
    stack<TreeNode *> s;
    unordered_map<TreeNode *, int> flag;
    s.push(root);
    while (!s.empty()){
        TreeNode *node = s.top();
        if (node->left != nullptr && !flag.count(node->left)){
            s.push(node->left);
        }else if (node->right != nullptr){
            cout << node->val << ' ';
            flag[node]++;
            s.pop();
            s.push(node->right);
        }else{
            flag[node]++;
            cout << node->val << ' ';
            s.pop();
        }
    }
    return;
}

void post_traversal(TreeNode* root){
    if (root == nullptr){
        return;
    }
    stack<TreeNode *> s;
    unordered_map<TreeNode *, int> flag;
    s.push(root);
    while (!s.empty()){
        TreeNode *node = s.top();
        if (!flag.count(node)){
            if (node->right != nullptr){
                s.push(node->right);
            }
            if (node->left != nullptr){
                s.push(node->left);
            }
            if ((node->left == nullptr || flag.count(node->left) ) && (node->right == nullptr || flag.count(node->right))){
                cout << node->val << ' ';
                flag[node]++;
                s.pop();
            }
        }else {
            s.pop();
        }
    }
    return;
}

void inorder_traversal(TreeNode* root){
    if (root == nullptr){
        return;
    }

    stack<TreeNode *> s;
    TreeNode *cur = root;
    while (cur || !s.empty()){
        if (cur){
            s.push(cur);
            cur = cur->left;
        }else {
            cur = s.top();
            s.pop();
            cout << cur->val << ' ';
            cur = cur->right;
        }
    }
    return;
}