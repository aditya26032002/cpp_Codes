#include <bits/stdc++.h>
using namespace std;

void findSmallestAndSwap(int arr[], int j, int size, int smallestIndex)
{
    if (j == size)
    {
        swap(arr[smallestIndex], arr[0]);
        return;
    }
    if (arr[j] < arr[smallestIndex])
        smallestIndex = j;
    findSmallestAndSwap(arr, j + 1, size, smallestIndex);
}

void selectionSort(int arr[], int size)
{
    if (size == 1 || size == 0)
        return;
    findSmallestAndSwap(arr, 1, size, 0);
    selectionSort(arr + 1, size - 1);
}

void printArr(int arr[], int size)
{
    if (size == 0)
    {
        cout << endl;
        return;
    }
    cout << *arr << " ";
    printArr(arr + 1, size - 1);
}

int main()
{
    // int arr[] = {1, 3, 5, 7, 9};
    int arr[] = {4, 3, 2, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, size);
    printArr(arr, size);
    return 0;
}