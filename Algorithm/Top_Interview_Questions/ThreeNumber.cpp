/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int len = static_cast<int> (nums.size());
        if (nums[0] >= 0 || nums[len - 1] <= 0)
            return vector<vector<int> > ();
        
        set<vector<int> > tmp;
        for (int i = 1; i < len - 1; i++) 
        {
            int target = nums[i] + nums[i - 1];
            for (int j = i + 1; j < len; j++) 
            {
                if (nums[j] == -target)
                {
                    vector<int> a{nums[i - 1], nums[i], nums[j]};
                    tmp.insert(a);
                }
            }
        }
        vector<vector<int> > res(tmp.begin(), tmp.end());
        return res;
    }
};

int main() 
{
    vector<int> t{-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int> > tmp = s.threeSum(t);
    for (int i = 0; i < tmp.size(); i++) 
    {
        for (auto x : tmp[i])
            cout << x << ' ';
        cout << endl;
    }
}