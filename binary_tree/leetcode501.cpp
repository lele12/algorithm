#include "binary_tree.h"

TreeNode *pre = nullptr;
int count = -1;
int max_count = 0;
void traversal(TreeNode* root, vector<int>& re){
    if (root == nullptr){
        return;
    }

    traversal(root->left, re);
    if (pre == nullptr){
        pre = root;
        count = 1;
    }else if (root->val == pre->val){
        count++;
    }else {
        pre = root;
        count = 1;
    }
    if (count > max_count){
        re.clear();
        re.push_back(root->val);
        max_count = count;
    }else if (count == max_count){
        re.push_back(root->val);
    }
    traversal(root->right, re);
    return;
}
vector<int> findMode(TreeNode* root){
    vector<int> re;
    traversal(root, re);
    return re;
}

int main(){
    vector<int> nums = {1, -1, 2};
    TreeNode* root = make_tree(nums);
    vector<int> re = findMode(root);
    for (int r:re){
        cout << r << " ";
    }
    system("pause");
    return 0;
}