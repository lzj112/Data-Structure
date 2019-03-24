/* 
数组除自身外的乘积
给定一个包含n个整数的数组，其中n个> 1，返回一个数组输出，使输出[i]等于除nums[i]外的所有nums元素的乘积。
例子
输入:(1、2、3、4)
输出:[24,12,8,6]

不能使用额外空间 时间复杂度要为 O(n) 不能使用除法
*/

/*
使用两个辅助数组,一个arr1保存正序遍历的乘积,一个arr2保存逆序遍历的乘积
然后 ret[i] = arr1[i - 1] * arr2[i + 1]
注意边界条件
*/

#include <vector>
using namespace std;

class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int len = nums.size();
        if (0 == len || 1 == len)
        {
            vector<int> ret = nums;
            return ret;
        }

        vector<int> ins(len, nums[0]);
        vector<int> ret(len, nums[len - 1]);

        int mul1 = nums[0], mul2 = nums[len - 1];
        for (int i = 1; i < len; ++i)
        {
            mul1 *= nums[i];
            mul2 *= nums[len - i - 1];
            ins[i] = mul1;
            ret[len - i - 1] = mul2;
        }

        ret[0] = ret[1];
        for (int i = 1; i < len - 1; ++i)
        {
            ret[i] = ins[i - 1] * ret[i + 1];
        }
        ret[len - 1] = ins[len - 2];

        return ret;
    }
};