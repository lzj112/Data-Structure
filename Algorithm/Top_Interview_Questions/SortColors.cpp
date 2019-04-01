/*
排序
相同数字相邻
不能使用 sort
Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        int len = static_cast<int> (nums.size());
        quicksort(0, len - 1, nums);
    }
    void quicksort(int l, int r, vector<int>& nums) 
    {
        if (l >= r)
            return ;
        int i = l, j = r;
        while (i < j) 
        {
            while (i < j && nums[j] >= nums[l])
                j--;
            while (i < j && nums[i] <= nums[l])
                i++;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[j], nums[l]);
        quicksort(l, j - 1, nums);
        quicksort(j + 1, r, nums);
    }
    
};
