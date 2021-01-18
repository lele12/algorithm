#include <vector>

using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode ():val(0), next(nullptr) {}
    ListNode (int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next_): val(x), next(next_) {}
};

ListNode* make_list(const vector<int>& nums){
    ListNode *head = new ListNode();
    ListNode *tmp = head;
    for (int i = 0; i < nums.size(); i++){
        tmp->next = new ListNode(nums[i]);
        tmp = tmp->next;
    }
    return head->next;
}
