#include <iostream>
#include "list_node.h"

using namespace std;

ListNode *detectCycle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    bool have_cycle = false;
    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
        if (slow == fast){
            have_cycle = true;
            break;
        }
    }

    if (!have_cycle){
        return nullptr;
    }

    slow = head;
    while (fast != slow){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
int main(){
    system("pause");
    return 0;
}