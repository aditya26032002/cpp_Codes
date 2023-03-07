#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partitionThenFindPivotIndex(int arr[], int s, int e)
{
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] < arr[s])
            count++;
    }
    int pivIndex = s + count;
    swap(arr[s], arr[pivIndex]);
    int i = s, j = e;
    while (i < pivIndex && j > pivIndex)
    {
        while (arr[i] < arr[pivIndex])
            i++;
        while (arr[j] > arr[pivIndex])
            j--;
        if (i < pivIndex && j > pivIndex)
            swap(arr[i++], arr[j--]);
    }
    return pivIndex;
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    int p = partitionThenFindPivotIndex(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {3, 1, 4, 5, 2};
    // int arr[] = {1, 3, 5, 7, 9};
    // int arr[] = {2, 4, 1, 3, 5};
    // int arr[] = {4, 3, 2, 1, 5, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    printArr(arr, size);
    return 0;
}