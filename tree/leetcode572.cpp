#include <iostream>
#include <string>
#include <vector>

#include "tree.h"

using namespace std;

string traverse(TreeNode* s, vector<string> &res){
    if(s == nullptr){
        return "#";
    }
    string left = traverse(s->left, res);
    string right = traverse(s->right, res);
    string tree = left + "," + right + "," + to_string(s->val);
    res.push_back(tree);
    return tree;
}

string postorder(TreeNode* t){
    if(t == nullptr){
        return "#";
    }
    string left = postorder(t->left);
    string right = postorder(t->right);
    string tree = left + "," + right + "," + to_string(t->val);
    return tree;
}

bool isSubtree(TreeNode* s, TreeNode* t){
    vector<string> res;
    traverse(s, res);
    string t_ser = postorder(t);
    bool flag = false;
    for (string a: res){
        if (a == t_ser){
            flag = true;
            break;
        }
    }
    return flag;

}
int main(){

    TreeNode* s, *t;
    int i = 0, j = 0;
    vector<int> nums1 = {4, 1, -1, -1, 2};
    vector<int> nums2 = {1, -1, 4, -1, -1, 2};
    makeTree(s, nums1, i);
    makeTree(t, nums2, j);
    cout << isSubtree(s, t);

    return 0;

}