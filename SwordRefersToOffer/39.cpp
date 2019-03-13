/*
题目描述
数组中有一个数字出现的次数超过数组长度的一半请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        sort(numbers.begin(), numbers.end(), [](int a, int b){
            return a < b;
        });
        for (auto x : numbers) 
            cout << x << ' ';
        cout << endl;
        int len = static_cast<int> (numbers.size());
        int number = numbers[len / 2];
        int count = 0;
        for (int i = 0; i < len; i++) 
            if (number == numbers[i])
                count++; 
        return (count > len / 2) ? numbers[len / 2] : 0;
    }
};
