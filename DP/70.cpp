/*
爬楼梯
你正在爬楼梯。它需要n步才能达到顶峰。
每次你可以爬1或2步。您可以通过多少不同的方式登顶？
注意：给定n将是一个正整数。
Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

class Solution
{
  public:
    int climbStairs(int n)
    {
        int f1 = 0;
        int f2 = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (i == 1) 
            {
                f1 = 0, f2 = 1;
            }
            else if (i == 2) 
            {
                f1 = 1, f2 = 1;
            }
            else 
            {
                f1 = f1 + f2;
                int t = f1;
                f1 = f2;
                f2 = t;
            }
        }
        return f1 + f2;
    }
};