/*
删除链表的节点
给定一个头指针,一个指定节点
*/

struct ListNode 
{
    int m_nValue;
    ListNode* next;
};

/*
将删除节点的下一个节点内容复制给该节点,然后删除下一个节点
*/
void DeleteNode(ListNode* head, ListNode* delNode) 
{
    if (delNode == head) //假如只有一节点
    {
        delete delNode;
        delNode = nullptr;
        head = nullptr;
    }
    else if (delNode->next == nullptr) //假如要删除的节点是尾节点
    {
        ListNode* p = head;
        while (p) 
        {
            if (p->next == delNode) 
            {
                delete delNode;
                delNode = nullptr;
                p->next = nullptr;
                break;
            }
        }
    }
    else //是链表中的节点
    {
        delNode->m_nValue = delNode->next->m_nValue;
        delNode->next = delNode->next->next;
        delete delNode->next;
    }
}
/*
但是这样就只能假设该删除节点的确在该链表中
这种验证只能交给调用该函数的人了 
*/