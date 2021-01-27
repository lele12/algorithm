#include "binary_tree.h"

// void build(vector<int>& s, TreeNode* root, vector<vector<int>>& re){
//     if (root == nullptr){
//         return;
//     }
//     if (root->left == nullptr && root->right == nullptr){
//         s.push_back(root->val);
//         re.push_back(s);
//         s.pop_back();
//         return;
//     }
//     s.push_back(root->val);
//     build(s, root->left, re);
//     s.pop_back();

//     s.push_back(root->val);
//     build(s, root->right, re);
//     s.pop_back();
//     return;
// }
// vector<string> binaryTreePaths(TreeNode* root){
//     vector<int> s;
//     vector<vector<int>> re;
//     build(s, root, re);
//     vector<string> paths;
//     for (int i = 0; i < re.size(); i++){
//         string path;
//         for (int j = 0; j < re[i].size(); j++){
//             path += to_string(re[i][j]);
//             if (j != re[i].size() - 1){
//                 path += "->";
//             }
//         }
//         paths.push_back(path);
//     }
//     return paths;
// }

vector<string> binaryTreePaths(TreeNode* root){
    vector<string> paths;
    if (root == nullptr){
        return paths;
    }
    stack<string> res;
    stack<TreeNode*> s;
    s.push(root);
    res.push("");

    while(!s.empty()){
        TreeNode *cur = s.top();
        s.pop();
        string re = res.top();
        res.pop();
        if (re != ""){
            re += "->";
        }
        
        re += to_string(cur->val);
        if (cur->left){
            s.push(cur->left);
            res.push(re);
        }
        if (cur->right){
            s.push(cur->right);
            res.push(re);
        }
        if (cur->left == nullptr && cur->right == nullptr){
            paths.push_back(re);
        }

    }
    return paths;
}
int main(){
    vector<int> nums = {1, 2, 3, -1, 5};
    TreeNode *root = make_tree(nums);
    vector<string> re = binaryTreePaths(root);
    for (string s:re){
        cout << s << ' ';
    }
    system("pause");
    return 0;
}