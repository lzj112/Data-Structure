/*
调整数组顺序使得奇数位于偶数前面
头尾各有一个指针,头指针后移碰到偶数停下,尾指针前移碰见奇数停下
然后交换

如果想保有奇偶数的原有次序,就只能顺序或者相邻交换,可以直接使用冒泡,改一下判断条件
*/

#include <vector>

class Solution 
{
public:
    void reOrderArray(std::vector<int>& array) 
    {
        if (array.empty()) 
        {
            return ;
        }
        int head = 0;
        int rear = array.size() - 1;

        while (1) 
        {
            while (array[head] % 2 != 0) 
            {
                head++;
            }
            while (array[rear] % 2 == 0) 
            {
                rear--;
            }

            if (head >= rear) 
            {
                break;
            }

            int tmp = array[head];
            array[head] = array[rear];
            array[rear] = tmp;
        }
    }
};