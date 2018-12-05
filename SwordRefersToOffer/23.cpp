#include <iostream>
#include <list>
/*
链表中环的入口节点
如果一个链表中包含环,如何找出环的 入口节点
*/

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* isThereLoop(ListNode* pHead)  //确认是否有环,没有返回nullptr,有返回环中某个节点
    {
        if (pHead == nullptr) 
        {
            return nullptr;
        }
        ListNode* pre = pHead->next;
        ListNode* ptr = nullptr;;
        if (pHead->next != nullptr) 
        {
            ptr = pHead->next->next;
        }
        while (ptr != nullptr && pre != nullptr) 
        {
            if (ptr == pre) 
            {
                break;
            }

            pre = pre->next;
            ptr = ptr->next;
            if (ptr != nullptr) 
            {
                ptr = ptr->next;
            }
        }
       
        return ptr;
    }

    ListNode* EntryNodeOfLoop(ListNode* pHead) 
    {
        ListNode* ptr = isThereLoop(pHead);
        if (ptr == nullptr) 
        {
            return nullptr;
        }
        int nodeCount = 1;
        ListNode* p = ptr->next;
        while (p != ptr)    //确定环的节点个数
        {
            nodeCount++;
            p = p->next;
        }
        p = pHead;
        for (int i = 0; i < nodeCount; i++) 
        {
            p = p->next;
        }
        ListNode* pre = pHead;
        while (pre != p) 
        {
            pre = pre->next;
            p = p->next;
        }
        return p;
    }
};

/*
要找的是环的入口节点
所以要先确认是否有环(使用快慢指针)
然后确定环的节点个数
这样才能确认入口
*/