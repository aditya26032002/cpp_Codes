#include <bits/stdc++.h>
using namespace std;

void mergeArr(long long arr[], long long s, long long e, long long mid, long long int &inversionCount)
{
    long long *newArr = new long long[e - s + 1];
    long long ptr1 = s, ptr2 = mid + 1, newArrPtr = 0;
    for (; ptr1 <= mid && ptr2 <= e; newArrPtr++)
    {
        if (arr[ptr1] > arr[ptr2])
        {
            newArr[newArrPtr] = arr[ptr2];
            ptr2++;
            inversionCount += (mid - ptr1 + 1);
        }
        else
        {
            newArr[newArrPtr] = arr[ptr1];
            ptr1++;
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

void mergeSort(long long arr[], long long s, long long e, long long int &inversionCount)
{
    if (s >= e)
        return;
    long long mid = s + (e - s) / 2;
    mergeSort(arr, s, mid, inversionCount);
    mergeSort(arr, mid + 1, e, inversionCount);

    mergeArr(arr, s, e, mid, inversionCount);
}

long long int inversionCount(long long arr[], long long N)
{
    long long int inversions = 0;
    mergeSort(arr, 0, N - 1, inversions);
    return inversions;
}

int main()
{
    // long long arr[] = {1, 3, 5, 7, 9};
    // long long arr[] = {2, 4, 1, 3, 5};
    // long long arr[] = {10, 10, 10};
    long long arr[] = {2, 3, 4, 5, 6};
    long long size = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of inversions = " << inversionCount(arr, size) << endl;
    return 0;
}