/*
编写一个反转字符串的函数。输入字符串作为字符数组char[]给出。
不要为另一个数组分配额外的空间，您必须使用O(1)额外内存修改输入数组。
您可以假设所有字符都由可打印的ascii字符组成。
Example 1:
Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:
Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
  public:
    void reverseString(vector<char>& s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r) 
        {
            swap(s[l++], s[r--]);
        }

    }
};