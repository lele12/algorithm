#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left_, TreeNode* right_):val(x), left(left_), right(right_){}
};

int maxDepth(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


int main(){
    return 0;
}
