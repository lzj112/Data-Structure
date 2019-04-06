#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, sum, cnt;
    int i, j, k;
    cin >> m >> n;
    vector<int> A(n);
    for (i = 0; i < n; i++)
        cin >> A[i];
    sort(A.begin(), A.end());
    if (A[0] != 1)  //如果没有1,一定有面值是凑不出来的
    {
        cout << -1 << endl;
        return 0;
    }
    sum = 1;        //sum表示1~sum(包括sum)可以被表示
    while (sum < m) //凑到m为止
    {
        for (i = 0; i < n; i++)    //如果有一个面额
            if (A[i] > sum + 1)
                break;
        sum += A[i];
        cnt++;
        cout << sum << endl;
    }
    cout << cnt + 1 << endl;
}