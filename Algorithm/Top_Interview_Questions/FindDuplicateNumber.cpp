/*
给定一个包含n + 1个整数的数组，其中每个整数都在1和n之间(含)，
证明至少有一个重复的数字必须存在。假设只有一个重复的数字，找出重复的那个。

例子:
Input: [1,3,4,2,2]
Output: 2

Input: [3,1,3,4,2]
Output: 3

要求:
不能修改数组(假设数组是只读的)。
你必须只使用常数O(1)额外的空间。
您的运行时复杂度应该小于O(n2)。
数组中只有一个重复的数字，但它可以重复多次。
*/


#include <vector>
using namespace std;

class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++) 
        {
            if (findSameNumber(i + 1, nums.size() - 1, nums[i], nums))
                return nums[i];
        }
        return -1;
    }
    bool findSameNumber(int l, int r, int k, vector<int>& nums) 
    {
        if (l > r)
            return false;
        int mid = (r - l) / 2;
        if (nums[mid] == k)
            return true;
        if (nums[mid] > k)
            return findSameNumber(l, mid - 1, k, nums);
        else 
            return findSameNumber(mid + 1, r, k, nums);

    }
};