#include <iostream>
#include <vector>

#include "tree.h"

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0), next(nullptr) {}
    ListNode(int val_):val(val_), next(nullptr) {}
    ListNode(int val_, ListNode* next_):val(val_), next(next_) {}
};

ListNode* makeList(vector<int>& nums){
    if(nums.size() == 0){
        return nullptr;
    }

    ListNode *head = new ListNode(nums[0]);
    ListNode *p = head;
    for (int i = 1; i < nums.size(); i++){
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head;
}

ListNode* get_mid(ListNode* left, ListNode* right){
    ListNode *fast = left;
    ListNode *low = left;
    while(fast != right && fast->next != right){
        fast = fast->next;
        fast = fast->next;
        low = low->next;
    }
    return low;
}
TreeNode* build(ListNode* left, ListNode* right){
    if (left == right){
        return nullptr;
    }
    ListNode *mid = get_mid(left, right);
    TreeNode *node = new TreeNode(mid->val);
    node->left = build(left, mid);
    node->right = build(mid->next, right);
    return node;
}
TreeNode* sortedListToBST(ListNode* head){
    return build(head, nullptr);
}

int main(){
    vector<int> nums = {-10, -3, 0, 5, 9};
    ListNode *head = makeList(nums);


}