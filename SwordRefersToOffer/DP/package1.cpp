#include <iostream>
#include <iomanip>
using namespace std;
int V[4][6];
int KNAPSACK(int n, int C, int w[], int v[])
{
    for (int i = 0; i <= n; i++)
        V[i][0] = 0;

    for (int j = 0; j <= C; j++)
        V[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            V[i][j] = V[i - 1][j];
            if (w[i - 1] <= j)
                V[i][j] = max(V[i][j], V[i - 1][j - w[i - 1]] + v[i - 1]);
        }

        //（非必须）输出V数组显示动态规划的过程
        for (int x = 0; x <= n; x++)
        {
            for (int y = 0; y <= C; y++)
            {
                cout << setw(3) << V[x][y];
            }
            cout << endl;
        }
        cout << endl;
    }

    //输出放入背包的物品
    int k = C;
    for (int i = n; i >= 0; i--)
    {
        if (V[i][k] > V[i - 1][k])
        {
            cout << v[i - 1] << " " << w[i - 1] << endl;
            k -= w[i - 1];
        }
    }

    //返回能装下的最大价值
    return V[n][C];
}
int main()
{
    int n = 4, C = 6;
    int w[3] = {1, 2, 3};
    int v[3] = {6, 10, 12};
    cout << KNAPSACK(3, 5, w, v);
    return 0;
}
