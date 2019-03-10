#include <vector>
#include <iostream>
using namespace std;

//冒泡
void sort_1(vector<int>& arr) 
{
    bool flag;
    for (int i = 0; i < arr.size(); i++) 
    {
        flag = false;
        for (int j = 0; j < arr.size() - 1; j++) 
        {
            if (arr[j] > arr[ j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

//选择
void sort_2(vector<int>& arr) 
{
    for (int i = 0; i < arr.size(); i++) 
    {
        for (int j = i; j < arr.size(); j++) 
        {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

//快排
void quick_sort(int l, int r, vector<int>& arr) 
{
    if (l < r) 
    {
        int i = l, j = r;
        int target = l;
        while (i < j) 
        {
            while (i < j && arr[j] >= arr[target]) 
                j--;
            while (i < j && arr[i] <= arr[target]) 
                i++;
            if (i < j)
            swap(arr[i], arr[j]);
        }
        swap(arr[i], arr[target]);
        quick_sort(l, i - 1, arr);
        quick_sort(i + 1, r, arr);
    }
}

//堆排序 
//i结点的父节点下标为(i - 1) / 2,其左子结点下标为2 * i + 1,右子结点下标为2 * i + 2
void heap_sort(vector<int>& arr) 
{
    for (int i = arr.size() / 2;)
}


int main() 
{
    vector<int> arr{9, 2, 6, 7, 1, 4, 3, 10, 45, 40, 69, 56, 99, 79};
    // sort_1(arr);
    // sort_2(arr);
    // quick_sort(0, arr.size(), arr);
    for (auto x : arr) 
        cout << x << ' ';
    cout << endl;

    return 0;
}