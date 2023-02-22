#include <bits/stdc++.h>
using namespace std;

// int findPeakIndex(vector<int> &arr, int s, int e)
// {
//     int mid = s + (e - s) / 2;
//     if (mid > 0)
//     {
//         if ((arr[mid] > arr[mid - 1]) && (arr[mid] > arr[mid + 1]))
//             return mid;
//         if (arr[mid] > arr[mid - 1])
//             return findPeakIndex(arr, mid + 1, e);
//         else
//             return findPeakIndex(arr, s, mid - 1);
//     }
//     else
//         return findPeakIndex(arr, mid + 1, e);
// }

int findPeakIndex(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    if (s >= e)
        return s;
    if (arr[mid] < arr[mid + 1])
        return findPeakIndex(arr, mid + 1, e);
    else
        return findPeakIndex(arr, s, mid);
}

int peakIndexInMountainArray(vector<int> &arr)
{
    return findPeakIndex(arr, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {3, 5, 3, 2, 0};
    cout << peakIndexInMountainArray(arr);
    return 0;
}