#include <iostream>
#include "binary_tree.h"

using namespace std;

int main(){
    vector<int> nums = {1, -1, 2, -1, -1, 3, -1};
    TreeNode *root = make_tree(nums);
    post_traversal(root);
    // cout << endl;
    // mid_order(root);
    // cout << endl;
    post_order(root);
    // cout << endl;
    // layer_order(root);
    // cout << endl;
    system("pause");
    return 0;
}