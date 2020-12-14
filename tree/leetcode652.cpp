#include <iostream>
#include "tree.h"
#include <map>
#include <set>

using namespace std;

bool equal(TreeNode* a, TreeNode* b){
    if ((a == nullptr and b != nullptr) or (a != nullptr and b == nullptr)){
        return 0;
    }
    if (a == nullptr and b == nullptr){
        return true;
    }
    return (a->val == b->val) && equal(a->left, b->left) && equal(a->right, b->right);
}

void repeat(int &num, TreeNode* root, TreeNode* p){
    if (root == nullptr ){
        return;
    }
    int s = equal(root, p);
    num += s;
    repeat(num, root->left, p);
    repeat(num, root->right, p);
    return;
}
bool is_repeat(TreeNode* root, TreeNode* p){
    int num = 0;
    repeat(num, root, p);
    if (num >=2){
        return true;
    }
    return false;
}

bool is_in_res(vector<TreeNode*> res, TreeNode* p){
    bool flag = false;
    for (int i = 0; i < res.size(); i++){
        if (equal(res[i], p)){
            flag = true;
            break;
        }
    }
    return flag;
}

void find(vector<TreeNode*>& res, TreeNode* root, TreeNode* p){
    if (root == nullptr or p == nullptr){
        return;
    }

    if (is_repeat(root, p) and !is_in_res(res, p)){
        res.push_back(p);
    }
    find(res, root, p->left);
    find(res, root, p->right);
}
// vector<TreeNode*> findDuplicateSubtrees(TreeNode* root){
//     vector<TreeNode *> res;
//     find(res, root, root);
    
//     return res;
// }

string traverse(map<string, int>& res, set<TreeNode*>& re,  TreeNode* root){
    if (root == nullptr){
        return "#";
    }
    string left = traverse(res, re, root->left);
    string right = traverse(res, re, root->right);
    string tree = left + "," + right + "," + to_string(root->val);
    res[tree] += 1;
    if (res[tree] == 2){
        re.insert(root);
    }

    return tree;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root){
    map<string, int> res;
    set<TreeNode*> re;
    traverse(res, re, root);
    vector<TreeNode *> result;
    for (auto a:re){
        result.push_back(a);
    }

    return result;
}

int main(){
    TreeNode *root;
    int i = 0;
    vector<int> nums = {1, 2, 3, 4, -1, 2, 4, -1, -1, -1, -1, 4, -1, -1, -1};
    makeTree(root, nums, i);
    vector<TreeNode *> res = findDuplicateSubtrees(root);
    system("pause");
    return 0;
}