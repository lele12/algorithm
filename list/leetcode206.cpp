#include <iostream>
#include "list_node.h"

using namespace std;

ListNode* reverseList(ListNode* head){
    ListNode *prev = nullptr;
    ListNode *cur = head;
    while (cur != nullptr){
        ListNode *tmp = cur;
        cur = cur->next;
        tmp->next = prev;
        prev = tmp;
    }
    return prev;
}

int main(){
    vector<int> nums = {};
    ListNode *head = make_list(nums);
    ListNode *re = reverseList(head);
    system("pause");
    return 0;
}