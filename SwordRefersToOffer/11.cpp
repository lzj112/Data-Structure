/*
把一个数组最开始的若干个元素搬到数组的末尾,
我们称之为数组的旋转,输入一个递增排序的数组的一个
旋转,输出旋转数组的最小元素
例如:
数组{3, 4, 5, 1, 2}是{1, 2, 3, 4, 5}的一个旋转,该数组的最小值为1
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) 
        {
            return 0;
        }        
        int length = rotateArray.size();
        int front = 0;
        int rear = length - 1;
        if (rotateArray[front] == rotateArray[rear]) //特例,首尾值相等,只能遍历
        {
            int min = rotateArray[front];
            for (int x : rotateArray) 
            {
                if (x <= min) 
                {
                    min = x;
                }
            }
            return min;
        }
        else if (rotateArray[front] < rotateArray[rear]) //说明这个数组整体旋转了,所以首就是最小值
        {
            return rotateArray[front];
        }
        else 
        {
            int middle = (front + rear) / 2;
            while (rotateArray[front] > rotateArray[rear]) //二分查找
            {
                if (rotateArray[middle] > rotateArray[front]) 
                {
                    front  = middle;
                    middle = (front + rear) / 2;
                }
                else if (rotateArray[middle] < rotateArray[rear]) 
                {
                    rear = middle;
                    middle = (front +rear) / 2;
                }
                if (front + 1 == rear) 
                {
                    return rotateArray[rear];
                }   
            }
        }
    }
};
int main() 
{
    Solution A;
    vector<int> tmp = {3, 4, 5, 1, 2};
    cout <<  "here is min :" << A.minNumberInRotateArray(tmp) << endl;
}

/*
直接遍历拿不到offer系列
旋转数组,可以分为两个有序的子数组
采用二分查找,当front大于middle说明middle值属于后面的子数组,小于middle说明
middle属于前面偏大的子数组
当front与rear相邻时,rear就是后面小的子数组的最小值
*/