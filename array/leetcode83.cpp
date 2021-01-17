#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode*next_): val(x), next(next_){}
};

ListNode* deleteDuplicates(ListNode* head){
    if (head == nullptr){
        return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != nullptr){
        if(fast->val == slow->val){
            fast = fast->next;
        }else{
            slow = slow->next;
            slow->val = fast->val;
            fast = fast->next;
        }
    }
    slow->next = nullptr;
    return head;
}

ListNode* makeList(const vector<int>& nums){
    if (nums.size() == 0){
        return nullptr;
    }
    ListNode *head = new ListNode();
    ListNode *tmp = head;
    for (int i = 0; i < nums.size(); i++){
        tmp->next = new ListNode(nums[i]);
        tmp = tmp->next;
    }
    return head->next;
}
int main(){
    vector<int> nums = {1, 1, 2, 3, 3};
    ListNode *head = makeList(nums);
    ListNode *re = deleteDuplicates(head);
    system("pause");
    return 0;
}