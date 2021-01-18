#include <iostream>
#include "list_node.h"
using namespace std;

class MyLinkedList{
public:
    MyLinkedList(){
        head_ = new ListNode(0);
        size_ = 0;
    }

    int get(int index){
        if (index < 0 || index >= size_){
            return -1;
        }

        ListNode *cur = head_->next;
        while (index--){
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val){
        ListNode *tmp = new ListNode(val);
        tmp->next = head_->next;
        head_->next = tmp;
        size_++;
        return;
    }

    void addAtTail(int val){
        ListNode *tmp = new ListNode(val);
        ListNode *cur = head_;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = tmp;
        size_++;
        return;
    }

    void addAtIndex(int index, int val){
        if (index > size_){
            return;
        }
        ListNode *new_node = new ListNode(val);
        ListNode *cur = head_;
        while (index--){
            cur = cur->next;
        }
        new_node->next = cur->next;
        cur->next = new_node;
        size_++;
        return;
    }

    void deleteAtIndex(int index){
        if (index < 0 || index >= size_){
            return;
        }
        ListNode *cur = head_;
        while (index--){
            cur = cur->next;
        }
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        size_--;
        return;
    }

private:
    ListNode *head_;
    int size_;
}