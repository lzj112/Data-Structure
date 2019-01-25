/*
钢条切割
不同长度的钢条对应不同的价格
给定一定长度的钢条,怎样切割利益最大
注意: 最优解可能是完全不需要切割
*/

#include <vector>
#include <iostream>

using namespace std;

//给定长度从1到10对应的不同价格
vector<int> price{0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
//保存每段长度对应的对大收益
vector<int> earning(100, 0);

//方法1 递归 自顶向下 效率差,重复计算多
//在长度>=30时所需要的计算时间已经不能接受了
int recursive(int len) 
{
    if (len == 0) 
        return 0;
    int max = 0;
    for (int i = 1; i <= len; i++) 
    {
        int p = price[i] + recursive(len - i);
        max = (p > max) ? p : max;
    }
    return max;
}

//方法2 使用备忘录的自顶向下 提升效率
int mome(int len) 
{
    if (len == 0) 
        return 0;
    else if (earning[len] != 0) //如果有记录
        return earning[len];
    
    int max = 0;
    for (int i = 1; i <= len; i++) 
    {
        int p = price[i] + mome(len - i);
        max = (p > max) ? p : max;
    }
    earning[len] = max;
    return max;
}

//方案3 自底向上
int fromBottomUp(int len) 
{
    for (int i = 1; i <= len; i++) 
    {
        int max = 0;
        for (int j = i; j >= 0; j--) 
        {
            int p = price[j] + earning[i - j];
            max = (p > max) ? p : max;
        }
        earning[i] = max;
    }
    return earning[len];
}


int main() 
{
    int n;
    cout << "钢条长度?" << endl;
    cin >> n;

    cout << fromBottomUp(n) << endl;
    cout << mome(n) << endl;
    cout << recursive(n) << endl;
}