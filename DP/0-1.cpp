/*
0-1背包问题
给定 i 种物品和一个最大载重量为 j 的背包，物品 i 的重量是 wi，其价值为 vi 。
问：应该如何选择装入背包的物品，使得装入背包中的物品的总价值最大？

状态转移方程为 
边界条件 
    if (i == 0) 
        F(0, j) = 0
    if (j == 0) 
        F(i, 0) = 0
    if (w[1] >= j) 
        F(1, j) = v[1]
    else    
        F(1, j) = 0
转移方程
F(i, j) = max(F(i - 1, j), F(i - 1, j - w[i]) + v[i])

如果第i种物品不拿,之前的背包容量从j - w[i - 1]增大到j,第i种不拿只拿到第i-1种,所以是
F(i - 1, j),相当于容量增大到j,放东西的选择种类只到第i-1种物品
如果第i种物品拿,每种物品只能放一次,所以就是之前容量是j - w[i] 时的价值 :
F(i - 1, j - w[i])再加上第i种物品的价值
然后在这两种情况里选择最大值
*/

#include <vector>
#include <iostream>
using namespace std;

int mostValue_01(vector<int>& val, vector<int>& wt, int capacity) 
{
    vector<int> ret(capacity + 1, 0);
    int len = val.size();

    for (int i = 1; i <= len; i++) //控制循环次数
    {
        for (int j = capacity; j >= 1; j--) //从右向左遍历
        {
            if (j >= wt[i]) //可以装下第i种物品
                ret[j] = max(ret[j], ret[j - wt[i]] + val[i]);
        }
    }

    return ret[capacity];
}

int main() 
{
    vector<int> value_{-1,2,3,1,4,6,5};
    vector<int> weight_{-1,5,6,5,1,19,7};
    int capacity = 10;

    cout << "最大价值为 = " << mostValue_01(value_, weight_, capacity) << endl;
}