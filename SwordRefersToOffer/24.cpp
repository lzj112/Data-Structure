/*
反转链表
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
    ListNode* ReverseList(ListNode* pHead) 
    {
        if (pHead == nullptr) 
        {
            return nullptr;
        }
        ListNode* preNode = pHead;
        ListNode* nextNode = pHead->next;
        ListNode* tmpNode = nullptr;
        while (nextNode != nullptr) 
        {
            tmpNode = nextNode->next;
            nextNode->next = preNode;
            preNode = nextNode;
            nextNode = tmpNode; 
        }
        pHead->next = nullptr;
        return preNode;

    }
};