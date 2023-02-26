#include <bits/stdc++.h>
using namespace std;

void swapRound(int arr[], int i, int lastIndex)
{
    if (i == lastIndex)
        return;
    if (arr[i] > arr[i + 1])
        swap(arr[i], arr[i + 1]);
    swapRound(arr, i + 1, lastIndex);
}

void bubbleSort(int arr[], int size)
{
    if (size == 1 || size == 0)
        return;
    swapRound(arr, 0, size - 1);
    bubbleSort(arr, size - 1);
}

void printArr(int arr[], int size)
{
    if (size == 0)
        return;
    cout << *arr << " ";
    printArr(arr + 1, size - 1);
}

int main()
{
    int arr[] = {4, 3, 2, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    cout << "After sorting : " << endl;
    printArr(arr, size);
    return 0;
}