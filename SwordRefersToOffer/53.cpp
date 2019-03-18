/*
题目描述
统计一个数字在排序数组中出现的次数。
都是整数且排序好,那就搜索 k + 0.5 和 k - 0.5 应该插入的位置
然后相减,就是k 的个数
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findNumber(vector<int>& arr, double k) 
    {
        int l = 0;
        int r = arr.size() - 1;
        int mid;
        while (l <= r) 
        {
            mid = (r - l) / 2 + l;
            if (arr[mid] < k)
                l = mid + 1;
            else
                r = mid - 1;
        }    
        return l;
   }
    int GetNumberOfK(vector<int> data, int k)
    {
        int l = findNumber(data, k - 0.5);
        int r = findNumber(data, k + 0.5);        
        return r - l;
    }
};