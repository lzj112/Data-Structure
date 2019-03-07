
/*
对于一个数字序列，请设计一个复杂度为O(nlogn)的算法，返回该序列的最长上升子序列的长度，
这里的子序列定义为这样一个序列U1，U2...，其中Ui < Ui+1，且A[Ui] < A[Ui+1]。
给定一个数字序列A及序列的长度n，请返回最长上升子序列的长度。
测试样例：
[2,1,4,3,1,5,6],7
返回：4
*/

#include <vector>
#include <iostream>
using namespace std;

//时间复杂度O(n2)
int findLongest(int A[], int len)
{
    //初始化一维数组存放每个元素对应的最大递增子序列长度
    int* arr = new int[len];
    for (int i = 0; i < len; i++) 
        arr[i] = 1; //初始化长度为1,即一个只有元素时的长度
    
    //控制循环条件,每个元素都从头遍历一遍进行比较
    for (int i = 1; i < len; i++)
    for (int j = 0; j < i; j++) //0到i-1去和A[i]比较
    {
        //如果当前元素比前面的元素大,且和其能组成更长的子序列
        if (A[i] > A[j] && arr[i] < arr[j] + 1)
            arr[i] = arr[j] + 1;    
    }
    //arr数组中最大值就是最长递增子序列的长度
    int max = 0;
    for (int i = 0; i < len; i++) 
        if (max < arr[i])
            max = arr[i];
    delete[] arr;
    return max;
}

//时间复杂度O(nlogn)
int findLongestSub(int A[], int len) 
{
    vector<int> arr;
    for (int i = 0; i < len; i++) 
        //如果辅助数组arr为空,或者当前元素比辅助数组末尾元素大,就更新辅助数组末尾元素
        if (arr.size() == 0 || arr.back() < A[i]) 
            arr.push_back(A[i]);
        else 
        {
            int low = 0, high = arr.size() - 1;
            while (low < high) //二分查找辅助数组中第一个大于等于A[i]的数,进行替换
            {
                int mid = (low + high) / 2;
                if (arr[mid] < A[i])
                    low = mid + 1;
                else 
                    high = mid - 1;
            }
            arr[low] = A[i];
        }
    //辅助数组长度即为最长递增子序列的长度
    return arr.size();
}


int main() 
{
    int a[] = {2 ,1, 5, 3, 6, 4, 8, 9, 7, 8};
    cout << findLongest(a, 10) << endl;
    cout << findLongestSub(a, 10) << endl;
}