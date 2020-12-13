#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node *right;
    Node *next;
    Node():val(0), left(nullptr), right(nullptr), next(nullptr){}
    Node(int val_): val(val_), left(nullptr), right(nullptr), next(nullptr){}
    Node(int val_, Node* left_, Node*right_, Node*next_):val(val_), left(left_), right(right_), next(next_){}
};

void makeNode(Node* &node,  const vector<int>& nums, int i){
    if (i>=nums.size()){
        return;
    }
    if (nums[i] == -1){
        return;
    }
    node = new Node(nums[i]);
    makeNode(node->left, nums, 2 * i + 1);
    makeNode(node->right, nums, 2 * i + 2);

}

void pre_order(Node* node){
    if (node == nullptr)
        return;
    cout << node->val << "  ";
    pre_order(node->left);
    pre_order(node->right);
    return;
}
void connectTwoNode(Node* node1, Node* node2){
    if (node1 == nullptr || node2 == nullptr){
        return;
    }
    node1->next = node2;
    connectTwoNode(node1->left, node1->right);
    connectTwoNode(node1->right, node2->left);
    connectTwoNode(node2->left, node2->right);
}
Node* connect(Node* node){
    if (node == nullptr){
        return nullptr;
    }
    connectTwoNode(node->left, node->right);
    return nullptr;
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int i = 0;
    Node *node;
    makeNode(node, nums, i);
    pre_order(node);
    system("pause");
    return 0;
}
