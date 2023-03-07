#include <bits/stdc++.h>
using namespace std;

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

void mergeArr(int arr[], int s, int e, int mid)
{
    int *newArr = new int[e - s + 1];
    int ptr1 = s, ptr2 = mid + 1, newArrPtr = 0;
    for (; ptr1 <= mid && ptr2 <= e; newArrPtr++)
    {
        if (arr[ptr1] < arr[ptr2])
        {
            newArr[newArrPtr] = arr[ptr1];
            ptr1++;
        }
        else
        {
            newArr[newArrPtr] = arr[ptr2];
            ptr2++;
        }
    }
    for (; ptr1 <= mid; ptr1++, newArrPtr++)
    {
        newArr[newArrPtr] = arr[ptr1];
    }
    for (; ptr2 <= e; ptr2++, newArrPtr++)
    {
        newArr[newArrPtr] = arr[ptr2];
    }
    ptr1 = s;
    newArrPtr = 0;
    for (; newArrPtr <= (e - s); newArrPtr++, ptr1++)
    {
        arr[ptr1] = newArr[newArrPtr];
    }
    delete[] newArr;
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    printArr(arr, e - s + 1);

    mergeArr(arr, s, e, mid);
}

int main()
{
    // int arr[] = {1, 3, 5, 7, 9};
    int arr[] = {2, 4, 1, 3, 5};
    // int arr[] = {4, 3, 2, 1, 5, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    printArr(arr, size);
    return 0;
}