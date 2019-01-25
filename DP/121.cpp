/*
Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.

假设有一个数组，其中第i个元素是给定股票在第i天的价格。
如果只允许您完成最多一项交易(即(即买一股，卖一股)，设计一种算法来寻找最大利润。
注意，你不能在买股票之前就把它卖掉。

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: 
Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/

#include <vector>
using namespace std;


class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int max = 0;
        
        for (int i = 0; i < prices.size(); i++) 
        {
            for (int j = i; j < prices.size(); j ++) 
            {
                int p = prices[j] - prices[i];
                max= (p > max) ? p : max;
            }
        }
        return max;
    }
};