

/*
最大子数列和
*/
#include <iostream>


int maxSubSequm(int a[], int len) 
{
    if (a == nullptr) 
        return -1;
    int maxNum = 0;
    int subNum = 0;
    for (int i = 0; i < len; i++) 
    {
        if (subNum <= 0)
            subNum = a[i];  //如果之前子序列小于等于零,那么对后面的子序列号没有帮助,直接抛弃,以当前位置重新开始
        else 
            subNum += a[i]; //之前子序列加到目前为止大于零,那么继续累加
        if (subNum > maxNum)
            maxNum = subNum;    //更换最大值
    }

    return maxNum;
}
int main() 
{
    int a[] = {1, 0, -1, -2, 5, 9, -2, -4, 10, -2, 4, 1};
    std::cout << maxSubSequm(a, 12) << std::endl;
}