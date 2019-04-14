
//大数相加

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string func(string s1, string s2) 
{
    int len1 = s1.size();
    int len2 = s2.size();
    string ret("");
    if (len1 > len2) 
    {
        string tmp(len1 - len2, '0');
        s2 = tmp + s2;
    }
    else if (len2 > len1)
    {
        string tmp(len2 - len1, '0');
        s1 = tmp + s1;
    }
    int i = s1.size(), j = s2.size();
    int tmp_1, tmp_2, sum;
    int isOver = 0;
    while (i && j)
    {
        tmp_1 = s1[--i] - '0';
        tmp_2 = s2[--j] - '0';
        sum = (isOver > 0) ? (tmp_1 + tmp_2 + isOver) : (tmp_1 + tmp_2);
        isOver = (sum >= 10) ? (sum / 10) : 0;
        ret += ((sum % 10) + '0');
    }
    if (isOver) 
    {
        ret += isOver + '0';
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() 
{
    string s1("1234");
    string s2("123");
    cout << func(s1, s2) << endl;
}