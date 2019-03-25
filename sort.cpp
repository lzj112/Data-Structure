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
//调整元素使其成为一个大顶堆/小顶堆
//i是指向的是第i个非叶子结点
void heap_adjust(vector<int>& arr, int i, int len) 
{
    int tmp = arr[i];   //保存当前结点值
    for (int j = 2 * i + 1; j < len; j = 2 * j + 1)   //遍历其子结点
    {
        //得到j是值较大的子结点下标
        if (j + 1 < len && arr[j] < arr[j + 1]) 
            j++;    
        //如果当前结点比其最大子结点大,就不用调整,break
        if (tmp >= arr[j]) 
            break;
        //将当前结点等于其最大子结点,这时这两个结点值是一样的
        arr[i] = arr[j];
        //改变当前结点指向其最大子结点
        i = j;
    }
    //交换,其最大子结点等于刚才的当前结点
    arr[i] = tmp;
}

void heap_sort(vector<int>& arr) 
{
    //从第一个非叶子结点开始调整
    //即从下往上,从右到左,将每个非叶子结点当做根节点
    //将其和其子树调整为大顶堆
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heap_adjust(arr, i, arr.size());
    
    //不停交换堆顶元素和数组尾元素,再将剩下的元素重新调整编程大顶堆
    for (int i = arr.size() - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);   //交换堆顶元素和数组末尾元素
        heap_adjust(arr, 0, i); //对剩下的元素进行堆重建
    }
}


int main() 
{
    vector<int> arr{9, 2, 6, 7, 1, 4, 3, 10, 45, 40, 69, 56, 99, 79};
    // sort_1(arr);
    // sort_2(arr);
    // quick_sort(0, arr.size(), arr);
    heap_sort(arr);
    for (auto x : arr) 
        cout << x << ' ';
    cout << endl;

    return 0;
}