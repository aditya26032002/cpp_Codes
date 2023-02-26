#include <bits/stdc++.h>
using namespace std;

void shiftPrevElements(int arr[], int i)
{
    if (i == 0)
        return;
    if (arr[i] >= arr[i - 1])
        return;
    swap(arr[i], arr[i - 1]);
    shiftPrevElements(arr, i - 1);
}

void insertionSort(int arr[], int size, int i)
{
    if (i == size || size == 0)
        return;
    shiftPrevElements(arr, i);
    insertionSort(arr, size, i + 1);
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
    insertionSort(arr, size, 0);
    printArr(arr, size);
    return 0;
}