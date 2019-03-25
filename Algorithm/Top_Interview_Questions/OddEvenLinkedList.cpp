/*
给定一个单链表，将所有奇数节点按偶数节点分组。请注意，这里我们讨论的是节点号，而不是节点中的值。
你应该试着把它放在合适的位置。程序应该在O(1)空间复杂度和O(nodes)时间复杂度下运行。
示例1:
Input: 1->2->3->4->5->nullptr
Output: 1->3->5->2->4->nullptr
示例2:
Input: 2->1->3->5->6->4->7->nullptr
Output: 2->3->6->7->1->5->4->nullptr
注意:
偶数组和奇数组内部的相对顺序应该与输入中相同。
第一个节点被认为是奇数，第二个节点被认为是偶数，以此类推……
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
一对奇偶指针
奇指针先指向头指针,偶指针指向第二个结点
然后将偶指针后面的一个节点交换到奇指针后面,
奇偶指针同时向前进,循环上面
*/

class Solution
{
  public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *pre = head, *cur = head->next;
        while (cur && cur->next)
        {
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            cur = cur->next;
            pre = pre->next;
        }
        return head;
    }
};