#include <vector>
#include <iostream>
using namespace std;

int binarySearch(vector<int>& arr, int k, int l, int r)
{
    if (arr.empty() || l > r)
        return -1;

    int mid = (r - l) / 2 + l;
    if (arr[mid] > k)
        return binarySearch(arr, k, l, mid - 1);
    else if (arr[mid] < k)
        return binarySearch(arr, k, mid + 1, r);
    else 
        return mid;
}

int binarySearch_(vector<int>& arr, int k) 
{
    if (arr.empty())
        return -1;
    int l, r, mid;
    l = 0;
    r = arr.size() - 1;

    while (l <= r) 
    {
        mid = (r - l) / 2 + l;
        if (arr[mid] > k)
            r = mid - 1;
        else if (arr[mid] < k)
            l = mid + 1;
        else 
            return mid;
    }
}

int main() 
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << binarySearch(arr, 5, 0, 7) << endl;
    cout << binarySearch_(arr, 5) << endl;
}