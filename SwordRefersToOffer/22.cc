/*
链表中倒数第k个节点
输入一个链表, 输出链表中倒数第k个节点
有头结点
从头结点的下一节点算为第一个节点
*/
struct ListNode 
{
    int value;
    ListNode* next;
};

class Solution 
{
public:
    void show(ListNode*);   //输出节点
    void findKToTail(ListNode* head, int k) 
    {
        if (head == nullptr || k <= 0) return;
        ListNode* pre = head;

        ListNode* ptr = pre;
        for (int i = 0; i < k; i++) 
        {
            ptr = ptr->next;
            if (ptr == nullptr) 
            {
                return ;
            }
        }
        while (ptr->next != nullptr) 
        {
            pre = pre->next;
            ptr = ptr->next;
        }
        show(pre);  //找到了
    }
};

/*
前后指针,保持k-1的距离
要注意代码的鲁棒性
*/
