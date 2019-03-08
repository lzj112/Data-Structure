/* 
给定整数数组号，找到具有最大和的相邻子数组(至少包含一个数字)并返回其和。
例子:
输入:[-2,1,-3,4,-1,2,1,-5,4],
输出:6
说明:[4，-1,2,1]的和最大= 6。

跟进:
如果您已经找到了O(n)的解决方案，那么尝试使用分治方法编写另一个解决方案，这种方法更加微妙。
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        int* num = new int[nums.size()];
        for (int i = 0; i < nums.size(); i++) 
            num[i] = nums[i];
        
        int tmpNum = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            for (int j = i; j < nums.size(); j++) 
            {
                tmpNum += nums[j];
                if (num[i] < tmpNum)
                    num[i] = tmpNum;
            }
            tmpNum = 0;
        }

        int max = num[0];   //不能等于0,如果数组只有一个负数就不对了
        for (int i = 0; i < nums.size(); i++) 
            if (max < num[i]) max = num[i];
        delete[] num;
        return max;
    }
};

int main() 
{
    vector<int> a = {-2};
    Solution b;
    cout << b.maxSubArray(a) << endl;
}