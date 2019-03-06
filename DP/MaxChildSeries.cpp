

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
            subNum = a[i];
        else 
            subNum += a[i];
        if (subNum > maxNum)
            maxNum = subNum;
    }

    return maxNum;
}
int main() 
{
    int a[] = {1, 0, -1, -2, 5, 9, -2, -4, 10, -2, 4, 1};
    std::cout << maxSubSequm(a, 12) << std::endl;
}