/*
给定一组不同的整数nums，返回所有可能的子集(幂集)。
注意:解决方案集不能包含重复的子集。
例子:
输入:nums = [1,2,3]
输出:
(
[3],
[1],
[2],
(1、2、3),
(1、3)
(2、3),
(1、2),
[]
]
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class numsolution
{
public:
  vector<vector<int> > subsets(vector<int> &nums)
  {
    vector<vector<int> > res(1);  //初始化一个空集
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
    {
      int size = res.size();
      for (int j = 0; j < size; ++j)  //将之前保存的子集分别加上现在的 这个元素
      {
        res.push_back(res[j]);
        res.back().push_back(nums[i]);
      }
    }
    return res;
  }
};