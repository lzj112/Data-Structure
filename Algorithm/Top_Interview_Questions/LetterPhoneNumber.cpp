
/*
给定一个包含2-9数字的字符串，返回该数字可能表示的所有字母组合。
下面给出了数字到字母的映射(就像电话按钮一样)。注意，1不映射到任何字母。
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
尽管上面的答案是按照字典顺序排列的，但是您的答案可以是您想要的任何顺序。
*/

#include <string>
#include <vector>
using namespace std;

/*
这种题都是递归,记录层数
*/
class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        string out[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret;
        DFS(digits, ret, 0, out, "");
        return ret;
    }

    void DFS(string digits, vector<string>& ret, int level, string* out, string str) 
    {
        if (level == digits.size())
        {
            ret.push_back(str);
            return;
        }
        
        string tmp = out[digits[level] - '0'];
        for (int i = 0; i < tmp.size(); i++) 
        {
            DFS(digits, ret, level + 1, out, str + tmp[i]);
        }
    }
};


