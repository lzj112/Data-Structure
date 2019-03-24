/*
给定一个非空整数数组，返回k个最常见的元素。
示例1:
输入:nums = [1,1,1,2,2,3]， k = 2
输出:[1,2]
示例2:
输入:nums = [1]， k = 1
输出:[1]
注意:
你可以假设k总是有效的，1≤k≤个数的唯一元素。
算法的时间复杂度必须优于O(n log n)，其中n是数组的大小。
*/

/*
想到哈希建立映射关系,统计出现次数,然后排序,然后返回前K个
*/
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> ret;
        int len = static_cast<int> (nums.size());
        if (k == len)
            return nums;
        
        for (int i = 0; i < len; i++) 
        {
            auto it = ret.find(nums[i]);
            if (it != ret.end())
                it->second++;
            else 
                ret.insert(make_pair(nums[i], 1));
        }

        vector<pair<int, int> > tmp(ret.begin(), ret.end());
        sort(tmp.begin(), tmp.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        });

        vector<int> t;
        for (int i = 0; i < k; i++) 
            t.push_back(tmp[i].first);
        return t;
    }
};