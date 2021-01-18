#include <iostream>
#include "list_node.h"

using namespace std;

ListNode* removeElements(ListNode* head, int val){
    ListNode *new_head = new ListNode(0);
    new_head->next = head;
    ListNode *slow = new_head;
    ListNode *fast = head;
    while (fast != nullptr){
        if (fast->val == val){
            fast = fast->next;
        }else{
            slow = slow->next;
            slow->val = fast->val;
            fast = fast->next;
        }
    }
    slow->next = nullptr;
    return new_head->next;
}

int main(){
    vector<int> nums = {1, 2, 6, 3, 4, 5, 6};
    int val = 6;
    ListNode *head = make_list(nums);
    head = removeElements(head, val);

    system("pause");
    return 0;
}