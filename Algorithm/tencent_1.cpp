#include <iostream>
#include <vector>
#include <stack>
using namespace std;


vector<int> func(vector<int> a, int len)
{
    vector<int> res(len, -1);   //存储结果
    stack<int> sta; //栈
    sta.push(0);    //压入数组第一个元素的下标
    for (int i = 1; i < len; i++)   //遍历数组
    {
        while (!sta.empty() && a[i] > a[(sta.top())])   //栈为空或者当前元素不大于栈顶对应元素
        {
            res[(sta.top())] = a[i];    //如果大于说明当前元素就是他的右边第一个最大值
            sta.pop();  //将栈顶元素出栈
        }
        sta.push(i);    //将当前元素下标入栈
    }
    return res;
}


int main()
{
    vector<int> a = {2, 5, 3, 7, 1, 2, 8};
    vector<int> b = func(a, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}