/*
反转单链表。
例子:
输入:1 - > 2 - > 3 - > 4 - > 5 - > NULL
输出:5 - > 4 - > 3 - > 2 - > 1 - > NULL
跟进:
链表可以迭代或递归地反转。你能两者都实现吗?
*/

/*
Definition for singly-linked list.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
  public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode* preNode = nullptr;
        ListNode* nextNode = head->next;
        while (head != nullptr) 
        {
            head->next = preNode;
            preNode = head;
            head = nextNode;
            if (nextNode != nullptr)
                nextNode = nextNode->next;
        } 
        return preNode;
    }
};