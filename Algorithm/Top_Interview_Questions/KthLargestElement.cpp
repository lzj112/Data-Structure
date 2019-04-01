/*
找出未排序数组中第k大的元素。注意，它是排序后第k大的元素，而不是第k个不同的元素。
示例1:
输入:[3,2,1,5,6,4]，k = 2
输出:5
示例2:
输入:[3,2,3,1,2,4,5,5,6]，k = 4
输出:4
注意:
你可以假设k总是有效的，1≤k≤数组的长度。
*/
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    sort(nums.begin(), nums.end());
    int len = static_cast<int> (nums.size());
    return nums[len - k];
  }
};
