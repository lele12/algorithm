#include <iostream>
#include <string>
#include <regex>
#include "tree.h"

using namespace std;

string serialize(TreeNode* root){
    if (root == nullptr){
        return "#";
    }
    string val = to_string(root->val);
    string left = serialize(root->left);
    string right = serialize(root->right);
    return val + "," + left + "," + right;
}

void deser(TreeNode* &root, vector<string>& data){
    if (data.size() <= 0){
        root == nullptr;
        return;
    }
    if (data[data.size()-1] == "#"){
        root = nullptr;
        data.pop_back();
        return;
    }
    root = new TreeNode(stoi(data[data.size()-1]));
    data.pop_back();
    deser(root->left, data);
    deser(root->right, data);
    return;
}
TreeNode* deserialize(string data){
    TreeNode *root;
    regex ws_re(",");
    vector<string> nums(sregex_token_iterator(data.begin(), data.end(), ws_re, -1), sregex_token_iterator());
    reverse(nums.begin(), nums.end());
    deser(root, nums);
    return root;
}

int main(){
    TreeNode *root;
    int i = 0;
    vector<int> nums = {1, 2, 3, -1, -1, 4, 5};
    makeTree(root, nums, i);
    pre_order(root);
    string data = serialize(root);
    cout << endl
         << data << endl;
    ;
    TreeNode* node = deserialize(data);
    pre_order(node);
    system("pause");
    return 0;
}