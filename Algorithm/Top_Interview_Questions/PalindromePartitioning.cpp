/*
给定一个字符串s，分区s使得分区的每个子字符串都是回文。
返回所有可能的s的回文分区。
Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> out;
        helper(s, 0, out, res);
        return res;
    }

    void helper(string s, int start, vector<string> &out, vector<vector<string>> &res)
    {
        if (start == s.size())  //遍历完s
        {
            res.push_back(out);
            return;
        }
        for (int i = start; i < s.size(); ++i)  //每个位置都遍历其子串
        {
            if (!isPalindrome(s, start, i))
                continue;
            out.push_back(s.substr(start, i - start + 1));  //从start开始到i的子串是一个回文串
            helper(s, i + 1, out, res); 
            out.pop_back(); //回溯到此,移除该子串,遍历其剩下的子串组合
        }
    }
    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            ++start;
            --end;
        }
        return true;
    }
};
