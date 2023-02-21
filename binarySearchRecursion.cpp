#include <bits/stdc++.h>
using namespace std;

// bool binarySearch(int arr[], int size, int key)
// {
//     int mid = (size - 1) / 2;
//     if (size == 0)
//         return false;
//     if (arr[mid] == key)
//         return true;
//     else if (arr[mid] > key)
//         return binarySearch(arr, mid, key);
//     else
//         return binarySearch(arr + mid + 1, size - mid, key);
// }

int binarySearch(int arr[], int key, int s, int e)
{
    int mid = e + (s - e) / 2;
    if (s > e)
        return -1;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarySearch(arr, key, s, mid - 1);
    else
        return binarySearch(arr, key, mid + 1, e);
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr[] = {6, 11, 22, 23, 43, 46, 52, 54, 67, 80, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Index : " << binarySearch(arr, 80, 2, size - 1);
    // cout << "Present(1), Not present(0), Output : " << binarySearch(arr, size, 80);
    return 0;
}