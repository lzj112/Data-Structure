

#include <map>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

/*
给定一个数组,全是正数, 返回累加和为给定值 k 的最长子数组长度
因为全是正数,又要求是子数组,那么使用左右指针记录子数组左右边界
和相等时加上下一个元素一定是大于,减去一个元素一定是小于
*/
int getMaxLength(vector<int> arr, int k)
{
    if (arr.empty() || k <= 0)
        return 0;
    int len = 0, left = 0, right = 0;
    int sum = arr[0];
    while (right < arr.size())
    {
        if (sum == k) //满足条件,此时记录较大的len,右移left,检测下一个子数组
        {
            len = max(len, right - left + 1);
            sum -= arr[left++];
        }
        else if (sum < k) //小于,不够,右移right
        {
            right++;
            if (right == arr.size())
            { //边界判断
                break;
            }
            sum += arr[right]; //更新sum
        }
        else
        {
            sum -= arr[left++]; //大了,这个子数组不行,右移left
        }
    }
    return len; //遍历完后len是最大子数组长度
}



int main()
{
    vector<int> data{1, 2, 3, 4, 5, 6};
    int sum = 10;
    cout << getMaxLength(data, sum) << endl;
    return 0;
}