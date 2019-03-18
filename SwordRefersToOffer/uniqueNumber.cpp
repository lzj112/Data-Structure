/*
一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        sort(data.begin(), data.end());
        for (int i = 0; i < data.size(); )
        {
            if (data[i] != data[i + 1])
                cout << data[i++];
            else 
                i += 2;
        }
    }
};