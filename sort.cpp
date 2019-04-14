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
    
    //不停交换堆顶元素和数组尾元素,再将剩下的元素重新调整变成大顶堆
    for (int i = arr.size() - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);   //交换堆顶元素和数组末尾元素
        heap_adjust(arr, 0, i); //对剩下的元素进行堆重建
    }
}
/*
 * 将一个数组中的两个相邻有序区间合并成一个
 *
 * 参数说明：
 *     a -- 包含两个有序区间的数组
 *     start -- 第1个有序区间的起始地址。
 *     mid   -- 第1个有序区间的结束地址。也是第2个有序区间的起始地址。
 *     end   -- 第2个有序区间的结束地址。
 */
void merge(int* a, int start, int mid, int end)
{
    int *tmp = new int[end-start+1];    // tmp是汇总2个有序区的临时区域
    int i = start;            // 第1个有序区的索引
    int j = mid + 1;        // 第2个有序区的索引
    int k = 0;                // 临时区域的索引

    while(i <= mid && j <= end) //合并两个有序数组
    {
        if (a[i] <= a[j]) 
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    //哪个数组没放完,就全部添加到后面
    while(i <= mid)
        tmp[k++] = a[i++];
    while(j <= end)
        tmp[k++] = a[j++];

    // 将排序后的元素，全部都整合到数组a中。
    for (i = 0; i < k; i++)
        a[start + i] = tmp[i];

    delete[] tmp;
}

/*
 * 归并排序(从上往下)
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     start -- 数组的起始地址
 *     endi -- 数组的结束地址
 */
void mergeSortUp2Down(int* a, int start, int end)
{
    if(a==NULL || start >= end)
        return ;

    int mid = (end + start)/2;
    mergeSortUp2Down(a, start, mid); // 递归排序a[start...mid]
    mergeSortUp2Down(a, mid+1, end); // 递归排序a[mid+1...end]

    // a[start...mid] 和 a[mid...end]是两个有序空间，
    // 将它们排序成一个有序空间a[start...end]
    merge(a, start, mid, end);
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