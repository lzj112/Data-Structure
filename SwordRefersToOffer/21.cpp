/*
调整数组顺序使得奇数位于偶数前面
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