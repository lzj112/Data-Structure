/*
peak元素是比它的邻居更大的元素。
给定一个输入数组nums，其中nums[i]≠nums[i+1]，找到一个peak元素并返回其索引。
数组可能包含多个峰值，在这种情况下，将索引返回到任何一个峰值都可以。
你可以想象一下nums[-1] = nums[n] = -∞。
Example 1:
Input: nums = [1,2,3,1]
Output: 2
说明:3是一个peak元素，您的函数应该返回索引号2。
Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
说明:函数可以返回索引号1，其中峰值元素为2，
或者索引5，其中峰值元素是6。
注意:
你的解应该是对数复杂度。
*/

#include <vector>
using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    int n = static_cast<int> (nums.size());
    if (n == 1)
      return 0;
    if (n == 0)
      return -1;      
    if (nums[0] > nums[1])
      return 0;
    else if (nums[n - 1] > nums[n - 2])
      return n - 1;
    return findPeak(1, n, nums);
  }
  int findPeak(int l ,int r, vector<int>& nums) 
  {
    if (l >= r) return -1;
    if (nums[l] > nums[l - 1] && nums[l] > nums[l + 1])
      return l;
    return findPeak(l + 1, r, nums);
  }
};