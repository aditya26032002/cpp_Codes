#include <bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int peak = 1;

    while (1)
    {
        if (arr[mid + 1] < arr[mid] && arr[mid - 1] < arr[mid])
        {
            peak = mid;
            break;
        }
        else if (arr[mid + 1] < arr[mid])
        {
            end = mid;
        }
        else if (arr[mid + 1] > arr[mid])
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return peak;
}

int main()
{
    vector<int> arr = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
    cout << peakIndexInMountainArray(arr);
    return 0;
}