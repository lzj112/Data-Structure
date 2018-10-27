/*
找出数组中重复的数字
在一个长度为N的数组中, 元素范围在0~N-1,
*/

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 7;
vector<int> result;

void findDuplicate(array<int, N> &numbers);

int main()
{
    array<int, N> numbers;
    numbers = {2, 3, 1, 0, 2, 5, 5};
    findDuplicate(numbers);
    if (!result.empty())
    for_each(result.begin(), result.end(), [&](int x) {
        cout << x << ' ';
    });
    cout << endl;
}

void findDuplicate(array<int, N>& numbers)
{
    if (numbers.empty())
    {
        return ;
    }

    /*
    没有比number长度更大的元素
    */
    for (int x : numbers) 
    {
        if (x > numbers.size() - 1) 
        {
            return ;
        }
    }
    for (int i = 0; i < numbers.size(); i++)
    {

        while (numbers[i] != i)
        {
            if (numbers[numbers[i]] == numbers[i])
            {
                result.push_back(numbers[i]);
                break;
            }
            int tmp = numbers[i];
            // numbers[i] = numbers[numbers[i]];    
            numbers[i] = numbers[tmp];
            // numbers[numbers[i]] = tmp;
            numbers[tmp] = tmp;
            /*
            注释部分为第一次写的错误代码,numbers[i]已经交换为了numbers[numbers[i]]
            不是所期望的原值,要使用中间变量
            */
        }
    }
}