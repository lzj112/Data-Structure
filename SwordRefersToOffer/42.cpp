
/*
给一个数组，返回它的最大连续子序列的和

F(i) = arr[i] (i == 0 || F(i - 1) <= 0)
     = F(i - 1) + arr[i] (i != 0 || F(i - 1) > 0)
*/
#include <vector>
using namespace std;

class Solution
{
  public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        vector<int> tmp(array.size(), 0);
        int currentSum = 0, greatestSum = array[0];
        for (int j = 0; j < array.size(); j++)
        {
            if (currentSum <= 0)
                currentSum = array[j];
            else 
                currentSum += array[j];
            greatestSum = (greatestSum > currentSum) ? greatestSum : currentSum;
        }
        return greatestSum;
    }
};