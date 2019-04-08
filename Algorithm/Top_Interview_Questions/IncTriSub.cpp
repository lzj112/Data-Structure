/*
给定一个未排序的数组，返回该数组中是否存在长度为3的递增子序列。
函数的形式上应:
如果存在i j k，返回true
令arr[i] < arr[j] < arr[k]给定0≤i < j < k≤n-1否则返回false。
注意:您的算法应该在O(n)时间复杂度和O(1)空间复杂度下运行。

Example 1:
Input: [1,2,3,4,5]
Output: true

Example 2:
Input: [5,4,3,2,1]
Output: false
*/
#include <vector>
using namespace std;

class Solution
{
  public:
    bool increasingTriplet(vector<int> &nums)
    {
        vector<int> arr;
        int len = static_cast<int>(nums.size());
        for (int i = 0; i < len; i++)
            //如果辅助数组arr为空,或者当前元素比辅助数组末尾元素大,就更新辅助数组末尾元素
            if (arr.size() == 0 || arr.back() < nums[i])
                arr.push_back(nums[i]);
            else
            {
                int low = 0, high = arr.size() - 1;
                while (low < high) //二分查找辅助数组中第一个大于等于nums[i]的数,进行替换
                {
                    int mid = (low + high) / 2;
                    if (arr[mid] < nums[i])
                        low = mid + 1;
                    else
                        high = mid - 1;
                }
                arr[low] = nums[i];
            }
        //辅助数组长度即为最长递增子序列的长度
        return arr.size() >= 3;
    }
};