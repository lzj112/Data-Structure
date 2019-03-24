/*
给定一组不同的整数，返回所有可能的排列。
例子:
输入:(1、2、3)
输出:
(1、2、3),
(1、3、2),
(2,1,3),
(2、3、1)
(3、1、2),
(3,2,1)
*/
#include <iostream>
using namespace std;

int sum = 0; //全排列个数

//打印数组内容
void print(int array[], int len)
{
    printf("{");
    for (int i = 0; i < len; ++i)
        cout << array[i] << " ";
    printf("}\n");
}


//实现两数交换
void swap(int *o, int i, int j)
{
    int tmp = o[i];
    o[i] = o[j];
    o[j] = tmp;
}
/*
//递归实现数组全排列并打印
void permutation(int array[], int len, int index)
{
    if (index == len)   //全排列结束
    {
        ++sum;
        print(array, len);
    }
    else
        for (int i = index; i < len; ++i)
        {
            //将第i个元素交换至当前index下标处
            swap(array, index, i);

            //以递归的方式对剩下元素进行全排列
            permutation(array, len, index + 1);

            //将第i个元素交换回原处
            swap(array, index, i);
        }
}
*/


///如果有重复的元素
//是否交换
bool isSwap(int array[], int len, int index)
{
    for (int i = index + 1; i < len; ++i)
        if (array[index] == array[i])
            return false;
    return true;
}

//递归实现有重复元素的数组全排列
void permutation(int array[], int len, int index)
{
    if (index == len)
    { //全排列结束
        ++sum;
        print(array, len);
    }
    else
        for (int i = index; i < len; ++i)
        {
            if (isSwap(array, len, i) == true)
            { //新增判断是否交换
                //将第i个元素交换至当前index下标处
                swap(array, index, i);

                //以递归的方式对剩下元素进行全排列
                permutation(array, len, index + 1);

                //将第i个元素交换回原处
                swap(array, index, i);
            }
        }
}

int main()
{
    int array[3] = {3, 3, 3};
    permutation(array, 3, 0);
    cout << "sum:" << sum << endl;
}