/*
最长不重复子串
*/

#include <string>
#include <iostream>
using namespace std;

int longestSubstring(string str)
{
    //利用哈希的思想,key是每一个字符,value是其对应的下标
    // 存储上一个重复字符的位置
    int* lastPosition = new int[256];
    //初始化,首字符之前没有与其重复的字符,都为-1
    for (int i = 0; i < 256; i++)
    {
        lastPosition[i] = -1;
    }

    // 动态规划过程
    int previous = -1;  //记录上一个不重复子串的终点
    int current = 0;    //记录当前不重复子串长度
    int maxLength = 0;  //记录最大不重复子串长度
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        //碰到重复字符previous更改为该重复字符的位置
        previous = max(previous, lastPosition[str[i]]);
        //本次子串长度
        current = i - previous;
        maxLength = max(current, maxLength);
        //更新该字符对应的下标
        lastPosition[str[i]] = i;
    }
    return maxLength;
}

int main() 
{
    string a("abbcdd");
    cout << longestSubstring(a) << endl;;
}