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
TreeNode* sortedListToBST(ListNode* head){

}

int main(){
    vector<int> nums = {-10, -3, 0, 5, 9};
    ListNode *head = makeList(nums);


}