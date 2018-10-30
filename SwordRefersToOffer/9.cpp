/*
用两个栈实现一个队列
队列的声明如下,请实现他的两个函数appendTail和deleteHead
分别完成在队列尾部插入节点和在队列头部删除节点的功能
*/

#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class CQueue
{
  public:
    CQueue();
    ~CQueue();

    void appendTail(const T &node);
    T deleteHead();

  private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
    if (stack2.empty()) //stack2为空
    {
        if (!stack1.empty())    //stack1不为空
        {
            while (!stack1.empty()) //将stack1中所有元素移至stack2
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }

    if (stack2.empty()) //两个栈都是空的
    {
        cout << "there is empty" << endl;
        throw new exception("there is empty");
    }

    T head = stack2.top(); //删除stack2栈顶元素
    stack2.pop();

    return head;
}