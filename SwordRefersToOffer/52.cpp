/*
题目描述
输入两个链表，找出它们的第一个公共结点。
*/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};
class Solution
{
  public:

    

    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        if (pHead1 == nullptr || pHead2 == nullptr)
            return nullptr;
        
        int len1 = 1;
        ListNode* p1 = pHead1;
        while (p1 != nullptr) 
        {
            ++len1;
            p1 = p1->next;
        }

        int len2 = 1;
        ListNode* p2 = pHead2;
        while (p2 != nullptr) 
        {
            ++len2;
            p2 = p2->next;
        }
        if (p1 != p2)
            return nullptr;

        if (len1 > len2) 
        {
            int count = len1 - len2;
            while (count > 0) 
            {
                pHead1 = pHead1->next;
                count--;
            }
        }
        else 
        {
            int count = len2 - len1;
            while (count > 0)
            {
                pHead2 = pHead2->next;
            }
        }
        while (pHead1 != pHead2) 
        {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
};
