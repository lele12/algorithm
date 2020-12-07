#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* detectCycle(ListNode* head)
{
    ListNode *point1 = head;
    ListNode *point2 = head;
    bool flag = false;
    while(point2 != NULL)
    {
        point1 = point1->next;
        if (point2->next == NULL)
        {
            return NULL;
        }
        point2 = point2->next->next;
        if (point1 == point2)
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        return NULL;
    }
    point2 = head;
    while(point1 != point2)
    {
        point1 = point1->next;
        point2 = point2->next;
    }
    return point1;
}
int main()
{
    ListNode a(1);
    // ListNode b(2);
    // ListNode c(0);
    // ListNode d(-4);
    // a.next = &b;
    // b.next = &a;
    // c.next = &d;
    // d.next = &b;
    ListNode *head = &a;
    ListNode *re = detectCycle(head);
    if (re != NULL)
    {
        cout << re->val << endl;
    }
    

    system("pause");
    return 0;
}