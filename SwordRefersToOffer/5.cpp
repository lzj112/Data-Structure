/*
替换空格
题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
则输出“We%20are%20happy.”。
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int Length = 20;

void ExchangeBlank(char *str, int stringLength);
int main()
{
    char str[Length];
    cout << "Input a String : " << endl;
    cin.getline(str, Length);
    ExchangeBlank(str, strlen(str));
    cout << "After ExchangeBlank : " << str << endl;
    return 0;
}

void ExchangeBlank(char *str, int stringLength)
{
    if (str == nullptr || stringLength <= 0)
    {
        return;
    }
    int numberBlank = 0;
    for (int i = 0; i < stringLength; i++) 
    {
        if (str[i] == ' ') 
        {
            numberBlank++;    //空格数
        }
    }
    int newLength = numberBlank * 2 + stringLength;    //空格换成%20
    if (newLength >= Length)    //不够放
    {
        return;
    }

    while (stringLength >= 0/* && newLength > stringLength*/) 
    {
        if (str[stringLength] == ' ') 
        {
            str[newLength--] = '0';
            str[newLength--] = '2';
            str[newLength--] = '%';
        }
        else 
        {
            str[newLength--] = str[stringLength];
        }
        --stringLength;
    }
}
