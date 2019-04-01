/*
给定一个字符串数组，将字谜组合在一起。
例子:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
注意:
所有输入都是小写的。
输出的顺序无关紧要。
*/

#include <map>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

//将每个字符串重新排序,如果能组成同一个,排序后结果一样
//使用map保存键值相等的这些字符串
class Solution
{
  public:
    vector<vector<string> > groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string> > strcount_;
        for (auto k : strs) 
        {
          string x = k;
          sort(x.begin(), x.end());
          auto it = strcount_.find(x);
          if (it != strcount_.end())
            it->second.push_back(k);
          else 
            strcount_.insert(make_pair(x, vector<string>{k}));
        }
        vector<vector<string> > ret;
        for (auto x : strcount_) 
          ret.push_back(x.second);
        return ret;
    }
};