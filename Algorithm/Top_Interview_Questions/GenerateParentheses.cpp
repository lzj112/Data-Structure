/*
给定n对括号，编写一个函数来生成所有格式良好的括号组合。
例如，给定n = 3，解集为:
(
”((()))”,
”(()())”,
”(())()”,
“()(())”,
”()()()”
]

*/

#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;

        //n对括号,n个左括号,n个右括号
        generateParenthesisDFS(n, n, "", res);
        return res;
    }

    //left right记录左右括号的数量
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res)
    {
        //剩下的左括号数比右括号多,说明在下面生成的括号序列里
        //一定会发生右括号比左括号多的情况,有)(这种情况,直接退出
        if (left > right)
            return;
        //如果左右括号都没了,说明组成了一个括号排列了
        if (left == 0 && right == 0)
            res.push_back(out);
        else
        {
            //还余有左括号
            if (left > 0)
                generateParenthesisDFS(left - 1, right, out + '(', res);
            //还余有右括号
            if (right > 0)
                generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }
};


class Parenthesis
{
  public:
    bool chkParenthesis(string A, int n)
    {
        if (n % 2)
            return false;
        stack<char> st;
        for (char c : A)
        {
            if ('(' == c)
                st.push(c);
            else if (')' == c)
            {
                if (st.empty())
                    return false;
                else
                    st.pop();
            }
            else
                return false;
        }
        return st.empty();
    }
};