/*
输入一个链表的头结点
从头到尾反过来打印出每个节点的值
链表节点定义如下:
struct ListNode 
{
    int m_nKey;
    ListNode* m_pNext;
};
*/

#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode *m_pNext;
};

class List
{
  private:
    struct ListNode *head;
    int L = 10;

  public:
    List();
    ~List()
    {
        struct ListNode *p = head->m_pNext;
        while (p)
        {
            delete p;
            p = p->m_pNext;
        }
        delete head;
        head = nullptr;
    }
    struct ListNode *getHead()
    {
        return head;
    }
    void useRecursive(struct ListNode *p);
    void useStack();
};

List::List()
{
    head = new struct ListNode;
    struct ListNode *p1;
    struct ListNode *p2;
    p2 = head;
    cout << "Input " << L << "s numbers" << endl;
    while (L--)
    {
        p1 = new struct ListNode;
        p1->m_pNext = nullptr;
        cin >> p1->m_nKey;
        p2->m_pNext = p1;
        p2 = p1;
    }
}

void List::useRecursive(struct ListNode *p)
{

    if (p->m_pNext)
    {
        useRecursive(p->m_pNext);
    }
    if (p != head)
    cout << p->m_nKey << ' ';
}

void List::useStack()
{
    stack<struct ListNode *> node;
    struct ListNode *p = head->m_pNext;
    while (p)
    {
        node.push(p);
        p = p->m_pNext;
    }
    while (!node.empty())
    {
        cout << node.top()->m_nKey << ' ';
        node.pop();
    }
    cout << endl;
}

int main()
{
    List listP;
    cout << "Recursive : \n";
    struct ListNode *p = listP.getHead();
    listP.useRecursive(p);
    cout << endl;

    cout << "Stack : \n";
    listP.useStack();

    return 0;
}