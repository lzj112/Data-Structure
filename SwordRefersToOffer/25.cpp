/*
合并两个排序的链表
*/

#include <iostream>


struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == nullptr)
        {
            return pHead2;
        }
        else if (pHead2 == nullptr) 
        {
            return pHead1;
        }

        ListNode* p1 = pHead1, * p2 = pHead2;
        ListNode* p0 = new ListNode(1);
        ListNode* head = p0;

        while (p1 != nullptr && p2 != nullptr) 
        {
            if (p1->val > p2->val) 
            {
                p0->next = p2;
                p0 = p0->next;
                p2 = p2->next;
            }
            else 
            {
                p0->next = p1;
                p0 = p0->next;
                p1 = p1->next;
            }
        }
        if (p1 != nullptr) 
        {
            p0->next = p1;
        }
        if (p2 != nullptr) 
        {
            p0->next = p2;
        }
        return head->next;
    }
};