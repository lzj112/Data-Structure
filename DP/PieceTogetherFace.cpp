/*
题目描述：给你六种面额1、5、10、20、50、100元的纸币，
假设每种币值的数量都足够多，编写程序求组成n元（n为0-10000的非负整数）的不同组合的个数。
输入描述：输入为一个数字n，即需要拼凑的面额
输出描述：也是一个数字，为组成n的组合个数。
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[6] = {1, 5, 10, 20, 50, 100};
    vector<long> dp(n + 1, 0); //取到n时的有多少种组合
    dp[0] = 1;
    for (int i = 0; i < 6; i++) //遍历每个钱的面值
    {
        for (int j = 1; j <= n; j++)
        {
            //用前i种面额的时候,拼凑成j
            if (j >= a[i])
                dp[j] = dp[j] + dp[j - a[i]]; //j值取和不取两种情况组合数目之和
        }
    }
    cout << dp[n] << endl;
    return 0;
}