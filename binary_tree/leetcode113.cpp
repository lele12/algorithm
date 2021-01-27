#include "binary_tree.h"

void traversal(TreeNode* root, vector<int>& path, int targetSum, vector<vector<int>>&res){

    if (root == nullptr){
        return;
    }

    path.push_back(root->val);
    targetSum -= root->val;
    if (targetSum == 0 && root->left == nullptr && root->right == nullptr){
        res.push_back(path);
    }
    traversal(root->left, path, targetSum, res);
    traversal(root->right, path, targetSum, res);
    targetSum += root->val;
    path.pop_back();
    return;
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum){
    vector<int> path;
    vector<vector<int>> res;
    traversal(root, path, targetSum, res);
    return res;
}

int main(){
    vector<int> nums = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, -1, 5, 1};
    TreeNode *root = make_tree(nums);
    int targetSum = 22;
    vector<vector<int>> re = pathSum(root, targetSum);
    for (int i = 0; i < re.size(); i++){
        for (int j = 0; j < re[i].size(); j++){
            cout << re[i][j] << ' ';
        }
        cout << endl;
    }
    system("pause");
    return 0;
}