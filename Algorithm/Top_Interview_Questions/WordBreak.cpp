/*
给定一个非空字符串s和一个包含非空单词列表的dictionary wordDict，
确定是否可以将s分割为一个由一个或多个字典单词组成的空格分隔的序列。
注意:
同一词在词典中可以重复使用多次。
你可以假设字典里没有重复的单词。
Example 1:
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

//递归解法
class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return check(s, wordSet, 0, memo);
    }
    bool check(string s, unordered_set<string> &wordSet, int start, vector<int> &memo)
    {
        if (start >= s.size())
            return true;
        if (memo[start] != -1)
            return memo[start];
        for (int i = start + 1; i <= s.size(); ++i)
        {
            if (wordSet.count(s.substr(start, i - start)) && check(s, wordSet, i, memo))
            {
                return memo[start] = 1;
            }
        }
        return memo[start] = 0;
    }
};
//dP解法
class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 0; i < dp.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (dp[j] && wordSet.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};