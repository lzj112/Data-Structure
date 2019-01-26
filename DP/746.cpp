/*
 Min Cost Climbing Stairs
 On a staircase, the i-th step 
 has some non-negative cost cost[i] assigned (0 indexed).
Once you pay the cost, you can either climb one or two steps. 
You need to find minimum cost to reach the top of the floor, 
and you can either start from the step with index 0, 
or the step with index 1.

在楼梯上，第i步有一些非负成本 成本[i]赋值(索引为0)。
一旦你付出了代价，你可以爬上一两级。你需要找到到达顶层的最小成本，
你可以从索引0的步骤开始，也可以从索引1的步骤开始。

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: 
Cheapest is start on cost[1], pay that cost and go to the top.
最便宜的是从成本[1]开始，支付这个成本，然后到顶部。

Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: 
Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
最便宜的是从成本[0]开始，只在1s开始，跳过成本[3]。

Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].

注意:
cost的长度将在[2,1000]范围内。
每个代价[i]都是[0,999]范围内的整数。
*/

#include <vector>
using namespace std;

// 题目说了cost长度从2开始
//prev先等于到达第i台阶的最小代价
//交换然后交换prev和curr,让curr等于达到第i台阶台阶
//然后下一个台阶时,curr等于的是i-1台阶最小代价,prev是i-2台阶最小代价
//然后min()求最小值

class Solution
{
  public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int prev = 0, curr = 0;
        for (size_t i = 2; i < cost.size() + 1; ++i)
        {
            prev = min(prev + cost[i - 2], curr + cost[i - 1]);
            swap(prev, curr);
        }
        return curr;
    }
};
