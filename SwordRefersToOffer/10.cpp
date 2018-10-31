/*
求斐波那契额数列的第n项
*/
#include <iostream>
using namespace std;

/*
效率很低的解法
重复的计算太多
*/
long long Fibonacci_0(unsigned int n) 
{
    if (n <= 0) 
    {
        return 0;
    }
    else if (n == 1) 
    {
        return 1;
    }
    return Fibonacci_0(n - 1) + Fibonacci_0(n - 2);
}

/*
改进版本
从下往上计算
*/
long long Fibonacci_1(unsigned int n) 
{
    int t[2] = {0, 1};
    if (n < 2) 
    {
        return t[n];
    }

    long long first, second, tmp;
    tmp = 0;
    first = 0;
    second = 1;
    for (int i = 2; i <= n; i++) 
    {
        tmp = first + second;
        first = second;
        second = tmp;
    }
    return tmp;
}
int main() 
{
    cout << Fibonacci_1(99) << endl;
}